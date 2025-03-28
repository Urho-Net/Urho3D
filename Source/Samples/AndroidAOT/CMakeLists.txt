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

# Check for supported ABIs - only proceed if we're building for a supported ABI
if(ANDROID AND (ANDROID_ABI STREQUAL "armeabi-v7a" OR ANDROID_ABI STREQUAL "arm64-v8a" OR ANDROID_ABI STREQUAL "x86_64"))
    # Define target name
    set (TARGET_NAME AndroidAOT)

    set (INCLUDE_DIRS ${INCLUDE_DIRS} ../../../DotNet/libs/android/net6.0-Release/${ANDROID_ABI}/include/mono-2.0)
    set (MONO_LIBPATH  ../../../DotNet/libs/android/net6.0-Release/${ANDROID_ABI}) 
    set (LIBS 
        Game.so
    )

    link_directories(. ${MONO_LIBPATH} /Users/elialoni/Development/Urho.Net/Source/DotNet/libs/android/net6.0-Release/${ANDROID_ABI})

    # Define source files
    define_source_files (EXTRA_H_FILES ${COMMON_SAMPLE_H_FILES})

    # Setup target with resource copying
    setup_main_executable ()

    # Setup test cases
    setup_test ()
else()
    if(ANDROID)
        # When building for Android but with an unsupported ABI, show a clear message
        message(STATUS "Skipping AndroidAOT build for unsupported ABI: ${ANDROID_ABI}")
    endif()
endif()