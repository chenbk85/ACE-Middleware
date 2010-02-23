/**
 * @author Johnny Willemsen <jwillemsen@remedy.nl>
 *
 * $Id$
 *
 * Wrapper facade for NDDS.
 */

#ifndef CIAO_RTI_DATAREADERLISTENER_H
#define CIAO_RTI_DATAREADERLISTENER_H

#include "tao/LocalObject.h"

#include "dds4ccm/idl/dds_rtf2_dcpsC.h"
#include "dds4ccm_ndds_impl_export.h"

#if defined (CIAO_DDS4CCM_NDDS) && (CIAO_DDS4CCM_NDDS==1)
# include "ndds/ndds_cpp.h"
#endif

#if defined (CIAO_DDS4CCM_OPENDDS) && (CIAO_DDS4CCM_OPENDDS==1)
typedef ::DDS::DataReaderListener DDSDataReaderListener;
typedef ::DDS::DataReader DDSDataReader;
typedef ::DDS::RequestedDeadlineMissedStatus DDS_RequestedDeadlineMissedStatus;
typedef ::DDS::LivelinessChangedStatus DDS_LivelinessChangedStatus;
typedef ::DDS::RequestedIncompatibleQosStatus DDS_RequestedIncompatibleQosStatus;
typedef ::DDS::SampleRejectedStatus DDS_SampleRejectedStatus;
typedef ::DDS::SubscriptionMatchedStatus DDS_SubscriptionMatchedStatus;
typedef ::DDS::SampleLostStatus DDS_SampleLostStatus;
#endif

namespace CIAO
{
  namespace DDS4CCM
  {
    namespace RTI
    {
      class DDS4CCM_NDDS_IMPL_Export RTI_DataReaderListener_i :
        public virtual ::DDSDataReaderListener
      {
      public:
        // Constructor
        RTI_DataReaderListener_i (::DDS::DataReaderListener_ptr p);

        // Destructor
        virtual ~RTI_DataReaderListener_i (void);

        virtual void on_requested_deadline_missed(::DDSDataReader* reader,
          const ::DDS_RequestedDeadlineMissedStatus& status);

        virtual void on_liveliness_changed(::DDSDataReader* reader,
          const ::DDS_LivelinessChangedStatus& status);

        virtual void on_requested_incompatible_qos(::DDSDataReader* reader,
          const ::DDS_RequestedIncompatibleQosStatus& status);

        virtual void on_sample_rejected(::DDSDataReader* reader,
          const ::DDS_SampleRejectedStatus& status);

        virtual void on_data_available(::DDSDataReader* reader);

        virtual void on_sample_lost(::DDSDataReader* reader,
            const ::DDS_SampleLostStatus& status);

        virtual void on_subscription_matched(::DDSDataReader* reader,
            const ::DDS_SubscriptionMatchedStatus& status);

        ::DDS::DataReaderListener_ptr get_datareaderlistener (void);
      private:
        ::DDS::DataReaderListener_var impl_;
      };
    }
  }
}

#endif
