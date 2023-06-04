if ($env:GITHUB_ACTIONS -eq "true") {
   $monoPath = "C:\Program Files\Mono"
   # Configure Mono Environment
   $env:PATH += ";$monoPath\bin"
   $env:FrameworkPathOverride = "$monoPath\lib\mono\4.5"
}
New-Item -ItemType Directory -Force "..\UrhoDotNet\desktop" | Out-Null
csc /target:library /out:../UrhoDotNet/desktop/UrhoDotNet.dll /platform:x64 -unsafe /doc:../UrhoDotNet/desktop/UrhoDotNet.xml -define:NET45  -define:HAVE_REFLECTION_EMIT -define:HAVE_LINQ -define:FEATURE_JNIOBJECTREFERENCE_INTPTRS -define:INTEROP -define:FEATURE_JNIENVIRONMENT_JI_PINVOKES Desktop/*.cs Portable/*.cs Portable/Actions/*.cs Portable/Actions/Base/*.cs Portable/Actions/Ease/*.cs Portable/Actions/Instants/*.cs Portable/Actions/Instants/Callfunc/*.cs  Portable/Actions/Intervals/*.cs  Portable/External/*.cs Portable/Math/*.cs Portable/Runtime/*.cs Portable/Shapes/*.cs   Portable/Generated/*.cs Java.Interop/*.cs Java.Interop.Dynamic/*.cs ../Newtonsoft.Json/*.cs ../Newtonsoft.Json/Bson/*.cs ../Newtonsoft.Json/Converters/*.cs ../Newtonsoft.Json/Linq/*.cs ../Newtonsoft.Json/Linq/JsonPath/*.cs ../Newtonsoft.Json/Properties/*.cs ../Newtonsoft.Json/Schema/*.cs ../Newtonsoft.Json/Serialization/*.cs ../Newtonsoft.Json/Utilities/*.cs Portable/UIActions/*.cs Portable/UIActions/Base/*.cs Portable/UIActions/Ease/*.cs Portable/UIActions/Instants/*.cs Portable/UIActions/Instants/Callfunc/*.cs  Portable/UIActions/Intervals/*.cs
