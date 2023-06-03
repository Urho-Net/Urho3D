# Install Mono
$installPath = "$env:TEMP\MonoInstaller.exe"
$downloadUrl = "https://download.mono-project.com/archive/6.12.0/windows-installer/mono-6.12.0.182-x64-0.msi"
Invoke-WebRequest -Uri $downloadUrl -OutFile $installPath
Start-Process -FilePath $installPath -ArgumentList "/quiet" -Wait

# Configure Mono Environment
$monoPath = (Get-Command mono).Source
$env:PATH += ";$monoPath"
$env:FrameworkPathOverride = "$monoPath\lib\mono\4.5"

# Display Installation Directory
Write-Host "Mono installed at: $monoPath"
