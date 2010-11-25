// -*- C++ -*-
// $Id$

#include "ace/Tokenizer_T.h"
#include "ace/Env_Value_T.h"
#include "tao/ORB_Core.h"
#include "dds4ccm/impl/Utils.h"
#include "dds4ccm/impl/logger/Log_Macros.h"

#include "dds4ccm/impl/TopicListener.h"
#include "dds4ccm/impl/PublisherListener.h"
#include "dds4ccm/impl/SubscriberListener.h"

#if (CIAO_DDS4CCM_NDDS==1)
# include "dds4ccm/impl/ndds/TypeSupport.h"
# include "dds4ccm/impl/ndds/DomainParticipant.h"
#endif

template <typename CCM_TYPE, typename DDS_TYPE>
DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::DDS_Base_Connector_T (void)
  : domain_id_ (0)
  , configuration_complete_ (false)
  , library_name_ (0)
  , profile_name_ (0)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::DDS_Base_Connector_T");

  ACE_Env_Value<int> id (ACE_TEXT("DDS4CCM_DEFAULT_DOMAIN_ID"), this->domain_id_);
  this->domain_id_ = id;
  this->dlf_ = ACE_Dynamic_Service<CIAO::DDS4CCM::Logger_Service>::instance ("DDS4CCM_Logger");
  this->dlf_->init ();

}

template <typename CCM_TYPE, typename DDS_TYPE>
DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::~DDS_Base_Connector_T (void)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::~DDS_Base_Connector_T");

  ACE_OS::free (library_name_);
  ACE_OS::free (profile_name_);

  DDS4CCM_DEBUG (DDS4CCM_LOG_LEVEL_ACTION, (LM_TRACE, DDS4CCM_INFO
                "DDS_Base_Connector_T::~DDS_Base_Connector_T - "
                "Connector has been destructed\n"));
}

template <typename CCM_TYPE, typename DDS_TYPE>
::DDS::DomainId_t
DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::domain_id (void)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::domain_id");

  return this->domain_id_;
}

template <typename CCM_TYPE, typename DDS_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::domain_id (
  ::DDS::DomainId_t domain_id)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::domain_id");

  if (this->configuration_complete_)
    {
      throw ::CCM_DDS::NonChangeable ();
    }
  else
    {
      this->domain_id_ = domain_id;
    }
}

template <typename CCM_TYPE, typename DDS_TYPE>
char *
DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::qos_profile (void)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::qos_profile");

  return CORBA::string_dup (this->qos_profile_.in ());
}

template <typename CCM_TYPE, typename DDS_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::qos_profile (
  const char * qos_profile)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::qos_profile");

  if (this->configuration_complete_)
    {
      throw ::CCM_DDS::NonChangeable ();
    }
  else
    {
      this->qos_profile_ = qos_profile;
    }
}

template <typename CCM_TYPE, typename DDS_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::init_default_domain (void)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::init_default_domain");

  DDS4CCM_DEBUG (DDS4CCM_LOG_LEVEL_ACTION_STARTING, (LM_TRACE, DDS4CCM_INFO
                "DDS_Base_Connector_T::init_default_domain - "
                "Start configuring default domain <%d>\n",
                this->domain_id_));

  // Generic parsing code, library and profile should be separated by a #
  if (this->qos_profile_.in ())
    {
      char* buf = ACE_OS::strdup (this->qos_profile_.in ());
      ACE_Tokenizer_T<char> tok (buf);
      tok.delimiter_replace ('#', 0);
      for (char *p = tok.next (); p; p = tok.next ())
      {
        if (!this->library_name_)
        {
          this->library_name_ = ACE_OS::strdup (p);
        }
        else if (!this->profile_name_)
        {
          this->profile_name_ = ACE_OS::strdup (p);
        }
      }
      ACE_OS::free (buf);
    }
  if (this->library_name_ && this->profile_name_)
    {
      this->dp_factory_.set_default_participant_qos_with_profile (
          this->library_name_,
          this->profile_name_);
      this->domain_participant_ =
        this->dp_factory_.create_participant_with_profile (
            this->domain_id_,
            this->library_name_,
            this->profile_name_,
            ::DDS::DomainParticipantListener::_nil (),
            0);
    }
  else
    {
      ::DDS::DomainParticipantQos qos;
      this->domain_participant_ =
        this->dp_factory_.create_participant (
          this->domain_id_,
          qos,
          ::DDS::DomainParticipantListener::_nil (),
          0);
    }

  if (::CORBA::is_nil (this->domain_participant_.in ()))
    {
      DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_ERROR, (LM_ERROR, DDS4CCM_INFO
                  "DDS_Base_Connector_T::init_default_domain - "
                  "Error: Unable to create DomainParticipant for domain <%d>\n",
                  this->domain_id_));
      throw ::CCM_DDS::InternalError (::DDS::RETCODE_ERROR, 0);
    }

}

