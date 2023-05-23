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

package rtdb

import (
	"bytes"
	"encoding/gob"
	_ "../third_party/go-sqlite3"
	"database/sql"
	"fmt"
	"log"
	"reflect"
)

type SQLiteBackend struct {
	db *sql.DB
}

// SQLiteBackend implementation

func (backend *SQLiteBackend) upgrade () error {
	db := backend.db
	db.Exec("CREATE TABLE IF NOT EXISTS meta (id INT PRIMARY KEY, schemaVersion INT)")
	var schemaVersion int
	err := db.QueryRow("SELECT schemaVersion FROM meta").Scan(&schemaVersion)

	// Initialize schema, if none found in db.
	if err != nil {
		log.Println("[rtdb] no schema version found in database, create version 1")
		db.Exec("INSERT INTO meta (id, schemaVersion) VALUES (0, 1)")
		schemaVersion = 1
	}

	// Upgrade to version 2.
	if schemaVersion == 1 {
		log.Println("[rtdb] update schema to version 2")
		db.Exec("UPDATE meta SET schemaVersion=2 WHERE schemaVersion=1")
		schemaVersion = 2
	}

	// Upgrade to version 3.
	if schemaVersion == 2 {
		log.Println("[rtdb] update schema to version 3")

		_, err = db.Exec("CREATE TABLE objects (id VARCHAR(64) NOT NULL, version INT NOT NULL, value TEXT NOT NULL, ops TEXT NOT NULL, PRIMARY KEY(id, version))")
		if err != nil { return err }
		_, err = db.Exec("CREATE INDEX objects_id_version ON objects (id, version)")
		if err != nil { return err }
		_, err = db.Exec("CREATE TABLE version (id INT PRIMARY KEY, version INT NOT NULL)")
		if err != nil { return err }
		_, err = db.Exec("INSERT INTO version (id, version) VaLUES (0, 1)")
		if err != nil { return err }

		db.Exec("UPDATE meta SET schemaVersion=3 WHERE schemaVersion=2")
		schemaVersion = 3
	}

	// Upgrade to version 4.
	if schemaVersion == 3 {
		log.Println("[rtdb] update schema to version 4")

		_, err = db.Exec("DROP TABLE objects")
		if err != nil { return err }

		_, err = db.Exec("CREATE TABLE objects (id VARCHAR(128) NOT NULL, version INT NOT NULL, value BLOB NOT NULL, PRIMARY KEY(id, version))")
		if err != nil { return err }

		db.Exec("UPDATE meta SET schemaVersion=4 WHERE schemaVersion=3")
		schemaVersion = 4
	}

	// Upgrade to version 5.
	if schemaVersion == 4 {
		log.Println("[rtdb] update schema to version 5")

		_, err := db.Exec("DROP TABLE objects")
		if err != nil { return err }

		_, err = db.Exec("CREATE TABLE objects (type VARCHAR(64) NOT NULL, id VARCHAR(128) NOT NULL, version INT NOT NULL, value BLOB NOT NULL, PRIMARY KEY(type, id, version))")

		db.Exec("UPDATE meta SET schemaVersion=5 WHERE schemaVersion=4")
		schemaVersion = 5
	}

	// Upgrade to version 6.
	if schemaVersion == 5 {
		log.Println("[rtdb] update schema to version 6")

		_, err := db.Exec("DROP TABLE objects")
		if err != nil { return err }

		_, err = db.Exec("DROP TABLE version")
		if err != nil { return err }

		_, err = db.Exec("CREATE TABLE objects (type VARCHAR(64) NOT NULL, id VARCHAR(128) NOT NULL, value BLOB NOT NULL, PRIMARY KEY(type, id))")
		if err != nil { return err }

		db.Exec("UPDATE meta SET schemaVersion=6 WHERE schemaVersion=5")
		schemaVersion = 6
	}

	return nil
}

// Backend API

func NewSQLiteBackend (fileName string, syncIo bool) (Backend, error) {
	// Open connection to MySQL.
	db, err := sql.Open("sqlite3", fileName)
	if err != nil { return nil, err }

	// Create backend.
	backend := SQLiteBackend {
		db: db,
	}

	if !syncIo { backend.db.Exec("PRAGMA synchronous = OFF") }

	// Upgrade schema to latest version.
	if err = backend.upgrade(); err != nil {
		return nil, err
	}

	return &backend, nil
}

func (backend *SQLiteBackend) GetExplicitTypeObject (objType string, objId string, dst ObjectBase) error {
	// Query from database.
	var objValue []byte
	err := backend.db.QueryRow("SELECT value FROM objects WHERE type=? AND id=?", objType, objId).Scan(&objValue)
	if err != nil { return err }

	// Create object.
	reader := bytes.NewReader(objValue)
	dec := gob.NewDecoder(reader)
	dec.Decode(dst)

	// Call object post-load.
	dst.PostLoad()

	return nil
}

func (backend *SQLiteBackend) GetObject (objId string, dst ObjectBase) error {
	// Resolve type.
	ptr := reflect.ValueOf(dst)
	if ptr.Kind() != reflect.Ptr { return fmt.Errorf("[rtdb] must pass pointer to dst (got %s)", ptr) }

	direct := reflect.Indirect(ptr)
	if direct.Kind() != reflect.Struct { return fmt.Errorf("[rtdb] pointer must be to a struct (got %s)", direct) }

	return backend.GetExplicitTypeObject(direct.Type().Name(), objId, dst)
}

func (backend *SQLiteBackend) WriteObjects (writeOps []WriteOp) error {
	// Begin transaction.
	tx, err := backend.db.Begin()
	if err != nil { panic(err) } // \todo [petri] can we handle this sanely?

	// Enqueue all object writes.
	// \todo [petri] version conflicts are *NOT* handled here!
	for _, writeOp := range writeOps {
		// writeOps: ObjId, Value, Ops
		buffer := bytes.Buffer{}
		enc := gob.NewEncoder(&buffer)
		enc.Encode(writeOp.Value)
		if err != nil { return err }

		typeName := reflect.TypeOf(writeOp.Value).Elem().Name()

		_, err = tx.Exec("INSERT OR REPLACE INTO objects (type, id, value) VALUES (?, ?, ?)", typeName, writeOp.ObjId, buffer.Bytes())
		if err != nil { return err }
	}

	// Commit transaction.
	err = tx.Commit()
	if err != nil { return err }

	return nil
}
