$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$URHO3D_HOME=$scriptDir+"/../"

$configureFile = $scriptDir+"/../../configure.bat"
if (Test-Path -Path $configureFile -PathType Leaf) {
    Write-Host "found configure.bat , calling it!"
    & $configureFile
}


$URHONET_HOME_ROOT = cat $HOME/.urhonet_config/urhonethome
if (Test-Path -Path $URHONET_HOME_ROOT) 
{
    echo $URHONET_HOME_ROOT
}
else
{
    echo  "Urho.Net is not configured , please  run configure.sh (configure.bat on Windows) from the Urho.Net installation folder  "
    exit -1
}

cd $URHO3D_HOME

# building the Native part an copy it to the Urho.Net folder
script/cmake_vs2019_dotnet_editor_dll.bat build-vs2019-dotnet-editor-dll
cmake --build build-vs2019-dotnet-editor-dll/.  --config Release
Copy-Item   build-vs2019-dotnet-editor-dll\bin\Urho3D.dll  -Destination  $URHONET_HOME_ROOT/template/libs/windows 

# compiling the dotnet assembly
cd $URHO3D_HOME/DotNet/Bindings
./build-editor-bindings.bat
cd $URHO3D_HOME

# copy the dotnet assembly to the Urho.Net folder
Copy-Item   $URHO3D_HOME/DotNet/UrhoDotNet/editor/UrhoDotNet.dll -Destination  $URHONET_HOME_ROOT/template/libs/dotnet/urho/desktop
Copy-Item   $URHO3D_HOME/DotNet/UrhoDotNet/editor/UrhoDotNet.xml -Destination  $URHONET_HOME_ROOT/template/libs/dotnet/urho/desktop

