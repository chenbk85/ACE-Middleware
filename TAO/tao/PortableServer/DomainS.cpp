/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "DomainS.h"
#include "Object_Adapter.h"
#include "Operation_Table.h"

#include "tao/ORB_Core.h"
#include "tao/Server_Request.h"
#include "tao/Stub.h"

#if !defined (__ACE_INLINE__)
#include "DomainS.i"
#endif /* !defined INLINE */

class TAO_CORBA_DomainManager_Perfect_Hash_OpTable : public TAO_Perfect_Hash_OpTable
{
private:
  unsigned int hash (const char *str, unsigned int len);
public:
 const TAO_operation_db_entry * lookup (const char *str, unsigned int len);
};
/* starting time is 18:29:02 */
/* C++ code produced by gperf version 2.8 (ACE version) */
/* Command-line: /export/kelvar/coryan/head/ACE_wrappers/build/Linux/bin/gperf -m -M -J -c -C -D -E -T -f 0 -F 0 -a -o -t -p -K opname_ -L C++ -Z TAO_CORBA_DomainManager_Perfect_Hash_OpTable -N lookup  */
unsigned int
TAO_CORBA_DomainManager_Perfect_Hash_OpTable::hash (const char *str, unsigned int len)
{
  static const unsigned char asso_values[] =
    {
#if defined (ACE_MVS)
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18,  0,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18,  0,
     18, 18, 18, 18, 18,  0, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18,  0, 18, 18, 18, 18,  0, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18,
#else
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18,  0, 18,  0, 18, 18,
     18, 18, 18,  0, 18, 18, 18, 18, 18, 18,
     18, 18, 18, 18, 18, 18,  0, 18, 18, 18,
     18,  0, 18, 18, 18, 18, 18, 18,
#endif /* ACE_MVS */
    };
  return len + asso_values[str[len - 1]] + asso_values[str[0]];
}

