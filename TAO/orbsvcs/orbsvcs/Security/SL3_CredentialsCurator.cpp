// $Id$

#include "SL3_CredentialsCurator.h"
#include "SL3_CredentialsAcquirerFactory.h"


ACE_RCSID (Security,
           SL3_CredentialsCurator,
           "$Id$")


namespace TAO
{
  namespace SL3
  {
    static const size_t CREDENTIALS_TABLE_SIZE = 128;
  }
}

TAO::SL3::CredentialsCurator::CredentialsCurator (void)
  : lock_ (),
    acquirer_factories_ (),
    credentials_table_ (TAO::SL3::CREDENTIALS_TABLE_SIZE)
{
}

TAO::SL3::CredentialsCurator::~CredentialsCurator (void)
{
  const Factory_Iterator fend = this->acquirer_factories_.end ();
  for (Factory_Iterator i = this->acquirer_factories_.begin ();
       i != fend;
       ++i)
    {
      // Deallocate the CredentialsId.
      CORBA::string_free (const_cast<char *> ((*i).ext_id_));

      delete (*i).int_id_;
    }

  this->acquirer_factories_.close ();

  const Credentials_Iterator end = this->credentials_table_.end ();
  for (Credentials_Iterator j = this->credentials_table_.begin ();
       j != end;
       ++j)
    {
      // Deallocate the CredentialsId.
      CORBA::string_free (const_cast<char *> ((*j).ext_id_));
    }

  this->credentials_table_.close ();
}

TAO::SL3::CredentialsCurator_ptr
TAO::SL3::CredentialsCurator::_duplicate (TAO::SL3::CredentialsCurator_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_add_ref ();

  return obj;
}

TAO::SL3::CredentialsCurator_ptr
TAO::SL3::CredentialsCurator::_narrow (CORBA::Object_ptr obj
                                       ACE_ENV_ARG_DECL_NOT_USED)
{
  return TAO::SL3::CredentialsCurator::_duplicate (
             dynamic_cast<TAO::SL3::CredentialsCurator *> (obj));
}

TAO::SL3::CredentialsCurator_ptr
TAO::SL3::CredentialsCurator::_nil (void)
{
  return (CredentialsCurator *) 0;
}

SecurityLevel3::AcquisitionMethodList *
TAO::SL3::CredentialsCurator::supported_methods (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  SecurityLevel3::AcquisitionMethodList * list;
  ACE_NEW_THROW_EX (list,
                    SecurityLevel3::AcquisitionMethodList,
                    CORBA::NO_MEMORY ());
  SecurityLevel3::AcquisitionMethodList_var methods = list;

  ACE_GUARD_RETURN (TAO_SYNCH_MUTEX,
                    guard,
                    this->lock_,
                    0);

  methods->length (this->acquirer_factories_.current_size ());

  CORBA::ULong n = 0;

  const Factory_Iterator end = this->acquirer_factories_.end ();
  for (Factory_Iterator i = this->acquirer_factories_.begin ();
       i != end;
       ++i)
    {
      methods[n++] = CORBA::string_dup ((*i).ext_id_);
    }

  return methods._retn ();
}

SecurityLevel3::CredentialsAcquirer_ptr
TAO::SL3::CredentialsCurator::acquire_credentials (
    const char * acquisition_method,
    const CORBA::Any & acquisition_arguments
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO::SL3::CredentialsAcquirerFactory * factory;

  if (this->acquirer_factories_.find (acquisition_method,
                                      factory) == 0)
    {
      return factory->make (this,
                            acquisition_arguments
                            ACE_ENV_ARG_PARAMETER);
    }

  ACE_THROW_RETURN (CORBA::BAD_PARAM (),
                    SecurityLevel3::CredentialsAcquirer::_nil ());

}

SecurityLevel3::OwnCredentialsList *
TAO::SL3::CredentialsCurator::default_creds_list (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  SecurityLevel3::OwnCredentialsList * list;
  ACE_NEW_THROW_EX (list,
                    SecurityLevel3::OwnCredentialsList,
                    CORBA::NO_MEMORY ());
  ACE_CHECK_RETURN (0);

  SecurityLevel3::OwnCredentialsList_var creds_list = list;

  ACE_GUARD_RETURN (TAO_SYNCH_MUTEX,
                    guard,
                    this->lock_,
                    0);

  creds_list->length (this->credentials_table_.current_size ());

  CORBA::ULong n = 0;

  const Credentials_Iterator end = this->credentials_table_.end ();
  for (Credentials_Iterator i = this->credentials_table_.begin ();
       i != end;
       ++i)
    {
      creds_list[n++] =
        SecurityLevel3::OwnCredentials::_duplicate ((*i).int_id_.in());
    }

  return creds_list._retn ();
}

SecurityLevel3::CredentialsIdList *
TAO::SL3::CredentialsCurator::default_creds_ids (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  SecurityLevel3::CredentialsIdList * list;
  ACE_NEW_THROW_EX (list,
                    SecurityLevel3::CredentialsIdList,
                    CORBA::NO_MEMORY ());
  SecurityLevel3::CredentialsIdList_var creds_ids = list;

  ACE_GUARD_RETURN (TAO_SYNCH_MUTEX,
                    guard,
                    this->lock_,
                    0);

  creds_ids->length (this->credentials_table_.current_size ());

  CORBA::ULong n = 0;

  const Credentials_Iterator end = this->credentials_table_.end ();
  for (Credentials_Iterator i = this->credentials_table_.begin ();
       i != end;
       ++i)
    {
      creds_ids[n++] = CORBA::string_dup ((*i).ext_id_);
    }

  return creds_ids._retn ();
}

