URHONET_HOME_ROOT=$(cat ~/.urhonet_config/urhonethome)
URHO3D_HOME=$(pwd)

if [ ! -d "$URHONET_HOME_ROOT" ]; then
    echo  "Urho.Net is not configured , please  run configure.sh (configure.bat on Windows) from the Urho.Net installation folder  "
    exit -1
else
    echo "URHONET_HOME_ROOT=${URHONET_HOME_ROOT}"
fi


cp -f ${URHO3D_HOME}/DotNet/libs/android/net6.0-Release/arm64-v8a/libUrho3D.so     ${URHONET_HOME_ROOT}/template/libs/android/arm64-v8a
cp -f ${URHO3D_HOME}/DotNet/libs/android/net6.0-Release/armeabi-v7a/libUrho3D.so    ${URHONET_HOME_ROOT}/template/libs/android/armeabi-v7a
cp -f ${URHO3D_HOME}/DotNet/libs/android/net6.0-Release/x86/libUrho3D.so     ${URHONET_HOME_ROOT}/template/libs/android/x86
cp -f ${URHO3D_HOME}/DotNet/libs/android/net6.0-Release/x86_64/libUrho3D.so     ${URHONET_HOME_ROOT}/template/libs/android/x86_64

cp -f ${URHO3D_HOME}/DotNet/libs/android/net6.0-Release/arm64-v8a/libMonoEmbedded.so     ${URHONET_HOME_ROOT}/template/libs/android/arm64-v8a
cp -f ${URHO3D_HOME}/DotNet/libs/android/net6.0-Release/armeabi-v7a/libMonoEmbedded.so     ${URHONET_HOME_ROOT}/template/libs/android/armeabi-v7a
cp -f ${URHO3D_HOME}/DotNet/libs/android/net6.0-Release/x86/libMonoEmbedded.so     ${URHONET_HOME_ROOT}/template/libs/android/x86
cp -f ${URHO3D_HOME}/DotNet/libs/android/net6.0-Release/x86_64/libMonoEmbedded.so    ${URHONET_HOME_ROOT}/template/libs/android/x86_64
