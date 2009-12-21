// $Id$

#include "dds4ccm/impl/ndds/DataWriter.h"
#include "dds4ccm/impl/ndds/Utils.h"
#include "dds4ccm/impl/ndds/Coherent_Changes_Guard.h"
#include "dds4ccm/impl/ndds/InstanceHandle_t.h"
#include "ciao/Logger/Log_Macros.h"

// Implementation skeleton constructor
template <typename DDS_TYPE, typename CCM_TYPE >
CIAO::DDS4CCM::RTI::Writer_T<DDS_TYPE, CCM_TYPE>::Writer_T (void)
  : InstanceHandleManager_T<DDS_TYPE, CCM_TYPE, typename CCM_TYPE::writer_type> (),
    is_coherent_write_ (false)
{
  CIAO_TRACE ("CIAO::DDS4CCM::RTI::Writer_T::Writer_T");
}

// Implementation skeleton destructor
template <typename DDS_TYPE, typename CCM_TYPE >
CIAO::DDS4CCM::RTI::Writer_T<DDS_TYPE, CCM_TYPE>::~Writer_T (void)
{
  CIAO_TRACE ("CIAO::DDS4CCM::RTI::Writer_T::~Writer_T");
}

template <typename DDS_TYPE, typename CCM_TYPE >
void
CIAO::DDS4CCM::RTI::Writer_T<DDS_TYPE, CCM_TYPE>::write_i (
  const typename DDS_TYPE::value_type& datum,
  const ::DDS::InstanceHandle_t& instance_handle,
  ::CCM_DDS::DataNumber_t index)
{
  CIAO_TRACE ("CIAO::DDS4CCM::RTI::Writer_T::write_i");

  ::DDS_InstanceHandle_t handle = ::DDS_HANDLE_NIL;
  handle <<= instance_handle;
  DDS_ReturnCode_t const retval = this->impl ()->write (datum, handle);

  if (retval != DDS_RETCODE_OK)
    {
      CIAO_ERROR (1, (LM_ERROR, CLINFO "CIAO::DDS4CCM::RTI::Writer_T::write_i - "
                   "Write unsuccessful, received error code %C\n",
                   translate_retcode (retval)));
      throw CCM_DDS::InternalError (retval, index);
    }
}

template <typename DDS_TYPE, typename CCM_TYPE >
void
CIAO::DDS4CCM::RTI::Writer_T<DDS_TYPE, CCM_TYPE>::write_one (
  const typename DDS_TYPE::value_type & an_instance,
  const ::DDS::InstanceHandle_t & instance_handle)
{
  CIAO_TRACE ("CIAO::DDS4CCM::RTI::Writer_T::write_one");

  this->write_i (an_instance, instance_handle, 0);

  CIAO_DEBUG (9, (LM_TRACE, CLINFO "CIAO::DDS4CCM::RTI::Writer_T::write_one - "
               "Write successful\n"));
}

template <typename DDS_TYPE, typename CCM_TYPE >
void
CIAO::DDS4CCM::RTI::Writer_T<DDS_TYPE, CCM_TYPE>::write_many (
  const typename CCM_TYPE::seq_type& instances)
{
  CIAO_TRACE ("CIAO::DDS4CCM::RTI::Writer_T::write_many");

  Coherent_Changes_Guard guard (this->impl ()->get_publisher(),
                                this->is_coherent_write_);

  CIAO_DEBUG (9, (LM_TRACE, CLINFO "CIAO::DDS4CCM::RTI::Writer_T::write_many - "
               "Preparing to write to DDS\n"));

  for (typename CCM_TYPE::seq_type::size_type index = 0;
       index < instances.length();
       index++)
    {
      this->write_i (instances[index], ::DDS::HANDLE_NIL, index);
    }

  CIAO_DEBUG (9, (LM_TRACE, CLINFO "CIAO::DDS4CCM::RTI::Writer_T::write_many - "
               "Write successful\n"));
}

template <typename DDS_TYPE, typename CCM_TYPE >
::CORBA::Boolean
CIAO::DDS4CCM::RTI::Writer_T<DDS_TYPE, CCM_TYPE>::is_coherent_write (void)
{
  return this->is_coherent_write_;
}

template <typename DDS_TYPE, typename CCM_TYPE >
void
CIAO::DDS4CCM::RTI::Writer_T<DDS_TYPE, CCM_TYPE>::is_coherent_write (
  ::CORBA::Boolean value)
{
  this->is_coherent_write_ = value;
}
