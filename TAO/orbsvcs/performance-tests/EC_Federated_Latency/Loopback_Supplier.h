/**
 * @file Loopback_Supplier.h
 *
 * $Id$
 *
 * @author Carlos O'Ryan <coryan@uci.edu>
 */

#ifndef ECFL_LOOPBACK_SUPPLIER_H
#define ECFL_LOOPBACK_SUPPLIER_H

#include "orbsvcs/RtecEventCommS.h"
#include "orbsvcs/RtecEventChannelAdminC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

/**
 * @class ECFL_Loopback_Supplier
 *
 * @brief Implement a simple supplier to keep track of the latency
 *
 */
class ECFL_Loopback_Supplier
  : public virtual POA_RtecEventComm::PushSupplier
  , public virtual PortableServer::RefCountServantBase
{
public:
  /// Constructor
  /**
   * The experiment ID is used to configure the supplier ID on the
   * publication.
   */
  ECFL_Loopback_Supplier (CORBA::Long experiment_id);

  /// Connect to the event channel
  void connect (RtecEventChannelAdmin::EventChannel_ptr ec
                TAO_ENV_ARG_DECL);

  /// Disconnect from the event channel
  void disconnect (TAO_ENV_SINGLE_ARG_DECL);

  void push (const RtecEventComm::EventSet &events
             TAO_ENV_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException));

  //@{
  /** @name The RtecEventComm::PushSupplier methods
   */
  virtual void disconnect_push_supplier (TAO_ENV_SINGLE_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException));
  //@}

private:
  /// The experiment id
  /// Synchronize access to the internal data
  TAO_SYNCH_MUTEX mutex_;

  /// The experiment id
  CORBA::Long experiment_id_;

  /// The proxy this object is connected to
  RtecEventChannelAdmin::ProxyPushConsumer_var proxy_consumer_;
};

#endif /* ECFL_LOOPBACK_SUPPLIER_H */
