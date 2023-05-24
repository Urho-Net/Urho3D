script_path=$(readlink -f "$0")
scriptDir=$(dirname "$script_path")
URHO3D_HOME=${scriptDir}/../

configureFile=${scriptDir}/../../configure.sh
if [ -e "$configureFile" ]; then
    cd ${scriptDir}/../../
    echo "configure.sh found , calling it !"
    ./configure.sh
fi

URHONET_HOME_ROOT=$(cat ~/.urhonet_config/urhonethome)
URHO3D_HOME=${scriptDir}/../


if [ ! -d "$URHONET_HOME_ROOT" ]; then
    echo  "Urho.Net is not configured , please  run configure.sh (configure.bat on Windows) from the Urho.Net installation folder  "
    exit -1
else
    echo "URHONET_HOME_ROOT=${URHONET_HOME_ROOT}"
fi

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

cd ${URHO3D_HOME}

./script/make_csharp_editor_bindings.sh
exit_status=$?
if [ $exit_status -ne 0 ]; then
echo "An error occurred while executing make_csharp_editor_bindings.sh Exiting."
exit 1 
fi
./script/build_xcode_dotnet_editor_dylib.sh 
exit_status=$?
if [ $exit_status -ne 0 ]; then
echo "An error occurred while executing build_xcode_dotnet_editor_dylib.sh  Exiting."
exit 1 
fi

mkdir -p ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/desktop
cp -f ${URHO3D_HOME}/DotNet/UrhoDotNet/editor/UrhoDotNet.dll ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/desktop
cp -f ${URHO3D_HOME}/DotNet/UrhoDotNet/editor/UrhoDotNet.xml ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/desktop

mkdir -p ${URHONET_HOME_ROOT}/template/libs/macos
cp -f ${URHO3D_HOME}/DotNet/libs/macos/Release/libUrho3D.dylib  ${URHONET_HOME_ROOT}/template/libs/macos
