set SDK=%ANDROID_HOME%
set CMAKE=%SDK%/cmake/3.10.2.4988404/bin/cmake.exe
set CMAKE_MAKE_PROGRAM=%SDK%/cmake/3.10.2.4988404/bin/ninja.exe
set ANDROID_NDK=%SDK%/ndk/21.0.6113669
set CMAKE_TOOLCHAIN_FILE=%ANDROID_NDK%/build/cmake/android.toolchain.cmake
set CXX=%ANDROID_NDK%/toolchains/llvm/prebuilt/windows-x86_64/bin/clang++.exe
set CC=%ANDROID_NDK%/toolchains/llvm/prebuilt/windows-x86_64/bin/clang.exe


%CMAKE% -GNinja -DURHO3D_LUA=0 -DURHO3D_WEBP=0 -DURHO3D_SAMPLES=1 -DURHO3D_LIB_TYPE=SHARED -DANDROID_TOOLCHAIN_NAME=arm-linux-androideabi-4.9 -DANDROID_ABI=armeabi-v7a -DANDROID_PLATFORM=android-17 -DCMAKE_SYSTEM_NAME=Android -DCMAKE_ANDROID_ARCH_ABI=armeabi-v7a -DCMAKE_SYSTEM_VERSION=17 -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DANDROID_NDK=%SDK%/ndk/21.0.6113669 -DCMAKE_BUILD_TYPE=Debug -DCMAKE_MAKE_PROGRAM=%SDK%/cmake/3.10.2.4988404/bin/ninja.exe -DCMAKE_TOOLCHAIN_FILE=%ANDROID_NDK%/build/cmake/android.toolchain.cmake -DANDROID_NATIVE_API_LEVEL=23 -DANDROID_TOOLCHAIN=clang jvmArgs :  ..
