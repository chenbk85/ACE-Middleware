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
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html


// TAO_IDL - Generated from
// be/be_codegen.cpp:617

#ifndef _TAO_IDL_TESTS_CPP_
#define _TAO_IDL_TESTS_CPP_


#include "TestS.h"
#include "tao/PortableServer/Object_Adapter.h"
#include "tao/PortableServer/Operation_Table.h"
#include "tao/TAO_Server_Request.h"
#include "tao/Argument.h"
#include "tao/ORB_Core.h"
#include "tao/Profile.h"
#include "tao/Stub.h"
#include "tao/IFR_Client_Adapter.h"
#include "tao/PortableInterceptor.h"
#if TAO_HAS_INTERCEPTORS == 1
#include "tao/RequestInfo_Util.h"
#include "tao/PICurrent.h"
#include "tao/PortableServer/ServerRequestInfo.h"
#include "tao/PortableServer/ServerInterceptorAdapter.h"
#endif  /* TAO_HAS_INTERCEPTORS == 1 */

#include "ace/Dynamic_Service.h"
#include "tao/Basic_Arguments.h"
#include "tao/UB_String_Arguments.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "TestS.i"
#endif /* !defined INLINE */



// TAO_IDL - Generated from
// be/be_interface.cpp:1248

class TAO_Test_Hello_Perfect_Hash_OpTable : public TAO_Perfect_Hash_OpTable
{
private:
  unsigned int hash (const char *str, unsigned int len);
public:
 const TAO_operation_db_entry * lookup (const char *str, unsigned int len);
};

/* C++ code produced by gperf version 2.8 (ACE version) */
/* Command-line: /project/tangotmp/bala/work/ACE+TAO/refactor/ACE_wrappers/bin/gperf -m -M -J -c -C -D -E -T -f 0 -F 0 -a -o -t -p -K opname_ -L C++ -Z TAO_Test_Hello_Perfect_Hash_OpTable -N lookup  */
unsigned int
TAO_Test_Hello_Perfect_Hash_OpTable::hash (const char *str, unsigned int len)
{
  static const unsigned char asso_values[] =
    {
#if defined (ACE_MVS)
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21,  0,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21,  0,
     21, 21, 21,  5, 21,  5, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21,  0,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21,  0,  0, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21,
#else
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
     21, 21, 21, 21, 21,  0, 21,  0, 21, 21,
     21,  5, 21,  5, 21, 21, 21, 21, 21, 21,
      0, 21, 21, 21, 21,  0,  0, 21, 21, 21,
     21, 21, 21, 21, 21, 21, 21, 21,
#endif /* ACE_MVS */
    };
  return len + asso_values[(int) str[len - 1]] + asso_values[(int) str[0]];
}

const class TAO_operation_db_entry *
TAO_Test_Hello_Perfect_Hash_OpTable::lookup (const char *str, unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 6,
      MIN_WORD_LENGTH = 5,
      MAX_WORD_LENGTH = 13,
      MIN_HASH_VALUE = 5,
      MAX_HASH_VALUE = 20,
      HASH_VALUE_RANGE = 16,
      DUPLICATES = 0,
      WORDLIST_SIZE = 11
    };

  static const class TAO_operation_db_entry  wordlist[] =
    {
      {"",0},{"",0},{"",0},{"",0},{"",0},
      {"_is_a",  &POA_Test::Hello::_is_a_skel},
      {"",0},{"",0},
      {"shutdown",      &POA_Test::Hello::shutdown_skel},
      {"",0},
      {"_component",  &POA_Test::Hello::_component_skel},
      {"",0},{"",0},
      {"_non_existent",  &POA_Test::Hello::_non_existent_skel},
      {"",0},
      {"_interface",  &POA_Test::Hello::_interface_skel},
      {"",0},{"",0},{"",0},{"",0},
      {"get_string",    &POA_Test::Hello::get_string_skel},
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= MIN_HASH_VALUE)
        {
          const char *s = wordlist[key].opname_;

          if (*str == *s && !strncmp (str + 1, s + 1, len - 1))
            return &wordlist[key];
        }
    }
  return 0;
}
static TAO_Test_Hello_Perfect_Hash_OpTable tao_Test_Hello_optable;

