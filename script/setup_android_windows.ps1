# Set up environment variables
$env:ANDROID_SDK_ROOT = "$env:USERPROFILE\android-sdk"
$env:ANDROID_NDK_ROOT = "$env:USERPROFILE\android-ndk"

mkdir "$env:ANDROID_SDK_ROOT\cmdline-tools"

# Install Android SDK
Write-Host "Installing Android SDK..."
Invoke-WebRequest -Uri "https://dl.google.com/android/repository/commandlinetools-win-7583922_latest.zip" -OutFile "commandlinetools.zip"
Expand-Archive -Path "commandlinetools.zip" -DestinationPath "$env:ANDROID_SDK_ROOT\cmdline-tools"
Remove-Item "commandlinetools.zip"
Move-Item "$env:ANDROID_SDK_ROOT\cmdline-tools\cmdline-tools" "$env:ANDROID_SDK_ROOT\cmdline-tools\tools"

# Install Java JDK
Write-Host "Installing Java JDK..."
choco install -y openjdk8 --version=8.0.302.8

# Install Android NDK
Write-Host "Installing Android NDK..."
Invoke-WebRequest -Uri "https://dl.google.com/android/repository/android-ndk-r21e-windows-x86_64.zip" -OutFile "android-ndk.zip"
Expand-Archive -Path "android-ndk.zip" -DestinationPath "$env:USERPROFILE\android-ndk"
Remove-Item "android-ndk.zip"

# Configure environment variables
Write-Host "Configuring environment variables..."
$env:Path += ";$env:ANDROID_SDK_ROOT\cmdline-tools\tools\bin;$env:ANDROID_SDK_ROOT\platform-tools"
$env:JAVA_HOME = "C:\Program Files\AdoptOpenJDK\jdk-8.0.302.8-hotspot"
$env:ANDROID_NDK_HOME = "$env:ANDROID_NDK_ROOT\android-ndk-r21e"

# Accept Android SDK licenses
# Write-Host "y" | $env:ANDROID_SDK_ROOT\cmdline-tools\tools\bin\sdkmanager --licenses
Set-Content -Path "$env:ANDROID_SDK_ROOT\cmdline-tools\tools\bin\accept_licenses.bat" -Value "echo y | %~dp0sdkmanager --licenses"
Start-Process -FilePath "$env:ANDROID_SDK_ROOT\cmdline-tools\tools\bin\accept_licenses.bat"



# Install required Android packages
Write-Host "Installing Android packages..."
$env:ANDROID_SDK_ROOT\cmdline-tools\tools\bin\sdkmanager "platform-tools" "build-tools;30.0.3" "platforms;android-30"

# Display installed versions
Write-Host "Installed versions:"
java -version
javac -version
$env:ANDROID_SDK_ROOT\cmdline-tools\tools\bin\sdkmanager --version
$env:ANDROID_NDK_HOME\ndk-build --version
