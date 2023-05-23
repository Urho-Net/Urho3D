//
// Copyright (c) 2008-2020 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#if  defined(__ANDROID__)

#include <dirent.h>
#include <cerrno>
#include <unistd.h>
#include <utime.h>
#include <sys/wait.h>



#ifndef _TESTCASE_
#include <mono/jit/jit.h>
#endif

#include <mono/metadata/environment.h>
#include <mono/utils/mono-publib.h>
#include <mono/metadata/mono-config.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/mono-debug.h>
#include <mono/utils/mono-logger.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif


namespace android {
namespace support {

void initialize()
{
        mono_dllmap_insert(NULL, "java-interop", "java_interop_jvm_list", "MonoEmbedded", "java_interop_jvm_list");
        mono_dllmap_insert(NULL, "__Internal", "monodroid_get_system_property", "MonoEmbedded", "monodroid_get_system_property");
        mono_dllmap_insert(NULL, "__Internal", "monodroid_free", "MonoEmbedded", "monodroid_free");
        mono_dllmap_insert(NULL, "__Internal", "_monodroid_timezone_get_default_id", "MonoEmbedded", "_monodroid_timezone_get_default_id");
        mono_dllmap_insert(NULL, "__Internal", "_monodroid_getifaddrs", "MonoEmbedded", "_monodroid_getifaddrs");
        mono_dllmap_insert(NULL, "__Internal", "_monodroid_freeifaddrs", "MonoEmbedded", "_monodroid_freeifaddrs");
        mono_dllmap_insert(NULL, "__Internal", "_mono_android_init_cert_store", "MonoEmbedded", "_mono_android_init_cert_store");
        mono_dllmap_insert(NULL, "__Internal", "_mono_android_cert_store_lookup", "MonoEmbedded", "_mono_android_cert_store_lookup");
        


        mono_dllmap_insert(NULL, "System.Native", NULL, "mono-native", NULL);
        mono_dllmap_insert(NULL, "System.Net.Security.Native", NULL, "mono-native", NULL);
        
        mono_dllmap_insert(NULL, "MonoPosixHelper", NULL, "MonoPosixHelper", NULL);
        mono_dllmap_insert(NULL, "libmono-btls-shared", NULL, "mono-btls-shared", NULL);
        
    
}

void cleanup()
{
    
    
}

#ifdef __cplusplus
}
#endif


} // namespace macos
} // namespace support


#endif // ANDROID