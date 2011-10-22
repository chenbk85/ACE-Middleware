
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// ------------------------------
#ifndef CORBA_DOMAIN_VALIDATOR_EXPORT_H
#define CORBA_DOMAIN_VALIDATOR_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (CORBA_DOMAIN_VALIDATOR_HAS_DLL)
#  define CORBA_DOMAIN_VALIDATOR_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && CORBA_DOMAIN_VALIDATOR_HAS_DLL */

#if !defined (CORBA_DOMAIN_VALIDATOR_HAS_DLL)
#  define CORBA_DOMAIN_VALIDATOR_HAS_DLL 1
#endif /* ! CORBA_DOMAIN_VALIDATOR_HAS_DLL */

#if defined (CORBA_DOMAIN_VALIDATOR_HAS_DLL) && (CORBA_DOMAIN_VALIDATOR_HAS_DLL == 1)
#  if defined (CORBA_DOMAIN_VALIDATOR_BUILD_DLL)
#    define CORBA_Domain_Validator_Export ACE_Proper_Export_Flag
#    define CORBA_DOMAIN_VALIDATOR_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define CORBA_DOMAIN_VALIDATOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* CORBA_DOMAIN_VALIDATOR_BUILD_DLL */
#    define CORBA_Domain_Validator_Export ACE_Proper_Import_Flag
#    define CORBA_DOMAIN_VALIDATOR_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define CORBA_DOMAIN_VALIDATOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* CORBA_DOMAIN_VALIDATOR_BUILD_DLL */
#else /* CORBA_DOMAIN_VALIDATOR_HAS_DLL == 1 */
#  define CORBA_Domain_Validator_Export
#  define CORBA_DOMAIN_VALIDATOR_SINGLETON_DECLARATION(T)
#  define CORBA_DOMAIN_VALIDATOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* CORBA_DOMAIN_VALIDATOR_HAS_DLL == 1 */

// Set CORBA_DOMAIN_VALIDATOR_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (CORBA_DOMAIN_VALIDATOR_NTRACE)
#  if (ACE_NTRACE == 1)
#    define CORBA_DOMAIN_VALIDATOR_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define CORBA_DOMAIN_VALIDATOR_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !CORBA_DOMAIN_VALIDATOR_NTRACE */

#if (CORBA_DOMAIN_VALIDATOR_NTRACE == 1)
#  define CORBA_DOMAIN_VALIDATOR_TRACE(X)
#else /* (CORBA_DOMAIN_VALIDATOR_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define CORBA_DOMAIN_VALIDATOR_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (CORBA_DOMAIN_VALIDATOR_NTRACE == 1) */

#endif /* CORBA_DOMAIN_VALIDATOR_EXPORT_H */

// End of auto generated file.
