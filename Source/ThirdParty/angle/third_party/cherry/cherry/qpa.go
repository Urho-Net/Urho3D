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
	"time"
	"bytes"
	"log"
	"strconv"
	"io"
)

type BatchSessionInfo struct {
	ADBSerialNumber			string		`json:"adbSerialNumber"` // Empty for non-adb devices.

	ReleaseName				string		`json:"releaseName"`
	ReleaseId				string		`json:"releaseId"`
	BuildTargetName			string		`json:"buildTargetName"`
	ResultName				string		`json:"resultName"`
	Timestamp				time.Time	`json:"timestamp"`

	TargetAddress			string		`json:"targetAddress"`
	TargetPort				int			`json:"targetPort"`
	SpawnLocalProcess		string		`json:"spawnLocalProcess"`
	DeviceId				string		`json:"deviceId"`
	TestBinaryName			string		`json:"testBinaryName"`
	TestBinaryCommandLine	string		`json:"testBinaryCommandLine"`
	TestBinaryWorkingDir	string		`json:"testBinaryWorkingDir"`

	CandyTargetName			string		`json:"candyTargetName"`
	CandyConfigName			string		`json:"candyConfigName"`
}

type LogContainerParser struct {
	sessionInfo			BatchSessionInfo
	isInsideSession		bool
	currentCasePath		string
	currentCaseLog		bytes.Buffer

	resultQueue			chan<- TestExecutorEvent
}

type LogContainerWriter struct {
	dst					io.Writer
	err					error
	isSessionStarted	bool
	isFinished			bool
}

func CreateLogContainerParser (resultQueue chan<- TestExecutorEvent) *LogContainerParser {
	return &LogContainerParser {
		resultQueue: resultQueue,
	}
}

func split2 (s string, delim string) (string, string) {
	strs := strings.SplitN(s, delim, 2)
	last := ""
	if len(strs) == 2 { last = strs[1] }
	return strs[0], last
}

func parseTimestamp (timestamp string) time.Time {
	// \todo [nuutti] Timezones
	if t, err := time.Parse("2006-01-02 15:04:05Z", timestamp); err == nil { return t }
	if t, err := time.Parse("1/2/2006 3:04:05 PM", timestamp); err == nil { return t }
	if t, err := time.Parse("02/01/2006 15:04:05", timestamp); err == nil { return t }
	if t, err := time.Parse("2.1.2006 15:04:05", timestamp); err == nil { return t }
	return time.Time{}
}

func parseTestStatusCode (statusString string) TestStatusCode {
	switch "TSC" + statusString {
		case string(TEST_STATUS_CODE_PASS):						return TEST_STATUS_CODE_PASS
		case string(TEST_STATUS_CODE_FAIL):						return TEST_STATUS_CODE_FAIL
		case string(TEST_STATUS_CODE_QUALITY_WARNING):			return TEST_STATUS_CODE_QUALITY_WARNING
		case string(TEST_STATUS_CODE_COMPATIBILITY_WARNING):	return TEST_STATUS_CODE_COMPATIBILITY_WARNING
		case string(TEST_STATUS_CODE_PENDING):					return TEST_STATUS_CODE_PENDING
		case string(TEST_STATUS_CODE_RUNNING):					return TEST_STATUS_CODE_RUNNING
		case string(TEST_STATUS_CODE_NOT_SUPPORTED):			return TEST_STATUS_CODE_NOT_SUPPORTED
		case string(TEST_STATUS_CODE_RESOURCE_ERROR):			return TEST_STATUS_CODE_RESOURCE_ERROR
		case string(TEST_STATUS_CODE_INTERNAL_ERROR):			return TEST_STATUS_CODE_INTERNAL_ERROR
		case string(TEST_STATUS_CODE_CANCELED):					return TEST_STATUS_CODE_CANCELED
		case string(TEST_STATUS_CODE_TIMEOUT):					return TEST_STATUS_CODE_TIMEOUT
		case string(TEST_STATUS_CODE_CRASH):					return TEST_STATUS_CODE_CRASH
		case string(TEST_STATUS_CODE_DISABLED):					return TEST_STATUS_CODE_DISABLED
		default:												return TestStatusCode("")
	}
}

