#ifdef __ANDROID__

#include "../Container/Str.h"
#include "../Core/Context.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef _TESTCASE_
#include <mono/jit/jit.h>
#endif

#include <mono/metadata/environment.h>
#include <mono/utils/mono-publib.h>
#include <mono/metadata/mono-config.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/mono-debug.h>
#include <mono/utils/mono-logger.h>

#include "ifaddrs-android.h"
#include <android/log.h>
#include <jni.h>
#include <sys/system_properties.h>

#define DllExport extern "C" __attribute__((visibility("default")))

using namespace Urho3D;

#define ERR_FAIL_NULL_V(m_param, m_retval)
#define ERR_PRINTS(m_string)
#define _FORCE_INLINE_ inline

template <typename T> struct ScopedLocalRef
{
    JNIEnv* env;
    T local_ref;

    _FORCE_INLINE_ T get() const { return local_ref; }
    _FORCE_INLINE_ operator T() const { return local_ref; }
    _FORCE_INLINE_ operator jvalue() const { return (jvalue)local_ref; }

    _FORCE_INLINE_ operator bool() const { return local_ref != NULL; }

    _FORCE_INLINE_ bool operator==(std::nullptr_t) const { return local_ref == nullptr; }

    _FORCE_INLINE_ bool operator!=(std::nullptr_t) const { return local_ref != nullptr; }

    ScopedLocalRef(const ScopedLocalRef&) = delete;
    ScopedLocalRef& operator=(const ScopedLocalRef&) = delete;

    ScopedLocalRef(JNIEnv* p_env, T p_local_ref)
        : env(p_env)
        , local_ref(p_local_ref)
    {
    }

    ~ScopedLocalRef()
    {
        if (local_ref)
        {
            env->DeleteLocalRef(local_ref);
        }
    }
};

