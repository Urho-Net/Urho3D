call script/cmake_vs2019_dotnet_editor_dll.bat build-vs2019-dotnet-editor-dll

echo Building Release configuration...
cmake --build build-vs2019-dotnet-editor-dll/.  --config Release
if not exist DotNet\libs\editor\windows\Release mkdir DotNet\libs\editor\windows\Release
xcopy build-vs2019-dotnet-editor-dll\bin\Urho3D.dll DotNet\libs\editor\windows\Release\ /y
echo   OK Windows Release: DotNet\libs\editor\windows\Release\Urho3D.dll

echo Building Debug configuration...
cmake --build build-vs2019-dotnet-editor-dll/.  --config Debug
if not exist DotNet\libs\editor\windows\Debug mkdir DotNet\libs\editor\windows\Debug
xcopy build-vs2019-dotnet-editor-dll\bin\Urho3D_d.dll DotNet\libs\editor\windows\Debug\ /y
if exist DotNet\libs\editor\windows\Debug\Urho3D_d.dll (
    ren DotNet\libs\editor\windows\Debug\Urho3D_d.dll Urho3D.dll
    echo   OK Windows Debug:   DotNet\libs\editor\windows\Debug\Urho3D.dll
) else (
    echo   ERROR: Failed to copy Debug DLL
    exit /b 1
)

echo.
echo Build complete:
echo   OK Windows Release: DotNet\libs\editor\windows\Release\Urho3D.dll
echo   OK Windows Debug:   DotNet\libs\editor\windows\Debug\Urho3D.dll