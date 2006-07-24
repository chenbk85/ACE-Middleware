/* -*- C++ -*- */
// $Id$

// The following configuration file is designed to work for SunOS4
// platforms using the SunC++ 3.0.x compiler.

#ifndef ACE_CONFIG_H

#define ACE_LACKS_GETPGID
#define ACE_LACKS_SETPGID

#define ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT

#define ACE_HAS_UNION_WAIT
#define ACE_HAS_SPARCWORKS_401_SIGNALS

#define ACE_CONFIG_H
#define ACE_HAS_CHARPTR_SPRINTF
#define ACE_HAS_SYS_ERRLIST

// Platform supports System V IPC (most versions of UNIX, but not Win32)
#define ACE_HAS_SYSV_IPC

// Platform supports recvmsg and sendmsg.
#define ACE_HAS_MSG

// Compiler/platform contains the <sys/syscall.h> file.
#define ACE_HAS_SYS_SYSCALL_H

// Compiler/platform has the getrusage() system call.
#define ACE_HAS_GETRUSAGE

// Header files lack t_errno for ACE_TLI.
// #define ACE_LACKS_T_ERRNO

// Compiler/platform uses old malloc()/free() prototypes (ugh).
#define ACE_HAS_OLD_MALLOC

// Defines the page size of the system.
#define ACE_PAGE_SIZE 4096

// Compiler/platform supports poll().
#define ACE_HAS_POLL

// Compiler/platform defines a union semun for SysV shared memory.
#define ACE_HAS_SEMUN

// Compiler/platform provides the sockio.h file.
#define ACE_HAS_SYS_SOCKIO_H

// Compiler/platform supports struct strbuf
#define ACE_HAS_STRBUF_T

// Platform supports STREAMS.
#define ACE_HAS_STREAMS

// Platform/compiler supports timezone * as second parameter to gettimeofday().
#define ACE_HAS_TIMEZONE_GETTIMEOFDAY

// Compiler/platform supports SVR4 dynamic linking semantics.
#define ACE_HAS_SVR4_DYNAMIC_LINKING

// Platform provides <sys/filio.h> header.
#define ACE_HAS_SYS_FILIO_H

// Platform supports ACE_TLI tiuser header.
// #define ACE_HAS_TIUSER_H

// Platform has ACE_TLI.
// #define ACE_HAS_TLI

#define ACE_LACKS_LINEBUFFERED_STREAMBUF
#define ACE_LACKS_SIGNED_CHAR

#define ACE_NEEDS_DEV_IO_CONVERSION

#define ACE_LACKS_U_LONGLONG_T

#define ACE_LACKS_DIFFTIME

#endif /* ACE_CONFIG_H */
