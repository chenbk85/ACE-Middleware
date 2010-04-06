// -*- C++ -*-
// $Id$

#include "dds4ccm/impl/dds/DataReaderStateListener_T.h"
#include "dds4ccm/impl/dds/DataWriterListener_T.h"
#include "dds4ccm/impl/dds/Updater_T.h"
#include "dds4ccm/impl/dds/Reader_T.h"
#include "dds4ccm/impl/dds/PublisherListener_T.h"
#include "dds4ccm/impl/dds/SubscriberListener_T.h"
#include "dds4ccm/impl/dds/DataListenerControl_T.h"
#include "dds4ccm/impl/dds/StateListenerControl_T.h"
#include "dds4ccm/impl/dds/PortStatusListener_T.h"

#include "dds4ccm/impl/logger/Log_Macros.h"
#include "dds4ccm/impl/dds4ccm_conf.h"

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::DDS_State_Connector_T (void) :
    TopicBaseConnector (),
    observable_obtained_ (false),
    passive_observer_obtained_ (false),
    pull_observer_obtained_ (false),
    push_observer_obtained_ (false),
    push_state_observer_obtained_ (false)
{
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::~DDS_State_Connector_T (void)
{
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
typename CCM_TYPE::updater_type::_ptr_type
DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::get_observable_data (void)
{
  DDS4CCM_TRACE ("DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::get_observable_data");

  this->observable_obtained_ = true;
  return this->observable_.get_data ();
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
::DDS::CCM_DataWriter_ptr
DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::get_observable_dds_entity (void)
{
  DDS4CCM_TRACE ("DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::get_observable_dds_entity");

  this->observable_obtained_ = true;
  return this->observable_.get_dds_entity ();
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
typename CCM_TYPE::reader_type::_ptr_type
DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::get_passive_observer_data (void)
{
  DDS4CCM_TRACE ("DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::get_passive_observer_data");

  this->passive_observer_obtained_ = true;
  return this->passive_observer_.get_data ();
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
::DDS::CCM_DataReader_ptr
DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::get_passive_observer_dds_entity (void)
{
  DDS4CCM_TRACE ("DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::get_passive_observer_dds_entity");

  this->passive_observer_obtained_ = true;
  return this->passive_observer_.get_dds_entity ();
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
typename CCM_TYPE::reader_type::_ptr_type
DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::get_pull_observer_data (void)
{
  DDS4CCM_TRACE ("DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::get_pull_observer_data");

  this->pull_observer_obtained_ = true;
  return this->pull_observer_.get_data ();
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
typename CCM_TYPE::getter_type::_ptr_type
DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::get_pull_observer_fresh_data (void)
{
  DDS4CCM_TRACE ("DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::get_pull_observer_fresh_data");

  this->pull_observer_obtained_ = true;
  return this->pull_observer_.get_fresh_data ();
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
::DDS::CCM_DataReader_ptr
DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::get_pull_observer_dds_entity (void)
{
  DDS4CCM_TRACE ("DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::get_pull_observer_dds_entity");

  return this->pull_observer_.get_dds_entity ();
  this->pull_observer_obtained_ = true;
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
typename CCM_TYPE::reader_type::_ptr_type
DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::get_push_observer_data (void)
{
  DDS4CCM_TRACE ("DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::get_push_observer_data");

  this->push_observer_obtained_ = true;
  return this->push_observer_.get_data ();
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
::CCM_DDS::CCM_DataListenerControl_ptr
DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::get_push_observer_data_control (void)
{
  DDS4CCM_TRACE ("DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::get_push_observer_data_control");

  this->push_observer_obtained_ = true;
  return this->push_observer_.get_data_control ();
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
::DDS::CCM_DataReader_ptr
DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::get_push_observer_dds_entity (void)
{
  DDS4CCM_TRACE ("DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::get_push_observer_dds_entity");

  this->push_observer_obtained_ = true;
  return this->push_observer_.get_dds_entity ();
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
typename CCM_TYPE::reader_type::_ptr_type
DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::get_push_state_observer_data (void)
{
  DDS4CCM_TRACE ("DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::get_push_state_observer_data");

  this->push_state_observer_obtained_ = true;
  return this->push_state_observer_.get_data ();
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
::CCM_DDS::CCM_StateListenerControl_ptr
DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::get_push_state_observer_data_control (void)
{
  DDS4CCM_TRACE ("DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::get_push_state_observer_data_control");

  this->push_state_observer_obtained_ = true;
  return this->push_state_observer_.get_data_control ();
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
::DDS::CCM_DataReader_ptr
DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::get_push_state_observer_dds_entity (void)
{
  DDS4CCM_TRACE ("DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::get_push_state_observer_dds_entity");

  this->push_state_observer_obtained_ = true;
  return this->push_state_observer_.get_dds_entity ();
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
void
DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::configuration_complete (void)
{
  DDS4CCM_TRACE ("DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::configuration_complete");

  TopicBaseConnector::configuration_complete ();

  ::CCM_DDS::PortStatusListener_var push_observer_psl =
    this->context_->get_connection_push_observer_status ();
  typename CCM_TYPE::listener_type::_var_type push_observer_dl =
    typename CCM_TYPE::listener_type::_ptr_type
      this->context_->get_connection_push_observer_data_listener ();
  this->push_observer_obtained_ |= ! ::CORBA::is_nil (push_observer_psl.in ());
  this->push_observer_obtained_ |= ! ::CORBA::is_nil (push_observer_dl.in ());

  ::CCM_DDS::PortStatusListener_var push_state_observer_psl =
    this->context_->get_connection_push_state_observer_status ();
  typename CCM_TYPE::listener_type::_var_type push_state_observer_dl =
    typename CCM_TYPE::listener_type::_ptr_type
      this->context_->get_connection_push_state_observer_data_listener ();
  this->push_state_observer_obtained_ |= ! ::CORBA::is_nil (push_state_observer_psl.in ());
  this->push_state_observer_obtained_ |= ! ::CORBA::is_nil (push_state_observer_dl.in ());

  ::CCM_DDS::PortStatusListener_var pull_observer_psl =
    this->context_->get_connection_pull_observer_status ();
  this->pull_observer_obtained_ |= ! ::CORBA::is_nil (pull_observer_psl.in ());

  ::CCM_DDS::PortStatusListener_var passive_observer_psl =
    this->context_->get_connection_passive_observer_status ();
  this->passive_observer_obtained_ |= ! ::CORBA::is_nil (passive_observer_psl.in ());

  if (this->observable_obtained_)
    {
      this->observable_.configuration_complete (
        this->topic_.in (),
        this->publisher_.in (),
        this->library_name_,
        this->profile_name_);
    }

  if (this->push_observer_obtained_)
    {
      this->push_observer_.configuration_complete (
        this->topic_.in (),
        this->subscriber_.in (),
        this->library_name_,
        this->profile_name_);
    }

  if (this->push_state_observer_obtained_)
    {
      this->push_state_observer_.configuration_complete (
        this->topic_.in (),
        this->subscriber_.in (),
        this->library_name_,
        this->profile_name_);
    }

  if (this->pull_observer_obtained_)
    {
      this->pull_observer_.configuration_complete (
        this->topic_.in (),
        this->subscriber_.in (),
        this->library_name_,
        this->profile_name_);
    }

  if (this->passive_observer_obtained_)
    {
      this->passive_observer_.configuration_complete (
        this->topic_.in (),
        this->subscriber_.in (),
        this->library_name_,
        this->profile_name_);
    }
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
void
DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::ccm_activate (void)
{
  DDS4CCM_TRACE ("DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::ccm_activate");

  ACE_Reactor* reactor = 0;
#if (CIAO_DDS4CCM_CONTEXT_SWITCH == 1)
  reactor = this->context_->get_CCM_object()->_get_orb ()->orb_core ()->reactor ();
#endif
  TopicBaseConnector::ccm_activate (reactor);

  if (this->observable_obtained_)
    {
      this->observable_.activate ();
    }

  if (this->push_observer_obtained_)
    {
      this->push_observer_.activate (
        this->context_->get_connection_push_observer_data_listener (),
        this->context_->get_connection_push_observer_status (),
        reactor);
    }

  if (this->push_state_observer_obtained_)
    {
      this->push_state_observer_.activate (
        this->context_->get_connection_push_state_observer_data_listener (),
        this->context_->get_connection_push_state_observer_status (),
        reactor);
    }

  if (this->pull_observer_obtained_)
    {
      this->pull_observer_.activate (
        this->context_->get_connection_pull_observer_status (),
        reactor);
    }

  if (this->passive_observer_obtained_)
    {
      this->passive_observer_.activate (
        this->context_->get_connection_passive_observer_status (),
        reactor);
    }
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
void
DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::ccm_passivate (void)
{
  DDS4CCM_TRACE ("DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::ccm_passivate");
  if (this->observable_obtained_)
    {
      this->observable_.passivate ();
    }

  if (this->push_observer_obtained_)
    {
      this->push_observer_.passivate ();
    }

  if (this->push_state_observer_obtained_)
    {
      this->push_state_observer_.passivate ();
    }

  if (this->pull_observer_obtained_)
    {
      this->pull_observer_.passivate ();
    }

  if (this->passive_observer_obtained_)
    {
      this->passive_observer_.passivate ();
    }

  TopicBaseConnector::ccm_passivate ();
}

template <typename DDS_TYPE, typename CCM_TYPE, bool FIXED>
void
DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::ccm_remove (void)
{
  DDS4CCM_TRACE ("DDS_State_Connector_T<DDS_TYPE, CCM_TYPE, FIXED>::ccm_remove");

  if (this->observable_obtained_)
    {
      this->observable_.remove (this->publisher_.in ());
    }

  if (this->push_observer_obtained_)
    {
      this->push_observer_.remove (this->subscriber_.in ());
    }

  if (this->push_state_observer_obtained_)
    {
      this->push_state_observer_.remove (this->subscriber_.in ());
    }

  if (this->pull_observer_obtained_)
    {
      this->pull_observer_.remove (this->subscriber_.in ());
    }

  if (this->passive_observer_obtained_)
    {
      this->passive_observer_.remove (this->subscriber_.in ());
    }
  TopicBaseConnector::ccm_remove ();
}

