./gradlew assembleRelease -P URHO3D_DOTNET=1 -P URHO3D_DATABASE_SQLITE=1 -P URHO3D_ANGELSCRIPT=0 -P URHO3D_LUA=0  -P URHO3D_LIB_TYPE=SHARED  -P URHO3D_SAMPLES=0

mkdir -p DotNet/libs/android/net8.0-Release/armeabi-v7a
mkdir -p DotNet/libs/android/net8.0-Release/x86
mkdir -p DotNet/libs/android/net8.0-Release/arm64-v8a
mkdir -p DotNet/libs/android/net8.0-Release/x86_64

cp android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/armeabi-v7a/libUrho3D.so   DotNet/libs/android/net8.0-Release/armeabi-v7a
cp android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/x86/libUrho3D.so   DotNet/libs/android/net8.0-Release/x86
cp android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/arm64-v8a/libUrho3D.so     DotNet/libs/android/net8.0-Release/arm64-v8a
cp android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/x86_64/libUrho3D.so    DotNet/libs/android/net8.0-Release/x86_64

cp android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/armeabi-v7a/libMonoEmbedded.so   DotNet/libs/android/net8.0-Release/armeabi-v7a
cp android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/x86/libMonoEmbedded.so   DotNet/libs/android/net8.0-Release/x86
cp android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/arm64-v8a/libMonoEmbedded.so     DotNet/libs/android/net8.0-Release/arm64-v8a
cp android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/x86_64/libMonoEmbedded.so    DotNet/libs/android/net8.0-Release/x86_64