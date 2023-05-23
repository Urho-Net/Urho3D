
./script/cmake_ios_dotnet_lib.sh build-ios-dotnet-lib
xcodebuild -project  build-ios-dotnet-lib/Urho3D.xcodeproj -target Urho3D -configuration Release
cp -Lf build-ios-dotnet-lib/lib/libUrho3D.a  DotNet/libs/iphone/Release-iphoneos/libUrho3D-GLES.a 
xcodebuild -project  build-ios-dotnet-lib/Urho3D.xcodeproj -target Urho3D -configuration Debug
cp -Lf build-ios-dotnet-lib/lib/libUrho3D.a  DotNet/libs/iphone/Debug-iphoneos/libUrho3D-GLES.a 

./script/cmake_ios_dotnet_metal_lib.sh build-ios-dotnet-metal-lib
xcodebuild -project  build-ios-dotnet-metal-lib/Urho3D.xcodeproj -target Urho3D -configuration Release
cp -Lf build-ios-dotnet-metal-lib/lib/libUrho3D.a  DotNet/libs/iphone/Release-iphoneos/libUrho3D-Metal.a 
xcodebuild -project  build-ios-dotnet-metal-lib/Urho3D.xcodeproj -target Urho3D -configuration Debug
cp -Lf build-ios-dotnet-metal-lib/lib/libUrho3D.a  DotNet/libs/iphone/Debug-iphoneos/libUrho3D-Metal.a 