const class TAO_operation_db_entry *
TAO_CORBA_DomainManager_Perfect_Hash_OpTable::lookup (const char *str, unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 3,
      MIN_WORD_LENGTH = 5,
      MAX_WORD_LENGTH = 17,
      MIN_HASH_VALUE = 5,
      MAX_HASH_VALUE = 17,
      HASH_VALUE_RANGE = 13,
      DUPLICATES = 0
    };

  static const class TAO_operation_db_entry  wordlist[] =
    {
      {"",0},{"",0},{"",0},{"",0},{"",0},
      {"_is_a",  &POA_CORBA_DomainManager::_is_a_skel},
      {"",0},{"",0},{"",0},{"",0},{"",0},{"",0},{"",0},
      {"_non_existent",  &POA_CORBA_DomainManager::_non_existent_skel},
      {"",0},{"",0},{"",0},
      {"get_domain_policy",     &POA_CORBA_DomainManager::get_domain_policy_skel},
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
/* ending time is 18:29:02 */
static TAO_CORBA_DomainManager_Perfect_Hash_OpTable tao_CORBA_DomainManager_optable;

CORBA::DomainManager_ptr _TAO_collocation_POA_CORBA_DomainManager_Stub_Factory (
    CORBA::Object_ptr obj
  )
{
  TAO_Stub *stub = obj->_stubobj ();

  switch (stub->servant_orb_var ()->orb_core ()->get_collocation_strategy ())
    {
    case TAO_ORB_Core::THRU_POA:
      {
      CORBA::DomainManager_ptr retval = 0;
      ACE_NEW_RETURN (
          retval,
          POA_CORBA__tao_thru_poa_collocated_DomainManager (stub),
          0
        );
      return retval;
      }
    case TAO_ORB_Core::DIRECT:
      if (obj->_is_local () != 0)
        {
          TAO_Collocated_Object *local_object =
            TAO_Collocated_Object::_narrow (obj);

          POA_CORBA_DomainManager *servant = ACE_reinterpret_cast (POA_CORBA_DomainManager*, local_object->_servant ()->_downcast ("IDL:CORBA/DomainManager:1.0"));
          if (servant != 0)
            {
              CORBA::DomainManager *retval = 0;
              ACE_NEW_RETURN (
                  retval,
                  POA_CORBA__tao_direct_collocated_DomainManager (servant, stub),
                  0
                );
              return retval;
            }
        }
      break;
    default:
      break;
    }
  return 0;
}

int _TAO_collocation_POA_CORBA_DomainManager_Stub_Factory_Initializer (long dummy)
{
  ACE_UNUSED_ARG (dummy);

  _TAO_collocation_CORBA_DomainManager_Stub_Factory_function_pointer =
    _TAO_collocation_POA_CORBA_DomainManager_Stub_Factory;

  return 0;
}

static int _TAO_collocation_POA_CORBA_DomainManager_Stub_Factory_Initializer_Scarecrow =
  _TAO_collocation_POA_CORBA_DomainManager_Stub_Factory_Initializer (ACE_reinterpret_cast (long, _TAO_collocation_POA_CORBA_DomainManager_Stub_Factory_Initializer));

// skeleton constructor
POA_CORBA_DomainManager::POA_CORBA_DomainManager (void)
{
  this->optable_ = &tao_CORBA_DomainManager_optable;
}

// copy ctor
POA_CORBA_DomainManager::POA_CORBA_DomainManager (const POA_CORBA_DomainManager& rhs)
  :   TAO_ServantBase (rhs)
{}

// skeleton destructor
POA_CORBA_DomainManager::~POA_CORBA_DomainManager (void)
{
}

void POA_CORBA_DomainManager::get_domain_policy_skel (
    CORBA::ServerRequest &_tao_server_request,
    void *_tao_object_reference,
    void * /* context */,
    CORBA::Environment &ACE_TRY_ENV
)
{
  TAO_InputCDR &_tao_in = _tao_server_request.incoming ();
  POA_CORBA_DomainManager *_tao_impl = (POA_CORBA_DomainManager *)_tao_object_reference;

  CORBA::Policy_var _tao_retval;
  CORBA::PolicyType policy_type;
  if (!(
    (_tao_in >> policy_type)
  ))
    ACE_THROW (CORBA::MARSHAL());

#if (TAO_HAS_INTERCEPTORS == 1)
  TAO_ServerRequestInterceptor_Adapter
    _tao_vfr (_tao_server_request.orb ()->_get_server_interceptor (ACE_TRY_ENV));
  ACE_CHECK;
  // @@ CORBA::Object_var _tao_objref;
    POA_CORBA_DomainManager::TAO_ServerRequest_Info_CORBA_DomainManager_get_domain_policy  ri ("get_domain_policy",
_tao_server_request.service_info ()    ,  policy_type    ,
    ACE_TRY_ENV);
if (_tao_vfr.valid ())
    {
      // @@ _tao_objref = _tao_server_request.objref (ACE_TRY_ENV);
      ACE_CHECK;
    }

  ACE_TRY
    {
      ri.request_id (_tao_server_request.request_id ());
      _tao_vfr.receive_request (&ri, ACE_TRY_ENV);
    TAO_INTERCEPTOR_CHECK;
#endif /* TAO_HAS_INTERCEPTORS */

    _tao_retval = _tao_impl->get_domain_policy (
      policy_type,
      ACE_TRY_ENV
    );

    CORBA::Policy_ptr  _tao_retval_info = _tao_retval._retn ();
    #if (TAO_HAS_INTERCEPTORS == 1)

     ri.result (_tao_retval_info);
    _tao_retval = _tao_retval_info;
    #endif /* TAO_HAS_INTERCEPTORS */

TAO_INTERCEPTOR_CHECK;


    #if (TAO_HAS_INTERCEPTORS == 1)

   _tao_vfr.send_reply (&ri, ACE_TRY_ENV);
  TAO_INTERCEPTOR_CHECK;
}
ACE_CATCHANY
  {
    ri.exception (&ACE_ANY_EXCEPTION);
    _tao_vfr.send_exception (&ri,
        ACE_TRY_ENV
      );
    ACE_RE_THROW;
  }
ACE_ENDTRY;
ACE_CHECK;
#endif /* TAO_HAS_INTERCEPTORS */

_tao_server_request.init_reply (ACE_TRY_ENV);
ACE_CHECK;
TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
if (!(
  (_tao_out << _tao_retval.in ())
))
  ACE_THROW (CORBA::MARSHAL());

}

void POA_CORBA_DomainManager::_is_a_skel (
    CORBA::ServerRequest &_tao_server_request,
    void * _tao_object_reference,
    void * /* context */,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  TAO_InputCDR &_tao_in = _tao_server_request.incoming ();
  POA_CORBA_DomainManager *_tao_impl = (POA_CORBA_DomainManager *) _tao_object_reference;
  CORBA::Boolean _tao_retval = 0;
  CORBA::String_var value;
  if (!(_tao_in >> value.out ()))
    ACE_THROW (CORBA::MARSHAL ());

  _tao_retval = _tao_impl->_is_a (value.in (), ACE_TRY_ENV);
  ACE_CHECK;

  _tao_server_request.init_reply (ACE_TRY_ENV);
  ACE_CHECK;
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  if (!(_tao_out << CORBA::Any::from_boolean (_tao_retval)))
    ACE_THROW (CORBA::MARSHAL ());
}

void POA_CORBA_DomainManager::_non_existent_skel (
    CORBA::ServerRequest &_tao_server_request,
    void * _tao_object_reference,
    void * /* context */,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_CORBA_DomainManager *_tao_impl = (POA_CORBA_DomainManager *) _tao_object_reference;
  CORBA::Boolean _tao_retval = _tao_impl->_non_existent (ACE_TRY_ENV);
  ACE_CHECK;

  _tao_server_request.init_reply (ACE_TRY_ENV);
  ACE_CHECK;
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  if (!(_tao_out << CORBA::Any::from_boolean (_tao_retval)))
    ACE_THROW (CORBA::MARSHAL ());
}

CORBA::Boolean POA_CORBA_DomainManager::_is_a (
    const char* value,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:CORBA/DomainManager:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (ACE_TRY_ENV))))
      return 1;
    else
      return 0;
}

