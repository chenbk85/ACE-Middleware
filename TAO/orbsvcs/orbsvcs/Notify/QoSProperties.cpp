// $Id$

#include "QoSProperties.h"

#if ! defined (__ACE_INLINE__)
#include "QoSProperties.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(Notify, TAO_NS_QoSProperties, "$Id$")

#include "Property.h"

TAO_NS_QoSProperties::TAO_NS_QoSProperties (void)
  : priority_ (CosNotification::Priority)
    , timeout_ (CosNotification::Timeout)
    , stop_time_supported_ (CosNotification::StopTimeSupported)
    , maximum_batch_size_ (CosNotification::MaximumBatchSize)
    , pacing_interval_ (CosNotification::PacingInterval)
    , thread_pool_ (NotifyExt::ThreadPool)
    , thread_pool_lane_ (NotifyExt::ThreadPoolLanes)
{
  unsupported_[0] = CosNotification::EventReliability;
  unsupported_[1] = CosNotification::ConnectionReliability;
  unsupported_[2] = CosNotification::StartTimeSupported;
}

TAO_NS_QoSProperties::~TAO_NS_QoSProperties ()
{
}

int
TAO_NS_QoSProperties::unsupported (ACE_CString& name)
{
  for (int i = 0; i < UNSUPPORTED_PROPERTY_COUNT; ++i)
    {
      if (this->unsupported_[i] == name)
        return 1;
    }

  return 0;
}

int
TAO_NS_QoSProperties::init (const CosNotification::PropertySeq& prop_seq, CosNotification::PropertyErrorSeq& err_seq)
{
  int err_index = -1;

  ACE_CString name;
  for (CORBA::ULong i = 0; i < prop_seq.length (); ++i)
    {
      name = prop_seq[i].name.in();

      if (this->unsupported (name))
        {
          err_index =  err_seq.length ();
          err_seq.length (err_seq.length () + 1);

          err_seq[err_index].code = CosNotification::UNSUPPORTED_PROPERTY;
          err_seq[err_index].name = CORBA::string_dup (prop_seq[i].name);
        }
      else if (this->property_map_.rebind (prop_seq[i].name.in (), prop_seq[i].value) == -1)
        return -1;
      // Note call to rebind. This allows to call <init> to set updates.
    }

  if (prop_seq.length () > 0)
  {
        // Now, init the supported properties
        this->priority_.set (*this);
        this->timeout_.set (*this);
        this->stop_time_supported_.set (*this);
        this->maximum_batch_size_.set (*this);
        this->pacing_interval_.set (*this);
        this->thread_pool_.set (*this);
        this->thread_pool_lane_.set (*this);
  }

  return err_index == -1 ? 0 : 1;
}

int
TAO_NS_QoSProperties::copy (TAO_NS_QoSProperties& qos_properties)
{
  qos_properties.priority_ = this->priority_.value ();
  qos_properties.timeout_ = this->timeout_.value ();
  qos_properties.stop_time_supported_ = this->stop_time_supported_.value ();
  qos_properties.maximum_batch_size_ = this->maximum_batch_size_.value ();
  qos_properties.pacing_interval_ = this->pacing_interval_.value ();

  PROPERTY_MAP::ITERATOR iter (this->property_map_);
  PROPERTY_MAP::ENTRY *entry;

  for (; iter.next (entry); iter.advance ())
    {
      if (qos_properties.property_map_.rebind (entry->ext_id_, entry->int_id_) == -1)
        return -1;
    }

  return 0;
}

int
TAO_NS_QoSProperties::transfer (TAO_NS_QoSProperties& qos_properties)
{
  if (this->copy (qos_properties) == -1)
    return -1;

  // unbind the properties that we don't want to transfer.
  qos_properties.property_map_.unbind (NotifyExt::ThreadPool);
  qos_properties.property_map_.unbind (NotifyExt::ThreadPoolLanes);

  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class TAO_NS_PropertyBase_T<CORBA::Long>;
template class TAO_NS_PropertyBase_T<CORBA::Short>;
template class TAO_NS_PropertyBase_T<TimeBase::TimeT>;

template class TAO_NS_Property_T<CORBA::Long>;
template class TAO_NS_Property_T<CORBA::Short>;
template class TAO_NS_Property_T<TimeBase::TimeT>;

template class TAO_NS_StructProperty_T<NotifyExt::ThreadPoolParams>;
template class TAO_NS_StructProperty_T<NotifyExt::ThreadPoolLanesParams>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate TAO_NS_PropertyBase_T<CORBA::Long>
#pragma instantiate TAO_NS_PropertyBase_T<CORBA::Short>
#pragma instantiate TAO_NS_PropertyBase_T<TimeBase::TimeT>

#pragma instantiate TAO_NS_Property_T<CORBA::Long>
#pragma instantiate TAO_NS_Property_T<CORBA::Short>
#pragma instantiate TAO_NS_Property_T<TimeBase::TimeT>

#pragma instantiate TAO_NS_StructProperty_T<NotifyExt::ThreadPoolParams>
#pragma instantiate TAO_NS_StructProperty_T<NotifyExt::ThreadPoolLanesParams>

#endif /*ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
