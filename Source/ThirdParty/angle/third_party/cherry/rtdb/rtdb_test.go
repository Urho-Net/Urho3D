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
	"reflect"
	"math/rand"
	"strconv"
	"testing"
)

// Counter
type Counter struct {
	Value	int
}

func (c *Counter) PostLoad () {
}

func (c *Counter) Init () error {
	c.Value = 0
	return nil
}

func (c *Counter) Increment () error {
	c.Value++
	return nil
}

func (c *Counter) Decrement () error {
	c.Value--
	return nil
}

func (c *Counter) Add (v int) error {
	c.Value += v
	return nil
}

func TestRtdbTransactions (t *testing.T) {
	// Create in-memory SQLite backend.
	backend, err := NewSQLiteBackend(":memory:", true)
	if err != nil { t.Errorf("unable to create sqlite backend: %s", err) }

	// Create data model.
	typeCounter := reflect.TypeOf((*Counter)(nil)).Elem()
	objectTypes := []reflect.Type {
		typeCounter,
	}
	dataModel := NewObjectModel(objectTypes)

	rtdb, err := NewServer(dataModel, backend)
	if err != nil { t.Errorf("unable to create rtdb server instance: %s", err) }

	// Init counters.
	opSet := NewOpSet()
	opSet.Call(typeCounter, "c0", "Init")
	opSet.Call(typeCounter, "c1", "Init")
	opSet.Call(typeCounter, "c2", "Init")
	opSet.Call(typeCounter, "c3", "Init")
	opSet.Call(typeCounter, "c4", "Init")
	err = rtdb.ExecuteOpSet(opSet)
	if err != nil { t.Errorf("init with ExecuteOpSet() failed: %s", err) }

	// Launch threads to do lots of counter modifications.
	done := make(chan bool)
	counters := []string{ "c0", "c1", "c2", "c3", "c4" }
	for ndx := 0; ndx < len(counters); ndx++ {
		ca := counters[ndx]
		cb := counters[(ndx+1) % len(counters)]
		go func() {
			for count := 0; count < 100; count++ {
				{
					opSet := NewOpSet()
					opSet.Call(typeCounter, ca, "Increment")
					opSet.Call(typeCounter, cb, "Decrement")
					err = rtdb.ExecuteOpSet(opSet)
					if err != nil { t.Fatalf("counter inc/dec failed: %s", err) }
				}

				{
					opSet := NewOpSet()
					opSet.Call(typeCounter, ca, "Decrement")
					opSet.Call(typeCounter, cb, "Increment")
					err = rtdb.ExecuteOpSet(opSet)
					if err != nil { t.Fatalf("counter inc/dec failed: %s", err) }
				}
			}

			done <- true
		}()
	}

	// Wait for all threads to finish.
	for ndx := 0; ndx < len(counters); ndx++ {
		<- done
	}

	// Check all counters.
	results := make([]Counter, len(counters))
	isOk := true
	for ndx := 0; ndx < len(counters); ndx++ {
		rtdb.GetObject(counters[ndx], &results[ndx])
		if results[ndx].Value != 0 { isOk = false }
	}

	// Check all counters.
	if !isOk {
		t.Errorf("non-zero value in found counters: %v", results)
	}
}

