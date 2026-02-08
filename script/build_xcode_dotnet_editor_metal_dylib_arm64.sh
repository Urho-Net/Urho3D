#!/bin/bash

HOST_ARCH=$(uname -m)

if [ "$HOST_ARCH" != "arm64" ]; then
    echo "⚠️  Skipping arm64 build on $HOST_ARCH host (arm64 builds only run on Apple Silicon)"
    exit 0
fi

echo "Building macOS arm64 Editor libraries (Release + Debug)..."

# Build Release
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "Building arm64 Release..."
./script/cmake_xcode_dotnet_editor_metal_dylib.sh build-xcode-dotnet-editor-metal-dylib-arm64 -DCMAKE_OSX_ARCHITECTURES=arm64
rm -rf build-xcode-dotnet-editor-metal-dylib-arm64/lib
xcodebuild -project build-xcode-dotnet-editor-metal-dylib-arm64/Urho3D.xcodeproj -scheme Urho3D -configuration Release -arch arm64 ONLY_ACTIVE_ARCH=NO
if [ ! -e build-xcode-dotnet-editor-metal-dylib-arm64/lib/libUrho3D.dylib ]; then
  echo "libUrho3D.dylib does not exist. Exiting with an error."
  exit 1
fi
mkdir -p DotNet/libs/editor/macos/arm64/Release
cp -Lf build-xcode-dotnet-editor-metal-dylib-arm64/lib/libUrho3D.dylib DotNet/libs/editor/macos/arm64/Release/
echo "✓ arm64 Release library built"

# Build Debug
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "Building arm64 Debug..."
rm -rf build-xcode-dotnet-editor-metal-dylib-arm64/lib
xcodebuild -project build-xcode-dotnet-editor-metal-dylib-arm64/Urho3D.xcodeproj -scheme Urho3D -configuration Debug -arch arm64 ONLY_ACTIVE_ARCH=NO
if [ ! -e build-xcode-dotnet-editor-metal-dylib-arm64/lib/libUrho3D.dylib ]; then
  echo "libUrho3D.dylib does not exist. Exiting with an error."
  exit 1
fi
mkdir -p DotNet/libs/editor/macos/arm64/Debug
cp -Lf build-xcode-dotnet-editor-metal-dylib-arm64/lib/libUrho3D.dylib DotNet/libs/editor/macos/arm64/Debug/
echo "✓ arm64 Debug library built"

echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "✅ macOS arm64 Editor libraries build complete"
