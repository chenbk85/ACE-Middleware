
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl TSEC_CHECKPOINT_SVNT
// ------------------------------
#ifndef TSEC_CHECKPOINT_SVNT_EXPORT_H
#define TSEC_CHECKPOINT_SVNT_EXPORT_H

#include "ace/config-all.h"

#if !defined (TSEC_CHECKPOINT_SVNT_HAS_DLL)
#  define TSEC_CHECKPOINT_SVNT_HAS_DLL 1
#endif /* ! TSEC_CHECKPOINT_SVNT_HAS_DLL */

#if defined (TSEC_CHECKPOINT_SVNT_HAS_DLL) && (TSEC_CHECKPOINT_SVNT_HAS_DLL == 1)
#  if defined (TSEC_CHECKPOINT_SVNT_BUILD_DLL)
#    define TSEC_CHECKPOINT_SVNT_Export ACE_Proper_Export_Flag
#    define TSEC_CHECKPOINT_SVNT_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define TSEC_CHECKPOINT_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* TSEC_CHECKPOINT_SVNT_BUILD_DLL */
#    define TSEC_CHECKPOINT_SVNT_Export ACE_Proper_Import_Flag
#    define TSEC_CHECKPOINT_SVNT_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define TSEC_CHECKPOINT_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* TSEC_CHECKPOINT_SVNT_BUILD_DLL */
#else /* TSEC_CHECKPOINT_SVNT_HAS_DLL == 1 */
#  define TSEC_CHECKPOINT_SVNT_Export
#  define TSEC_CHECKPOINT_SVNT_SINGLETON_DECLARATION(T)
#  define TSEC_CHECKPOINT_SVNT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* TSEC_CHECKPOINT_SVNT_HAS_DLL == 1 */

// Set TSEC_CHECKPOINT_SVNT_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (TSEC_CHECKPOINT_SVNT_NTRACE)
#  if (ACE_NTRACE == 1)
#    define TSEC_CHECKPOINT_SVNT_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define TSEC_CHECKPOINT_SVNT_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !TSEC_CHECKPOINT_SVNT_NTRACE */

#if (TSEC_CHECKPOINT_SVNT_NTRACE == 1)
#  define TSEC_CHECKPOINT_SVNT_TRACE(X)
#else /* (TSEC_CHECKPOINT_SVNT_NTRACE == 1) */
#  define TSEC_CHECKPOINT_SVNT_TRACE(X) ACE_TRACE_IMPL(X)
#endif /* (TSEC_CHECKPOINT_SVNT_NTRACE == 1) */

#endif /* TSEC_CHECKPOINT_SVNT_EXPORT_H */

// End of auto generated file.
