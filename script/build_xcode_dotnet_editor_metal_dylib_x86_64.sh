#!/bin/bash

echo "Building macOS X64 Editor libraries (Release + Debug)..."

# Build Release
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "Building X64 Release..."
./script/cmake_xcode_dotnet_editor_metal_dylib.sh build-xcode-dotnet-editor-metal-dylib-x86_64 -DCMAKE_OSX_ARCHITECTURES=x86_64
rm -rf build-xcode-dotnet-editor-metal-dylib-x86_64/lib
xcodebuild -project build-xcode-dotnet-editor-metal-dylib-x86_64/Urho3D.xcodeproj -scheme Urho3D -configuration Release -arch x86_64 ONLY_ACTIVE_ARCH=NO
if [ ! -e build-xcode-dotnet-editor-metal-dylib-x86_64/lib/libUrho3D.dylib ]; then
  echo "libUrho3D.dylib does not exist. Exiting with an error."
  exit 1
fi
mkdir -p DotNet/libs/editor/macos/X64/Release
cp -Lf build-xcode-dotnet-editor-metal-dylib-x86_64/lib/libUrho3D.dylib DotNet/libs/editor/macos/X64/Release/
echo "✓ X64 Release library built"

# Build Debug
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "Building X64 Debug..."
rm -rf build-xcode-dotnet-editor-metal-dylib-x86_64/lib
xcodebuild -project build-xcode-dotnet-editor-metal-dylib-x86_64/Urho3D.xcodeproj -scheme Urho3D -configuration Debug -arch x86_64 ONLY_ACTIVE_ARCH=NO
if [ ! -e build-xcode-dotnet-editor-metal-dylib-x86_64/lib/libUrho3D.dylib ]; then
  echo "libUrho3D.dylib does not exist. Exiting with an error."
  exit 1
fi
mkdir -p DotNet/libs/editor/macos/X64/Debug
cp -Lf build-xcode-dotnet-editor-metal-dylib-x86_64/lib/libUrho3D.dylib DotNet/libs/editor/macos/X64/Debug/
echo "✓ X64 Debug library built"

echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "✅ macOS X64 Editor libraries build complete"
