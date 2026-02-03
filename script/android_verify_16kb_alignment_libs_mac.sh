
LLVM_OBJDUMP=/Users/elialoni/Library/Android/sdk/ndk/29.0.14033849/toolchains/llvm/prebuilt/darwin-x86_64/bin/llvm-objdump
${LLVM_OBJDUMP} -p android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/armeabi-v7a/libUrho3D.so | grep LOAD
${LLVM_OBJDUMP} -p android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/x86/libUrho3D.so | grep LOAD
${LLVM_OBJDUMP} -p android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/arm64-v8a/libUrho3D.so | grep LOAD
${LLVM_OBJDUMP} -p android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/x86_64/libUrho3D.so | grep LOAD

${LLVM_OBJDUMP} -p android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/armeabi-v7a/libMonoEmbedded.so | grep LOAD
${LLVM_OBJDUMP} -p android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/x86/libMonoEmbedded.so | grep LOAD
${LLVM_OBJDUMP} -p android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/arm64-v8a/libMonoEmbedded.so | grep LOAD
${LLVM_OBJDUMP} -p android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/x86_64/libMonoEmbedded.so | grep LOAD

${LLVM_OBJDUMP} -p android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/armeabi-v7a/libUrhoMain.so | grep LOAD
${LLVM_OBJDUMP} -p android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/arm64-v8a/libUrhoMain.so | grep LOAD   
${LLVM_OBJDUMP} -p android/launcher-app/build/intermediates/stripped_native_libs/release/out/lib/x86_64/libUrhoMain.so | grep LOAD    

