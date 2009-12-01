// $Id$
/**
 * @author Marcel Smit <msmit@remedy.nl>
 *
 * $Id$
 *
 * Eventhandler on orb thread, handling the
 * received data from DDS.
 */

#ifndef CIAO_RTI_DATAREADERHANDLER_T_H
#define CIAO_RTI_DATAREADERHANDLER_T_H

#include "dds4ccm/idl/dds_rtf2_dcpsC.h"
#include "ace/Reactor.h"

namespace CIAO
{
  namespace DDS4CCM
  {
    namespace RTI
    {
      template <typename DDS_TYPE, typename CCM_TYPE>
      class DataReaderHandler_T :
        public ACE_Event_Handler
      {
        public:
          DataReaderHandler_T (
              typename CCM_TYPE::listener_type::_ptr_type listener,
              typename DDS_TYPE::data_reader * reader);
          virtual ~DataReaderHandler_T ();

          virtual int handle_exception (ACE_HANDLE fc = ACE_INVALID_HANDLE);
        private:
          typename DDS_TYPE::data_reader * reader_;
          typename CCM_TYPE::listener_type::_var_type listener_;
      };
    }
  }
}

#include "dds4ccm/impl/ndds/DataReaderHandler_T.cpp"

#endif
