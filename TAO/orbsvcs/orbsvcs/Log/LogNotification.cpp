/* -*- C++ -*- $Id$ */

#include "orbsvcs/Log/LogNotification.h"
#include "orbsvcs/Time_Utilities.h"
#include "tao/debug.h"

LogNotification::LogNotification (void)
{
  // No-Op.
}

LogNotification::~LogNotification (void)
{
  // No-Op.
}

void
LogNotification::object_creation (DsLogAdmin::Log_ptr log,
                                 DsLogAdmin::LogId id
                                 ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_UNUSED_ARG (log);
  
  CORBA::Any any;
  DsLogNotification::ObjectCreation event;

  // The log id.
  event.id = id;

  TimeBase::TimeT current_time;
  ACE_Time_Value now = ACE_OS::gettimeofday ();
  ORBSVCS_Time::Time_Value_to_TimeT(current_time, now);

  event.time = current_time;

  any <<= event;

  send_notification (any);
}

void
LogNotification::object_deletion (DsLogAdmin::LogId id
                                 ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::Any any;
  DsLogNotification::ObjectDeletion event;

  event.id = id;

  TimeBase::TimeT current_time;
  ACE_Time_Value now = ACE_OS::gettimeofday ();
  ORBSVCS_Time::Time_Value_to_TimeT(current_time, now);

  // Time object deleted.
  event.time = current_time;

  any <<= event;

  send_notification (any);
}

void
LogNotification::processing_error_alarm (CORBA::ULong error_num,
                                 const char* error_string
                                 ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::Any any;
  DsLogNotification::ProcessingErrorAlarm event;

  event.error_num = error_num;
  event.error_string = CORBA::string_dup (error_string);

  any <<= event;

  send_notification (any);
}

void
LogNotification::attribute_value_change (DsLogAdmin::Log_ptr log,
                                 DsLogAdmin::LogId id,
                                 DsLogNotification::AttributeType type,
                                 CORBA::Any oldValue,
                                 CORBA::Any newValue
                                 ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::Any any;
  DsLogNotification::AttributeValueChange event;

  event.logref = log;
  event.id = id;

  TimeBase::TimeT current_time;
  ACE_Time_Value now = ACE_OS::gettimeofday ();
  ORBSVCS_Time::Time_Value_to_TimeT(current_time, now);

  event.time = current_time;

  // The attribute type e.g. logFullAction, maxLogSize etc.
  event.type = type;
  event.old_value = oldValue;
  event.new_value = newValue;

  any <<= event;

  send_notification (any);
}

void
LogNotification::capacity_alarm_threshold_value_change (DsLogAdmin::Log_ptr log,
                                 DsLogAdmin::LogId id,
                                 const DsLogAdmin::CapacityAlarmThresholdList& oldValue,
                                 const DsLogAdmin::CapacityAlarmThresholdList& newValue
                                 ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::Any oldV, newV;
  oldV <<= oldValue;
  newV <<= newValue;

  attribute_value_change (log, id, DsLogNotification::capacityAlarmThreshold,
                          oldV, newV ACE_ENV_ARG_PARAMETER);
}

void
LogNotification::log_full_action_value_change (DsLogAdmin::Log_ptr log,
                                 DsLogAdmin::LogId id,
                                 CORBA::ULong oldValue,
                                 CORBA::ULong newValue
                                 ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::Any oldV, newV;
  oldV <<= oldValue;
  newV <<= newValue;

  attribute_value_change (log, id, DsLogNotification::logFullAction,
                          oldV, newV ACE_ENV_ARG_PARAMETER);
}

void
LogNotification::max_log_size_value_change (DsLogAdmin::Log_ptr log,
                                 DsLogAdmin::LogId id,
                                 CORBA::ULongLong oldValue,
                                 CORBA::ULongLong newValue
                                 ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::Any oldV, newV;
  oldV <<= oldValue;
  newV <<= newValue;

  attribute_value_change (log, id, DsLogNotification::maxLogSize,
                          oldV, newV ACE_ENV_ARG_PARAMETER);
}

void
LogNotification::start_time_value_change (DsLogAdmin::Log_ptr log,
                                 DsLogAdmin::LogId id,
                                 DsLogAdmin::TimeT oldValue,
                                 DsLogAdmin::TimeT newValue
                                 ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::Any oldV, newV;
  oldV <<= oldValue;
  newV <<= newValue;

  attribute_value_change (log, id, DsLogNotification::startTime,
                          oldV, newV ACE_ENV_ARG_PARAMETER);
}