void* POA_CORBA_DomainManager::_downcast (
    const char* logical_type_id
  )
{
if (ACE_OS::strcmp (logical_type_id, "IDL:CORBA/DomainManager:1.0") == 0)
    return ACE_static_cast (POA_CORBA_DomainManager_ptr, this);
    if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Object:1.0") == 0)
    return ACE_static_cast(PortableServer::Servant, this);
  return 0;
}

void POA_CORBA_DomainManager::_dispatch (CORBA::ServerRequest &req, void *context, CORBA::Environment &ACE_TRY_ENV)
{
  this->synchronous_upcall_dispatch(req, context, this, ACE_TRY_ENV);
}

const char* POA_CORBA_DomainManager::_interface_repository_id (void) const
{
  return "IDL:CORBA/DomainManager:1.0";
}

CORBA::DomainManager*
POA_CORBA_DomainManager::_this (CORBA_Environment &ACE_TRY_ENV)
{
  TAO_Stub *stub = this->_create_stub (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);
  if (stub->servant_orb_var ()->orb_core ()->optimize_collocation_objects ())
    switch (stub->servant_orb_var ()->orb_core ()->get_collocation_strategy ())
      {
      case TAO_ORB_Core::THRU_POA:
        {
          ::CORBA::DomainManager_ptr retval = 0;
          ACE_NEW_RETURN (
              retval,
              POA_CORBA__tao_thru_poa_collocated_DomainManager (stub),
              0
            );
          return retval;
        }
      case TAO_ORB_Core::DIRECT:
        {
          ::CORBA::DomainManager_ptr retval = 0;
          ACE_NEW_RETURN (
              retval,
              POA_CORBA__tao_direct_collocated_DomainManager (this, stub),
              0
            );
          return retval;
        }
      default:
        ACE_THROW_RETURN (CORBA::BAD_PARAM (), 0);
      }
  else
    {
      // stub->_incr_refcnt ();
      CORBA::Object_ptr tmp = CORBA::Object::_nil ();
      ACE_NEW_RETURN (tmp, CORBA::Object (stub), 0);
      CORBA::Object_var obj = tmp;
      return ::CORBA::DomainManager::_unchecked_narrow (obj.in ());
    }
}

POA_CORBA__tao_thru_poa_collocated_DomainManager::POA_CORBA__tao_thru_poa_collocated_DomainManager (
  TAO_Stub *stub
)
  :  CORBA_Object (stub, 1)
{
}

CORBA::Boolean POA_CORBA__tao_thru_poa_collocated_DomainManager::_is_a(
    const CORBA::Char *logical_type_id,
    CORBA_Environment &ACE_TRY_ENV
  )

{
  TAO_Object_Adapter::Servant_Upcall servant_upcall (
      this->_stubobj ()->servant_orb_var ()->orb_core ()
    );
  servant_upcall.prepare_for_upcall (
      this->_object_key (),
      "_is_a",
      ACE_TRY_ENV
    );
  ACE_CHECK_RETURN (0);
  return ACE_reinterpret_cast (
      POA_CORBA_DomainManager_ptr,
      servant_upcall.servant ()->_downcast (
          "IDL:CORBA/DomainManager:1.0"
        )
    )->_is_a (logical_type_id, ACE_TRY_ENV);
}


CORBA::Boolean POA_CORBA__tao_thru_poa_collocated_DomainManager::_non_existent(
    CORBA_Environment &ACE_TRY_ENV
  )

