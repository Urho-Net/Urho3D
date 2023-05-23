URHONET_HOME_ROOT=$(cat ~/.urhonet_config/urhonethome)
URHO3D_HOME=$(pwd)

if [ ! -d "$URHONET_HOME_ROOT" ]; then
    echo  "Urho.Net is not configured , please  run configure.sh (configure.bat on Windows) from the Urho.Net installation folder  "
    exit -1
else
    echo "URHONET_HOME_ROOT=${URHONET_HOME_ROOT}"
fi

./script/make_csharp_bindings.sh
./script/build_xcode_dotnet_dylib.sh 

mkdir -p ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/desktop
cp -f ${URHO3D_HOME}/DotNet/UrhoDotNet/desktop/UrhoDotNet.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/desktop
cp -f ${URHO3D_HOME}/DotNet/UrhoDotNet/desktop/UrhoDotNet.xml ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/desktop

mkdir -p ${URHONET_HOME_ROOT}/template/libs/macos
cp -f ${URHO3D_HOME}/DotNet/libs/macos/Release/libUrho3D.dylib  ${URHONET_HOME_ROOT}/template/libs/macos