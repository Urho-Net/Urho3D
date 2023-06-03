# Set up environment variables
$env:ANDROID_SDK_ROOT = "$env:USERPROFILE\android-sdk"
$env:ANDROID_NDK_ROOT = "$env:USERPROFILE\android-ndk"

# Install Android SDK
Write-Host "Installing Android SDK..."
Invoke-WebRequest -Uri "https://dl.google.com/android/repository/commandlinetools-win-7583922_latest.zip" -OutFile "commandlinetools.zip"
Expand-Archive -Path "commandlinetools.zip" -DestinationPath $env:ANDROID_SDK_ROOT
Remove-Item "commandlinetools.zip"

# Install Java JDK
Write-Host "Installing Java JDK..."
choco install -y openjdk8 --version=8.0.302.8

# Install Android NDK
Write-Host "Installing Android NDK..."
Invoke-WebRequest -Uri "https://dl.google.com/android/repository/android-ndk-r21e-windows-x86_64.zip" -OutFile "android-ndk.zip"
Expand-Archive -Path "android-ndk.zip" -DestinationPath $env:USERPROFILE
Remove-Item "android-ndk.zip"

# Configure environment variables
Write-Host "Configuring environment variables..."
$env:Path += ";$env:ANDROID_SDK_ROOT\cmdline-tools\latest\bin;$env:ANDROID_SDK_ROOT\platform-tools"
$env:JAVA_HOME = "C:\Program Files\OpenJDK\jdk1.8.0_302"
$env:ANDROID_NDK_HOME = "$env:USERPROFILE\android-ndk-r21e"

# Accept Android SDK licenses
Write-Host "Accepting Android SDK licenses..."
& "$env:ANDROID_SDK_ROOT\cmdline-tools\latest\bin\sdkmanager.bat" --licenses --sdk_root="$env:ANDROID_SDK_ROOT"

# Install required Android packages
Write-Host "Installing Android packages..."
& "$env:ANDROID_SDK_ROOT\cmdline-tools\latest\bin\sdkmanager.bat" "platform-tools" "build-tools;30.0.3" "platforms;android-30" --sdk_root="$env:ANDROID_SDK_ROOT"

# Display installed versions
Write-Host "Installed versions:"
java -version
$env:ANDROID_SDK_ROOT\cmdline-tools\latest\bin\sdkmanager.bat --version
$env:ANDROID_NDK_HOME\ndk-build.cmd --version