{
  TAO_Object_Adapter::Servant_Upcall servant_upcall (
      this->_stubobj ()->servant_orb_var ()->orb_core ()
    );
  servant_upcall.prepare_for_upcall (
      this->_object_key (),
      "_non_existent",
      ACE_TRY_ENV
    );
  ACE_CHECK_RETURN (0);
  return ACE_reinterpret_cast (
      POA_CORBA_DomainManager_ptr,
      servant_upcall.servant ()->_downcast (
          "IDL:CORBA/DomainManager:1.0"
        )
    )->_non_existent (ACE_TRY_ENV);
}


CORBA::Policy_ptr POA_CORBA__tao_thru_poa_collocated_DomainManager::get_domain_policy  (
    CORBA::PolicyType policy_type,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  CORBA::Policy_var _tao_retval;
  ACE_UNUSED_ARG (_tao_retval);
  TAO_Object_Adapter::Servant_Upcall servant_upcall (
      this->_stubobj ()->servant_orb_var ()->orb_core ()
    );
  servant_upcall.prepare_for_upcall (
      this->_object_key (),
      "get_domain_policy",
      ACE_TRY_ENV
    );
  ACE_CHECK_RETURN (0);
  return ACE_reinterpret_cast (
      POA_CORBA_DomainManager_ptr,
      servant_upcall.servant ()->_downcast (
          "IDL:CORBA/DomainManager:1.0"
        )
    )->get_domain_policy (
      policy_type,
      ACE_TRY_ENV
    );

}

POA_CORBA__tao_direct_collocated_DomainManager::POA_CORBA__tao_direct_collocated_DomainManager (
    POA_CORBA_DomainManager_ptr  servant,
    TAO_Stub *stub
  )
  : CORBA_DomainManager (stub, 1),
    TAO_Collocated_Object (stub, 1, servant),
    CORBA_Object (stub, 1),
    servant_ (servant)
{
}

CORBA::Boolean POA_CORBA__tao_direct_collocated_DomainManager::_is_a(
    const CORBA::Char *logical_type_id,
    CORBA_Environment &ACE_TRY_ENV
  )

{
  return this->servant_->_is_a (logical_type_id, ACE_TRY_ENV);
}

void *
POA_CORBA__tao_direct_collocated_DomainManager::_tao_QueryInterface (ptr_arith_t type)
{
  void *value =
    this->TAO_Collocated_Object::_tao_QueryInterface (type);
  if (value != 0)
    return value;
  return this->CORBA_DomainManager::_tao_QueryInterface (type);
}

POA_CORBA_DomainManager_ptr POA_CORBA__tao_direct_collocated_DomainManager::_get_servant (void) const
{
  return this->servant_;
}

CORBA::Boolean POA_CORBA__tao_direct_collocated_DomainManager::_non_existent(
    CORBA_Environment &ACE_TRY_ENV
  )

{
  return this->servant_->_non_existent (ACE_TRY_ENV);
}


CORBA::Policy_ptr POA_CORBA__tao_direct_collocated_DomainManager::get_domain_policy  (
    CORBA::PolicyType policy_type,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->servant_->get_domain_policy (
      policy_type,
      ACE_TRY_ENV
    );

}




#if (TAO_HAS_INTERCEPTORS == 1)
POA_CORBA_DomainManager::TAO_ServerRequest_Info_CORBA_DomainManager_get_domain_policy::TAO_ServerRequest_Info_CORBA_DomainManager_get_domain_policy (const char *_tao_operation,
IOP::ServiceContextList &_tao_service_context_list,CORBA::PolicyType policy_type,
CORBA::Environment &)
  : TAO_ServerRequest_Info (_tao_operation, _tao_service_context_list),policy_type_ (policy_type)
{}

Dynamic::ParameterList *
POA_CORBA_DomainManager::TAO_ServerRequest_Info_CORBA_DomainManager_get_domain_policy::arguments (CORBA::Environment &)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
   // Generate the arg list on demand
  CORBA::ULong length = 0;
        length = this->parameter_list_.length ();
      this->parameter_list_.length (length + 1);
      this->parameter_list_[length].argument <<=  this->policy_type_;

    this->parameter_list_[length].mode = Dynamic::PARAM_IN;

    return &this->parameter_list_;
}

  Dynamic::ExceptionList *
  POA_CORBA_DomainManager::TAO_ServerRequest_Info_CORBA_DomainManager_get_domain_policy::exceptions (CORBA::Environment &)
    ACE_THROW_SPEC ((CORBA::SystemException))
  {
 // Generate the exception list on demand
  return 0;
}


  CORBA::Any *
