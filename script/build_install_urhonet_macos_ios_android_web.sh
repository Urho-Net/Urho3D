script_path=$(readlink -f "$0")
scriptDir=$(dirname "$script_path")
URHO3D_HOME=${scriptDir}/../
cd ${URHO3D_HOME}

./script/make_csharp_bindings.sh
./script/build_install_urhonet_web_mono_runtime.sh
./script/build_emscripten_dotnet_dylib.sh
./script/build_xcode_dotnet_metal_dylib.sh 
./script/build_ios_dotnet_libs.sh
./script/build_android_dotnet_libs.sh
./script/copy_urhonet_libs.sh