/* -*- C++ -*- */
// $Id$
//
// ============================================================================
//
// = LIBRARY
//   ORBSVCS Real-time Event Channel
//
// = FILENAME
//   EC_ConsumerAdmin
//
// = AUTHOR
//   Carlos O'Ryan (coryan@cs.wustl.edu)
//
// = CREDITS
//   Based on previous work by Tim Harrison (harrison@cs.wustl.edu)
//   and other members of the DOC group.
//   More details can be found in:
//   http://www.cs.wustl.edu/~schmidt/oopsla.ps.gz
//   http://www.cs.wustl.edu/~schmidt/JSAC-98.ps.gz
//
// ============================================================================

#ifndef TAO_EC_CONSUMERADMIN_H
#define TAO_EC_CONSUMERADMIN_H

#include "ace/Containers.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "orbsvcs/RtecEventChannelAdminS.h"
#include "EC_ProxyPushSupplier_Set.h"

class TAO_EC_Event_Channel;
class TAO_EC_ProxyPushSupplier;
class TAO_EC_ProxyPushConsumer;

class TAO_ORBSVCS_Export TAO_EC_ConsumerAdmin : public POA_RtecEventChannelAdmin::ConsumerAdmin
{
  // = TITLE
  //   ConsumerAdmin
  //
  // = DESCRIPTION
  //   Implements the ConsumerAdmin interface, i.e. the factory for
  //   ProxyPushSupplier objects.
  //
  // = MEMORY MANAGMENT
  //   It does not assume ownership of the TAO_EC_Event_Channel
  //   object; but it *does* assume ownership of the
  //   TAO_EC_ProxyPushSupplier_Set object.
  //
  // = LOCKING
  //   No provisions for locking, access must be serialized
  //   externally.
  //
  // = TODO
  //
public:
  TAO_EC_ConsumerAdmin (TAO_EC_Event_Channel* event_channel,
                        TAO_EC_ProxyPushSupplier_Set* supplier_set = 0);
  // constructor. If <supplier_set> is nil then it builds one using
  // the <event_channel> argument.
  // In any case it assumes ownership.

  virtual ~TAO_EC_ConsumerAdmin (void);
  // destructor...

  typedef TAO_EC_ProxyPushSupplier_Set::SupplierSet SupplierSet;
  typedef TAO_EC_ProxyPushSupplier_Set::SupplierSetIterator SupplierSetIterator;

  SupplierSetIterator begin (void);
  SupplierSetIterator end (void);
  // Iterators over the set of ProxyPushSuppliers

  typedef TAO_EC_ProxyPushSupplier_Set::Busy_Lock Busy_Lock;
  Busy_Lock& busy_lock (void);

  virtual void connected (TAO_EC_ProxyPushConsumer*,
                          CORBA::Environment&);
  virtual void disconnected (TAO_EC_ProxyPushConsumer*,
                             CORBA::Environment&);
  // Used to inform the EC that a Consumer has connected or
  // disconnected from it.

  virtual void connected (TAO_EC_ProxyPushSupplier*,
                          CORBA::Environment&);
  virtual void disconnected (TAO_EC_ProxyPushSupplier*,
                             CORBA::Environment&);
  // Used to inform the EC that a Supplier has connected or
  // disconnected from it.

  virtual void shutdown (CORBA::Environment&);
  // The event channel is shutting down, inform all the consumers of
  // this

  // = The RtecEventChannelAdmin::ConsumerAdmin methods...
  virtual RtecEventChannelAdmin::ProxyPushSupplier_ptr
      obtain_push_supplier (CORBA::Environment &);

  // = The PortableServer::ServantBase methods
  virtual PortableServer::POA_ptr _default_POA (CORBA::Environment& env);

private:
  TAO_EC_Event_Channel *event_channel_;
  // The Event Channel we belong to

  TAO_EC_ProxyPushSupplier_Set* supplier_set_;
  // The implementation for the supplier set container.

  PortableServer::POA_var default_POA_;
  // Store the default POA.
};

#if defined (__ACE_INLINE__)
#include "EC_ConsumerAdmin.i"
#endif /* __ACE_INLINE__ */

#endif /* TAO_EC_CONSUMERADMIN_H */