POA_CORBA_DomainManager::TAO_ServerRequest_Info_CORBA_DomainManager_get_domain_policy::result (CORBA::Environment &)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
 // Generate the result on demand

return &this->result_val_;
}

void
POA_CORBA_DomainManager::TAO_ServerRequest_Info_CORBA_DomainManager_get_domain_policy::result (CORBA::Policy_ptr  result)
  {
  // update the result
   this->result_ = result;
  }

#endif /* TAO_HAS_INTERCEPTORS */
class TAO_CORBA_ConstructionPolicy_Perfect_Hash_OpTable : public TAO_Perfect_Hash_OpTable
{
private:
  unsigned int hash (const char *str, unsigned int len);
public:
 const TAO_operation_db_entry * lookup (const char *str, unsigned int len);
};
/* starting time is 18:29:02 */
/* C++ code produced by gperf version 2.8 (ACE version) */
/* Command-line: /export/kelvar/coryan/head/ACE_wrappers/build/Linux/bin/gperf -m -M -J -c -C -D -E -T -f 0 -F 0 -a -o -t -p -K opname_ -L C++ -Z TAO_CORBA_ConstructionPolicy_Perfect_Hash_OpTable -N lookup  */
unsigned int
TAO_CORBA_ConstructionPolicy_Perfect_Hash_OpTable::hash (const char *str, unsigned int len)
{
  static const unsigned char asso_values[] =
    {
#if defined (ACE_MVS)
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20,  0,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20,  0,
     20,  0,  0,  0, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20,  0, 20,
     20, 20, 20,  0, 20, 20, 20, 20, 20, 20,
     20, 20, 20,  0, 20, 20, 20, 20,  0, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20,
#else
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20,  0, 20,  0, 20,  0,
      0,  0, 20, 20, 20, 20, 20, 20, 20,  0,
     20, 20, 20, 20,  0, 20,  0, 20, 20, 20,
     20,  0, 20, 20, 20, 20, 20, 20,
#endif /* ACE_MVS */
    };
  return len + asso_values[str[len - 1]] + asso_values[str[0]];
}