SecurityLevel3::OwnCredentials_ptr
TAO::SL3::CredentialsCurator::get_own_credentials (
    const char * credentials_id
    ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  Credentials_Table::ENTRY * entry;

  ACE_GUARD_RETURN (TAO_SYNCH_MUTEX,
                    guard,
                    this->lock_,
                    SecurityLevel3::OwnCredentials::_nil ());

  if (this->credentials_table_.find (credentials_id, entry) != 0)
    {
      return SecurityLevel3::OwnCredentials::_nil ();
    }

  return
    SecurityLevel3::OwnCredentials::_duplicate (entry->int_id_.in ());
}

void
TAO::SL3::CredentialsCurator::release_own_credentials (
    const char * credentials_id
    ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  Credentials_Table::ENTRY * entry;

  ACE_GUARD (TAO_SYNCH_MUTEX, guard, this->lock_);

  if (this->credentials_table_.find (credentials_id, entry) == 0)
    {
      // Deallocate the external ID (a const char *) before unbinding.
      CORBA::string_free (const_cast<char *> (entry->ext_id_));

      (void) this->credentials_table_.unbind (entry);
    }
}

void
TAO::SL3::CredentialsCurator:: register_acquirer_factory (
  const char * acquisition_method,
  TAO::SL3::CredentialsAcquirerFactory * factory
  ACE_ENV_ARG_DECL)
{
  if (acquisition_method == 0 || factory == 0)
    ACE_THROW (CORBA::BAD_PARAM ());

  CORBA::String_var method = CORBA::string_dup (acquisition_method);

  ACE_GUARD (TAO_SYNCH_MUTEX, guard, this->lock_);

  const int result =
    this->acquirer_factories_.bind (method.in (), factory);

  if (result == 1)  // Entry already exists in table.
    ACE_THROW (CORBA::BAD_INV_ORDER ());
  else if (result == -1)  // Failure.
    ACE_THROW (CORBA::INTERNAL ());

  // Otherwise success!
}

void
TAO::SL3::CredentialsCurator::_tao_add_own_credentials (
  SecurityLevel3::OwnCredentials_ptr credentials
  ACE_ENV_ARG_DECL)
{
  CORBA::String_var credentials_id =
    credentials->creds_id (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  SecurityLevel3::OwnCredentials_var creds =
    SecurityLevel3::OwnCredentials::_duplicate (credentials);

  if (this->credentials_table_.bind (credentials_id.in (),
                                     creds) != 0)
    {
      ACE_THROW (CORBA::NO_RESOURCES ());
    }

  (void) credentials_id._retn (); // Credentials table nows owns the id.
}



#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class ACE_Map_Entry<const char *, TAO::SL3::CredentialsAcquirerFactory *>;
template class ACE_Map_Iterator_Base<const char *, TAO::SL3::CredentialsAcquirerFactory *, ACE_Null_Mutex>;
template class ACE_Map_Iterator<const char *, TAO::SL3::CredentialsAcquirerFactory *, ACE_Null_Mutex>;
template class ACE_Map_Reverse_Iterator<const char *, TAO::SL3::CredentialsAcquirerFactory *, ACE_Null_Mutex>;
template class ACE_Map_Manager<const char *, TAO::SL3::CredentialsAcquirerFactory *, ACE_Null_Mutex>;

template class ACE_Hash_Map_Entry<const char *, SecurityLevel3::OwnCredentials_var>;
template class ACE_Hash_Map_Manager_Ex<const char *, SecurityLevel3::OwnCredentials_var, ACE_Hash<const char *>, ACE_Equal_To<const char *>, ACE_Null_Mutex>;
template class ACE_Hash_Map_Iterator_Base_Ex<const char *, SecurityLevel3::OwnCredentials_var, ACE_Hash<const char *>, ACE_Equal_To<const char *>, ACE_Null_Mutex>;
template class ACE_Hash_Map_Iterator_Ex<const char *, SecurityLevel3::OwnCredentials_var, ACE_Hash<const char *>, ACE_Equal_To<const char *>, ACE_Null_Mutex>;
template class ACE_Hash_Map_Reverse_Iterator_Ex<const char *, SecurityLevel3::OwnCredentials_var, ACE_Hash<const char *>, ACE_Equal_To<const char *>, ACE_Null_Mutex>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate ACE_Map_Entry<const char *, TAO::SL3::CredentialsAcquirerFactory *>
#pragma instantiate ACE_Map_Iterator_Base<const char *, TAO::SL3::CredentialsAcquirerFactory *, ACE_Null_Mutex>
#pragma instantiate ACE_Map_Iterator<const char *, TAO::SL3::CredentialsAcquirerFactory *, ACE_Null_Mutex>
#pragma instantiate ACE_Map_Reverse_Iterator<const char *, TAO::SL3::CredentialsAcquirerFactory *, ACE_Null_Mutex>
#pragma instantiate ACE_Map_Manager<const char *, TAO::SL3::CredentialsAcquirerFactory *, ACE_Null_Mutex>

#pragma instantiate ACE_Hash_Map_Entry<const char *, SecurityLevel3::OwnCredentials_var>
#pragma instantiate ACE_Hash_Map_Manager_Ex<const char *, SecurityLevel3::OwnCredentials_var, ACE_Hash<const char *>, ACE_Equal_To<const char *>, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Iterator_Base_Ex<const char *, SecurityLevel3::OwnCredentials_var, ACE_Hash<const char *>, ACE_Equal_To<const char *>, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Iterator_Ex<const char *, SecurityLevel3::OwnCredentials_var, ACE_Hash<const char *>, ACE_Equal_To<const char *>, ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Reverse_Iterator_Ex<const char *, SecurityLevel3::OwnCredentials_var, ACE_Hash<const char *>, ACE_Equal_To<const char *>, ACE_Null_Mutex>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
