// $Id$

#include "Notify_SupplierAdmin_i.h"
#include "Notify_ProxyPushConsumer_i.h"
#include "Notify_StructuredProxyPushConsumer_i.h"
#include "Notify_EventChannel_i.h"
#include "Notify_Resource_Manager.h"
#include "Notify_Event_Manager.h"
#include "ace/Auto_Ptr.h"

// Implementation skeleton constructor
TAO_Notify_SupplierAdmin_i::TAO_Notify_SupplierAdmin_i (TAO_Notify_EventChannel_i* myChannel, TAO_Notify_Resource_Manager* resource_manager)
  :my_channel_ (myChannel),
   resource_manager_ (resource_manager),
   is_destroyed_ (0)
{
  //No-Op.
}

// Implementation skeleton destructor
TAO_Notify_SupplierAdmin_i::~TAO_Notify_SupplierAdmin_i (void)
{
  if (this->is_destroyed_ == 0)
    this->cleanup_i ();
}

void
TAO_Notify_SupplierAdmin_i::init (CosNotifyChannelAdmin::AdminID myID,
                                  CosNotifyChannelAdmin::InterFilterGroupOperator myOperator,
                                  PortableServer::POA_ptr my_POA,
                                  CORBA::Environment &ACE_TRY_ENV)
{
  my_POA_ = PortableServer::POA::_duplicate (my_POA);

  this->proxy_pushconsumer_POA_ = this->resource_manager_->
    create_proxy_pushconsumer_POA (this->my_POA_.in (),
                                   ACE_TRY_ENV);
  ACE_CHECK;

  myID_ = myID;
  myOperator_ = myOperator;
}


CosNotifyChannelAdmin::SupplierAdmin_ptr
TAO_Notify_SupplierAdmin_i::get_ref (CORBA::Environment &ACE_TRY_ENV)
{
  return CosNotifyChannelAdmin::SupplierAdmin
    ::_narrow (this->resource_manager_->
               servant_to_reference (this->my_POA_.in (), this, ACE_TRY_ENV));
}

TAO_Notify_Event_Manager*
TAO_Notify_SupplierAdmin_i::get_event_manager (void)
{
  return this->my_channel_->get_event_manager ();
}

void
TAO_Notify_SupplierAdmin_i::cleanup_i (CORBA::Environment &ACE_TRY_ENV)
{
  // Cleanup all resources..
  this->resource_manager_->destroy_POA (this->proxy_pushconsumer_POA_.in (),
                                        ACE_TRY_ENV);
  this->proxy_pushconsumer_POA_ = PortableServer::POA::_nil ();
  this->my_POA_ = PortableServer::POA::_nil ();
}

void
TAO_Notify_SupplierAdmin_i::deactivate_proxy_pushconsumer (PortableServer::Servant servant, CORBA::Environment &ACE_TRY_ENV)
{
  this->resource_manager_->
    deactivate_object (servant, this->proxy_pushconsumer_POA_.in (),
                       ACE_TRY_ENV);
}

CosNotifyChannelAdmin::AdminID
TAO_Notify_SupplierAdmin_i::MyID (CORBA::Environment &/*ACE_TRY_ENV*/)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  return myID_;
}

CosNotifyChannelAdmin::EventChannel_ptr
TAO_Notify_SupplierAdmin_i::MyChannel (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  return my_channel_->get_ref (ACE_TRY_ENV);
}

CosNotifyChannelAdmin::InterFilterGroupOperator
TAO_Notify_SupplierAdmin_i::MyOperator (CORBA::Environment &/*ACE_TRY_ENV*/)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  return myOperator_;
}

CosNotifyChannelAdmin::ProxyIDSeq*
TAO_Notify_SupplierAdmin_i::pull_consumers (CORBA::Environment& ACE_TRY_ENV)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
}

CosNotifyChannelAdmin::ProxyIDSeq*
TAO_Notify_SupplierAdmin_i::push_consumers (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  return this->proxy_pushconsumer_ids_.get_sequence (ACE_TRY_ENV);
}

