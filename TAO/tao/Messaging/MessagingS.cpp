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
// be\be_codegen.cpp:609

#ifndef _TAO_IDL_ORIG_MESSAGINGS_CPP_
#define _TAO_IDL_ORIG_MESSAGINGS_CPP_


#include "MessagingS.h"
#include "tao/PortableServer/Servant_Upcall.h"
#include "tao/PortableServer/ForwardRequestC.h"
#include "tao/PortableServer/Operation_Table.h"
#include "tao/TAO_Server_Request.h"
#include "tao/ORB_Core.h"
#include "tao/Profile.h"
#include "tao/Stub.h"
#include "tao/IFR_Client_Adapter.h"
#include "tao/Object_T.h"
#include "tao/Typecode.h"
#include "tao/DynamicC.h"
#include "tao/CDR.h"
#include "tao/PortableInterceptor.h"
#if TAO_HAS_INTERCEPTORS == 1
#include "tao/PortableServer/PICurrent_Guard.h"
#include "tao/PortableServer/ServerRequestInfo.h"
#include "tao/PortableServer/ServerInterceptorAdapter.h"
#include "tao/RequestInfo_Util.h"
#endif  /* TAO_HAS_INTERCEPTORS == 1 */

#include "ace/Dynamic_Service.h"
#include "ace/Malloc_Allocator.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "MessagingS.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:66

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_interface.cpp:1536

class TAO_Messaging_ReplyHandler_Perfect_Hash_OpTable
  : public TAO_Perfect_Hash_OpTable
{
private:
  unsigned int hash (const char *str, unsigned int len);

public:
  const TAO_operation_db_entry * lookup (const char *str, unsigned int len);
};

/* C++ code produced by gperf version 2.8 (ACE version) */
/* Command-line: c:\ace\POArefactor3\ace_wrappers\bin\gperf.exe -m -M -J -c -C -D -E -T -f 0 -F 0,0,0 -a -o -t -p -K opname_ -L C++ -Z TAO_Messaging_ReplyHandler_Perfect_Hash_OpTable -N lookup  */
unsigned int
TAO_Messaging_ReplyHandler_Perfect_Hash_OpTable::hash (const char *str, unsigned int len)
{
  static const unsigned char asso_values[] =
    {
#if defined (ACE_MVS)
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14,  0,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14,  0,
     14, 14, 14,  1, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14,  0, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14,
#else
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14,  0, 14,  0, 14, 14,
     14,  1, 14, 14, 14, 14, 14, 14, 14, 14,
     14, 14, 14, 14, 14, 14,  0, 14, 14, 14,
     14, 14, 14, 14, 14, 14, 14, 14,
#endif /* ACE_MVS */
    };
  return len + asso_values[(int) str[len - 1]] + asso_values[(int) str[0]];
}

