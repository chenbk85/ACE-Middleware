// $Id$

#include "CIAO_DirectEvent.h"

namespace CIAO
{
  DirectEventService::DirectEventService (
    CORBA::ORB_ptr orb,
    PortableServer::POA_ptr poa)
    : orb_ (CORBA::ORB::_duplicate (orb))
    , root_poa_ (PortableServer::POA::_duplicate (poa))
  {
  }

  Supplier_Config_ptr
  DirectEventService::create_supplier_config (void)
    ACE_THROW_SPEC ((CORBA::SystemException))
  {
    Direct_Supplier_Config_impl * supplier_config = 0;
    ACE_NEW_RETURN (supplier_config,
                    Direct_Supplier_Config_impl (this->root_poa_.in ()),
                    Supplier_Config::_nil ());
    Direct_Supplier_Config_var return_direct =
      supplier_config->_this (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK;
    return return_direct._retn ();
  }

  Consumer_Config_ptr
  DirectEventService::create_consumer_config (void)
    ACE_THROW_SPEC ((CORBA::SystemException))
  {
    Direct_Consumer_Config_impl * consumer_config = 0;
    ACE_NEW_RETURN (consumer_config,
                    Direct_Consumer_Config_impl (this->root_poa_.in ()),
                    Consumer_Config::_nil ());
    Direct_Consumer_Config_var return_direct =
      consumer_config->_this (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK;
    return return_direct._retn ();
  }

  void
  DirectEventService::connect_event_supplier (
      Supplier_Config_ptr supplier_config
      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException))
  {
  }

  void
  DirectEventService::connect_event_consumer (
      Consumer_Config_ptr consumer_config
      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
  {
    Components::EventConsumerBase_var consumer =
      consumer_config->consumer (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK;

    //@@@ Needs some reference counting logic here, since we really
    // don't want an EventConsumerBase object to be cached more
    // than once. We could use two ACE_Hash_Manager_Maps, one to
    // cache the object reference, and the other one keeps track of
    // the reference count of each object.

    this->consumer_array_.size (this->consumer_array_.size () + 1);

    this->consumer_array_.set (Components::EventConsumerBase::_duplicate (consumer.in ()),
                               this->consumer_array_.size () - 1);
  }

  // @@ Need to implement this logic.
  void
  DirectEventService::disconnect_event_consumer (
      const char * connection_id
      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException,
      Components::InvalidName,
      Components::InvalidConnection))
  {
    // The connection_id is used to find the event consumer object
    ACE_DEBUG ((LM_DEBUG,
      "Direct_Consumer_Config_impl::disconnect_event_consumer() of ID [%s]\n",
      connection_id));
  }

  void
  DirectEventService::disconnect_event_supplier (
      const char * connection_id
      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException,
      Components::InvalidName,
      Components::InvalidConnection))
  {
  }

  void
  DirectEventService::push_event (
      Components::EventBase * ev
      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException))
  {
    ACE_DEBUG ((LM_DEBUG,
                "CIAO::DirectEventService::push_event\n"));

    size_t end = this->consumer_array_.size ();

    // Iterate through the array, pushing the event to each consumer.
    for (size_t iter = 0; iter != end; ++iter)
      {
        ev->_add_ref (); // Is this needed or not?
        this->consumer_array_[iter]->push_event (
          ev
          ACE_ENV_ARG_PARAMETER);
        ACE_CHECK;
      }
  }

  Direct_Consumer_Config_impl::Direct_Consumer_Config_impl (PortableServer::POA_ptr poa) :
    service_type_ (DIRECT),
    poa_ (PortableServer::POA::_duplicate (poa))
  {
  }

  Direct_Consumer_Config_impl::~Direct_Consumer_Config_impl (void)
  {
    ACE_DEBUG ((LM_DEBUG, "Direct_Consumer_Config_impl::~Direct_Consumer_Config_impl\n"));
  }

  void
  Direct_Consumer_Config_impl::consumer_id (
      const char * consumer_id
      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException))
  {
    this->consumer_id_ = consumer_id;
  }

  void
  Direct_Consumer_Config_impl::supplier_id (
      const char * supplier_id
      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException))
  {
    this->supplier_id_ = supplier_id;
  }

  void
  Direct_Consumer_Config_impl::consumer (
      Components::EventConsumerBase_ptr consumer
      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException))
  {
    this->consumer_ = Components::EventConsumerBase::_duplicate (consumer);
  }

  CONNECTION_ID
  Direct_Consumer_Config_impl::consumer_id (
      ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException))
  {
    return CORBA::string_dup (this->consumer_id_.c_str ());
  }

  CONNECTION_ID
  Direct_Consumer_Config_impl::supplier_id (
      ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException))
  {
    return CORBA::string_dup (this->supplier_id_.c_str ());
  }

  EventServiceType
  Direct_Consumer_Config_impl::service_type (
      ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException))
  {
    return this->service_type_;
  }

  Components::EventConsumerBase_ptr
  Direct_Consumer_Config_impl::consumer (
      ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException))
  {
    return Components::EventConsumerBase::_duplicate (this->consumer_.in ());
  }

  void
  Direct_Consumer_Config_impl::destroy (
      ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException))
  {
    PortableServer::ObjectId_var oid = this->poa_->servant_to_id (this);
    this->poa_->deactivate_object (oid);
    this->_remove_ref ();
  }

  Direct_Supplier_Config_impl::Direct_Supplier_Config_impl (PortableServer::POA_ptr poa)
    : service_type_ (DIRECT),
      poa_ (PortableServer::POA::_duplicate (poa))
  {
  }

  Direct_Supplier_Config_impl::~Direct_Supplier_Config_impl (void)
  {
    ACE_DEBUG ((LM_DEBUG, "Direct_Supplier_Config_impl::~Direct_Supplier_Config_impl\n"));
  }

  void
  Direct_Supplier_Config_impl::supplier_id (
      const char * supplier_id
      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException))
  {
    this->supplier_id_ = supplier_id;
  }

  CONNECTION_ID
  Direct_Supplier_Config_impl::supplier_id (
      ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException))
  {
    return CORBA::string_dup (this->supplier_id_.c_str ());
  }

  EventServiceType
  Direct_Supplier_Config_impl::service_type (
      ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException))
  {
    return this->service_type_;
  }

  void
  Direct_Supplier_Config_impl::destroy (
      ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException))
  {
    PortableServer::ObjectId_var oid = this->poa_->servant_to_id (this);
    this->poa_->deactivate_object (oid);
    this->_remove_ref ();
  }
}
