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
	"crypto/rand"
	"encoding/hex"
	"io"
	"regexp"
	"strings"
)

const defaultHumanReadableTimeFormat = "2006-Jan-02 15:04:05"

func genRandomId (length int) string {
	bytes := make([]byte, length)
	_, err := rand.Read(bytes)
	if err != nil { panic(err) } // \todo [petri] can this fail?!
	return hex.EncodeToString(bytes)
}

type CountingReader struct {
	reader	io.Reader
	count	int64
}

func NewCountingReader (reader io.Reader) *CountingReader {
	return &CountingReader {
		reader:		reader,
		count:		0,
	}
}

func (r *CountingReader) Read (p []byte) (n int, err error) {
	n, err = r.reader.Read(p)
	r.count += int64(n)
	return
}

func (r *CountingReader) Count () int64 {
	return r.count
}

func filterTestCaseNames (testCasePaths []string, filters []string) []string {
	// If no filters, return all test cases.
	if len(filters) == 0 {
		return testCasePaths
	}

	// Prepare regexps from filters.
	// \todo [nuutti] Do we want to enforce the simple filter syntax
	//				  (i.e. only plain characters and asterisk wildcards),
	//				  and disallow general regex syntax, in input?
	//				  Currently this allows filters like foo.ba[rz].as?d
	var regExps []*regexp.Regexp
	for _, filter := range filters {
		reStr := strings.Trim(filter, " ")
		reStr = strings.Replace(reStr, ".", "\\.", -1)
		reStr = strings.Replace(reStr, "*", ".*", -1)
		reStr = "^" + reStr + "$"
		re, err := regexp.Compile(reStr)
		// Only use this filter if the regex is valid.
		if err == nil {
			regExps = append(regExps, re)
		}
	}

	// Filter all cases with regexps.
	result := make([]string, 0)
	for _, casePath := range testCasePaths {
		matched := false
		for _, re := range regExps {
			if re.MatchString(casePath) {
				matched = true
				break
			}
		}

		if matched {
			result = append(result, casePath)
		}
	}

	return result
}
