#!/usr/bin/env bash
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
#
# Emscripten compiler version for .NET 8 release should be 3.1.34  , see https://github.com/dotnet/runtime/blob/release/8.0/src/mono/wasm/emscripten-version.txt
# emsdk install 3.1.34 
# emsdk activate 3.1.34 
# source ./emsdk_env.sh
# export EMSCRIPTEN=~/emsdk/upstream/emscripten
# -D CMAKE_BUILD_TYPE=Debug

$(dirname $0)/cmake_generic.sh "$@" -D WEB=1 -D URHO3D_DATABASE_SQLITE=1 -D URHO3D_DOTNET=1 -D URHO3D_DOTNET_LIB=1 -D URHO3D_LUA=0 -D URHO3D_ANGELSCRIPT=0 -D URHO3D_SAMPLES=0 -D URHO3D_PCH=0

# vi: set ts=4 sw=4 expandtab:
