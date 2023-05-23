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

angular.module('cherry.testCaseResult', [])

// CONTROLLERS

// Individual test case result.

.controller('TestCaseResultCtrl', ['$scope', '$stateParams', '$compile', '$sce', '$state', 'rtdb', 'rpc', function($scope, $stateParams, $compile, $sce, $state, rtdb, rpc)
{
	console.log('TestCaseResultCtrl: ' + JSON.stringify($stateParams));

	$scope.stateParams	= $stateParams;
	$scope.stateName	= $state.$current.name;

	// Batch name if displaying a comparison view
	$scope.batchResultName = "";
	if ($scope.batchResults && $scope.batchResultIds && $stateParams.batchResultId)
	{
		var batchResult = $scope.batchResults[$scope.batchResultIds.indexOf($stateParams.batchResultId)];
		if (batchResult)
			$scope.batchResultName = batchResult.name;
	}

	$scope.logHtml = '<div>Pending...</div>';

	// Convert log to
	$scope.$watch('result.log', function(log)
	{
		if (log)
		{
			// Parse test log with sax and convert tags and attributes to a format more suitable for AngularJS.
			// Also, closes possibly unclosed tags resulting from terminated (e.g. crashed) test runs.
			var convertLog = function (log)
			{
				var elementTranslations =
				{
					TestCaseResult:			{ tag: 'de-test-case-result'										},
					Text:					{ tag: 'de-text'													},
					Number:					{ tag: 'de-number'													},
					ImageSet:				{ tag: 'de-image-set'												},
					Image:					{ tag: 'de-image'													},
					Result:					{ tag: 'de-result'													},
					SampleList:				{ tag: 'table',				attributes: {'de-sample-list':	''	}	},
					SampleInfo:				{ tag: 'tr',				attributes: {'de-sample-info':	''	}	},
					ValueInfo:				{ tag: 'th',				attributes: {'de-value-info':	''	}	},
					Sample:					{ tag: 'tr',				attributes: {'de-sample':		''	}	},
					Value:					{ tag: 'td',				attributes: {'de-value':		''	}	},
					ShaderProgram:			{ tag: 'de-shader-program'											},
					InfoLog:				{ tag: 'de-info-log'												},
					VertexShader:			{ tag: 'de-shader',			attributes: {'type': 'vertex'}			},
					FragmentShader:			{ tag: 'de-shader',			attributes: {'type': 'fragment'}		},
					GeometryShader:			{ tag: 'de-shader',			attributes: {'type': 'geometry'}		},
					TessControlShader:		{ tag: 'de-shader',			attributes: {'type': 'tess-control'}	},
					TessEvaluationShader:	{ tag: 'de-shader',			attributes: {'type': 'tess-evaluation'}	},
					ComputeShader:			{ tag: 'de-shader',			attributes: {'type': 'compute'}			},
					ShaderSource:			{ tag: 'de-shader-source'											},
					SpirVAssemblySource:	{ tag: 'de-spirv-source'											},
					Section:				{ tag: 'de-section'													},
					EglConfigSet:			{ tag: 'de-egl-config-set'											},
					EglConfig:				{ tag: 'de-egl-config'												},
					KernelSource:			{ tag: 'de-kernel-source'											},
					CompileInfo:			{ tag: 'de-compile-info'											},
				};

				var attributeTranslations =
				{
					Version:				'version',
					CasePath:				'case-path',
					CaseType:				'case-type',
					Name:					'name',
					Description:			'description',
					Tag:					'tag',
					Unit:					'unit',
					Width:					'width',
					Height:					'height',
					Format:					'format',
					CompressionMode:		'compression-mode',
					StatusCode:				'status-code',
					LinkStatus:				'link-status',
					CompileStatus:			'compile-status',
					BufferSize:				'buffer-size',
					RedSize:				'red-size',
					GreenSize:				'green-size',
					BlueSize:				'blue-size',
					LuminanceSize:			'luminance-size',
					AlphaSize:				'alpha-size',
					AlphaMaskSize:			'alpha-mask-size',
					BindToTextureRGB:		'bind-to-texture-rgb',
					BindToTextureRGBA:		'bind-to-texture-rgba',
					ColorBufferType:		'color-buffer-type',
					ConfigCaveat:			'config-caveat',
					Conformant:				'conformant',
					DepthSize:				'depth-size',
					Level:					'level',
					MaxPBufferWidth:		'max-pbuffer-width',
					MaxPBufferHeight:		'max-pbuffer-height',
					MaxPBufferPixels:		'max-pbuffer-pixels',
					MaxSwapInterval:		'max-swap-interval',
					MinSwapInterval:		'min-swap-interval',
					NativeRenderable:		'native-renderable',
					RenderableType:			'renderable-type',
					SampleBuffers:			'sample-buffers',
					Samples:				'samples',
					StencilSize:			'stencil-size',
					SurfaceTypes:			'surface-types',
					TransparentType:		'transparent-type',
					TransparentRedValue:	'transparent-red-value',
					TransparentGreenValue:	'transparent-green-value',
					TransparentBlueValue:	'transparent-blue-value',
				}

				// \note Some log elements may contain text that AngularJS shouldn't try to parse
				//		 (e.g. "foo bar[2] = {{1, 2}, {3, 4}};" can appear in OpenCL kernel sources,
				//		 and AngularJS would try to parse the stuff between {{ and }}). We add a
				//		 wrapper element with the ng-non-bindable attribute around the contents of
				//		 such elements.
				var elementNonBindableTags =
				{
					Text:			'span',
					Number:			'span',
					Result:			'span',
					Sample:			'span',
					Value:			'span',
					InfoLog:		'div',
					ShaderSource:	'div',
					KernelSource:	'div',
				};

				var parser			= sax.parser(true /* strict */);
				var openElements	= [];

				parser.onopentag = function (tag)
				{
					var parent = openElements[openElements.length-1];
					var translatedElement;

					if (elementTranslations.hasOwnProperty(tag.name))
					{
						var translatedParams = elementTranslations[tag.name];

						translatedElement = document.createElement(translatedParams.tag);

						for (var attr in translatedParams.attributes)
							translatedElement.setAttribute(attr, translatedParams.attributes[attr]);

						for (var attr in tag.attributes)
						{
							if (attributeTranslations.hasOwnProperty(attr))
								translatedElement.setAttribute(attributeTranslations[attr], tag.attributes[attr]);
						}

						{
							var innerElement;
							if (elementNonBindableTags.hasOwnProperty(tag.name))
							{
								innerElement = document.createElement(elementNonBindableTags[tag.name]);
								innerElement.setAttribute('ng-non-bindable', '');
								translatedElement.appendChild(innerElement);
							}
							else
								innerElement = translatedElement;

							openElements.push({
								element: innerElement,
								isValid: true
							});
						}
					}
					else
					{
						translatedElement = document.createElement('de-unknown-log-element');
						translatedElement.setAttribute('name', tag.name);
						openElements.push({
							element: translatedElement,
							isValid: false
						});
					}

					if (parent.isValid)
						parent.element.appendChild(translatedElement);
				};

				var closeTag = function ()
				{
					openElements.pop();
				};

				parser.onclosetag = closeTag;

				parser.ontext = function (text)
				{
					var parent = openElements[openElements.length-1];
					if (parent.isValid)
						parent.element.appendChild(document.createTextNode(text));
				};

				// Dummy root.
				openElements.push({
					element: document.createElement('div'),
					isValid: true
				});

				// \note The sax parser will stop parsing if it encounters an error (since we're not handling the error event to resume).
				parser.write(log).close();

				// Close remaining tags
				while (openElements.length > 1)
					closeTag();

				return openElements[0].element.innerHTML;
			};

			var convertedHtml;
			try
			{
				// \todo [petri] security hole right here?
				convertedHtml = convertLog(log);
			}
			catch (ex)
			{
				var element = document.createElement("div");
				var errorElement = document.createElement("pre");
				var logElement = document.createElement("pre");
				errorElement.appendChild(document.createTextNode("Log format error, dumping unformatted log\n" + ex.message));
				logElement.appendChild(document.createTextNode(log));
				element.appendChild(errorElement);
				element.appendChild(logElement);

				convertedHtml = element.outerHTML;
			}

			$scope.logHtml = convertedHtml;
		}
	});

	rtdb.bind('TestCaseResult', $stateParams.batchResultId + '/' + $stateParams.testCasePath, $scope, { valueName:'result' });
	rtdb.bind('TestCaseHeader', $stateParams.batchResultId + '/' + $stateParams.testCasePath, $scope, { valueName:'header' });
	rtdb.bind('BatchResult', $stateParams.batchResultId, $scope, { valueName:'batchResult' });

	$scope.$watch('batchResult.execParams.deviceId', function(deviceId)
	{
		if (deviceId)
			rtdb.bind('DeviceConfig', deviceId, $scope, { valueName:'deviceConfig' });
	});

	$scope.$watch('deviceConfig.name', function(deviceConfigName)
	{
		if ($scope.deviceConfig)
			$scope.deviceConfigName = deviceConfigNameHumanReadable($scope.deviceConfig);
	});

	$scope.titleExpr('stateParams.testCasePath + " in " + batchResult.name + " - " + deviceConfigName');
}])

