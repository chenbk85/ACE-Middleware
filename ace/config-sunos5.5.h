/* -*- C++ -*- */
// $Id$

// This configuration file is designed to work for SunOS 5.5 platforms
// using the following compilers:
//   * Sun C++ 4.2 and later (including 5.x), patched as noted below
//   * g++ 2.7.2 and later, including egcs
//   * Green Hills 1.8.8 and later

#ifndef ACE_CONFIG_H
#define ACE_CONFIG_H

// Compiler version-specific settings:
#if defined (__SUNPRO_CC)
# if (__SUNPRO_CC < 0x410)
    // The following might not be necessary, but I can't tell: my build
    // with Sun C++ 4.0.1 never completes.
#   define ACE_NEEDS_DEV_IO_CONVERSION
# elif (__SUNPRO_CC >= 0x420)
# define ACE_HAS_ANSI_CASTS
# if (__SUNPRO_CC >= 0x500)
    /* Explicit instantiation requires the -instances=explicit
       CCFLAG.  It seems to work for the most part, except for:
       1) Static data members get instantiated multiple times.
       2) In TAO, the TAO_Unbounded_Sequence vtbl can't be found.
       With CC 5.0, those problems may be fixed.  And, this is necessary
       to work around problems with automatic template instantiation. */
#   define ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION
#   define ACE_TEMPLATES_REQUIRE_SOURCE
#   define ACE_LACKS_ACE_IOSTREAM
# endif /* __SUNPRO_CC >= 0x500 */
# endif /* __SUNPRO_CC >= 0x420 */
# define ACE_CAST_CONST const
# define ACE_HAS_HI_RES_TIMER
# define ACE_HAS_SIG_C_FUNC /* Sun CC 5.0 needs this, 4.2 doesn't mind. */
# define ACE_HAS_TEMPLATE_SPECIALIZATION
# define ACE_HAS_XPG4_MULTIBYTE_CHAR
# define ACE_LACKS_LINEBUFFERED_STREAMBUF
# define ACE_LACKS_SIGNED_CHAR

  // ACE_HAS_EXCEPTIONS precludes -noex in
  // include/makeinclude/platform_macros.GNU.  But beware, we have
  // seen problems with exception handling on multiprocessor
  // UltraSparcs:  threaded executables core dump when threads exit.
  // This problem does not seem to appear on single-processor UltraSparcs.
  // And, it is solved with the application of patch
  //   104631-02 "C++ 4.2: Jumbo Patch for C++ 4.2 on Solaris SPARC"
  // to Sun C++ 4.2.
  // To provide optimum performance, ACE_HAS_EXCEPTIONS is disabled by
  // default.  It can be enabled by adding "exceptions=1" to the "make"
  // invocation.  See include/makeinclude/platform_sunos5_sunc++.GNU
  // for details.
  // #define ACE_HAS_EXCEPTIONS

#  if defined (ACE_HAS_EXCEPTIONS)
     // If exceptions are enabled and we are using Sun/CC then
     // <operator new> throws an exception instead of returning 0.
#    define ACE_NEW_THROWS_EXCEPTIONS
#  endif /* ACE_NEW_THROWS_EXCEPTIONS */

    /* If you want to disable threading with Sun CC, remove -mt
       from your CFLAGS, e.g., using make threads=0. */

#elif defined (__GNUG__)
# include "ace/config-g++-common.h"
# define ACE_HAS_HI_RES_TIMER
# define ACE_HAS_STRING_CLASS
  // Denotes that GNU has cstring.h as standard, to redefine memchr().
# define ACE_HAS_GNU_CSTRING_H
# define ACE_HAS_XPG4_MULTIBYTE_CHAR
# define ACE_MALLOC_ALIGN 8

# if !defined (ACE_MT_SAFE) || ACE_MT_SAFE != 0
    // ACE_MT_SAFE is #defined below, for all compilers.
#   if !defined (_REENTRANT)
    /* If you want to disable threading, comment out the following
       line.  Or, add -DACE_MT_SAFE=0 to your CFLAGS, e.g., using
       make threads=0. */
#     define _REENTRANT
#   endif /* _REENTRANT */
# endif /* !ACE_MT_SAFE */

#elif defined (ghs)
# if defined (__STANDARD_CXX)
   // Green Hills 1.8.9, but not 1.8.8.
