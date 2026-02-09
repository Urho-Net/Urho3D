#!/bin/bash
# Build only arm64 architecture

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

if [ "$HOST_ARCH" != "arm64" ]; then
  echo "ERROR: This script requires an arm64 (Apple Silicon) host"
  exit 1
fi

echo "Building for Arm64..."

# Build Release
echo "  → Building Release configuration..."
rm -rf build-xcode-dotnet-metal-dylib/lib
xcodebuild -project build-xcode-dotnet-metal-dylib/Urho3D.xcodeproj -scheme Urho3D -configuration Release -arch arm64 ONLY_ACTIVE_ARCH=NO
if [ ! -e build-xcode-dotnet-metal-dylib/lib/libUrho3D.dylib ]; then
  echo "libUrho3D.dylib does not exist. Exiting with an error."
  exit 1
fi

mkdir -p DotNet/libs/macos/Arm64/Release
cp -Lf build-xcode-dotnet-metal-dylib/lib/libUrho3D.dylib DotNet/libs/macos/Arm64/Release/

# Ad-hoc code sign the library (required for macOS to load it)
echo "  → Code signing Arm64 Release library..."
codesign --force --sign - DotNet/libs/macos/Arm64/Release/libUrho3D.dylib

echo "  ✓ Arm64 Release:   DotNet/libs/macos/Arm64/Release/libUrho3D.dylib"

# Build Debug
echo "  → Building Debug configuration..."
rm -rf build-xcode-dotnet-metal-dylib/lib
xcodebuild -project build-xcode-dotnet-metal-dylib/Urho3D.xcodeproj -scheme Urho3D -configuration Debug -arch arm64 ONLY_ACTIVE_ARCH=NO
if [ ! -e build-xcode-dotnet-metal-dylib/lib/libUrho3D.dylib ]; then
  echo "libUrho3D.dylib does not exist. Exiting with an error."
  exit 1
fi

mkdir -p DotNet/libs/macos/Arm64/Debug
cp -Lf build-xcode-dotnet-metal-dylib/lib/libUrho3D.dylib DotNet/libs/macos/Arm64/Debug/

# Ad-hoc code sign the library (required for macOS to load it)
echo "  → Code signing Arm64 Debug library..."
codesign --force --sign - DotNet/libs/macos/Arm64/Debug/libUrho3D.dylib

echo "  ✓ Arm64 Debug:     DotNet/libs/macos/Arm64/Debug/libUrho3D.dylib"

echo ""
echo "Build complete:"
echo "  ✓ Arm64 Release:   DotNet/libs/macos/Arm64/Release/libUrho3D.dylib"
echo "  ✓ Arm64 Debug:     DotNet/libs/macos/Arm64/Debug/libUrho3D.dylib"
