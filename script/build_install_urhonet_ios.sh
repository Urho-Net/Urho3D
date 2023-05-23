URHONET_HOME_ROOT=$(cat ~/.urhonet_config/urhonethome)
URHO3D_HOME=$(pwd)

if [ ! -d "$URHONET_HOME_ROOT" ]; then
    echo  "Urho.Net is not configured , please  run configure.sh (configure.bat on Windows) from the Urho.Net installation folder  "
    exit -1
else
    echo "URHONET_HOME_ROOT=${URHONET_HOME_ROOT}"
fi

./script/make_csharp_bindings.sh
./script/build_ios_dotnet_libs.sh

cp -f ${URHO3D_HOME}/Source/Samples/MonoEmbed/mono_enc_dec_keys.cpp  ${URHONET_HOME_ROOT}/template/IOS/mono_enc_dec_keys.cpp 
cp -f ${URHO3D_HOME}/Source/Samples/MonoEmbed/mono_enc_dec.cpp  ${URHONET_HOME_ROOT}/template/IOS/mono_enc_dec.cpp 
cp -f ${URHO3D_HOME}/Source/Samples/MonoEmbed/mono_support.cpp  ${URHONET_HOME_ROOT}/template/IOS/mono_support.cpp 
cp -f ${URHO3D_HOME}/Source/Samples/MonoEmbed/mono_support.h  ${URHONET_HOME_ROOT}/template/IOS/mono_support.h
cp -f ${URHO3D_HOME}/Source/Samples/MonoEmbed/MonoEmbed.cpp ${URHONET_HOME_ROOT}/template/IOS/MonoEmbed.cpp
cp -f ${URHO3D_HOME}/Source/Samples/MonoEmbed/MonoEmbed.h  ${URHONET_HOME_ROOT}/template/IOS/MonoEmbed.h

cp -fRL ${URHO3D_HOME}/build-ios-dotnet-lib/include ${URHONET_HOME_ROOT}/template/IOS

mkdir -p ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/gles
mkdir -p ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/gles/release
mkdir -p ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/gles/debug
cp -f ${URHO3D_HOME}/DotNet/libs/iphone/Release-iphoneos/libUrho3D-GLES.a  ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/gles/release/libUrho3D.a

cp -f ${URHO3D_HOME}/DotNet/libs/iphone/Debug-iphoneos/libUrho3D-GLES.a  ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/gles/debug/libUrho3D.a
rm -f ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/gles/debug/libUrho3D.split.*
split -b45M  ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/gles/debug/libUrho3D.a  ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/gles/debug/libUrho3D.split.
rm -f ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/gles/debug/libUrho3D.a

mkdir -p ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/metal
mkdir -p ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/metal/release
mkdir -p ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/metal/debug
cp -f ${URHO3D_HOME}/DotNet/libs/iphone/Release-iphoneos/libUrho3D-Metal.a ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/metal/release/libUrho3D.a

cp -f ${URHO3D_HOME}/DotNet/libs/iphone/Debug-iphoneos/libUrho3D-Metal.a ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/metal/debug/libUrho3D.a
rm -f ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/metal/debug/libUrho3D.split.*
split -b45M ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/metal/debug/libUrho3D.a ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/metal/debug/libUrho3D.split.
rm -f ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/metal/debug/libUrho3D.a

mkdir -p ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/mobile/ios
cp -f ${URHO3D_HOME}/DotNet/UrhoDotNet/mobile/ios/UrhoDotNet.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/mobile/ios