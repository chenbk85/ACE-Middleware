// $Id$

#include "Any_SystemException.h"
#include "Any_Unknown_IDL_Type.h"
#include "CDR.h"
#include "Exception.h"
#include "Environment.h"
#include "Marshal.h"
#include "CORBA_String.h"
#include "SystemException.h"
#include "Typecode.h"

#include "ace/Auto_Ptr.h"
#include "ace/CORBA_macros.h"
#include "ace/Auto_Ptr.h"


ACE_RCSID (tao,
           Any_SystemException,
           "$Id$")


TAO::Any_SystemException::Any_SystemException (_tao_destructor destructor,
                                               CORBA::TypeCode_ptr tc,
                                               CORBA::SystemException * const val)
  : Any_Impl (destructor,
              tc),
    value_ (val)
{
}

TAO::Any_SystemException::Any_SystemException (_tao_destructor destructor,
                                               CORBA::TypeCode_ptr tc,
                                               const CORBA::SystemException & val)
  : Any_Impl (destructor,
              tc)
{
 this->value_ =
   dynamic_cast <CORBA::SystemException *> (val._tao_duplicate ());
}

TAO::Any_SystemException::Any_SystemException (CORBA::TypeCode_ptr tc)
  : Any_Impl (0,
              tc)
{
}

TAO::Any_SystemException::~Any_SystemException (void)
{
}

void
TAO::Any_SystemException::insert (CORBA::Any & any,
                                  _tao_destructor destructor,
                                  CORBA::TypeCode_ptr tc,
                                  CORBA::SystemException * const value)
{
  Any_SystemException *new_impl = 0;
  ACE_NEW (new_impl,
           Any_SystemException (destructor,
                                tc,
                                value));
  any.replace (new_impl);
}

void
TAO::Any_SystemException::insert_copy (CORBA::Any & any,
                                       _tao_destructor destructor,
                                       CORBA::TypeCode_ptr tc,
                                       const CORBA::SystemException & value)
{
  Any_SystemException *new_impl = 0;
  ACE_NEW (new_impl,
           Any_SystemException (destructor,
                                tc,
                                value));
  any.replace (new_impl);
}

CORBA::Boolean
TAO::Any_SystemException::extract (const CORBA::Any & any,
                                   _tao_destructor destructor,
                                   CORBA::TypeCode_ptr tc,
                                   const CORBA::SystemException *& _tao_elem,
                                   TAO::excp_factory f)
{
  _tao_elem = 0;

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
          TAO::Any_SystemException *narrow_impl =
            dynamic_cast <TAO::Any_SystemException *> (impl);

          if (narrow_impl == 0)
            {
              return 0;
            }

          _tao_elem = narrow_impl->value_;
          return 1;
        }

      CORBA::SystemException *empty_value =  (*f) ();

      TAO::Any_SystemException *replacement = 0;
      ACE_NEW_RETURN (replacement,
                      TAO::Any_SystemException (destructor,
                                                any_tc,
                                                empty_value),
                      0);

      auto_ptr<TAO::Any_SystemException > replacement_safety (replacement);

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
    }
  ACE_CATCHANY
    {
    }
  ACE_ENDTRY;

  return 0;
}

void
TAO::Any_SystemException::free_value (void)
{
  if (this->value_destructor_ != 0)
    {
      (*this->value_destructor_) (this->value_);
      this->value_destructor_ = 0;
    }

  this->value_ = 0;
}

const void *
TAO::Any_SystemException::value (void) const
{
  return this->value_;
}

CORBA::Boolean
TAO::Any_SystemException::marshal_value (TAO_OutputCDR &cdr)
{
  ACE_TRY_NEW_ENV
    {
      this->value_->_tao_encode (cdr
                                 ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      return 1;
    }
  ACE_CATCHANY
    {
    }
  ACE_ENDTRY;
  return 0;
}

CORBA::Boolean
TAO::Any_SystemException::demarshal_value (TAO_InputCDR &cdr)
{
  ACE_TRY_NEW_ENV
    {
      this->value_->_tao_decode (cdr
                                 ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      return 1;
    }
  ACE_CATCHANY
    {
    }
  ACE_ENDTRY;
  return 0;
}
