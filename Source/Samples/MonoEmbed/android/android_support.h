#ifndef ANDROID_SUPPORT_H
#define ANDROID_SUPPORT_H

#if  defined(__ANDROID__)

#ifdef __cplusplus
extern "C" {
#endif

namespace android {
namespace support {

void initialize();
void cleanup();

} // namespace support
} // namespace ios

#ifdef __cplusplus
}
#endif

#endif // __ANDROID__

#endif // ANDROID_SUPPORT_H
