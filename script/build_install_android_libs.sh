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



./gradlew assembleRelease -P URHO3D_DOTNET=1 -P URHO3D_DATABASE_SQLITE=1 -P URHO3D_ANGELSCRIPT=0 -P URHO3D_LUA=0  -P URHO3D_LIB_TYPE=SHARED  -P URHO3D_SAMPLES=0 -P URHO3D_PCH=0

cp -f android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/armeabi-v7a/libUrho3D.so   ${URHONET_HOME_ROOT}/template/libs/android/armeabi-v7a
cp -f android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/x86/libUrho3D.so   ${URHONET_HOME_ROOT}/template/libs/android/x86
cp -f android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/arm64-v8a/libUrho3D.so      ${URHONET_HOME_ROOT}/template/libs/android/arm64-v8a
cp -f android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/x86_64/libUrho3D.so    ${URHONET_HOME_ROOT}/template/libs/android/x86_64

cp -f android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/armeabi-v7a/libUrhoMain.so   ${URHONET_HOME_ROOT}/template/libs/android/armeabi-v7a
# cp -f android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/x86/libUrhoMain.so   ${URHONET_HOME_ROOT}/template/libs/android/x86
cp -f android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/arm64-v8a/libUrhoMain.so     ${URHONET_HOME_ROOT}/template/libs/android/arm64-v8a
cp -f android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/x86_64/libUrhoMain.so    ${URHONET_HOME_ROOT}/template/libs/android/x86_64