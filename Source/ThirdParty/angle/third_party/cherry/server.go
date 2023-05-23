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

package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"./third_party/websocket"
	"log"
	"net/http"
	"net/url"
	"reflect"
	"./cherry"
	"./rtdb"
	"./service"
	"regexp"
	"time"
	"strconv"
	"io"
	"io/ioutil"
	"strings"
)

var rtdbServer	*rtdb.Server
var testRunner	*cherry.TestRunner
var rpcServices	*service.Library
var objectModel	*rtdb.ObjectModel

// \todo [petri] is there a better place for this?

func EncodeJSONRPC (method string, params interface{}) ([]byte, error) {
	type Message struct {
		JsonRPC		string			`json:"jsonrpc"`
		Method		string			`json:"method"`
		Params		[]interface{}	`json:"params"`
	}
	return json.Marshal(Message{
		JsonRPC:	"2.0",
		Method:		method,
		Params:		[]interface{}{ params },
	})
}

func debugStr (s string) string {
	if len(s) > 100 {
		return s[0:97] + "..."
	} else {
		return s
	}
}

// Websocket handling.

func wsHandler (w http.ResponseWriter, r *http.Request) {
	conn, err := websocket.Upgrade(w, r, nil, 1024, 1024)
	if _, ok := err.(websocket.HandshakeError); ok {
		http.Error(w, "Not a websocket handshake", 400)
		return
	} else if err != nil {
		log.Println(err)
		return
	}
	log.Println("[socket] connection established")
	defer conn.Close()

	// Channels.
	type msgReceived struct {
		content	[]byte
		err		error
	}

	type sendMessage struct {
		content	[]byte
	}

	connQueue := make(chan interface{}, 1000) // \note A too small capacity causes deadlock; this is a temporary fix.

	// RTDB listener callbacks.
	onSubscribeObject := func(objects []rtdb.Object) {
		// Send initial object to client.
		log.Printf("[socket] send %d subscribed object to client\n", len(objects))
		encoded, err := EncodeJSONRPC("rtdb.InitObjects", objects)
		if err != nil { panic(err) }
		connQueue <- sendMessage{ encoded }
	}

	onUpdateObjects := func(changes []rtdb.Update) {
		// \todo [petri] currently handled inside server thread -- move to client thread instead?
		// \todo [petri] we should be sending {id:ops}, but changes instead contains values
		getObjIds := func() []string {
			names := make([]string, len(changes))
			for ndx, change := range changes { names[ndx] = change.ObjId }
			return names
		}
		log.Printf("[socket] update client objects: %q\n", getObjIds())

		type UpdateObjects struct {
			Changes []rtdb.Update `json:"changes"`
		}

		update := UpdateObjects {
			Changes: changes,
		}

		encoded, err := EncodeJSONRPC("rtdb.UpdateObjects", update)
		// \todo [petri] what to do on error?!
		if err == nil {
			connQueue <- sendMessage{ encoded }
		}
	}

	// Create client.
	listener := rtdbServer.NewListener(onSubscribeObject, onUpdateObjects)
	rpcClient := cherry.NewRPCClient(listener)

	// Handle message reading in separate goroutine.
	connectionClosed := make(chan struct{})
	go func() {
		// Handle incoming messages in this thread.
		for {
			select {
				case <-connectionClosed:
					return
				default:
					_, input, err := conn.ReadMessage()
					connQueue <- msgReceived{ input, err }
					if err != nil { <-connectionClosed; return }
			}
		}
	}()

	// Handle socket connection.
	func() {
		for {
			op := <- connQueue
			switch op.(type) {
				case msgReceived:
					msg := op.(msgReceived)
					if msg.err != nil {
						log.Printf("[socket] error reading message: %s\n", msg.err)
						return
					}

					result, err := rpcServices.CallJSON(rpcClient, msg.content)
					if err == nil {
						log.Printf("[socket] result: %s\n", debugStr(string(result)))
						err = conn.WriteMessage(websocket.TextMessage, result)
						if err != nil { log.Printf("[socket] WARNING: unable to write message: %s\n", err); return }
					} else {
						log.Printf("[socket] WARNING: invalid rpc call '%s': '%s'\n", string(msg.content), err)
						// \todo [petri] return error!
					}

				case sendMessage:
					// Send message to client.
					msg := op.(sendMessage)
					err = conn.WriteMessage(websocket.TextMessage, msg.content)
					if err != nil { log.Printf("[socket] WARNING: unable to write message: %s\n", err); return }
			}
		}
	}()

	connectionClosed <- struct{}{}

	// Cleanup.
	log.Printf("[socket] destroy listener\n")
	rtdbServer.DestroyListener(listener)

	// Close channel and eat all messages (to avoid blocking senders).
	close(connQueue)
	for _ = range connQueue {}

	log.Println("[socket] client disconnected")
}