// TAO_IDL - Generated from
// be/be_visitor_interface/interceptors_ss.cpp:52

///////////////////////////////////////////////////////////////////////
//            Strategized Proxy Broker Implementation
//

// TAO_IDL - Generated from
// be/be_visitor_interface/strategized_proxy_broker_ss.cpp:40

// Factory function Implementation.
POA_Test::_TAO_Hello_Strategized_Collocation_Proxy_Broker *
POA_Test::_TAO_Hello_Strategized_Collocation_Proxy_Broker::the_TAO_Hello_Strategized_Collocation_Proxy_Broker (void)
{
  static POA_Test::_TAO_Hello_Strategized_Collocation_Proxy_Broker strategized_proxy_broker;
  return &strategized_proxy_broker;
}

POA_Test::_TAO_Hello_Strategized_Collocation_Proxy_Broker::_TAO_Hello_Strategized_Collocation_Proxy_Broker (void)
{
}

POA_Test::_TAO_Hello_Strategized_Collocation_Proxy_Broker::~_TAO_Hello_Strategized_Collocation_Proxy_Broker (void)
{

}

TAO::Collocation_Strategy
POA_Test::_TAO_Hello_Strategized_Collocation_Proxy_Broker::get_strategy (
    CORBA::Object *obj
    ACE_ENV_ARG_DECL)
{
  TAO::Collocation_Strategy strategy =
    TAO_ORB_Core::collocation_strategy_new (obj ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (TAO::TAO_CS_REMOTE_STRATEGY);

  return  strategy;
}

void
POA_Test::_TAO_Hello_Strategized_Collocation_Proxy_Broker::dispatch (
    CORBA::Object *obj,
    CORBA::Object_out forward_obj,
    TAO::Argument **arg,
    int num_args,
    const char *op,
    int op_len,
    TAO::Collocation_Strategy strategy
    ACE_ENV_ARG_DECL)
{

  ACE_TRY
    {
      switch ((int) strategy)
        {
        case TAO::TAO_CS_THRU_POA_STRATEGY:
          // Here is where we need table lookups
          if (ACE_OS::strcmp (op,
                              "get_string") == 0)
            {
              POA_Test::_TAO_Hello_ThruPOA_Proxy_Impl::get_string (obj,
                                                                   forward_obj,
                                                                   arg,
                                                                   num_args
                                                                   ACE_ENV_ARG_DECL);
              ACE_TRY_CHECK;

            }
          else if (ACE_OS::strcmp (op,
                                   "shutdown") == 0)
            {
              POA_Test::_TAO_Hello_ThruPOA_Proxy_Impl::shutdown (obj,
                                                                 forward_obj,
                                                                 arg,
                                                                 num_args
                                                                 ACE_ENV_ARG_DECL);
              ACE_TRY_CHECK;
            }
          break;
        default:
          ACE_THROW (CORBA::INTERNAL ());
        }
    }
#if (TAO_HAS_MINIMUM_CORBA == 0)
  ACE_CATCH (PortableServer::ForwardRequest, forward_request)
    {
      forward_obj =
        CORBA::Object::_duplicate (forward_request.forward_reference.in ());
      return;
    }
#else
  ACE_CATCHANY
    {
      ACE_UNUSED_ARG (forward_obj);
      ACE_RE_THROW;
    }
#endif /* TAO_HAS_MINIMUM_CORBA */
  ACE_ENDTRY;
}

//
//        End Strategized Proxy Broker Implementation
///////////////////////////////////////////////////////////////////////

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ss.cpp:598

TAO::Collocation_Proxy_Broker *
Test__TAO_Hello_Collocation_Proxy_Broker_Factory_function (CORBA::Object_ptr )
{
  return ::POA_Test::_TAO_Hello_Strategized_Collocation_Proxy_Broker::the_TAO_Hello_Strategized_Collocation_Proxy_Broker();
}

int
Test__TAO_Hello_Collocation_Proxy_Broker_Factory_Initializer (size_t)
{
  Test__TAO_Hello_Collocation_Proxy_Broker_Factory_function_pointer =
    Test__TAO_Hello_Collocation_Proxy_Broker_Factory_function;

  return 0;
}

static int Test__TAO_Hello_Collocation_Proxy_Broker_Stub_Factory_Initializer_Scarecrow =
  Test__TAO_Hello_Collocation_Proxy_Broker_Factory_Initializer (ACE_reinterpret_cast (size_t, Test__TAO_Hello_Collocation_Proxy_Broker_Factory_Initializer));


///////////////////////////////////////////////////////////////////////
//                 ThruPOA Proxy  Implementation
//

// TAO_IDL - Generated from
// be/be_visitor_interface/thru_poa_proxy_impl_ss.cpp:37

POA_Test::_TAO_Hello_ThruPOA_Proxy_Impl::_TAO_Hello_ThruPOA_Proxy_Impl (void)
{}

// ThruPOA Implementation of the IDL interface methods

// TAO_IDL - Generated from
// be/be_visitor_operation/thru_poa_proxy_impl_ss.cpp:67

/*static*/void
POA_Test::_TAO_Hello_ThruPOA_Proxy_Impl::get_string (
     CORBA::Object *obj,
     CORBA::Object_out forward,
     TAO::Argument **arg,
     int num_args
     ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  TAO_Object_Adapter::Servant_Upcall servant_upcall (
      obj->_stubobj ()->servant_orb_var ()->orb_core ()
      );

  servant_upcall.prepare_for_upcall (
      obj->_stubobj ()->object_key (),
      "get_string",
      forward
      ACE_ENV_ARG_PARAMETER
      );
  ACE_CHECK;

  servant_upcall.pre_invoke_collocated_request (
      ACE_ENV_SINGLE_ARG_PARAMETER
      );
  ACE_CHECK;

  ((TAO::Arg_Traits<CORBA::Char *>::stub_ret_val *)arg[0])->arg ()
    = ACE_reinterpret_cast (
          POA_Test::Hello_ptr,
          servant_upcall.servant ()->_downcast (
                                                "IDL:Test/Hello:1.0"
                                                )
          )->get_string (
                         ACE_ENV_SINGLE_ARG_PARAMETER
                         );

  ACE_CHECK;
}

// TAO_IDL - Generated from
// be/be_visitor_operation/thru_poa_proxy_impl_ss.cpp:67

/*static*/void
POA_Test::_TAO_Hello_ThruPOA_Proxy_Impl::shutdown (
   CORBA::Object *obj,
   CORBA::Object_out forward,
   TAO::Argument **arg,
   int num_args
   ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{

   TAO_Object_Adapter::Servant_Upcall servant_upcall (
       obj->_stubobj ()->servant_orb_var ()->orb_core ()
    );
  servant_upcall.prepare_for_upcall (
      obj->_stubobj ()->object_key (),
      "shutdown",
      forward
      ACE_ENV_ARG_PARAMETER
    );
  ACE_CHECK;

  servant_upcall.pre_invoke_collocated_request (
      ACE_ENV_SINGLE_ARG_PARAMETER
    );
  ACE_CHECK;

  ACE_reinterpret_cast (
      POA_Test::Hello_ptr,
      servant_upcall.servant ()->_downcast (
          "IDL:Test/Hello:1.0"
        )
    )->shutdown (

        ACE_ENV_SINGLE_ARG_PARAMETER
      );
  ACE_CHECK;
}

//
//           End ThruPOA Proxy Implementation
///////////////////////////////////////////////////////////////////////

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ss.cpp:98

POA_Test::Hello::Hello (void)
{
  this->optable_ = &tao_Test_Hello_optable;
}

POA_Test::Hello::Hello (const Hello& rhs)
  : TAO_Abstract_ServantBase (rhs),
    TAO_ServantBase (rhs)
{
}

POA_Test::Hello::~Hello (void)
{
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_ss.cpp:100

void POA_Test::Hello::get_string_skel (
    TAO_ServerRequest &_tao_server_request,
    void *_tao_servant,
    void *_tao_servant_upcall
    ACE_ENV_ARG_DECL
  )
{
  POA_Test::Hello *_tao_impl =
    ACE_static_cast (
        POA_Test::Hello *,
        _tao_servant
      );
  CORBA::String_var _tao_retval;

            _tao_retval =
            _tao_impl->get_string (

                ACE_ENV_SINGLE_ARG_PARAMETER
              );
            TAO_INTERCEPTOR_CHECK;

  _tao_server_request.init_reply ();

  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();

  if (!(
      (_tao_out << _tao_retval.in ())
      ))
      {

        TAO_OutputCDR::throw_skel_exception (errno ACE_ENV_ARG_PARAMETER);
        ACE_CHECK;
      }


  // In case _tao_servant_upcall is not used in this function
  ACE_UNUSED_ARG (_tao_servant_upcall);
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_ss.cpp:100

void POA_Test::Hello::shutdown_skel (
    TAO_ServerRequest &_tao_server_request,
    void *_tao_servant,
    void *_tao_servant_upcall
    ACE_ENV_ARG_DECL
  )
{
  POA_Test::Hello *_tao_impl =
    ACE_static_cast (
        POA_Test::Hello *,
        _tao_servant
      );
  _tao_server_request.argument_flag (0);


            _tao_impl->shutdown (

                ACE_ENV_SINGLE_ARG_PARAMETER
              );
            TAO_INTERCEPTOR_CHECK;

  if (_tao_server_request.response_expected ()
      && !_tao_server_request.sync_with_server ())
    {
      _tao_server_request.init_reply ();
    }

  // In case _tao_servant_upcall is not used in this function
  ACE_UNUSED_ARG (_tao_servant_upcall);
}

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ss.cpp:165

void POA_Test::Hello::_is_a_skel (
    TAO_ServerRequest &_tao_server_request,
    void * _tao_servant,
    void * /* Servant_Upcall */
    ACE_ENV_ARG_DECL
  )
{
  TAO_InputCDR &_tao_in = _tao_server_request.incoming ();
  POA_Test::Hello *_tao_impl = (POA_Test::Hello *) _tao_servant;
  CORBA::Boolean _tao_retval = 0;
  CORBA::String_var value;

  if (!(_tao_in >> value.out ()))
    ACE_THROW (CORBA::MARSHAL ());

  _tao_retval = _tao_impl->_is_a (value.in () ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  _tao_server_request.init_reply ();
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();

  if (!(_tao_out << CORBA::Any::from_boolean (_tao_retval)))
    ACE_THROW (CORBA::MARSHAL ());
}

void POA_Test::Hello::_non_existent_skel (
    TAO_ServerRequest &_tao_server_request,
    void * _tao_servant,
    void * /* Servant_Upcall */
    ACE_ENV_ARG_DECL
  )
{
  POA_Test::Hello *_tao_impl = (POA_Test::Hello *) _tao_servant;
  CORBA::Boolean _tao_retval =
    _tao_impl->_non_existent (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  _tao_server_request.init_reply ();
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();

  if (!(_tao_out << CORBA::Any::from_boolean (_tao_retval)))
    ACE_THROW (CORBA::MARSHAL ());
}

void POA_Test::Hello::_interface_skel (
    TAO_ServerRequest &_tao_server_request,
    void * _tao_servant,
    void * /* Servant_Upcall */
    ACE_ENV_ARG_DECL
  )
{
  POA_Test::Hello *_tao_impl = (POA_Test::Hello *) _tao_servant;
  CORBA::InterfaceDef_ptr _tao_retval = 0;
  CORBA::Boolean _tao_result = 0;

  TAO_IFR_Client_Adapter *_tao_adapter =
    ACE_Dynamic_Service<TAO_IFR_Client_Adapter>::instance (
        TAO_ORB_Core::ifr_client_adapter_name ()
      );

  if (_tao_adapter == 0)
    {
      ACE_THROW (CORBA::INTF_REPOS ());
    }

  ACE_TRY
    {
      _tao_retval =
        _tao_impl->_get_interface (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      _tao_server_request.init_reply ();

      TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();

      _tao_result =
        _tao_adapter->interfacedef_cdr_insert (
            _tao_out,
            _tao_retval
          );
    }
  ACE_CATCHALL
    {
      _tao_adapter->dispose (_tao_retval);
    }
  ACE_ENDTRY;

  if (_tao_result == 0)
    {
      ACE_THROW (CORBA::MARSHAL ());
    }
}

void POA_Test::Hello::_component_skel (
    TAO_ServerRequest &_tao_server_request,
    void * _tao_object_reference,
    void * /* Servant_Upcall */
    ACE_ENV_ARG_DECL
  )
{
  POA_Test::Hello *_tao_impl = (POA_Test::Hello *) _tao_object_reference;
  CORBA::Object_var _tao_retval =
    _tao_impl->_get_component (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  _tao_server_request.init_reply ();
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();

  if (!(_tao_out << _tao_retval._retn ()))
    ACE_THROW (CORBA::MARSHAL ());
}

CORBA::Boolean POA_Test::Hello::_is_a (
    const char* value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:Test/Hello:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:org.omg/CORBA/Object:1.0"
        )
     )
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

void* POA_Test::Hello::_downcast (
    const char* logical_type_id
  )
{
  if (ACE_OS::strcmp (logical_type_id,
                      "IDL:Test/Hello:1.0") == 0)
    {
      return ACE_static_cast (POA_Test::Hello_ptr, this);
    }

  if (ACE_OS::strcmp (logical_type_id,
                      "IDL:omg.org/CORBA/Object:1.0") == 0)
    {
      return ACE_static_cast(PortableServer::Servant, this);
    }

  return 0;
}

const char* POA_Test::Hello::_interface_repository_id (void) const
{
  return "IDL:Test/Hello:1.0";
}

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ss.cpp:533

void POA_Test::Hello::_dispatch (
    TAO_ServerRequest &req,
    void *servant_upcall
    ACE_ENV_ARG_DECL
  )
{
  this->synchronous_upcall_dispatch (req,
                                     servant_upcall,
                                     this
                                     ACE_ENV_ARG_PARAMETER);
}

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ss.cpp:479

Test::Hello *
POA_Test::Hello::_this (ACE_ENV_SINGLE_ARG_DECL)
{
  TAO_Stub *stub = this->_create_stub (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  TAO_Stub_Auto_Ptr safe_stub (stub);
  CORBA::Object_ptr tmp = CORBA::Object::_nil ();

  if (stub->servant_orb_var ()->orb_core ()->optimize_collocation_objects ())
    {
      ACE_NEW_RETURN (
          tmp,
          CORBA::Object (
              stub,
              1,
              this
            ),
          0
        );
    }
  else
    {
      ACE_NEW_RETURN (
          tmp,
          CORBA::Object (
              stub,
              0,
              this
            ),
          0
        );
    }

  CORBA::Object_var obj = tmp;
  (void) safe_stub.release ();
  return ::Test::Hello::_unchecked_narrow (obj.in ());
}
#endif /* ifndef */