void
LogNotification::stop_time_value_change (DsLogAdmin::Log_ptr log,
                                 DsLogAdmin::LogId id,
                                 DsLogAdmin::TimeT oldValue,
                                 DsLogAdmin::TimeT newValue
                                 ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::Any oldV, newV;
  oldV <<= oldValue;
  newV <<= newValue;

  attribute_value_change (log, id, DsLogNotification::stopTime,
                          oldV, newV ACE_ENV_ARG_PARAMETER);
}

void
LogNotification::week_mask_value_change (DsLogAdmin::Log_ptr log,
                                 DsLogAdmin::LogId id,
                                 const DsLogAdmin::WeekMask& oldValue,
                                 const DsLogAdmin::WeekMask& newValue
                                 ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::Any oldV, newV;
  oldV <<= oldValue;
  newV <<= newValue;

  attribute_value_change (log, id, DsLogNotification::weekMask,
                          oldV, newV ACE_ENV_ARG_PARAMETER);
}

void
LogNotification::max_record_life_value_change (DsLogAdmin::Log_ptr log,
                                 DsLogAdmin::LogId id,
                                 CORBA::ULong oldValue,
                                 CORBA::ULong newValue
                                 ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::Any oldV, newV;
  oldV <<= oldValue;
  newV <<= newValue;

  attribute_value_change (log, id, DsLogNotification::maxRecordLife,
                          oldV, newV ACE_ENV_ARG_PARAMETER);
}

void
LogNotification::quality_of_service_value_change (DsLogAdmin::Log_ptr log,
                                 DsLogAdmin::LogId id,
                                 const DsLogAdmin::QoSList& oldValue,
                                 const DsLogAdmin::QoSList& newValue
                                 ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::Any oldV, newV;
  oldV <<= oldValue;
  newV <<= newValue;

  attribute_value_change (log, id, DsLogNotification::qualityOfService,
                          oldV, newV ACE_ENV_ARG_PARAMETER);
}

void
LogNotification::state_change (DsLogAdmin::Log_ptr log,
                                 DsLogAdmin::LogId id,
                                 DsLogNotification::StateType type,
                                 CORBA::Any newValue
                                 ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_UNUSED_ARG (log);

  CORBA::Any any;
  DsLogNotification::StateChange event;

  // The log id.
  event.id = id;

  TimeBase::TimeT current_time;
  ACE_Time_Value now = ACE_OS::gettimeofday ();
  ORBSVCS_Time::Time_Value_to_TimeT(current_time, now);
  event.time = current_time;

  // Administrative, Operational or Forwarding state.
  event.type = type;

  event.new_value = newValue;

  any <<= event;

  send_notification (any);
}

void
LogNotification::administrative_state_change (DsLogAdmin::Log_ptr log,
                                 DsLogAdmin::LogId id,
                                 DsLogAdmin::AdministrativeState newValue
                                 ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::Any newV;
  newV <<= newValue;

  state_change (log, id, DsLogNotification::administrativeState,
                        newV ACE_ENV_ARG_PARAMETER);
}

void
LogNotification::operational_state_change (DsLogAdmin::Log_ptr log,
                                 DsLogAdmin::LogId id,
                                 DsLogAdmin::OperationalState newValue
                                 ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::Any newV;
  newV <<= newValue;

  state_change (log, id, DsLogNotification::operationalState,
                        newV ACE_ENV_ARG_PARAMETER);
}

void
LogNotification::forwarding_state_change (DsLogAdmin::Log_ptr log,
                                 DsLogAdmin::LogId id,
                                 DsLogAdmin::ForwardingState newValue
                                 ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::Any newV;
  newV <<= newValue;

  state_change (log, id, DsLogNotification::forwardingState,
                        newV ACE_ENV_ARG_PARAMETER);
}

void
LogNotification::threshold_alarm (DsLogAdmin::Log_ptr log,
                                 DsLogAdmin::LogId id,
                                 DsLogAdmin::Threshold crossedValue,
                                 DsLogAdmin::Threshold observedValue,
                                 DsLogNotification::PerceivedSeverityType severity
                                 ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_UNUSED_ARG (log);

  CORBA::Any any;
  DsLogNotification::ThresholdAlarm event;

  event.id = id;

  TimeBase::TimeT current_time;
  ACE_Time_Value now = ACE_OS::gettimeofday ();
  ORBSVCS_Time::Time_Value_to_TimeT(current_time, now);
  event.time = current_time;

  event.crossed_value = crossedValue;
  event.observed_value = observedValue;
  event.perceived_severity = severity;

  any <<= event;

  send_notification (any);
}

