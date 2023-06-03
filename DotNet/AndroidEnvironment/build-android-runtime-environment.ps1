if ($env:GITHUB_ACTIONS -eq "true") {
   $monoPath = "C:\Program Files\Mono"
   # Configure Mono Environment
   $env:PATH += ";$monoPath\bin"
   $env:FrameworkPathOverride = "$monoPath\lib\mono\4.5"
}
New-Item -ItemType Directory -Force "..\UrhoDotNet\mobile\android" | Out-Null
mcs /target:library /out:../UrhoDotNet/mobile/android/Mono.Android.dll -unsafe -define:__ANDROID__  AndroidEnvironment.cs
