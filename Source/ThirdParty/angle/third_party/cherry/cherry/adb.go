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
	"os/exec"
	"bytes"
	"bufio"
	"strings"
	"errors"
	"../rtdb"
	"time"
	"strconv"
	"fmt"
	"log"
)

type commandError struct {
	cmdName		string
	cmdArgs		[]string
	subErr		error
	stdErr		string
}

func indent (str string, numSpaces int) string {
	indentation := strings.Repeat(" ", numSpaces)
	numNewlines := strings.Count(str, "\n")
	return indentation + strings.Replace(str, "\n", "\n" + indentation, numNewlines-1)
}

func (err commandError) Error () string {
	result := fmt.Sprintf("command '%s' with arguments [", err.cmdName)
	for ndx, arg := range err.cmdArgs {
		if ndx > 0 {
			result += ", "
		}
		result += "'" + arg + "'"
	}
	result += fmt.Sprintf("] gave '%v', with the following stderr:\n%s\n", err.subErr, strings.TrimSuffix(indent(err.stdErr, 4), "\n"))

	return result
}

func getSystemCommandOutput (command string, args ...string) (string, error) {
	cmd					:= exec.Command(command, args...)
	outputBuffer		:= bytes.Buffer{}
	errOutputBuffer		:= bytes.Buffer{}

	cmd.Stdout = &outputBuffer
	cmd.Stderr = &errOutputBuffer

	err := cmd.Run()
	if err != nil {
		return "", commandError {
			cmdName:	command,
			cmdArgs:	args,
			subErr:		err,
			stdErr:		errOutputBuffer.String(),
		}
	}

	return outputBuffer.String(), nil
}

func runCommands (commands ...*exec.Cmd) error {
	for _, cmd := range commands {
		stdErr := bytes.Buffer{}
		cmd.Stderr = &stdErr
		err := cmd.Run()
		if err != nil {
			return commandError {
				cmdName:	cmd.Args[0],
				cmdArgs:	cmd.Args[1:],
				subErr:		err,
				stdErr:		stdErr.String(),
			}
		}
	}
	return nil
}

func lines (str string) []string {
	scanner := bufio.NewScanner(strings.NewReader(str))
	result := []string{}
	for scanner.Scan() {
		result = append(result, scanner.Text())
	}
	return result
}

type adbDeviceInfo struct {
	serialNumber	string
	state			string
	qualifiers		map[string]string
}

func parseADBDeviceInfo (infoStr string) (adbDeviceInfo, error) {
	infoParts := strings.Fields(infoStr)

	if len(infoParts) < 1 {
		return adbDeviceInfo{}, errors.New("No device info present")
	}

	deviceInfo := adbDeviceInfo {
		serialNumber:	infoParts[0],
		state:			"",
		qualifiers:		map[string]string{},
	}

	infoRest := infoParts[1:]

	for _, infoPart := range infoRest {
		keyValue := strings.SplitN(infoPart, ":", 2)
		if len(keyValue) == 1 {
			if deviceInfo.state != "" {
				deviceInfo.state += " "
			}
			deviceInfo.state += keyValue[0]
		} else {
			deviceInfo.qualifiers[keyValue[0]] = keyValue[1]
		}
	}

	return deviceInfo, nil
}

func getADBDeviceInfos () ([]adbDeviceInfo, error) {
	deviceInfoStr, err := getSystemCommandOutput("adb", "devices", "-l")
	if err != nil { return []adbDeviceInfo{}, err }

	deviceInfoLines			:= lines(deviceInfoStr)
	deviceInfos				:= []adbDeviceInfo{}
	serialNumbers			:= map[string]struct{}{} // Keep track to avoid duplicates (sometimes adb gives those).
	// There may be irrelevant lines at the beginning of the output,
	// like info about the ADB daemon starting. Skip those.
	deviceListStartFound	:= false

	for _, line := range deviceInfoLines {
		if deviceListStartFound {
			info, err := parseADBDeviceInfo(line)
			if err == nil {
				if _, alreadyIn := serialNumbers[info.serialNumber]; !alreadyIn {
					serialNumbers[info.serialNumber] = struct{}{}
					deviceInfos = append(deviceInfos, info)
				}
			}
		} else if strings.Trim(line, " ") == "List of devices attached" {
			deviceListStartFound = true
		}
	}

	return deviceInfos, nil
}

