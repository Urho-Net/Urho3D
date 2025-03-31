function readlink(){
    DIR="${1%/*}"
    (cd "$DIR" && echo "$(pwd -P)")
}

script_path=$(readlink  "$0")
scriptDir=$(dirname "$script_path")
URHO3D_HOME=${scriptDir}


configureFile=${scriptDir}/../configure.sh
if [ -e "$configureFile" ]; then
    cd ${scriptDir}/../
    echo "configure.sh found , calling it !"
    ./configure.sh
fi


URHONET_HOME_ROOT=$(cat ~/.urhonet_config/urhonethome)


if [ ! -d "$URHONET_HOME_ROOT" ]; then
    echo  "Urho.Net is not configured , please  run configure.sh (configure.bat on Windows) from the Urho.Net installation folder  "
    exit -1
else
    echo "URHONET_HOME_ROOT=${URHONET_HOME_ROOT}"
fi

cd ${URHO3D_HOME}

input1=$1
if [[ $input1 == "generate-bindings" ]]; then
    ./script/make_csharp_bindings.sh
    exit_status=$?
    if [ $exit_status -ne 0 ]; then
    echo "An error occurred while executing make_csharp_bindings.sh Exiting."
    exit 1 
    fi
else 
    # compiling only the UrhoNet  assembly
    cd $URHO3D_HOME/DotNet/Bindings
    ./build-ios-bindings.sh
    exit_status=$?
    if [ $exit_status -ne 0 ]; then
        echo "An error occurred while executing build-ios-bindings.sh Exiting."
        exit 1 
    fi
    cd $URHO3D_HOME
fi

if [ ! -e ${URHO3D_HOME}/DotNet/UrhoDotNet/mobile/ios/UrhoDotNet.dll ]; then
  echo "ios/UrhoDotNet.dll does not exist. Exiting with an error."
  exit 1
fi

./script/build_ios_dotnet_libs.sh
exit_status=$?
if [ $exit_status -ne 0 ]; then
  echo "An error occurred while executing build_ios_dotnet_libs.sh Exiting."
  exit 1 
fi


cp -fRL ${URHO3D_HOME}/build-ios-dotnet-lib-metal-shared/include ${URHONET_HOME_ROOT}/template/IOS


if [ ! -e ${URHO3D_HOME}/DotNet/libs/iphone/Release-iphoneos/Urho3D.framework/Urho3D ]; then
  echo "Release-iphoneos/Urho3D.framework does not exist. Exiting with an error."
  exit 1
fi
mkdir -p ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/release
cp -rf ${URHO3D_HOME}/DotNet/libs/iphone/Release-iphoneos/Urho3D.framework  ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/release


if [ ! -e ${URHO3D_HOME}/DotNet/libs/iphone/Debug-iphoneos/Urho3D.framework/Urho3D ]; then
  echo "Debug-iphoneos/Urho3D.framework does not exist. Exiting with an error."
  exit 1
fi
mkdir -p ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/debug
cp -rf ${URHO3D_HOME}/DotNet/libs/iphone/Debug-iphoneos/Urho3D.framework ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/debug
rm -f ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/debug/Urho3D.framework/Urho3D.split.*
split -b45M  ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/debug/Urho3D.framework/Urho3D  ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/debug/Urho3D.framework/Urho3D.split.
rm -f ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/debug/Urho3D.framework/Urho3D


mkdir -p ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/mobile/ios
cp -f ${URHO3D_HOME}/DotNet/UrhoDotNet/mobile/ios/UrhoDotNet.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/mobile/ios