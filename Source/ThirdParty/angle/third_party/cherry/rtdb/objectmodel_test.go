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
	"testing"
)

// TestObject

type TestObject struct {
	Value	int
}

func (obj *TestObject) PostLoad () {
}

func (obj *TestObject) SetValue (value int) error {
	obj.Value = value
	return nil
}

func (obj *TestObject) GenError () error {
	return fmt.Errorf("expected error")
}

// TestObjectModel

func TestObjectModel (t *testing.T) {
	// Create object model.
	objectModel := NewObjectModel([]reflect.Type {
		reflect.TypeOf((*TestObject)(nil)).Elem(),
	})

	// Create object.
	object, err := objectModel.NewObject("TestObject")
	if err != nil {
		t.Errorf("unable to instantiate TestObject: %s", err)
	}

	// Check that object is of correct type.
	objType := reflect.TypeOf(object)
	if objType != reflect.TypeOf((*TestObject)(nil)) {
		t.Errorf("created wrong type of object: %T", object)
	}

	// Set value via object model.
	err = objectModel.Cast(object, "SetValue", 5)
	if err != nil {
		t.Errorf("unable to call SetValue dynamically: %s", err)
	}

	// Check that we have proper result.
	if object.(*TestObject).Value != 5 {
		t.Errorf("object's value not set properly: got %d, expecting: 5\n", object.(*TestObject).Value)
	}
}

func TestErrorReporting (t *testing.T) {
	// Create object model.
	objectModel := NewObjectModel([]reflect.Type {
		reflect.TypeOf((*TestObject)(nil)).Elem(),
	})

	// Create object.
	object, err := objectModel.NewObject("TestObject")
	if err != nil {
		t.Errorf("unable to instantiate TestObject: %s", err)
	}

	// Call error-generating function.
	err = objectModel.Cast(object, "GenError")
	if err == nil {
		t.Errorf("expected error not generated")
	}
}