const class TAO_operation_db_entry *
TAO_CORBA_ConstructionPolicy_Perfect_Hash_OpTable::lookup (const char *str, unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 6,
      MIN_WORD_LENGTH = 4,
      MAX_WORD_LENGTH = 19,
      MIN_HASH_VALUE = 4,
      MAX_HASH_VALUE = 19,
      HASH_VALUE_RANGE = 16,
      DUPLICATES = 0
    };

  static const class TAO_operation_db_entry  wordlist[] =
    {
      {"",0},{"",0},{"",0},{"",0},
      {"copy",  &POA_CORBA_ConstructionPolicy::copy_skel},
      {"_is_a",  &POA_CORBA_ConstructionPolicy::_is_a_skel},
      {"",0},
      {"destroy",       &POA_CORBA_ConstructionPolicy::destroy_skel},
      {"",0},{"",0},{"",0},{"",0},{"",0},
      {"_non_existent",  &POA_CORBA_ConstructionPolicy::_non_existent_skel},
      {"",0},{"",0},
      {"_get_policy_type",      &POA_CORBA_ConstructionPolicy::_get_policy_type_skel},
      {"",0},{"",0},
      {"make_domain_manager",   &POA_CORBA_ConstructionPolicy::make_domain_manager_skel},
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
/* ending time is 18:29:02 */
static TAO_CORBA_ConstructionPolicy_Perfect_Hash_OpTable tao_CORBA_ConstructionPolicy_optable;

CORBA::ConstructionPolicy_ptr _TAO_collocation_POA_CORBA_ConstructionPolicy_Stub_Factory (
    CORBA::Object_ptr obj
  )
{
  TAO_Stub *stub = obj->_stubobj ();

  switch (stub->servant_orb_var ()->orb_core ()->get_collocation_strategy ())
    {
    case TAO_ORB_Core::THRU_POA:
      {
      CORBA::ConstructionPolicy_ptr retval = 0;
      ACE_NEW_RETURN (
          retval,
          POA_CORBA__tao_thru_poa_collocated_ConstructionPolicy (stub),
          0
        );
      return retval;
      }
    case TAO_ORB_Core::DIRECT:
      break;
    default:
      break;
    }
  return 0;
}

int _TAO_collocation_POA_CORBA_ConstructionPolicy_Stub_Factory_Initializer (long dummy)
{
  ACE_UNUSED_ARG (dummy);

  _TAO_collocation_CORBA_ConstructionPolicy_Stub_Factory_function_pointer =
    _TAO_collocation_POA_CORBA_ConstructionPolicy_Stub_Factory;

  return 0;
}

static int _TAO_collocation_POA_CORBA_ConstructionPolicy_Stub_Factory_Initializer_Scarecrow =
  _TAO_collocation_POA_CORBA_ConstructionPolicy_Stub_Factory_Initializer (ACE_reinterpret_cast (long, _TAO_collocation_POA_CORBA_ConstructionPolicy_Stub_Factory_Initializer));

// skeleton constructor
POA_CORBA_ConstructionPolicy::POA_CORBA_ConstructionPolicy (void)
{
  this->optable_ = &tao_CORBA_ConstructionPolicy_optable;
}

// copy ctor
POA_CORBA_ConstructionPolicy::POA_CORBA_ConstructionPolicy (const POA_CORBA_ConstructionPolicy& rhs)
  :   ACE_NESTED_CLASS (POA_CORBA,Policy) (rhs),
    TAO_ServantBase (rhs)
{}

// skeleton destructor
POA_CORBA_ConstructionPolicy::~POA_CORBA_ConstructionPolicy (void)
{
}

void POA_CORBA_ConstructionPolicy::make_domain_manager_skel (
    CORBA::ServerRequest &_tao_server_request,
    void *_tao_object_reference,
    void * /* context */,
    CORBA::Environment &ACE_TRY_ENV
)
{
#if (TAO_HAS_INTERFACE_REPOSITORY == 1)
  TAO_InputCDR &_tao_in = _tao_server_request.incoming ();
  POA_CORBA_ConstructionPolicy *_tao_impl = (POA_CORBA_ConstructionPolicy *)_tao_object_reference;

  IR_InterfaceDef_var object_type;
  CORBA::Boolean constr_policy;
  if (!(
    (_tao_in >> object_type.out ()) &&
    (_tao_in >> CORBA::Any::to_boolean (constr_policy))
  ))
    ACE_THROW (CORBA::MARSHAL());

#if (TAO_HAS_INTERCEPTORS == 1)
  TAO_ServerRequestInterceptor_Adapter
    _tao_vfr (_tao_server_request.orb ()->_get_server_interceptor (ACE_TRY_ENV));
  ACE_CHECK;
  // @@ CORBA::Object_var _tao_objref;
    POA_CORBA_ConstructionPolicy::TAO_ServerRequest_Info_CORBA_ConstructionPolicy_make_domain_manager  ri ("make_domain_manager",
_tao_server_request.service_info ()    ,  object_type.in ()    ,  constr_policy    ,
    ACE_TRY_ENV);
if (_tao_vfr.valid ())
    {
      // @@ _tao_objref = _tao_server_request.objref (ACE_TRY_ENV);
      ACE_CHECK;
    }

  ACE_TRY
    {
      ri.request_id (_tao_server_request.request_id ());
      _tao_vfr.receive_request (&ri, ACE_TRY_ENV);
    TAO_INTERCEPTOR_CHECK;
#endif /* TAO_HAS_INTERCEPTORS */

    _tao_impl->make_domain_manager (
      object_type.in (),
      constr_policy,
      ACE_TRY_ENV
    );

    TAO_INTERCEPTOR_CHECK;


    #if (TAO_HAS_INTERCEPTORS == 1)

   _tao_vfr.send_reply (&ri, ACE_TRY_ENV);
  TAO_INTERCEPTOR_CHECK;
}
ACE_CATCHANY
  {
    ri.exception (&ACE_ANY_EXCEPTION);
    _tao_vfr.send_exception (&ri,
        ACE_TRY_ENV
      );
    ACE_RE_THROW;
  }
ACE_ENDTRY;
ACE_CHECK;
#endif /* TAO_HAS_INTERCEPTORS */

_tao_server_request.init_reply (ACE_TRY_ENV);
ACE_CHECK;
#else
 ACE_UNUSED_ARG (_tao_server_request);
 ACE_UNUSED_ARG (_tao_object_reference);
 ACE_THROW (CORBA::NO_IMPLEMENT ());
#endif /* TAO_HAS_INTERFACE_REPOSITORY */
}

void POA_CORBA_ConstructionPolicy::_is_a_skel (
    CORBA::ServerRequest &_tao_server_request,
    void * _tao_object_reference,
    void * /* context */,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  TAO_InputCDR &_tao_in = _tao_server_request.incoming ();
  POA_CORBA_ConstructionPolicy *_tao_impl = (POA_CORBA_ConstructionPolicy *) _tao_object_reference;
  CORBA::Boolean _tao_retval = 0;
  CORBA::String_var value;
  if (!(_tao_in >> value.out ()))
    ACE_THROW (CORBA::MARSHAL ());

  _tao_retval = _tao_impl->_is_a (value.in (), ACE_TRY_ENV);
  ACE_CHECK;

  _tao_server_request.init_reply (ACE_TRY_ENV);
  ACE_CHECK;
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  if (!(_tao_out << CORBA::Any::from_boolean (_tao_retval)))
    ACE_THROW (CORBA::MARSHAL ());
}

void POA_CORBA_ConstructionPolicy::_non_existent_skel (
    CORBA::ServerRequest &_tao_server_request,
    void * _tao_object_reference,
    void * /* context */,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_CORBA_ConstructionPolicy *_tao_impl = (POA_CORBA_ConstructionPolicy *) _tao_object_reference;
  CORBA::Boolean _tao_retval = _tao_impl->_non_existent (ACE_TRY_ENV);
  ACE_CHECK;

  _tao_server_request.init_reply (ACE_TRY_ENV);
  ACE_CHECK;
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  if (!(_tao_out << CORBA::Any::from_boolean (_tao_retval)))
    ACE_THROW (CORBA::MARSHAL ());
}

CORBA::Boolean POA_CORBA_ConstructionPolicy::_is_a (
    const char* value,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:CORBA/ConstructionPolicy:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Policy:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (ACE_TRY_ENV))))
      return 1;
    else
      return 0;
}

