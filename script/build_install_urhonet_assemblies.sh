script_path=$(readlink -f "$0")
scriptDir=$(dirname "$script_path")

configureFile=${scriptDir}/../../configure.sh
if [ -e "$configureFile" ]; then
    cd ${scriptDir}/../../
    echo "configure.sh found , calling it !"
    ./configure.sh
fi

URHONET_HOME_ROOT=$(cat ~/.urhonet_config/urhonethome)
URHO3D_HOME=${scriptDir}/../

if [ ! -d "$URHONET_HOME_ROOT" ]; then
    echo  "Urho.Net is not configured , please  run configure.sh (configure.bat on Windows) from the Urho.Net installation folder  "
    exit -1
else
    echo "URHONET_HOME_ROOT=${URHONET_HOME_ROOT}"
fi

cd ${URHO3D_HOME}

./script/make_csharp_bindings.sh

mkdir -p ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/desktop
cp -f ${URHO3D_HOME}/DotNet/UrhoDotNet/desktop/UrhoDotNet.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/desktop
cp -f ${URHO3D_HOME}/DotNet/UrhoDotNet/desktop/UrhoDotNet.xml ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/desktop
mkdir -p ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/mobile/ios
cp -f ${URHO3D_HOME}/DotNet/UrhoDotNet/mobile/ios/UrhoDotNet.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/mobile/ios
mkdir -p ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/mobile/android
cp -f ${URHO3D_HOME}/DotNet/UrhoDotNet/mobile/android/UrhoDotNet.dll  ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/mobile/android
cp -f ${URHO3D_HOME}/DotNet/UrhoDotNet/mobile/android/Mono.Android.dll  ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/mobile/android
mkdir -p ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/web
cp -f ${URHO3D_HOME}/DotNet/UrhoDotNet/web/UrhoDotNet.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/web