// Helper for handling GET requests of the form /uriDirectoryName/param .
func handleSingleParamGETRequest (response http.ResponseWriter, request *http.Request, uriDirectoryName string, writeResponse func(param string) error) {
	if request.Method != "GET" {
		http.Error(response, "Invalid request", 400)
		return
	}

	uri, err := url.ParseRequestURI(request.RequestURI)
	if err != nil {
		log.Printf("[getrequest] Error when parsing URI: %v\n", err)
		http.Error(response, err.Error(), 404)
		return
	}

	re, _ := regexp.Compile(fmt.Sprintf("/%s/(.*)", uriDirectoryName))
	param := re.FindStringSubmatch(uri.Path)[1]

	err = writeResponse(param)
	if err != nil {
		log.Printf("[getrequest] Finished with error: %v\n", err)
		http.Error(response, err.Error(), 404)
		return
	}
	log.Printf("[getrequest] Finished successfully\n")
}

// Batch execution log export request handler.
func executionLogExportHandler (response http.ResponseWriter, request *http.Request) {
	handleSingleParamGETRequest(response, request, "executionLog", func(batchResultId string) error {
		log.Printf("[execlog] Handling request for batch '%s'\n", batchResultId)
		str, err := testRunner.QueryBatchExecutionLog(batchResultId)
		if err != nil { return err }
		_, err = io.WriteString(response, str)
		return err
	})
}

type batchResultExportHttpResponse struct {
	response http.ResponseWriter
}

func (w batchResultExportHttpResponse) Write (p []byte) (int, error) {
	return w.response.Write(p)
}

func (w batchResultExportHttpResponse) SetFilename (name string) {
	w.response.Header().Add("Content-Disposition", "attachment; filename=" + strconv.Quote(name))
}

// QPA export request handler.
func exportHandler (response http.ResponseWriter, request *http.Request) {
	handleSingleParamGETRequest(response, request, "export", func(batchResultId string) error {
		log.Printf("[export] Handling request for batch '%s'\n", batchResultId)
		return cherry.WriteBatchResultExport(batchResultExportHttpResponse{response}, rtdbServer, batchResultId)
	})
}

// QPA import request handler.
func importHandler (response http.ResponseWriter, request *http.Request) {
	if request.Method != "POST" || request.RequestURI != "/import/" {
		http.Error(response, "Invalid request", 400)
		return
	}

	parts, err := request.MultipartReader()
	if err != nil {
		http.Error(response, "Expected a multipart upload", 400)
		return
	}

	log.Printf("[import] Received request with Content-Length %d\n", request.ContentLength)

	anyImportSucceeded := false
	anyImportFailed := false

	for {
		file, err := parts.NextPart();
		if err != nil {
			break
		}

		startTime := time.Now()
		batchResultDefaultName := "Import-" + startTime.Format("2006-Jan-02 15:04:05")
		err = testRunner.ImportBatch(batchResultDefaultName, file, request.ContentLength)
		if err != nil {
			log.Printf("[import] Import failed with error %v\n", err)
			anyImportFailed = true
		} else {
			log.Printf("[import] Single import finished\n")
			anyImportSucceeded = true
		}

		file.Close()
	}

	request.Body.Close()

	if !anyImportFailed {
		// no failures
		response.WriteHeader(http.StatusOK)
	} else if !anyImportSucceeded {
		// no successes
		http.Error(response, "Import failed", 500)
	} else {
		// both failures and successes
		http.Error(response, "Partial failure", 207)
	}
}

// Garbage in, strings split by newlines and comments removed out.
func splitAndTrimTestSetFilters (setFilters string) []string {
	cleanFilters := make([]string, 0)
	commentEraser := regexp.MustCompile(`#.*$`)

	for _, filter := range strings.Split(strings.Replace(setFilters,"\r\n","\n", -1), "\n") {
		noComments := commentEraser.ReplaceAllString(filter, "")
		clean := strings.TrimSpace(noComments)
		if len(clean) > 0 {
			cleanFilters = append(cleanFilters, clean)
		}
	}
	return cleanFilters
}

