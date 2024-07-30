
./script/cmake_xcode_dotnet_metal_dylib.sh build-xcode-dotnet-metal-dylib
xcodebuild -project  build-xcode-dotnet-metal-dylib/Urho3D.xcodeproj -scheme Urho3D
mkdir -p DotNet/libs/macos/Release
cp -Lf build-xcode-dotnet-metal-dylib/lib/libUrho3D.dylib DotNet/libs/macos/Release