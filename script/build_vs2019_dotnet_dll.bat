call script/cmake_vs2019_dotnet_dll.bat build-vs2019-dotnet-dll

REM Detect host architecture (.NET naming convention)
set HOST_ARCH=X64
if "%PROCESSOR_ARCHITECTURE%"=="AMD64" set HOST_ARCH=X64
if "%PROCESSOR_ARCHITECTURE%"=="ARM64" set HOST_ARCH=Arm64
if "%PROCESSOR_ARCHITECTURE%"=="x86" set HOST_ARCH=X86

echo Building for Windows %HOST_ARCH%...

echo Building Release configuration...
cmake --build build-vs2019-dotnet-dll/.  --config Release
if not exist DotNet\libs\windows\%HOST_ARCH%\Release mkdir DotNet\libs\windows\%HOST_ARCH%\Release
xcopy build-vs2019-dotnet-dll\bin\Urho3D.dll DotNet\libs\windows\%HOST_ARCH%\Release\ /y
echo   OK Windows Release: DotNet\libs\windows\%HOST_ARCH%\Release\Urho3D.dll

echo Building Debug configuration...
cmake --build build-vs2019-dotnet-dll/.  --config Debug
if not exist DotNet\libs\windows\%HOST_ARCH%\Debug mkdir DotNet\libs\windows\%HOST_ARCH%\Debug
xcopy build-vs2019-dotnet-dll\bin\Urho3D_d.dll DotNet\libs\windows\%HOST_ARCH%\Debug\ /y
if exist DotNet\libs\windows\%HOST_ARCH%\Debug\Urho3D_d.dll (
    ren DotNet\libs\windows\%HOST_ARCH%\Debug\Urho3D_d.dll Urho3D.dll
    echo   OK Windows Debug:   DotNet\libs\windows\%HOST_ARCH%\Debug\Urho3D.dll
) else (
    echo   ERROR: Failed to copy Debug DLL
    exit /b 1
)

echo.
echo Build complete:
echo   OK Windows Release: DotNet\libs\windows\%HOST_ARCH%\Release\Urho3D.dll
echo   OK Windows Debug:   DotNet\libs\windows\%HOST_ARCH%\Debug\Urho3D.dll