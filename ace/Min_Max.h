// -*- C++ -*-
// $Id$

#ifndef ACE_MIN_MAX_H
#include "ace/pre.h"
#define ACE_MIN_MAX_H

// ============================================================================
//
// = LIBRARY
//   ace
//
// = FILENAME
//   Min_Max.h
//
// = DESCRIPTION
//   Define an appropriate set of min()/max() functions using templates. 
//
// = AUTHOR
//   Derek Dominish <Derek.Dominish@Australia.Boeing.com>
//
// ============================================================================

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#   pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

# if !defined (ACE_LACKS_MIN_MAX_TEMPLATES)
template <class T>
inline const T &
ace_min (const T &t1, const T &t2)
{
  return t2 > t1 ? t1 : t2;
}

template <class T>
inline const T & 
ace_max (const T &t1, const T &t2) 
{
  return t1 > t2 ? t1 : t2;
}

template <class T>
inline const T &
ace_min (const T &t1, const T &t2, const T &t3) 
{
  return ace_min (ace_min (t1, t2), t3);
}

template <class T>
inline const T &
ace_max (const T &t1, const T &t2, const T &t3) 
{
  return ace_max (ace_max (t1, t2), t3);
}

template <class T>
inline const T &
ace_range (const T &min, const T &max, const T &val)
{
  return ace_min (ace_max (min, val), max);
}
# else
// These macros should only be used if a C++ compiler can't grok the
// inline templates 
#  define ace_min(a,b)      (((b) > (a)) ? (a) : (b))
#  define ace_max(a,b)      (((a) > (b)) ? (a) : (b))
#  define ace_range(a,b,c)  (ace_min(ace_max((a), (c)), (b))

# endif /* ACE_LACKS_MIN_MAX_TEMPLATES */

# define ACE_MIN(a,b)     ace_min((a),(b))
# define ACE_MAX(a,b)     ace_max((a),(b))
# define ACE_RANGE(a,b,c) ace_range((a),(b),(c))

#include "ace/post.h"
#endif  /* ACE_MIN_MAX_H */
