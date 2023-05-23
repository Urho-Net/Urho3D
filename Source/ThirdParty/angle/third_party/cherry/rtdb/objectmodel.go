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
	"fmt"
	"reflect"
)

var (
	errorType		= reflect.TypeOf((*error)(nil)).Elem()
	objectBaseType	= reflect.TypeOf((*ObjectBase)(nil)).Elem()
)

// ObjectBase

type ObjectBase interface {
	PostLoad ()
}

// Method

type Method struct {
	Method		reflect.Method			// method
	ArgTypes	[]reflect.Type			// method argument types
	RetType		reflect.Type			// return type (in addition to error)
}

// Module

type Module struct {
	Name		string					// name of object
	PtrType		reflect.Type			// type of pointer to object
	Methods		map[string]*Method		// callable methods in object
}

// ObjectModel

type ObjectModel struct {
	moduleByName	map[string]*Module
	moduleByType	map[reflect.Type]*Module
}

func getObjectMethods (ptrType reflect.Type) map[string]*Method {
	methods := make(map[string]*Method, 0)

	for methodNdx := 0; methodNdx < ptrType.NumMethod(); methodNdx++ {
		method := ptrType.Method(methodNdx)
		mType := method.Type

		// Method must be visible.
		if method.PkgPath != "" { continue }

		// Must have at least one argument (destination object).
		numArgs := mType.NumIn()
		if numArgs == 0 { continue }

		// Must have one or two output values (optional value and error).
		numOut := mType.NumOut()
		if numOut == 0 || numOut > 2 { continue }

		// Get argument types.
		argTypes := make([]reflect.Type, numArgs - 1)
		for argNdx := 0; argNdx < numArgs - 1; argNdx++ {
			argTypes[argNdx] = mType.In(argNdx + 1)
		}

		// With two output arguments, first must be return value.
		var retType reflect.Type
		if numOut == 2 {
			retType = mType.Out(0)
		}

		// Last output value must be error.
		errType := mType.Out(numOut - 1)
		if errType != errorType { continue }

		methods[method.Name] = &Method {
			Method:		method,
			ArgTypes:	argTypes,
			RetType:	retType,
		}
	}

	return methods
}

func newModule (ptrType reflect.Type) *Module {
	model := Module {
		Name:		ptrType.Elem().Name(),
		PtrType:	ptrType,
		Methods:	getObjectMethods(ptrType),
	}
	return &model
}

func NewObjectModel (objectTypes []reflect.Type) *ObjectModel {
	// Create moduleByType and moduleByName maps.
	moduleByName := make(map[string]*Module, 0)
	moduleByType := make(map[reflect.Type]*Module, 0)
	for _, objType := range objectTypes {
		ptrType := reflect.PtrTo(objType)
		if !ptrType.Implements(objectBaseType) {
			panic(fmt.Errorf("[object] type %s doesn't implement ObjectBase interface", objType.Name()))
		}

		module := newModule(ptrType)
		moduleByName[objType.Name()]	= module
		moduleByType[ptrType]			= module
	}

	return &ObjectModel {
		moduleByName: moduleByName,
		moduleByType: moduleByType,
	}
}

func (model *ObjectModel) NewObject (typeName string) (ObjectBase, error) {
	// Find module by name.
	module, ok := model.moduleByName[typeName]
	if !ok {
		return nil, fmt.Errorf("[object] no such module: %s", typeName)
	}

	// Instantiate object and return it.
	object := reflect.New(module.PtrType.Elem())
	return object.Interface().(ObjectBase), nil
}

func (model *ObjectModel) Cast (dst ObjectBase, methodName string, args ...interface{}) error {
	// Check that destination object is a known type.
	dstType := reflect.TypeOf(dst)
	module, ok := model.moduleByType[dstType]
	if !ok {
		return fmt.Errorf("[object] invalid module type: %s", dstType.Name())
	}

	// Check that method is a known one.
	method, ok := module.Methods[methodName]
	if !ok {
		return fmt.Errorf("[object] no method '%s' in module '%s'", methodName, module.Name)
	}

	// Fill method argument values.
	numArgs := len(args)
	values	:= make([]reflect.Value, numArgs + 1)
	values[0] = reflect.ValueOf(dst)
	for i, _ := range args {
		values[i+1] = reflect.ValueOf(args[i])
	}

	// Call method.
	retValues := method.Method.Func.Call(values) // \todo [petri] handle return value!
	errValue := retValues[len(retValues) - 1]
	err := errValue.Interface()

	if err != nil {
		return err.(error)
	} else {
		return nil
	}
}
