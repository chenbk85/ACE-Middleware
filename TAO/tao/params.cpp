// $Id$

#include "tao/corba.h"

#if !defined (__ACE_INLINE__)
# include "tao/params.i"
#endif /* __ACE_INLINE__ */

ACE_RCSID(tao, params, "$Id$")

TAO_ORB_Parameters::TAO_ORB_Parameters (void)
  : name_service_port_ (0),
    trading_service_port_ (0),
    sock_rcvbuf_size_ (ACE_DEFAULT_MAX_SOCKET_BUFSIZ),
    sock_sndbuf_size_ (ACE_DEFAULT_MAX_SOCKET_BUFSIZ),
    cdr_memcpy_tradeoff_ (ACE_DEFAULT_CDR_MEMCPY_TRADEOFF),
    use_lite_protocol_ (0)
{
}

TAO_ORB_Parameters::~TAO_ORB_Parameters (void)
{
}
