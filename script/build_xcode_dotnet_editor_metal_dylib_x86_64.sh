#!/bin/bash

echo "Building macOS x86_64 Editor libraries (Release + Debug)..."

# Build Release
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "Building x86_64 Release..."
./script/cmake_xcode_dotnet_editor_metal_dylib.sh build-xcode-dotnet-editor-metal-dylib-x86_64 -DCMAKE_OSX_ARCHITECTURES=x86_64
xcodebuild -project build-xcode-dotnet-editor-metal-dylib-x86_64/Urho3D.xcodeproj -scheme Urho3D -configuration Release
mkdir -p DotNet/libs/editor/macos/x86_64/Release
cp -Lf build-xcode-dotnet-editor-metal-dylib-x86_64/lib/libUrho3D.dylib DotNet/libs/editor/macos/x86_64/Release/
echo "✓ x86_64 Release library built"

# Build Debug
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "Building x86_64 Debug..."
xcodebuild -project build-xcode-dotnet-editor-metal-dylib-x86_64/Urho3D.xcodeproj -scheme Urho3D -configuration Debug
mkdir -p DotNet/libs/editor/macos/x86_64/Debug
cp -Lf build-xcode-dotnet-editor-metal-dylib-x86_64/lib/Debug/libUrho3D.dylib DotNet/libs/editor/macos/x86_64/Debug/
echo "✓ x86_64 Debug library built"

echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "✅ macOS x86_64 Editor libraries build complete"