#   define ACE_HAS_STANDARD_CPP_LIBRARY 1
# endif /* __STANDARD_CXX */

# define ACE_HAS_BROKEN_ENUMS /* Necessary with 1.8.9, harmless with 1.8.8. */
# define ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA
# define ACE_LACKS_LINEBUFFERED_STREAMBUF
# define ACE_LACKS_LONGLONG_T /* It really doesn't have it.  Boo. */
# define ACE_LACKS_SIGNED_CHAR

# if !defined (ACE_MT_SAFE) || ACE_MT_SAFE != 0
    // ACE_MT_SAFE is #defined below, for all compilers.
#   if !defined (_REENTRANT)
    /* If you want to disable threading, comment out the following
       line.  Or, add -DACE_MT_SAFE=0 to your CFLAGS, e.g., using
       make threads=0. */
#     define _REENTRANT
#   endif /* _REENTRANT */
# endif /* !ACE_MT_SAFE */

  // To avoid warning about inconsistent declaration between Sun's
  // stdlib.h and Green Hills' ctype.h.
# include <stdlib.h>

#else  /* ! __SUNPRO_CC && ! __GNUG__  && ! ghs */
# error unsupported compiler in ace/config-sunos5.5.h
#endif /* ! __SUNPRO_CC && ! __GNUG__  && ! ghs */

#if !defined (__ACE_INLINE__)
// NOTE:  if you have link problems with undefined inline template
// functions with Sun C++, be sure that the #define of __ACE_INLINE__
// below is not commented out.
# define __ACE_INLINE__
#endif /* ! __ACE_INLINE__ */

// Platform supports the POSIX regular expression library.
// NOTE:  please comment out the ACE_HAS_REGEX #define if you
// have link problems with g++ or egcs on SunOS 5.5.
#define ACE_HAS_REGEX

// Maximum compensation (10 ms) for early return from timed ::select ().
#if !defined (ACE_TIMER_SKEW)
# define ACE_TIMER_SKEW 10 * 1000
#endif /* ACE_TIMER_SKEW */

// Optimize ACE_Handle_Set for select().
#define ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT

// Platform supports pread() and pwrite()
#define ACE_HAS_P_READ_WRITE
#define ACE_HAS_RECURSIVE_THR_EXIT_SEMANTICS
#define ACE_HAS_UALARM
#define ACE_LACKS_UALARM_PROTOTYPE

// Platform supports System V IPC (most versions of UNIX, but not Win32)
#define ACE_HAS_SYSV_IPC

#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES

// Platform supports system configuration information.
#define ACE_HAS_SYSINFO

// Platform supports recvmsg and sendmsg.
#define ACE_HAS_MSG

// Compiler/platform contains the <sys/syscall.h> file.
#define ACE_HAS_SYSCALL_H

// Platform has terminal ioctl flags like TCGETS and TCSETS.
#define ACE_HAS_TERM_IOCTLS

// Compiler/platform correctly calls init()/fini() for shared libraries.
#define ACE_HAS_AUTOMATIC_INIT_FINI

// Platform supports POSIX O_NONBLOCK semantics.
#define ACE_HAS_POSIX_NONBLOCK

// Compiler/platform has correctly prototyped header files.
#define ACE_HAS_CPLUSPLUS_HEADERS

// Platform supports IP multicast
#define ACE_HAS_IP_MULTICAST

// Compiler/platform supports alloca()
#define ACE_HAS_ALLOCA

// Compiler/platform has <alloca.h>
#define ACE_HAS_ALLOCA_H

// Platform contains <poll.h>.
#define ACE_HAS_POLL

// Platform supports POSIX timers via timestruc_t.
#define ACE_HAS_POSIX_TIME

// ACE_HAS_CLOCK_GETTIME requires linking with -lposix4.
#define ACE_HAS_CLOCK_GETTIME

// Platform supports the /proc file system.
#define ACE_HAS_PROC_FS

// Platform supports the prusage_t struct.
#define ACE_HAS_PRUSAGE_T

// Compiler/platform defines the sig_atomic_t typedef.
#define ACE_HAS_SIG_ATOMIC_T

// Platform supports SVR4 extended signals.
#define ACE_HAS_SIGINFO_T
#define ACE_HAS_UCONTEXT_T

// Compiler/platform provides the sockio.h file.
#define ACE_HAS_SOCKIO_H

// Compiler supports the ssize_t typedef.
#define ACE_HAS_SSIZE_T

