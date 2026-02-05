function readlink(){
    DIR="${1%/*}"
    (cd "$DIR" && echo "$(pwd -P)")
}

script_path=$(readlink  "$0")
scriptDir=$(dirname "$script_path")
URHO3D_HOME=${scriptDir}

./script/cmake_xcode_dotnet_metal_dylib.sh build-xcode-dotnet-metal-dylib

# Detect host architecture
HOST_ARCH=$(uname -m)
echo "Host architecture: $HOST_ARCH"

# Build for arm64 (only on Apple Silicon or if cross-compilation is available)
if [ "$HOST_ARCH" = "arm64" ]; then
  echo "Building for arm64..."
  rm -rf build-xcode-dotnet-metal-dylib/lib
  xcodebuild -project build-xcode-dotnet-metal-dylib/Urho3D.xcodeproj -scheme Urho3D -configuration Release -arch arm64 ONLY_ACTIVE_ARCH=NO
  if [ ! -e build-xcode-dotnet-metal-dylib/lib/libUrho3D.dylib ]; then
    echo "libUrho3D.dylib does not exist. Exiting with an error."
    exit 1
  fi
  mkdir -p DotNet/libs/macos/arm64/Release
  cp -Lf build-xcode-dotnet-metal-dylib/lib/libUrho3D.dylib DotNet/libs/macos/arm64/Release/
  echo "  ✓ arm64:   DotNet/libs/macos/arm64/Release/libUrho3D.dylib"
else
  echo "  ⊘ Skipping arm64 build (requires Apple Silicon host)"
fi

# Build for x86_64 (works on both Intel and Apple Silicon)
echo "Building for x86_64..."
rm -rf build-xcode-dotnet-metal-dylib/lib
xcodebuild -project build-xcode-dotnet-metal-dylib/Urho3D.xcodeproj -scheme Urho3D -configuration Release -arch x86_64 ONLY_ACTIVE_ARCH=NO
if [ ! -e build-xcode-dotnet-metal-dylib/lib/libUrho3D.dylib ]; then
  echo "libUrho3D.dylib does not exist. Exiting with an error."
  exit 1
fi
mkdir -p DotNet/libs/macos/x86_64/Release
cp -Lf build-xcode-dotnet-metal-dylib/lib/libUrho3D.dylib DotNet/libs/macos/x86_64/Release/

echo ""
echo "Build complete:"
if [ "$HOST_ARCH" = "arm64" ]; then
  echo "  ✓ arm64:   DotNet/libs/macos/arm64/Release/libUrho3D.dylib"
fi
echo "  ✓ x86_64:  DotNet/libs/macos/x86_64/Release/libUrho3D.dylib"