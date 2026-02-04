unamestr=$(uname)

if [[ "$unamestr" == "Darwin" ]]; then
    function readlink(){
    DIR="${1%/*}"
    (cd "$DIR" && echo "$(pwd -P)")
    }

    script_path=$(readlink  "$0")
    scriptDir=$(dirname "$script_path")
 
    configureFile=${scriptDir}/../configure.sh
    if [ -e "$configureFile" ]; then
        cd ${scriptDir}/../
        echo "configure.sh found , calling it !"
        ./configure.sh
    fi
    URHO3D_HOME=${scriptDir}
else
	script_path=$(readlink -f "$0")
    scriptDir=$(dirname "$script_path")


    configureFile=${scriptDir}/../../configure.sh
    if [ -e "$configureFile" ]; then
        cd ${scriptDir}/../../
        echo "configure.sh found , calling it !"
        ./configure.sh
    fi
    URHO3D_HOME=${scriptDir}/../
fi

URHONET_HOME_ROOT=$(cat ~/.urhonet_config/urhonethome)


if [ ! -d "$URHONET_HOME_ROOT" ]; then
    echo  "Urho.Net is not configured , please  run configure.sh (configure.bat on Windows) from the Urho.Net installation folder  "
    exit -1
else
    echo "URHONET_HOME_ROOT=${URHONET_HOME_ROOT}"
fi

cd ${URHO3D_HOME}/DotNet/Projects
dotnet build -c Debug Projects.sln 
dotnet build -c Release Projects.sln 


mkdir -p ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/desktop
cp -f ${URHO3D_HOME}/DotNet/UrhoDotNet/desktop/release/net10.0/UrhoDotNet.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/desktop
cp -f ${URHO3D_HOME}/DotNet/UrhoDotNet/desktop/release/net10.0/UrhoDotNet.xml ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/desktop
mkdir -p ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/mobile/ios
cp -f ${URHO3D_HOME}/DotNet/UrhoDotNet/mobile/ios/release/net10.0/UrhoDotNet.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/mobile/ios
mkdir -p ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/mobile/android
cp -f ${URHO3D_HOME}/DotNet/UrhoDotNet/mobile/android/release/net10.0/UrhoDotNet.dll  ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/mobile/android
mkdir -p ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/web
cp -f ${URHO3D_HOME}/DotNet/UrhoDotNet/web/release/net8.0/UrhoDotNet.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/web