// DIRECTIVES

.directive('deTestCaseResult', [function()
{
	return {
		restrict:	'E',
		replace:	true,
		transclude:	true,
		template:	'<div ng-transclude></div>'
	};
}])

.directive('deNumber', [function()
{
	return {
		restrict:	'E',
		replace:	true,
		transclude:	true,
		template:	'<div ng-transclude></div>',
		link:		function(scope, elem, attrs)
		{
			elem.html(attrs.description + ' = ' + elem.html() + " " + attrs.unit);
		}
	};
}])

.directive('deText', [function()
{
	return {
		restrict:	'E',
		replace:	true,
		transclude:	true,
		template:	'<div class="de-text" ng-transclude></div>'
	};
}])

.directive('deImageSet', [function()
{
	return {
		restrict:	'E',
		replace:	true,
		transclude:	true,
		scope:		{
			description: '@'
		},
		template:	'<div class="de-image-set"><h4 style="text-align:center">{{ description }}</h4><div ng-transclude /></div>'
	};
}])

.directive('deImage', [function()
{
	// \todo [petri] hard-coded do embedded png images! ignores width/height/format
	return {
		restrict:	'E',
		replace:	true,
		transclude:	true,
		scope:		{
			description:	'@'
		},
		// \todo [petri] move template to its own html file?
		template:	'<div style="text-align:center;"><img ng-src="{{ imgUri }}" alt="{{ description }}" /><div class="caption"><h5>{{ description }}</h5></div></div>',

		compile: function(tElem, tAttrs, transclude)
		{
			var link = function(scope, elem, attrs)
			{
				transclude(scope, function(clone, scope)
				{
					var base64 = clone.text();
					scope.imgUri = 'data:image/png;base64,' + base64;
				});
			}

			return link;
		}
	};
}])

