call script/cmake_vs2019_dotnet_dll.bat build-vs2019-dotnet-debug-dll
cmake --build build-vs2019-dotnet-debug-dll/.  --config Debug
xcopy   build-vs2019-dotnet-debug-dll\bin\Urho3D_d.dll  DotNet\libs\windows\Debug /y