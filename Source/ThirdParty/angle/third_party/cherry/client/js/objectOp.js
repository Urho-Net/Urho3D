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

function copyProperties(dst, src)
{
	for (var k in src)
		dst[k] = src[k];
}

(function(exports)
{
	// Operation handlers for RTDB objects.
	// \note The $postInitialize function is ran for each object (if
	//		 it exists for the object type) in rtdb's InitObjects in
	//		 services.js. Note that $postInitialize is not related to
	//		 Init, which is just another object operation.

	exports.opHandlers =
	{
		// DeviceConfig

		DeviceConfig:
		{
			Init: function(value, src)
			{
				copyProperties(value, src);
			},

			// \todo [petri] implement as custom operation?
			Delete: function(value)
			{
				console.log('DELETE ' + JSON.stringify(value));
				value = {};
			},

			SetName: function(value, name)
			{
				value.name = name;
			}
		},

		// DeviceConfigList

		DeviceConfigList:
		{
			Init: function(value, devices)
			{
				if (!value.devices)
					value.devices = devices;
			},

			Append: function(value, device)
			{
				for (var ndx = 0; ndx < value.devices.length; ndx++)
				{
					if (value.devices[ndx].id == device.id)
					{
						value.devices[ndx] = device;
						return;
					}
				}

				value.devices.push(device);
			},

			Remove: function(value, deviceId)
			{
				for (var ndx = 0; ndx < value.devices.length; ndx++)
				{
					var dev = value.devices[ndx];
					if (dev.id == deviceId)
					{
						value.devices.splice(ndx, 1);
						return;
					}
				}
			}
		},

		// TestCaseResult

		TestCaseResult:
		{
			Init: function(value, src)
			{
				copyProperties(value, src);
			},

			SetLog: function(value, log)
			{
				value.log = log;
			}
		},

		// TestCaseHeader

		TestCaseHeader:
		{
			Init: function(value, src)
			{
				copyProperties(value, src);
			},

			SetStatus: function(value, status)
			{
				value.status = status;
			},

			SetResult: function(value, caseType, status, result)
			{
				value.caseType	= caseType;
				value.status	= status;
				value.result	= result;
			}
		},

		TestCaseTreeGroup:
		{
			Init: function(value, src)
			{
				copyProperties(value, src);
			},

			UpdateStats: function(value, delta)
			{
				value.numSuccess				+= delta.deltaSuccess;
				value.numFailure				+= delta.deltaFailure;
				value.numCrash					+= delta.deltaCrash;
				value.numTimeout				+= delta.deltaTimeout;
				value.numQualityWarning			+= delta.deltaQualityWarning;
				value.numCompatibilityWarning	+= delta.deltaCompatibilityWarning;
				value.numNotSupported			+= delta.deltaNotSupported;
				value.numResourceError			+= delta.deltaResourceError;
				value.numInternalError			+= delta.deltaInternalError;
			},

			AddCase: function(value)
			{
				value.numTotalCases++;
			}
		},

		// TestCaseList

		TestCaseList:
		{
			Init: function(value, src)
			{
				copyProperties(value, src);
			},

			Append: function(value, str)
			{
				value.paths.push(str);
			},
		},

		// BatchResult

		BatchResult:
		{
			$postInitialize: function(value)
			{
				value.timestamp = new Date(value.timestamp);
			},

			Init: function(value, src)
			{
				copyProperties(value, src);
				value.timestamp = new Date(value.timestamp);
			},

			SetName: function(value, name)
			{
				console.log('BatchResult.SetName(' + JSON.stringify(name) + ')');
				value.name = name;
			},

			SetStatus: function(value, status)
			{
				console.log('BatchResult.SetStatus(' + JSON.stringify(status) + ')');
				value.status = status;
			},

			SetSessionInfo: function(value, info)
			{
				var zeroTime = new Date();
				zeroTime.setUTCFullYear(1, 0, 1);
				zeroTime.setUTCHours(0, 0, 0, 0);

				if (value.name === '')									{ value.name				= info.resultName; }
				if (value.timestamp.getTime() === zeroTime.getTime())	{ value.timestamp			= new Date(info.timestamp); }
				if (value.releaseName === '')							{ value.releaseName			= info.releaseName; }
				if (value.releaseId === '')								{ value.releaseId			= info.releaseId; }
				if (value.buildTargetName === '')						{ value.buildTargetName		= info.buildTargetName; }
				if (value.candyTargetName === '')						{ value.candyTargetName		= info.candyTargetName; }
				if (value.candyConfigName === '')						{ value.candyConfigName		= info.candyConfigName; }

				if (value.execParams.targetAddress === '')				{ value.execParams.targetAddress			= info.targetAddress; }
				if (value.execParams.targetPort === 0)					{ value.execParams.targetPort				= info.targetPort; }
				if (value.execParams.spawnLocalProcess === '')			{ value.execParams.spawnLocalProcess		= info.spawnLocalProcess; }
				if (value.execParams.deviceId === '')					{ value.execParams.deviceId					= info.deviceId; }

				if (value.execParams.testBinaryName === '')				{ value.execParams.testBinaryName			= info.testBinaryName; }
				if (value.execParams.testBinaryCommandLine === '')		{ value.execParams.testBinaryCommandLine	= info.testBinaryCommandLine; }
				if (value.execParams.testBinaryWorkingDir === '')		{ value.execParams.testBinaryWorkingDir		= info.testBinaryWorkingDir; }
			},

			SetInitProgress: function(value, progress)
			{
				value.initProgress = progress;
			}
		},

		// BatchResultExecutionLog

		BatchResultExecutionLog:
		{
			Init: function(value)
			{
				value.content = "";
			},

			Append: function(value, part)
			{
				value.content += part;
			},
		},

		// BatchResultList

		BatchResultList:
		{
			Append: function(value, args)
			{
				value.batchResults.push(args)
			},

			SetBatchResultName: function(value, id, name)
			{
				console.log('BatchResultList.SetBatchResultName(' + JSON.stringify(id) + ', ' + JSON.stringify(name) + ')');
				var results = value.batchResults;
				for (var ndx = 0; ndx < results.length; ndx++)
				{
					if (results[ndx].id == id)
					{
						results[ndx].name = name;
						return;
					}
				}

				// \todo [petri] warning..
			}
		},

		// ActiveBatchResultList

		ActiveBatchResultList:
		{
			Append: function(value, id)
			{
				value.batchResultIds.push(id)
			},

			Remove: function(value, id)
			{
				for (var ndx = 0; ndx < value.batchResultIds.length; ndx++)
				{
					if (value.batchResultIds[ndx] === id)
					{
						value.batchResultIds.splice(ndx, 1);
						return;
					}
				}
			}
		},

		// DeviceBatchQueue

		DeviceBatchQueue:
		{
			Init: function(value)
			{
				value.batchResultIds = [];
			},

			Append: function(value, id)
			{
				value.batchResultIds.push(id);
			},

			Remove: function(value, id)
			{
				for (var ndx = 0; ndx < value.batchResultIds.length; ndx++)
				{
					if (value.batchResultIds[ndx] === id)
					{
						value.batchResultIds.splice(ndx, 1);
						return;
					}
				}
			},

			Move: function(value, srcNdx, dstNdx)
			{
				var elem = value.batchResultIds[srcNdx];
				if (srcNdx < dstNdx)
				{
					for (var ndx = srcNdx; ndx < dstNdx; ndx++)
						value.batchResultIds[ndx] = value.batchResultIds[ndx+1];
				}
				else
				{
					for (var ndx = srcNdx; ndx > dstNdx; ndx--)
						value.batchResultIds[ndx] = value.batchResultIds[ndx-1];
				}
				value.batchResultIds[dstNdx] = elem;
			}
		},

		// DeviceBatchQueueList

		DeviceBatchQueueList:
		{
			Append: function(value, id)
			{
				value.queueIds.push(id);
			}
		},

		// ADBDeviceConnectionList

		ADBDeviceConnectionList:
		{
			Clear: function(value)
			{
				value.connections	= [];
				value.error			= "";
			},

			SetError: function(value, err)
			{
				value.error = err;
			},

			SetConnectionState: function(value, ndx, state)
			{
				value.connections[ndx].state = state;
			},

			Remove: function(value, ndx)
			{
				value.connections.splice(ndx, 1);
			},

			Append: function(value, connection)
			{
				value.connections.push(connection);
			}
		},

		// TestSetList
		TestSetList:
		{
			Append: function(value, setHeader)
			{
				value.testSetHeaders.push(setHeader)
			},

			Remove: function(value, testSetId)
			{
				for (var ndx = 0; ndx < value.testSetHeaders.length; ndx++)
				{
					var set = value.testSetHeaders[ndx];
					if (set.id == testSetId)
					{
						value.testSetHeaders.splice(ndx, 1);
						return;
					}
				}
			}
		},
	};
})(typeof exports === 'undefined' ? this['objectop'] = {} : exports);
