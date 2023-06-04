#!/bin/bash

# Set up environment variables
export ANDROID_SDK_ROOT=$HOME/android-sdk
export ANDROID_NDK_ROOT=$HOME/android-ndk

mkdir -p $ANDROID_SDK_ROOT/cmdline-tools


Install Android SDK
echo "Installing Android SDK..."
wget https://dl.google.com/android/repository/commandlinetools-mac-7583922_latest.zip
unzip commandlinetools-mac-7583922_latest.zip -d $ANDROID_SDK_ROOT/cmdline-tools
rm commandlinetools-mac-7583922_latest.zip
mv $ANDROID_SDK_ROOT/cmdline-tools/cmdline-tools $ANDROID_SDK_ROOT/cmdline-tools/tools

# Install Android NDK
echo "Installing Android NDK..."
mkdir -p $ANDROID_NDK_ROOT
wget https://dl.google.com/android/repository/android-ndk-r21e-darwin-x86_64.zip
unzip android-ndk-r21e-darwin-x86_64.zip -d $ANDROID_NDK_ROOT
rm android-ndk-r21e-darwin-x86_64.zip



# Configure environment variables
echo "Configuring environment variables..."
export PATH=$PATH:$ANDROID_SDK_ROOT/cmdline-tools/tools/bin:$ANDROID_SDK_ROOT/platform-tools
export ANDROID_NDK_HOME=$ANDROID_NDK_ROOT/android-ndk-r21e

# Accept Android SDK licenses
yes | $ANDROID_SDK_ROOT/cmdline-tools/tools/bin/sdkmanager --licenses

# Install required Android packages
echo "Installing Android packages..."
$ANDROID_SDK_ROOT/cmdline-tools/tools/bin/sdkmanager "platform-tools" "build-tools;30.0.3" "platforms;android-30"

# Display installed versions
echo "Installed versions:"
java -version
javac -version
$ANDROID_SDK_ROOT/cmdline-tools/tools/bin/sdkmanager --version
$ANDROID_NDK_HOME/ndk-build --version
