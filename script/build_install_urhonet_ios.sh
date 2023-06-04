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

cp -f ${URHO3D_HOME}/Source/Samples/MonoEmbed/mono_enc_dec_keys.cpp  ${URHONET_HOME_ROOT}/template/IOS/mono_enc_dec_keys.cpp 
cp -f ${URHO3D_HOME}/Source/Samples/MonoEmbed/mono_enc_dec.cpp  ${URHONET_HOME_ROOT}/template/IOS/mono_enc_dec.cpp 
cp -f ${URHO3D_HOME}/Source/Samples/MonoEmbed/mono_support.cpp  ${URHONET_HOME_ROOT}/template/IOS/mono_support.cpp 
cp -f ${URHO3D_HOME}/Source/Samples/MonoEmbed/mono_support.h  ${URHONET_HOME_ROOT}/template/IOS/mono_support.h
cp -f ${URHO3D_HOME}/Source/Samples/MonoEmbed/MonoEmbed.cpp ${URHONET_HOME_ROOT}/template/IOS/MonoEmbed.cpp
cp -f ${URHO3D_HOME}/Source/Samples/MonoEmbed/MonoEmbed.h  ${URHONET_HOME_ROOT}/template/IOS/MonoEmbed.h

cp -fRL ${URHO3D_HOME}/build-ios-dotnet-lib/include ${URHONET_HOME_ROOT}/template/IOS


if [ ! -e ${URHO3D_HOME}/DotNet/libs/iphone/Release-iphoneos/libUrho3D-GLES.a ]; then
  echo "Release-iphoneos/libUrho3D-GLES.a does not exist. Exiting with an error."
  exit 1
fi

mkdir -p ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/gles
mkdir -p ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/gles/release
mkdir -p ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/gles/debug
cp -f ${URHO3D_HOME}/DotNet/libs/iphone/Release-iphoneos/libUrho3D-GLES.a  ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/gles/release/libUrho3D.a

if [ ! -e ${URHO3D_HOME}/DotNet/libs/iphone/Debug-iphoneos/libUrho3D-GLES.a ]; then
  echo "Debug-iphoneos/libUrho3D-GLES.a does not exist. Exiting with an error."
  exit 1
fi
cp -f ${URHO3D_HOME}/DotNet/libs/iphone/Debug-iphoneos/libUrho3D-GLES.a  ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/gles/debug/libUrho3D.a
rm -f ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/gles/debug/libUrho3D.split.*
split -b45M  ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/gles/debug/libUrho3D.a  ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/gles/debug/libUrho3D.split.
rm -f ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/gles/debug/libUrho3D.a


if [ ! -e ${URHO3D_HOME}/DotNet/libs/iphone/Release-iphoneos/libUrho3D-Metal.a ]; then
  echo "Release-iphoneos/libUrho3D-Metal.a does not exist. Exiting with an error."
  exit 1
fi
mkdir -p ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/metal
mkdir -p ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/metal/release
mkdir -p ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/metal/debug
cp -f ${URHO3D_HOME}/DotNet/libs/iphone/Release-iphoneos/libUrho3D-Metal.a ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/metal/release/libUrho3D.a

if [ ! -e ${URHO3D_HOME}/DotNet/libs/iphone/Debug-iphoneos/libUrho3D-Metal.a ]; then
  echo "Debug-iphoneos/libUrho3D-Metal.a does not exist. Exiting with an error."
  exit 1
fi
cp -f ${URHO3D_HOME}/DotNet/libs/iphone/Debug-iphoneos/libUrho3D-Metal.a ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/metal/debug/libUrho3D.a
rm -f ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/metal/debug/libUrho3D.split.*
split -b45M ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/metal/debug/libUrho3D.a ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/metal/debug/libUrho3D.split.
rm -f ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/metal/debug/libUrho3D.a

mkdir -p ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/mobile/ios
cp -f ${URHO3D_HOME}/DotNet/UrhoDotNet/mobile/ios/UrhoDotNet.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/mobile/ios