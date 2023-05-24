$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$URHO3D_HOME="$scriptDir/../"
$URHONET_HOME_ROOT = Get-Content "$env:USERPROFILE\.urhonet_config\urhonethome"

$configureFile = $scriptDir+"/../../configure.bat"
if (Test-Path -Path $configureFile -PathType Leaf) {
    Write-Host "found configure.bat , calling it!"
    & $configureFile
}

if (-not (Test-Path $URHONET_HOME_ROOT)) {
    Write-Host "Urho.Net is not configured, please run configure.bat from the Urho.Net installation folder"
    exit -1
}
else {
    Write-Host "URHONET_HOME_ROOT=$URHONET_HOME_ROOT"
}

& "$scriptDir\build_android_dotnet_libs.ps1"
# Check the exit code
if ($LASTEXITCODE -ne 0) {
    Write-Output "An error occurred in the called build_android_dotnet_libs.ps1 script. Stopping execution."
    exit -1
}

# build UrhoDotNet.dll assembly for all supported platforms
Set-Location "$URHO3D_HOME\DotNet\Bindings"
& ".\build-android-bindings.ps1"
# Check the exit code
if ($LASTEXITCODE -ne 0) {
    Write-Output "An error occurred in the called build-android-bindings.ps1 script. Stopping execution."
    exit -1
}

# build Mono.Android.dll assembly for all supported platforms
Set-Location "$URHO3D_HOME\DotNet\AndroidEnvironment"
& ".\build-android-runtime-environment.ps1"

# Check the exit code
if ($LASTEXITCODE -ne 0) {
    Write-Output "An error occurred in the called build-android-runtime-environment.ps script. Stopping execution."
    exit -1
}

Set-Location $URHO3D_HOME


New-Item -ItemType Directory -Force "$URHO3D_HOME\bin\Data\DotNet\android" | Out-Null


Copy-Item -Force "$URHO3D_HOME\DotNet\UrhoDotNet\mobile\android\UrhoDotNet.dll" "$URHO3D_HOME\bin\Data\DotNet\android"
Copy-Item -Force "$URHO3D_HOME\DotNet\UrhoDotNet\mobile\android\Mono.Android.dll" "$URHO3D_HOME\bin\Data\DotNet\android"
Copy-Item -Force "$URHO3D_HOME\DotNet\UrhoDotNet\mobile\android\UrhoDotNet.dll" "$URHONET_HOME_ROOT\template\libs\dotnet\urho\mobile\android"
Copy-Item -Force "$URHO3D_HOME\DotNet\UrhoDotNet\mobile\android\Mono.Android.dll" "$URHONET_HOME_ROOT\template\libs\dotnet\urho\mobile\android"

Copy-Item -Force "$URHO3D_HOME\DotNet\libs\android\net6.0-Release\arm64-v8a\libUrho3D.so" "$URHONET_HOME_ROOT\template\libs\android\arm64-v8a"
Copy-Item -Force "$URHO3D_HOME\DotNet\libs\android\net6.0-Release\armeabi-v7a\libUrho3D.so" "$URHONET_HOME_ROOT\template\libs\android\armeabi-v7a"
Copy-Item -Force "$URHO3D_HOME\DotNet\libs\android\net6.0-Release\x86\libUrho3D.so" "$URHONET_HOME_ROOT\template\libs\android\x86"
Copy-Item -Force "$URHO3D_HOME\DotNet\libs\android\net6.0-Release\x86_64\libUrho3D.so" "$URHONET_HOME_ROOT\template\libs\android\x86_64"

Copy-Item -Force "$URHO3D_HOME\DotNet\libs\android\net6.0-Release\arm64-v8a\libMonoEmbedded.so" "$URHONET_HOME_ROOT\template\libs\android\arm64-v8a"
Copy-Item -Force "$URHO3D_HOME\DotNet\libs\android\net6.0-Release\armeabi-v7a\libMonoEmbedded.so" "$URHONET_HOME_ROOT\template\libs\android\armeabi-v7a"
Copy-Item -Force  "$URHO3D_HOME\DotNet\libs\android\net6.0-Release\x86\libMonoEmbedded.so"     "$URHONET_HOME_ROOT\template\libs\android\x86"
Copy-Item -Force  "$URHO3D_HOME\DotNet\libs\android\net6.0-Release\x86_64\libMonoEmbedded.so"    "$URHONET_HOME_ROOT\template\libs\android\x86_64"

Copy-Item -Force  "$URHO3D_HOME\android\urho3d-lib\build\intermediates\aar_main_jar\release\classes.jar"  "$URHONET_HOME_ROOT\template\Android\classes"