CosNotifyChannelAdmin::ProxyConsumer_ptr
TAO_Notify_SupplierAdmin_i::get_proxy_consumer (CosNotifyChannelAdmin::ProxyID proxy_id, CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((
                   CORBA::SystemException,
                   CosNotifyChannelAdmin::ProxyNotFound
                   ))
{
  CORBA::Object_var obj =
    this->resource_manager_->id_to_reference (proxy_id,
                                              proxy_pushconsumer_POA_.in (),
                                              ACE_TRY_ENV);
  ACE_CHECK_RETURN (CosNotifyChannelAdmin::ProxyConsumer::_nil ());

  return CosNotifyChannelAdmin::ProxyConsumer::_narrow (obj._retn ());
}

CosNotifyChannelAdmin::ProxyConsumer_ptr
TAO_Notify_SupplierAdmin_i::obtain_notification_pull_consumer (CosNotifyChannelAdmin::ClientType /*ctype*/, CosNotifyChannelAdmin::ProxyID_out /*proxy_id*/, CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((
                   CORBA::SystemException,
                   CosNotifyChannelAdmin::AdminLimitExceeded
                   ))
{
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (),
                    CosNotifyChannelAdmin::ProxyConsumer::_nil ());
}


CORBA::Object_ptr
TAO_Notify_SupplierAdmin_i::obtain_struct_proxy_pushconsumer_i (CosNotifyChannelAdmin::ProxyID proxy_id, CORBA::Environment &ACE_TRY_ENV)
{
  TAO_Notify_StructuredProxyPushConsumer_i* struct_proxy_pushconsumer =
    this->resource_manager_->create_struct_proxy_pushconsumer (this,
                                                               ACE_TRY_ENV);
  ACE_CHECK_RETURN (CORBA::Object::_nil ());

  PortableServer::ServantBase_var proxy_pushconsumer_var (struct_proxy_pushconsumer);

  struct_proxy_pushconsumer->init (ACE_TRY_ENV);
  ACE_CHECK_RETURN (CORBA::Object::_nil ());

  return this->resource_manager_->
    activate_object_with_id (proxy_id,
                             this->proxy_pushconsumer_POA_.in (),
                             struct_proxy_pushconsumer,
                             ACE_TRY_ENV);
}

CORBA::Object_ptr
TAO_Notify_SupplierAdmin_i::obtain_proxy_pushconsumer_i (CosNotifyChannelAdmin::ProxyID proxy_id, CORBA::Environment &ACE_TRY_ENV)
{
  TAO_Notify_ProxyPushConsumer_i* proxy_pushconsumer =
    this->resource_manager_->create_proxy_pushconsumer (this, ACE_TRY_ENV);
  ACE_CHECK_RETURN (CORBA::Object::_nil ());

  PortableServer::ServantBase_var proxy_pushconsumer_var (proxy_pushconsumer);

  proxy_pushconsumer->init (ACE_TRY_ENV);
  ACE_CHECK_RETURN (CORBA::Object::_nil ());

  return this->resource_manager_->
    activate_object_with_id (proxy_id,
                             this->proxy_pushconsumer_POA_.in (),
                             proxy_pushconsumer,
                             ACE_TRY_ENV);
}

CosNotifyChannelAdmin::ProxyConsumer_ptr
TAO_Notify_SupplierAdmin_i::obtain_notification_push_consumer (CosNotifyChannelAdmin::ClientType ctype, CosNotifyChannelAdmin::ProxyID_out proxy_id, CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((
                   CORBA::SystemException,
                   CosNotifyChannelAdmin::AdminLimitExceeded
                   ))
{
  CORBA::Object_var obj;

  proxy_id = this->proxy_pushconsumer_ids_.get ();

  switch (ctype)
    {
    case CosNotifyChannelAdmin::ANY_EVENT:
      {
        obj = this->obtain_proxy_pushconsumer_i (proxy_id, ACE_TRY_ENV);
        ACE_CHECK_RETURN (CosNotifyChannelAdmin::ProxyConsumer::_nil ());
      }
      break;
    case CosNotifyChannelAdmin::STRUCTURED_EVENT:
      {
        obj = this->obtain_struct_proxy_pushconsumer_i (proxy_id,
                                                        ACE_TRY_ENV);
        ACE_CHECK_RETURN (CosNotifyChannelAdmin::ProxyConsumer::_nil ());
      }
      break;

    case CosNotifyChannelAdmin::SEQUENCE_EVENT:
    default:
      ACE_THROW_RETURN (CORBA::BAD_PARAM (),
                        CosNotifyChannelAdmin::ProxyConsumer::_nil ());
    }

  this->proxy_pushconsumer_ids_.next ();

  return CosNotifyChannelAdmin::ProxyConsumer::_narrow (obj._retn (),
                                                        ACE_TRY_ENV);
}

void
TAO_Notify_SupplierAdmin_i::destroy (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  this->is_destroyed_ = 1;

  // deactivate ourselves
  this->resource_manager_->deactivate_object (this, this->my_POA_.in (),
                                              ACE_TRY_ENV);
  this->cleanup_i (ACE_TRY_ENV);
}

CosNotification::QoSProperties*
TAO_Notify_SupplierAdmin_i::get_qos (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  return this->qos_admin_.get_qos (ACE_TRY_ENV);
}

void
TAO_Notify_SupplierAdmin_i::set_qos (const CosNotification::QoSProperties & qos, CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((
                   CORBA::SystemException,
                   CosNotification::UnsupportedQoS
                   ))
{
  this->qos_admin_.set_qos (qos, ACE_TRY_ENV);
}

void
TAO_Notify_SupplierAdmin_i::validate_qos (const CosNotification::QoSProperties & required_qos, CosNotification::NamedPropertyRangeSeq_out available_qos, CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((
                   CORBA::SystemException,
                   CosNotification::UnsupportedQoS
                   ))
{
  this->qos_admin_.validate_qos (required_qos, available_qos, ACE_TRY_ENV);
}

void
TAO_Notify_SupplierAdmin_i::offer_change (const CosNotification::EventTypeSeq & added, const CosNotification::EventTypeSeq & removed, CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((
                   CORBA::SystemException,
                   CosNotifyComm::InvalidEventType
                   ))
{
  this->get_event_manager ()->update_publication_list (added,
                                                       removed, ACE_TRY_ENV);
}

CosNotifyFilter::FilterID
TAO_Notify_SupplierAdmin_i::add_filter (CosNotifyFilter::Filter_ptr new_filter, CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  return this->filter_admin_.add_filter (new_filter, ACE_TRY_ENV);
}

void
TAO_Notify_SupplierAdmin_i::remove_filter (CosNotifyFilter::FilterID filter, CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((
                   CORBA::SystemException,
                   CosNotifyFilter::FilterNotFound
                   ))
{
  this->filter_admin_.remove_filter (filter, ACE_TRY_ENV);
}

CosNotifyFilter::Filter_ptr
TAO_Notify_SupplierAdmin_i::get_filter (CosNotifyFilter::FilterID filter, CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((
                   CORBA::SystemException,
                   CosNotifyFilter::FilterNotFound
                   ))
{
  return this->filter_admin_.get_filter (filter, ACE_TRY_ENV);
}

CosNotifyFilter::FilterIDSeq*
TAO_Notify_SupplierAdmin_i::get_all_filters (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  return this->filter_admin_.get_all_filters (ACE_TRY_ENV);
}

void
TAO_Notify_SupplierAdmin_i::remove_all_filters (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  this->filter_admin_.remove_all_filters (ACE_TRY_ENV);
}

CosEventChannelAdmin::ProxyPushConsumer_ptr
TAO_Notify_SupplierAdmin_i::obtain_push_consumer (CORBA::Environment& /*ACE_TRY_ENV*/)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  // TODO:!!
  return 0;
}

CosEventChannelAdmin::ProxyPullConsumer_ptr
TAO_Notify_SupplierAdmin_i::obtain_pull_consumer (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (),
                    CosEventChannelAdmin::ProxyPullConsumer::_nil ());
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class TAO_Notify_ID_Pool_Ex<CosNotifyChannelAdmin::ProxyID, CosNotifyChannelAdmin::ProxyIDSeq>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate TAO_Notify_ID_Pool_Ex<CosNotifyChannelAdmin::ProxyID, CosNotifyChannelAdmin::ProxyIDSeq>;

#endif /*ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
