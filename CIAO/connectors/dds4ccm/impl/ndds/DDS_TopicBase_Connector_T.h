/**
 * @author Marcel Smit <msmit@remedy.nl>
 *
 * $Id$
 *
 * Wrapper facade for NDDS.
 */
#ifndef DDS_TOPIC_BASE_CONNECTOR_H
#define DDS_TOPIC_BASE_CONNECTOR_H

#include "ace/Copy_Disabled.h"
#include "dds4ccm/impl/ndds/DDS_Base_Connector_T.h"

template <typename DDS_TYPE, typename CCM_TYPE>
class DDS_TopicBase_Connector_T
  : public virtual DDS_Base_Connector_T<DDS_TYPE, CCM_TYPE>
{
public:
  DDS_TopicBase_Connector_T (void);
  virtual ~DDS_TopicBase_Connector_T (void);

  virtual char *topic_name (void);

  virtual void topic_name (const char * topic_name);

  virtual ::DDS::StringSeq *key_fields (void);

  virtual void key_fields (const ::DDS::StringSeq & key_fields);

  virtual void configuration_complete (void);
  virtual void ccm_remove (void);
  virtual void ccm_activate (ACE_Reactor* reactor);
  virtual void ccm_passivate (void);

protected:
  void init_default_topic (void);
  void init_publisher (void);
  void init_subscriber (void);

  void activate_default_topic (ACE_Reactor* reactor);
  void activate_publisher (ACE_Reactor* reactor);
  void activate_subscriber (ACE_Reactor* reactor);

  void passivate_default_topic (void);
  void passivate_publisher (void);
  void passivate_subscriber (void);

  void remove_default_topic (void);
  void remove_publisher (void);
  void remove_subscriber (void);

  CORBA::String_var topic_name_;
  DDS::StringSeq key_fields_;

  ::DDS::Topic_var topic_;
  ::DDS::TopicListener_var topiclistener_;

  ::DDS::Publisher_var publisher_;
  ::DDS::PublisherListener_var publisher_listener_;
  ::DDS::Subscriber_var subscriber_;
  ::DDS::SubscriberListener_var subscriber_listener_;
};

#include "dds4ccm/impl/ndds/DDS_TopicBase_Connector_T.cpp"

#endif /* DDS_TOPIC_BASE_CONNECTOR_H */
