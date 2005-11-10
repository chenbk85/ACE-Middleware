// $Id$

#include "EC_Reactive_Dispatching.h"
#include "EC_ProxySupplier.h"

ACE_RCSID(Event, EC_Reactive_Dispatching, "$Id$")

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_EC_Reactive_Dispatching::TAO_EC_Reactive_Dispatching (void)
  : TAO_EC_Dispatching ()
{
}

void
TAO_EC_Reactive_Dispatching::activate (void)
{
}

void
TAO_EC_Reactive_Dispatching::shutdown (void)
{
}

void
TAO_EC_Reactive_Dispatching::push (TAO_EC_ProxyPushSupplier* proxy,
                                   RtecEventComm::PushConsumer_ptr consumer,
                                   const RtecEventComm::EventSet& event,
                                   TAO_EC_QOS_Info&
                                   ACE_ENV_ARG_DECL)
{
  proxy->reactive_push_to_consumer (consumer, event ACE_ENV_ARG_PARAMETER);
}

void
TAO_EC_Reactive_Dispatching::push_nocopy (TAO_EC_ProxyPushSupplier* proxy,
                                          RtecEventComm::PushConsumer_ptr consumer,
                                          RtecEventComm::EventSet& event,
                                          TAO_EC_QOS_Info&
                                          ACE_ENV_ARG_DECL)
{
  proxy->reactive_push_to_consumer (consumer, event ACE_ENV_ARG_PARAMETER);
}

TAO_END_VERSIONED_NAMESPACE_DECL
