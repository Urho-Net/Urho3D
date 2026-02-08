call script/cmake_vs2019_dotnet_dll.bat build-vs2019-dotnet-dll

echo Building Release configuration...
cmake --build build-vs2019-dotnet-dll/.  --config Release
if not exist DotNet\libs\windows\Release mkdir DotNet\libs\windows\Release
xcopy build-vs2019-dotnet-dll\bin\Release\Urho3D.dll DotNet\libs\windows\Release\ /y
echo   OK Windows Release: DotNet\libs\windows\Release\Urho3D.dll

echo Building Debug configuration...
cmake --build build-vs2019-dotnet-dll/.  --config Debug
if not exist DotNet\libs\windows\Debug mkdir DotNet\libs\windows\Debug
xcopy build-vs2019-dotnet-dll\bin\Debug\Urho3D.dll DotNet\libs\windows\Debug\ /y
echo   OK Windows Debug:   DotNet\libs\windows\Debug\Urho3D.dll

echo.
echo Build complete:
echo   OK Windows Release: DotNet\libs\windows\Release\Urho3D.dll
echo   OK Windows Debug:   DotNet\libs\windows\Debug\Urho3D.dll