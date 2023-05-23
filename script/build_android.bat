@ECHO off
cls
:start
ECHO. Choose build type
ECHO 1. Debug
ECHO 2. Release
set choice=
set buildType=
set /p choice=Build Type=
if not '%choice%'=='' set choice=%choice:~0,1%
if '%choice%'=='1' goto debug
if '%choice%'=='2' goto release
ECHO "%choice%" is not valid, try again
ECHO.
goto start
:debug
ECHO  picked Debug
set buildType=Debug
goto startGradlew
:release
ECHO  picked Release
set buildType=Release
goto startGradlew

pause


:startGradlew
rmdir android\launcher-app\src\main\assets /Q/S
xcopy /E bin android\launcher-app\src\main\assets\
gradlew assemble%buildType% -P URHO3D_DOTNET=1 -P URHO3D_ANGELSCRIPT=0 -P URHO3D_LUA=0  -P URHO3D_LIB_TYPE=SHARED 

cls
:end