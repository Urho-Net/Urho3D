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


git checkout v9.0.3

sed -i "" "s*--minimize**g" "eng/native/functions.cmake"
# Compiler error fix 
sed -i '' '/add_compile_options(-Wno-unknown-warning-option)/a\
\ \ \ \ add_compile_options(-Wno-anon-enum-enum-conversion)' eng/native/configurecompiler.cmake

sed -i '' '29,32d' src/native/libs/System.Security.Cryptography.Native.Apple/pal_rsa.c
sed -i '' '27,30d' src/native/libs/System.Security.Cryptography.Native.Apple/pal_ecc.c


./build.sh mono+libs  -os iOS -arch arm64  -c Release  

echo "Host processor = $(uname -m)"
ARCHITECTURE=$(uname -m)
cp -rf artifacts/bin/mono/iOS.arm64.Release/*.a  ${URHONET_HOME_ROOT}/template/libs/ios/
cp -rf artifacts/bin/native/net9.0-ios-Release-arm64/*.a ${URHONET_HOME_ROOT}/template/libs/ios/
cp -rf artifacts/bin/runtime/net9.0-ios-Release-arm64/*.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/bcl/ios/
cp -f artifacts/bin/mono/iOS.arm64.Release/System.Private.CoreLib.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/bcl/ios/System.Private.CoreLib.dll
cp -f artifacts/bin/mono/iOS.arm64.Release/cross/ios-arm64/mono-aot-cross  ${URHONET_HOME_ROOT}/tools/aotcompiler/ios/macos/${ARCHITECTURE}/mono-aot-cross

cd ${URHONET_HOME_ROOT}