#ifdef __cplusplus
extern "C" {
#endif

    JavaVM* SDL_Android_GetJVM();
    JNIEnv* Android_JNI_GetEnv(void);

    bool jni_exception_check(JNIEnv *p_env) 
    {
        if (p_env->ExceptionCheck()) {
            // Print the exception to logcat
            p_env->ExceptionDescribe();

            p_env->ExceptionClear();
            return true;
        }

        return false;
    }

    DllExport int32_t monodroid_get_system_property(const char* p_name, char** r_value)
    {
        char prop_value_str[PROP_VALUE_MAX + 1] = {0};

        int len = __system_property_get(p_name, prop_value_str);

        if (r_value)
        {
            if (len >= 0)
            {
                *r_value = (char*)malloc(len + 1);
                if (!*r_value)
                    return -1;
                memcpy(*r_value, prop_value_str, len);
                (*r_value)[len] = '\0';
            }
            else
            {
                *r_value = NULL;
            }
        }

        return len;
    }

    DllExport void monodroid_free(void* ptr) { free(ptr); }

    DllExport int32_t _monodroid_getifaddrs(struct ifaddrs** p_ifap) { return getifaddrs(p_ifap); }

    DllExport void _monodroid_freeifaddrs(struct ifaddrs* p_ifap) { freeifaddrs(p_ifap); }

    DllExport int java_interop_jvm_list(JavaVM** vmBuf, int bufLen, int* nVMs)
    {
        __android_log_print(2, "Urho3D", "java_interop_jvm_list vmBuf=%p bufLen=%d nVMs=%p", vmBuf, bufLen, nVMs);
        if (vmBuf != 0)
        {
            vmBuf[0] = SDL_Android_GetJVM();
        }

        if (nVMs != NULL)
        {
            *nVMs = 1;
        }

        return 0;
    }

    DllExport const char* _monodroid_timezone_get_default_id()
    {
        // The JNI code is the equivalent of:
        //
        // TimeZone.getDefault().getID()

        JNIEnv* env = Android_JNI_GetEnv();

        ScopedLocalRef<jclass> timeZoneClass(env, env->FindClass("java/util/TimeZone"));
        ERR_FAIL_NULL_V(timeZoneClass, NULL);

        jmethodID getDefault = env->GetStaticMethodID(timeZoneClass, "getDefault", "()Ljava/util/TimeZone;");
        ERR_FAIL_NULL_V(getDefault, NULL);

        jmethodID getID = env->GetMethodID(timeZoneClass, "getID", "()Ljava/lang/String;");
        ERR_FAIL_NULL_V(getID, NULL);

        ScopedLocalRef<jobject> defaultTimeZone(env, env->CallStaticObjectMethod(timeZoneClass, getDefault));

        if (!defaultTimeZone)
            return NULL;

        ScopedLocalRef<jstring> defaultTimeZoneID(env, (jstring)env->CallObjectMethod(defaultTimeZone, getID));

        if (!defaultTimeZoneID)
            return NULL;

        const char* default_time_zone_id = env->GetStringUTFChars(defaultTimeZoneID, 0);

        char* result = strdup(default_time_zone_id); // freed by the BCL

        env->ReleaseStringUTFChars(defaultTimeZoneID, default_time_zone_id);

        return result;
    }


static jobject certStore = NULL; // KeyStore

DllExport MonoBoolean _mono_android_init_cert_store() {
	// The JNI code is the equivalent of:
	//
	// try {
	// 	certStoreLocal = KeyStore.getInstance("AndroidCAStore");
	// 	certStoreLocal.load(null);
	//	certStore = certStoreLocal;
	//	return true;
	// } catch (Exception e) {
	//	return false;
	// }

	JNIEnv* env = Android_JNI_GetEnv();

	ScopedLocalRef<jclass> keyStoreClass(env, env->FindClass("java/security/KeyStore"));

	jmethodID getInstance = env->GetStaticMethodID(keyStoreClass, "getInstance", "(Ljava/lang/String;)Ljava/security/KeyStore;");
	jmethodID load = env->GetMethodID(keyStoreClass, "load", "(Ljava/security/KeyStore$LoadStoreParameter;)V");

	ScopedLocalRef<jstring> androidCAStoreString(env, env->NewStringUTF("AndroidCAStore"));

	ScopedLocalRef<jobject> certStoreLocal(env, env->CallStaticObjectMethod(keyStoreClass, getInstance, androidCAStoreString.get()));

	if (jni_exception_check(env))
		return 0;

	env->CallVoidMethod(certStoreLocal, load, NULL);

	if (jni_exception_check(env))
		return 0;

	certStore = env->NewGlobalRef(certStoreLocal);

	return 1;
}

DllExport MonoArray *_mono_android_cert_store_lookup(MonoString *p_alias) {
	// The JNI code is the equivalent of:
	//
	// Certificate certificate = certStore.getCertificate(alias);
	// if (certificate == null)
	//	return null;
	// return certificate.getEncoded();

    return NULL;
    
/* TBD ELI , unstable , needs more work
	MonoError mono_error;
	char *alias_utf8 = mono_string_to_utf8_checked(p_alias, &mono_error);

	if (!mono_error_ok(&mono_error)) {
		ERR_PRINTS(String() + "Failed to convert MonoString* to UTF-8: '" + mono_error_get_message(&mono_error) + "'.");
		mono_error_cleanup(&mono_error);
		return NULL;
	}

	JNIEnv* env = Android_JNI_GetEnv();

	ScopedLocalRef<jstring> js_alias(env, env->NewStringUTF(alias_utf8));
	mono_free(alias_utf8);

	ScopedLocalRef<jclass> keyStoreClass(env, env->FindClass("java/security/KeyStore"));
	ERR_FAIL_NULL_V(keyStoreClass, NULL);
	ScopedLocalRef<jclass> certificateClass(env, env->FindClass("java/security/cert/Certificate"));
	ERR_FAIL_NULL_V(certificateClass, NULL);

	jmethodID getCertificate = env->GetMethodID(keyStoreClass, "getCertificate", "(Ljava/lang/String;)Ljava/security/cert/Certificate;");
	ERR_FAIL_NULL_V(getCertificate, NULL);

	jmethodID getEncoded = env->GetMethodID(certificateClass, "getEncoded", "()[B");
	ERR_FAIL_NULL_V(getEncoded, NULL);

	ScopedLocalRef<jobject> certificate(env, env->CallObjectMethod(certStore, getCertificate, js_alias.get()));

	if (!certificate)
		return NULL;

	ScopedLocalRef<jbyteArray> encoded(env, (jbyteArray)env->CallObjectMethod(certificate, getEncoded));
	jsize encodedLength = env->GetArrayLength(encoded);

	MonoArray *encoded_ret = mono_array_new(mono_domain_get(), mono_get_byte_class() , encodedLength);
	uint8_t *dest = (uint8_t *)mono_array_addr(encoded_ret, uint8_t, 0);

	env->GetByteArrayRegion(encoded, 0, encodedLength, reinterpret_cast<jbyte *>(dest));

	return encoded_ret;
    */
}

#ifdef __cplusplus
}
#endif

#endif // ANDROID