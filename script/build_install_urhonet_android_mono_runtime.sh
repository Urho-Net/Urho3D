URHONET_HOME_ROOT=$(cat ~/.urhonet_config/urhonethome)
URHO3D_HOME=$(pwd)
unamestr=$(uname)

if [ ! -d "$URHONET_HOME_ROOT" ]; then
    echo  "Urho.Net is not configured , please  run configure.sh (configure.bat on Windows) from the Urho.Net installation folder  "
    exit -1
else
    echo "URHONET_HOME_ROOT=${URHONET_HOME_ROOT}"
fi

if [[ "$unamestr" == "Darwin" ]]; then
	outputdir="macos"
else
	outputdir="linux"
fi


if [ ! -d runtime ]; then
    git clone --recursive https://github.com/dotnet/runtime.git
fi

cd runtime
git checkout v6.0.11

./build.sh mono+libs -os Android -arch arm64 -c Release 
./build.sh mono+libs -os Android -arch arm -c Release
./build.sh mono+libs -os Android -arch x86 -c Release
./build.sh mono+libs -os Android -arch x64 -c Release

cp -rf artifacts/bin/mono/Android.arm.Release/*.so  ${URHONET_HOME_ROOT}/template/libs/android/armeabi-v7a/
cp -rf artifacts/bin/native/net6.0-Android-Release-arm/*.so  ${URHONET_HOME_ROOT}/template/libs/android/armeabi-v7a/

cp -rf artifacts/bin/mono/Android.arm64.Release/*.so  ${URHONET_HOME_ROOT}/template/libs/android/arm64-v8a/
cp -rf artifacts/bin/native/net6.0-Android-Release-arm64/*.so  ${URHONET_HOME_ROOT}/template/libs/android/arm64-v8a/

cp -rf artifacts/bin/mono/Android.x64.Release/*.so  ${URHONET_HOME_ROOT}/template/libs/android/x86_64/
cp -rf artifacts/bin/native/net6.0-Android-Release-x64/*.so  ${URHONET_HOME_ROOT}/template/libs/android/x86_64/

cp -rf artifacts/bin/mono/Android.x86.Release/*.so  ${URHONET_HOME_ROOT}/template/libs/android/x86/
cp -rf artifacts/bin/native/net6.0-Android-Release-x86/*.so  ${URHONET_HOME_ROOT}/template/libs/android/x86/

# Assuming all assemblies are the same for each ABI
cp -rf artifacts/bin/runtime/net6.0-Android-Release-arm/*.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/bcl/android/common/

cp -f artifacts/bin/mono/Android.arm.Release/System.Private.CoreLib.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/bcl/android/armeabi-v7a/System.Private.CoreLib.dll
cp -f artifacts/bin/mono/Android.arm64.Release/System.Private.CoreLib.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/bcl/android/arm64-v8a/System.Private.CoreLib.dll
cp -f artifacts/bin/mono/Android.x64.Release/System.Private.CoreLib.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/bcl/android/x86_64/System.Private.CoreLib.dll
cp -f artifacts/bin/mono/Android.x86.Release/System.Private.CoreLib.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/bcl/android/x86/System.Private.CoreLib.dll

mkdir -p ${URHONET_HOME_ROOT}/tools/aotcompiler/android/${outputdir}/android-arm
cp -f artifacts/bin/mono/Android.arm.Release/cross/android-arm/mono-aot-cross  ${URHONET_HOME_ROOT}/tools/aotcompiler/android/${outputdir}/android-arm/mono-aot-cross
mkdir -p ${URHONET_HOME_ROOT}/tools/aotcompiler/android/${outputdir}/android-arm64
cp -f artifacts/bin/mono/Android.arm64.Release/cross/android-arm64/mono-aot-cross  ${URHONET_HOME_ROOT}/tools/aotcompiler/android/${outputdir}/android-arm64/mono-aot-cross
mkdir -p ${URHONET_HOME_ROOT}/tools/aotcompiler/android/${outputdir}/android-x64
cp -f artifacts/bin/mono/Android.x64.Release/cross/android-x64/mono-aot-cross  ${URHONET_HOME_ROOT}/tools/aotcompiler/android/${outputdir}/android-x64/mono-aot-cross
mkdir -p ${URHONET_HOME_ROOT}/tools/aotcompiler/android/${outputdir}/android-x86
cp -f artifacts/bin/mono/Android.x86.Release/cross/android-x86/mono-aot-cross  ${URHONET_HOME_ROOT}/tools/aotcompiler/android/${outputdir}/android-x86/mono-aot-cross

cd ${URHONET_HOME_ROOT}