func TestRtdbVersionedViews (t *testing.T) {
	typeCounter := reflect.TypeOf((*Counter)(nil)).Elem()

	var rtdb *Server

	// Structures for naive but probably correct (reference) emulation of version-viewed db.
	var realtime		map[string]Counter
	var versionViews	[]map[string]Counter

	// Version view IDs from rtdb.
	var versionViewIds	[]int

	// Functions for validating rtdb state against reference.

	// Check that existence and value of versioned object in rtdb matches reference.
	checkGetVersionViewedObject := func (objId string, viewNdx int) {
		referenceCounter, objectExists := versionViews[viewNdx][objId]

		var rtdbCounter Counter
		err := rtdb.GetVersionViewedObject(objId, &rtdbCounter, versionViewIds[viewNdx])
		if (err == nil) != objectExists { t.Errorf("rtdb.GetVersionViewedObject error not consistent with existence of object") }

		if err == nil && objectExists {
			if rtdbCounter.Value != referenceCounter.Value {
				t.Errorf("rtdb.GetVersionViewedObject returned counter with invalid value")
			}
		}
	}

	// Check that existence and value of realtime object in rtdb matches reference.
	checkGetObject := func (objId string) {
		referenceCounter, objectExists := realtime[objId]

		var rtdbCounter Counter
		err := rtdb.GetObject(objId, &rtdbCounter)
		if (err == nil) != objectExists { t.Errorf("rtdb.GetObject error not consistent with existence of object") }

		if err == nil && objectExists {
			if rtdbCounter.Value != referenceCounter.Value {
				t.Errorf("rtdb.GetObject returned counter with invalid value")
			}
		}
	}

	// Checks for all objects and all versions (and realtime) that rtdb matches reference.
	validateAllObjects := func () {
		for counterId, _ := range realtime {
			checkGetObject(counterId)
			for viewNdx, _ := range versionViewIds {
				checkGetVersionViewedObject(counterId, viewNdx)
			}
		}
	}

	// Functions for manipulating db state. Each function calls validateAllObjects() at the end.

	initCounter := func (id string) {
		counter := Counter{}
		counter.Init()
		realtime[id] = counter

		opSet := NewOpSet()
		opSet.Call(typeCounter, id, "Init")
		err := rtdb.ExecuteOpSet(opSet)
		if err != nil { t.Fatalf("unexpected error in initCounter") }

		validateAllObjects()
	}

	addToCounter := func (id string, v int) {
		counter := realtime[id]
		counter.Add(v)
		realtime[id] = counter

		opSet := NewOpSet()
		opSet.Call(typeCounter, id, "Add", v)
		err := rtdb.ExecuteOpSet(opSet)
		if err != nil { t.Fatalf("unexpected error in addToCounter") }

		validateAllObjects()
	}

	newView := func () {
		copiedState := map[string]Counter{}
		for k, v := range realtime {
			copiedState[k] = v
		}
		versionViews = append(versionViews, copiedState)
		versionViewIds = append(versionViewIds, rtdb.NewVersionView())
		validateAllObjects()
	}

	// Deletes a version view; note that the ndx parameter is the index into versionViewIds, i.e. is not the actual id.
	releaseView := func (ndx int) {
		rtdb.ReleaseVersionView(versionViewIds[ndx])
		versionViewIds = append(versionViewIds[:ndx], versionViewIds[ndx+1:]...)
		versionViews = append(versionViews[:ndx], versionViews[ndx+1:]...)
		validateAllObjects()
	}

	// Tests, each to be run with a fresh database.

	tests := []func() {
		func () {
			newView()
			initCounter("c0")
			newView()
			addToCounter("c0", 5)
			newView()
			initCounter("c1")
			addToCounter("c1", 7)
			addToCounter("c0", 9)
			newView()
			addToCounter("c1", 10)
			releaseView(0)
			releaseView(1)
			releaseView(1)
			releaseView(0)
		},

		func () {
			initCounter("c0")
			newView()
			newView()
			newView()
			initCounter("c1")
			initCounter("c2")
			addToCounter("c1", 5)
			addToCounter("c0", 5)
			newView()
			releaseView(3)
			releaseView(2)
			releaseView(1)
			releaseView(0)
		},

		func () {
			initCounter("c0")
			newView()
			addToCounter("c0", 2)
			releaseView(0)
			newView()
			addToCounter("c0", 3)
			releaseView(0)
			newView()
			addToCounter("c0", 4)
			releaseView(0)
		},
	}

	{
		// Random tests.

		randomTest := func (seed int) func () {
			rand.New(rand.NewSource(int64(seed)))
			return func() {
				numCounters := 0
				numViews := 0
				for iter := 0; iter < 100; iter++ {
					switch rand.Intn(6) {
						case 0:
							initCounter("c" + strconv.Itoa(numCounters))
							numCounters++
						case 1:
							if numCounters > 0 {
								addToCounter("c" + strconv.Itoa(rand.Intn(numCounters)), rand.Intn(100)-50)
							}
						case 2:
							newView()
							numViews++
						case 3:
							if numViews > 0 {
								releaseView(rand.Intn(numViews))
								numViews--
							}
						case 4:
							for verNdx := 0; verNdx < numViews; verNdx++ {
								checkGetVersionViewedObject("invalid" + strconv.Itoa(100), verNdx)
							}
						case 5:
							checkGetObject("invalid" + strconv.Itoa(100))
						default:
							panic("Bad random test")
					}
				}
			}
		}

		for randomCaseNdx := 0; randomCaseNdx < 20; randomCaseNdx++ {
			tests = append(tests, randomTest(randomCaseNdx))
		}
	}

	// Run the tests.
	for _, test := range tests {
		// Create in-memory SQLite backend.
		backend, err := NewSQLiteBackend(":memory:", true)
		if err != nil { t.Fatalf("unable to create sqlite backend: %s", err);  }

		// Create data model.
		objectTypes := []reflect.Type {
			typeCounter,
		}
		dataModel := NewObjectModel(objectTypes)

		rtdb, err = NewServer(dataModel, backend)
		if err != nil { t.Fatalf("unable to create rtdb server instance: %s", err) }

		realtime		= map[string]Counter{}
		versionViews	= []map[string]Counter{}
		versionViewIds	= []int{}

		test()
	}
}
