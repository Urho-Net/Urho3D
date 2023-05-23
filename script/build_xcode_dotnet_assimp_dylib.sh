
./script/cmake_xcode_dotnet_assimp_dylib.sh build-xcode-dotnet-assimp-dylib
xcodebuild -project  build-xcode-dotnet-assimp-dylib/Urho3D.xcodeproj -scheme Urho3D
cp -Lf build-xcode-dotnet-assimp-dylib/lib/libUrho3D.dylib DotNet/libs/macos/Release