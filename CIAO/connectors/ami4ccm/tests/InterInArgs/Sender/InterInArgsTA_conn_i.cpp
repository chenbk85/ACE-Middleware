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

#include "InterInArgsTA_conn_i.h"


namespace CIAO_InterInArgsT_AMI4CCM_MyFoo_Connector_AMI4CCM_Connector_Impl
{
  CORBA::UShort update_val = InterInArgsT::update_val;
  CORBA::UShort cmd_synch_ok = InterInArgsT::cmd_synch_ok;
  CORBA::UShort cmd_synch_nok = InterInArgsT::cmd_synch_nok;
  CORBA::UShort cmd_asynch_ok = InterInArgsT::cmd_asynch_ok;
  CORBA::UShort cmd_asynch_nok = InterInArgsT::cmd_asynch_nok;


  AMI4CCM_MyFooReplyHandler_i::AMI4CCM_MyFooReplyHandler_i (
      Atomic_UShort &nr_of_received)
  : nr_of_received_(nr_of_received)
  {
  }

  AMI4CCM_MyFooReplyHandler_i::~AMI4CCM_MyFooReplyHandler_i (void)
  {
  }

  void
  AMI4CCM_MyFooReplyHandler_i::foo (
      ::CORBA::Long ami_return_val,
        const char * /*answer*/)
  {
    if ( ami_return_val == ( cmd_asynch_ok + update_val ))
      {
        ++this->nr_of_received_;
      }
  }

  void
  AMI4CCM_MyFooReplyHandler_i::foo_excep (
      ::CCM_AMI::ExceptionHolder * excep_holder)
  {
    try
      {
        excep_holder->raise_exception ();
      }
    catch (const InterInArgsT::InternalError& ex)
      {
        CIAO_InterInArgsT_Sender_Impl::HandleException (ex.id,
                        (cmd_asynch_nok + update_val),
                         ex.error_string.in(), "asynch foo");
      }
    catch (const CORBA::Exception& ex)
      {
        ex._tao_print_exception ("ERROR: Caught unexpected exception:");
      }
  }

  void
  AMI4CCM_MyFooReplyHandler_i::var_ins (
      const char * /*answer*/)
  {
    ++this->nr_of_received_;
  }

  void
  AMI4CCM_MyFooReplyHandler_i::var_ins_excep (
      ::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }

  void
  AMI4CCM_MyFooReplyHandler_i::var_div_ins (const char * /* answer */)
  {
    ++this->nr_of_received_;
  }

  void
  AMI4CCM_MyFooReplyHandler_i::var_div_ins_excep (
      ::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }

  void
  AMI4CCM_MyFooReplyHandler_i::var_div2_ins (const char * /* answer */)
  {
    ++this->nr_of_received_;
  }

  void
  AMI4CCM_MyFooReplyHandler_i::var_div2_ins_excep (
      ::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }

  void
  AMI4CCM_MyFooReplyHandler_i::enum_in (const char * /* answer */)
  {
    ++this->nr_of_received_;
  }

  void
  AMI4CCM_MyFooReplyHandler_i::enum_in_excep (
      ::CCM_AMI::ExceptionHolder_ptr excep_holder)
  {
    excep_holder->raise_exception ();
  }
}
