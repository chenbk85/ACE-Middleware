// -*- C++ -*-
// $Id$

//
// The following configuration file is designed to work for win32
// platforms using gcc/g++ with mingw32 (http://www.mingw.org).
//

#ifndef ACE_CONFIG_WIN32_MINGW_H
#define ACE_CONFIG_WIN32_MINGW_H
#include /**/ "ace/pre.h"

#ifndef ACE_CONFIG_WIN32_H
#  error Use config-win32.h in config.h instead of this header
#endif /* ACE_CONFIG_WIN32_H */

#define ACE_CC_PREPROCESSOR "cpp"
#define ACE_CC_PREPROCESOR_ARGS ""

#if !defined(__MINGW32__)
#  error You do not seem to be using mingw32
#endif

#include "ace/config-g++-common.h"

#include /**/ <_mingw.h>
#include /**/ <w32api.h>

#define ACE_HAS_USER_MODE_MASKS

#if (__MINGW32_MAJOR_VERSION < 2) && (__MINGW64_VERSION_MAJOR < 3)
#  error You need a newer version (>= 2.0) of mingw32/w32api
#endif

// When using the --std=c++0x option the compiler omits defining
// the following required macros (at least with the GCC 4.6.2 version)
// So we define them ourselves here.
#if !defined(WIN32)
#  define _stdcall __attribute__((__stdcall__))
#  define _cdecl __attribute__((__cdecl__))
#  define _thiscall __attribute__((__thiscall__))
#  define _fastcall __attribute__((__fastcall__))
#  define WIN32 1
#  define WINNT 1
#  define i386 1
#endif

// In strict ANSI mode (default when using --std=c++0x) the fileno()
// macro is not defined so use the following work around.
#if defined(__STRICT_ANSI__)
# define ACE_FILENO_EQUIVALENT ::_fileno
#endif

#if (__MINGW32_MAJOR_VERSION >= 3) || (__MINGW64_VERSION_MAJOR >= 3)
#  define ACE_HAS_SSIZE_T
#  undef ACE_LACKS_STRUCT_DIR
#  undef ACE_LACKS_OPENDIR
#  undef ACE_LACKS_CLOSEDIR
#  undef ACE_LACKS_READDIR
#  undef ACE_LACKS_TELLDIR
#  undef ACE_LACKS_SEEKDIR
#  undef ACE_LACKS_REWINDDIR
#else
#  define ACE_LACKS_DIRENT_H
#endif

#if (__MINGW32_MAJOR_VERSION > 3)  || ((__MINGW32_MAJOR_VERSION == 3) && (__MINGW32_MINOR_VERSION >= 15))
# undef ACE_LACKS_USECONDS_T
#elif (__MINGW64_VERSION_MAJOR >= 3)
# undef ACE_LACKS_USECONDS_T
#endif

#if (__MINGW64_VERSION_MAJOR >= 3)
# define ACE_HAS_POSIX_TIME 1
# define ACE_LACKS_TIMESPEC_T 1

# include <stdlib.h>
# if defined (strtod)
#  undef strtod
# endif
#else
# if defined (ACE_LACKS_SIGSET_T)
#   undef ACE_LACKS_SIGSET_T
# endif
#endif

#undef ACE_HAS_WTOF

#define ACE_LACKS_SYS_SHM_H
#define ACE_LACKS_TERMIOS_H
#define ACE_LACKS_NETINET_TCP_H
#define ACE_LACKS_STRRECVFD
#define ACE_LACKS_STRPTIME
#define ACE_LACKS_POLL_H
#define ACE_LACKS_REGEX_H
#define ACE_LACKS_SYS_MSG_H
#define ACE_LACKS_PWD_H
#define ACE_LACKS_SEMAPHORE_H
#define ACE_LACKS_UCONTEXT_H
#define ACE_LACKS_SYS_SELECT_H
#define ACE_LACKS_SYS_RESOURCE_H
#define ACE_LACKS_SYS_WAIT_H
#define ACE_LACKS_DLFCN_H
#define ACE_LACKS_SYS_MMAN_H
#define ACE_LACKS_SYS_UIO_H
#define ACE_LACKS_SYS_SOCKET_H
#define ACE_LACKS_NETINET_IN_H
#define ACE_LACKS_NETDB_H
#define ACE_LACKS_NET_IF_H
#define ACE_LACKS_SYS_IPC_H
#define ACE_LACKS_SYS_SEM_H
#define ACE_LACKS_STROPTS_H
#define ACE_LACKS_SYS_IOCTL_H
#define ACE_LACKS_PDH_H
#define ACE_LACKS_PDHMSG_H
#define ACE_LACKS_STRTOK_R
#define ACE_LACKS_LOCALTIME_R
#define ACE_HAS_NONCONST_WCSDUP
#define ACE_HAS_WINSOCK2_GQOS
#define ACE_ISCTYPE_EQUIVALENT ::_isctype

// We trust the user: He must have used -mpentiumpro or -mpentium
// if that is what he wants.
#if defined(pentiumpro) || defined(pentium)
# define ACE_HAS_PENTIUM
#endif

#define ACE_INT64_FORMAT_SPECIFIER_ASCII "%I64d"
#define ACE_UINT64_FORMAT_SPECIFIER_ASCII "%I64u"

#define ACE_ENDTHREADEX(STATUS)  ::_endthreadex ((DWORD) (STATUS))

#define ACE_DLL_PREFIX ACE_TEXT ("lib")

#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_WIN32_MINGW_H */
