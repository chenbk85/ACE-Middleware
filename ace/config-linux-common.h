/* -*- C++ -*- */
// $Id$

// This configuration file is designed to be included by another,
// specific configuration file.  It provides config information common
// to all Linux platforms.  It automatically determines the CPU
// architecture, compiler (g++ or egcs), libc (libc5 or glibc), and
// whether the library supports exception handling, and configures
// based on those.

#if !defined (ACE_LINUX_COMMON_H)
#define ACE_LINUX_COMMON_H

#define ACE_HAS_BYTESEX_H

#if ! defined (__ACE_INLINE__)
#define __ACE_INLINE__
#endif /* ! __ACE_INLINE__ */

// Needed to differentiate between libc 5 and libc 6 (aka glibc).
// It's there on all libc 5 systems I checked.
#include <features.h>


// First the machine specific part

#if defined (i386)
  // If running an Intel, assume that it's a Pentium so that
  // ACE_OS::gethrtime () can use the RDTSC instruction.  If
  // running a 486 or lower, be sure to comment this out.
  // (If not running an Intel CPU, this #define will not be seen
  //  because of the i386 protection, so it can be ignored.)
# define ACE_HAS_PENTIUM
#endif /* i386 */


// Then glibc/libc5 specific parts

#if defined(__GLIBC__)
# define ACE_HAS_BROKEN_SETRLIMIT
# define ACE_HAS_RUSAGE_WHO_ENUM enum __rusage_who
# define ACE_HAS_RLIMIT_RESOURCE_ENUM enum __rlimit_resource
# define ACE_HAS_SOCKLEN_T

  // NOTE:  the following defines are necessary with glibc 2.0 (0.961212-5)
  //        on Alpha.  I assume that they're necessary on Intel as well,
  //        but that may depend on the version of glibc that is used.
# define ACE_HAS_DLFCN_H_BROKEN_EXTERN_C
# define ACE_HAS_VOIDPTR_SOCKOPT
# define ACE_LACKS_GETPGID
# define ACE_LACKS_RPC_H
# define ACE_NEEDS_SYSTIME_H
  // The strtok_r declaration is protected in string.h.
  extern "C" char *strtok_r __P ((char *__s, __const char *__delim,
                                  char **__save_ptr));
  // NOTE:  end of glibc 2.0 (0.961212-5)-specific configuration.

#if defined (__alpha)
  // To avoid compilation warnings about TCP_NODELAY and TCP_MAXSEG
  // being redefined, because they're defined in linux/socket.h:
# define ACE_LACKS_TCP_H

// NOTE:  On __alpha only, the assembler doesn't have enough string
//        space with -g.  You can either SUPPRESS_DASH_G = 1, or patch
//        your binutils 2.8.1.0.1-g gas/ecoff.c as follows:
//--- ecoff.c.ORIGINAL	Mon May 26 12:32:47 1997
//+++ ecoff.c	Thu Jan 15 09:21:08 1998
//@@ -769,7 +769,11 @@
//    can't be represented (assuming there are strings > 4096 bytes).  */
// 
// #ifndef PAGE_SIZE
//-#define PAGE_SIZE 4096		/* size of varray pages */
//+// Thu Jan 15 09:21:03 CST 1998  David L. Levine  <levine@cs.wustl.edu>
//+// Raised PAGE_SIZE to 8192 from 4096 to avoid "String too big"
//+// errors on Linux/Alpha, with -g.  The OS page size is 8192, so this
//+// should be OK.
//+#define PAGE_SIZE 8192		/* size of varray pages */
// #endif
// 
// #define PAGE_USIZE ((unsigned long) PAGE_SIZE)

