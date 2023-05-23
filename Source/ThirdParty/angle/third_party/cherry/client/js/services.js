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

// BatchQueue
//
// Enqueue items and flush them in batch (using setTimeout of 0).

var BatchQueue = function(flushFunc, maxBatchSize)
{
	maxBatchSize = maxBatchSize || 0;

	var queue = [];

	// Flush queue func.
	var flushQueue = function()
	{
		var batchSize	= (maxBatchSize > 0) ? Math.min(maxBatchSize, queue.length) : queue.length;
		var batchItems	= queue.slice(0, batchSize);

		flushFunc(batchItems);

		queue = queue.slice(batchSize);
		if (queue.length !== 0)
			setTimeout(flushQueue, 0);
	};

	this.enqueue = function(item)
	{
		queue.push(item);
		if (queue.length === 1)
			setTimeout(flushQueue, 0);
	};
};

// Services

angular.module('cherry.services', [])

.value('version', '0.0.1')

// WebSockets

.factory('socket', ['$rootScope', '$location', function ($rootScope, $location)
{
	var url = "ws://" + $location.host() + ":" + $location.port() + "/ws";
	var socket = new WebSocket(url);

	var sendQueue		= [];
	var eventHandlers	= {};
	var msgHandlers		= [];
	var statusHandlers	= [];

	var flushInMsgs = function(items)
	{
		for (var msgNdx = 0; msgNdx < items.length; msgNdx++)
		{
			var msgArgs = items[msgNdx];
			for (var ndx = 0; ndx < msgHandlers.length; ndx++)
				msgHandlers[ndx].call(null, socket, msgArgs); // \todo [petri] this?
		}
	};
	var inMsgQueue = new BatchQueue(flushInMsgs, 100);

	socket.onopen = function(ev)
	{
		console.log('[socket] connected (' + sendQueue.length + ' queued)!');
		for (var ndx = 0; ndx < sendQueue.length; ndx++)
			socket.send(sendQueue[ndx]);
		sendQueue = [];

		// \note scope.$apply is wrapped in setTimeout to avoid calling it while angular's digest is already active.
		setTimeout(function()
		{
			$rootScope.$apply(function ()
			{
				for (var ndx = 0; ndx < statusHandlers.length; ndx++)
					statusHandlers[ndx]('connected');
			});
		}, 0);
	};

	socket.onclose = function(ev)
	{
		console.log('[socket] disconnected -- reload!');

		// \note scope.$apply is wrapped in setTimeout to avoid calling it while angular's digest is already active.
		setTimeout(function()
		{
			$rootScope.$apply(function ()
			{
				for (var ndx = 0; ndx < statusHandlers.length; ndx++)
					statusHandlers[ndx]('disconnected');
			});
		}, 0);
	};

	socket.onmessage = function(ev)
	{
		// Push to queue.
		var args = JSON.parse(ev.data);
		inMsgQueue.enqueue(args);
	};

	return {
		onmessage: function (callback)
		{
			msgHandlers.push(callback);
		},

		onStatus: function (callback)
		{
			statusHandlers.push(callback);
		},

		on: function (eventName, callback)
		{
			console.log('[socket] register handler for ' + eventName);
			if (eventHandlers.hasOwnProperty(eventName))
				eventHandlers[eventName].push(callback);
			else
				eventHandlers[eventName] = [callback];
		},

		emit: function (data)
		{
			var msg = JSON.stringify(data);
			if (socket.readyState === WebSocket.OPEN)
				socket.send(msg);
			else
				sendQueue.push(msg);
		}
	};
}])

