#include "Environment.h"
#include "ORB_Core.h"
#include "SystemException.h"
#include "default_environment.h"

#include "ace/OS_NS_string.h"

#if !defined (__ACE_INLINE__)
# include "tao/Environment.i"
#endif /* __ACE_INLINE__ */


ACE_RCSID (tao,
           Environment,
           "$Id$")


CORBA::Environment::Environment (void)
  : exception_ (0)
  , previous_ (0)
{
}

CORBA::Environment::Environment (const CORBA::Environment& rhs)
  : exception_ (0)
  , previous_ (0)
{
  if (rhs.exception_)
    this->exception_ = rhs.exception_->_tao_duplicate ();
}

CORBA::Environment::Environment (TAO_ORB_Core* orb_core)
  : exception_ (0)
  , previous_ (orb_core->default_environment ())
{
  orb_core->default_environment (this);
}

CORBA::Environment&
CORBA::Environment::operator= (const CORBA::Environment& rhs)
{
  CORBA::Environment tmp (rhs);
  {
    CORBA::Exception *tmp_ex = this->exception_;
    this->exception_ = tmp.exception_;
    tmp.exception_ = tmp_ex;
  }
  {
    CORBA::Environment *tmp_env = this->previous_;
    this->previous_ = rhs.previous_;
    tmp.previous_ = tmp_env;
  }
  return *this;
}

CORBA::Environment::~Environment (void)
{
  this->clear ();

  // If previous is 0 then this is the first Environment, allocated
  // with the ORB, it shouldn't try to pop because the ORB is beign
  // destroyed also.
  if (this->previous_ != 0)
    TAO_ORB_Core_instance ()->default_environment (this->previous_);
}

void
CORBA::Environment::exception (CORBA::Exception *ex)
{
  // @@ This does not look right, setting the exception to the
  //    contained exception is a bug,  the application is only
  //    supposed to pass in a pointer to an exception that it (the
  //    application) owns, however, if we contain the exception then
  //    *WE* own it.
  //    Normally I (coryan) would remove code like this, but I feel
  //    that it is a typical example of defensive programming for the
  //    *BAD*, i.e. we are not helping the application to get better
  //    and only making the ORB bigger and slower.
#if 0
  if (ex != this->exception_)
    {
      this->clear ();
    }
#else
  ACE_ASSERT (ex != this->exception_);
  this->clear ();
#endif /* 0 */

  this->exception_ = ex;

#if defined (TAO_HAS_EXCEPTIONS)
  if (this->exception_ != 0)
    this->exception_->_raise ();
#endif /* TAO_HAS_EXCEPTIONS */
}

void
CORBA::Environment::clear (void)
{
  delete this->exception_;
  this->exception_ = 0;
}

CORBA::Environment&
CORBA::Environment::default_environment ()
{
#if defined (TAO_HAS_EXCEPTIONS)
  //
  // If we are using native C++ exceptions the user is *not* supposed
  // to clear the environment every time she calls into TAO.  In fact
  // the user is not supposed to use the environment at all!
  //
  // But TAO is using the default environment internally, thus
  // somebody has to clear it. Since TAO passes the environment around
  // this function should only be called when going from the user code
  // into TAO's code.
  //
  // This is not an issue when using the alternative C++ mapping (with
  // the Environment argument) because then the user is supposed to
  // clear the environment before calling into the ORB.
  //
  TAO_ORB_Core_instance ()->default_environment ()->clear ();
#endif /* TAO_HAS_EXCEPTIONS */

  return TAO_default_environment ();;
}

// Convenience -- say if the exception is a system exception or not.

int
CORBA::Environment::exception_type (void) const
{
  // @@ Carlos, is this stuff that's properly "transformed" for EBCDIC
  //    platforms?!
  // @@ Doug: Yes, they are used to compare against the _id() of the
  //    exception, which should have been mappend to the native
  //    codeset.  Notice the "should" we haven't tried that stuff yet,
  //    and i find it hard to keep track of all the transformations
  //    going on, specially for the TypeCodes that are generated by
  //    the IDL compiler vs. the ones hard-coded in
  //    $TAO_ROOT/tao/Typecode_Constants.cpp

  static char sysex_prefix [] = "IDL:omg.org/CORBA/";
  static char typecode_extra [] = "TypeCode/";

  if (!this->exception_)
    {
      return CORBA::NO_EXCEPTION;
    }

  // All exceptions currently (CORBA 2.0) defined in the CORBA scope
  // are system exceptions ... except for a couple that are related to
  // TypeCodes.

  const char *id = this->exception_->_rep_id ();

  if ((ACE_OS::strncmp (id,
                        sysex_prefix,
                        sizeof sysex_prefix - 1) == 0
       && ACE_OS::strncmp (id + sizeof sysex_prefix - 1,
                           typecode_extra,
                           sizeof typecode_extra - 1) != 0))
    return CORBA::SYSTEM_EXCEPTION;
  else
    return CORBA::USER_EXCEPTION;
}

const char*
CORBA::Environment::exception_id (void) const
{
  if (this->exception_ == 0)
    return 0;

  return this->exception_->_rep_id ();
}

// Diagnostic utility routine: describe the exception onto the
// standard I/O stream passed as a parameter.

void
CORBA::Environment::print_exception (const char *info,
                                     FILE *) const
{
  if (this->exception_)
    {
      const char *id = this->exception_->_rep_id ();

      ACE_DEBUG ((LM_ERROR,
                  ACE_TEXT ("TAO: (%P|%t) EXCEPTION, %s\n"),
                  ACE_TEXT_CHAR_TO_TCHAR (info)));

      CORBA::SystemException *x2 =
        CORBA::SystemException::_downcast (this->exception_);

      if (x2 != 0)
        x2->_tao_print_system_exception ();
      else
        // @@ we can use the exception's typecode to dump all the data
        // held within it ...

        ACE_DEBUG ((LM_ERROR,
                    ACE_TEXT ("TAO: (%P|%t) user exception, ID '%s'\n"),
                    ACE_TEXT_CHAR_TO_TCHAR (id)));
    }
  else
    ACE_DEBUG ((LM_ERROR,
                ACE_TEXT ("TAO: (%P|%t) no exception, %s\n"), ACE_TEXT_CHAR_TO_TCHAR (info)));
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class TAO_Pseudo_Var_T<CORBA::Environment>;
  template class TAO_Pseudo_Out_T<CORBA::Environment, CORBA::Environment_var>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate TAO_Pseudo_Var_T<CORBA::Environment>
# pragma instantiate TAO_Pseudo_Out_T<CORBA::Environment, CORBA::Environment_var>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
