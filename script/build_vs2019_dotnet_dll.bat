call script/cmake_vs2019_dotnet_dll.bat build-vs2019-dotnet-dll
cmake --build build-vs2019-dotnet-dll/.  --config Release
xcopy   build-vs2019-dotnet-dll\bin\Urho3D.dll  DotNet\libs\windows\Release /y