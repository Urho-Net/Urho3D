URHONET_HOME_ROOT=$(cat ~/.urhonet_config/urhonethome)
script_path=$(readlink -f "$0")
scriptDir=$(dirname "$script_path")
URHO3D_HOME=${scriptDir}/../
cd ${URHO3D_HOME}

if [ ! -d "$URHONET_HOME_ROOT" ]; then
    echo  "Urho.Net is not configured , please  run configure.sh (configure.bat on Windows) from the Urho.Net installation folder  "
    exit -1
else
    echo "URHONET_HOME_ROOT=${URHONET_HOME_ROOT}"
fi


# Android
mkdir -p ${URHONET_HOME_ROOT}/template/libs/android/armeabi-v7a
mkdir -p ${URHONET_HOME_ROOT}/template/libs/android/arm64-v8a
mkdir -p ${URHONET_HOME_ROOT}/template/libs/android/x86_64

cp -f ${URHO3D_HOME}/DotNet/libs/android/Release/armeabi-v7a/libUrho3D.so   ${URHONET_HOME_ROOT}/template/libs/android/armeabi-v7a
cp -f ${URHO3D_HOME}/DotNet/libs/android/Release/arm64-v8a/libUrho3D.so      ${URHONET_HOME_ROOT}/template/libs/android/arm64-v8a
cp -f ${URHO3D_HOME}/DotNet/libs/android/Release/x86_64/libUrho3D.so    ${URHONET_HOME_ROOT}/template/libs/android/x86_64

cp -f ${URHO3D_HOME}/DotNet/libs/android/Release/armeabi-v7a/libUrhoMain.so   ${URHONET_HOME_ROOT}/template/libs/android/armeabi-v7a
cp -f ${URHO3D_HOME}/DotNet/libs/android/Release/arm64-v8a/libUrhoMain.so     ${URHONET_HOME_ROOT}/template/libs/android/arm64-v8a
cp -f ${URHO3D_HOME}/DotNet/libs/android/Release/x86_64/libUrhoMain.so    ${URHONET_HOME_ROOT}/template/libs/android/x86_64



#iOS
mkdir -p ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/debug
cp -rf ${URHO3D_HOME}/DotNet/libs/iphone/Debug-iphoneos/Urho3D.framework ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/debug
rm -f ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/debug/Urho3D.framework/Urho3D.split.*
split -b45M  ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/debug/Urho3D.framework/Urho3D  ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/debug/Urho3D.framework/Urho3D.split.
rm -f ${URHONET_HOME_ROOT}/template/libs/ios/urho3d/debug/Urho3D.framework/Urho3D
mkdir -p ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/mobile/ios
cp -f ${URHO3D_HOME}/DotNet/UrhoDotNet/mobile/ios/release/net10.0/UrhoDotNet.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/mobile/ios

#macOS
mkdir -p ${URHONET_HOME_ROOT}/template/libs/macos/Arm64
cp -f ${URHO3D_HOME}/DotNet/libs/macos/arm64/Release/libUrho3D.dylib  ${URHONET_HOME_ROOT}/template/libs/macos/Arm64
mkdir -p ${URHONET_HOME_ROOT}/template/libs/macos/X64
cp -f ${URHO3D_HOME}/DotNet/libs/macos/x86_64/Release/libUrho3D.dylib  ${URHONET_HOME_ROOT}/template/libs/macos/X64

#Windows
mkdir -p ${URHONET_HOME_ROOT}/template/libs/windows
cp -f ${URHO3D_HOME}/DotNet/libs/windows/Release/Urho3D.dll  ${URHONET_HOME_ROOT}/template/libs/windows

#Linux
mkdir -p ${URHONET_HOME_ROOT}/template/libs/linux
cp -f ${URHO3D_HOME}/DotNet/libs/linux/x86_64/Release/libUrho3D.so  ${URHONET_HOME_ROOT}/template/libs/linux


# WebAssembly
mkdir -p ${URHONET_HOME_ROOT}/template/libs/web
cp -f ${URHO3D_HOME}/DotNet/libs/wasm/Release/Urho3D.a  ${URHONET_HOME_ROOT}/template/libs/web/Urho3D.a

