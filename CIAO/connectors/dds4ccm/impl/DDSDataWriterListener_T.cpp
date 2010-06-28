// $Id$

#include "DataWriterListener_T.h"
#include "DataWriter_T.h"
#include "ndds/PublicationMatchedStatus.h"
#include "ndds/LivelinessLostStatus.h"
#include "ndds/OfferedIncompatibleQosStatus.h"
#include "ndds/OfferedDeadlineMissedStatus.h"

#include "dds4ccm/impl/dds4ccm_conf.h"
#include "dds4ccm/impl/Log_Macros.h"

namespace CIAO
{
  namespace DDS4CCM
  {
    template <typename DDS_TYPE, typename CCM_TYPE, DDS4CCM_Vendor VENDOR_TYPE>
    CCM_DDS_DataWriterListener_T<DDS_TYPE, CCM_TYPE, VENDOR_TYPE>::CCM_DDS_DataWriterListener_T (
      ::DDS::DataWriterListener_ptr s,
      DataWriter_type * typed_dw)
      : impl_ (::DDS::DataWriterListener::_duplicate (s)),
        typed_dw_ (typed_dw)
    {
    }

    template <typename DDS_TYPE, typename CCM_TYPE, DDS4CCM_Vendor VENDOR_TYPE>
    CCM_DDS_DataWriterListener_T<DDS_TYPE, CCM_TYPE, VENDOR_TYPE>::~CCM_DDS_DataWriterListener_T (void)
    {
    }

    template <typename DDS_TYPE, typename CCM_TYPE, DDS4CCM_Vendor VENDOR_TYPE>
    void
    CCM_DDS_DataWriterListener_T<DDS_TYPE, CCM_TYPE, VENDOR_TYPE>::on_offered_deadline_missed (
      ::DDSDataWriter *,
      const ::DDS_OfferedDeadlineMissedStatus & status)
    {
      DDS4CCM_TRACE ("CCM_DDS_DataWriterListener_T<DDS_TYPE, CCM_TYPE, VENDOR_TYPE>::on_offered_deadline_missed");
      ::DDS::OfferedDeadlineMissedStatus ddsstatus;
      ddsstatus <<= status;
      this->impl_->on_offered_deadline_missed (
        this->typed_dw_,
        ddsstatus);
    }

    template <typename DDS_TYPE, typename CCM_TYPE, DDS4CCM_Vendor VENDOR_TYPE>
    void
    CCM_DDS_DataWriterListener_T<DDS_TYPE, CCM_TYPE, VENDOR_TYPE>::on_offered_incompatible_qos (
      ::DDSDataWriter *,
      const ::DDS_OfferedIncompatibleQosStatus & status)
    {
      DDS4CCM_TRACE ("CCM_DDS_DataWriterListener_T<DDS_TYPE, CCM_TYPE, VENDOR_TYPE>::on_offered_incompatible_qos");
      ::DDS::OfferedIncompatibleQosStatus ddsstatus;
      ddsstatus <<= status;
      this->impl_->on_offered_incompatible_qos (
        this->typed_dw_,
        ddsstatus);
    }

    template <typename DDS_TYPE, typename CCM_TYPE, DDS4CCM_Vendor VENDOR_TYPE>
    void
    CCM_DDS_DataWriterListener_T<DDS_TYPE, CCM_TYPE, VENDOR_TYPE>::on_liveliness_lost (
      ::DDSDataWriter *,
      const ::DDS_LivelinessLostStatus & status)
    {
      DDS4CCM_TRACE ("CCM_DDS_DataWriterListener_T<DDS_TYPE, CCM_TYPE, VENDOR_TYPE>::on_liveliness_lost");
      ::DDS::LivelinessLostStatus ddsstatus;
      ddsstatus <<= status;
      this->impl_->on_liveliness_lost (
        this->typed_dw_,
        ddsstatus);
    }

    template <typename DDS_TYPE, typename CCM_TYPE, DDS4CCM_Vendor VENDOR_TYPE>
    void
    CCM_DDS_DataWriterListener_T<DDS_TYPE, CCM_TYPE, VENDOR_TYPE>::on_publication_matched (
      ::DDSDataWriter *,
      const ::DDS_PublicationMatchedStatus & status)
    {
      DDS4CCM_TRACE ("CCM_DDS_DataWriterListener_T<DDS_TYPE, CCM_TYPE, VENDOR_TYPE>::on_publication_matched");
      ::DDS::PublicationMatchedStatus ddsstatus;
      ddsstatus <<= status;
      this->impl_->on_publication_matched (this->typed_dw_, ddsstatus);
    }

    template <typename DDS_TYPE, typename CCM_TYPE, DDS4CCM_Vendor VENDOR_TYPE>
    ::DDS::DataWriterListener_ptr
    CCM_DDS_DataWriterListener_T<DDS_TYPE, CCM_TYPE, VENDOR_TYPE>::get_datawriterlistener (void)
    {
      return ::DDS::DataWriterListener::_duplicate (this->impl_.in ());
    }
  }
}

