#
# Copyright (c) 2008-2020 the Urho3D project.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#

# Define target name
set (TARGET_NAME MonoEmbedded)


if(WIN32)
set (MONO_LIBPATH  ../../../DotNet/libs/windows/debug)  
set (LIBS 
    libmono-static-sgen
    libmonoruntime-sgen
    libmonoutils
)
endif()

if(ANDROID)
set (INCLUDE_DIRS ${INCLUDE_DIRS} ../../../DotNet/libs/android/net8.0-Release/${ANDROID_ABI}/include/mono-2.0)
set (MONO_LIBPATH  ../../../DotNet/libs/android/net8.0-Release/${ANDROID_ABI}) 
set (LIBS 
libSystem.IO.Compression.Native.so			
libmono-component-debugger.so			
libmonosgen-2.0.so
libSystem.Native.so				
libmono-component-diagnostics_tracing.so
libSystem.Security.Cryptography.Native.Android.so	
libmono-component-hot_reload.so
libmono-component-marshal-ilgen.so
)
file (GLOB ANDROID_FILES android/*.*)
endif()




if(APPLE)
if (IOS)
set (MONO_LIBPATH  ../../../DotNet/libs/iphone)  
set (LIBS 
    lib-urho3d-mono-aot.a
    libmonosgen-2.0.iphone.fat.a
    libmono-native.iphone.fat.a
    libmono-ee-interp.iphone.fat.a
    libmono-icall-table.iphone.fat.a
    libmono-ilgen.iphone.fat.a
    libmono-profiler-log.iphone.fat.a
    "-framework Security"
    "-framework GSS"
    "-framework CFNetwork"
    "-framework SystemConfiguration"
)
set(BITCODE "")
set(CMAKE_XCODE_ATTRIBUTE_ENABLE_BITCODE "NO" CACHE INTERNAL "")
file (GLOB S_FILES *.s)
file (GLOB EXTRA_MM_FILES *.mm)
else()

file (GLOB MACOS_FILES macos/*.*)

set (MONO_LIBPATH  ../../../DotNet/libs/macos)  
set (LIBS 
    libmonosgen-2.0.a
    libmono-native.a

)
endif()
endif()

if(APPLE)
set (LIBS  ${LIBS}  z ncurses)
endif()

if (EMSCRIPTEN)
set (INCLUDE_DIRS ${INCLUDE_DIRS} ../../../DotNet/libs/wasm/net6.0-Release/include/mono-2.0)
set (MONO_LIBPATH  ../../../DotNet/libs/wasm/net6.0-Release)  
set (LIBS 
libSystem.IO.Compression.Native.a			
libSystem.Native.a					
libmono-component-hot_reload-stub-static.a
libicui18n.a						
libmono-ee-interp.a
libicuuc.a						
libmono-icall-table.a		
libmono-ilgen.a
libmono-component-debugger-stub-static.a		
libmono-profiler-aot.a		
libmonosgen-2.0.a
libmono-component-diagnostics_tracing-stub-static.a
)

file (GLOB EMSCRIPTEN_FILES web/*.*)
list (APPEND LINK_FLAGS "--js-library ${CMAKE_CURRENT_SOURCE_DIR}/web/dotnet_support.js")
list (APPEND LINK_FLAGS "--js-library ${CMAKE_CURRENT_SOURCE_DIR}/web/library_mono.js")
list (APPEND LINK_FLAGS "--js-library ${CMAKE_CURRENT_SOURCE_DIR}/web/pal_random.js")
list (APPEND LINK_FLAGS "--js-library ${CMAKE_CURRENT_SOURCE_DIR}/web/binding_support.js")
list (APPEND LINK_FLAGS "-s \"EXTRA_EXPORTED_RUNTIME_METHODS=['ccall', 'FS_createPath', 'FS_createDataFile', 'cwrap', 'setValue', 'getValue', 'UTF8ToString', 'addFunction', 'addOnPostRun']\"")
list (APPEND LINK_FLAGS "--post-js ${CMAKE_CURRENT_SOURCE_DIR}/web/postfix.js")
list (APPEND LINK_FLAGS "-s FORCE_FILESYSTEM=1")
list (APPEND LINK_FLAGS "-s LZ4=1")
list (APPEND LINK_FLAGS "-s ASSERTIONS=1")
endif()


link_directories(. ${MONO_LIBPATH})

# set (INCLUDE_DIRS ${INCLUDE_DIRS} ../../../DotNet/include)


if(WIN32)
set (LIBS  ${LIBS}  bcrypt)
endif()



# Define source files
define_source_files (EXTRA_H_FILES ${COMMON_SAMPLE_H_FILES} ${S_FILES} ${EXTRA_MM_FILES} ${MACOS_FILES} ${ANDROID_FILES} ${EMSCRIPTEN_FILES})

# Setup target with resource copying
setup_main_executable ()

# Setup test cases
setup_test ()
