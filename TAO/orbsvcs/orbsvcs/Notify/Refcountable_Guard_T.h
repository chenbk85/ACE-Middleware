/* -*- C++ -*- */
/**
 *  @file Refcountable_Guard_T.h
 *
 *  $Id$
 *
 *  @author Pradeep Gore <pradeep@oomworks.com>
 *
 *
 */

#ifndef TAO_Notify_REFCOUNTABLE_GUARD_T_H
#define TAO_Notify_REFCOUNTABLE_GUARD_T_H

#include /**/ "ace/pre.h"

#include "notify_serv_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

/**
 * @class TAO_Notify_Refcountable_Guard_T
 *
 * @brief Increments the reference count in the constructor, the count is decremented in the destructor.
 *
 */
template <class T>
class TAO_Notify_Refcountable_Guard_T
{
public:
  /// Constuctor
  TAO_Notify_Refcountable_Guard_T (T* t = 0);

  /// Copy constructor
  TAO_Notify_Refcountable_Guard_T (const TAO_Notify_Refcountable_Guard_T<T> & rhs);

  /// Destructor
  ~TAO_Notify_Refcountable_Guard_T ();

  /// Redirection operator
  T * get (void) const;

  /// Redirection operator
  T *operator-> (void) const;

  T &operator *() const;

  TAO_Notify_Refcountable_Guard_T<T> & operator = (
    const TAO_Notify_Refcountable_Guard_T<T> & rhs);

private:
  /// helper for exception safeness
  /// @throws nothing
  void swap (TAO_Notify_Refcountable_Guard_T & rhs);
private:
  T* t_;
};

#if defined (__ACE_INLINE__)
#include "Refcountable_Guard_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "Refcountable_Guard_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Refcountable_Guard_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"

#endif /* TAO_Notify_REFCOUNTABLE_GUARD_T_H */