type adbPortForwardInfo struct {
	serialNumber	string
	localProtocol	string
	localPort		int
	remoteProtocol	string
	remotePort		int
}

func parseADBPortSpec (specStr string) (string, int, error) {
	parts := strings.SplitN(specStr, ":", 2)
	if len(parts) != 2 { return "", 0, errors.New("Expected 2 colon-separated fields") }
	port, err := strconv.Atoi(parts[1])
	if err != nil { return "", 0, errors.New("Expected second field to be valid integer") }
	return parts[0], port, nil
}

func parseADBPortForwardInfo (infoStr string) (adbPortForwardInfo, error) {
	infoParts := strings.Fields(infoStr)
	if len(infoParts) != 3 {
		return adbPortForwardInfo{}, errors.New("Expected 3 whitespace-delimited fields")
	}

	localProtocol, localPort, err := parseADBPortSpec(infoParts[1])
	if err != nil { return adbPortForwardInfo{}, fmt.Errorf("Invalid local port spec; %v", err) }
	remoteProtocol, remotePort, err := parseADBPortSpec(infoParts[2])
	if err != nil { return adbPortForwardInfo{}, fmt.Errorf("Invalid remote port spec; %v", err) }

	return adbPortForwardInfo {
		serialNumber:		infoParts[0],
		localProtocol:		localProtocol,
		localPort:			localPort,
		remoteProtocol:		remoteProtocol,
		remotePort:			remotePort,
	}, nil
}

func getADBPortForwardInfos () ([]adbPortForwardInfo, error) {
	forwardInfoStr, err := getSystemCommandOutput("adb", "forward", "--list")
	if err != nil { return []adbPortForwardInfo{}, err }

	forwardInfoLines	:= lines(forwardInfoStr)
	forwardInfos		:= []adbPortForwardInfo{}

	for _, line := range forwardInfoLines {
		info, err := parseADBPortForwardInfo(line)
		if err == nil {
			forwardInfos = append(forwardInfos, info)
		}
	}

	return forwardInfos, nil
}

func serialNumberToDeviceId (ser string) string {
	return "adb:" + ser
}

