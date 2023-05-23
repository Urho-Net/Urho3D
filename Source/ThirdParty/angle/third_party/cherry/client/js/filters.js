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

function testCaseListResult(testHeader)
{
	if (!testHeader)
		return "";

	if (testHeader.status === TEST_STATUS_CODE.PASS)
	{
		switch (testHeader.caseType)
		{
			case TEST_CASE_TYPE.PERFORMANCE:
			case TEST_CASE_TYPE.ACCURACY:
			case TEST_CASE_TYPE.CAPABILITY:
				return testHeader.result;
		}
	}

	return testStatusCodeHumanReadable(testHeader.status);
}

// Filters

angular.module('cherry.filters', [])

.filter('interpolate', ['version', function(version)
{
	return function(text)
	{
		return String(text).replace(/\%VERSION\%/mg, version);
	}
}])

.filter('reverse', function()
{
	return function(items)
	{
		return Array.isArray(items) ? items.slice().reverse() : [];
	};
})

.filter('encodeURIComponent', function()
{
	return encodeURIComponent;
})

.filter('percent', function()
{
	return function(value)
	{
		return (value * 100.0).toFixed(2) + '%';
	};
})

.filter('testStatusClass', function()
{
	return function(status)
	{
		switch (status)
		{
			case TEST_STATUS_CODE.PASS:						return 'test-status-pass';
			case TEST_STATUS_CODE.FAIL:						return 'test-status-fail';
			case TEST_STATUS_CODE.QUALITY_WARNING:			return 'test-status-quality-warning';
			case TEST_STATUS_CODE.COMPATIBILITY_WARNING:	return 'test-status-compatibility-warning';
			case TEST_STATUS_CODE.PENDING:					return 'test-status-pending';
			case TEST_STATUS_CODE.RUNNING:					return 'test-status-running';
			case TEST_STATUS_CODE.NOT_SUPPORTED:			return 'test-status-not-supported';
			case TEST_STATUS_CODE.RESOURCE_ERROR:			return 'test-status-resource-error';
			case TEST_STATUS_CODE.INTERNAL_ERROR:			return 'test-status-internal-error';
			case TEST_STATUS_CODE.CANCELED:					return 'test-status-canceled';
			case TEST_STATUS_CODE.TIMEOUT:					return 'test-status-timeout';
			case TEST_STATUS_CODE.CRASH:					return 'test-status-crash';
			case TEST_STATUS_CODE.DISABLED:					return 'test-status-disabled';
		}
	}
})

.filter('testStatusHumanReadable', function()
{
	return function(status)
	{
		// \note This filter is used in places where status may be undefined when objects aren't fully loaded yet.
		return status ? testStatusCodeHumanReadable(status) : "";
	}
})

.filter('batchStatusHumanReadable', function()
{
	return function(status)
	{
		// \note This filter is used in places where status may be undefined when objects aren't fully loaded yet.
		return status ? batchStatusCodeHumanReadable(status) : "";
	}
})

.filter('shaderTypeHumanReadable', function()
{
	return function(shaderName)
	{
		switch (shaderName)
		{
			case 'vertex':				return 'Vertex';
			case 'fragment':			return 'Fragment';
			case 'geometry':			return 'Geometry';
			case 'tess-control':		return 'Tessellation Control';
			case 'tess-evaluation':		return 'Tessellation Evaluation';
			case 'compute':				return 'Compute';
		}
	}
})

.filter('buildStatusHumanReadable', function()
{
	return function(shaderName)
	{
		switch (shaderName)
		{
			case 'OK':		return 'OK';
			case 'Fail':	return 'failed';
		}
	}
})

.filter('testCaseListResult', function()
{
	return testCaseListResult;
})

.filter('adbDeviceStateHumanReadable', function()
{
	return function(state)
	{
		if (state === 'device')
			return 'online';
		else
			return state;
	}
})

.filter('adbDeviceStateClass', function()
{
	return function(state)
	{
		if (state === 'device')
			return 'adb-device-state-online';
		else
			return 'adb-device-state-other';
	}
})

;
