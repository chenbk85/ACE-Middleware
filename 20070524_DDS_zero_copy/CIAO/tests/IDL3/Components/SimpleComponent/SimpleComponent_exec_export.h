
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl SIMPLECOMPONENT_EXEC
// ------------------------------
#ifndef SIMPLECOMPONENT_EXEC_EXPORT_H
#define SIMPLECOMPONENT_EXEC_EXPORT_H

#include "ace/config-all.h"

#if !defined (SIMPLECOMPONENT_EXEC_HAS_DLL)
#  define SIMPLECOMPONENT_EXEC_HAS_DLL 1
#endif /* ! SIMPLECOMPONENT_EXEC_HAS_DLL */

#if defined (SIMPLECOMPONENT_EXEC_HAS_DLL) && (SIMPLECOMPONENT_EXEC_HAS_DLL == 1)
#  if defined (SIMPLECOMPONENT_EXEC_BUILD_DLL)
#    define SIMPLECOMPONENT_EXEC_Export ACE_Proper_Export_Flag
#    define SIMPLECOMPONENT_EXEC_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define SIMPLECOMPONENT_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* SIMPLECOMPONENT_EXEC_BUILD_DLL */
#    define SIMPLECOMPONENT_EXEC_Export ACE_Proper_Import_Flag
#    define SIMPLECOMPONENT_EXEC_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define SIMPLECOMPONENT_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* SIMPLECOMPONENT_EXEC_BUILD_DLL */
#else /* SIMPLECOMPONENT_EXEC_HAS_DLL == 1 */
#  define SIMPLECOMPONENT_EXEC_Export
#  define SIMPLECOMPONENT_EXEC_SINGLETON_DECLARATION(T)
#  define SIMPLECOMPONENT_EXEC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* SIMPLECOMPONENT_EXEC_HAS_DLL == 1 */

// Set SIMPLECOMPONENT_EXEC_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (SIMPLECOMPONENT_EXEC_NTRACE)
#  if (ACE_NTRACE == 1)
#    define SIMPLECOMPONENT_EXEC_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define SIMPLECOMPONENT_EXEC_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !SIMPLECOMPONENT_EXEC_NTRACE */

#if (SIMPLECOMPONENT_EXEC_NTRACE == 1)
#  define SIMPLECOMPONENT_EXEC_TRACE(X)
#else /* (SIMPLECOMPONENT_EXEC_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define SIMPLECOMPONENT_EXEC_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (SIMPLECOMPONENT_EXEC_NTRACE == 1) */

#endif /* SIMPLECOMPONENT_EXEC_EXPORT_H */

// End of auto generated file.
