// -*- C++ -*-
//
// $Id$

template <typename DISCRIMINATOR_TYPE, typename STRING_TYPE>
TAO::TypeCode::Non_Default_Case<DISCRIMINATOR_TYPE,
                                STRING_TYPE>::Non_Default_Case (
  DISCRIMINATOR_TYPE member_label,
  char const * member_name,
  CORBA::TypeCode_ptr const * member_type)
  : Case<STRING_TYPE> (member_name, member_type)
  , label_ (member_label)
{
}
