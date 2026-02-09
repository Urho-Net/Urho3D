
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
# Convert to .NET architecture naming
if [ "$HOST_ARCH" = "x86_64" ]; then
  DOTNET_ARCH="X64"
elif [ "$HOST_ARCH" = "aarch64" ] || [ "$HOST_ARCH" = "arm64" ]; then
  DOTNET_ARCH="Arm64"
else
  DOTNET_ARCH="$HOST_ARCH"
fi

echo "Building for Linux ${DOTNET_ARCH}..."

# Build Release
echo "  → Building Release configuration..."
./script/cmake_linux_dotnet_so.sh build-dotnet-lib
cd build-dotnet-lib/
make -j4 

if [ ! -e lib/libUrho3D.so ]; then
  echo "❌ libUrho3D.so does not exist. Exiting with an error."
  exit 1
fi

cd ..
mkdir -p DotNet/libs/linux/${DOTNET_ARCH}/Release
cp -L build-dotnet-lib/lib/libUrho3D.so  DotNet/libs/linux/${DOTNET_ARCH}/Release/
echo "  ✓ Linux ${DOTNET_ARCH} Release: DotNet/libs/linux/${DOTNET_ARCH}/Release/libUrho3D.so"

# Build Debug
echo "  → Building Debug configuration..."
./script/cmake_linux_dotnet_so.sh build-dotnet-lib-debug -DCMAKE_BUILD_TYPE=Debug
cd build-dotnet-lib-debug/
make -j4

if [ ! -e lib/libUrho3D.so ]; then
  echo "❌ Debug libUrho3D.so does not exist. Exiting with an error."
  exit 1
fi

cd ..
mkdir -p DotNet/libs/linux/${DOTNET_ARCH}/Debug
cp -L build-dotnet-lib-debug/lib/libUrho3D.so  DotNet/libs/linux/${DOTNET_ARCH}/Debug/
echo "  ✓ Linux ${DOTNET_ARCH} Debug:   DotNet/libs/linux/${DOTNET_ARCH}/Debug/libUrho3D.so"

echo ""
echo "Build complete:"
echo "  ✓ Linux ${DOTNET_ARCH} Release: DotNet/libs/linux/${DOTNET_ARCH}/Release/libUrho3D.so"
echo "  ✓ Linux ${DOTNET_ARCH} Debug:   DotNet/libs/linux/${DOTNET_ARCH}/Debug/libUrho3D.so"