template <typename CCM_TYPE, typename DDS_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::set_session_context (
  ::Components::SessionContext_ptr ctx)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::set_session_context");

  typename CCM_TYPE::context_type::_var_type lctx =
    CCM_TYPE::context_type::_narrow (ctx);

  if (::CORBA::is_nil (lctx.in ()))
    {
      throw ::CORBA::INTERNAL ();
    }

  this->context_ = lctx;
}

template <typename CCM_TYPE, typename DDS_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::configuration_complete (void)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::configuration_complete");
  this->init_default_domain ();
  this->configuration_complete_ = true;
}

template <typename CCM_TYPE, typename DDS_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::ccm_activate (void)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::ccm_activate");
}

template <typename CCM_TYPE, typename DDS_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::ccm_passivate (void)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::ccm_passivate");
}

template <typename CCM_TYPE, typename DDS_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::ccm_remove (void)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::ccm_remove");

  ::DDS::ReturnCode_t const retcode = this->dp_factory_.delete_participant (
                                                this->domain_participant_.in ());
  if (retcode != ::DDS::RETCODE_OK)
    {
      throw ::CCM_DDS::InternalError (retcode, 0);
    }

  this->domain_participant_ = ::DDS::DomainParticipant::_nil ();
}

template <typename CCM_TYPE, typename DDS_TYPE>
ACE_Reactor*
DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::reactor (void)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::reactor");

  ACE_Reactor* reactor = 0;

  ::CORBA::Object_var ccm_object = this->context_->get_CCM_object();
  if (!::CORBA::is_nil (ccm_object.in ()))
    {
      ::CORBA::ORB_var orb = ccm_object->_get_orb ();
      if (!::CORBA::is_nil (orb.in ()))
        {
          reactor = orb->orb_core ()->reactor ();
        }
    }

  return reactor;
}

/**
  * Type registration
 **/
template <typename CCM_TYPE, typename DDS_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::register_type (
  const char * typesupport_name)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T::register_type");

  ::DDS::ReturnCode_t retcode = ::DDS::RETCODE_OK;
#if (CIAO_DDS4CCM_NDDS==1)
  ::CIAO::NDDS::DDS_DomainParticipant_i *part =
    dynamic_cast< CIAO::NDDS::DDS_DomainParticipant_i * > (
      this->domain_participant_.in ());
  if (!part)
    {
      DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_ERROR, (LM_ERROR, DDS4CCM_INFO
          "DDS_Base_Connector_T::register_type - "
          "Unable to cast the DomainParticipant proxy to its internal "
          "representation.\n"));
      throw ::CORBA::INTERNAL ();
    }

  ::CIAO::NDDS::DDS_TypeFactory_i * factory = new ::CIAO::NDDS::DDS_TypeFactory_T <DDS_TYPE> ();

  ::CIAO::NDDS::DDS_TypeSupport_i::register_type (
      typesupport_name, factory, this->domain_participant_.in ());

  retcode = DDS_TYPE::type_support::register_type(
    part->get_rti_entity (), typesupport_name);
