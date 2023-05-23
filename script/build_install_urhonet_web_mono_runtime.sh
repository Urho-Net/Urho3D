URHONET_HOME_ROOT=$(cat ~/.urhonet_config/urhonethome)
URHO3D_HOME=$(pwd)
RUNTIME_PATH=${URHO3D_HOME}/runtime

if [ ! -d "$URHONET_HOME_ROOT" ]; then
    echo  "Urho.Net is not configured , please  run configure.sh (configure.bat on Windows) from the Urho.Net installation folder  "
    exit -1
else
    echo "URHONET_HOME_ROOT=${URHONET_HOME_ROOT}"
fi

if [ ! -d runtime ]; then
    git clone --recursive https://github.com/dotnet/runtime.git
fi

cd ${RUNTIME_PATH}
git checkout v6.0.11

export EMSCRIPTEN_VERSION=$(cat src/mono/wasm/emscripten-version.txt)
echo "EMSCRIPTEN_VERSION=${EMSCRIPTEN_VERSION}"
export EMSDK_PATH=${URHO3D_HOME}/runtime/emsdk
EMCC=source ${EMSDK_PATH}/emsdk_env.sh 2>/dev/null && emcc

if [ ! -d "${RUNTIME_PATH}/artifacts/bin/mono/Browser.wasm.Release" ]; then
    if [ ! -d "$EMSDK_PATH" ]; then
         git clone https://github.com/emscripten-core/emsdk.git ${EMSDK_PATH}
    fi
    cd ${EMSDK_PATH} && git checkout ${EMSCRIPTEN_VERSION}
    cd ${EMSDK_PATH} && python ./emsdk.py install ${EMSCRIPTEN_VERSION}
    # cd ${EMSDK_PATH} && ./emsdk install ${EMSCRIPTEN_VERSION}
    cd ${EMSDK_PATH} && ./emsdk activate ${EMSCRIPTEN_VERSION}
    cd ${RUNTIME_PATH} && ./build.sh mono+libs -os Browser -c Debug
fi

mkdir -p ${URHO3D_HOME}/DotNet/libs/wasm/net6.0-Release
# cp -rf ${RUNTIME_PATH}/artifacts/bin/mono/Browser.wasm.Release/  ${URHO3D_HOME}/DotNet/libs/wasm/net6.0-Release
# cp -rf ${RUNTIME_PATH}/artifacts/bin/native/net6.0-Browser-Release-wasm/*.a ${URHO3D_HOME}/DotNet/libs/wasm/net6.0-Release/

cp -rf ${RUNTIME_PATH}/artifacts/bin/mono/Browser.wasm.Debug/  ${URHO3D_HOME}/DotNet/libs/wasm/net6.0-Release
cp -rf ${RUNTIME_PATH}/artifacts/bin/native/net6.0-Browser-Debug-wasm/*.a ${URHO3D_HOME}/DotNet/libs/wasm/net6.0-Release/

rm -rf ${URHONET_HOME_ROOT}/template/libs/dotnet/bcl/wasm
mkdir -p ${URHONET_HOME_ROOT}/template/libs/dotnet/bcl/wasm
# cp -rf ${RUNTIME_PATH}/artifacts/bin/runtime/net6.0-Browser-Release-wasm/*.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/bcl/wasm/
# cp -f ${RUNTIME_PATH}/artifacts/bin/mono/Browser.wasm.Release/System.Private.CoreLib.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/bcl/wasm/System.Private.CoreLib.dll
cp -rf ${RUNTIME_PATH}/artifacts/bin/runtime/net6.0-Browser-Debug-wasm/*.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/bcl/wasm/
cp -f ${RUNTIME_PATH}/artifacts/bin/mono/Browser.wasm.Debug/System.Private.CoreLib.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/bcl/wasm/System.Private.CoreLib.dll


cd ${URHONET_HOME_ROOT}