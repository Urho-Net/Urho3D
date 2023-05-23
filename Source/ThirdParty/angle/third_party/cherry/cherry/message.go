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
	"encoding/binary"
	"fmt"
	"io"
	"log"
)

const (
	MessageHeaderSize = 8	// msgSize:int32, msgType:int32
)

type Message interface {
	GetType		() MessageType
	Serialize	(io.Writer) error
	Deserialize	(io.Reader) error
}

// \todo [petri] implement serialization using reflection instead of manually?

type MessageType int32

const (
	// Commands.
	MSG_HELLO			MessageType	= 100
	MSG_TEST						= 101
	MSG_KEEPALIVE					= 102
	MSG_EXECUTE_BINARY				= 111
	MSG_STOP_EXECUTION				= 112

	// Responses.
	MSG_PROCESS_STARTED				= 200
	MSG_PROCESS_LAUNCH_FAILED		= 201
	MSG_PROCESS_FINISHED			= 202
	MSG_PROCESS_LOG_DATA			= 203
	MSG_INFO						= 204
)

func createMessage (msgType MessageType) (Message, error) {
	switch msgType {
		case MSG_HELLO:					return &MsgHello{}, nil
		case MSG_TEST:					return &MsgTest{}, nil
		case MSG_KEEPALIVE:				return &MsgKeepAlive{}, nil
		case MSG_EXECUTE_BINARY:		return &MsgExecuteBinary{}, nil
		case MSG_STOP_EXECUTION:		return &MsgStopExecution{}, nil

		case MSG_PROCESS_STARTED:		return &MsgProcessStarted{}, nil
		case MSG_PROCESS_LAUNCH_FAILED:	return &MsgProcessLaunchFailed{}, nil
		case MSG_PROCESS_FINISHED:		return &MsgProcessFinished{}, nil
		case MSG_PROCESS_LOG_DATA:		return &MsgProcessLogData{}, nil
		case MSG_INFO:					return &MsgInfo{}, nil
	}

	return nil, fmt.Errorf("CreateMessage(): invalid message type %v", msgType)
}

// Util

func read (r io.Reader, v interface{}) error {
	return binary.Read(r, binary.BigEndian, v)
}

func write (w io.Writer, v interface{}) error {
	return binary.Write(w, binary.BigEndian, v)
}

func readString (r io.Reader, v *string) error {
	/* \todo [petri] this is probably horribly slow implementation.. */
	buf := make([]byte, 0)
	for {
		var b byte
		err := read(r, &b)
		if err != nil { return err }
		if b == 0 { break }
		buf = append(buf, b)
	}
	*v = string(buf)
	return nil
}

func writeString (w io.Writer, v string) error {
	_, err := w.Write([]byte(v))
	if err != nil { return err }
	var eos byte = 0
	err = write(w, eos)
	return err
}

// MsgHello

type MsgHello struct {
	Version		int32
}

func (msg *MsgHello) GetType () MessageType { return MSG_HELLO }

func (msg *MsgHello) Serialize (w io.Writer) error {
	/* \todo [petri] chain err through write() calls? */
	if err := write(w, msg.Version); err != nil { return err }
	return nil
}

func (msg *MsgHello) Deserialize (r io.Reader) error {
	if err := read(r, &msg.Version); err != nil { return err }
	return nil
}

// MsgTest

type MsgTest struct {
}

func (msg *MsgTest) GetType () MessageType { return MSG_TEST }

func (msg *MsgTest) Serialize (w io.Writer) error {
	return nil
}

func (msg *MsgTest) Deserialize (r io.Reader) error {
	return nil
}

// MsgKeepAlive

type MsgKeepAlive struct {
}

func (msg *MsgKeepAlive) GetType () MessageType { return MSG_KEEPALIVE }

func (msg *MsgKeepAlive) Serialize (w io.Writer) error {
	return nil
}

func (msg *MsgKeepAlive) Deserialize (r io.Reader) error {
	return nil
}

// MsgExecuteBinary

type MsgExecuteBinary struct {
	BinaryName	string
	Parameters	string
	WorkingDir	string
	CaseList	string
}

func (msg *MsgExecuteBinary) GetType () MessageType { return MSG_EXECUTE_BINARY }

func (msg *MsgExecuteBinary) Serialize (w io.Writer) error {
	if err := writeString(w, msg.BinaryName); err != nil { return err }
	if err := writeString(w, msg.Parameters); err != nil { return err }
	if err := writeString(w, msg.WorkingDir); err != nil { return err }
	if err := writeString(w, msg.CaseList); err != nil { return err }
	return nil
}

