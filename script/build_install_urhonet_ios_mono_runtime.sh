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

if [ -d runtime ]; then
    cd runtime
    git restore .
    ./build.sh --clean
    git checkout main
    git pull origin
else
    git clone --recursive https://github.com/dotnet/runtime.git
    cd runtime
fi

# Official .NET 8 release
git checkout v8.0.0

sed -i "" "s*--minimize**g" "eng/native/functions.cmake"
./build.sh mono+libs  -os iOS -arch arm64  -c Release

cp -rf artifacts/bin/mono/iOS.arm64.Release/*.a  ${URHONET_HOME_ROOT}/template/libs/ios/
cp -rf artifacts/bin/native/net8.0-iOS-Release-arm64/*.a ${URHONET_HOME_ROOT}/template/libs/ios/
cp -rf artifacts/bin/runtime/net8.0-iOS-Release-arm64/*.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/bcl/ios/
cp -f artifacts/bin/mono/iOS.arm64.Release/System.Private.CoreLib.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/bcl/ios/System.Private.CoreLib.dll
cp -f artifacts/bin/mono/iOS.arm64.Release/cross/ios-arm64/mono-aot-cross  ${URHONET_HOME_ROOT}/tools/aotcompiler/ios/macos/ios-arm64/aarch64-apple-darwin-mono-sgen

# TBD ELI , For now deleting since it is failing during iOS AOT compilation.
rm -f ${URHONET_HOME_ROOT}/template/libs/dotnet/bcl/ios/System.Security.Cryptography.ProtectedData.dll 

cd ${URHONET_HOME_ROOT}