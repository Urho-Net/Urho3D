echo "Building Android libraries..."

# Android uses RelWithDebInfo configuration which includes debug symbols
# Full Debug configuration is not supported in Android NDK builds
echo "  → Building Release (RelWithDebInfo) configuration..."
./gradlew assembleRelease  -P URHO3D_DOTNET=1 -P URHO3D_DATABASE_SQLITE=1 -P URHO3D_ANGELSCRIPT=0 -P URHO3D_LUA=0  -P URHO3D_LIB_TYPE=SHARED  -P URHO3D_SAMPLES=0 -P URHO3D_PCH=0

mkdir -p DotNet/libs/android/Release/armeabi-v7a
mkdir -p DotNet/libs/android/Release/x86
mkdir -p DotNet/libs/android/Release/arm64-v8a
mkdir -p DotNet/libs/android/Release/x86_64

cp android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/armeabi-v7a/libUrho3D.so   DotNet/libs/android/Release/armeabi-v7a
cp android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/x86/libUrho3D.so   DotNet/libs/android/Release/x86
cp android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/arm64-v8a/libUrho3D.so     DotNet/libs/android/Release/arm64-v8a
cp android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/x86_64/libUrho3D.so    DotNet/libs/android/Release/x86_64

cp -f android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/armeabi-v7a/libUrhoMain.so    DotNet/libs/android/Release/armeabi-v7a
# cp -f android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/x86/libUrhoMain.so    DotNet/libs/android/Release/x86
cp -f android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/arm64-v8a/libUrhoMain.so     DotNet/libs/android/Release/arm64-v8a
cp -f android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/x86_64/libUrhoMain.so   DotNet/libs/android/Release/x86_64

echo "  ✓ Android Release libraries copied"

echo ""
echo "Build complete:"
echo "  ✓ Android Release (RelWithDebInfo): armeabi-v7a, x86, arm64-v8a, x86_64"
echo ""
echo "Note: Android uses RelWithDebInfo which includes debug symbols."
echo "      Separate Debug builds are not supported for Android NDK."