#endif
  if (retcode != ::DDS::RETCODE_OK)
    {
      DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_ERROR, (LM_ERROR, DDS4CCM_INFO
          "DDS_Base_Connector_T::register_type - "
          "Error registering type <%C>\n",
          ::CIAO::DDS4CCM::translate_retcode (retcode)));
      throw ::CCM_DDS::InternalError (retcode, 0);
    }
}

/**
  * Initialization
 **/
template <typename CCM_TYPE, typename DDS_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::init_topic (
  ::DDS::Topic_ptr & topic,
  const char * topic_name,
  const char * typesupport_name)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T::init_topic");

  ::DDS::Topic_var tp;
  if (this->library_name_ && this->profile_name_)
    {
      tp = this->domain_participant_->create_topic_with_profile (
                                              topic_name,
                                              typesupport_name,
                                              this->library_name_,
                                              this->profile_name_,
                                              ::DDS::TopicListener::_nil (),
                                              0);
    }
  else
    {
      ::DDS::TopicQos tqos;
      tp = this->domain_participant_->create_topic (
                                              topic_name,
                                              typesupport_name,
                                              tqos,
                                              ::DDS::TopicListener::_nil (),
                                              0);
    }
  if (::CORBA::is_nil (tp))
    {
      DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_DDS_NIL_RETURN, (LM_ERROR, DDS4CCM_INFO
                    "DDS_Base_Connector_T::init_topic - "
                    "Error: Proxy returned a nil topic\n"));
      throw ::CCM_DDS::InternalError (::DDS::RETCODE_ERROR, 0);
    }
  topic = tp._retn ();
}

template <typename CCM_TYPE, typename DDS_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::init_publisher (
  ::DDS::Publisher_ptr & publisher)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T::init_publisher");

  if (::CORBA::is_nil (publisher))
    {
      if (this->library_name_ && this->profile_name_)
        {
          publisher = this->domain_participant_->
            create_publisher_with_profile (
              this->library_name_,
              this->profile_name_,
              ::DDS::PublisherListener::_nil (),
              0);
        }
      else
        {
          ::DDS::PublisherQos pqos;
          publisher = this->domain_participant_->
            create_publisher (
              pqos,
              ::DDS::PublisherListener::_nil (),
              0);
        }
      if (::CORBA::is_nil (publisher))
        {
          DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_DDS_NIL_RETURN, (LM_ERROR, DDS4CCM_INFO
                        "DDS_Base_Connector_T::init_publisher - "
                        "Error: Proxy returned a nil publisher.\n"));
          throw ::CCM_DDS::InternalError (::DDS::RETCODE_ERROR, 0);
        }
    }
}

template <typename CCM_TYPE, typename DDS_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::init_subscriber (
  ::DDS::Subscriber_ptr & subscriber)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T::init_subscriber");

  if (::CORBA::is_nil (subscriber))
    {
      if (this->library_name_ && this->profile_name_)
        {
          subscriber = this->domain_participant_->
            create_subscriber_with_profile (
              this->library_name_,
              this->profile_name_,
              ::DDS::SubscriberListener::_nil (),
              0);
        }
      else
        {
          ::DDS::SubscriberQos sqos;
          subscriber = this->domain_participant_->
            create_subscriber (
              sqos,
              ::DDS::SubscriberListener::_nil (),
              0);
        }
      if (::CORBA::is_nil (subscriber))
        {
          DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_DDS_NIL_RETURN, (LM_ERROR, DDS4CCM_INFO
                        "DDS_Base_Connector_T::init_subscriber - "
                        "Error: Proxy returned a nil subscriber.\n"));
          throw ::CCM_DDS::InternalError (::DDS::RETCODE_ERROR, 0);
        }
    }
}

/**
  * Activation
 **/
