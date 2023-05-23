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
	"fmt"
	"io"
	"log"
	"net"
	"os/exec"
	"strings"
	"time"
)

// CommLinkTcpIp

type CommLinkParams struct {
	SpawnProcessPath	string
	TargetAddress		string
	TargetPort			int
}

type CommLinkTcpIp struct {
	params				CommLinkParams

	spawnProcessCommand	*exec.Cmd
	spawnProcessOutput	bytes.Buffer

	socket				net.Conn

	appendCommLogLine	func(string)
}

func NewCommLinkTcpIp (params CommLinkParams, appendCherryLogLine func(string)) *CommLinkTcpIp {
	appendCommLogLine := func(content string) {
		log.Printf("[comm] %s\n", content)
		appendCherryLogLine(content)
	}

	return &CommLinkTcpIp {
		params:				params,
		appendCommLogLine:	appendCommLogLine,
	}
}

// Constants

const (
	KEEP_ALIVE_INTERVAL_SECONDS		= 5
	KEEP_ALIVE_TIMEOUT_MINUTES		= 20
	STOP_REQUEST_TIMEOUT_SECONDS	= 10
)

// Enums

type ExecStatusCode int

const (
	EXEC_STATUS_DONE			ExecStatusCode = iota
	EXEC_STATUS_LINK_ERROR
	EXEC_STATUS_TIMEOUT
)

// TestExecutorEvent

type TestExecutorEvent interface {
}

type EventProcessStarted struct {
}

type EventProcessLaunchFailed struct {
	reason			string
}

type EventSessionInfoRead struct {
	sessionInfo		BatchSessionInfo
}

type EventInfoLogRead struct {
	infoLog			string
}

type EventTestCaseStarted struct {
	testCasePath	string
}

type EventTestCaseFinished struct {
	path			string
	status			TestStatusCode
	log				string
}

type EventExecutionFinished struct {
	status			ExecStatusCode
}

// LineSplitter

type LineSplitter struct {
	buffer		string
}

func (s *LineSplitter) Push (data string) {
	s.buffer = s.buffer + data
}

func (s *LineSplitter) GetLines () []string {
	pieces := strings.Split(s.buffer, "\n")
	s.buffer = pieces[len(pieces)-1]
	return pieces[:len(pieces)-1]
}

// TcpIpLink

