/* -*- C++ -*- */
// $Id$

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO ORB and the TAO IDL Compiler have been developed by Washington
// University Computer Science's Distributed Object Computing Group.
//
// Information on TAO is available at
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "tao/PolicyC.h"
#include "tao/Operation_Table.h"
#include "tao/Server_Request.h"
#include "tao/POA_CORBA.h"
#include "tao/Environment.h"
#include "tao/Typecode.h"
#include "tao/ORB.h"

ACE_RCSID(tao, PolicyS, "$Id$")

#if !defined (TAO_HAS_LOCALITY_CONSTRAINT_POLICIES)
class TAO_CORBA_Policy_Perfect_Hash_OpTable : public TAO_Perfect_Hash_OpTable
{
private:
  unsigned int hash (const char *str, unsigned int len);
public:
 const TAO_operation_db_entry * lookup (const char *str, unsigned int len);
};
/* starting time is 17:16:21 */
/* C++ code produced by gperf version 2.7 (GNU C++ version) */
/* Command-line: /project/macarena/coryan/head/ACE_wrappers/bin/gperf -m -M -J -c -C -D -E -T -f 0 -a -o -t -p -K opname_ -L C++ -Z TAO_CORBA_Policy_Perfect_Hash_OpTable -N lookup  */
unsigned int
TAO_CORBA_Policy_Perfect_Hash_OpTable::hash (const char *str, unsigned int len)
{
  static const unsigned char asso_values[] =
    {
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17,  0, 17,  0, 17,  0,
      0,  0, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17,  0, 17, 17, 17,
     17,  0, 17, 17, 17, 17, 17, 17,
    };
  return len + asso_values[str[len - 1]] + asso_values[str[0]];
}

