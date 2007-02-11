// $Id$

#include "tao/Buffering_Constraint_Policy.h"

#if (TAO_HAS_BUFFERING_CONSTRAINT_POLICY == 1)

#include "tao/TAOC.h"
#include "tao/SystemException.h"
#include "ace/CORBA_macros.h"

ACE_RCSID (tao,
           Buffering_Constraint_Policy,
           "$Id$")

#if ! defined (__ACE_INLINE__)
#include "tao/Buffering_Constraint_Policy.inl"
#endif /* __ACE_INLINE__ */

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Buffering_Constraint_Policy::TAO_Buffering_Constraint_Policy (const TAO::BufferingConstraint &buffering_constraint)
  : ::CORBA::Object ()
  , ::CORBA::Policy ()
  , ::CORBA::LocalObject ()
  , TAO::BufferingConstraintPolicy ()
  , TAO_Local_RefCounted_Object ()
  , buffering_constraint_ (buffering_constraint)
{
}

TAO_Buffering_Constraint_Policy::TAO_Buffering_Constraint_Policy (const TAO_Buffering_Constraint_Policy &rhs)

  : ::CORBA::Object ()
  , ::CORBA::Policy ()
  , ::CORBA::LocalObject ()
  , TAO::BufferingConstraintPolicy ()
  , TAO_Local_RefCounted_Object ()
  , buffering_constraint_ (rhs.buffering_constraint_)
{
}

CORBA::PolicyType
TAO_Buffering_Constraint_Policy::policy_type (void)
{
  return TAO::BUFFERING_CONSTRAINT_POLICY_TYPE;
}

TAO_Buffering_Constraint_Policy *
TAO_Buffering_Constraint_Policy::clone (void) const
{
  TAO_Buffering_Constraint_Policy *copy = 0;
  ACE_NEW_RETURN (copy,
                  TAO_Buffering_Constraint_Policy (*this),
                  0);
  return copy;
}

TAO::BufferingConstraint
TAO_Buffering_Constraint_Policy::buffering_constraint (void)
{
  return this->buffering_constraint_;
}

CORBA::Policy_ptr
TAO_Buffering_Constraint_Policy::copy (void)
{
  TAO_Buffering_Constraint_Policy* servant = 0;
  ACE_NEW_THROW_EX (servant,
                    TAO_Buffering_Constraint_Policy (*this),
                    CORBA::NO_MEMORY ());

  return servant;
}

void
TAO_Buffering_Constraint_Policy::destroy (void)
{
}

TAO_Cached_Policy_Type
TAO_Buffering_Constraint_Policy::_tao_cached_type (void) const
{
  return TAO_CACHED_POLICY_BUFFERING_CONSTRAINT;
}

TAO_END_VERSIONED_NAMESPACE_DECL

#endif /* TAO_HAS_BUFFERING_CONSTRAINT_POLICY == 1 */
