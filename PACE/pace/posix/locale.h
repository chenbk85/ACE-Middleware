/* $Id$ -*- C -*-

 * ============================================================================
 *
 * = LIBRARY
 *    pace
 *
 * = FILENAME
 *    locale.h
 *
 * = AUTHOR
 *    Joe Hoffert
 *
 * ===========================================================================
 */


#ifndef PACE_LOCALE_H
#define PACE_LOCALE_H


#include "pace/defines.h"
#include <locale.h>


# if defined (PACE_HAS_CPLUSPLUS)
extern "C" {
# endif /* PACE_HAS_CPLUSPLUS */

  PACE_INLINE char * pace_setlocale (int category, const char * locale);

# if defined (PACE_HAS_CPLUSPLUS)
}
# endif /* PACE_HAS_CPLUSPLUS */

# if defined (PACE_HAS_INLINE)
# include "locale.inl"
# endif /* PACE_HAS_INLINE */


#endif /* PACE_LOCALE_H */
