
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

script/cmake_vs2019_dotnet_dll.bat build-vs2019-dotnet-dll
cmake --build build-vs2019-dotnet-dll/.  --config Release
# Check if the file doesn't exist
if (-not (Test-Path -Path build-vs2019-dotnet-dll\bin\Urho3D.dll)) {
  Write-Host "Urho3D.dll does not exist. Exiting with an error."
  exit 1
}
Copy-Item   build-vs2019-dotnet-dll\bin\Urho3D.dll  -Destination  $URHONET_HOME_ROOT/template/libs/windows 

