// Copyright 2015 Google Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

'use strict';

var TEST_STATUS_CODE =
{
	PASS:					'TSCPass',
	FAIL:					'TSCFail',
	QUALITY_WARNING:		'TSCQualityWarning',
	COMPATIBILITY_WARNING:	'TSCCompatibilityWarning',
	PENDING:				'TSCPending',
	RUNNING:				'TSCRunning',
	NOT_SUPPORTED:			'TSCNotSupported',
	RESOURCE_ERROR:			'TSCResourceError',
	INTERNAL_ERROR:			'TSCInternalError',
	CANCELED:				'TSCCanceled',
	TIMEOUT:				'TSCTimeout',
	CRASH:					'TSCCrash',
	DISABLED:				'TSCDisabled',
};

function testStatusCodeHumanReadable (status)
{
	return status.slice(3);
}

function isTestStatusCodeFinished (status)
{
	switch (status)
	{
		case TEST_STATUS_CODE.PASS:						return true;
		case TEST_STATUS_CODE.FAIL:						return true;
		case TEST_STATUS_CODE.QUALITY_WARNING:			return true;
		case TEST_STATUS_CODE.COMPATIBILITY_WARNING:	return true;
		case TEST_STATUS_CODE.PENDING:					return false;
		case TEST_STATUS_CODE.RUNNING:					return false;
		case TEST_STATUS_CODE.NOT_SUPPORTED:			return true;
		case TEST_STATUS_CODE.RESOURCE_ERROR:			return true;
		case TEST_STATUS_CODE.INTERNAL_ERROR:			return true;
		case TEST_STATUS_CODE.CANCELED:					return true;
		case TEST_STATUS_CODE.TIMEOUT:					return true;
		case TEST_STATUS_CODE.CRASH:					return true;
		case TEST_STATUS_CODE.DISABLED:					return false;
		default:
			throw new Error('Invalid test status code');
	}
}

var BATCH_STATUS_CODE =
{
	INITIALIZING:	'BSCInitializing',
	IMPORTING:		'BSCImporting',
	PENDING:		'BSCPending',
	RUNNING:		'BSCRunning',
	FINISHED:		'BSCFinished',
	CANCELED:		'BSCCanceled',
	INTERRUPTED:	'BSCInterrupted',
};

function batchStatusCodeHumanReadable (status)
{
	return status.slice(3);
}
