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

# Emscripten compiler version for .NET 8 should be 3.1.34
# See: https://github.com/dotnet/runtime/blob/release/8.0/src/mono/wasm/emscripten-version.txt

REQUIRED_VERSION="3.1.34"
EMSDK_DIR="$HOME/emsdk"

# Skip installation if SKIP_EMSDK_INSTALL is set (used by GitHub Actions)
if [ "${SKIP_EMSDK_INSTALL}" = "1" ]; then
    echo "⏭️  Skipping emsdk installation (SKIP_EMSDK_INSTALL=1)"
    echo "✅ Using pre-installed Emscripten from GitHub Actions"
else
    echo "🔧 Checking for Emscripten SDK ${REQUIRED_VERSION}..."

    # Check if emsdk is installed
    if [ ! -d "$EMSDK_DIR" ]; then
        echo "📥 Emscripten SDK not found. Installing to ${EMSDK_DIR}..."
        
        # Clone emsdk
        git clone https://github.com/emscripten-core/emsdk.git "$EMSDK_DIR"
        
        if [ $? -ne 0 ]; then
            echo "❌ Failed to clone emsdk"
            exit 1
        fi
    else
        echo "✅ Emscripten SDK found at ${EMSDK_DIR}"
    fi

    # Navigate to emsdk directory
    cd "$EMSDK_DIR"

    # Update emsdk
    echo "🔄 Updating emsdk..."
    ./emsdk update

    # Check if the required version is installed
    if ! ./emsdk list | grep -q "${REQUIRED_VERSION}.*INSTALLED"; then
        echo "📦 Installing Emscripten ${REQUIRED_VERSION}..."
        ./emsdk install ${REQUIRED_VERSION}
        
        if [ $? -ne 0 ]; then
            echo "❌ Failed to install Emscripten ${REQUIRED_VERSION}"
            exit 1
        fi
    else
        echo "✅ Emscripten ${REQUIRED_VERSION} already installed"
    fi

    # Activate the required version
    echo "🔌 Activating Emscripten ${REQUIRED_VERSION}..."
    ./emsdk activate ${REQUIRED_VERSION}

    if [ $? -ne 0 ]; then
        echo "❌ Failed to activate Emscripten ${REQUIRED_VERSION}"
        exit 1
    fi

    # Source the environment
    source "${EMSDK_DIR}/emsdk_env.sh"

    # Return to original directory
    cd - > /dev/null
fi

# Verify emcc is available
if ! command -v emcc &> /dev/null; then
    echo "❌ emcc not found after activation"
    exit 1
fi

echo "✅ Using Emscripten: $(emcc --version | head -1)"
echo "📍 Path: $(which emcc)"

# Set Emscripten flags to ensure 32-bit WebAssembly output
export EMCC_CFLAGS="-s WASM=1 -s MEMORY64=0"

echo "🎯 Building for 32-bit WebAssembly (wasm32)"

$(dirname $0)/cmake_generic.sh "$@" -D WEB=1 -D URHO3D_DATABASE_SQLITE=1 -D URHO3D_DOTNET=1 -D URHO3D_DOTNET_LIB=1 -D URHO3D_LUA=0 -D URHO3D_ANGELSCRIPT=0 -D URHO3D_SAMPLES=0 -D URHO3D_PCH=0 -D CMAKE_C_FLAGS="-s MEMORY64=0" -D CMAKE_CXX_FLAGS="-s MEMORY64=0"
# vi: set ts=4 sw=4 expandtab:
