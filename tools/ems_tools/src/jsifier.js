/**
 * @license
 * Copyright 2010 The Emscripten Authors
 * SPDX-License-Identifier: MIT
 */

//"use strict";

// Convert analyzed data to javascript. Everything has already been calculated
// before this stage, which just does the final conversion to JavaScript.

var addedLibraryItems = {};

// Some JS-implemented library functions are proxied to be called on the main browser thread, if the Emscripten runtime is executing in a Web Worker.
// Each such proxied function is identified via an ordinal number (this is not the same namespace as function pointers in general).
var proxiedFunctionTable = ["null" /* Reserve index 0 for an undefined function*/];

// Used internally. set when there is a main() function.
// Also set when in a linkable module, as the main() function might
// arrive from a dynamically-linked library, and not necessarily
// the current compilation unit.
// Also set for STANDALONE_WASM since the _start function is needed to call
// static ctors, even if there is no user main.
var HAS_MAIN = ('_main' in IMPLEMENTED_FUNCTIONS) || MAIN_MODULE || STANDALONE_WASM;

// Mangles the given C/JS side function name to assembly level function name (adds an underscore)
function mangleCSymbolName(f) {
  return f[0] == '$' ? f.substr(1) : '_' + f;
}

// Reverses C/JS name mangling: _foo -> foo, and foo -> $foo.
function demangleCSymbolName(f) {
  return f[0] == '_' ? f.substr(1) : '$' + f;
}

// Splits out items that pass filter. Returns also the original sans the filtered
function splitter(array, filter) {
  var splitOut = array.filter(filter);
  var leftIn = array.filter(function(x) { return !filter(x) });
  return { leftIn: leftIn, splitOut: splitOut };
}

// Functions that start with '$' should not be imported to asm.js/wasm module.
// They are intended to be exclusive to JS code only.
function isJsOnlyIdentifier(ident) {
  return ident[0] == '$';
}

function escapeJSONKey(x) {
  if (/^[\d\w_]+$/.exec(x) || x[0] === '"' || x[0] === "'") return x;
  assert(x.indexOf("'") < 0, 'cannot have internal single quotes in keys: ' + x);
  return "'" + x + "'";
}

function stringifyWithFunctions(obj) {
  if (typeof obj === 'function') return obj.toString();
  if (obj === null || typeof obj !== 'object') return JSON.stringify(obj);
  if (Array.isArray(obj)) {
    return '[' + obj.map(stringifyWithFunctions).join(',') + ']';
  } else {
    return '{' + keys(obj).map(function(key) { return escapeJSONKey(key) + ':' + stringifyWithFunctions(obj[key]) }).join(',') + '}';
  }
}

// JSifier
function JSify(data, functionsOnly) {
  var mainPass = !functionsOnly;

  var itemsDict = { type: [], GlobalVariableStub: [], functionStub: [], function: [], GlobalVariable: [], GlobalVariablePostSet: [] };

  if (mainPass) {
    // Add additional necessary items for the main pass. We can now do this since types are parsed (types can be used through
    // generateStructInfo in library.js)

    LibraryManager.load();

    var libFuncsToInclude;
    if (INCLUDE_FULL_LIBRARY) {
      libFuncsToInclude = MAIN_MODULE ? DEFAULT_LIBRARY_FUNCS_TO_INCLUDE.slice(0) : [];
      for (var key in LibraryManager.library) {
        if (!isJsLibraryConfigIdentifier(key)) {
          libFuncsToInclude.push(key);
        }
      }
    } else {
      libFuncsToInclude = DEFAULT_LIBRARY_FUNCS_TO_INCLUDE;
    }
    libFuncsToInclude.forEach(function(ident) {
      data.functionStubs.push({
        ident: mangleCSymbolName(ident)
      });
    });
  }

  function processLibraryFunction(snippet, ident, finalName) {
    // It is possible that when printing the function as a string on Windows, the js interpreter we are in returns the string with Windows
    // line endings \r\n. This is undesirable, since line endings are managed in the form \n in the output for binary file writes, so
    // make sure the endings are uniform.
    snippet = snippet.toString().replace(/\r\n/gm,"\n");

    // name the function; overwrite if it's already named
    snippet = snippet.replace(/function(?:\s+([^(]+))?\s*\(/, 'function ' + finalName + '(');

    // apply LIBRARY_DEBUG if relevant
    if (LIBRARY_DEBUG) {
      snippet = modifyFunction(snippet, function(name, args, body) {
        return 'function ' + name + '(' + args + ') {\n' +
               'var ret = (function() { if (runtimeDebug) err("[library call:' + finalName + ': " + Array.prototype.slice.call(arguments).map(prettyPrint) + "]");\n' +
                body +
                '}).apply(this, arguments); if (runtimeDebug && typeof ret !== "undefined") err("  [     return:" + prettyPrint(ret)); return ret; \n}\n';
      });
    }
    return snippet;
  }

  // functionStub
  function functionStubHandler(item) {
    // In LLVM, exceptions generate a set of functions of form __cxa_find_matching_catch_1(), __cxa_find_matching_catch_2(), etc.
    // where the number specifies the number of arguments. In Emscripten, route all these to a single function '__cxa_find_matching_catch'
    // that variadically processes all of these functions using JS 'arguments' object.
    if (item.ident.startsWith('___cxa_find_matching_catch_')) {
      if (DISABLE_EXCEPTION_THROWING) {
        error('DISABLE_EXCEPTION_THROWING was set (likely due to -fno-exceptions), which means no C++ exception throwing support code is linked in, but exception catching code appears. Either do not set DISABLE_EXCEPTION_THROWING (if you do want exception throwing) or compile all source files with -fno-except (so that no exceptions support code is required); also make sure DISABLE_EXCEPTION_CATCHING is set to the right value - if you want exceptions, it should be off, and vice versa.');
        return;
      }
      var num = +item.ident.split('_').slice(-1)[0];
      addCxaCatch(num);
      // Continue, with the code below emitting the proper JavaScript based on
      // what we just added to the library.
    }

    function addFromLibrary(ident, dependent) {
      if (ident in addedLibraryItems) return '';
      addedLibraryItems[ident] = true;

      // dependencies can be JS functions, which we just run
      if (typeof ident == 'function') return ident();

      // don't process any special identifiers. These are looked up when processing the base name of the identifier.
      if (isJsLibraryConfigIdentifier(ident)) {
        return '';
      }

      var finalName = mangleCSymbolName(ident);

      // if the function was implemented in compiled code, we just need to export it so we can reach it from JS
      if (finalName in IMPLEMENTED_FUNCTIONS) {
        EXPORTED_FUNCTIONS[finalName] = 1;
        // stop here: we don't need to add anything from our js libraries, not even deps, compiled code is on it
        return '';
      }

      // Don't replace implemented functions with library ones (which can happen when we add dependencies).
      // Note: We don't return the dependencies here. Be careful not to end up where this matters
      if (finalName in Functions.implementedFunctions) return '';

      var noExport = false;

      if (!LibraryManager.library.hasOwnProperty(ident)) {
        if (!(finalName in IMPLEMENTED_FUNCTIONS) && !LINKABLE) {
          var msg = 'undefined symbol: ' + ident;
          if (dependent) msg += ' (referenced by ' + dependent + ')';
          if (ERROR_ON_UNDEFINED_SYMBOLS) {
            error(msg);
            if (!LLD_REPORT_UNDEFINED) {
              warnOnce('Link with `-s LLD_REPORT_UNDEFINED` to get more information on undefined symbols');
            }
            warnOnce('To disable errors for undefined symbols use `-s ERROR_ON_UNDEFINED_SYMBOLS=0`')
            warnOnce(finalName + ' may need to be added to EXPORTED_FUNCTIONS if it arrives from a system library')
          } else if (VERBOSE || WARN_ON_UNDEFINED_SYMBOLS) {
            warn(msg);
          }
          if (ident === 'main' && STANDALONE_WASM) {
            warn('To build in STANDALONE_WASM mode without a main(), use emcc --no-entry');
          }
        }
        if (!RELOCATABLE) {
          // emit a stub that will fail at runtime
          LibraryManager.library[ident] = new Function("err('missing function: " + ident + "'); abort(-1);");
          // We have already warned/errored about this function, so for the purposes of Closure use, mute all type checks
          // regarding this function, marking ot a variadic function that can take in anything and return anything.
          // (not useful to warn/error multiple times)
          LibraryManager.library[ident + '__docs'] = '/** @type {function(...*):?} */';
        } else {
          var realIdent = ident;

          var target = "Module['" + mangleCSymbolName(realIdent) + "']";
          var assertion = '';
          if (ASSERTIONS) {
            var what = 'function';
            assertion += 'if (!' + target + ') abort("external symbol \'' + realIdent + '\' is missing. perhaps a side module was not linked in? if this function was expected to arrive from a system library, try to build the MAIN_MODULE with EMCC_FORCE_STDLIBS=1 in the environment");\n';

          }
          var functionBody = assertion + "return " + target + ".apply(null, arguments);";
          LibraryManager.library[ident] = new Function(functionBody);
          noExport = true;
        }
      }

      var original = LibraryManager.library[ident];
      var snippet = original;
      var redirectedIdent = null;
      var deps = LibraryManager.library[ident + '__deps'] || [];
      if (!Array.isArray(deps)) {
        error('JS library directive ' + ident + '__deps=' + deps.toString() + ' is of type ' + typeof deps + ', but it should be an array!');
        return;
      }
      deps.forEach(function(dep) {
        if (typeof snippet === 'string' && !(dep in LibraryManager.library)) warn('missing library dependency ' + dep + ', make sure you are compiling with the right options (see #if in src/library*.js)');
      });
      var isFunction = false;

      if (typeof snippet === 'string') {
        if (snippet[0] != '=') {
          var target = LibraryManager.library[snippet];
          if (target) {
            // Redirection for aliases. We include the parent, and at runtime make ourselves equal to it.
            // This avoid having duplicate functions with identical content.
            redirectedIdent = snippet;
            deps.push(snippet);
            snippet = mangleCSymbolName(snippet);
          }
          // In asm, we need to know about library functions. If there is a target, though, then no
          // need to consider this a library function - we will call directly to it anyhow
          if (!redirectedIdent && (typeof target == 'function')) {
            Functions.libraryFunctions[finalName] = 1;
          }
        }
      } else if (typeof snippet === 'object') {
        snippet = stringifyWithFunctions(snippet);
      } else if (typeof snippet === 'function') {
        isFunction = true;
        snippet = processLibraryFunction(snippet, ident, finalName);
        if (!isJsOnlyIdentifier(ident[0])) {
          Functions.libraryFunctions[finalName] = 1;
        }
      }

      // If a JS library item specifies xxx_import: true, then explicitly mark that symbol to be imported
      // to asm.js/wasm module.
      if (LibraryManager.library[ident + '__import']) {
        Functions.libraryFunctions[finalName] = 1;
      }

      if (ONLY_CALC_JS_SYMBOLS)
        return '';

      var postsetId = ident + '__postset';
      var postset = LibraryManager.library[postsetId];
      if (postset) {
        // A postset is either code to run right now, or some text we should emit.
        // If it's code, it may return some text to emit as well.
        if (typeof postset === 'function') {
          postset = postset();
        }
        if (postset && !addedLibraryItems[postsetId]) {
          addedLibraryItems[postsetId] = true;
          itemsDict.GlobalVariablePostSet.push({
            JS: postset + ';'
          });
        }
      }

      if (redirectedIdent) {
        deps = deps.concat(LibraryManager.library[redirectedIdent + '__deps'] || []);
      }
      // In asm, dependencies implemented in C might be needed by JS library functions.
      // We don't know yet if they are implemented in C or not. To be safe, export such
      // special cases.
      [LIBRARY_DEPS_TO_AUTOEXPORT].forEach(function(special) {
        deps.forEach(function(dep) {
          if (dep == special && !EXPORTED_FUNCTIONS[dep]) {
            EXPORTED_FUNCTIONS[dep] = 1;
          }
        });
      });
      if (VERBOSE) printErr('adding ' + finalName + ' and deps ' + deps + ' : ' + (snippet + '').substr(0, 40));
      var identDependents = ident + "__deps: ['" + deps.join("','")+"']";
      function addDependency(dep) {
        return addFromLibrary(dep, identDependents + ', referenced by ' + dependent);
      }
      var depsText = (deps ? deps.map(addDependency).filter(function(x) { return x != '' }).join('\n') + '\n' : '');
      var contentText;
      if (isFunction) {
        // Emit the body of a JS library function.
        var proxyingMode = LibraryManager.library[ident + '__proxy'];
        if (USE_PTHREADS && proxyingMode) {
          if (proxyingMode !== 'sync' && proxyingMode !== 'async') {
            throw 'Invalid proxyingMode ' + ident + '__proxy: \'' + proxyingMode + '\' specified!';
          }
          var sync = proxyingMode === 'sync';
          assert(typeof original === 'function');
          contentText = modifyFunction(snippet, function(name, args, body) {
            return 'function ' + name + '(' + args + ') {\n' +
                   'if (ENVIRONMENT_IS_PTHREAD) return _emscripten_proxy_to_main_thread_js(' + proxiedFunctionTable.length + ', ' + (+sync) + (args ? ', ' : '') + args + ');\n' + body + '}\n';
          });
          proxiedFunctionTable.push(finalName);
        } else {
          contentText = snippet; // Regular JS function that will be executed in the context of the calling thread.
        }
      } else if (typeof snippet === 'string' && snippet.indexOf(';') == 0) {
        // In JS libraries
        //   foo: ';[code here verbatim]'
        //  emits
        //   'var foo;[code here verbatim];'
        contentText = 'var ' + finalName + snippet;
        if (snippet[snippet.length-1] != ';' && snippet[snippet.length-1] != '}') contentText += ';';
      } else {
        // In JS libraries
        //   foo: '=[value]'
        //  emits
        //   'var foo = [value];'
        if (typeof snippet === 'string' && snippet[0] == '=') snippet = snippet.substr(1);
        contentText = 'var ' + finalName + '=' + snippet + ';';
      }
      var sig = LibraryManager.library[ident + '__sig'];
      // asm module exports are done in emscripten.py, after the asm module is ready. Here
      // we also export library methods as necessary.
      if ((EXPORT_ALL || (finalName in EXPORTED_FUNCTIONS)) && !noExport) {
        contentText += '\nModule["' + finalName + '"] = ' + finalName + ';';
      }
      if (MAIN_MODULE && sig) {
        contentText += '\n' + finalName + '.sig = \'' + sig + '\';';
      }

      var commentText = '';
      if (LibraryManager.library[ident + '__docs']) {
        commentText = LibraryManager.library[ident + '__docs'] + '\n';
      }

      return depsText + commentText + contentText;
    }

    itemsDict.functionStub.push(item);
    var shortident = demangleCSymbolName(item.ident);
    item.JS = addFromLibrary(shortident, 'top-level compiled C/C++ code');
  }

  // Final combiner

  function finalCombiner() {
    var splitPostSets = splitter(itemsDict.GlobalVariablePostSet, function(x) { return x.ident && x.dependencies });
    itemsDict.GlobalVariablePostSet = splitPostSets.leftIn;
    var orderedPostSets = splitPostSets.splitOut;

    var limit = orderedPostSets.length * orderedPostSets.length;
    for (var i = 0; i < orderedPostSets.length; i++) {
      for (var j = i+1; j < orderedPostSets.length; j++) {
        if (orderedPostSets[j].ident in orderedPostSets[i].dependencies) {
          var temp = orderedPostSets[i];
          orderedPostSets[i] = orderedPostSets[j];
          orderedPostSets[j] = temp;
          i--;
          limit--;
          assert(limit > 0, 'Could not sort postsets!');
          break;
        }
      }
    }

    itemsDict.GlobalVariablePostSet = itemsDict.GlobalVariablePostSet.concat(orderedPostSets);

    //

    if (!mainPass) {
      var generated = itemsDict.function.concat(itemsDict.type).concat(itemsDict.GlobalVariableStub).concat(itemsDict.GlobalVariable);
      print(generated.map(function(item) { return item.JS; }).join('\n'));
      return;
    }

    var shellFile = SHELL_FILE ? SHELL_FILE : (MINIMAL_RUNTIME ? 'shell_minimal.js' : 'shell.js');

    var shellParts = read(shellFile).split('{{BODY}}');
    print(processMacros(preprocess(shellParts[0], shellFile)));
    var pre;
    if (MINIMAL_RUNTIME) {
      pre = processMacros(preprocess(read('preamble_minimal.js'), 'preamble_minimal.js'));
    } else {
      pre = processMacros(preprocess(read('support.js'), 'support.js')) +
            processMacros(preprocess(read('preamble.js'), 'preamble.js'));
    }
    print(pre);

    // Print out global variables and postsets TODO: batching
    var legalizedI64sDefault = legalizedI64s;
    legalizedI64s = false;

    var globalsData = {functionStubs: []}
    JSify(globalsData, true);
    globalsData = null;

    var generated = itemsDict.functionStub.concat(itemsDict.GlobalVariablePostSet);
    generated.forEach(function(item) { print(indentify(item.JS || '', 2)); });

    legalizedI64s = legalizedI64sDefault;

    if (USE_PTHREADS) {
      print('\n // proxiedFunctionTable specifies the list of functions that can be called either synchronously or asynchronously from other threads in postMessage()d or internally queued events. This way a pthread in a Worker can synchronously access e.g. the DOM on the main thread.')
      print('\nvar proxiedFunctionTable = [' + proxiedFunctionTable.join() + '];\n');
    }

    if (!MINIMAL_RUNTIME) {
      print('var ASSERTIONS = ' + !!ASSERTIONS + ';\n');

      print(preprocess(read('arrayUtils.js')));
    }

    if (SUPPORT_BASE64_EMBEDDING && !MINIMAL_RUNTIME) {
      print(preprocess(read('base64Utils.js')));
    }

    if (abortExecution) throw Error('Aborting compilation due to previous errors');

    // This is the main 'post' pass. Print out the generated code that we have here, together with the
    // rest of the output that we started to print out earlier (see comment on the
    // "Final shape that will be created").
    print('// EMSCRIPTEN_END_FUNCS\n');

    if (HEADLESS) {
      print('if (!ENVIRONMENT_IS_WEB) {');
      print(read('headlessCanvas.js'));
      print('\n');
      print(read('headless.js').replace("'%s'", "'http://emscripten.org'").replace("'?%s'", "''").replace("'?%s'", "'/'").replace('%s,', 'null,').replace('%d', '0'));
      print('}');
    }
    if (PROXY_TO_WORKER) {
      print('if (ENVIRONMENT_IS_WORKER) {\n');
      print(read('webGLWorker.js'));
      print(processMacros(preprocess(read('proxyWorker.js'), 'proxyWorker.js')));
      print('}');
    }
    if (DETERMINISTIC) {
      print(read('deterministic.js'));
    }

    var postFile = MINIMAL_RUNTIME ? 'postamble_minimal.js' : 'postamble.js';
    var post = processMacros(preprocess(read(postFile), postFile));
    print(post);

    var shellParts = read(shellFile).split('{{BODY}}');
    print(processMacros(preprocess(shellParts[1], shellFile)));

    PassManager.serialize();
  }

  // Data

  if (mainPass) {
    data.functionStubs.forEach(functionStubHandler);
  }

  finalCombiner();
}