func importTestSetHandler (response http.ResponseWriter, request *http.Request) {
	if request.Method != "POST" || request.RequestURI != "/importTestSet/" {
		http.Error(response, "Invalid request", 400)
		return
	}

	parts, err := request.MultipartReader()
	if err != nil {
		http.Error(response, "Expected a multipart upload", 400)
		return
	}

	log.Printf("[test set import] Received request with Content-Length %d\n", request.ContentLength)

	anyImportFailed := false

	var setName string
	var setFilters string

	for {
		part, err := parts.NextPart();
		if err != nil {
			break
		}

		data, err := ioutil.ReadAll(part)
		if err != nil {
			log.Printf("[test set import] Reading upload failed with error %v\n", err)
			anyImportFailed = true
		} else {
			switch part.FormName() {
			case "set-name":
				setName = string(data)
			case "set-filters":
				setFilters = string(data)
			}
		}
		part.Close()
	}

	request.Body.Close()

	filterList := splitAndTrimTestSetFilters(setFilters)
	if !anyImportFailed && len(setName) > 0 && len(filterList) > 0 {
		err = cherry.AddTestSet(rtdbServer, setName, filterList)
		if err != nil {
			log.Printf("[test set import] Import failed with error %v\n", err)
			http.Error(response, "Import failed", 500)
		} else {
			log.Printf("[test set import] Imported test set %s with %d filters\n", setName, len(filterList))
			response.WriteHeader(http.StatusOK)
		}
	} else {
		log.Printf("[test set import] Tried to import empty filter set or empty set name or other failure.\n")
		http.Error(response, "Import failed", 500)
	}
}

// Mapping of third party locations to desired server locations
// This allows us to remap the locations for release packages or when versions change
func setUpFileMappings() {
	type ServerFileMapping struct {
		SourceRootDir string
		ServerPrefix  string
	}

	serverFileMappings := []ServerFileMapping{
		{"third_party/ui-bootstrap",			"/ui-bootstrap/"},
		{"third_party/angular",					"/lib/angular/"},
		{"third_party/ui-router",		        "/lib/ui-router/"},
		{"third_party/jquery",					"/lib/jquery/"},
		{"third_party/spin",					"/lib/spin/"},
		{"third_party/angular-spinner",			"/lib/angular-spinner/"},
		{"third_party/bootstrap",				"/lib/bootstrap/"},
		{"third_party/sax",						"/lib/sax/"},
		{"third_party/underscore",				"/lib/underscore/"},
 		{"third_party/angular-tree-control",	"/lib/angular-tree-control/"}}

	// Special case the main license
	http.HandleFunc("/LICENSE", func(w http.ResponseWriter, r *http.Request) {
		http.ServeFile(w, r, "LICENSE")
	})

	// The client hierarchy served as-is
	fs := http.Dir("client")
	fileHandler := http.FileServer(fs)
	http.Handle("/", fileHandler)

	// Re-map third-party to point to the listed directories
	for _, mapping := range serverFileMappings {
		bootStrapFs := http.Dir(mapping.SourceRootDir)
		bootStrapFileHandler := http.StripPrefix(mapping.ServerPrefix, http.FileServer(bootStrapFs))
		http.Handle(mapping.ServerPrefix, bootStrapFileHandler)
	}
}

// Main

func main () {
	port := flag.Int("port", 8080, "port to serve on")
	dbName := flag.String("db", "Cherry.db", "database file name (use :memory: for in-memory)")
	// \todo [2014-10-02 pyry] Temporary workaround to make cherry usable on non-SSD systems.
	//						   Real fix is to write better DB backend.
	dbSyncIo := flag.Bool("db-sync-io", true, "use synchronous IO in DB backend")
	flag.Parse()

	// Initialize Cherry object model.
	objectModel := rtdb.NewObjectModel(cherry.GetObjectTypes())

	// Create RTDB instance.
	log.Println("[main] create sql backend")
	rtdbBackend, err := rtdb.NewSQLiteBackend(*dbName, *dbSyncIo)
	if err != nil { log.Println(err); return }
	log.Println("[main] create rtdb")
	rtdbServer, err = rtdb.NewServer(objectModel, rtdbBackend)
	if err != nil { log.Println(err); return }

	// Initialize database data model.
	cherry.InitDB(rtdbServer)

	cherry.StartADBDeviceListPoller(rtdbServer, 2 * time.Second)

	// Initialize RPC services.
	testRunner = cherry.NewTestRunner(rtdbServer)
	rpcHandler := cherry.NewRPCHandler(rtdbServer, testRunner)
	rpcServices = service.NewServiceLibrary(
		reflect.TypeOf((*cherry.RPCClient)(nil)),
		[]service.HandlerSpec{
			service.HandlerSpec{ "rtdb", rpcHandler },
		})

	// Setup http handling.
	setUpFileMappings()

	http.HandleFunc("/ws", wsHandler)
	http.HandleFunc("/executionLog/", executionLogExportHandler)
	http.HandleFunc("/export/", exportHandler)
	http.HandleFunc("/import/", importHandler)
	http.HandleFunc("/importTestSet/", importTestSetHandler)

	// Fire up http server!
	addr := fmt.Sprintf("127.0.0.1:%d", *port)
	log.Printf("Listening on port %d\n", *port)
	err = http.ListenAndServe(addr, nil)
	log.Println(err.Error())
}
