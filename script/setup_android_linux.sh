#!/bin/bash

# Set up environment variables
export ANDROID_SDK_ROOT=$HOME/android-sdk
export ANDROID_NDK_ROOT=$HOME/android-ndk

# Install Android SDK
echo "Installing Android SDK..."
wget https://dl.google.com/android/repository/commandlinetools-linux-7583922_latest.zip
unzip commandlinetools-linux-7583922_latest.zip -d $ANDROID_SDK_ROOT
rm commandlinetools-linux-7583922_latest.zip

# Install Java JDK
echo "Installing Java JDK..."
sudo apt-get update
sudo apt-get install -y openjdk-8-jdk

# Install Android NDK
echo "Installing Android NDK..."
wget https://dl.google.com/android/repository/android-ndk-r21e-linux-x86_64.zip
unzip android-ndk-r21e-linux-x86_64.zip -d $HOME
rm android-ndk-r21e-linux-x86_64.zip

# Configure environment variables
echo "Configuring environment variables..."
export PATH=$PATH:$ANDROID_SDK_ROOT/cmdline-tools/latest/bin:$ANDROID_SDK_ROOT/platform-tools
export JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64
export ANDROID_NDK_HOME=$ANDROID_NDK_ROOT/android-ndk-r21e

# Accept Android SDK licenses
yes | sdkmanager --licenses

# Install required Android packages
echo "Installing Android packages..."
sdkmanager "platform-tools" "build-tools;30.0.3" "platforms;android-30"

# Display installed versions
echo "Installed versions:"
java -version
javac -version
sdkmanager --version
$ANDROID_NDK_HOME/ndk-build --version