.factory('rpc', ['$q', 'socket', 'usSpinnerService', function($q, socket, usSpinnerService)
{
	var nextRequestId		= 1;
	var pendingRequests		= {};
	var spinnerSpinning		= false;
	var spinnerStartIssued	= false;
	var modules				= {};

	var updateSpinner = function()
	{
		var shouldBeSpinning = !_.isEmpty(pendingRequests);

		// \todo [petri] use data binding instead of explicit calls?

		if (spinnerSpinning && !shouldBeSpinning)
		{
			spinnerSpinning = false;
			usSpinnerService.stop('rpc-spinner');
		}
		else if (!spinnerSpinning && shouldBeSpinning)
		{
			// Delay spinner start to avoid costly relayout for short rpc queries
			if (!spinnerStartIssued)
			{
				spinnerStartIssued = true;
				setTimeout(function()
				{
					spinnerStartIssued = false;

					var shouldBeSpinning = !_.isEmpty(pendingRequests);
					if (shouldBeSpinning)
					{
						spinnerSpinning = true;
						usSpinnerService.spin('rpc-spinner');
					}
				}, 300);
			}
		}
	};

	var call = function(method)
	{
		var requestId = nextRequestId++;
		var params = Array.prototype.slice.call(arguments, 1)
		console.log('[rpc] call ' + method + ': ' + debugStr(JSON.stringify(params)));
		socket.emit({ jsonrpc:"2.0", id:requestId, method:method, params:params });

		// \todo [petri] possible race condition?
		var deferred = $q.defer();
		pendingRequests[requestId] = deferred;

		updateSpinner();

		return deferred.promise;
	};

	var cast = function(method)
	{
		var requestId = nextRequestId++;
		var params = Array.prototype.slice.call(arguments, 1)
		socket.emit({ jsonrpc:"2.0", id:requestId, method:method, params:params });
		pendingRequests[requestId] = $q.defer(); // not used!
		// \todo [petri] don't create deferred object?

		updateSpinner();
	};

	socket.onmessage(function(socket, args)
	{
		if (args.hasOwnProperty('jsonrpc'))
		{
			if (args.hasOwnProperty('method')) // rpc call by server
			{
				var methodParts	= args.method.split('.'); // \todo [petri] assert two parts?
				var moduleName	= methodParts[0];
				var funcName	= methodParts[1];
				if (modules.hasOwnProperty(moduleName))
				{
					var module = modules[moduleName];
					if (module.hasOwnProperty(funcName))
					{
						var func = module[funcName];
						func.apply(module, args.params);
					}
					else
					{
						// \todo [petri] proper error handling
						console.log('[rpc] ERROR: unknown func ' + funcName + ' in module ' + moduleName);
					}
				}
				else
				{
					// \todo [petri] proper error handling
					console.log('[rpc] ERROR: unknown module ' + moduleName);
				}
			}
			else // result from an rpc call
			{
				console.log('[rpc] result: ' + debugStr(JSON.stringify(args)));
				var requestId	= args.id;
				var deferred	= pendingRequests[requestId];
				delete pendingRequests[requestId];

				if (args.hasOwnProperty('result'))
					deferred.resolve(args.result);
				else
					deferred.reject(args.error);

				updateSpinner();
			}
		}
	});

	var register = function(name, module)
	{
		modules[name] = module;
	};

	return {
		call:		call,
		cast:		cast,
		register:	register
	};
}])

