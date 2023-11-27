if ($env:GITHUB_ACTIONS -eq "true") {
   $monoPath = "C:\Program Files\Mono"
   # Configure Mono Environment
   $env:PATH += ";$monoPath\bin"
   $env:FrameworkPathOverride = "$monoPath\lib\mono\4.5"
}
New-Item -ItemType Directory -Force "..\UrhoDotNet\desktop" | Out-Null
dotnet build ../Bindings/Projects/UrhoProjects/UrhoDotNet/UrhoDotNet.csproj --no-incremental -c Release
