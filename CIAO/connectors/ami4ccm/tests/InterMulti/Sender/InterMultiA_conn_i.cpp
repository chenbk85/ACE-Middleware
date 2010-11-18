// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.8.3
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// be/be_codegen.cpp:1661

#include "InterMultiA_conn_i.h"

namespace CIAO_InterMulti_AMI4CCM_One_Connector_AMI4CCM_Connector_Impl
{
  AMI4CCM_OneReplyHandler_i::AMI4CCM_OneReplyHandler_i (
      Atomic_UShort &nr_of_received)
  : nr_of_received_(nr_of_received)
  {
  }

  AMI4CCM_OneReplyHandler_i::~AMI4CCM_OneReplyHandler_i (void)
  {
  }

  void
  AMI4CCM_OneReplyHandler_i::foo (::CORBA::Long /* ami_return_val */,
      const char * answer)
  {
    ACE_DEBUG ((LM_DEBUG, "OK: Get asynchronous callback from ONE::foo,"
                          " answer = <%C>\n",
                          answer));
    ++this->nr_of_received_;  }

  void
  AMI4CCM_OneReplyHandler_i::foo_excep (
      ::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }
}

namespace CIAO_InterMulti_AMI4CCM_Two_Connector_AMI4CCM_Connector_Impl
{
  AMI4CCM_TwoReplyHandler_i::AMI4CCM_TwoReplyHandler_i (
      Atomic_UShort &nr_of_received)
  : nr_of_received_(nr_of_received)

  {
  }

  AMI4CCM_TwoReplyHandler_i::~AMI4CCM_TwoReplyHandler_i (void)
  {
  }

  void
  AMI4CCM_TwoReplyHandler_i::bar (const char * answer)
  {
    ACE_DEBUG ((LM_DEBUG, "OK: Get asynchronous callback from TWO::bar,"
                          " answer = <%C>\n",
                          answer));
    ++this->nr_of_received_;
  }

  void
  AMI4CCM_TwoReplyHandler_i::bar_excep (
      ::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }
}

namespace CIAO_InterMulti_AMI4CCM_Three_Connector_AMI4CCM_Connector_Impl
{
  AMI4CCM_ThreeReplyHandler_i::AMI4CCM_ThreeReplyHandler_i (
      Atomic_UShort &nr_of_received)
  : nr_of_received_(nr_of_received)

  {
  }

  AMI4CCM_ThreeReplyHandler_i::~AMI4CCM_ThreeReplyHandler_i (void)
  {
  }

  void
  AMI4CCM_ThreeReplyHandler_i::foo (::CORBA::Long /* ami_return_val */,
  const char * answer)
  {
    ACE_DEBUG ((LM_DEBUG, "OK: Get asynchronous callback from THREE::foo,"
                          " answer = <%C>\n",
                          answer));
    ++this->nr_of_received_;
 }

  void
  AMI4CCM_ThreeReplyHandler_i::foo_excep (
      ::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }

  void
  AMI4CCM_ThreeReplyHandler_i::bar (const char * answer)
  {
    ACE_DEBUG ((LM_DEBUG, "OK: Get asynchronous callback from THREE::bar,"
                           " answer = <%C>\n",
                           answer));
     ++this->nr_of_received_;
 }

  void
  AMI4CCM_ThreeReplyHandler_i::bar_excep (:
      :CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }

  void
  AMI4CCM_ThreeReplyHandler_i::plus (const char * answer )
  {
    ACE_DEBUG ((LM_DEBUG, "OK: Get asynchronous callback from THREE::plus,"
                          " answer = <%C>\n",
                          answer));
     ++this->nr_of_received_;
  }

  void
  AMI4CCM_ThreeReplyHandler_i::plus_excep (
      ::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }
}
