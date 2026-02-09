
URHO3D_HOME=$(pwd)

CWD=$(pwd)
unamestr=$(uname)
# Switch-on alias expansion within the script 
shopt -s expand_aliases

#Alias the sed in-place command for OSX and Linux - incompatibilities between BSD and Linux sed args
if [[ "$unamestr" == "Darwin" ]]; then
	alias aliassedinplace='sed -i ""'
else
	#For Linux, notice no space after the '-i' 
	alias aliassedinplace='sed -i""'
fi

HOST_ARCH=$(uname -m)

echo "Building for Linux ${HOST_ARCH}..."

# Build Release
echo "  → Building Release configuration..."
./script/cmake_linux_dotnet_editor_so.sh build-dotnet-editor-lib
cd build-dotnet-editor-lib/
make -j4 

if [ ! -e lib/libUrho3D.so ]; then
  echo "❌ libUrho3D.so does not exist. Exiting with an error."
  exit 1
fi

cd ..
mkdir -p DotNet/libs/editor/linux/${HOST_ARCH}/Release
cp -L build-dotnet-editor-lib/lib/libUrho3D.so  DotNet/libs/editor/linux/${HOST_ARCH}/Release/
echo "  ✓ Linux ${HOST_ARCH} Release: DotNet/libs/editor/linux/${HOST_ARCH}/Release/libUrho3D.so"

# Build Debug
echo "  → Building Debug configuration..."
./script/cmake_linux_dotnet_editor_so.sh build-dotnet-editor-lib-debug -DCMAKE_BUILD_TYPE=Debug
cd build-dotnet-editor-lib-debug/
make -j4

if [ ! -e lib/libUrho3D.so ]; then
  echo "❌ Debug libUrho3D.so does not exist. Exiting with an error."
  exit 1
fi

cd ..
mkdir -p DotNet/libs/editor/linux/${HOST_ARCH}/Debug
cp -L build-dotnet-editor-lib-debug/lib/libUrho3D.so  DotNet/libs/editor/linux/${HOST_ARCH}/Debug/
echo "  ✓ Linux ${HOST_ARCH} Debug:   DotNet/libs/editor/linux/${HOST_ARCH}/Debug/libUrho3D.so"

echo ""
echo "Build complete:"
echo "  ✓ Linux ${HOST_ARCH} Release: DotNet/libs/editor/linux/${HOST_ARCH}/Release/libUrho3D.so"
echo "  ✓ Linux ${HOST_ARCH} Debug:   DotNet/libs/editor/linux/${HOST_ARCH}/Debug/libUrho3D.so"
