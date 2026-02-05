
#!/bin/bash

CWD=$(pwd)
unamestr=$(uname)

# Switch-on alias expansion within the script 
shopt -s expand_aliases

#Alias the sed in-place command for OSX and Linux - incompatibilities between BSD and Linux sed args
if [[ "$unamestr" == "Darwin" ]]; then
	alias aliassedinplace='sed -i ""'
else
	#For Linux, notice no space after the '-i' 
	alias aliassedinplace='sed -i""'
fi

echo "🚀 Building Urho3D with Emscripten 3.1.34..."

# cmake_emscripten_dotnet_lib.sh will check/install/activate emsdk 3.1.34
./script/cmake_emscripten_dotnet_lib.sh build-emscripten-dotnet-dylib

if [ $? -ne 0 ]; then
    echo "❌ CMake configuration failed"
    exit 1
fi

# Source emsdk environment for the build (only if not using GitHub Actions setup)
if [ "${SKIP_EMSDK_INSTALL}" != "1" ] && [ -f "$HOME/emsdk/emsdk_env.sh" ]; then
    source "$HOME/emsdk/emsdk_env.sh"
fi

echo "🔨 Building..."
cd build-emscripten-dotnet-dylib
make -j4
BUILD_STATUS=$?
cd ..

if [ $BUILD_STATUS -eq 0 ]; then
    echo "✅ Build succeeded!"
    if [ -f "build-emscripten-dotnet-dylib/lib/libUrho3D.a" ]; then
        echo "📦 Library: build-emscripten-dotnet-dylib/lib/libUrho3D.a"
        ls -lh build-emscripten-dotnet-dylib/lib/libUrho3D.a
    fi
else
    echo "❌ Build failed"
    exit 1
fi

mkdir -p DotNet/libs/wasm/Release   
cp -f build-emscripten-dotnet-dylib/lib/libUrho3D.a DotNet/libs/wasm/Release/Urho3D.a