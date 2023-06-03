# Install Mono
$installPath = "$env:TEMP\MonoInstaller.exe"
$downloadUrl = "https://download.mono-project.com/archive/6.12.0/windows-installer/mono-6.12.0.182-x64-0.msi"
Invoke-WebRequest -Uri $downloadUrl -OutFile $installPath
Start-Process -FilePath "msiexec.exe" -ArgumentList "/i", $installPath, "/quiet" -Wait

$monoPath = "C:\Program Files\Mono"
# Check if Mono directory exists
if (Test-Path $monoPath) {
    Write-Host "Mono is installed in $monoPath"
} else {
    Write-Host "Mono is not installed in $monoPath"
    Exit 1  # Exit the script with an error code
}

# Configure Mono Environment
$env:PATH += ";$monoPath\bin"
$env:FrameworkPathOverride = "$monoPath\lib\mono\4.5"

$env:PATH
Get-ChildItem -Path "$monoPath\bin" -Recurse

# Display Installation Directory
Write-Host "Mono installed at: $monoPath"
