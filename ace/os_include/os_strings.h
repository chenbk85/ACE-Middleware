// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_strings.h
 *
 *  string operations
 *
 *  $Id$
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_STRINGS_H
#define ACE_OS_INCLUDE_OS_STRINGS_H

#include /**/ "ace/pre.h"

#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/os_stddef.h"

#if !defined (ACE_LACKS_STRINGS_H)
#  include /**/ <strings.h>
#endif /* !ACE_LACKS_STRINGS_H */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#if defined (__Lynx__)
  int strcasecmp(const char *, const char *);
  int strncasecmp(const char *, const char *, size_t);
#endif /* __Lynx__ */
    
#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_STRINGS_H */
