# Set up environment variables
$env:ANDROID_HOME = "$env:USERPROFILE\android-sdk"
$env:JAVA_HOME = "C:\Program Files\Java\jdk1.8.0"

# Download and install Android SDK command-line tools
echo "Installing Android SDK..."
Invoke-WebRequest -Uri "https://dl.google.com/android/repository/commandlinetools-win-7583922_latest.zip" -OutFile "sdk-tools.zip"
Expand-Archive -Path "sdk-tools.zip" -DestinationPath $env:ANDROID_HOME
Remove-Item "sdk-tools.zip"

# Install Java JDK
echo "Installing Java JDK..."
choco install -y openjdk8 --version=8.0.302.8

# Download and install Android NDK
echo "Installing Android NDK..."
Invoke-WebRequest -Uri "https://dl.google.com/android/repository/android-ndk-r21e-windows-x86_64.zip" -OutFile "android-ndk.zip"
Expand-Archive -Path "android-ndk.zip" -DestinationPath $env:USERPROFILE
Remove-Item "android-ndk.zip"

# Configure environment variables
echo "Configuring environment variables..."
$env:Path += ";$env:ANDROID_HOME\cmdline-tools\latest\bin;$env:ANDROID_HOME\platform-tools"
$env:ANDROID_NDK_HOME = "$env:USERPROFILE\android-ndk-r21e"

# Accept Android SDK licenses
echo "Accepting Android SDK licenses..."
& "$env:ANDROID_HOME\cmdline-tools\latest\bin\sdkmanager.bat" --licenses --sdk_root="$env:ANDROID_HOME"

# Install required Android packages
echo "Installing Android packages..."
& "$env:ANDROID_HOME\cmdline-tools\latest\bin\sdkmanager.bat" "platform-tools" "build-tools;30.0.3" "platforms;android-30" --sdk_root="$env:ANDROID_HOME"

# Display installed versions
echo "Installed versions:"
java -version
& "$env:ANDROID_HOME\cmdline-tools\latest\bin\sdkmanager.bat" --version
& "$env:ANDROID_NDK_HOME\ndk-build.cmd" --version
