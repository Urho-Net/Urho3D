/*
 * Copyright 2015 Google Inc. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package rtdb

import (
	"database/sql"
	"errors"
	"fmt"
	"log"
	"reflect"
	"time"
	"strconv"
)

type Object struct {
	Type		string			`json:"type"`
	Id			string			`json:"id"`
	Value		ObjectBase		`json:"value"`
	Ops			string			`json:"ops"`
}

type TypedObject struct {
	Type		string			`json:"objType"`
	ObjId		string			`json:"objId"`
}

type ObjectOp struct {
	Method		string			`json:"method"`
	Args		[]interface{}	`json:"args"`
}

type ObjectOpSet struct {
	ObjectOps	map[TypedObject][]ObjectOp
}

type Update struct {
	ObjId		string			`json:"objId"`
	ObjType		string			`json:"objType"`
	Ops			[]ObjectOp		`json:"ops"`
}

// Data type for writing objects to backend storage.
type WriteOp struct {
	ObjId		string
	Value		ObjectBase
	Ops			[]ObjectOp
}

// Backend

type Backend interface {
	GetObject				(objId string, dst ObjectBase) error
	GetExplicitTypeObject	(objType string, objId string, dst ObjectBase) error
	WriteObjects			(writeOps []WriteOp) error // \todo [petri] ops?
}

type Server struct {
	objectModel			*ObjectModel
	backend				Backend
	requestQueue		chan func()
	stopQueue			chan bool
	objectListeners		map[TypedObject]map[*Listener]bool

	// versionViewDelta[v] represents the difference between
	// the current state of the database and the state of the
	// database at the time the versioned view v was created.
	// d = versionViewDelta[v][o] exists iff object o has been
	// created/updated after version view v was created. If o
	// didn't exist when v was created, d is struct{}{};
	// if o did exist when v was created but has since been
	// changed, d is the value of o when v was created.
	versionViewDelta	map[int]map[TypedObject]interface{}
	// Running ID for version views.
	versionViewId		int
}

type SubscribeFunc func ([]Object)
type UpdateFunc func (changes []Update)

type Listener struct {
	server						*Server
	subscribeFn					SubscribeFunc
	updateFn					UpdateFunc
	listenedObjects				map[TypedObject]bool
	// \note Each Listener has its own ID space for version views, different from its server's ID space.
	versionViews				map[int]int		// Maps this listener's view ID to the server's.
	versionViewId				int				// Running ID.
}

// Server implementation

func (server *Server) run () error {
	log.Printf("[rtdb] starting server\n")

	go func() {
		for {
			select {
				case <- server.stopQueue:
					log.Println("[rtdb] stopping server on request")
					return

				case reqFunc := <- server.requestQueue:
					reqFunc()
			}
		}
	}()

	return nil
}

// Listener API

func (listener *Listener) Subscribe (objectInfos []TypedObject) error {
	ret := make(chan error)
	server := listener.server
	server.requestQueue <- func() {
		log.Printf("[rtdb] subscribe to %d objects\n", len(objectInfos))

		objects := make([]Object, len(objectInfos))

		for objNdx, info := range objectInfos {
			objType	:= info.Type
			objId	:= info.ObjId

			// Fetch object.
			// \todo [petri] should fetch in caller thread? careful with listening in that case!
			objValue, err := server.objectModel.NewObject(objType)
			if err == nil {
				err = server.backend.GetObject(objId, objValue)
			}

			object := Object {
				Type:	objType,
				Id:		objId,
			}
			if err != nil && err != sql.ErrNoRows {
				log.Printf("[rtdb] error when fetching object on subscribe: %s\n", err)
				ret <- err
				return
			} else if err == sql.ErrNoRows {
				log.Printf("[rtdb] subscribed to non-existent object: %s.%s\n", objType, objId)
			} else {
				object.Value = objValue
			}
			objects[objNdx] = object

			// Add to listener's list.
			if _, ok := listener.listenedObjects[info]; ok {
				ret <- fmt.Errorf("objId %s already in listener's list", objId)
				return
			}
			listener.listenedObjects[info] = true

			// Register as listener to object.
			listeners, ok := server.objectListeners[info]
			if ok {
				listeners[listener] = true
			} else {
				listeners = make(map[*Listener]bool)
				listeners[listener] = true
				server.objectListeners[info] = listeners
			}
		}

		// Notify listener of subscription.
		// \todo [petri] if object isn't yet created in rtdb, this will send value==nil object!
		listener.subscribeFn(objects)

		ret <- nil
	}
	return <- ret
}

func (listener *Listener) Unsubscribe (objects []TypedObject) error {
	ret := make(chan error)
	server := listener.server
	server.requestQueue <- func() {
		log.Printf("[rtdb] listener unsubscribe %d objects\n", len(objects))

		for _, obj := range objects {
			listeners := server.objectListeners[obj]
			delete(listeners, listener)
			// \todo [petri] delete empty listeners?

			if _, ok := listener.listenedObjects[obj]; !ok {
				ret <- fmt.Errorf("object %s of type %s not in listener's list", obj.ObjId, obj.Type)
				return
			}
			delete(listener.listenedObjects, obj)
		}

		ret <- nil
	}
	return <- ret
}

func (listener *Listener) NewVersionView () int {
	log.Println("[rtdb] create new version view for listener")
	serverViewId	:= listener.server.NewVersionView()
	listenerViewId	:= listener.versionViewId
	listener.versionViewId++
	listener.versionViews[listenerViewId] = serverViewId
	return listenerViewId
}

func (listener *Listener) ReleaseVersionView (listenerViewId int) error {
	log.Printf("[rtdb] release listener's version view %d\n", listenerViewId)
	if serverViewId, ok := listener.versionViews[listenerViewId]; ok {
		listener.server.ReleaseVersionView(serverViewId)
		delete(listener.versionViews, listenerViewId)
		return nil
	} else {
		return fmt.Errorf("[rtdb] listener tried to release non-existent version view %d", listenerViewId)
	}
}

func (listener *Listener) GetVersionViewedObject (objInfo TypedObject, listenerViewId int) (ObjectBase, error) {
	if serverViewId, ok := listener.versionViews[listenerViewId]; ok {
		object, err := listener.server.objectModel.NewObject(objInfo.Type)
		if err != nil { return Object{}.Value, err }
		err = listener.server.GetVersionViewedObject(objInfo.ObjId, object, serverViewId)
		if err != nil { return Object{}.Value, err }
		return object, nil
	} else {
		return Object{}.Value, fmt.Errorf("Listener requested object from invalid version view %d", listenerViewId)
	}
}

// Server API

func NewServer (objectModel *ObjectModel, backend Backend) (*Server, error) {
	server := Server {
		objectModel:		objectModel,
		backend:			backend,
		requestQueue:		make(chan func(), 200),
		stopQueue:			make(chan bool, 8),
		objectListeners:	make(map[TypedObject]map[*Listener]bool),

		versionViewDelta:	map[int]map[TypedObject]interface{}{},
		versionViewId:		1,
	}
	if err := server.run(); err != nil {
		return nil, err
	}
	return &server, nil
}

func (server *Server) Stop () {
	server.stopQueue <- true
}

func (server *Server) NewListener (subscribeFn SubscribeFunc, updateFn UpdateFunc) *Listener {
	ret := make(chan *Listener)
	server.requestQueue <- func() {
		listener := &Listener{
			server:						server,
			subscribeFn:				subscribeFn,
			updateFn:					updateFn,
			listenedObjects:			make(map[TypedObject]bool),
			versionViews:				make(map[int]int),
			versionViewId:				0,
		}
		ret <- listener
	}
	return <- ret
}

func (server *Server) DestroyListener (listener *Listener) {
	ret := make(chan bool)
	server.requestQueue <- func() {
		log.Printf("[rtdb] destroy listener (%d subscribed objects, %d version views)\n", len(listener.listenedObjects), len(listener.versionViews))

		// Remove listener from all listened objects' list.
		for objId, _ := range listener.listenedObjects {
			delete(server.objectListeners[objId], listener)
			// \todo [petri] remove empty listener list?
		}

		// Release all listener's version views.
		for _, serverViewId := range listener.versionViews {
			delete(server.versionViewDelta, serverViewId)
		}

		ret <- true
	}
	<- ret
}

// Helpers for creating object-ops.

func Obj (objType reflect.Type, objId string) TypedObject {
	return TypedObject {
		Type:   objType.Name(),
		ObjId:  objId,
	}
}

func Op (method string, args ...interface{}) ObjectOp {
	return ObjectOp {
		Method: method,
		Args:   args,
	}
}

func (server *Server) NewVersionView () int {
	ret := make(chan int)

	server.requestQueue <- func() {
		viewId := server.versionViewId
		server.versionViewId++
		server.versionViewDelta[viewId] = map[TypedObject]interface{}{}
		ret <- viewId
	}

	return <- ret
}

func (server *Server) ReleaseVersionView (viewId int) {
	done := make(chan struct{})

	server.requestQueue <- func() {
		delete(server.versionViewDelta, viewId)
		done <- struct{}{}
	}

	<- done
}

func (server *Server) GetVersionViewedObject (objId string, dst ObjectBase, viewId int) error {
	ret := make(chan error)

	server.requestQueue <- func() {
		viewDelta, versionExists := server.versionViewDelta[viewId]
		if !versionExists { ret <- fmt.Errorf("Object requested from invalid version view %d", viewId); return }
		objKey := Obj(reflect.TypeOf(dst).Elem(), objId)
		if oldObject, ok := viewDelta[objKey]; ok {
			switch oldObject.(type) {
				case struct{}:
					ret <- errors.New("Non-existent object requested from version view")
				default:
					reflect.Indirect(reflect.ValueOf(dst)).Set(reflect.ValueOf(oldObject))
					ret <- nil
			}
		} else {
			ret <- server.backend.GetObject(objId, dst)
		}
	}

	return <- ret
}

func (server *Server) writeObjects (writeOps []WriteOp) error {
	// Update version view deltas where necessary.
	if len(server.versionViewDelta) > 0 {
		for _, writeOp := range writeOps {
			objId			:= writeOp.ObjId
			objType			:= reflect.TypeOf(writeOp.Value).Elem()
			objKey			:= Obj(objType, objId)
			typeName		:= objType.Name()

			oldObject, err	:= server.objectModel.NewObject(typeName)
			if err != nil { return err }

			err = server.backend.GetObject(objId, oldObject)
			isNewObject := err != nil

			for _, viewDelta := range server.versionViewDelta {
				if _, alreadyChanged := viewDelta[objKey]; !alreadyChanged {
					if isNewObject {
						viewDelta[objKey] = struct{}{}
					} else {
						viewDelta[objKey] = reflect.Indirect(reflect.ValueOf(oldObject)).Interface()
					}
				}
			}
		}
	}

	// Write to backend.
	err := server.backend.WriteObjects(writeOps)
	if err != nil { return err }

	// Collect all notifications per-listener.
	notifications := make(map[*Listener][]Update)
	for _, writeOp := range writeOps {
		objId		:= writeOp.ObjId
		objType		:= reflect.TypeOf(writeOp.Value).Elem() // \todo [petri] assumption about pointer!
		typeName	:= objType.Name()
		obj			:= Obj(objType, objId)
		update 		:= Update{ ObjId:objId, ObjType:typeName, Ops:writeOp.Ops }

		if objectListeners, ok := server.objectListeners[obj]; ok {
			for listener, _ := range objectListeners {
				if _, ok := notifications[listener]; !ok {
					notifications[listener] = []Update{ update }
				} else {
					notifications[listener] = append(notifications[listener], update)
				}
			}
		}
	}

	// Send all notifications to listeners.
	// \todo [petri] use separate notify goroutine with in-order queue?
	for listener, updates := range notifications {
		listener.updateFn(updates)
	}

	return nil
}

func NewOpSet () ObjectOpSet {
	return ObjectOpSet {
		ObjectOps: make(map[TypedObject][]ObjectOp),
	}
}

func (opSet *ObjectOpSet) Call (objType reflect.Type, objId string, method string, args ...interface{}) {
	target := TypedObject {
		Type:	objType.Name(),
		ObjId:	objId,
	}
	op := ObjectOp {
		Method:	method,
		Args:	args,
	}

	// Create new array, or append to existing one.
	if value, ok := opSet.ObjectOps[target]; !ok {
		opSet.ObjectOps[target] = []ObjectOp{ op }
	} else {
		opSet.ObjectOps[target] = append(value, op)
	}
}

func (opSet *ObjectOpSet) Delete (objType reflect.Type, objId string) {
	target := TypedObject {
		Type:	objType.Name(),
		ObjId:	objId,
	}
	// \todo [petri] better implementation -- actually delete object from rtdb!
	opSet.ObjectOps[target] = []ObjectOp{ ObjectOp{ Method:"Delete" } }
}

func (server *Server) ExecuteOpSet (opSet ObjectOpSet) error {
	// \todo [petri] properly handle version conflicts!
	// \todo [petri] fetch objects concurrently

	ret := make(chan error)
	server.requestQueue <- func() {
		writeOps := make([]WriteOp, 0) // \todo [petri] size?
		for target, opList := range opSet.ObjectOps {
			typeName	:= target.Type
			objId		:= target.ObjId
			objValue, err := server.objectModel.NewObject(typeName)
			if err != nil { ret <- err; return }

			server.backend.GetObject(objId, objValue)

			// Execute each operation.
			for _, op := range opList {
				// \todo [petri] handle errors!
				err = server.objectModel.Cast(objValue, op.Method, op.Args...)
			}
			if err != nil { ret <- err; return }

			// Append into writeOps list.
			writeOp := WriteOp{ ObjId:objId, Value:objValue, Ops:opList }
			writeOps = append(writeOps, writeOp)
		}

		// Commit object modifications.
		err := server.writeObjects(writeOps) // \todo [petri] error handling & retry support!
		if err != nil { panic(err) }

		ret <- nil
	}

	return <- ret
}

// \todo [petri] version handling?
func (server *Server) GetObject (objId string, dst ObjectBase) error {
	ret := make(chan error)
	server.requestQueue <- func() {
		ret <- server.backend.GetObject(objId, dst)
	}
	return <- ret
}

func (server *Server) GetExplicitTypeObject (obj TypedObject, dst ObjectBase) error {
	ret := make(chan error)
	server.requestQueue <- func() {
		ret <- server.backend.GetExplicitTypeObject(obj.Type, obj.ObjId, dst)
	}
	return <- ret
}

func (server *Server) MakeUniqueID () string {
	ret := make(chan string)
	server.requestQueue <- func() {
		// requestQueue serializes accesses -> time will be unique
		ret <- strconv.FormatInt(time.Now().UnixNano(), 10)
	}
	return <- ret
}
