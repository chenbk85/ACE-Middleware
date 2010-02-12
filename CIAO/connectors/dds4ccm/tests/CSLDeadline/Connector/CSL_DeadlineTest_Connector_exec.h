// -*- C++ -*-
// $Id$

#ifndef CSL_DEADLINETEST_CONNECTOR_EXEC_H_
#define CSL_DEADLINETEST_CONNECTOR_EXEC_H_

#include /**/ "ace/pre.h"

#include "CSL_DeadlineTest_ConnectorEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "CSL_DeadlineTest_Connector_exec_export.h"

#include "dds4ccm/impl/ndds/DDS4CCM_Traits.h"
#include "dds4ccm/impl/ndds/DDS_Event_Connector_T.h"


#include "Base/CSL_DeadlineTest_BaseSupport.h"

namespace CIAO_CSL_DeadlineTest_CSL_DeadlineTest_Connector_Impl
{

  // @from use of CSL_DeadlineTest as a parameter
  typedef CIAO::DDS4CCM::RTI::Type_Traits <
    TestTopic,
    TestTopicSeq,
    TestTopicTypeSupport,
    TestTopicDataWriter,
    TestTopicDataReader > TestTopic_DDS_Traits;

  typedef CIAO::DDS4CCM::Connector_Traits <
    ::CIAO_CSL_DeadlineTest_CSL_DeadlineTest_Connector_Impl::CSL_DeadlineTest_Connector_Exec,
    TestTopic_Seq,
    ::CSL_DeadlineTest::TestTopicConn::CCM_Writer,
    ::CSL_DeadlineTest::TestTopicConn::CCM_Updater,
    ::CSL_DeadlineTest::TestTopicConn::CCM_Getter,
    ::CSL_DeadlineTest::TestTopicConn::CCM_Reader,
    ::CSL_DeadlineTest::CCM_CSL_DeadlineTest_Connector_Context,
    ::CSL_DeadlineTest::TestTopicConn::Listener,
    ::CSL_DeadlineTest::TestTopicConn::StateListener,
    ::CCM_DDS::ConnectorStatusListener> TestTopic_Connector_Traits;

  class CSL_DEADLINETEST_CONNECTOR_EXEC_Export CSL_DeadlineTest_Connector_exec_i :
    public DDS_Event_Connector_T <TestTopic_DDS_Traits, TestTopic_Connector_Traits>
  {
  public:
    CSL_DeadlineTest_Connector_exec_i (void);
    virtual ~CSL_DeadlineTest_Connector_exec_i (void);
  };

  extern "C" CSL_DEADLINETEST_CONNECTOR_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_CSL_DeadlineTest_CSL_DeadlineTest_Connector_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */

