
CWD=$(pwd)
unamestr=$(uname)
# Switch-on alias expansion within the script 
shopt -s expand_aliases

#Alias the sed in-place command for OSX and Linux - incompatibilities between BSD and Linux sed args
if [[ "$unamestr" == "Darwin" ]]; then
	alias aliassedinplace='sed -i ""'
else
	#For Linux, notice no space after the '-i' 
	alias aliassedinplace='sed -i""'
fi

mono tools/wasm_tools/wasm-tuner.exe --gen-pinvoke-table Urho3D Dotnet/UrhoDotNet/web/UrhoDotNet.dll > Source/Samples/MonoEmbed/web/urho-pinvoke-table.h

./script/build_web_mono_runtime.sh

# export EMSCRIPTEN_ROOT_PATH=${CWD}/runtime/emsdk/upstream/emscripten
# export EMSDK_PATH=${CWD}/runtime/emsdk
# export EMSCRIPTEN_VERSION=$(cat ${CWD}/runtime/src/mono/wasm/emscripten-version.txt)
# echo "EMSCRIPTEN_VERSION=${EMSCRIPTEN_VERSION}"
# ${EMSDK_PATH}/emsdk activate ${EMSCRIPTEN_VERSION}
# source "${EMSDK_PATH}/emsdk_env.sh"


./script/cmake_emscripten_dotnet_lib.sh build-emscripten-dotnet-dylib
cd build-emscripten-dotnet-dylib
aliassedinplace "s*,-Bstatic**g" "Source/Samples/MonoEmbed/CMakeFiles/MonoEmbedded.dir/link.txt"
aliassedinplace "s*,-Bdynamic**g" "Source/Samples/MonoEmbed/CMakeFiles/MonoEmbedded.dir/link.txt"
make -j4
cd ..

cp -f build-emscripten-dotnet-dylib/bin/MonoEmbedded.html DotNet/libs/wasm/index.html
cp -f build-emscripten-dotnet-dylib/bin/MonoEmbedded.js DotNet/libs/wasm/MonoEmbedded.js
cp -f build-emscripten-dotnet-dylib/bin/MonoEmbedded.wasm DotNet/libs/wasm/MonoEmbedded.wasm