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
	"bytes"
	"strings"
)

func encodeRecursive (buffer *bytes.Buffer, casePaths []string) {
	prefixHash := make(map[string][]string)
	prefixList := make([]string, 0)

	// Split all paths into hash, based on prefix.
	for _, path := range casePaths {
		parts := strings.Split(path, ".")
		prefix := parts[0]
		rest := strings.Join(parts[1:], ".")
		list, ok := prefixHash[prefix]
		if !ok {
			prefixHash[prefix] = []string{}
			prefixList = append(prefixList, prefix)
		}

		if len(parts) > 1 {
			prefixHash[prefix] = append(list, rest)
		}
	}

	// Write output.
	buffer.WriteString("{")
	isFirst := true
	for _, prefix := range prefixList {
		if isFirst {
			isFirst = false
		} else {
			buffer.WriteString(",")
		}

		buffer.WriteString(prefix)

		children := prefixHash[prefix]
		if len(children) > 0 {
			encodeRecursive(buffer, children)
		}
	}
	buffer.WriteString("}")
}

func prefixEncode (casePaths []string) string {
	buffer := bytes.Buffer{}
	encodeRecursive(&buffer, casePaths)
	return buffer.String()
}