func parseIntOrDefault (s string, def int) int {
	i, err := strconv.Atoi(s)
	if err != nil { return def }
	return i
}

func (parser *LogContainerParser) parseSessionInfo (line string) {
	key, value := split2(line, " ")
	if value == "" {
		log.Println("[qpa] warning: empty value in #sessionInfo")
	} else if value[0] == '"' {
		last := strings.LastIndex(value, `"`)
		if last == 0 {
			log.Println("[qpa] warning: missing double quote in #sessionInfo line")
		} else {
			value = value[1 : last]
		}
	}

	switch key {
		case "adbSerialNumber":					parser.sessionInfo.ADBSerialNumber			= value
		case "candyTargetName":					parser.sessionInfo.CandyTargetName			= value
		case "resultName":						parser.sessionInfo.ResultName				= value
		case "targetName":						parser.sessionInfo.BuildTargetName			= value
		case "releaseName":						parser.sessionInfo.ReleaseName				= value
		case "releaseId":						parser.sessionInfo.ReleaseId				= value
		case "configName":						parser.sessionInfo.CandyConfigName			= value
		case "timestamp":						parser.sessionInfo.Timestamp				= parseTimestamp(value)
		case "cherryTargetAddress":				parser.sessionInfo.TargetAddress			= value
		case "cherryTargetPort":				parser.sessionInfo.TargetPort				= parseIntOrDefault(value, 0)
		case "cherrySpawnLocalProcess":			parser.sessionInfo.SpawnLocalProcess		= value
		case "cherryDeviceId":					parser.sessionInfo.DeviceId					= value
		case "cherryTestBinaryName":			parser.sessionInfo.TestBinaryName			= value
		case "cherryTestBinaryCommandLine":		parser.sessionInfo.TestBinaryCommandLine	= value
		case "cherryTestBinaryWorkingDir":		parser.sessionInfo.TestBinaryWorkingDir		= value
		default: log.Println("[qpa] warning: unknown #sessionInfo item")
	}
}

func (parser *LogContainerParser) beginSession () {
	parser.resultQueue <- EventSessionInfoRead {
		sessionInfo: parser.sessionInfo,
	}
}

func (parser *LogContainerParser) beginTestCase (casePath string) {
	parser.resultQueue <- EventTestCaseStarted {
		testCasePath: casePath,
	}
	parser.currentCasePath = casePath
}

func (parser *LogContainerParser) endTestCase (status TestStatusCode) {
	parser.resultQueue <- EventTestCaseFinished {
		path:		parser.currentCasePath,
		status:		status,
		log:		parser.currentCaseLog.String(),
	}

	parser.currentCasePath = ""
	parser.currentCaseLog.Truncate(0)
}

func parseLogStatusCode (logStatus string) TestStatusCode {
	parsed := parseTestStatusCode(logStatus)
	if parsed == TestStatusCode("") {
		switch logStatus {
			case "Watchdog timeout occurred.":	return TEST_STATUS_CODE_TIMEOUT
			default:							return TEST_STATUS_CODE_CRASH
		}
	} else {
		return parsed
	}
}

func (parser *LogContainerParser) Terminate () {
	if parser.currentCasePath != "" {
		parser.endTestCase(TEST_STATUS_CODE_CRASH)
	}
}

func (parser *LogContainerParser) IsInsideSession () bool {
	return parser.isInsideSession
}

