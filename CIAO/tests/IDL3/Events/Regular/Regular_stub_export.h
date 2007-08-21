
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl REGULAR_STUB
// ------------------------------
#ifndef REGULAR_STUB_EXPORT_H
#define REGULAR_STUB_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (REGULAR_STUB_HAS_DLL)
#  define REGULAR_STUB_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && REGULAR_STUB_HAS_DLL */

#if !defined (REGULAR_STUB_HAS_DLL)
#  define REGULAR_STUB_HAS_DLL 1
#endif /* ! REGULAR_STUB_HAS_DLL */

#if defined (REGULAR_STUB_HAS_DLL) && (REGULAR_STUB_HAS_DLL == 1)
#  if defined (REGULAR_STUB_BUILD_DLL)
#    define REGULAR_STUB_Export ACE_Proper_Export_Flag
#    define REGULAR_STUB_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define REGULAR_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* REGULAR_STUB_BUILD_DLL */
#    define REGULAR_STUB_Export ACE_Proper_Import_Flag
#    define REGULAR_STUB_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define REGULAR_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* REGULAR_STUB_BUILD_DLL */
#else /* REGULAR_STUB_HAS_DLL == 1 */
#  define REGULAR_STUB_Export
#  define REGULAR_STUB_SINGLETON_DECLARATION(T)
#  define REGULAR_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* REGULAR_STUB_HAS_DLL == 1 */

// Set REGULAR_STUB_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (REGULAR_STUB_NTRACE)
#  if (ACE_NTRACE == 1)
#    define REGULAR_STUB_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define REGULAR_STUB_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !REGULAR_STUB_NTRACE */

#if (REGULAR_STUB_NTRACE == 1)
#  define REGULAR_STUB_TRACE(X)
#else /* (REGULAR_STUB_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define REGULAR_STUB_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (REGULAR_STUB_NTRACE == 1) */

#endif /* REGULAR_STUB_EXPORT_H */

// End of auto generated file.
