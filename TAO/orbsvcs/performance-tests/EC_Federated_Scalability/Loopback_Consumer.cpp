/**
 * @file Loopback_Consumer.cpp
 *
 * $Id$
 *
 * @author Carlos O'Ryan <coryan@uci.edu>
 */

#include "Loopback_Consumer.h"
#include "ECFS_Configuration.h"
#include "orbsvcs/Event_Service_Constants.h"

ACE_RCSID(EC_Federated_Scalability, Loopback_Consumer, "$Id$")

ECFS_Loopback_Consumer::
     ECFS_Loopback_Consumer (CORBA::Long experiment_id,
                             ECFS_Loopback_Supplier *supplier)
  : experiment_id_ (experiment_id)
  , supplier_ (supplier)
{
  this->supplier_->_add_ref ();
}

void
ECFS_Loopback_Consumer::connect (RtecEventChannelAdmin::EventChannel_ptr ec
                       TAO_ENV_ARG_DECL)
{
  RtecEventChannelAdmin::ConsumerAdmin_var consumer_admin =
    ec->for_consumers (TAO_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  {
    ACE_GUARD (TAO_SYNCH_MUTEX, ace_mon, this->mutex_);
    if (!CORBA::is_nil (this->proxy_supplier_.in ()))
      return;

    this->proxy_supplier_ =
      consumer_admin->obtain_push_supplier (TAO_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK;
  }

  RtecEventComm::PushConsumer_var consumer =
    this->_this (TAO_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  RtecEventChannelAdmin::ConsumerQOS consumer_qos;
  consumer_qos.is_gateway = 0;
  consumer_qos.dependencies.length (2);
  RtecEventComm::EventHeader& h0 =
    consumer_qos.dependencies[0].event.header;
  h0.type   = ACE_ES_DISJUNCTION_DESIGNATOR;
  h0.source = 1;

  RtecEventComm::EventHeader& h1 =
    consumer_qos.dependencies[1].event.header;
  h1.type   = ECFS_START_EVENT_TYPE;
  h1.source = this->experiment_id_;

  this->proxy_supplier_->connect_push_consumer (consumer.in (),
                                                consumer_qos
                                                TAO_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

void
ECFS_Loopback_Consumer::disconnect (TAO_ENV_SINGLE_ARG_DECL)
{
  RtecEventChannelAdmin::ProxyPushSupplier_var proxy;
  {
    ACE_GUARD (TAO_SYNCH_MUTEX, ace_mon, this->mutex_);
    if (CORBA::is_nil (this->proxy_supplier_.in ()))
      return;
    proxy = this->proxy_supplier_._retn ();
  }

  ACE_TRY
    {
      proxy->disconnect_push_supplier (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY {} ACE_ENDTRY;

  PortableServer::POA_var poa = this->_default_POA (TAO_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;
  PortableServer::ObjectId_var id = poa->servant_to_id (this
                                                        TAO_ENV_ARG_PARAMETER);
  ACE_CHECK;
  poa->deactivate_object (id.in () TAO_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

void
ECFS_Loopback_Consumer::push (const RtecEventComm::EventSet &events
                              TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // ACE_DEBUG ((LM_DEBUG, "Loopback_Consumer::push (%P|%t)\n"));
  this->supplier_->push (events TAO_ENV_ARG_PARAMETER);
}

void
ECFS_Loopback_Consumer::disconnect_push_consumer (TAO_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_GUARD (TAO_SYNCH_MUTEX, ace_mon, this->mutex_);
  this->proxy_supplier_ =
    RtecEventChannelAdmin::ProxyPushSupplier::_nil ();
}