.directive('deResult', [function()
{
	return {
		restrict:	'E',
		replace:	true,
		transclude:	true,
		template:	'<div>Result: <span ng-transclude /></div>'
	};
}])

.directive('deKernelSource', [function()
{
	return {
		restrict:	'E',
		replace:	true,
		transclude:	true,
		template:	'<pre ng-transclude />',
	};
}])

.directive('deShaderSource', [function()
{
	return {
		restrict:	'E',
		replace:	true,
		transclude:	true,
		template:	'<pre ng-transclude />',
	};
}])

.directive('deShaderProgram', [function()
{
	return {
		restrict:	'E',
		replace:	true,
		transclude:	true,
		scope:		{
			linkStatus: '@'
		},
		template:	'<div class="de-shader-program">' +
						'<span class="de-shader-program-heading">' +
							'Program ' +
							'(<span class="de-build-status-{{ linkStatus | lowercase }}">' +
								'link {{ linkStatus | buildStatusHumanReadable }}' +
							'</span>)' +
						'</span>' +
						'<div ng-transclude />' +
					'</div>',
	};
}])

.directive('deShader', [function()
{
	return {
		restrict:	'E',
		replace:	true,
		transclude:	true,
		scope:		{
			type:			'@',
			compileStatus:	'@'
		},
		template:	'<div class="de-shader">' +
						'<span class="de-shader-heading">' +
							'{{ type | shaderTypeHumanReadable }} shader ' +
							'(<span class="de-build-status-{{ compileStatus | lowercase }}">' +
								'compile {{ compileStatus | buildStatusHumanReadable }}' +
							'</span>)' +
						'</span>' +
						'<div ng-transclude />' +
					'</div>',
	};
}])

