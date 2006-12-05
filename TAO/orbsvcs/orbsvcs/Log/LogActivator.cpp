#include "orbsvcs/Log/LogActivator.h"

ACE_RCSID (Log,
           LogActivator,
           "$Id$")

#if (TAO_HAS_MINIMUM_POA == 0) && !defined (CORBA_E_COMPACT) && !defined (CORBA_E_MICRO)
#include "orbsvcs/Log/LogMgr_i.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_LogActivator::TAO_LogActivator (TAO_LogMgr_i &logmgr_i)
  : logmgr_i_ (logmgr_i)
{
}

TAO_LogActivator::~TAO_LogActivator ()
{
}

PortableServer::Servant
TAO_LogActivator::incarnate (const PortableServer::ObjectId& oid,
			     PortableServer::POA_ptr
			     ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
		   PortableServer::ForwardRequest
		   ))
{
  CORBA::String_var poa_id = PortableServer::ObjectId_to_string (oid);

  DsLogAdmin::LogId id = ACE_OS::strtoul(poa_id.in (), 0, 0);

  if (!logmgr_i_.exists(id ACE_ENV_ARG_PARAMETER))
    ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (), 0);
  ACE_CHECK_RETURN(0);

  return logmgr_i_.create_log_servant (id ACE_ENV_ARG_PARAMETER);
}


void
TAO_LogActivator::etherealize (const PortableServer::ObjectId&,
			       PortableServer::POA_ptr,
			       PortableServer::Servant servant,
			       CORBA::Boolean,
			       CORBA::Boolean remaining_activations
			       ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  if (!remaining_activations)
   {
     delete servant;
   }
}

TAO_END_VERSIONED_NAMESPACE_DECL

#endif
