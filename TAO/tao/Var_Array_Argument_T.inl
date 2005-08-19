// -*- C++ -*-
//
// $Id$

template<typename S,
         typename S_slice,
         typename S_forany,
         typename Insert_Policy>
ACE_INLINE
TAO::In_Var_Array_Argument_T<S,S_slice,S_forany,Insert_Policy>::
In_Var_Array_Argument_T (const S_slice * x)
  : x_ (const_cast<S_slice *> (x))
{
}

template<typename S,
         typename S_slice,
         typename S_forany,
         typename Insert_Policy>
ACE_INLINE
S_slice const *
TAO::In_Var_Array_Argument_T<S,S_slice,S_forany,Insert_Policy>::arg (void) const
{
  return this->x_.in ();
}

// ==========================================================================

template<typename S,
         typename S_slice,
         typename S_forany,
         typename Insert_Policy>
ACE_INLINE
TAO::Inout_Var_Array_Argument_T<S,S_slice,S_forany,Insert_Policy>::
Inout_Var_Array_Argument_T (S_slice  *&x)
  : x_ (x)
{
}

template<typename S,
         typename S_slice,
         typename S_forany,
         typename Insert_Policy>
ACE_INLINE
S_slice *
TAO::Inout_Var_Array_Argument_T<S,S_slice,S_forany,Insert_Policy>::arg (void)
{
  return this->x_.inout ();
}

// ==========================================================================

template<typename S,
         typename S_slice,
         typename S_var,
         typename S_out,
         typename S_forany,
         typename S_tag,
         typename Insert_Policy>
ACE_INLINE
TAO::Out_Var_Array_Argument_T<S,S_slice,S_var,S_out,S_forany,S_tag,Insert_Policy>::
Out_Var_Array_Argument_T (S_out x)
  : x_ (x.ptr ())
{
}

template<typename S,
         typename S_slice,
         typename S_var,
         typename S_out,
         typename S_forany,
         typename S_tag,
         typename Insert_Policy>
ACE_INLINE
S_slice *&
TAO::Out_Var_Array_Argument_T<S,S_slice,S_var,S_out,S_forany,S_tag,Insert_Policy>::arg (void)
{
  return this->x_;
}

// ==========================================================================

template<typename S,
         typename S_slice,
         typename S_var,
         typename S_forany,
         typename S_tag,
         typename Insert_Policy>
ACE_INLINE
TAO::Ret_Var_Array_Argument_T<S,S_slice,S_var,S_forany,S_tag,Insert_Policy>::
Ret_Var_Array_Argument_T (void)
{}

template<typename S,
         typename S_slice,
         typename S_var,
         typename S_forany,
         typename S_tag,
         typename Insert_Policy>
ACE_INLINE
S_slice *&
TAO::Ret_Var_Array_Argument_T<S,S_slice,S_var,S_forany,S_tag,Insert_Policy>::arg (void)
{
  return this->x_.out ();
}

template<typename S,
         typename S_slice,
         typename S_var,
         typename S_forany,
         typename S_tag,
         typename Insert_Policy>
ACE_INLINE
S_slice *
TAO::Ret_Var_Array_Argument_T<S,S_slice,S_var,S_forany,S_tag,Insert_Policy>::excp (void)
{
  return this->x_.ptr ();
}

template<typename S,
         typename S_slice,
         typename S_var,
         typename S_forany,
         typename S_tag,
         typename Insert_Policy>
ACE_INLINE
S_slice *
TAO::Ret_Var_Array_Argument_T<S,S_slice,S_var,S_forany,S_tag,Insert_Policy>::retn (void)
{
  return this->x_._retn ();
}