.directive('deSpirvSource', [function()
{
	return {
		restrict:	'E',
		replace:	true,
		transclude:	true,
		template:	'<div class="de-shader">' +
						'<span class="de-shader-heading">SPIR-V assembly source</span>' +
						'<pre ng-transclude />' +
					'</div>',
	};
}])

.directive('deSection', [function()
{
	return {
		restrict:	'E',
		replace:	true,
		transclude:	true,
		scope:		{
			description:	'@'
		},
		template:	'<div class="de-section"><span class="de-section-heading">{{ description }}</span><div ng-transclude /></div>'
	};
}])

.directive('deCompileInfo', [function()
{
	return {
		restrict:	'E',
		replace:	true,
		transclude:	true,
		scope:		{
			description:	'@',
			compileStatus:	'@'
		},
		template:	'<div class="de-build-info">' +
						'<span class="de-build-info-heading">' +
							'{{ description }} ' +
							'(<span class="de-build-status-{{ compileStatus | lowercase }}">' +
								'compile {{ compileStatus | buildStatusHumanReadable }}' +
							'</span>)' +
						'</span>' +
						'<div ng-transclude />' +
					'</div>',
	};
}])

.directive('deInfoLog', [function()
{
	return {
		restrict:	'E',
		replace:	true,
		transclude:	true,
		template:	'<div>Info log:<pre ng-transclude /></div>' // \todo [nuutti] Something more appropriate and less browser-dependent (?) than pre.
	};
}])

.directive('deEglConfigSet', [function()
{
	return {
		restrict:	'E',
		replace:	true,
		transclude:	true,
		scope:		{
			description:	'@'
		},
		template:	'<div class="de-egl-config-set"><span class="de-egl-config-set-heading">{{ description }}</span><ol ng-transclude /></div>'
	};
}])

.directive('deEglConfig', [function()
{
	return {
		restrict:	'E',
		replace:	true,
		scope: {
			redSize:			'@',
			greenSize:			'@',
			blueSize:			'@',
			alphaSize:			'@',
			depthSize:			'@',
			stencilSize:		'@',
			renderableType:		'@'
		},
		template:	'<li>{{ colorFormat }}, {{ depthString }}, {{ stencilString }}, {{ renderableType }}</li>',
		link:		function(scope, elem, attrs)
		{
			var hasAlpha	= parseInt(scope.alphaSize) > 0;
			var hasDepth	= parseInt(scope.depthSize) > 0;
			var hasStencil	= parseInt(scope.stencilSize) > 0;

			scope.colorFormat = 'RGB' + (hasAlpha ? 'A' : '') +
								scope.redSize +
								scope.greenSize +
								scope.blueSize +
								(hasAlpha ? scope.alphaSize : '');

			scope.depthString		= hasDepth ? scope.depthSize + '-bit depth' : 'no depth';
			scope.stencilString		= hasStencil ? scope.stencilSize + '-bit stencil' : 'no stencil';
		}
	};
}])

.directive('deUnknownLogElement', [function()
{
	return {
		restrict:	'E',
		replace:	true,
		scope:		{
			name:		'@'
		},
		template:	'<div>Warning: unknown log element {{ name }}</div>'
	};
}])

// SAMPLE LISTS

.directive('deSampleList', [function()
{
	return {
		restrict:	'A',
		replace:	true,
		transclude:	true,
		scope:		{
			description:	'@'
		},
		template:	'<div class="panel panel-default"><div class="panel-heading">{{ description }}</div><table class="table table-striped table-condensed de-sample-table" ng-transclude/></div>'
	};
}])

.directive('deSampleInfo', [function()
{
	return {
		restrict:	'A',
		replace:	true,
		transclude:	true,
		template:	'<tr ng-transclude />'
	};
}])

.directive('deValueInfo', [function()
{
	return {
		restrict:	'A',
		replace:	true,
		transclude:	true,
		scope:		{
			'description':	'@',
		},
		template:	'<th>{{ description }}</th>'
	};
}])

.directive('deSample', [function()
{
	return {
		restrict:	'A',
//		replace:	true,
//		transclude:	true,
//		template:	'<tr ng-transclude />'
	};
}])

.directive('deValue', [function()
{
	return {
		restrict:	'A',
		replace:	true,
		transclude:	true,
		template:	'<td ng-transclude />'
	};
}])

;
