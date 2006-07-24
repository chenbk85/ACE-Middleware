
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl XML_OUTPUT_ADAPTER_STUB
// ------------------------------
#ifndef XML_OUTPUT_ADAPTER_STUB_EXPORT_H
#define XML_OUTPUT_ADAPTER_STUB_EXPORT_H

#include "ace/config-all.h"

#if !defined (XML_OUTPUT_ADAPTER_STUB_HAS_DLL)
#  define XML_OUTPUT_ADAPTER_STUB_HAS_DLL 1
#endif /* ! XML_OUTPUT_ADAPTER_STUB_HAS_DLL */

#if defined (XML_OUTPUT_ADAPTER_STUB_HAS_DLL) && (XML_OUTPUT_ADAPTER_STUB_HAS_DLL == 1)
#  if defined (XML_OUTPUT_ADAPTER_STUB_BUILD_DLL)
#    define XML_OUTPUT_ADAPTER_STUB_Export ACE_Proper_Export_Flag
#    define XML_OUTPUT_ADAPTER_STUB_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define XML_OUTPUT_ADAPTER_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* XML_OUTPUT_ADAPTER_STUB_BUILD_DLL */
#    define XML_OUTPUT_ADAPTER_STUB_Export ACE_Proper_Import_Flag
#    define XML_OUTPUT_ADAPTER_STUB_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define XML_OUTPUT_ADAPTER_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* XML_OUTPUT_ADAPTER_STUB_BUILD_DLL */
#else /* XML_OUTPUT_ADAPTER_STUB_HAS_DLL == 1 */
#  define XML_OUTPUT_ADAPTER_STUB_Export
#  define XML_OUTPUT_ADAPTER_STUB_SINGLETON_DECLARATION(T)
#  define XML_OUTPUT_ADAPTER_STUB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* XML_OUTPUT_ADAPTER_STUB_HAS_DLL == 1 */

// Set XML_OUTPUT_ADAPTER_STUB_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (XML_OUTPUT_ADAPTER_STUB_NTRACE)
#  if (ACE_NTRACE == 1)
#    define XML_OUTPUT_ADAPTER_STUB_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define XML_OUTPUT_ADAPTER_STUB_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !XML_OUTPUT_ADAPTER_STUB_NTRACE */

#if (XML_OUTPUT_ADAPTER_STUB_NTRACE == 1)
#  define XML_OUTPUT_ADAPTER_STUB_TRACE(X)
#else /* (XML_OUTPUT_ADAPTER_STUB_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define XML_OUTPUT_ADAPTER_STUB_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (XML_OUTPUT_ADAPTER_STUB_NTRACE == 1) */

#endif /* XML_OUTPUT_ADAPTER_STUB_EXPORT_H */

// End of auto generated file.