template <typename CCM_TYPE, typename DDS_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::activate_topic (
  ACE_Reactor* reactor,
  ::DDS::Topic_ptr topic,
  ::DDS::TopicListener_ptr & listener)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T::activate_topic");

  ::CCM_DDS::ConnectorStatusListener_var error_listener =
    this->context_->get_connection_error_listener ();

  ::DDS::StatusMask const mask =
    ::CIAO::DDS4CCM::TopicListener::get_mask (error_listener.in ());

  if (mask != 0)
    {
      if (::CORBA::is_nil (listener))
        {
          ACE_NEW_THROW_EX (listener,
                            ::CIAO::DDS4CCM::TopicListener (
                              error_listener.in (),
                              reactor),
                            ::CORBA::NO_MEMORY ());

          ::DDS::ReturnCode_t const retcode = topic->set_listener (listener,
                                                                   mask);

          if (retcode != ::DDS::RETCODE_OK)
            {
              DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_ERROR, (LM_ERROR, DDS4CCM_INFO
                            "DDS_Base_Connector_T::activate_topic - "
                            "Error while setting the listener on the topic - <%C>\n",
                            ::CIAO::DDS4CCM::translate_retcode (retcode)));
              throw ::CORBA::INTERNAL ();
            }
        }
    }
}

template <typename CCM_TYPE, typename DDS_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::activate_publisher (
  ACE_Reactor* reactor,
  ::DDS::Publisher_ptr publisher,
  ::DDS::PublisherListener_ptr & publisher_listener)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T::activate_publisher");

  ::CCM_DDS::ConnectorStatusListener_var error_listener =
    this->context_->get_connection_error_listener ();

  ::DDS::StatusMask const mask =
      ::CIAO::DDS4CCM::PublisherListener::get_mask (error_listener.in ());

  if (mask != 0)
    {
      if (::CORBA::is_nil (publisher_listener))
        {
          ACE_NEW_THROW_EX (publisher_listener,
                            ::CIAO::DDS4CCM::PublisherListener (
                              error_listener.in (),
                              reactor),
                            ::CORBA::NO_MEMORY ());
        }

      ::DDS::ReturnCode_t const retcode = publisher->set_listener (publisher_listener,
                                                                   mask);

      if (retcode != ::DDS::RETCODE_OK)
        {
          DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_ERROR, (LM_ERROR, DDS4CCM_INFO
                        "DDS_Base_Connector_T::activate_publisher - "
                        "Error while setting the listener on the publisher - <%C>\n",
                        ::CIAO::DDS4CCM::translate_retcode (retcode)));
          throw ::CORBA::INTERNAL ();
        }
    }
}

template <typename CCM_TYPE, typename DDS_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::activate_subscriber (
  ACE_Reactor* reactor,
  ::DDS::Subscriber_ptr subscriber,
  ::DDS::SubscriberListener_ptr & subscriber_listener)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T::activate_subscriber");

  ::CCM_DDS::ConnectorStatusListener_var error_listener =
    this->context_->get_connection_error_listener ();

  ::DDS::StatusMask const mask =
    ::CIAO::DDS4CCM::SubscriberListener::get_mask (error_listener.in ());

  if (mask != 0)
    {
      if (::CORBA::is_nil (subscriber_listener))
        {
          ACE_NEW_THROW_EX (subscriber_listener,
                            ::CIAO::DDS4CCM::SubscriberListener (
                              error_listener.in (),
                              reactor),
                            ::CORBA::NO_MEMORY ());
        }

      ::DDS::ReturnCode_t const retcode = subscriber->set_listener (subscriber_listener,
                                                                    mask);

      if (retcode != ::DDS::RETCODE_OK)
        {
          DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_ERROR, (LM_ERROR, DDS4CCM_INFO
                        "DDS_Base_Connector_T::activate_subscriber - "
                        "Error while setting the listener on the subscriber - <%C>\n",
                        ::CIAO::DDS4CCM::translate_retcode (retcode)));
          throw ::CORBA::INTERNAL ();
        }
    }
}

/**
  * Passivation
 **/
