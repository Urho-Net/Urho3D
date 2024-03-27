./gradlew assembleRelease -P URHO3D_DOTNET=1 -P URHO3D_XAMARIN=1 -P URHO3D_DATABASE_SQLITE=1 -P URHO3D_ANGELSCRIPT=0 -P URHO3D_LUA=0  -P URHO3D_LIB_TYPE=SHARED  -P URHO3D_SAMPLES=0

mkdir -p Xamarin/libs/android/libs
mkdir -p Xamarin/libs/android/libs/armeabi-v7a
cp android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/armeabi-v7a/libUrho3D.so   Xamarin/libs/android/libs/armeabi-v7a
mkdir -p Xamarin/libs/android/libs/x86
cp android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/x86/libUrho3D.so   Xamarin/libs/android/libs/x86
mkdir -p Xamarin/libs/android/libs/arm64-v8a
cp android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/arm64-v8a/libUrho3D.so     Xamarin/libs/android/libs/arm64-v8a
mkdir -p  Xamarin/libs/android/libs/x86_64
cp android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/x86_64/libUrho3D.so    Xamarin/libs/android/libs/x86_64
