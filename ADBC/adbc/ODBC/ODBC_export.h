
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl ADBC_ODBC
// ------------------------------
#ifndef ADBC_ODBC_EXPORT_H
#define ADBC_ODBC_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (ADBC_ODBC_HAS_DLL)
#  define ADBC_ODBC_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && ADBC_ODBC_HAS_DLL */

#if !defined (ADBC_ODBC_HAS_DLL)
#  define ADBC_ODBC_HAS_DLL 1
#endif /* ! ADBC_ODBC_HAS_DLL */

#if defined (ADBC_ODBC_HAS_DLL) && (ADBC_ODBC_HAS_DLL == 1)
#  if defined (ADBC_ODBC_BUILD_DLL)
#    define ADBC_ODBC_Export ACE_Proper_Export_Flag
#    define ADBC_ODBC_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define ADBC_ODBC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* ADBC_ODBC_BUILD_DLL */
#    define ADBC_ODBC_Export ACE_Proper_Import_Flag
#    define ADBC_ODBC_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define ADBC_ODBC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* ADBC_ODBC_BUILD_DLL */
#else /* ADBC_ODBC_HAS_DLL == 1 */
#  define ADBC_ODBC_Export
#  define ADBC_ODBC_SINGLETON_DECLARATION(T)
#  define ADBC_ODBC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* ADBC_ODBC_HAS_DLL == 1 */

// Set ADBC_ODBC_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (ADBC_ODBC_NTRACE)
#  if (ACE_NTRACE == 1)
#    define ADBC_ODBC_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define ADBC_ODBC_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !ADBC_ODBC_NTRACE */

#if (ADBC_ODBC_NTRACE == 1)
#  define ADBC_ODBC_TRACE(X)
#else /* (ADBC_ODBC_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define ADBC_ODBC_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (ADBC_ODBC_NTRACE == 1) */

#endif /* ADBC_ODBC_EXPORT_H */

// End of auto generated file.
