
./script/cmake_ios_dotnet_lib_metal_shared.sh build-ios-dotnet-lib-metal-shared

xcodebuild -project  build-ios-dotnet-lib-metal-shared/Urho3D.xcodeproj -target Urho3D -configuration Release
mkdir -p DotNet/libs/iphone/Release-iphoneos/
cp -rf build-ios-dotnet-lib-metal-shared/lib/Urho3D.framework DotNet/libs/iphone/Release-iphoneos/
cp -f ./script/Info.plist DotNet/libs/iphone/Release-iphoneos/Urho3D.framework

xcodebuild -project  build-ios-dotnet-lib-metal-shared/Urho3D.xcodeproj -target Urho3D -configuration Debug
mkdir -p DotNet/libs/iphone/Debug-iphoneos/
cp -rf build-ios-dotnet-lib-metal-shared/lib/Urho3D.framework DotNet/libs/iphone/Debug-iphoneos/
cp -f ./script/Info.plist DotNet/libs/iphone/Debug-iphoneos/Urho3D.framework