.factory('rtdb', ['$rootScope', 'socket', 'rpc', function($rootScope, socket, rpc)
{
	console.log('[rtdb] init');
	var subscribedObjects	= {}; // objectKey(objType, objId): {count:<int>, obj:<obj>}

	var ListenerSet = function()
	{
		var nextId			= 1;
		var listeners		= {}
		var idTypeCallbacks	= {} // callbacks[objId][objType] :: List(callbacks)

		this.addListener = function(objId, objType, callback)
		{
			var listenerId	= nextId;
			nextId += 1;

			listeners[listenerId] =
			{
				listenerId:	listenerId,
				objType:	objType,
				objId:		objId,
				callback:	callback
			};

			if (!idTypeCallbacks.hasOwnProperty(objId))
				idTypeCallbacks[objId] = {};

			if (!idTypeCallbacks[objId].hasOwnProperty(objType))
				idTypeCallbacks[objId][objType] = [];

			idTypeCallbacks[objId][objType].push(callback);

			return listenerId;
		}

		this.removeListener = function(listenerId)
		{
			var listener	= listeners[listenerId];
			var objType		= listener.objType;
			var objId		= listener.objId;
			var callback	= listener.callback;
			var callbacks	= idTypeCallbacks[objId][objType];

			// swap with last and pop
			for (var ndx = 0; ndx < callbacks.length; ++ndx)
			{
				if (callbacks[ndx] === callback)
				{
					callbacks[ndx] = callbacks[callbacks.length - 1];
					callbacks.pop();

					if (callbacks.length === 0)
					{
						delete idTypeCallbacks[objId][objType];

						if (Object.keys(idTypeCallbacks[objId]).length === 0)
							delete idTypeCallbacks[objId];
					}
					break;
				}
			}
			delete listeners[listenerId];
		}

		this.getListenerById = function(listenerId)
		{
			return listeners[listenerId];
		}

		this.notifyUpdate = function(objId, objType, objValue)
		{
			if (!idTypeCallbacks.hasOwnProperty(objId))
				return;

			if (!idTypeCallbacks[objId].hasOwnProperty(objType))
				return;

			var callbacks = idTypeCallbacks[objId][objType];
			for (var ndx = 0; ndx < callbacks.length; ++ndx)
				callbacks[ndx](objValue);
		}
	};
	var listeners = new ListenerSet();

	var objectKey = function(objType, objId)
	{
		return objType + "," + objId;
	};

	var flushRTDB = function(items)
	{
		if (items.length !== 1)
			throw new Error("flushRTDB: items.length must be 1");

		var item = items[0];
		rpc.cast(item.method, item.args);
	};
	var rtdbQueue = new BatchQueue(flushRTDB, 1);

	// \note The same queue is used for subscriptions and unsubscriptions, and their
	//		 respective order is preserved. We want to keep them in sync so that the
	//		 server doesn't e.g. think that we have subscribed twice to the same
	//		 object. With separate subscribe and unsubscribe queues that could happen
	//		 if we first subscribed to an object, then unsubscribed and re-subscribed
	//		 the same object, all three operations done between two consecutive
	//		 flushes of the subscribe queue (so two subscribes to the same object
	//		 would end up in the same flush of the subscribe queue).
	var flushSubscriptionChanges = function(items)
	{
		var maxSubscriptionBatchSize = 100;
		var batchEndNdx;

		// Split the subscribe/unsubscribe operations to successive batches, such that:
		// - each batch contains only subscribes or only unsubscribes
		// - if subscribe S is before unsubscribe U in items, the batch containing
		//   S will go before U. And vice versa.
		// - subscription batches are no bigger than maxSubscriptionBatchSize
		for (var batchBeginNdx = 0; batchBeginNdx < items.length; batchBeginNdx = batchEndNdx)
		{
			for (batchEndNdx = batchBeginNdx+1; batchEndNdx < items.length; batchEndNdx++)
			{
				if (items[batchEndNdx].type !== items[batchBeginNdx].type)
					break;
				if (items[batchEndNdx].type === 'subscribe' && batchEndNdx-batchBeginNdx >= maxSubscriptionBatchSize)
					break;
			}

			var batchObjects = _.map(items.slice(batchBeginNdx, batchEndNdx), function(item) { return item.object; });

			if (items[batchBeginNdx].type === 'subscribe')
			{
				console.log('[rtdb] subscribe ' + batchObjects.length + ' objects from server; ' + JSON.stringify(batchObjects));
				rtdbQueue.enqueue({ method:'rtdb.Subscribe', args:{ objects:batchObjects } });
			}
			else if (items[batchBeginNdx].type === 'unsubscribe')
			{
				console.log('[rtdb] unsubscribe ' + batchObjects.length + ' objects from server');
				rtdbQueue.enqueue({ method:'rtdb.Unsubscribe', args:{ objects:batchObjects } });
			}
			else
				throw new Error('Invalid subscription change type');
		}
	};
	var subscriptionChangeQueue		= new BatchQueue(flushSubscriptionChanges);
	var enqueueSubscribe			= function(object) { subscriptionChangeQueue.enqueue({ type:'subscribe',	object:object }); };
	var enqueueUnsubscribe			= function(object) { subscriptionChangeQueue.enqueue({ type:'unsubscribe',	object:object }); };

	var flushVersionViewedObjectGets = function(items)
	{
		var views			= [];
		var itemsPerViewId	= {};

		for (var ndx = 0; ndx < items.length; ndx++)
		{
			var view = items[ndx].view;
			if (!itemsPerViewId.hasOwnProperty(view.id))
			{
				views.push(view);
				itemsPerViewId[view.id] = [];
			}
			itemsPerViewId[view.id].push(items[ndx]);
		}

		for (var viewNdx = 0; viewNdx < views.length; viewNdx++)
		{
			// Get the objects in successive batches, such that each batch waits for the
			// completion of the previous one before being issued. This makes it possible
			// to cancel the object-getting when the version view is released while some
			// objects are still pending (happens e.g. when user changes to another page
			// before objects are all loaded), so that we don't try to get objects from a
			// released version view.

			var getBatch = function(view, startNdx)
			{
				var maxBatchSize = 1000;

				if (view.id !== undefined) // view.id will be undefined when the view is released
				{
					var viewItems = itemsPerViewId[view.id];

					if (startNdx < viewItems.length)
					{
						var batchSize		= Math.min(maxBatchSize, viewItems.length - startNdx);
						var batchItems		= viewItems.slice(startNdx, startNdx + batchSize);
						var batchObjects	= _.map(batchItems, function(item) { return { objType: item.objType, objId: item.objId }; });

						rpc.call('rtdb.GetVersionViewedObjects', {
							viewId:		view.id,
							objects:	batchObjects
						})
						.then(function(objects)
						{
							if (objects.length !== batchSize)
								throw new Error('flushVersionViewedObjectGets callback: got ' + objects.length + ' objects, expected ' + batchSize);
							for (var ndx = 0; ndx < objects.length; ndx++)
								batchItems[ndx].onUpdate(objects[ndx]);
							getBatch(view, startNdx + maxBatchSize);
						});
					}
				}
			};

			getBatch(views[viewNdx], 0);
		}
	};
	var versionViewedObjectGetQueue = new BatchQueue(flushVersionViewedObjectGets);

	var rpcHandler =
	{
		InitObjects: function(args)
		{
			console.log('[rtdb] InitObjects: ' + args.length + ' objects');
			for (var objNdx = 0; objNdx < args.length; objNdx++)
			{
				var obj		= args[objNdx];
				var objType	= obj.type;
				var objId	= obj.id;
				var value	= obj.value;
				console.log('[rtdb] init: ' + objType + ' ' + objId + ': ' + debugStr(value));

				if (objectop.opHandlers.hasOwnProperty(objType) && objectop.opHandlers[objType].$postInitialize)
					objectop.opHandlers[objType].$postInitialize(value);

				var obj = {
					objType:	objType,
					objId:		objId,
					value:		value,
					ops:		[]
				};

				var objKey = objectKey(objType, objId);

				// Store copy of value.
				if (subscribedObjects.hasOwnProperty(objKey))
					subscribedObjects[objKey].obj = obj;

				// Send notification to all listeners.
				listeners.notifyUpdate(objId, objType, obj.value);
			}
		},

		UpdateObjects: function(args)
		{
			var changes = args.changes;
//			console.log('[rtdb] UpdateObjects: ' + changes.length + ' objects');
//			console.log('[rtdb] UpdateObjects: ' + _.map(changes, function(change) { return "'" + change.objId + "'"; }).join(', '));

			// Process all changed objects.
			for (var updateNdx = 0; updateNdx < changes.length; updateNdx++)
			{
				var change	= changes[updateNdx];
				var objId	= change.objId;
				var objType	= change.objType;
				var objKey	= objectKey(objType, objId);
				var ops		= change.ops;

				if (subscribedObjects.hasOwnProperty(objKey))
				{
					if (subscribedObjects[objKey].obj === undefined)
						console.log('[rtdb] update received before init for ' + objKey);
					else
					{
						// Apply ops to cached value.
						var obj = subscribedObjects[objKey].obj;
						for (var ndx = 0; ndx < ops.length; ndx++)
						{
							var op = ops[ndx];
							if (!objectop.opHandlers.hasOwnProperty(objType))
								throw new Error('[op] invalid object type (module): ' + objType);
							var module = objectop.opHandlers[objType];
							if (!module.hasOwnProperty(op.method))
								throw new Error('[op] object type "' + objType + '" has no method "' + op.method + '"');
							var handler = module[op.method];
							var args	= [obj.value].concat(op.args);
							handler.apply(null, args);
						}

						// Notify all listeners.
						listeners.notifyUpdate(objId, objType, obj.value);
					}
				}
				else
					console.log('[rtdb] got update to unsubscribed object ' + objKey);
			}
		}
	};

	rpc.register('rtdb', rpcHandler);

	var subscribe = function(objType, objId, callback)
	{
		var listenerId	= listeners.addListener(objId, objType, callback)
		var objKey		= objectKey(objType, objId);

		// Subscribe from cache or server.
		if (subscribedObjects.hasOwnProperty(objKey))
		{
			var subscribed = subscribedObjects[objKey];
			subscribed.count++;
			if (subscribed.obj !== undefined)
				callback(subscribed.obj.value);
		}
		else
		{
			// Push subscribe into queue (perform multiple subscribes in single RPC op).
			subscribedObjects[objKey] = { count:1, obj:undefined };
			enqueueSubscribe({ objType:objType, objId:objId });
		}

		return listenerId;
	};

	var unsubscribe = function(listenerId)
	{
		var listener	= listeners.getListenerById(listenerId);
		var objType		= listener.objType;
		var objId		= listener.objId;
		var objKey		= objectKey(objType, objId);

		var subscribed = subscribedObjects[objKey];
		subscribed.count--;
		if (subscribed.count === 0)
		{
			delete subscribedObjects[objKey];
			enqueueUnsubscribe({objType: objType, objId: objId});
		}

		listeners.removeListener(listenerId);
	};

	var getVersionViewedObject = function(view, objType, objId, onUpdate)
	{
		versionViewedObjectGetQueue.enqueue({ view: view, objType: objType, objId: objId, onUpdate: onUpdate });
	};

	var applyBoundDataUpdates = function(items)
	{
		for (var ndx = 0; ndx < items.length; ++ndx)
		{
			var scope		= items[ndx].scope;
			var valueName	= items[ndx].valueName;
			var value		= items[ndx].value;
			var onUpdateCb	= items[ndx].onUpdateCb;
			var objType		= items[ndx].objType;
			var objId		= items[ndx].objId;

			scope[valueName] = value;
			if (onUpdateCb)
				onUpdateCb(objType, objId, value);
		}
	};

	var flushRootInvalidateUpdates = function(items)
	{
		applyBoundDataUpdates(items);
		$rootScope.$digest();
	};
	var flushScopeInvalidateUpdates = function(items)
	{
		applyBoundDataUpdates(items);

		// apply in order

		var scopeList = [];
		for (var itemNdx = 0; itemNdx < items.length; ++itemNdx)
		{
			var seenScope = false;
			for (var scopeNdx = 0; scopeNdx < scopeList.length; ++scopeNdx)
			{
				if (scopeList[scopeNdx] === items[itemNdx].scope)
				{
					seenScope = true;
					break;
				}
			}

			if (!seenScope)
				scopeList.push(items[itemNdx].scope);
		}

		for (var ndx = 0; ndx < scopeList.length; ++ndx)
			scopeList[ndx].$digest();
	};

	var rootInvalidateUpdateQueue = new BatchQueue(flushRootInvalidateUpdates, 10);
	var scopeInvalidateUpdateQueue = new BatchQueue(flushScopeInvalidateUpdates, 20);

	var bind = function(objType, objId, scope, options)
	{
		options = options || {};
		var valueName = options.valueName || 'value';
		var invalidateMode = options.invalidateMode || 'root';
		var onUpdateCb = options.onUpdate || null;

		var initial = {};
		initial[valueName] = null;
		angular.extend(scope, initial);

		var onUpdate = function(obj)
		{
			if (invalidateMode === "root")
			{
				rootInvalidateUpdateQueue.enqueue({ scope: scope, valueName: valueName, value: obj, objType: objType, objId: objId, onUpdateCb: onUpdateCb });
			}
			else if (invalidateMode === "scope")
			{
				scopeInvalidateUpdateQueue.enqueue({ scope: scope, valueName: valueName, value: obj, objType: objType, objId: objId, onUpdateCb: onUpdateCb });
			}
			else if (invalidateMode === "none")
			{
				scope[valueName] = obj;
				if (onUpdateCb)
					onUpdateCb(objType, objId, obj);
			}
			else
				throw "Invalid mode: " + debugStr(invalidateMode);
		};

		if (scope.rtdbVersionView && scope.rtdbVersionView.id !== undefined)
		{
			// Version-viewed bind. Just get the version-viewed object once and set the value.
			getVersionViewedObject(scope.rtdbVersionView, objType, objId,
				function(obj)
				{
					if (objectop.opHandlers.hasOwnProperty(objType) && objectop.opHandlers[objType].$postInitialize)
						objectop.opHandlers[objType].$postInitialize(obj);
					onUpdate(obj);
				});
		}
		else
		{
			// Normal (real-time version) bind. Subscribe to object.

			var listener = subscribe(objType, objId, onUpdate);

			scope.$on('$destroy', function()
			{
				unsubscribe(listener);
			});
		}
	};

	var prefetch = function(objType, objId, scope)
	{
		var listener = subscribe(objType, objId, function(obj) { /*nada*/ });

		scope.$on('$destroy', function()
		{
			unsubscribe(listener);
		});
	};

	return {
		subscribe:		subscribe,
		unsubscribe:	unsubscribe,
		bind:			bind,
		prefetch:		prefetch
	};
}])

;
