// $Id$

#ifndef TAO_ANY_BASIC_IMPL_T_C
#define TAO_ANY_BASIC_IMPL_T_C

#include "tao/Any_Basic_Impl_T.h"
#include "tao/Any.h"
#include "tao/Marshal.h"
#include "tao/Environment.h"
#include "tao/SystemException.h"
#include "tao/CDR.h"

#include "ace/CORBA_macros.h"
#include "ace/Auto_Ptr.h"

#if !defined (__ACE_INLINE__)
# include "tao/Any_Basic_Impl_T.inl"
#endif /* ! __ACE_INLINE__ */

ACE_RCSID (tao,
           Any_Basic_Impl_T,
           "$Id$")


template<typename T>
TAO::Any_Basic_Impl_T<T>::Any_Basic_Impl_T (CORBA::TypeCode_ptr tc,
                                            const T & val)
  : Any_Impl (0,
              tc),
    value_ (val)
{
}

template<typename T>
TAO::Any_Basic_Impl_T<T>::~Any_Basic_Impl_T (void)
{
}

template<typename T>
void
TAO::Any_Basic_Impl_T<T>::insert (CORBA::Any & any,
                                  CORBA::TypeCode_ptr tc,
                                  const T & value)
{
  Any_Basic_Impl_T<T> *new_impl = 0;
  ACE_NEW (new_impl,
           Any_Basic_Impl_T (tc,
                             value));
  any.replace (new_impl);
}

template<typename T>
CORBA::Boolean
TAO::Any_Basic_Impl_T<T>::extract (const CORBA::Any & any,
                                   CORBA::TypeCode_ptr tc,
                                   T & _tao_elem)
{
  ACE_TRY_NEW_ENV
    {
      CORBA::TypeCode_ptr any_tc = any._tao_get_typecode ();
      CORBA::Boolean _tao_equiv = any_tc->equivalent (tc
                                                      ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (_tao_equiv == 0)
        {
          return 0;
        }

      TAO::Any_Impl *impl = any.impl ();

      if (!impl->encoded ())
        {
          TAO::Any_Basic_Impl_T<T> *narrow_impl =
            dynamic_cast <TAO::Any_Basic_Impl_T<T> *> (impl);

          if (narrow_impl == 0)
            {
              return 0;
            }

          _tao_elem = narrow_impl->value_;
          return 1;
        }

      TAO::Any_Basic_Impl_T<T> *replacement =
        TAO::Any_Basic_Impl_T<T>::create_empty (any_tc);

      auto_ptr<TAO::Any_Basic_Impl_T<T> > replacement_safety (replacement);

      // We know this will work since the unencoded case is covered above.  
      TAO::Unknown_IDL_Type *unk =
        dynamic_cast<TAO::Unknown_IDL_Type *> (impl);

      // We don't want the rd_ptr of unk to move, in case it is
      // shared by another Any. This copies the state, not the buffer.
      TAO_InputCDR for_reading (unk->_tao_get_cdr ());

      CORBA::Boolean good_decode =
        replacement->demarshal_value (for_reading);

      if (good_decode)
        {
          _tao_elem = replacement->value_;
          const_cast<CORBA::Any &> (any).replace (replacement);
          replacement_safety.release ();
          return 1;
        }

      // Duplicated by Any_Impl base class constructor.
      CORBA::release (any_tc);
    }
  ACE_CATCHANY
    {
    }
  ACE_ENDTRY;

  return 0;
}

template<typename T>
TAO::Any_Basic_Impl_T<T> *
TAO::Any_Basic_Impl_T<T>::create_empty (CORBA::TypeCode_ptr tc)
{
  TAO::Any_Basic_Impl_T<T> * retval = 0;
  ACE_NEW_RETURN (retval,
                  TAO::Any_Basic_Impl_T<T> (tc,
                                            static_cast<T> (0)),
                  0);
  return retval;
}

template<typename T>
void
TAO::Any_Basic_Impl_T<T>::_tao_decode (TAO_InputCDR &cdr
                                       ACE_ENV_ARG_DECL)
{
  if (! this->demarshal_value (cdr))
    {
      ACE_THROW (CORBA::MARSHAL ());
    }
}

#endif /* TAO_ANY_BASIC_IMPL_T_C */
