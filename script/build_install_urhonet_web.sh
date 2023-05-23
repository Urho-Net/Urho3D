URHONET_HOME_ROOT=$(cat ~/.urhonet_config/urhonethome)
URHO3D_HOME=$(pwd)

if [ ! -d "$URHONET_HOME_ROOT" ]; then
    echo  "Urho.Net is not configured , please  run configure.sh (configure.bat on Windows) from the Urho.Net installation folder  "
    exit -1
else
    echo "URHONET_HOME_ROOT=${URHONET_HOME_ROOT}"
fi

echo "URHO3D_HOME=${URHO3D_HOME}"

./script/make_csharp_bindings.sh
./script/build_install_urhonet_web_mono_runtime.sh
./script/build_emscripten_dotnet_dylib.sh

mkdir -p ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/web
cp -f ${URHO3D_HOME}/DotNet/UrhoDotNet/web/UrhoDotNet.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/web

mkdir -p ${URHONET_HOME_ROOT}/template/libs/web
cp -f ${URHO3D_HOME}/DotNet/libs/wasm/index.html  ${URHONET_HOME_ROOT}/template/libs/web/index.html
cp -f ${URHO3D_HOME}/DotNet/libs/wasm/MonoEmbedded.js  ${URHONET_HOME_ROOT}/template/libs/web/MonoEmbedded.js
cp -f ${URHO3D_HOME}/DotNet/libs/wasm/MonoEmbedded.wasm  ${URHONET_HOME_ROOT}/template/libs/web/MonoEmbedded.wasm
