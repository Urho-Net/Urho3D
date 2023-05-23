URHONET_HOME_ROOT=$(cat ~/.urhonet_config/urhonethome)
URHO3D_HOME=$(pwd)

if [ ! -d "$URHONET_HOME_ROOT" ]; then
    echo  "Urho.Net is not configured , please  run configure.sh (configure.bat on Windows) from the Urho.Net installation folder  "
    exit -1
else
    echo "URHONET_HOME_ROOT=${URHONET_HOME_ROOT}"
fi


mkdir -p ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/desktop
cp -f ${URHO3D_HOME}/DotNet/UrhoDotNet/desktop/UrhoDotNet.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/desktop
cp -f ${URHO3D_HOME}/DotNet/UrhoDotNet/desktop/UrhoDotNet.xml ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/desktop
mkdir -p ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/mobile/ios
cp -f ${URHO3D_HOME}/DotNet/UrhoDotNet/mobile/ios/UrhoDotNet.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/mobile/ios
mkdir -p ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/mobile/android
cp -f ${URHO3D_HOME}/DotNet/UrhoDotNet/mobile/android/UrhoDotNet.dll  ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/mobile/android
mkdir -p ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/web
cp -f ${URHO3D_HOME}/DotNet/UrhoDotNet/web/UrhoDotNet.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/web

cp -fRL ${URHO3D_HOME}/build-ios-dotnet-lib/include ${URHONET_HOME_ROOT}/template/IOS

cp -f ${URHO3D_HOME}/Source/Samples/MonoEmbed/mono_enc_dec_keys.cpp  ${URHONET_HOME_ROOT}/template/IOS/mono_enc_dec_keys.cpp 
cp -f ${URHO3D_HOME}/Source/Samples/MonoEmbed/mono_enc_dec.cpp  ${URHONET_HOME_ROOT}/template/IOS/mono_enc_dec.cpp 
cp -f ${URHO3D_HOME}/Source/Samples/MonoEmbed/mono_support.cpp  ${URHONET_HOME_ROOT}/template/IOS/mono_support.cpp 
cp -f ${URHO3D_HOME}/Source/Samples/MonoEmbed/mono_support.h  ${URHONET_HOME_ROOT}/template/IOS/mono_support.h
cp -f ${URHO3D_HOME}/Source/Samples/MonoEmbed/MonoEmbed.cpp ${URHONET_HOME_ROOT}/template/IOS/MonoEmbed.cpp
cp -f ${URHO3D_HOME}/Source/Samples/MonoEmbed/MonoEmbed.h  ${URHONET_HOME_ROOT}/template/IOS/MonoEmbed.h


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

mkdir -p ${URHONET_HOME_ROOT}/template/libs/web
cp -f ${URHO3D_HOME}/DotNet/libs/wasm/index.html  ${URHONET_HOME_ROOT}/template/libs/web/index.html
cp -f ${URHO3D_HOME}/DotNet/libs/wasm/MonoEmbedded.js  ${URHONET_HOME_ROOT}/template/libs/web/MonoEmbedded.js
cp -f ${URHO3D_HOME}/DotNet/libs/wasm/MonoEmbedded.wasm  ${URHONET_HOME_ROOT}/template/libs/web/MonoEmbedded.wasm

mkdir -p ${URHONET_HOME_ROOT}/template/libs/macos
cp -f ${URHO3D_HOME}/DotNet/libs/macos/Release/libUrho3D.dylib  ${URHONET_HOME_ROOT}/template/libs/macos

mkdir -p ${URHONET_HOME_ROOT}/template/libs/windows
cp -f ${URHO3D_HOME}/DotNet/libs/windows/release/Urho3D.dll  ${URHONET_HOME_ROOT}/template/libs/windows

mkdir -p ${URHONET_HOME_ROOT}/template/libs/linux
cp -f ${URHO3D_HOME}/DotNet/libs/linux/release/libUrho3D.so  ${URHONET_HOME_ROOT}/template/libs/linux

cp -f ${URHO3D_HOME}/DotNet/libs/android/net6.0-Release/arm64-v8a/libUrho3D.so     ${URHONET_HOME_ROOT}/template/libs/android/arm64-v8a
cp -f ${URHO3D_HOME}/DotNet/libs/android/net6.0-Release/armeabi-v7a/libUrho3D.so    ${URHONET_HOME_ROOT}/template/libs/android/armeabi-v7a
cp -f ${URHO3D_HOME}/DotNet/libs/android/net6.0-Release/x86/libUrho3D.so     ${URHONET_HOME_ROOT}/template/libs/android/x86
cp -f ${URHO3D_HOME}/DotNet/libs/android/net6.0-Release/x86_64/libUrho3D.so     ${URHONET_HOME_ROOT}/template/libs/android/x86_64

cp -f ${URHO3D_HOME}/DotNet/libs/android/net6.0-Release/arm64-v8a/libMonoEmbedded.so     ${URHONET_HOME_ROOT}/template/libs/android/arm64-v8a
cp -f ${URHO3D_HOME}/DotNet/libs/android/net6.0-Release/armeabi-v7a/libMonoEmbedded.so     ${URHONET_HOME_ROOT}/template/libs/android/armeabi-v7a
cp -f ${URHO3D_HOME}/DotNet/libs/android/net6.0-Release/x86/libMonoEmbedded.so     ${URHONET_HOME_ROOT}/template/libs/android/x86
cp -f ${URHO3D_HOME}/DotNet/libs/android/net6.0-Release/x86_64/libMonoEmbedded.so    ${URHONET_HOME_ROOT}/template/libs/android/x86_64