template <typename CCM_TYPE, typename DDS_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::passivate_topic (
  ::DDS::Topic_ptr topic,
  ::DDS::TopicListener_ptr & listener)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T::passivate_topic");

  ::DDS::ReturnCode_t const retcode =
    topic->set_listener (::DDS::TopicListener::_nil (), 0);
  if (retcode != ::DDS::RETCODE_OK)
    {
      DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_ERROR, (LM_ERROR, DDS4CCM_INFO
                    "DDS_Base_Connector_T::passivate_topic - "
                    "Error while setting the listener on the topic - <%C>\n",
                    ::CIAO::DDS4CCM::translate_retcode (retcode)));
      throw ::CORBA::INTERNAL ();
    }

  listener = ::DDS::TopicListener::_nil ();
}

template <typename CCM_TYPE, typename DDS_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::passivate_publisher (
  ::DDS::Publisher_ptr publisher,
  ::DDS::PublisherListener_ptr & publisher_listener)

{
  DDS4CCM_TRACE ("DDS_Base_Connector_T::passivate_publisher");

  if (!::CORBA::is_nil (publisher_listener))
    {
      ::DDS::ReturnCode_t const retcode =
        publisher->set_listener (::DDS::PublisherListener::_nil (), 0);

      if (retcode != ::DDS::RETCODE_OK)
        {
          DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_ERROR, (LM_ERROR, DDS4CCM_INFO
                        "DDS_Base_Connector_T::passivate_publisher - "
                        "Error while setting the listener on the publisher - <%C>\n",
                        ::CIAO::DDS4CCM::translate_retcode (retcode)));
          throw ::CORBA::INTERNAL ();
        }

      publisher_listener = ::DDS::PublisherListener::_nil ();
    }
}

template <typename CCM_TYPE, typename DDS_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::passivate_subscriber (
  ::DDS::Subscriber_ptr subscriber,
  ::DDS::SubscriberListener_ptr & subscriber_listener)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T::passivate_subscriber");

  if (!::CORBA::is_nil (subscriber_listener))
    {
      ::DDS::ReturnCode_t const retcode =
        subscriber->set_listener (::DDS::SubscriberListener::_nil (), 0);
      if (retcode != ::DDS::RETCODE_OK)
        {
          DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_ERROR, (LM_ERROR, DDS4CCM_INFO
                        "DDS_Base_Connector_T::passivate_subscriber - "
                        "Error while setting the listener on the subscriber - <%C>\n",
                        ::CIAO::DDS4CCM::translate_retcode (retcode)));
          throw ::CORBA::INTERNAL ();
        }

      subscriber_listener = ::DDS::SubscriberListener::_nil ();
    }
}

/**
  * Removal
 **/
template <typename CCM_TYPE, typename DDS_TYPE>
void DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::remove_topic (
  ::DDS::Topic_ptr & topic)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T::remove_topic");

  ::DDS::ReturnCode_t retcode =
    this->domain_participant_->delete_topic (topic);
  if (retcode != ::DDS::RETCODE_OK)
    {
      throw ::CCM_DDS::InternalError (retcode, 0);
    }
  topic = ::DDS::Topic::_nil ();

}

template <typename CCM_TYPE, typename DDS_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::remove_publisher (
  ::DDS::Publisher_ptr & publisher)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T::remove_publisher");

  this->domain_participant_->delete_publisher (publisher);
  publisher = ::DDS::Publisher::_nil ();
}

template <typename CCM_TYPE, typename DDS_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::remove_subscriber (
  ::DDS::Subscriber_ptr & subscriber)
{
  DDS4CCM_TRACE ("DDS_Base_Connector_T::remove_subscriber");

  this->domain_participant_->delete_subscriber (subscriber);;
  subscriber = ::DDS::Subscriber::_nil ();
}

/**
  * Unregister type
 **/
template <typename CCM_TYPE, typename DDS_TYPE>
void
DDS_Base_Connector_T<CCM_TYPE, DDS_TYPE>::unregister_type (
  const char * typesupport_name)
{
#if (CIAO_DDS4CCM_NDDS==1)
  ::CIAO::NDDS::DDS_TypeFactory_i * factory =
    ::CIAO::NDDS::DDS_TypeSupport_i::unregister_type (
      typesupport_name, this->domain_participant_.in ());
  delete factory;
#endif
}
