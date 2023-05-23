/*
 * Copyright 2017 Google Inc. All rights reserved.
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

package cherry

import (
	"fmt"
	"regexp"
	"../rtdb"
)

func checkTestSetFilters (setFilters []string) error {
	filterChecker := regexp.MustCompile(`^dEQP-[a-zA-Z0-9-_.*]+$`)
	for _, filter := range setFilters {
		if !filterChecker.MatchString(filter) {
			return fmt.Errorf("'%s' is not a valid path filter", filter)
		}
	}
	return nil
}

func AddTestSet (rtdbServer *rtdb.Server, setName string, setFilters []string) error {
	err := checkTestSetFilters(setFilters)
	if err != nil {
		return err
	}

	opSet := rtdb.NewOpSet()
	testSetId := rtdbServer.MakeUniqueID()

	testSet := TestSet {
		Id: 		testSetId,
		Name: 		setName,
		Filters: 	setFilters,
	}
	testSetHeader := TestSetHeader {
		Id: 		testSet.Id,
		Name: 		testSet.Name,
	}
	opSet.Call(typeTestSet, testSetId, "Init", testSet)
	opSet.Call(typeTestSetList, "testSetList", "Append", testSetHeader)
	err = rtdbServer.ExecuteOpSet(opSet)
	return err
}