const class TAO_operation_db_entry *
TAO_CORBA_Policy_Perfect_Hash_OpTable::lookup (const char *str, unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 5,
      MIN_WORD_LENGTH = 4,
      MAX_WORD_LENGTH = 16,
      MIN_HASH_VALUE = 4,
      MAX_HASH_VALUE = 16,
      HASH_VALUE_RANGE = 13,
      DUPLICATES = 0
    };

  static const class TAO_operation_db_entry  wordlist[] =
    {
      {"",0}, {"",0}, {"",0}, {"",0},
      {"copy",  &POA_CORBA::Policy::copy_skel},
      {"_is_a",  &POA_CORBA::Policy::_is_a_skel},
      {"",0},
      {"destroy",       &POA_CORBA::Policy::destroy_skel},
      {"",0}, {"",0}, {"",0}, {"",0}, {"",0},
      {"_non_existent",  &POA_CORBA::Policy::_non_existent_skel},
      {"",0}, {"",0},
      {"_get_policy_type",      &POA_CORBA::Policy::_get_policy_type_skel},
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
/* ending time is 17:16:21 */
TAO_CORBA_Policy_Perfect_Hash_OpTable tao_CORBA_Policy_optable;
#endif /* !TAO_HAS_LOCALITY_CONSTRAINT_POLICIES */

// skeleton constructor
POA_CORBA::Policy::Policy (void)
{
#if !defined (TAO_HAS_LOCALITY_CONSTRAINT_POLICIES)
  this->optable_ = &tao_CORBA_Policy_optable;
#endif /* !TAO_HAS_LOCALITY_CONSTRAINT_POLICIES */
}

// copy ctor
POA_CORBA::Policy::Policy (const Policy& rhs)
  :   TAO_ServantBase (rhs)
{}
// skeleton destructor
POA_CORBA::Policy::~Policy (void)
{
}

#if !defined (TAO_HAS_LOCALITY_CONSTRAINT_POLICIES)
void POA_CORBA::Policy::_get_policy_type_skel (
    CORBA::ServerRequest &_tao_server_request,
    void *_tao_object_reference,
    void * /* context */,
    CORBA::Environment &ACE_TRY_ENV
)
{
  POA_CORBA::Policy *_tao_impl = (POA_CORBA::Policy *)_tao_object_reference;
  CORBA::PolicyType _tao_retval = 0;
  _tao_retval = _tao_impl->policy_type (
    ACE_TRY_ENV
  );
  ACE_CHECK;
  _tao_server_request.init_reply (ACE_TRY_ENV);
  ACE_CHECK;
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  if (!(
    (_tao_out << _tao_retval)
  ))
    ACE_THROW (CORBA::MARSHAL () );

}

void POA_CORBA::Policy::copy_skel (
    CORBA::ServerRequest &_tao_server_request,
    void *_tao_object_reference,
    void * /* context */,
    CORBA::Environment &ACE_TRY_ENV
)
{
  POA_CORBA::Policy *_tao_impl = (POA_CORBA::Policy *)_tao_object_reference;
  CORBA::Policy_var _tao_retval;
  _tao_retval = _tao_impl->copy (
    ACE_TRY_ENV
  );
  ACE_CHECK;
  _tao_server_request.init_reply (ACE_TRY_ENV);
  ACE_CHECK;
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  if (!(
    (_tao_out << _tao_retval.in ())
  ))
    ACE_THROW (CORBA::MARSHAL () );

}

void POA_CORBA::Policy::destroy_skel (
    CORBA::ServerRequest &_tao_server_request,
    void *_tao_object_reference,
    void * /* context */,
    CORBA::Environment &ACE_TRY_ENV
)
{
  POA_CORBA::Policy *_tao_impl = (POA_CORBA::Policy *)_tao_object_reference;
  _tao_impl->destroy (
    ACE_TRY_ENV
  );
  ACE_CHECK;
  _tao_server_request.init_reply (ACE_TRY_ENV);
}

void POA_CORBA::Policy::_is_a_skel (
    CORBA::ServerRequest &_tao_server_request,
    void * _tao_object_reference,
    void * /*context*/,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  static const TAO_Param_Data_Skel CORBA_Policy_is_a_paramdata [] =
  {
    {CORBA::_tc_boolean, 0, 0},
    {CORBA::_tc_string, CORBA::ARG_IN, 0}
  };
  static const TAO_Call_Data_Skel CORBA_Policy_is_a_calldata =
  {"_is_a", 1, 2, CORBA_Policy_is_a_paramdata};
  POA_CORBA::Policy_ptr  _tao_impl = (POA_CORBA::Policy_ptr) _tao_object_reference;
  CORBA::Boolean _tao_retval;
  CORBA::String_var _tao_value;
  _tao_server_request.demarshal (
    ACE_TRY_ENV,
    &CORBA_Policy_is_a_calldata,
    &_tao_retval,
    &_tao_value.inout ()
  );
  ACE_CHECK;
  _tao_retval = _tao_impl->_is_a (_tao_value.in (), ACE_TRY_ENV);
  ACE_CHECK;
  _tao_server_request.marshal (
    ACE_TRY_ENV,
    &CORBA_Policy_is_a_calldata,
    &_tao_retval,
    &_tao_value.inout ()
  );
}

void POA_CORBA::Policy::_non_existent_skel (
    CORBA::ServerRequest &_tao_server_request,
    void * /* _tao_object_reference */ ,
    void * /*context*/,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  static const TAO_Param_Data_Skel CORBA_Policy_non_existent_paramdata [] =
  {
    {CORBA::_tc_boolean, 0, 0}
  };
  static const TAO_Call_Data_Skel CORBA_Policy_non_existent_calldata =
  {"_non_existent", 1, 1, CORBA_Policy_non_existent_paramdata};
  CORBA::Boolean _tao_retval = 0;
  _tao_server_request.marshal (
    ACE_TRY_ENV,
    &CORBA_Policy_non_existent_calldata,
    &_tao_retval
  );
}

void POA_CORBA::Policy::_dispatch (CORBA::ServerRequest &req, void *context, CORBA::Environment &ACE_TRY_ENV)
{
  TAO_Skeleton skel; // pointer to skeleton for operation
  const char *opname = req.operation (); // retrieve operation name
  // find the skeleton corresponding to this opname
  if (this->_find (opname, skel) == -1)
    {
      ACE_THROW (CORBA_BAD_OPERATION ());
    }
  else
    skel (req, this, context, ACE_TRY_ENV);
}
#endif /* !TAO_HAS_LOCALITY_CONSTRAINT_POLICIES */

CORBA::Boolean POA_CORBA::Policy::_is_a (
    const char* value,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Policy:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (ACE_TRY_ENV))))
      return 1;
    else
      return 0;
}

