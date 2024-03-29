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

$(dirname $0)/cmake_generic.sh "$@"  -DCMAKE_OSX_DEPLOYMENT_TARGET=10.15 -DURHO3D_ANGLE_METAL=1 -DURHO3D_DOTNET=1 -DURHO3D_DOTNET_LIB=1 -DURHO3D_DOTNET_EDITOR=1 -DURHO3D_DOTNET_ASSIMP=1 -DURHO3D_DATABASE_SQLITE=1 -DURHO3D_LUA=0 -DURHO3D_ANGELSCRIPT=0 -DURHO3D_LIB_TYPE=SHARED -DURHO3D_SAMPLES=0 -DURHO3D_AUTOMATION=1 -G Xcode

# vi: set ts=4 sw=4 expandtab:
