// $Id$

#ifndef TAO_TYPECODE_CASE_ENUM_T_CPP
#define TAO_TYPECODE_CASE_ENUM_T_CPP

#include "tao/AnyTypeCode/Any_Unknown_IDL_Type.h"
#include "TypeCode_Case_T.h"

#include "tao/CDR.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/SystemException.h"

#ifndef __ACE_INLINE__
# include "tao/AnyTypeCode/TypeCode_Case_Enum_T.inl"
#endif /* __ACE_INLINE__ */

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// ----------------------------------------------------------------


template <typename StringType,
          typename TypeCodeType>
TAO::TypeCode::Case<StringType, TypeCodeType> *
TAO::TypeCode::Case_Enum_T<StringType,
                           TypeCodeType>::clone (void) const
{
  Case<StringType, TypeCodeType> * p = 0;

  typedef Case_Enum_T<StringType,
                      TypeCodeType> case_type;

  // The compiler generated memberwise copy constructor is sufficient.
  ACE_NEW_RETURN (p,
                  case_type (*this),
                  p);

  return p;
}

template <typename StringType,
          typename TypeCodeType>
bool
TAO::TypeCode::Case_Enum_T<StringType,
                           TypeCodeType>::marshal_label (TAO_OutputCDR & cdr) const
{
  return
    (cdr << this->label_);
}

template <typename StringType,
          typename TypeCodeType>
bool
TAO::TypeCode::Case_Enum_T<StringType,
                           TypeCodeType>::equal_label (::CORBA::ULong index,
                                                       ::CORBA::TypeCode_ptr tc
                                                       ACE_ENV_ARG_DECL) const
{
  CORBA::Any_var const any = tc->member_label (index
                                               ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (false);

  // The equality operator == below is guaranteed to be defined for
  // the discriminator type since an IDL union discriminator type must
  // be any of the following: (1) an integer, (2) a character, (3) a
  // boolean, or (4) an enumeration.

  CORBA::ULong tc_label;
  if ((any.in () >>= tc_label)
      && this->label_ == tc_label)
    {
      return true;
    }

  return false;
}

template <typename StringType,
          typename TypeCodeType>
CORBA::Any *
TAO::TypeCode::Case_Enum_T<StringType,
                           TypeCodeType>::label (ACE_ENV_SINGLE_ARG_DECL) const
{
    TAO_OutputCDR out_cdr;

    out_cdr.write_ulong (this->label_);

    CORBA::Any *retval = 0;
    ACE_NEW_THROW_EX (retval,
                        CORBA::Any,
                        CORBA::NO_MEMORY ());
    ACE_CHECK_RETURN (0);

    TAO_InputCDR in_cdr (out_cdr);
    TAO::Unknown_IDL_Type *unk = 0;
    ACE_NEW_THROW_EX (unk,
                      TAO::Unknown_IDL_Type (this->discriminator_tc_.in (),
                                             in_cdr),
                      CORBA::NO_MEMORY ());
    ACE_CHECK_RETURN (0);

    CORBA::Any_var safe_value (retval);

    retval->replace (unk);

    return safe_value._retn ();
}

TAO_END_VERSIONED_NAMESPACE_DECL

#endif  /* TAO_TYPECODE_CASE_T_CPP */
