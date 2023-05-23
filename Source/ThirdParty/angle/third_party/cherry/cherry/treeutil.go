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

package cherry

import (
	"strings"
)

// Tree utilities

type treeNodeInfo struct {
	path			string
	children		[]string
	numTotalCases	int
}

func computeTestCaseTreeNodes (testCasePaths []string) []treeNodeInfo {
	if len(testCasePaths) == 0 {
		return []treeNodeInfo{ { "", []string{}, 0 } }
	}

	// ..?
	treeNodeInfos := make([]treeNodeInfo, 0)
	treeNodeHash := make(map[string]int)
	for _, testCasePath := range testCasePaths {
		parts := strings.Split(testCasePath, ".")
		for ndx := 0; ndx < len(parts); ndx++ {
			subPath := strings.Join(parts[0:ndx], ".")
			if _, ok := treeNodeHash[subPath]; !ok {
				treeNodeHash[subPath] = len(treeNodeInfos)
				treeNodeInfos = append(treeNodeInfos, treeNodeInfo{ subPath, []string{}, 1 })
			} else {
				ndx := treeNodeHash[subPath]
				treeNodeInfos[ndx].numTotalCases++
			}
		}

		parentPath := strings.Join(parts[0:len(parts)-1], ".")
		parentNdx := treeNodeHash[parentPath]
		treeNodeInfos[parentNdx].children = append(treeNodeInfos[parentNdx].children, testCasePath)
	}

	// Accumulate parent counts.
	for _, nodeInfo := range treeNodeInfos {
		if nodeInfo.path != "" {
			parts := strings.Split(nodeInfo.path, ".")
			parentPath := strings.Join(parts[0:len(parts)-1], ".")
			parentNdx := treeNodeHash[parentPath]
			treeNodeInfos[parentNdx].children = append(treeNodeInfos[parentNdx].children, nodeInfo.path)
		}
	}

	return treeNodeInfos
}
