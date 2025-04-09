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


URHONET_HOME_ROOT=$(cat ~/.urhonet_config/urhonethome)


if [ ! -d "$URHONET_HOME_ROOT" ]; then
    echo  "Urho.Net is not configured , please  run configure.sh (configure.bat on Windows) from the Urho.Net installation folder  "
    exit -1
else
    echo "URHONET_HOME_ROOT=${URHONET_HOME_ROOT}"
fi

cd ${URHO3D_HOME}
./script/cmake_emscripten_dotnet_editor_lib.sh build-emscripten-dotnet-editor-libs
cd build-emscripten-dotnet-editor-libs
make -j4
exit_status=$?
if [ $exit_status -ne 0 ]; then
    echo "An error occurred while executing build-emscripten-dotnet-editor-libs.sh Exiting."
    exit 1 
fi

# build UrhoDotNet.dll  assembly for web
cd ${URHO3D_HOME}/DotNet/Bindings
./build-web-editor-bindings.sh
if [ $exit_status -ne 0 ]; then
    echo "An error occurred while executing build-web-bindings.sh Exiting."
    exit 1 
fi

cd ${URHO3D_HOME}

cp -f ${URHO3D_HOME}/DotNet/UrhoDotNet/web/UrhoDotNet.dll  ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/web
cp -f ${URHO3D_HOME}/build-emscripten-dotnet-editor-libs/lib/libUrho3D.a ${URHONET_HOME_ROOT}/template/libs/web/Urho3D.a