const class TAO_operation_db_entry *
TAO_Messaging_ReplyHandler_Perfect_Hash_OpTable::lookup (const char *str, unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 4,
      MIN_WORD_LENGTH = 5,
      MAX_WORD_LENGTH = 13,
      MIN_HASH_VALUE = 5,
      MAX_HASH_VALUE = 13,
      HASH_VALUE_RANGE = 9,
      DUPLICATES = 0,
      WORDLIST_SIZE = 9
    };

  static const class TAO_operation_db_entry  wordlist[] =
    {
      {"",0,0,0},{"",0,0,0},{"",0,0,0},{"",0,0,0},{"",0,0,0},
      {"_is_a", &POA_Messaging::ReplyHandler::_is_a_skel, 0, 0},
      {"",0,0,0},{"",0,0,0},{"",0,0,0},{"",0,0,0},
      {"_component", &POA_Messaging::ReplyHandler::_component_skel, 0, 0},
      {"_interface", &POA_Messaging::ReplyHandler::_interface_skel, 0, 0},
      {"",0,0,0},
      {"_non_existent", &POA_Messaging::ReplyHandler::_non_existent_skel, 0, 0},
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

static TAO_Messaging_ReplyHandler_Perfect_Hash_OpTable tao_Messaging_ReplyHandler_optable;

// TAO_IDL - Generated from
// be\be_visitor_interface/interceptors_ss.cpp:53

#if (TAO_HAS_INTERCEPTORS == 1)

#endif /* TAO_HAS_INTERCEPTORS */

///////////////////////////////////////////////////////////////////////
//            Strategized Proxy Broker Implementation
//

// TAO_IDL - Generated from
// be\be_visitor_interface/strategized_proxy_broker_ss.cpp:40

// Factory function Implementation.
POA_Messaging::_TAO_ReplyHandler_Strategized_Proxy_Broker *
POA_Messaging::_TAO_ReplyHandler_Strategized_Proxy_Broker::the_TAO_ReplyHandler_Strategized_Proxy_Broker (void)
{
  static POA_Messaging::_TAO_ReplyHandler_Strategized_Proxy_Broker
  strategized_proxy_broker;
  
  return &strategized_proxy_broker;
}

POA_Messaging::_TAO_ReplyHandler_Strategized_Proxy_Broker::_TAO_ReplyHandler_Strategized_Proxy_Broker (void)
{
}

POA_Messaging::_TAO_ReplyHandler_Strategized_Proxy_Broker::~_TAO_ReplyHandler_Strategized_Proxy_Broker (void)
{
}

TAO::Collocation_Strategy
POA_Messaging::_TAO_ReplyHandler_Strategized_Proxy_Broker::get_strategy (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO::Collocation_Strategy strategy =
    TAO_ORB_Core::collocation_strategy (obj ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (TAO::TAO_CS_REMOTE_STRATEGY);
  
  return strategy;
}

void
POA_Messaging::_TAO_ReplyHandler_Strategized_Proxy_Broker::dispatch (
    CORBA::Object_ptr obj,
    CORBA::Object_out forward_obj,
    TAO::Argument ** args,
    int num_args,
    const char * op,
    size_t op_len,
    TAO::Collocation_Strategy strategy
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((CORBA::Exception))
{
  TAO::Portable_Server::Servant_Upcall servant_upcall (
      obj->_stubobj ()->servant_orb_var ()->orb_core ()
    );
  
  TAO_Collocated_Skeleton collocated_skel;
  TAO_Abstract_ServantBase *servant = 0;
  
  if (strategy == TAO::TAO_CS_THRU_POA_STRATEGY)
    {
      servant_upcall.prepare_for_upcall (
          obj->_stubobj ()->object_key (),
          op,
          forward_obj
          ACE_ENV_ARG_PARAMETER
        );
      ACE_CHECK;
      
      servant_upcall.pre_invoke_collocated_request (
          ACE_ENV_SINGLE_ARG_PARAMETER
        );
      ACE_CHECK;
      
      servant = servant_upcall.servant ();
    }
  else
    {
      servant = obj->_servant ();
    }
  
  int status = servant->_find (op,
                               collocated_skel,
                               strategy,
                               op_len);
  
  if (status == -1)
    {
      ACE_THROW (CORBA::BAD_OPERATION (TAO::VMCID | 2, CORBA::COMPLETED_NO));
    }
  
  ACE_TRY
    {
      collocated_skel (servant,
                       args,
                       num_args
                       ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
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
  ACE_CHECK;
}

//
//        End Strategized Proxy Broker Implementation
///////////////////////////////////////////////////////////////////////

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_ss.cpp:640

TAO::Collocation_Proxy_Broker *
Messaging__TAO_ReplyHandler_Proxy_Broker_Factory_function (CORBA::Object_ptr)
{
  return
    ::POA_Messaging::_TAO_ReplyHandler_Strategized_Proxy_Broker::the_TAO_ReplyHandler_Strategized_Proxy_Broker ();
}

int
Messaging__TAO_ReplyHandler_Proxy_Broker_Factory_Initializer (size_t)
{
  Messaging__TAO_ReplyHandler_Proxy_Broker_Factory_function_pointer = 
    Messaging__TAO_ReplyHandler_Proxy_Broker_Factory_function;
  
  return 0;
}

static int
Messaging__TAO_ReplyHandler_Proxy_Broker_Stub_Factory_Initializer_Scarecrow =
  Messaging__TAO_ReplyHandler_Proxy_Broker_Factory_Initializer (
      reinterpret_cast<
          size_t> (
          Messaging__TAO_ReplyHandler_Proxy_Broker_Factory_Initializer
        )
    );


///////////////////////////////////////////////////////////////////////
//                 ThruPOA Proxy  Implementation
//

// TAO_IDL - Generated from
// be\be_visitor_interface/thru_poa_proxy_impl_ss.cpp:37

POA_Messaging::_TAO_ReplyHandler_ThruPOA_Proxy_Impl::_TAO_ReplyHandler_ThruPOA_Proxy_Impl (void)
{}

// ThruPOA Implementation of the IDL interface methods

//
//           End ThruPOA Proxy Implementation
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
//                 Direct Proxy  Implementation
//

POA_Messaging::_TAO_ReplyHandler_Direct_Proxy_Impl::_TAO_ReplyHandler_Direct_Proxy_Impl (void)
{}



//
//           End Direct Proxy Implementation
///////////////////////////////////////////////////////////////////////

// TAO_IDL - Generated from 
// be\be_visitor_interface/interface_ss.cpp:97

POA_Messaging::ReplyHandler::ReplyHandler (void)
{
  this->optable_ = &tao_Messaging_ReplyHandler_optable;
}

POA_Messaging::ReplyHandler::ReplyHandler (const ReplyHandler& rhs)
  : TAO_Abstract_ServantBase (rhs),
    TAO_ServantBase (rhs)
{
}

POA_Messaging::ReplyHandler::~ReplyHandler (void)
{
}

// TAO_IDL - Generated from 
// be\be_visitor_interface/interface_ss.cpp:162

void POA_Messaging::ReplyHandler::_is_a_skel (
    TAO_ServerRequest &_tao_server_request, 
    void * _tao_servant,
    void * /* Servant_Upcall */
    ACE_ENV_ARG_DECL
  )
{
  TAO_InputCDR &_tao_in = _tao_server_request.incoming ();
  
  POA_Messaging::ReplyHandler *_tao_impl =
    static_cast<POA_Messaging::ReplyHandler *> (_tao_servant);
  
  CORBA::Boolean _tao_retval = 0;
  CORBA::String_var value;
  
  if (!(_tao_in >> value.out ()))
    {
      ACE_THROW (CORBA::MARSHAL ());
    }
  
  _tao_retval = _tao_impl->_is_a (value.in () ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
  
  _tao_server_request.init_reply ();
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  
  if (!(_tao_out << CORBA::Any::from_boolean (_tao_retval)))
    {
      ACE_THROW (CORBA::MARSHAL ());
    }
}

void POA_Messaging::ReplyHandler::_non_existent_skel (
    TAO_ServerRequest &_tao_server_request, 
    void * _tao_servant,
    void * /* Servant_Upcall */
    ACE_ENV_ARG_DECL
  )
{
  POA_Messaging::ReplyHandler *_tao_impl =
    static_cast<POA_Messaging::ReplyHandler *> (_tao_servant);
  
  CORBA::Boolean _tao_retval =
    _tao_impl->_non_existent (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;
  
  _tao_server_request.init_reply ();
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  
  if (!(_tao_out << CORBA::Any::from_boolean (_tao_retval)))
    {
      ACE_THROW (CORBA::MARSHAL ());
    }
}

void POA_Messaging::ReplyHandler::_interface_skel (
    TAO_ServerRequest &_tao_server_request, 
    void * _tao_servant,
    void * /* Servant_Upcall */
    ACE_ENV_ARG_DECL
  )
{
  TAO_IFR_Client_Adapter *_tao_adapter =
    ACE_Dynamic_Service<TAO_IFR_Client_Adapter>::instance (
        TAO_ORB_Core::ifr_client_adapter_name ()
      );
    
  if (_tao_adapter == 0)
    {
      ACE_THROW (CORBA::INTF_REPOS ());
    }
  
  POA_Messaging::ReplyHandler *_tao_impl =
    static_cast<POA_Messaging::ReplyHandler *> (_tao_servant);
  
  CORBA::InterfaceDef_ptr _tao_retval = 
    _tao_impl->_get_interface (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;
  
  _tao_server_request.init_reply ();
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  
  CORBA::Boolean _tao_result =
    _tao_adapter->interfacedef_cdr_insert (
        _tao_out,
        _tao_retval
      );
  
  _tao_adapter->dispose (_tao_retval);
  
  if (_tao_result == 0)
    {
      ACE_THROW (CORBA::MARSHAL ());
    }
}

void POA_Messaging::ReplyHandler::_component_skel (
    TAO_ServerRequest &_tao_server_request, 
    void * _tao_object_reference,
    void * /* Servant_Upcall */
    ACE_ENV_ARG_DECL
  )
{
  POA_Messaging::ReplyHandler *_tao_impl =
    static_cast<POA_Messaging::ReplyHandler *> (_tao_object_reference);
  
  CORBA::Object_var _tao_retval =
    _tao_impl->_get_component (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;
  
  _tao_server_request.init_reply ();
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  
  if (!(_tao_out << _tao_retval.in ()))
    {
      ACE_THROW (CORBA::MARSHAL ());
    }
}

CORBA::Boolean POA_Messaging::ReplyHandler::_is_a (
    const char* value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return
    (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/Messaging/ReplyHandler:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
    );
}

void* POA_Messaging::ReplyHandler::_downcast (
    const char* logical_type_id
  )
{
  if (ACE_OS::strcmp (logical_type_id,
                      "IDL:omg.org/Messaging/ReplyHandler:1.0") == 0)
    {
      return static_cast<POA_Messaging::ReplyHandler_ptr> (this);
    }
  
  if (ACE_OS::strcmp (logical_type_id,
                      "IDL:omg.org/CORBA/Object:1.0") == 0)
    {
      return static_cast<PortableServer::Servant> (this);
    }
  
  return 0;
}

const char* POA_Messaging::ReplyHandler::_interface_repository_id (void) const
{
  return "IDL:omg.org/Messaging/ReplyHandler:1.0";
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_ss.cpp:576

void POA_Messaging::ReplyHandler::_dispatch (
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
// be\be_visitor_interface/interface_ss.cpp:527

Messaging::ReplyHandler *
POA_Messaging::ReplyHandler::_this (ACE_ENV_SINGLE_ARG_DECL)
{
  TAO_Stub *stub = this->_create_stub (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);
  
  TAO_Stub_Auto_Ptr safe_stub (stub);
  CORBA::Object_ptr tmp = CORBA::Object::_nil ();
  
  CORBA::Boolean _tao_opt_colloc =
    stub->servant_orb_var ()->orb_core ()->optimize_collocation_objects ();
  
  ACE_NEW_RETURN (
      tmp,
      CORBA::Object (stub, _tao_opt_colloc, this),
      0
    );
  
  CORBA::Object_var obj = tmp;
  (void) safe_stub.release ();
  
  typedef ::Messaging::ReplyHandler STUB_SCOPED_NAME;
  return
    TAO::Narrow_Utils<STUB_SCOPED_NAME>::unchecked_narrow (
        obj.in (),
        Messaging__TAO_ReplyHandler_Proxy_Broker_Factory_function_pointer
      );
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1683

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

#endif /* ifndef */