// Platform supports STREAMS.
#define ACE_HAS_STREAMS

// Platform supports STREAM pipes.
#define ACE_HAS_STREAM_PIPES

// Compiler/platform supports strerror ().
#define ACE_HAS_STRERROR

// Compiler/platform supports struct strbuf.
#define ACE_HAS_STRBUF_T

// Compiler/platform supports SVR4 dynamic linking semantics.
#define ACE_HAS_SVR4_DYNAMIC_LINKING

// Compiler/platform supports SVR4 gettimeofday() prototype.
#define ACE_HAS_SVR4_GETTIMEOFDAY

// Compiler/platform supports SVR4 ACE_TLI (in particular, T_GETNAME stuff)...
#define ACE_HAS_SVR4_TLI

// Platform provides <sys/filio.h> header.
#define ACE_HAS_SYS_FILIO_H

// Compiler/platform supports sys_siglist array.
#define ACE_HAS_SYS_SIGLIST

#if defined (_REENTRANT)
  // Compile using multi-thread libraries.
# define ACE_HAS_THREADS

# if !defined (ACE_MT_SAFE)
#   define ACE_MT_SAFE 1
# endif /* ACE_MT_SAFE */

  // Platform supports POSIX pthreads *and* Solaris threads, by
  // default!  If you only want to use POSIX pthreads, add
  // -D_POSIX_PTHREAD_SEMANTICS to your CFLAGS.  Or, #define it right
  // here.  See the Intro (3) man page for information on
  // -D_POSIX_PTHREAD_SEMANTICS.
# if !defined (_POSIX_PTHREAD_SEMANTICS)
#   define ACE_HAS_STHREADS
# endif /* ! _POSIX_PTHREAD_SEMANTICS */

# define ACE_HAS_PTHREADS
# define ACE_HAS_PTHREADS_STD
  // . . . but only supports SCHED_OTHER scheduling policy
# define ACE_HAS_ONLY_SCHED_OTHER
# define ACE_HAS_SIGWAIT

  // Compiler/platform has thread-specific storage
# define ACE_HAS_THREAD_SPECIFIC_STORAGE

  // Platform supports reentrant functions (i.e., all the POSIX *_r functions).
# define ACE_HAS_REENTRANT_FUNCTIONS

# define ACE_NEEDS_LWP_PRIO_SET
# define ACE_HAS_PTHREAD_SIGMASK
# define ACE_HAS_THR_YIELD
# define ACE_LACKS_PTHREAD_YIELD
#endif /* _REENTRANT */

# define ACE_HAS_PRIOCNTL

// Platform supports ACE_TLI timod STREAMS module.
#define ACE_HAS_TIMOD_H

// Platform supports ACE_TLI tiuser header.
#define ACE_HAS_TIUSER_H

// Platform provides ACE_TLI function prototypes.
#define ACE_HAS_TLI_PROTOTYPES

// Platform supports ACE_TLI.
#define ACE_HAS_TLI

// Turns off the tracing feature.
#if !defined (ACE_NTRACE)
# define ACE_NTRACE 1
#endif /* ACE_NTRACE */

#define ACE_HAS_GETPAGESIZE 1

#define ACE_HAS_STL_MAP_CONFLICT
#define ACE_HAS_STL_QUEUE_CONFLICT
#define ACE_HAS_IDTYPE_T

#define ACE_HAS_GPERF
#define ACE_HAS_DIRENT

#if defined (__SUNPRO_CC)
# define ACE_CC_NAME "SunPro C++"
# define ACE_CC_MAJOR_VERSION (__SUNPRO_CC >> 8)
# define ACE_CC_MINOR_VERSION (__SUNPRO_CC & 0x00ff)
# define ACE_CC_BETA_VERSION  (0)
#elif defined (__GNUG__)
# define ACE_CC_MAJOR_VERSION __GNUC__
# define ACE_CC_MINOR_VERSION __GNUC_MINOR__
# define ACE_CC_BETA_VERSION  (0)
# if __GNUC_MINOR__ >= 90
#   define ACE_CC_NAME "egcs"
# else
#   define ACE_CC_NAME "g++"
# endif /* __GNUC_MINOR__ */
#endif /* __GNUG__ */

#if defined (i386)
# define ACE_HAS_X86_STAT_MACROS
#endif /* i386 */

#endif /* ACE_CONFIG_H */
