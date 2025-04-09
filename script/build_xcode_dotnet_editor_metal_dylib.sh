
./script/cmake_xcode_dotnet_editor_metal_dylib.sh build-xcode-dotnet-editor-metal-dylib
xcodebuild -project  build-xcode-dotnet-editor-metal-dylib/Urho3D.xcodeproj -scheme Urho3D -configuration Release
mkdir -p DotNet/libs/macos/Release
cp -Lf build-xcode-dotnet-editor-metal-dylib/lib/libUrho3D.dylib DotNet/libs/macos/Release