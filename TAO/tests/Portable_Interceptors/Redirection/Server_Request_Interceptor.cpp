// -*- C++ -*-

#include "Server_Request_Interceptor.h"
#include "tao/ORB_Constants.h"
#include "ace/Log_Msg.h"
#include "CrashPoint.h"

ACE_RCSID (Redirection,
           Server_Request_Interceptor,
           "$Id$")

Server_Request_Interceptor::Server_Request_Interceptor (void)
  : request_count_ (0)
{
}

Server_Request_Interceptor::~Server_Request_Interceptor (void)
{
}

char *
Server_Request_Interceptor::name (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return CORBA::string_dup ("Server_Request_Interceptor");
}

void
Server_Request_Interceptor::destroy (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
}

void
Server_Request_Interceptor::receive_request_service_contexts (
    PortableInterceptor::ServerRequestInfo_ptr
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::ForwardRequest))
{
  this->request_count_++;
}

void
Server_Request_Interceptor::receive_request (
    PortableInterceptor::ServerRequestInfo_ptr
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::ForwardRequest))
{
}

void
Server_Request_Interceptor::send_reply (
    PortableInterceptor::ServerRequestInfo_ptr
    ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  if (crash_point == 1 && this->request_count_ == 2) ACE_OS::exit (1);
}

void
Server_Request_Interceptor::send_exception (
    PortableInterceptor::ServerRequestInfo_ptr
    ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::ForwardRequest))
{
}

void
Server_Request_Interceptor::send_other (
    PortableInterceptor::ServerRequestInfo_ptr
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::ForwardRequest))
{
}
