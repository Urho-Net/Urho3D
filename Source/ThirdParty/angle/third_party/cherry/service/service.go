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

package service

import (
	"bytes"
	"encoding/json"
	"fmt"
	"log"
	"reflect"
	"strings"
)

var (
	errorType = reflect.TypeOf((*error)(nil)).Elem()
)

// Method

type Method struct {
	Method		reflect.Method			// method
	ArgTypes	[]reflect.Type			// method argument types
	RetType		reflect.Type			// return type (in addition to error)
}

// Module

type Module struct {
	Handler		interface{}
	Methods		map[string]*Method		// callable methods in object
}

// HandlerSpec

type HandlerSpec struct {
	Name		string
	Handler		interface{}
}

// Library

type Library struct {
	moduleByName	map[string]*Module
	moduleByType	map[reflect.Type]*Module
}

func getObjectMethods (ptrType reflect.Type, contextType reflect.Type) map[string]*Method {
	methods := make(map[string]*Method, 0)

	for methodNdx := 0; methodNdx < ptrType.NumMethod(); methodNdx++ {
		method := ptrType.Method(methodNdx)
		mType := method.Type

		// Method must be visible.
		if method.PkgPath != "" { continue }

		// Skip handler and context params.
		numArgs := mType.NumIn() - 2

		// Get argument types (ignore dst, client).
		argTypes := make([]reflect.Type, numArgs)
		for argNdx := 0; argNdx < numArgs; argNdx++ {
			argTypes[argNdx] = mType.In(argNdx + 2)
		}

		// Check that first argument is client type.
		if mType.In(1) != contextType { fmt.Printf("WRONG CONTEXT TYPE\n"); continue }

		// Must have two output values: (value, error).
		numOut := mType.NumOut()
		if numOut != 2 { fmt.Printf("WRONG OUT VALUES\n"); continue }

		// With two output arguments, first must be return value.
		retType := mType.Out(0)
		// \todo [petri] check value?

		// Last output value must be error.
		errType := mType.Out(1)
		if errType != errorType { fmt.Printf("WRONG ERR TYPE\n"); continue }

		methods[method.Name] = &Method {
			Method:		method,
			ArgTypes:	argTypes,
			RetType:	retType,
		}
	}

	return methods
}

func newModule (handler interface{}, contextType reflect.Type) *Module {
	log.Printf("[service] register module %T\n", handler)
	library := Module {
		Handler:	handler,
		Methods:	getObjectMethods(reflect.TypeOf(handler), contextType),
	}
	return &library
}

func NewServiceLibrary (contextType reflect.Type, handlerSpecs []HandlerSpec) *Library {
	// Create moduleByName and moduleByType maps.
	moduleByName := make(map[string]*Module, 0)
	moduleByType := make(map[reflect.Type]*Module, 0)
	for _, spec := range handlerSpecs {
		handlerType := reflect.TypeOf(spec.Handler)
		module := newModule(spec.Handler, contextType)
		moduleByName[spec.Name]		= module
		moduleByType[handlerType]	= module
	}

	return &Library {
		moduleByName: moduleByName,
		moduleByType: moduleByType,
	}
}

func (library *Library) CallJSON (dst interface{}, request []byte) ([]byte, error) {
	// Parse JSON request.
	type jsonRequest struct {
		Method	string				`json:"method"`
		Params	[]json.RawMessage	`json:"params"`
		Id		*json.RawMessage	`json:"id"`
	}

	// Decode request.
	req := &jsonRequest{}
	reader := bytes.NewReader(request)
	err := json.NewDecoder(reader).Decode(req)
	if err != nil { return nil, err }

	// Decode module.method name.
	methodParts := strings.Split(req.Method, ".")
	if len(methodParts) != 2 {
		return nil, fmt.Errorf("service: Module/method request ill-formed: %q", req.Method)
	}
	moduleName := methodParts[0]
	methodName := methodParts[1]

	// Find module.
	module, ok := library.moduleByName[moduleName]
	if !ok {
		return nil, fmt.Errorf("[service] invalid module name: %s", moduleName)
	}

	// Find method.
	method, ok := module.Methods[methodName]
	if !ok {
		return nil, fmt.Errorf("[service] no method '%s' in module '%s'", methodName, moduleName)
	}

	// Fill method argument values.
	numArgs := len(method.ArgTypes)
	values	:= make([]reflect.Value, numArgs + 2)
	values[0] = reflect.ValueOf(module.Handler)
	values[1] = reflect.ValueOf(dst)
	for argNdx := 0; argNdx < numArgs; argNdx++ {
		argType := method.ArgTypes[argNdx]
		value := reflect.New(argType)
		json.Unmarshal(req.Params[argNdx], value.Interface())
		values[argNdx+2] = value.Elem()
	}

	// Call method.
	retValues := method.Method.Func.Call(values)
	retValue := retValues[0]
	errValue := retValues[1]	// \todo [petri] assert two return values are present?
	errInter := errValue.Interface()

	if errInter != nil {
		return nil, errInter.(error)
	} else {
		// Encode response.
		type jsonResponse struct {
			JsonRPC	string				`json:"jsonrpc"`
			Result	interface{}			`json:"result"`
			Error	interface{}			`json:"error,omitempty"`
			Id		*json.RawMessage	`json:"id"`
		}

		response := jsonResponse {
			JsonRPC:	"2.0",
			Id:			req.Id,
			Result:		retValue.Interface(),
			Error:		nil,
		}

		// Encode response.
		encoded, err := json.Marshal(response)
		return encoded, err
	}
}