void* POA_CORBA_ConstructionPolicy::_downcast (
    const char* logical_type_id
  )
{
if (ACE_OS::strcmp (logical_type_id, "IDL:CORBA/ConstructionPolicy:1.0") == 0)
    return ACE_static_cast (POA_CORBA_ConstructionPolicy_ptr, this);
  if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Policy:1.0") == 0)
    return ACE_static_cast (POA_CORBA::Policy_ptr, this);
    if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Object:1.0") == 0)
    return ACE_static_cast(PortableServer::Servant, this);
  return 0;
}

void POA_CORBA_ConstructionPolicy::_dispatch (CORBA::ServerRequest &req, void *context, CORBA::Environment &ACE_TRY_ENV)
{
  this->synchronous_upcall_dispatch(req, context, this, ACE_TRY_ENV);
}

const char* POA_CORBA_ConstructionPolicy::_interface_repository_id (void) const
{
  return "IDL:CORBA/ConstructionPolicy:1.0";
}

CORBA::ConstructionPolicy*
POA_CORBA_ConstructionPolicy::_this (CORBA_Environment &ACE_TRY_ENV)
{
  TAO_Stub *stub = this->_create_stub (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);
  if (stub->servant_orb_var ()->orb_core ()->optimize_collocation_objects ())
    switch (stub->servant_orb_var ()->orb_core ()->get_collocation_strategy ())
      {
      case TAO_ORB_Core::THRU_POA:
        {
          ::CORBA::ConstructionPolicy_ptr retval = 0;
          ACE_NEW_RETURN (
              retval,
              POA_CORBA__tao_thru_poa_collocated_ConstructionPolicy (stub),
              0
            );
          return retval;
        }
      case TAO_ORB_Core::DIRECT:
      default:
        ACE_THROW_RETURN (CORBA::BAD_PARAM (), 0);
      }
  else
    {
      // stub->_incr_refcnt ();
      CORBA::Object_ptr tmp = CORBA::Object::_nil ();
      ACE_NEW_RETURN (tmp, CORBA::Object (stub), 0);
      CORBA::Object_var obj = tmp;
      return ::CORBA::ConstructionPolicy::_unchecked_narrow (obj.in ());
    }
}

POA_CORBA__tao_thru_poa_collocated_ConstructionPolicy::POA_CORBA__tao_thru_poa_collocated_ConstructionPolicy (
  TAO_Stub *stub
)
  :  ACE_NESTED_CLASS (POA_CORBA, _tao_thru_poa_collocated_CORBA_Policy (stub)),
    CORBA_Object (stub, 1)
{
}

CORBA::Boolean POA_CORBA__tao_thru_poa_collocated_ConstructionPolicy::_is_a(
    const CORBA::Char *logical_type_id,
    CORBA_Environment &ACE_TRY_ENV
  )

