// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be/be_codegen.cpp:986

#include "interop_wchar_i.h"

// Implementation skeleton constructor
interop_WChar_Passer_i::interop_WChar_Passer_i (CORBA::ORB_ptr o,
                                                int verbose)
  : orb_(CORBA::ORB::_duplicate (o)),
    ref_ (verbose)
{
}

// Implementation skeleton destructor
interop_WChar_Passer_i::~interop_WChar_Passer_i (void)
{
}

char *
interop_WChar_Passer_i::orb_name (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC (( CORBA::SystemException ))
{
  return CORBA::string_dup ("TAO");
}

CORBA::Boolean
interop_WChar_Passer_i::wchar_to_server (CORBA::WChar test,
                                         CORBA::Short key
                                         ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC (( CORBA::SystemException ))
{
  return ref_.match_wchar (key,test);
}

CORBA::WChar
interop_WChar_Passer_i::wchar_from_server (CORBA::Short key
                                           ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC (( CORBA::SystemException ))
{
  return ref_.get_wchar (key);
}

CORBA::Boolean
interop_WChar_Passer_i::wstring_to_server (const CORBA::WChar * test,
                                           CORBA::Short key
                                           ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC (( CORBA::SystemException ))
{
  return ref_.match_wstring(key,test);
}

CORBA::WChar *
interop_WChar_Passer_i::wstring_from_server (CORBA::Short key
                                             ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC (( CORBA::SystemException ))
{
  return CORBA::wstring_dup (ref_.get_wstring(key));
}

CORBA::Boolean
interop_WChar_Passer_i::warray_to_server (const interop::warray test,
                                          CORBA::Short key
                                          ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC (( CORBA::SystemException ))
{
  return ref_.match_warray(key,test);
}

interop::warray_slice *
interop_WChar_Passer_i::warray_from_server (CORBA::Short key
                                            ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC (( CORBA::SystemException ))
{
  return interop::warray_dup (ref_.get_warray(key));
}

CORBA::Boolean
interop_WChar_Passer_i::wstruct_to_server (const interop::wstruct & test,
                                           CORBA::Short key
                                           ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( CORBA::SystemException ))
{
  return
    ref_.match_wchar (key,test.st_char) &&
    ref_.match_wstring (key,test.st_string) &&
    ref_.match_warray (key,test.st_array) &&
    this->any_to_server (test.st_any,key ACE_ENV_ARG_PARAMETER);
}

interop::wstruct *
interop_WChar_Passer_i::wstruct_from_server (CORBA::Short key
                                             ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC (( CORBA::SystemException ))
{
  interop::wstruct_var ws = new interop::wstruct ();
  ws->st_char = this->wchar_from_server(key ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);
  ws->st_string = this->wstring_from_server(key ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);
  ref_.assign_warray (key, ws->st_array);
  ws->st_any <<= ref_.get_wstring(key);
  return ws._retn ();
}

CORBA::Boolean
interop_WChar_Passer_i::wstructseq_to_server (const interop::wstructseq & test,
                                              CORBA::Short key
                                              ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC (( CORBA::SystemException ))
{
  CORBA::Boolean result = 1;
  for (CORBA::ULong i = 0; result && i < test.length(); i++)
    {
      result = this->wstruct_to_server(test[i], key);
      ACE_CHECK_RETURN (0);
    }
  return result;
}

interop::wstructseq *
interop_WChar_Passer_i::wstructseq_from_server (CORBA::Short key
                                                ACE_ENV_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC (( CORBA::SystemException ))
{
  interop::wstructseq_var wsListI = new interop::wstructseq();
  wsListI->length(5);

  for (CORBA::ULong i = 0; i < wsListI->length(); i++)
    {
      wsListI[i].st_char = this->wchar_from_server(key ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (interop::wstructseq->nil());
      wsListI[i].st_string = this->wstring_from_server(key ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (interop::wstructseq->nil());
      ref_.assign_warray (key, wsListI[i].st_array);
      wsListI[i].st_any <<= CORBA::wstring_dup(L"");
    }
  return wsListI._retn();
}

CORBA::Boolean
interop_WChar_Passer_i::wunion_to_server (const interop::wunion & test,
                                          CORBA::Short key
                                          ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC (( CORBA::SystemException ))
{
  switch (test._d()) {
  case interop::is_wchar :
    return this->wchar_to_server (test.u_char(),key  ACE_ENV_ARG_PARAMETER);
  case interop::is_wstring :
    return this->wstring_to_server (test.u_string(),key  ACE_ENV_ARG_PARAMETER);
  case interop::is_warray :
    return this->warray_to_server (test.u_array(),key ACE_ENV_ARG_PARAMETER);
  default:
    /*return 0*/;
  }
  return 0;
}

interop::wunion *
interop_WChar_Passer_i::wunion_from_server (CORBA::Short key,
                                            interop::wchar_types type
                                            ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC (( CORBA::SystemException ))
{
  interop::wunion *wu = new interop::wunion ();
  switch (type) {
  case interop::is_wchar :
    wu->u_char (ref_.get_wchar(key));
    break;
  case interop::is_wstring :
    wu->u_string (ref_.get_wstring(key));
    break;
  case interop::is_warray :
    wu->u_array (ref_.get_warray(key));
    break;
  }
  return wu;
}


CORBA::Boolean
interop_WChar_Passer_i::any_to_server (const CORBA::Any &test,
                                       CORBA::Short key
                                       ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC (( CORBA::SystemException ))
{
  CORBA::WChar wc;
  const CORBA::WChar *ws;
  CORBA::WString_var wstr;
  interop::warray_forany forany;

  if (test >>= CORBA::Any::to_wchar(wc))
    {
      return this->wchar_to_server(wc,key ACE_ENV_ARG_PARAMETER);
    }
  else if (test >>= ws)
    {
      return this->wstring_to_server (ws,key ACE_ENV_ARG_PARAMETER);
    }
  else if (test >>= forany)
    {
      return this->warray_to_server (forany.in(),key ACE_ENV_ARG_PARAMETER);
    }
  return 0;
}

CORBA::Any*
interop_WChar_Passer_i::any_from_server (CORBA::Short key,
                                         interop::wchar_types type
                                         ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC (( CORBA::SystemException ))
{
  CORBA::Any *any = new CORBA::Any;
  switch (type) {
  case interop::is_wchar :
    (*any) <<= CORBA::Any::from_wchar(ref_.get_wchar(key));
    break;
  case interop::is_wstring :
    (*any) <<= ref_.get_wstring(key);
    break;
  case interop::is_warray :
    {
      interop::warray_forany forany(ref_.get_warray(key));
      (*any) <<= forany.in();
      break;
    }
  }
  return any;
}

CORBA::Any *
interop_WChar_Passer_i::any_echo (const CORBA::Any &test
                                  ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC (( CORBA::SystemException ))
{
  return new CORBA::Any (test);
}

void
interop_WChar_Passer_i::exception_test ( CORBA::Short key
                                         ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   interop::WChar_Passer::WStringException))
{
  ACE_THROW (interop::WChar_Passer::WStringException(ref_.get_except(key),
                                             this->wchar_from_server(key ACE_ENV_ARG_PARAMETER)));
}

void
interop_WChar_Passer_i::shutdown (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( CORBA::SystemException ))
{
  this->orb_->shutdown(0 ACE_ENV_ARG_PARAMETER);
}