func (parser *LogContainerParser) ParseLine (line string) {
	if len(line) > 0 && line[0] == '#' {
		directive, rest := split2(line, " ")

		switch directive {
			case "#sessionInfo":
				if parser.isInsideSession {
					log.Println("[qpa] warning: #sessionInfo after #beginSession; ignoring")
				} else {
					parser.parseSessionInfo(rest)
				}

			case "#beginSession":
				if rest != "" { log.Println("[qpa] warning: garbage after #beginSession; ignoring garbage") }
				if parser.isInsideSession {
					log.Println("[qpa] warning: double #beginSession; ignoring")
				} else {
					parser.beginSession()
					parser.isInsideSession = true
				}

			case "#beginTestCaseResult":
				if !parser.isInsideSession {
					log.Println("[qpa] warning: first test case before #beginSession; assuming session started")
					parser.beginSession()
					parser.isInsideSession = true
				}
				if rest == "" {
					log.Println("[qpa] warning: empty test case name in #beginTestCaseResult; ignoring test case")
				} else {
					if parser.currentCasePath != "" {
						log.Println("[qpa] warning: #beginTestCaseResult when already parsing a test case; terminating current case")
						parser.endTestCase(TEST_STATUS_CODE_INTERNAL_ERROR)
					}
					parser.beginTestCase(rest)
				}

			case "#endTestCaseResult":
				if rest != "" { log.Println("[qpa] warning: garbage after #endTestCaseResult; ignoring garbage") }
				if parser.currentCasePath == "" {
					log.Println("[qpa] warning: #endTestCaseResult when not parsing a test case; ignoring")
				} else {
					parser.endTestCase(TestStatusCode(""))
				}

			case "#terminateTestCaseResult":
				if parser.currentCasePath == "" {
					log.Println("[qpa] warning: #terminateTestCaseResult when not parsing a test case; ignoring")
				} else {
					parser.endTestCase(parseLogStatusCode(rest))
				}

			case "#endSession":
				if rest != "" { log.Println("[qpa] warning: garbage after #endSession; ignoring garbage") }
				if !parser.isInsideSession {
					log.Println("[qpa] warning: #endSession when not parsing a session; ignoring")
				} else {
					if parser.currentCasePath != "" {
						log.Println("[qpa] warning: #endSession inside test case result; terminating current case")
						parser.endTestCase(TEST_STATUS_CODE_INTERNAL_ERROR)
					}
					parser.isInsideSession = false
				}

			default:
				if parser.currentCasePath != "" {
					parser.currentCaseLog.WriteString(line)
					parser.currentCaseLog.WriteString("\n")
				}
		}
	} else if parser.currentCasePath != "" {
		// Case data
		parser.currentCaseLog.WriteString(line)
		parser.currentCaseLog.WriteString("\n")
	} else {
		// empty line outside test case, ignore
	}
}

func CreateLogContainerWriter (dst io.Writer) *LogContainerWriter {
	writer := &LogContainerWriter {
		dst:				dst,
		err:				nil,
		isSessionStarted:	false,
		isFinished:			false,
	}

	return writer
}

func (writer *LogContainerWriter) BeginSession (batch BatchResult, config DeviceConfig) error {
	if writer.isSessionStarted { panic("[qpa] writer.BeginSession called twice") }

	writer.writeSessionInfo(BatchSessionInfo {
		ADBSerialNumber:		config.ADBSerialNumber,

		ReleaseName:			batch.ReleaseName,
		ReleaseId:				batch.ReleaseId,
		BuildTargetName:		batch.BuildTargetName,
		ResultName:				batch.Name,
		Timestamp:				batch.Timestamp,

		TargetAddress:			batch.ExecParams.TargetAddress,
		TargetPort:				batch.ExecParams.TargetPort,
		SpawnLocalProcess:		batch.ExecParams.SpawnLocalProcess,
		DeviceId:				batch.ExecParams.DeviceId,
		TestBinaryName:			batch.ExecParams.TestBinaryName,
		TestBinaryCommandLine:	batch.ExecParams.TestBinaryCommandLine,
		TestBinaryWorkingDir:	batch.ExecParams.TestBinaryWorkingDir,

		CandyTargetName:		batch.CandyTargetName,
		CandyConfigName:		batch.CandyConfigName,
	})
	writer.write("#beginSession\n")
	writer.isSessionStarted = true
	return writer.err
}

func (writer *LogContainerWriter) write (s string) {
	if writer.err == nil {
		_, writer.err = io.WriteString(writer.dst, s)
	}
}

