// $Id$

#include "WaitSet.h"

#include "dds4ccm/idl/dds4ccm_BaseC.h"

#include "dds4ccm/impl/ndds/Condition.h"
#include "dds4ccm/impl/ndds/QueryCondition.h"
#include "dds4ccm/impl/ndds/ReadCondition.h"
#include "dds4ccm/impl/ndds/convertors/Duration_t.h"
#include "dds4ccm/impl/Utils.h"

#include "dds4ccm/impl/logger/Log_Macros.h"

CIAO::NDDS::DDS_WaitSet_i::DDS_WaitSet_i ()
  : impl_ (0)
{
  DDS4CCM_TRACE ("CIAO::NDDS::DDS_WaitSet_i::DDS_WaitSet_i");
}

CIAO::NDDS::DDS_WaitSet_i::~DDS_WaitSet_i (void)
{
  DDS4CCM_TRACE ("CIAO::NDDS::DDS_WaitSet_i::~DDS_WaitSet_i");

  delete this->impl_;
}

::DDS::ReturnCode_t
CIAO::NDDS::DDS_WaitSet_i::wait (::DDS::ConditionSeq & active_conditions,
      const ::DDS::Duration_t & timeout)
{
  DDS4CCM_TRACE ("CIAO::NDDS::DDS_WaitSet_i::wait");

  DDS_Duration_t dds_timeout;
  dds_timeout <<= timeout;

  DDSConditionSeq dds_conditions;
  DDS_ReturnCode_t const retcode =
     this->impl ()->wait (dds_conditions, dds_timeout);

  this->convert_conditions (dds_conditions, active_conditions);

  return retcode;
}

::DDS::ReturnCode_t
CIAO::NDDS::DDS_WaitSet_i::attach_condition (::DDS::Condition_ptr cond)
{
  DDS4CCM_TRACE ("CIAO::NDDS::DDS_WaitSet_i::attach_condition");

  ::DDS::ReadCondition_var rc_cond = ::DDS::ReadCondition::_narrow (cond);
  ::DDS::QueryCondition_var qc_cond = ::DDS::QueryCondition::_narrow (cond);

  if (! ::CORBA::is_nil (qc_cond.in ()))
    {
      DDS_QueryCondition_i * qc_proxy =
        dynamic_cast <DDS_QueryCondition_i *> (qc_cond.in ());
      if (qc_proxy)
        {
          return this->impl ()->attach_condition (qc_proxy->get_rti_entity ());
        }
    }
  else if (! ::CORBA::is_nil (rc_cond.in ()))
    {
      DDS_ReadCondition_i * rc_proxy =
        dynamic_cast <DDS_ReadCondition_i *> (rc_cond.in ());
      if (rc_proxy)
        {
          return this->impl ()->attach_condition (rc_proxy->get_rti_entity ());
        }
    }
  return ::DDS::RETCODE_BAD_PARAMETER;
}

::DDS::ReturnCode_t
CIAO::NDDS::DDS_WaitSet_i::detach_condition (::DDS::Condition_ptr cond)
{
  DDS4CCM_TRACE ("CIAO::NDDS::DDS_WaitSet_i::detach_condition");

  ::DDS::ReadCondition_var rc_cond = ::DDS::ReadCondition::_narrow (cond);
  ::DDS::QueryCondition_var qc_cond = ::DDS::QueryCondition::_narrow (cond);

  if (! ::CORBA::is_nil (rc_cond.in ()))
    {
      DDS_ReadCondition_i * rc_proxy =
        dynamic_cast <DDS_ReadCondition_i *> (rc_cond.in ());
      if (rc_proxy)
        {
          return this->impl ()->detach_condition (rc_proxy->get_rti_entity ());
        }
    }
  else if (! ::CORBA::is_nil (qc_cond.in ()))
    {
      DDS_QueryCondition_i * qc_proxy =
        dynamic_cast <DDS_QueryCondition_i *> (qc_cond.in ());
      if (qc_proxy)
        {
          return this->impl ()->detach_condition (qc_proxy->get_rti_entity ());
        }
    }
  return ::DDS::RETCODE_BAD_PARAMETER;
}

::DDS::ReturnCode_t
CIAO::NDDS::DDS_WaitSet_i::get_conditions (::DDS::ConditionSeq & attached_conditions)
{
  DDS4CCM_TRACE ("CIAO::NDDS::DDS_WaitSet_i::get_conditions");

  DDSConditionSeq dds_seq;
  ::DDS::ReturnCode_t retcode = this->impl ()->get_conditions (dds_seq);

  if (retcode != ::DDS::RETCODE_OK)
    {
      DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_ERROR, (LM_ERROR, DDS4CCM_INFO
                    "DDS_WaitSet_i::get_conditions - "
                    "Error while calling get_conditions: <%C>\n",
                    CIAO::DDS4CCM::translate_retcode (retcode)));
      return retcode;
    }
  this->convert_conditions (dds_seq, attached_conditions);
  return retcode;
}


DDSWaitSet *
CIAO::NDDS::DDS_WaitSet_i::get_impl (void)
{
  return this->impl_;
}

void
CIAO::NDDS::DDS_WaitSet_i::init (void)
{
  DDS4CCM_TRACE ("CIAO::NDDS::DDS_WaitSet_i::init");
  if (!this->impl_)
    {
      ACE_NEW_THROW_EX (this->impl_,
                        DDSWaitSet (),
                        ::CORBA::NO_MEMORY ());
    }
}

void
CIAO::NDDS::DDS_WaitSet_i::convert_conditions (const DDSConditionSeq& dds_conditions,
                                               ::DDS::ConditionSeq & conditions)
{
  DDS4CCM_TRACE ("CIAO::NDDS::DDS_WaitSet_i::convert_conditions");

  conditions.length (dds_conditions.length ());

  for (DDS_Long i = 0;
       i < dds_conditions.length();
       ++i)
    {
      DDSQueryCondition * dds_qc =
        dynamic_cast <DDSQueryCondition *> (dds_conditions[i]);
      if (dds_qc)
        {
          DDS_QueryCondition_i * cond;
          //TODO : Which DataReader ??
          ACE_NEW_THROW_EX (cond,
                            DDS_QueryCondition_i (dds_qc,
                                                  ::DDS::DataReader::_nil ()),
                            ::CORBA::NO_MEMORY ());
          conditions[i] = cond;
        }
      else
        {
          DDSReadCondition * dds_rc =
            dynamic_cast <DDSReadCondition *> (dds_conditions[i]);
          if (dds_rc)
            {
              DDS_ReadCondition_i * cond;
              //TODO : Which DataReader ??
              ACE_NEW_THROW_EX (cond,
                                DDS_ReadCondition_i (dds_rc,
                                                     ::DDS::DataReader::_nil ()),
                                ::CORBA::NO_MEMORY ());
              conditions[i] = cond;
            }
        }
    }
}

DDSWaitSet *
CIAO::NDDS::DDS_WaitSet_i::impl (void)
{
  if (!this->impl_)
    {
      throw ::CORBA::BAD_INV_ORDER ();
    }
  return this->impl_;
}

