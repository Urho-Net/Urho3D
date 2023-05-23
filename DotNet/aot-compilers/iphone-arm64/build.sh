#!/usr/bin/env bash
export MONO_PATH=../../bcl/monotouch
export XCODE=$(xcode-select --print-path)
export CLANG=${XCODE}/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang
export AR=${XCODE}/Toolchains/XcodeDefault.xctoolchain/usr/bin/ar
export LIPO=${XCODE}/Toolchains/XcodeDefault.xctoolchain/usr/bin/lipo
export IOS_SDK_PATH=${XCODE}/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk

./aarch64-apple-darwin-mono-sgen   --aot=asmonly,full,direct-icalls,direct-pinvoke,static,mtriple=arm64-ios,outfile=mscorlib.dll.s  -O=gsharedvt ${MONO_PATH}/mscorlib.dll
./aarch64-apple-darwin-mono-sgen   --aot=asmonly,full,direct-icalls,direct-pinvoke,static,mtriple=arm64-ios,outfile=System.Core.dll.s  -O=gsharedvt ${MONO_PATH}/System.Core.dll
./aarch64-apple-darwin-mono-sgen   --aot=asmonly,full,direct-icalls,direct-pinvoke,static,mtriple=arm64-ios,outfile=System.dll.s  -O=gsharedvt ${MONO_PATH}/System.dll
./aarch64-apple-darwin-mono-sgen   --aot=asmonly,full,direct-icalls,direct-pinvoke,static,mtriple=arm64-ios,outfile=System.Xml.dll.s  -O=gsharedvt ${MONO_PATH}/System.Xml.dll
./aarch64-apple-darwin-mono-sgen   --aot=asmonly,full,direct-icalls,direct-pinvoke,static,mtriple=arm64-ios,outfile=Mono.Security.s  -O=gsharedvt ${MONO_PATH}/Mono.Security.dll
./aarch64-apple-darwin-mono-sgen   --aot=asmonly,full,direct-icalls,direct-pinvoke,static,mtriple=arm64-ios,outfile=System.Numerics.dll.s  -O=gsharedvt ${MONO_PATH}/System.Numerics.dll



for i in ./*.dll; do ./aarch64-apple-darwin-mono-sgen   --aot=asmonly,full,direct-icalls,direct-pinvoke,static,mtriple=arm64-ios,outfile=$i.s  -O=gsharedvt  $i; done

for i in ./*.s; do ${CLANG} -isysroot ${IOS_SDK_PATH} -Qunused-arguments -miphoneos-version-min=10.0  -arch arm64 -c -o $i.o -x assembler $i ; done

rm lib-urho3d-mono-aot.a 
 
${AR} cr lib-urho3d-mono-aot.a  *.o

rm *.s
rm *.o