void* POA_CORBA::Policy::_downcast (
    const char* logical_type_id
  )
{
  if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Policy:1.0") == 0)
    return ACE_static_cast (POA_CORBA::Policy_ptr, this);
  if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Object:1.0") == 0)
    return ACE_static_cast(PortableServer::Servant, this);
  return 0;
}

const char* POA_CORBA::Policy::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/Policy:1.0";
}

// ****************************************************************

POA_CORBA::_tao_collocated_Policy::_tao_collocated_Policy (
    POA_CORBA::Policy_ptr  servant,
    TAO_Stub *stub
  )
  : CORBA_Policy (stub, servant, 1),
    CORBA_Object (stub, servant, 1),
    servant_ (servant)
{
}

POA_CORBA::Policy_ptr POA_CORBA::_tao_collocated_Policy::_get_servant (void) const
{
  return this->servant_;
}

CORBA::Boolean POA_CORBA::_tao_collocated_Policy::_is_a (
    const char* logical_type_id,
    CORBA::Environment &_tao_orb_environment
  )
{
  return this->servant_->_is_a (
      logical_type_id,
      _tao_orb_environment
    );
}

CORBA::PolicyType POA_CORBA::_tao_collocated_Policy::policy_type  (
    CORBA::Environment &_tao_orb_environment
   )
{
  return this->servant_->policy_type (
    _tao_orb_environment
  );
}

CORBA::Policy_ptr POA_CORBA::_tao_collocated_Policy::copy  (
    CORBA::Environment &_tao_orb_environment
   )
{
  return this->servant_->copy (
    _tao_orb_environment
  );
}

void POA_CORBA::_tao_collocated_Policy::destroy  (
    CORBA::Environment &_tao_orb_environment
   )
{
  this->servant_->destroy (
    _tao_orb_environment
  );
}

CORBA::Policy*
POA_CORBA::Policy::_this (CORBA_Environment &ACE_TRY_ENV)
{
  TAO_Stub *stub = this->_create_stub (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);

  CORBA::Policy *retval = CORBA::Policy::_nil ();

  ACE_NEW_RETURN (retval,
                  POA_CORBA::_tao_collocated_Policy (this, 
                                                     stub),
                  CORBA::Policy::_nil ());

  return retval;
}

// ****************************************************************

POA_CORBA::PolicyManager::PolicyManager (void)
{
}

POA_CORBA::PolicyManager::PolicyManager (const PolicyManager& rhs)
  :   TAO_ServantBase (rhs)
{}

POA_CORBA::PolicyManager::~PolicyManager (void)
{
}

CORBA::Boolean POA_CORBA::PolicyManager::_is_a (
    const char* value,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/PolicyManager:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (ACE_TRY_ENV))))
      return 1;
    else
      return 0;
}

void* POA_CORBA::PolicyManager::_downcast (
    const char* logical_type_id
  )
{
  if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/PolicyManager:1.0") == 0)
    return ACE_static_cast (POA_CORBA::PolicyManager_ptr, this);
  if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Object:1.0") == 0)
    return ACE_static_cast(PortableServer::Servant, this);
  return 0;
}

const char* POA_CORBA::PolicyManager::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/PolicyManager:1.0";
}

CORBA::PolicyManager*
POA_CORBA::PolicyManager::_this (CORBA_Environment &ACE_TRY_ENV)
{
  TAO_Stub *stub = this->_create_stub (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);

  CORBA::PolicyManager *retval = CORBA::PolicyManager::_nil ();

  ACE_NEW_RETURN (retval,
                  POA_CORBA::_tao_collocated_PolicyManager (this, 
                                                            stub),
                  CORBA::PolicyManager::_nil ());

  return retval;
}