func (link *CommLinkTcpIp) handleConnection (conn net.Conn, eventChannel chan TestExecutorEvent, stopRequest <-chan struct{}) {
	defer log.Printf("[comm] handleConnection() returning..\n")

	type received struct {
		msg		Message
		err		error
	}
	receiveQueue := make(chan received, 32)

	// Spawn message reader.
	// \todo [petri] clean way to close this thread .. currently exits with error when socket closed
	go func() {
		for {
			msg, err := ReadMessage(conn)
			receiveQueue <- received{ msg, err }
			if err != nil { return }
		}
	}()

	log.Printf("[comm] writer goroutine active!\n")

	// Keepalive state.
	lastKeepaliveSent		:= time.Now()
	lastKeepaliveReceived	:= time.Now()

	// QPA parsing.
	lineSplitter	:= LineSplitter{}
	qpaParserQueue	:= make(chan TestExecutorEvent, 4)
	qpaParser		:= CreateLogContainerParser(qpaParserQueue)

	isStopRequested			:= false // stopRequest signaled at least once?
	isStopExecMsgPending	:= false // stopRequest signaled after we last sent MsgStopExecution?
	var firstStopRequestArrival time.Time

	// \todo [nuutti] This is a kludge to avoid sending MsgStopExecution before we've
	//		 received any log data; seems that sending it too soon won't have the
	//		 desired effect. Should investigate if this is a problem in the
	//		 execserver's end.
	hasAnyLogDataArrived := false

	handleParserQueue := func () {
		// Get result from queue if available.
		select {
			case event := <-qpaParserQueue:
				// \todo [petri] handle some events locally? only write to channel in parser?
				eventChannel <- event

			default:
				// Nothing
		}
	}

	var finishStatus ExecStatusCode

	// Handle connection.
	linkLoop:
	for {
		select {
			case <-stopRequest:
				log.Printf("[comm] got stop request\n")
				isStopExecMsgPending = true
				if !isStopRequested {
					isStopRequested = true
					firstStopRequestArrival = time.Now()
				}

			case received := <- receiveQueue:
				msg := received.msg
				err := received.err
				if err == io.EOF {
					link.appendCommLogLine("Remote host closed connection")
					finishStatus = EXEC_STATUS_DONE
					break linkLoop
				} else if err != nil {
					log.Printf("[comm] GOT ERROR FROM READER: %s\n", err)
					link.appendCommLogLine("Comm link terminating")
					finishStatus = EXEC_STATUS_LINK_ERROR
					break linkLoop
				} else {
					// Handle incoming messages.
					switch msg.(type) {
						case *MsgProcessStarted:
							log.Printf("[comm] process started!\n")
							eventChannel <- EventProcessStarted{}

						case *MsgProcessLaunchFailed:
							launchFailed := msg.(*MsgProcessLaunchFailed)
							log.Printf("[comm] WARNING: remote process launch failed: %s!\n", launchFailed.Reason)
							eventChannel <- EventProcessLaunchFailed{ launchFailed.Reason }

						case *MsgProcessFinished:
							log.Printf("[comm] remote process finished!\n")
							conn.Close() // \todo [petri] use CloseRead() to avoid error about reading from closed connection

						case *MsgProcessLogData:
							hasAnyLogDataArrived = true
							logData := msg.(*MsgProcessLogData)
							lineSplitter.Push(logData.Content)
							for _, line := range lineSplitter.GetLines() {
								qpaParser.ParseLine(line)
								handleParserQueue()
							}

						case *MsgInfo:
							info := msg.(*MsgInfo)
							eventChannel <- EventInfoLogRead{ info.Content }

						case *MsgKeepAlive:
							lastKeepaliveReceived = time.Now()

						default:
							log.Printf("[comm] warning: unknown message received: %T\n", msg)
					}
				}

			// \todo [petri] compute based on keepalive timing
			case <-time.After(100 * time.Millisecond):
				// nada..
		}

		// Check client keepalive timeout.
		timeoutDiff := time.Now().Sub(lastKeepaliveReceived)
		if timeoutDiff >= KEEP_ALIVE_TIMEOUT_MINUTES * time.Minute {
			link.appendCommLogLine("Client timeout")
			// \todo[petri] handle timeout properly
			finishStatus = EXEC_STATUS_TIMEOUT
			break linkLoop
		}

		if isStopRequested && time.Now().Sub(firstStopRequestArrival) >= STOP_REQUEST_TIMEOUT_SECONDS * time.Second {
			link.appendCommLogLine("Stop request timeout")
			finishStatus = EXEC_STATUS_TIMEOUT
			break linkLoop
		}

		// Send keepalive.
		keepaliveDiff := time.Now().Sub(lastKeepaliveSent)
		if keepaliveDiff >= KEEP_ALIVE_INTERVAL_SECONDS * time.Second {
			log.Printf("[comm] send keepalive\n")
			msgKeepAlive := MsgKeepAlive{}
			err := WriteMessage(conn, &msgKeepAlive)
			if err != nil {
				finishStatus = EXEC_STATUS_LINK_ERROR
				break linkLoop
			}
			lastKeepaliveSent = time.Now()
		}

		// Send MsgStopExecution if needed.
		if hasAnyLogDataArrived && isStopExecMsgPending {
			link.appendCommLogLine("Sending stop command to execserver")
			err := WriteMessage(conn, &MsgStopExecution{})
			if err != nil {
				link.appendCommLogLine(fmt.Sprintf("Got error when sending stop command: %s", err))
				finishStatus = EXEC_STATUS_LINK_ERROR
				break linkLoop
			}
			isStopExecMsgPending = false
		}
	}

	// \note If test run stopped abnormally, a crashed test case may be unterminated;
	//		 terminate it now so it doesn't keep us from continuing in the future.
	if !isStopRequested {
		qpaParser.Terminate()
		handleParserQueue()
	}

	eventChannel <- EventExecutionFinished{ finishStatus }
}

