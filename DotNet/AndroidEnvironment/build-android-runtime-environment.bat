mkdir ..\UrhoDotNet\mobile\android
mcs /target:library /out:../UrhoDotNet/mobile/android/Mono.Android.dll -unsafe -define:__ANDROID__  AndroidEnvironment.cs
