mkdir -p ../UrhoDotNet/editor
csc /target:library /out:../UrhoDotNet/editor/UrhoDotNet.dll /platform:x64  -unsafe -define:__EDITOR__  -define:HAVE_REFLECTION_EMIT -define:HAVE_LINQ  -define:NET45 -define:FEATURE_JNIOBJECTREFERENCE_INTPTRS -define:INTEROP -define:FEATURE_JNIENVIRONMENT_JI_PINVOKES /doc:../UrhoDotNet/editor/UrhoDotNet.xml -define:NET45 Desktop/*.cs Portable/*.cs Portable/Actions/*.cs Portable/Actions/Base/*.cs Portable/Actions/Ease/*.cs Portable/Actions/Instants/*.cs Portable/Actions/Instants/Callfunc/*.cs  Portable/Actions/Intervals/*.cs  Portable/External/*.cs Portable/Math/*.cs Portable/Runtime/*.cs Portable/Shapes/*.cs   Portable/Generated/*.cs Java.Interop/*.cs Java.Interop.Dynamic/*.cs ../Newtonsoft.Json/*.cs ../Newtonsoft.Json/Bson/*.cs ../Newtonsoft.Json/Converters/*.cs ../Newtonsoft.Json/Linq/*.cs ../Newtonsoft.Json/Linq/JsonPath/*.cs ../Newtonsoft.Json/Properties/*.cs ../Newtonsoft.Json/Schema/*.cs ../Newtonsoft.Json/Serialization/*.cs ../Newtonsoft.Json/Utilities/*.cs
