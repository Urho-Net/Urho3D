#include "macos_support.h"
#include <dirent.h>
#include <cerrno>
#include <unistd.h>
#include <utime.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

#ifndef _TESTCASE_
#include <mono/jit/jit.h>
#endif

#include <mono/metadata/environment.h>
#include <mono/utils/mono-publib.h>
#include <mono/metadata/mono-config.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/mono-debug.h>
#include <mono/utils/mono-logger.h>

enum
{
    FILESTATUS_FLAGS_NONE = 0,
    FILESTATUS_FLAGS_HAS_BIRTHTIME = 1,
};


#define ST_ATIME_NSEC(statstruct) ((statstruct)->st_atimespec.tv_nsec)
#define ST_MTIME_NSEC(statstruct) ((statstruct)->st_mtimespec.tv_nsec)
#define ST_CTIME_NSEC(statstruct) ((statstruct)->st_ctimespec.tv_nsec)

typedef struct
{
    int32_t Flags;     // flags for testing if some members are present (see FileStatusFlags)
    int32_t Mode;      // file mode (see S_I* constants above for bit values)
    uint32_t Uid;      // user ID of owner
    uint32_t Gid;      // group ID of owner
    int64_t Size;      // total size, in bytes
    int64_t ATime;     // time of last access
    int64_t ATimeNsec; //     nanosecond part
    int64_t MTime;     // time of last modification
    int64_t MTimeNsec; //     nanosecond part
    int64_t CTime;     // time of last status change
    int64_t CTimeNsec; //     nanosecond part
    int64_t BirthTime; // time the file was created
    int64_t BirthTimeNsec; // nanosecond part
    int64_t Dev;       // ID of the device containing the file
    int64_t Ino;       // inode number of the file
    uint32_t UserFlags; // user defined flags
} FileStatus;

static void ConvertFileStatus(const struct stat* src,  FileStatus* dst)
{
    dst->Dev = (int64_t)src->st_dev;
    dst->Ino = (int64_t)src->st_ino;
    dst->Flags = FILESTATUS_FLAGS_NONE;
    dst->Mode = (int32_t)src->st_mode;
    dst->Uid = src->st_uid;
    dst->Gid = src->st_gid;
    dst->Size = src->st_size;

    dst->ATime = src->st_atime;
    dst->MTime = src->st_mtime;
    dst->CTime = src->st_ctime;

    dst->ATimeNsec = ST_ATIME_NSEC(src);
    dst->MTimeNsec = ST_MTIME_NSEC(src);
    dst->CTimeNsec = ST_CTIME_NSEC(src);

#if HAVE_STAT_BIRTHTIME
    dst->BirthTime = src->st_birthtimespec.tv_sec;
    dst->BirthTimeNsec = src->st_birthtimespec.tv_nsec;
    dst->Flags |= FILESTATUS_FLAGS_HAS_BIRTHTIME;
#else
    // Linux path: until we use statx() instead
    dst->BirthTime = 0;
    dst->BirthTimeNsec = 0;
#endif

#if defined(HAVE_STAT_FLAGS) && defined(UF_HIDDEN)
    dst->UserFlags = ((src->st_flags & UF_HIDDEN) == UF_HIDDEN) ? PAL_UF_HIDDEN : 0;
#else
    dst->UserFlags = 0;
#endif
}

GD_PINVOKE_EXPORT int32_t SystemNative_Stat2(const char* path,  FileStatus* output)
{
    struct stat result;
    int ret;
    while ((ret = stat(path, &result)) < 0 && errno == EINTR);

    if (ret == 0)
    {
        ConvertFileStatus(&result, output);
    }

    return ret;
}


namespace macos {
namespace support {

void initialize()
{
    mono_dllmap_insert(NULL, "System.Native", NULL, "libmono-native-unified", NULL);
    mono_dllmap_insert(NULL, "System.Security.Cryptography.Native.Apple", NULL, "libmono-native-unified", NULL);
    
}

void cleanup()
{
    
    
}

} // namespace macos
} // namespace support
