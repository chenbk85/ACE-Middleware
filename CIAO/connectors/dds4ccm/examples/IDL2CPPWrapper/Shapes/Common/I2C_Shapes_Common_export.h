// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// ------------------------------
#ifndef I2C_SHAPES_COMMON_EXPORT_H
#define I2C_SHAPES_COMMON_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (I2C_SHAPES_HAS_DLL)
#  define I2C_SHAPES_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && I2C_SHAPES_HAS_DLL */

#if !defined (I2C_SHAPES_HAS_DLL)
#  define I2C_SHAPES_HAS_DLL 1
#endif /* ! I2C_SHAPES_HAS_DLL */

#if defined (I2C_SHAPES_HAS_DLL) && (I2C_SHAPES_HAS_DLL == 1)
#  if defined (I2C_SHAPES_COMMON_BUILD_DLL)
#    define I2C_SHAPES_Export ACE_Proper_Export_Flag
#    define I2C_SHAPES_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define I2C_SHAPES_COMMON_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* I2C_SHAPES_COMMON_BUILD_DLL */
#    define I2C_SHAPES_Export ACE_Proper_Import_Flag
#    define I2C_SHAPES_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define I2C_SHAPES_COMMON_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* I2C_SHAPES_COMMON_BUILD_DLL */
#else /* I2C_SHAPES_HAS_DLL == 1 */
#  define I2C_SHAPES_Export
#  define I2C_SHAPES_SINGLETON_DECLARATION(T)
#  define I2C_SHAPES_COMMON_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* I2C_SHAPES_HAS_DLL == 1 */

#endif /* I2C_SHAPES_COMMON_EXPORT_H */

// End of auto generated file.