// NOTE: you'll need to patch /usr/src/linux/include/linux/posix_types.h
//       as follows:
//--- posix_types.h.ORIGINAL	Wed Nov 12 12:01:56 1997
//+++ posix_types.h	Wed Jan 14 13:07:47 1998
//@@ -41,9 +41,13 @@
// #undef __FDMASK
// #define	__FDMASK(d)	(1UL << ((d) % __NFDBITS))
// 
//-typedef struct fd_set {
//+#include <gnu/types.h>
//+typedef __fd_set __kernel_fd_set;
//+#if 0
//+typedef struct kernel_fd_set {
// 	unsigned long fds_bits [__FDSET_LONGS];
// } __kernel_fd_set;
//+#endif
// 
// /* Type of a signal handler.  */
// typedef void (*__kernel_sighandler_t)(int);
#endif /* ! __alpha */

#else
#endif /* __GLIBC__ */


// Then the compiler specific parts

#if defined (__GNUG__)
# include "ace/config-g++-common.h"
#elif defined (__KCC)
// Add KCC support here!
# error KCC support is not yet available from ace/config-linux-common.h
#else  /* ! __GNUG__ && ! __KCC */
# error unsupported compiler in ace/config-linux-common.h
#endif /* ! __GNUG__ && ! __KCC */


// Completely common part :-)

// Platform/compiler has the sigwait(2) prototype
#define ACE_HAS_SIGWAIT

# define ACE_DEFAULT_BASE_ADDR ((char *) 0x80000000)

// Fixes a problem with new versions of Linux...
#ifndef msg_accrights
#undef msg_control
#define msg_accrights msg_control
#endif

#ifndef msg_accrightslen
#undef msg_controllen
#define msg_accrightslen msg_controllen
#endif

// Compiler/platform supports alloca().
#define ACE_HAS_ALLOCA

// Compiler/platform has <alloca.h>
#define ACE_HAS_ALLOCA_H

// Compiler/platform has the getrusage() system call.
#define ACE_HAS_GETRUSAGE
#define ACE_HAS_GETRUSAGE_PROTO

#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES

// Optimize ACE_Handle_Set for select().
#define ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT

// ONLY define this if you have config'd multicast into a 2.x kernel.
// If you do anything else, we've never tested it!
#define ACE_HAS_IP_MULTICAST

#define ACE_HAS_LONG_FDMASK

#define ACE_HAS_STRING_CLASS

// Linux defines struct msghdr in /usr/include/socket.h
#define ACE_HAS_MSG

// Linux "improved" the interface to select() so that it modifies
// the struct timeval to reflect the amount of time not slept
// (see NOTES in Linux's select(2) man page).
#define ACE_HAS_NONCONST_SELECT_TIMEVAL

// Defines the page size of the system.
#define ACE_PAGE_SIZE 4096

// Platform lacks POSIX prototypes for certain System V functions
// like shared memory and message queues.
#define ACE_LACKS_SOME_POSIX_PROTOTYPES

// Platform defines struct timespec but not timespec_t
#define ACE_LACKS_TIMESPEC_T

#define ACE_LACKS_STRRECVFD

#define ACE_LACKS_MSYNC
#define ACE_LACKS_MADVISE

// Platform supports System V IPC (most versions of UNIX, but not Win32)
#define ACE_HAS_SYSV_IPC

// Compiler/platform contains the <sys/syscall.h> file.
#define ACE_HAS_SYSCALL_H

#define ACE_HAS_SUNOS4_GETTIMEOFDAY

// Compiler/platform supports strerror ().
#define ACE_HAS_STRERROR

// Compiler supports the ssize_t typedef.
#define ACE_HAS_SSIZE_T

// Compiler/platform defines the sig_atomic_t typedef.
#define ACE_HAS_SIG_ATOMIC_T

// Compiler/platform defines a union semun for SysV shared memory.
#define ACE_HAS_SEMUN

#define ACE_HAS_POSIX_TIME

// Turns off the tracing feature.
#if !defined (ACE_NTRACE)
# define ACE_NTRACE 1
#endif /* ACE_NTRACE */

#if defined(__EXCEPTIONS)
# define ACE_HAS_EXCEPTIONS
#endif

#endif /* ACE_LINUX_COMMON_H */
