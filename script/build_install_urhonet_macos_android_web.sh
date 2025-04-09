unamestr=$(uname)

if [[ "$unamestr" == "Darwin" ]]; then
    function readlink(){
    DIR="${1%/*}"
    (cd "$DIR" && echo "$(pwd -P)")
    }

    script_path=$(readlink  "$0")
    scriptDir=$(dirname "$script_path")
 
    configureFile=${scriptDir}/../configure.sh
    if [ -e "$configureFile" ]; then
        cd ${scriptDir}/../
        echo "configure.sh found , calling it !"
        ./configure.sh
    fi
    URHO3D_HOME=${scriptDir}
else
	script_path=$(readlink -f "$0")
    scriptDir=$(dirname "$script_path")


    configureFile=${scriptDir}/../../configure.sh
    if [ -e "$configureFile" ]; then
        cd ${scriptDir}/../../
        echo "configure.sh found , calling it !"
        ./configure.sh
    fi
    URHO3D_HOME=${scriptDir}/../
fi
cd ${URHO3D_HOME}

./script/build_install_urhonet_macos.sh
./script/build_install_urhonet_android_libs.sh   
./script/build_install_urhonet_emscripten_libs.sh