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
	"testing"
)

// Test

func TestMessages (t *testing.T) {
	// Write message to buffer.
	msg := MsgExecuteBinary { "foo.exe", "--single", "c:/", "*" }
	buf := bytes.NewBuffer([]byte{})
	WriteMessage(buf, &msg)

	// Deserialize message from buffer.
	msg2, err := ReadMessage(bytes.NewBuffer(buf.Bytes()))
	if err != nil { panic(err) }
	decoded := msg2.(*MsgExecuteBinary)

	if decoded.BinaryName != "foo.exe" {
		t.Errorf("expecting deserialized msg.BinaryName to be '%s', got '%s'", msg.BinaryName, msg.BinaryName)
	}

	if decoded.Parameters != "--single" {
		t.Errorf("expecting deserialized msg.Parameters to be '%s', got '%s'", msg.Parameters, msg.Parameters)
	}

	if decoded.WorkingDir != "c:/" {
		t.Errorf("expecting deserialized msg.WorkingDir to be '%s', got '%s'", msg.WorkingDir, msg.WorkingDir)
	}

	if decoded.CaseList != "*" {
		t.Errorf("expecting deserialized msg.CaseList to be '%s', got '%s'", msg.CaseList, msg.CaseList)
	}
}
