script_path=$(readlink -f "$0")
scriptDir=$(dirname "$script_path")
URHO3D_HOME=${scriptDir}/..

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

cd ${URHO3D_HOME}


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

./script/build_install_linux_dotnet_so.sh

cd ${URHO3D_HOME}/DotNet/Bindings
./build-desktop-bindings.sh
cd ${URHO3D_HOME}

# Check if the file doesn't exist
if [ ! -e ${URHO3D_HOME}/DotNet/UrhoDotNet/desktop/UrhoDotNet.dll ]; then
  echo "UrhoDotNet.dll does not exist. Exiting with an error."
  exit 1
fi

# copy the dotnet assembly to the Urho.Net folder
cp   ${URHO3D_HOME}/DotNet/UrhoDotNet/desktop/UrhoDotNet.dll  ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/desktop
cp   ${URHO3D_HOME}/DotNet/UrhoDotNet/desktop/UrhoDotNet.xml   ${URHONET_HOME_ROOT}/template/libs/dotnet/urho/desktop