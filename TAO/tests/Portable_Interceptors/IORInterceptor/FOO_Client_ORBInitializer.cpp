#include "FOO_Client_ORBInitializer.h"
#include "FOO_ClientRequestInterceptor.h"

#include "tao/ORB_Constants.h"
#include "tao/CodecFactory/CodecFactory.h"

ACE_RCSID (IORInterceptor,
           FOO_Client_ORBInitializer,
           "$Id$")


void
FOO_Client_ORBInitializer::pre_init (
    PortableInterceptor::ORBInitInfo_ptr /* info */
    ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
}

void
FOO_Client_ORBInitializer::post_init (
    PortableInterceptor::ORBInitInfo_ptr info
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  IOP::CodecFactory_var codec_factory =
    info->codec_factory (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  // Set up a structure that contains information necessary to
  // create a GIOP 1.2 CDR encapsulation Codec.
  IOP::Encoding encoding;
  encoding.format = IOP::ENCODING_CDR_ENCAPS;
  encoding.major_version = 1;
  encoding.minor_version = 2;

  // Obtain the CDR encapsulation Codec.
  IOP::Codec_var codec =
    codec_factory->create_codec (encoding
                                 ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  PortableInterceptor::ClientRequestInterceptor_ptr foo;
  ACE_NEW_THROW_EX (foo,
                    FOO_ClientRequestInterceptor (codec.in ()),
                    CORBA::NO_MEMORY (
                      CORBA::SystemException::_tao_minor_code (
                        TAO::VMCID,
                        ENOMEM),
                      CORBA::COMPLETED_NO));
  ACE_CHECK;

  PortableInterceptor::ClientRequestInterceptor_var interceptor =
    foo;

  info->add_client_request_interceptor (interceptor.in ()
                                        ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}
