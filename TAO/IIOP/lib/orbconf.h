// This may look like C, but it's really -*- C++ -*-
//
/* orbconf.hh.  Generated automatically by configure.  */
// @(#) $Id$
// Copyright 1995 by Sun Microsystems, Inc
//
// Build configuration file for the Inter-ORB Engine, and application
// level code using it via <corba.hh>
//
// !! Modify "orbconf.hh", not the file generated by "configure" !!
//
// Keep the tests in the order they're found in "configure.in".  Also, keep
// in mind that all "#undef" preprocessor directives are deemed to be the
// property of "autoconf"; if those are needed in their own right, they must
// be in some other file.
//
// This file builds on work originally contributed by a team at apm.co.uk:
// Owen Rees (rtor), Guangxing Li (gxl) and Mike Beasley (mdrb).
//

#ifndef	_ORB_CONFIG_HH
#define	_ORB_CONFIG_HH

#include "ace/OS.h"

//
// BC++ seems to have a different convention for detecting Win32 than VC++.
//
#if	defined (__WIN32__)
#	define _WIN32
#endif	// BC++ convention

/* Define if you have the <widec.h> header file.  */
#if !defined(linux) && !defined(_WIN32) && !defined(VXWORKS)
#  define HAVE_WIDEC_H 1
#endif

/* Define to `int' if <sys/types.h> doesn't define.  */
/* #undef pid_t */

/* Define if your processor stores words with the most significant
   byte first (like Motorola and SPARC, unlike Intel and VAX).  */
#if defined(i386) || defined(_M_IX86) || defined(vax)
#else
#  define WORDS_BIGENDIAN 1
#endif

/* The number of bytes in an int.  */
#	if defined(_WIN32) || defined(linux) || defined(VXWORKS)
#		define	SIZEOF_INT	4
#	else	// Win16
#		define	SIZEOF_INT	2
#	endif	// Win32/Win16

/* The number of bytes in a long.  */
#define SIZEOF_LONG 4

/* The number of bytes in a void *.  */
#define SIZEOF_VOID_P 4

/* The number of bytes in a long long.  */
#if   !defined (_WIN32) && !defined (VXWORKS)
#define SIZEOF_LONG_LONG 8
#endif

/* The number of bytes in a long double.  */
#if defined(linux)
#  define SIZEOF_LONG_DOUBLE 12
#elif defined(_WIN32) || defined(VXWORKS)
#  define SIZEOF_LONG_DOUBLE 8
#else
#  define SIZEOF_LONG_DOUBLE 16
#endif

/* The number of bytes in a bool.  */
#define SIZEOF_BOOL 0

// The number of bytes in a wchar_t
#if defined (VXWORKS)
#define SIZEOF_WCHAR_T 1
#else
#define SIZEOF_WCHAR_T 2
#endif

/* Define as the return type of signal handlers (int or void).  */
#define RETSIGTYPE void

/* Define if you don't have vprintf but do have _doprnt.  */
/* #undef HAVE_DOPRNT */

/* Define if you have the vprintf function.  */
#define HAVE_VPRINTF 1

/* Define if you have strerror declared.  */
#define DECLARED_STRERROR 1

// With ACE, we always have this :-)
#define HAVE_GETTIMEOFDAY


//
// Various issues not dealt with via autoconf/configure.
//
#if !defined(ACE_INVALID_HANDLE)
#if	!defined (_WINSOCKAPI_)
	// Winsock added nonstandard APIs
#	define	closesocket(s)		close(s)
#endif	// _WINSOCKAPI_
#endif

#ifdef	minor
	// namespace pollution that's common on older UNIXes,
    // XXX this can't go here, "autoconf" wants to own #undef
/* #	undef	minor */
#endif	// minor

//
// For Win16, near/far pointers reflect same/other segment addressing.
//
#if	defined (unix) || defined (_WIN32) || defined(VXWORKS)
#	define	_FAR
#endif

//
// Assume DOS/Windows if "configure" didn't get run.
//
#if !defined(SIZEOF_LONG) || defined(_WIN32)
//#	if defined(_WIN32) || defined(linux)
//#		define	SIZEOF_INT	4
//#	else	// Win16
//#		define	SIZEOF_INT	2
//#	endif	// Win32/Win16

#	define DECLARED_ACCEPT
#	define DECLARED_BIND
#	define DECLARED_CONNECT
#	define DECLARED_GETHOSTNAME
#	define DECLARED_H_ERRNO
#	define DECLARED_LISTEN
#	define DECLARED_LISTEN
#	define DECLARED_SELECT
#	define DECLARED_SETSOCKOPT
#	define DECLARED_SHUTDOWN
#	define DECLARED_SOCKET

#	define HAVE_STRDUP

#  if !defined(linux) && !defined(_WIN32)
typedef	unsigned long pid_t;
#  endif

// "C4355: 'this' : used in base member initializer list"
#  pragma warning(disable:4355) /* disable C4355 warning */

#endif

//
// For both Win16 and Win32, DLLs (shared libraries) need to know what
// classes, functions, and data are exported.  DLLs aren't quite dealt
// with here yet, it's tough to do it portably (viz. the different
// answers now used by BC++/VC++).
//
// (Wouldn't it be nice if more C++ compilers and linkers took advantage
// of syntax to help get ensure that only public interfaces get exported
// from shared libraries?  Hmmm...)
//
#if	defined (unix) || !defined (__BORLANDC__)
#	define	_EXPFUNC
#	define	_EXPDATA
#endif

#if defined (hpux)
#	define SELECT_INT_STAR
#endif

#if !defined(ACE_INVALID_HANDLE)
#  if !defined(HAVE_STRDUP)
#    define strdup(s) strcpy ((char *)malloc (strlen (s) + 1), s)
#  endif
#endif

#endif	// _ORB_CONFIG_HH
