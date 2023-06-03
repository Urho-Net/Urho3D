URHONET_HOME_ROOT=$(cat ~/.urhonet_config/urhonethome)
URHO3D_HOME=$(pwd)

if [ ! -d "$URHONET_HOME_ROOT" ]; then
    echo  "Urho.Net is not configured , please  run configure.sh (configure.bat on Windows) from the Urho.Net installation folder  "
    exit -1
else
    echo "URHONET_HOME_ROOT=${URHONET_HOME_ROOT}"
fi

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


./script/cmake_linux_dotnet_so.sh build-dotnet-lib
cd build-dotnet-lib/
make -j4 

# Check if the file doesn't exist
if [ ! -e lib/libUrho3D.so ]; then
  echo "libUrho3D.so does not exist. Exiting with an error."
  exit 1
fi

cp -L lib/libUrho3D.so  ${URHONET_HOME_ROOT}/template/libs/linux