func (link *CommLinkTcpIp) Start () error {
	params := link.params

	// Spawn local process (if any).
	if link.params.SpawnProcessPath != "" {
		link.appendCommLogLine(fmt.Sprintf("Spawn process '%s'", params.SpawnProcessPath))
		parts	:= strings.Split(params.SpawnProcessPath, " ") // split executable and args
		cmdName	:= parts[0]
		portArg	:= fmt.Sprintf("--port=%d", link.params.TargetPort)
		cmdArgs	:= append([]string{ portArg }, parts[1:]...)
		cmd		:= exec.Command(cmdName, cmdArgs...)
		output	:= bytes.Buffer{}
		cmd.Stdin	= strings.NewReader("<local process input>")
		cmd.Stdout	= &output
		err := cmd.Start()
		if err != nil { return err }

		link.spawnProcessCommand = cmd
		link.spawnProcessOutput	= output

		// Sleep for a bit to let process start up properly.
		// \todo [petri] better way to handle this?
		time.Sleep(300 * time.Millisecond)
	}

	// Connect to target.
	addr := fmt.Sprintf("%s:%d", params.TargetAddress, params.TargetPort)
	link.appendCommLogLine(fmt.Sprintf("Connect to '%s'", addr))
	conn, err := net.Dial("tcp", addr)
	if err != nil {
		link.maybeKillLocalProcess()
		return err
	}

	link.socket = conn

	// Send hello.
	// \todo [petri] Candy never sends this..?
//	hello := MsgHello{ Version: ?? }
//	err = WriteMessage(conn, &msgExec)
//	if err != nil { return err }

	return nil
}

func (link *CommLinkTcpIp) Stop () {
	log.Printf("[comm] CommLinkTcpIp.Stop()\n")

	// Close connection to execserver.
	if link.socket != nil {
		link.socket.Close()
	}

	link.maybeKillLocalProcess()
}

func (link *CommLinkTcpIp) maybeKillLocalProcess () {
	// Shut down local process, if any.
	if link.spawnProcessCommand != nil {
		link.appendCommLogLine("Shutting down local process...")
		cmd := link.spawnProcessCommand

		// Kill process.
		err := cmd.Process.Kill()
		if err != nil {
			link.appendCommLogLine(fmt.Sprintf("WARNING: error terminating local process: %s", err))
		} else {
			link.appendCommLogLine("Local process terminated successfully")
		}
	}
}

type CommLinkExecParams struct {
								// For example:
	binaryName		string		// "Debug/deqp-gles2.exe",
	commandLine		string		// "--deqp-watchdog=enable --deqp-crashhandler=enable --deqp-visibility=hidden --deqp-gl-config-name=rgba8888d24s8ms0",
	workingDir		string		// "../../candy-build/deqp-wgl/modules/gles2",
	testCasePaths	string		// "{dEQP-GLES2{..}}"
}

func (link *CommLinkTcpIp) Execute (params CommLinkExecParams, eventChannel chan TestExecutorEvent, stopRequest <-chan struct{}) error {
	log.Printf("[comm] CommLinkTcpIp.Execute(binary='%s')\n", params.binaryName)

	// Send test execution message.
	msgExec := MsgExecuteBinary{
		BinaryName:		params.binaryName,
		Parameters:		params.commandLine,
		WorkingDir:		params.workingDir,
		CaseList:		params.testCasePaths,
	}
	link.appendCommLogLine(fmt.Sprintf("Sending command to execute binary '%s' to execserver", params.binaryName))
	err := WriteMessage(link.socket, &msgExec)
	if err != nil { return err }

	// Spawn goroutine for connection.
	go link.handleConnection(link.socket, eventChannel, stopRequest)

	return nil
}
