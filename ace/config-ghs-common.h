/* -*- C++ -*- */
// $Id$

// This configuration file is designed to be included by another,
// specific configuration file.  It provides config information common
// to all Green Hills platforms.

#ifndef ACE_GHS_COMMON_H
#define ACE_GHS_COMMON_H

#if !defined (ACE_CONFIG_INCLUDE_GHS_COMMON)
# error ace/config-ghs-common.h: ACE configuration error!  Do not #include this file directly!
#endif

#if defined (ghs)

# if defined (__STANDARD_CXX)
    // Green Hills 1.8.9, but not 1.8.8.
#   define ACE_HAS_STANDARD_CPP_LIBRARY 1
#   define ACE_LACKS_CHAR_RIGHT_SHIFTS
#   define ACE_LACKS_UNBUFFERED_STREAMBUF
# endif /* __STANDARD_CXX */

# define ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA
# define ACE_HAS_WCHAR_TYPEDEFS_CHAR
# define ACE_LACKS_LINEBUFFERED_STREAMBUF
# define ACE_LACKS_LONGLONG_T

#else  /* ! ghs */
# error ace/config-ghs-common.h can only be used with Green Hills compilers!
#endif /* ! ghs */

#endif /* ACE_GHS_COMMON_H */