func (writer *LogContainerWriter) WriteTestCaseResult (header TestCaseHeader, result TestCaseResult) error {
	if !writer.isSessionStarted { panic("[qpa] writer.WriteTestCaseResult called before BeginSession") }
	if writer.isFinished { panic("[qpa] writer.WriteTestCaseResult called after Finish") }

	writer.write("#beginTestCaseResult " + result.Path + "\n")
	writer.write(result.Log)

	status := header.Status
	if status == TEST_STATUS_CODE_RUNNING {
		status = TEST_STATUS_CODE_PENDING // \note Export running cases as pending.
	}
	if isTerminatedTestStatusCode(status) {
		writer.write("#terminateTestCaseResult " + testStatusCodeToString(status) + "\n")
	} else {
		writer.write("#endTestCaseResult\n")
	}

	return writer.err
}

func (writer *LogContainerWriter) EndSession () error {
	if !writer.isSessionStarted { panic("[qpa] writer.EndSession called before BeginSession") }
	if writer.isFinished { panic("[qpa] writer.EndSession() called twice") }

	writer.write("#endSession\n")
	writer.isFinished = true
	return writer.err
}

func (writer *LogContainerWriter) writeSessionInfoLine (key, value string) {
	writer.write("#sessionInfo " + key)
	if value != "" {
		writer.write(" " + value)
	}
	writer.write("\n")
}

func timestampToString (t time.Time) string {
	return t.UTC().Format("2006-01-02 15:04:05Z")
}

func isTerminatedTestStatusCode (status TestStatusCode) bool {
	switch status {
		case TEST_STATUS_CODE_TIMEOUT:			return true
		case TEST_STATUS_CODE_CRASH:			return true
		case TEST_STATUS_CODE_INTERNAL_ERROR:	return true
		case TEST_STATUS_CODE_DISABLED:			return true
		case TEST_STATUS_CODE_CANCELED:			return true
		case TEST_STATUS_CODE_PENDING:			return true
		default:								return false
	}
}

func testStatusCodeToString (status TestStatusCode) string {
	return string(status)[3:]
}

func (writer *LogContainerWriter) writeSessionInfo (session BatchSessionInfo) {
	writer.writeSessionInfoLine("adbSerialNumber",				`"` + session.ADBSerialNumber + `"`)

	writer.writeSessionInfoLine("releaseName",					session.ReleaseName)
	writer.writeSessionInfoLine("releaseId",					session.ReleaseId)
	writer.writeSessionInfoLine("targetName",					`"` + session.BuildTargetName + `"`)
	writer.writeSessionInfoLine("resultName",					`"` + session.ResultName + `"`)
	writer.writeSessionInfoLine("timestamp",					timestampToString(session.Timestamp))

	writer.writeSessionInfoLine("cherryTargetAddress",			`"` + session.TargetAddress + `"`)
	writer.writeSessionInfoLine("cherryTargetPort",				strconv.Itoa(session.TargetPort))
	writer.writeSessionInfoLine("cherrySpawnLocalProcess",		`"` + session.SpawnLocalProcess + `"`)
	writer.writeSessionInfoLine("cherryDeviceId",				`"` + session.DeviceId + `"`)
	writer.writeSessionInfoLine("cherryTestBinaryName",			`"` + session.TestBinaryName + `"`)
	writer.writeSessionInfoLine("cherryTestBinaryCommandLine",	`"` + session.TestBinaryCommandLine + `"`)
	writer.writeSessionInfoLine("cherryTestBinaryWorkingDir",	`"` + session.TestBinaryWorkingDir + `"`)

	// \note These two are legacy. Only write them if they're nonempty, i.e. this batch
	//		 has been imported from a qpa that had them.
	if session.CandyTargetName != "" {
		writer.writeSessionInfoLine("candyTargetName",	`"` + session.CandyTargetName + `"`)
	}
	if session.CandyConfigName != "" {
		writer.writeSessionInfoLine("configName",		`"` + session.CandyConfigName + `"`)
	}
}
