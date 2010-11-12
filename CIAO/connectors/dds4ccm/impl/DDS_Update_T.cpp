// -*- C++ -*-
// $Id$

#include "dds4ccm/impl/DataReaderStateListener_T.h"
#include "dds4ccm/impl/DataWriterListener_T.h"
#include "dds4ccm/impl/Updater_T.h"

#if (CIAO_DDS4CCM_NDDS==1)
#include "dds4ccm/impl/ndds/DataWriter_T.h"
#endif

#include "dds4ccm/impl/logger/Log_Macros.h"

template <typename DDS_TYPE, typename CCM_TYPE>
DDS_Update_T<DDS_TYPE, CCM_TYPE>::DDS_Update_T (void)
{
}

template <typename DDS_TYPE, typename CCM_TYPE>
DDS_Update_T<DDS_TYPE, CCM_TYPE>::~DDS_Update_T (void)
{
}

template <typename DDS_TYPE, typename CCM_TYPE>
void
DDS_Update_T<DDS_TYPE, CCM_TYPE>::set_component (::CORBA::Object_ptr component)
{
  this->dds_update_->_set_component (component);
}

template <typename DDS_TYPE, typename CCM_TYPE>
void
DDS_Update_T<DDS_TYPE, CCM_TYPE>::configuration_complete (
  ::DDS::Topic_ptr topic,
  ::DDS::Publisher_ptr publisher,
  const char* library_name,
  const char* profile_name)
{
  DDS4CCM_TRACE ("DDS_Update_T<DDS_TYPE, CCM_TYPE>::configuration_complete");
  if (!this->ccm_dds_writer_->get_rti_entity ())
    {
      ::DDS::DataWriter_var dwv_tmp;
      if (library_name && profile_name)
        {
          dwv_tmp = publisher->create_datawriter_with_profile (
              topic,
              library_name,
              profile_name,
              ::DDS::DataWriterListener::_nil (),
              0);
        }
      else
        {
          ::DDS::DataWriterQos dwqos;
          dwv_tmp = publisher->create_datawriter (
              topic,
              dwqos,
              ::DDS::DataWriterListener::_nil (),
              0);
        }
      if (::CORBA::is_nil (dwv_tmp.in ()))
        {
          DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_DDS_NIL_RETURN, (LM_ERROR, DDS4CCM_INFO
                        "DDS_Update_T::configuration_complete - "
                        "Error: Proxy returned a nil datawriter.\n"));
          throw ::CCM_DDS::InternalError (::DDS::RETCODE_ERROR, 0);
        }

      DataWriter_type  *rw = dynamic_cast < DataWriter_type *> (dwv_tmp.in ());

      if (!rw)
        {
          DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_ERROR, (LM_ERROR, DDS4CCM_INFO
                        "DDS_Update_T::configuration_complete - "
                        "Unable to cast created DataWriter proxy to its "
                        "internal represenation.\n"));
          throw ::CORBA::INTERNAL ();
        }
      this->ccm_dds_writer_->set_rti_entity (rw->get_rti_entity ());
      this->dds_update_->set_dds_writer (dwv_tmp.in ());
      this->ccm_data_writer_->set_dds_entity (this->ccm_dds_writer_);
    }
}

template <typename DDS_TYPE, typename CCM_TYPE>
void
DDS_Update_T<DDS_TYPE, CCM_TYPE>::activate ()
{
  DDS4CCM_TRACE ("DDS_Update_T<DDS_TYPE, CCM_TYPE>::activate");

  ::DDS::StatusMask const mask =
    DataWriterListener_type::get_mask ();

  if (mask != 0)
    {
      if (::CORBA::is_nil (this->data_listener_.in ()))
        {
          ACE_NEW_THROW_EX (this->data_listener_,
                            DataWriterListener_type (),
                            ::CORBA::NO_MEMORY ());
        }

      ::DDS::ReturnCode_t const retcode = this->ccm_dds_writer_->set_listener (
        this->data_listener_.in (), mask);

      if (retcode != ::DDS::RETCODE_OK)
        {
          DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_ERROR, (LM_ERROR, DDS4CCM_INFO
                        "DDS_Update_T::activate - "
                        "Error while setting the listener on the updater - <%C>\n",
                        ::CIAO::DDS4CCM::translate_retcode (retcode)));
          throw ::CORBA::INTERNAL ();
        }
    }
}

template <typename DDS_TYPE, typename CCM_TYPE>
void
DDS_Update_T<DDS_TYPE, CCM_TYPE>::passivate ()
{
  DDS4CCM_TRACE ("DDS_Update_T<DDS_TYPE, CCM_TYPE>::passivate");

  if (!::CORBA::is_nil (this->data_listener_.in ()))
    {
      ::DDS::ReturnCode_t const retcode =
        this->ccm_dds_writer_->set_listener (::DDS::DataWriterListener::_nil (), 0);

      if (retcode != ::DDS::RETCODE_OK)
        {
          DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_ERROR, (LM_ERROR, DDS4CCM_INFO
                        "DDS_Update_T::passivate - "
                        "Error while setting the listener on the writer - <%C>\n",
                        ::CIAO::DDS4CCM::translate_retcode (retcode)));
          throw ::CORBA::INTERNAL ();
        }

      this->data_listener_ = ::DDS::DataWriterListener::_nil ();
    }
}

template <typename DDS_TYPE, typename CCM_TYPE>
void
DDS_Update_T<DDS_TYPE, CCM_TYPE>::remove (
  ::DDS::Publisher_ptr publisher)
{
  DDS4CCM_TRACE ("DDS_Update_T<DDS_TYPE, CCM_TYPE>::remove");

  ::DDS::ReturnCode_t const retval =
    publisher->delete_datawriter (this->ccm_dds_writer_);
  if (retval != ::DDS::RETCODE_OK)
    {
      DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_ERROR, (LM_ERROR, DDS4CCM_INFO
        "DDS_Update_T::remove - "
        "Unable to delete DataWriter: <%C>\n",
        ::CIAO::DDS4CCM::translate_retcode (retval)));
      throw ::CORBA::INTERNAL ();
    }
  this->ccm_dds_writer_->set_rti_entity (0);
  this->dds_update_->_set_component (::CORBA::Object::_nil ());
  this->dds_update_->set_dds_writer (::DDS::DataWriter::_nil ());
}

template <typename DDS_TYPE, typename CCM_TYPE>
typename CCM_TYPE::updater_type::_ptr_type
DDS_Update_T<DDS_TYPE, CCM_TYPE>::get_data (void)
{
  DDS4CCM_TRACE ("DDS_Update_T<DDS_TYPE, CCM_TYPE>::get_data");

  return CCM_TYPE::updater_type::_duplicate (this->dds_update_);
}

template <typename DDS_TYPE, typename CCM_TYPE>
typename CCM_TYPE::datawriter_type::_ptr_type
DDS_Update_T<DDS_TYPE, CCM_TYPE>::get_dds_entity (void)
{
  DDS4CCM_TRACE ("DDS_Update_T<DDS_TYPE, CCM_TYPE>::get_dds_entity");

  return ::DDS::CCM_DataWriter::_duplicate (this->ccm_data_writer_);
}

