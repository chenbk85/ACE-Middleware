#include "ServerInitializer.h"
#include "ServerInterceptor.h"

ServerInitializer::ServerInitializer ()
{
}

void
ServerInitializer::pre_init (
                             PortableInterceptor::ORBInitInfo_ptr)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
}

void
ServerInitializer::post_init (
                              PortableInterceptor::ORBInitInfo_ptr info)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // get reference to the codec_factory
  IOP::CodecFactory_var codec_factory = info->codec_factory();

  // Create and register the request interceptors.
  PortableInterceptor::ServerRequestInterceptor_var si =
    new ServerInterceptor (codec_factory);
  info->add_server_request_interceptor (si.in());
}
