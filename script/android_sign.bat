del /q my-release-key.jks
keytool -genkey -v -storepass Android -keypass Android -keystore my-release-key.jks -keyalg RSA -keysize 2048 -validity 10000 -alias my-alias
del /q %1-aligned.apk
zipalign -v -p 4 %1.apk %1-aligned.apk
del /q my-app-release.apk 
apksigner sign --ks my-release-key.jks --ks-pass pass:Android --out my-app-release.apk %1-aligned.apk
