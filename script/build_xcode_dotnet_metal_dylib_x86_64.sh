#!/bin/bash
# Build only x86_64 architecture

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

echo "Building for x86_64..."

# Build Release
echo "  → Building Release configuration..."
rm -rf build-xcode-dotnet-metal-dylib/lib
xcodebuild -project build-xcode-dotnet-metal-dylib/Urho3D.xcodeproj -scheme Urho3D -configuration Release -arch x86_64 ONLY_ACTIVE_ARCH=NO
if [ ! -e build-xcode-dotnet-metal-dylib/lib/libUrho3D.dylib ]; then
  echo "libUrho3D.dylib does not exist. Exiting with an error."
  exit 1
fi

mkdir -p DotNet/libs/macos/x86_64/Release
cp -Lf build-xcode-dotnet-metal-dylib/lib/libUrho3D.dylib DotNet/libs/macos/x86_64/Release/

# Ad-hoc code sign the library (required for macOS to load it)
echo "  → Code signing x86_64 Release library..."
codesign --force --sign - DotNet/libs/macos/x86_64/Release/libUrho3D.dylib

echo "  ✓ x86_64 Release:  DotNet/libs/macos/x86_64/Release/libUrho3D.dylib"

# Build Debug
echo "  → Building Debug configuration..."
rm -rf build-xcode-dotnet-metal-dylib/lib
xcodebuild -project build-xcode-dotnet-metal-dylib/Urho3D.xcodeproj -scheme Urho3D -configuration Debug -arch x86_64 ONLY_ACTIVE_ARCH=NO
if [ ! -e build-xcode-dotnet-metal-dylib/lib/libUrho3D.dylib ]; then
  echo "libUrho3D.dylib does not exist. Exiting with an error."
  exit 1
fi

mkdir -p DotNet/libs/macos/x86_64/Debug
cp -Lf build-xcode-dotnet-metal-dylib/lib/libUrho3D.dylib DotNet/libs/macos/x86_64/Debug/

# Ad-hoc code sign the library (required for macOS to load it)
echo "  → Code signing x86_64 Debug library..."
codesign --force --sign - DotNet/libs/macos/x86_64/Debug/libUrho3D.dylib

echo "  ✓ x86_64 Debug:    DotNet/libs/macos/x86_64/Debug/libUrho3D.dylib"

echo ""
echo "Build complete:"
echo "  ✓ x86_64 Release:  DotNet/libs/macos/x86_64/Release/libUrho3D.dylib"
echo "  ✓ x86_64 Debug:    DotNet/libs/macos/x86_64/Debug/libUrho3D.dylib"
