unamestr=$(uname)

if [[ "$unamestr" == "Darwin" ]]; then
    function readlink(){
    DIR="${1%/*}"
    (cd "$DIR" && echo "$(pwd -P)")
    }

    script_path=$(readlink  "$0")
    scriptDir=$(dirname "$script_path")
    URHO3D_HOME=${scriptDir}
else
	script_path=$(readlink -f "$0")
    scriptDir=$(dirname "$script_path")
    URHO3D_HOME=${scriptDir}/../
fi

LOCAL_CLANG=tools/clang+llvm-3.7.0-x86_64-apple-darwin/bin/clang
CUSTOM_CLANG=$(pwd)/${LOCAL_CLANG}
MONO64=mono64
XBUILD=xbuild
 

shopt -s expand_aliases
if [[ "$unamestr" == "Darwin" ]]; then
	alias aliassedinplace='sed -i ""'
else
	alias aliassedinplace='sed -i""'
fi

cd ${URHO3D_HOME}

# Only on Mac
if [[ "$unamestr" == "Darwin" ]]; then

rm -rf ${URHO3D_HOME}/DotNet/Bindings/Portable/Generated

./script/cmake_xcode.sh build-xcode -DURHO3D_DATABASE_SQLITE=1 -DURHO3D_PCH=0  -DURHO3D_WEBP=0 -DURHO3D_LUA=0 -DURHO3D_ANGELSCRIPT=0 -DURHO3D_TOOLS=1  -DCMAKE_OSX_DEPLOYMENT_TARGET=10.15

${CUSTOM_CLANG} -cc1 -stdlib=libc++ -std=c++0x -emit-pch -DURHO3D_OPENGL -o DotNet/Bindings/Urho.pch DotNet/Bindings/Native/all-urho.cpp  -Ibuild-xcode/include  -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include -Ibuild-xcode/include/Urho3D/ThirdParty -Ibuild-xcode/include/Urho3D/ThirdParty/Bullet -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenGL.framework

if [ ! -e DotNet/Bindings/Urho.pch ]; then
  echo "DotNet/Bindings/Urho.pch does not exist. Exiting with an error."
  exit 1
fi


cd tools/SharpieBinder 
$(echo "${MONO64} ${URHO3D_HOME}/tools/Nuget.exe restore SharpieBinder.sln")
${XBUILD} SharpieBinder.csproj 
cd bin 
${MONO64} SharpieBinder.exe

# Minor corrections on Generated files
aliassedinplace "s*public void Remove ()*public void Remove2 ()*g" "${URHO3D_HOME}/DotNet/Bindings/Portable/Generated/Node.cs"
aliassedinplace "s*private void SetMaterial (Material material)*public void SetMaterial (Material material)*g" "${URHO3D_HOME}/DotNet/Bindings/Portable/Generated/StaticModel.cs"
aliassedinplace "s*public void BroadcastMessage*private void BroadcastMessage*g" "${URHO3D_HOME}/DotNet/Bindings/Portable/Generated/Network.cs"

# Hack , the files below are generated with errors , for now I am using customized/modified files , so deleting the generated files .
rm -f ${URHO3D_HOME}/DotNet/Bindings/Portable/Generated/Key.cs
rm -f ${URHO3D_HOME}/DotNet/Bindings/Portable/Generated/Scancode.cs
rm -f ${URHO3D_HOME}/DotNet/Bindings/Portable/Generated/RefCount.cs
rm -f ${URHO3D_HOME}/DotNet/Bindings/Portable/Generated/UrhoString.cs
rm -f ${URHO3D_HOME}/DotNet/Bindings/Portable/Generated/Input.cs
rm -f ${URHO3D_HOME}/DotNet/Bindings/Portable/Generated/WorkItem.cs

# TBD ELI , not sure about these ones
rm -f ${URHO3D_HOME}/DotNet/Bindings/Portable/Generated/Algorithm.cs
rm -f ${URHO3D_HOME}/DotNet/Bindings/Portable/Generated/Feature.cs

# generate Object.Events.cs
cd ${URHO3D_HOME}/DotNet/Bindings && perl ParseEvents.pl ${URHO3D_HOME}/build-xcode/include/Urho3d/*/*h
# corrections on generated Object.Events.cs
aliassedinplace "s*VariantMap*EventDataContainer*g" "${URHO3D_HOME}/DotNet/Bindings/Portable/Generated/Object.Events.cs"

fi


# build UrhoDotNet.dll  assembly for all supported platforms
cd ${URHO3D_HOME}/DotNet/Bindings
./build-desktop-bindings.sh 
./build-ios-bindings.sh
./build-android-bindings.sh
./build-web-bindings.sh

cd ${URHO3D_HOME}

# build Mono.Android.dll  assembly for all supported platforms
cd ${URHO3D_HOME}/DotNet/AndroidEnvironment
./build-android-runtime-environment.sh

cd ${URHO3D_HOME}

files=("DotNet/UrhoDotNet/desktop/UrhoDotNet.dll" 
		"DotNet/UrhoDotNet/mobile/android/UrhoDotNet.dll" 
		"DotNet/UrhoDotNet/mobile/android/Mono.Android.dll"
		"DotNet/UrhoDotNet/mobile/ios/UrhoDotNet.dll" 
		"DotNet/UrhoDotNet/web/UrhoDotNet.dll"
		"${URHO3D_HOME}/DotNet/Bindings/Portable/Generated/binding.cpp")

for file in "${files[@]}"; do
  if [[ ! -e "$file" ]]; then
    echo "Error: $file does not exist"
    exit 1
  fi
done

# copy the native binding file to the right Source folder
cp -f ${URHO3D_HOME}/DotNet/Bindings/Portable/Generated/binding.cpp ${URHO3D_HOME}/Source/Urho3D/DotNet

