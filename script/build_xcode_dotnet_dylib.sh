
./script/cmake_xcode_dotnet_dylib.sh build-xcode-dotnet-dylib
xcodebuild -project  build-xcode-dotnet-dylib/Urho3D.xcodeproj -scheme Urho3D
mkdir -p DotNet/libs/macos/Release
cp -Lf build-xcode-dotnet-dylib/lib/libUrho3D.dylib DotNet/libs/macos/Release