POA_CORBA::_tao_collocated_PolicyManager::_tao_collocated_PolicyManager (
    POA_CORBA::PolicyManager_ptr  servant,
    TAO_Stub *stub
  )
  : ACE_CORBA_1 (PolicyManager) (),
    CORBA_Object (stub, servant, 1),
    servant_ (servant)
{
}

POA_CORBA::PolicyManager_ptr POA_CORBA::_tao_collocated_PolicyManager::_get_servant (void) const
{
  return this->servant_;
}

CORBA::Boolean POA_CORBA::_tao_collocated_PolicyManager::_is_a (
    const char* logical_type_id,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return this->servant_->_is_a (
      logical_type_id,
      ACE_TRY_ENV
    );
}

CORBA::PolicyList * POA_CORBA::_tao_collocated_PolicyManager::get_policy_overrides  (
    const CORBA::PolicyTypeSeq & ts,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return this->servant_->get_policy_overrides (
    ts,
    ACE_TRY_ENV
  );
}

void POA_CORBA::_tao_collocated_PolicyManager::set_policy_overrides  (
    const CORBA::PolicyList & policies,
    CORBA::SetOverrideType set_add,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  this->servant_->set_policy_overrides (
    policies,
    set_add,
    ACE_TRY_ENV
  );
}

// ****************************************************************

POA_CORBA::PolicyCurrent::PolicyCurrent (void)
{
}

// copy ctor
POA_CORBA::PolicyCurrent::PolicyCurrent (const PolicyCurrent& rhs)
  : ACE_NESTED_CLASS (POA_CORBA,PolicyManager) (rhs),
    ACE_NESTED_CLASS (POA_CORBA,Current) (rhs),
    TAO_ServantBase (rhs)
{}
// skeleton destructor
POA_CORBA::PolicyCurrent::~PolicyCurrent (void)
{
}

CORBA::Boolean POA_CORBA::PolicyCurrent::_is_a (
    const char* value,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/PolicyCurrent:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/PolicyManager:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Current:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (ACE_TRY_ENV))))
      return 1;
    else
      return 0;
}

void* POA_CORBA::PolicyCurrent::_downcast (
    const char* logical_type_id
  )
{
  if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/PolicyCurrent:1.0") == 0)
    return ACE_static_cast (POA_CORBA::PolicyCurrent_ptr, this);
  if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/PolicyManager:1.0") == 0)
    return ACE_static_cast (POA_CORBA::PolicyManager_ptr, this);
  if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Current:1.0") == 0)
    return ACE_static_cast (POA_CORBA::Current_ptr, this);
  if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Object:1.0") == 0)
    return ACE_static_cast(PortableServer::Servant, this);
  return 0;
}

const char* POA_CORBA::PolicyCurrent::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/PolicyCurrent:1.0";
}

CORBA::PolicyCurrent*
POA_CORBA::PolicyCurrent::_this (CORBA_Environment &ACE_TRY_ENV)
{
  TAO_Stub *stub = this->_create_stub (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);

  CORBA::PolicyCurrent *retval = CORBA::PolicyCurrent::_nil ();

  ACE_NEW_RETURN (retval,
                  POA_CORBA::_tao_collocated_PolicyCurrent (this, 
                                                            stub),
                  CORBA::PolicyCurrent::_nil ());

  return retval;
}

POA_CORBA::_tao_collocated_PolicyCurrent::_tao_collocated_PolicyCurrent (
    POA_CORBA::PolicyCurrent_ptr  servant,
    TAO_Stub *stub
  )
  : ACE_CORBA_1 (PolicyCurrent) (),
    ACE_NESTED_CLASS (POA_CORBA,_tao_collocated_PolicyManager) (servant, stub),
    ACE_NESTED_CLASS (POA_CORBA,_tao_collocated_Current) (servant, stub),
    CORBA_Object (stub, servant, 1),
    servant_ (servant)
{
}

POA_CORBA::PolicyCurrent_ptr POA_CORBA::_tao_collocated_PolicyCurrent::_get_servant (void) const
{
  return this->servant_;
}

CORBA::Boolean POA_CORBA::_tao_collocated_PolicyCurrent::_is_a (
    const char* logical_type_id,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return this->servant_->_is_a (
      logical_type_id,
      ACE_TRY_ENV
    );
}
