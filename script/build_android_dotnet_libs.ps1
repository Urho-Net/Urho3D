# Run Gradle command
$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$URHO3D_HOME=$scriptDir+"/../"
cd $URHO3D_HOME
& ".\gradlew" "assembleRelease" "-P" "URHO3D_DOTNET=1" "-P" "URHO3D_DATABASE_SQLITE=1" "-P" "URHO3D_ANGELSCRIPT=0" "-P" "URHO3D_LUA=0" "-P" "URHO3D_LIB_TYPE=SHARED" "-P" "URHO3D_SAMPLES=0"

# Create directories
mkdir "DotNet\libs\android\net6.0-Release\armeabi-v7a" -Force
mkdir "DotNet\libs\android\net6.0-Release\x86" -Force
mkdir "DotNet\libs\android\net6.0-Release\arm64-v8a" -Force
mkdir "DotNet\libs\android\net6.0-Release\x86_64" -Force

# Copy libraries
Copy-Item "android\launcher-app\build\intermediates\stripped_native_libs\release\out\lib\armeabi-v7a\libUrho3D.so" "DotNet\libs\android\net6.0-Release\armeabi-v7a" -Force
Copy-Item "android\launcher-app\build\intermediates\stripped_native_libs\release\out\lib\x86\libUrho3D.so" "DotNet\libs\android\net6.0-Release\x86" -Force
Copy-Item "android\launcher-app\build\intermediates\stripped_native_libs\release\out\lib\arm64-v8a\libUrho3D.so" "DotNet\libs\android\net6.0-Release\arm64-v8a" -Force
Copy-Item "android\launcher-app\build\intermediates\stripped_native_libs\release\out\lib\x86_64\libUrho3D.so" "DotNet\libs\android\net6.0-Release\x86_64" -Force

Copy-Item "android\launcher-app\build\intermediates\stripped_native_libs\release\out\lib\armeabi-v7a\libMonoEmbedded.so" "DotNet\libs\android\net6.0-Release\armeabi-v7a" -Force
Copy-Item "android\launcher-app\build\intermediates\stripped_native_libs\release\out\lib\x86\libMonoEmbedded.so" "DotNet\libs\android\net6.0-Release\x86" -Force
Copy-Item "android\launcher-app\build\intermediates\stripped_native_libs\release\out\lib\arm64-v8a\libMonoEmbedded.so" "DotNet\libs\android\net6.0-Release\arm64-v8a" -Force
Copy-Item "android\launcher-app\build\intermediates\stripped_native_libs\release\out\lib\x86_64\libMonoEmbedded.so" "DotNet\libs\android\net6.0-Release\x86_64" -Force
