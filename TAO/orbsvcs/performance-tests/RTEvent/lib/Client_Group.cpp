/**
 * @file Client_Group.cpp
 *
 * $Id$
 *
 * @author Carlos O'Ryan <coryan@uci.edu>
 */

#include "Client_Group.h"
#include "Auto_Disconnect.h"

#if !defined(__ACE_INLINE__)
#include "Client_Group.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(TAO_PERF_RTEC, Client_Group, "$Id$")

void
Client_Group::init (CORBA::Long experiment_id,
                    CORBA::Long base_event_type,
                    CORBA::ULong iterations,
                    CORBA::Long workload_in_usecs,
                    ACE_UINT32 gsf)
{
  this->supplier_ = new Supplier (experiment_id,
                                  base_event_type);
  this->consumer_ = new Consumer (experiment_id,
                                  base_event_type + 1,
                                  iterations,
                                  workload_in_usecs,
                                  gsf);
  this->loopback_pair_.init (experiment_id, base_event_type);
}

void
Client_Group::connect (RtecEventChannelAdmin::EventChannel_ptr ec
                       ACE_ENV_ARG_DECL)
{
  this->supplier_->connect (ec ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
  Auto_Disconnect<Supplier> supplier_disconnect (this->supplier_);

  this->consumer_->connect (ec ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
  Auto_Disconnect<Consumer> consumer_disconnect (this->consumer_);

  this->loopback_pair_.connect (ec ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
  Auto_Disconnect<Loopback_Pair> loopback_pair_disconnect (&this->loopback_pair_);

  loopback_pair_disconnect.release ();
  consumer_disconnect.release ();
  supplier_disconnect.release ();
}

void
Client_Group::disconnect (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
{
  Auto_Disconnect<Supplier> supplier_disconnect (this->supplier_);
  Auto_Disconnect<Consumer> consumer_disconnect (this->consumer_);
  Auto_Disconnect<Loopback_Pair> loopback_pair_disconnect (&this->loopback_pair_);
}