{
  TAO_Object_Adapter::Servant_Upcall servant_upcall (
      this->_stubobj ()->servant_orb_var ()->orb_core ()
    );
  servant_upcall.prepare_for_upcall (
      this->_object_key (),
      "_is_a",
      ACE_TRY_ENV
    );
  ACE_CHECK_RETURN (0);
  return ACE_reinterpret_cast (
      POA_CORBA_ConstructionPolicy_ptr,
      servant_upcall.servant ()->_downcast (
          "IDL:CORBA/ConstructionPolicy:1.0"
        )
    )->_is_a (logical_type_id, ACE_TRY_ENV);
}


CORBA::Boolean POA_CORBA__tao_thru_poa_collocated_ConstructionPolicy::_non_existent(
    CORBA_Environment &ACE_TRY_ENV
  )

{
  TAO_Object_Adapter::Servant_Upcall servant_upcall (
      this->_stubobj ()->servant_orb_var ()->orb_core ()
    );
  servant_upcall.prepare_for_upcall (
      this->_object_key (),
      "_non_existent",
      ACE_TRY_ENV
    );
  ACE_CHECK_RETURN (0);
  return ACE_reinterpret_cast (
      POA_CORBA_ConstructionPolicy_ptr,
      servant_upcall.servant ()->_downcast (
          "IDL:CORBA/ConstructionPolicy:1.0"
        )
    )->_non_existent (ACE_TRY_ENV);
}


void POA_CORBA__tao_thru_poa_collocated_ConstructionPolicy::make_domain_manager  (
    IR_InterfaceDef* object_type,
    CORBA::Boolean constr_policy,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  TAO_Object_Adapter::Servant_Upcall servant_upcall (
      this->_stubobj ()->servant_orb_var ()->orb_core ()
    );
  servant_upcall.prepare_for_upcall (
      this->_object_key (),
      "make_domain_manager",
      ACE_TRY_ENV
    );
  ACE_CHECK;
  ACE_reinterpret_cast (
      POA_CORBA_ConstructionPolicy_ptr,
      servant_upcall.servant ()->_downcast (
          "IDL:CORBA/ConstructionPolicy:1.0"
        )
    )->make_domain_manager (
      object_type,
      constr_policy,
      ACE_TRY_ENV
    );
  return;
}

#if (TAO_HAS_INTERCEPTORS == 1) && (TAO_HAS_INTERFACE_REPOSITORY == 1)
POA_CORBA_ConstructionPolicy::TAO_ServerRequest_Info_CORBA_ConstructionPolicy_make_domain_manager::TAO_ServerRequest_Info_CORBA_ConstructionPolicy_make_domain_manager (const char *_tao_operation,
IOP::ServiceContextList &_tao_service_context_list,IR_InterfaceDef* object_type,CORBA::Boolean constr_policy,
CORBA::Environment &)
  : TAO_ServerRequest_Info (_tao_operation, _tao_service_context_list),object_type_ (object_type),constr_policy_ (constr_policy)
{}

Dynamic::ParameterList *
POA_CORBA_ConstructionPolicy::TAO_ServerRequest_Info_CORBA_ConstructionPolicy_make_domain_manager::arguments (CORBA::Environment &)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
   // Generate the arg list on demand
  CORBA::ULong length = 0;
        length = this->parameter_list_.length ();
      this->parameter_list_.length (length + 1);
      this->parameter_list_[length].argument <<=  this->object_type_;

    this->parameter_list_[length].mode = Dynamic::PARAM_IN;
                length = this->parameter_list_.length ();
        this->parameter_list_.length (length + 1);
        this->parameter_list_[length].argument <<= CORBA::Any::from_boolean (this->constr_policy_ );
      this->parameter_list_[length].mode = Dynamic::PARAM_IN;

      return &this->parameter_list_;
}

    Dynamic::ExceptionList *
    POA_CORBA_ConstructionPolicy::TAO_ServerRequest_Info_CORBA_ConstructionPolicy_make_domain_manager::exceptions (CORBA::Environment &)
      ACE_THROW_SPEC ((CORBA::SystemException))
    {
 // Generate the exception list on demand
    return 0;
}


      CORBA::Any *
  POA_CORBA_ConstructionPolicy::TAO_ServerRequest_Info_CORBA_ConstructionPolicy_make_domain_manager::result (CORBA::Environment &)
    ACE_THROW_SPEC ((CORBA::SystemException))
  {
 // Generate the result on demand
   CORBA::TypeCode tc (CORBA::tk_void);
  this->result_val_.type (&tc);

  return &this->result_val_;
  }

#endif /* TAO_HAS_INTERCEPTORS && TAO_HAS_INTERFACE_REPOSITORY */