func StartADBDeviceListPoller (rtdbServer *rtdb.Server, interval time.Duration) {
	go func () {
		previousInfos		:= []adbDeviceInfo{}
		previousErrorStr	:= ""

		for {
			select {
				case <- time.After(interval):
					// Get devices from ADB and compare to previous; update connection list according to changes.

					currentInfos, err	:= getADBDeviceInfos()
					currentErrorStr		:= ""
					if err != nil { currentErrorStr = err.Error() }

					// potentiallyNewlyNamedDevices will contain the devices that might have gotten
					// a name ("model" qualifier in adb device list) since the last update. These are
					// devices whose state has changed, and newly connected devices.
					potentiallyNewlyNamedDevices	:= []adbDeviceInfo{}

					opSet							:= rtdb.NewOpSet()

					// Compare previousInfos and currentInfos to detect removed and added devices. We
					// do it this way (instead of just replacing the whole list) because otherwise
					// the AngularJS-using GUI will think that the whole list has changed, which will
					// result in inconveniences if the user is editing non-changing adb device configs.

					// The way this is implemented treats additions in the middle of the list as if
					// all items after the added item were removed, then that item appended, and finally
					// the removed items re-appended; in such cases, the operation sequence is rather
					// suboptimal, but with how adb seems to report the devices (new items are appended
					// to the end), these cases shouldn't occur often.

					curInfoNdx := 0 // Current index in the device list being updated.

					// Detect devices that were present both previously and currently (and may have had their
					// states changed), and also devices that were removed since the previous time.
					for _, oldInfo := range previousInfos {
						if curInfoNdx < len(currentInfos) && oldInfo.serialNumber == currentInfos[curInfoNdx].serialNumber {
							// Device is still connected. Check possible state change.
							if oldInfo.state != currentInfos[curInfoNdx].state {
								opSet.Call(typeADBDeviceConnectionList, "adbDeviceConnectionList", "SetConnectionState", curInfoNdx, currentInfos[curInfoNdx].state)
								if currentInfos[curInfoNdx].qualifiers["model"] != "" {
									potentiallyNewlyNamedDevices = append(potentiallyNewlyNamedDevices, currentInfos[curInfoNdx])
								}
							}
							curInfoNdx++
						} else {
							// Device was disconnected since the previous time.
							opSet.Call(typeADBDeviceConnectionList, "adbDeviceConnectionList", "Remove", curInfoNdx)
						}
					}

					// Add new devices to the end of the list. Also create configs for previously unseen devices.
					for _, newInfo := range currentInfos[curInfoNdx:] {
						deviceId	:= serialNumberToDeviceId(newInfo.serialNumber)
						modelName	:= newInfo.qualifiers["model"]

						{
							var config DeviceConfig
							err := rtdbServer.GetObject(deviceId, &config)

							if err != nil {
								// Device hasn't been seen previously; create a new config for it.
								log.Printf("[adb] detected new device '%s' (model name '%s')\n", newInfo.serialNumber, modelName)
								newConfig := DeviceConfig {
									IsADBDevice:		true,
									ADBSerialNumber:	newInfo.serialNumber,
									Name:				modelName,
									TargetAddress:		"127.0.0.1",
									TargetPort:			51116,
									CommandLine:		"--deqp-watchdog=enable --deqp-crashhandler=enable",
								}
								opSet.Call(typeDeviceConfig, deviceId, "Init", newConfig)
							} else if config.Name == "" && modelName != "" {
								// Device has been seen previously, but didn't have a name, and now does.
								potentiallyNewlyNamedDevices = append(potentiallyNewlyNamedDevices, newInfo)
							}
						}

						connection := ADBDeviceConnection {
							DeviceId:	deviceId,
							State:		newInfo.state,
						}
						opSet.Call(typeADBDeviceConnectionList, "adbDeviceConnectionList", "Append", connection)
					}

					// Set device config names for devices that don't have those yet, but do have a model name in the adb output.
					for _, info := range potentiallyNewlyNamedDevices {
						deviceId	:= serialNumberToDeviceId(info.serialNumber)
						modelName	:= info.qualifiers["model"]

						var config DeviceConfig
						err := rtdbServer.GetObject(deviceId, &config)
						if err != nil { panic(err) }

						if config.Name == "" {
							log.Printf("[adb] got model name for previously unnamed device '%s'; setting name to '%s'\n", info.serialNumber, modelName)
							opSet.Call(typeDeviceConfig, deviceId, "SetName", modelName)
						}
					}

					if previousErrorStr != currentErrorStr {
						opSet.Call(typeADBDeviceConnectionList, "adbDeviceConnectionList", "SetError", currentErrorStr)
					}

					err = rtdbServer.ExecuteOpSet(opSet)
					if err != nil { panic(err) }

					previousInfos		= currentInfos
					previousErrorStr	= currentErrorStr
			}
		}
	}()
}

func LaunchAndroidExecServer (adbSerialNumber string, port int) error {
	portSpec := "tcp:" + strconv.Itoa(port)

	return runCommands(
		exec.Command("adb", "-s", adbSerialNumber, "forward", portSpec, portSpec),
		exec.Command("adb", "-s", adbSerialNumber, "shell", "setprop", "log.tag.dEQP", "DEBUG"),
		exec.Command("adb", "-s", adbSerialNumber, "shell", "am", "start", "-n", "com.drawelements.deqp/.execserver.ServiceStarter", "--ei", "port", strconv.Itoa(port)),
	)
}

func RelaunchAndroidExecServer (adbSerialNumber string, port int) error {
	return runCommands(
		exec.Command("adb", "-s", adbSerialNumber, "shell", "am", "start", "-n", "com.drawelements.deqp/.execserver.ServiceStarter", "--ei", "port", strconv.Itoa(port)),
	)
}

func RemoveADBPortForward (adbSerialNumber string, localPort int) error {
	forwardInfos, err := getADBPortForwardInfos()
	if err != nil { return err }

	anyRemoved := false
	for _, info := range forwardInfos {
		if info.localProtocol == "tcp" && info.serialNumber == adbSerialNumber && info.localPort == localPort {
			err := runCommands(exec.Command("adb", "-s", info.serialNumber, "forward", "--remove", info.localProtocol + ":" + strconv.Itoa(info.localPort)))
			if err != nil { return err }
			anyRemoved = true
		}
	}

	if !anyRemoved { return errors.New("No matching forwards found") }

	return nil
}