func (msg *MsgExecuteBinary) Deserialize (r io.Reader) error {
	if err := readString(r, &msg.BinaryName); err != nil { return err }
	if err := readString(r, &msg.Parameters); err != nil { return err }
	if err := readString(r, &msg.WorkingDir); err != nil { return err }
	if err := readString(r, &msg.CaseList); err != nil { return err }
	return nil
}

// MsgStopExecution

type MsgStopExecution struct {
}

func (msg *MsgStopExecution) GetType () MessageType { return MSG_STOP_EXECUTION }

func (msg *MsgStopExecution) Serialize (w io.Writer) error {
	return nil
}

func (msg *MsgStopExecution) Deserialize (r io.Reader) error {
	return nil
}

// MsgProcessStarted

type MsgProcessStarted struct {
}

func (msg *MsgProcessStarted) GetType () MessageType { return MSG_PROCESS_STARTED }

func (msg *MsgProcessStarted) Serialize (w io.Writer) error {
	return nil
}

func (msg *MsgProcessStarted) Deserialize (r io.Reader) error {
	return nil
}

// MsgProcessLaunchFailed

type MsgProcessLaunchFailed struct {
	Reason		string
}

func (msg *MsgProcessLaunchFailed) GetType () MessageType { return MSG_PROCESS_LAUNCH_FAILED }

func (msg *MsgProcessLaunchFailed) Serialize (w io.Writer) error {
	if err := writeString(w, msg.Reason); err != nil { return err }
	return nil
}

func (msg *MsgProcessLaunchFailed) Deserialize (r io.Reader) error {
	if err := readString(r, &msg.Reason); err != nil { return err }
	return nil
}

// MsgProcessFinished

type MsgProcessFinished struct {
	ExitCode	int32
}

func (msg *MsgProcessFinished) GetType () MessageType { return MSG_PROCESS_FINISHED }

func (msg *MsgProcessFinished) Serialize (w io.Writer) error {
	if err := write(w, msg.ExitCode); err != nil { return err }
	return nil
}

func (msg *MsgProcessFinished) Deserialize (r io.Reader) error {
	if err := read(r, &msg.ExitCode); err != nil { return err }
	return nil
}

// MsgProcessLogData

type MsgProcessLogData struct {
	Content		string
}

func (msg *MsgProcessLogData) GetType () MessageType { return MSG_PROCESS_LOG_DATA }

func (msg *MsgProcessLogData) Serialize (w io.Writer) error {
	if err := writeString(w, msg.Content); err != nil { return err }
	return nil
}

func (msg *MsgProcessLogData) Deserialize (r io.Reader) error {
	if err := readString(r, &msg.Content); err != nil { return err }
	return nil
}

// MsgInfo

type MsgInfo struct {
	Content		string
}

func (msg *MsgInfo) GetType () MessageType { return MSG_INFO }

func (msg *MsgInfo) Serialize (w io.Writer) error {
	if err := writeString(w, msg.Content); err != nil { return err }
	return nil
}

func (msg *MsgInfo) Deserialize (r io.Reader) error {
	if err := readString(r, &msg.Content); err != nil { return err }
	return nil
}

// Utility for reading/writing messages with headers.

func WriteMessage (w io.Writer, msg Message) error {
	// Serialize payload.
	payload := bytes.NewBuffer([]byte{})
	err := msg.Serialize(payload)
	if err != nil { return err }

	// Write header.
	var msgSize	= (int32)(MessageHeaderSize + payload.Len())
	var msgType MessageType = msg.GetType()

	err = write(w, msgSize)
	if err != nil { return err }
	err = write(w, msgType)
	if err != nil { return err }

	// Write payload.
	bytes := payload.Bytes()
	numWritten, err := w.Write(bytes)
	if err != nil { return err }
	if numWritten != len(bytes) {
		log.Printf("[msg] WARNING: WROTE %d OF %d BYTES\n", numWritten, len(bytes))
	}

	return nil
}

func ReadMessage (r io.Reader) (Message, error) {
	// \todo [petri] implement
	var msgLen	int32
	var msgType	MessageType
	err := read(r, &msgLen)
	if err != nil { return nil, err }
	err = read(r, &msgType)
	if err != nil { return nil, err }

	msg, err := createMessage(msgType)
	if err != nil { return nil, err }
	err = msg.Deserialize(r)
	if err != nil { return nil, err }

	return msg, nil
}
