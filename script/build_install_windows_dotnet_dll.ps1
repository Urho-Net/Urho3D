
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
Copy-Item   build-vs2019-dotnet-dll\bin\Urho3D.dll  -Destination  $URHONET_HOME_ROOT/template/libs/windows 

