
export SDK_VER=16.2
export MIN_IOS_VER=12.4
export TARGET=iPhoneOS
mkdir -p Xamarin/libs/iphone/Release-iphoneos
mkdir -p Xamarin/libs/iphone/Debug-iphoneos
./script/cmake_ios_xamarin_lib.sh build-ios-xamarin-lib
xcodebuild -project  build-ios-xamarin-lib/Urho3D.xcodeproj -target Urho3D -configuration Release
cp -Lf build-ios-xamarin-lib/lib/libUrho3D.a  Xamarin/libs/iphone/Release-iphoneos/libUrho3D-GLES.a 
xcodebuild -project  build-ios-xamarin-lib/Urho3D.xcodeproj -target Urho3D -configuration Debug
cp -Lf build-ios-xamarin-lib/lib/libUrho3D.a  Xamarin/libs/iphone/Debug-iphoneos/libUrho3D-GLES.a 

./script/cmake_ios_xamarin_metal_lib.sh build-ios-xamarin-metal-lib
xcodebuild -project  build-ios-xamarin-metal-lib/Urho3D.xcodeproj -target Urho3D -configuration Release
cp -Lf build-ios-xamarin-metal-lib/lib/libUrho3D.a  Xamarin/libs/iphone/Release-iphoneos/libUrho3D-Metal.a 
xcodebuild -project  build-ios-xamarin-metal-lib/Urho3D.xcodeproj -target Urho3D -configuration Debug
cp -Lf build-ios-xamarin-metal-lib/lib/libUrho3D.a  Xamarin/libs/iphone/Debug-iphoneos/libUrho3D-Metal.a 
