// -*- C++ -*-
// $Id$

#ifndef CIAO_SENDER_EXEC_H_
#define CIAO_SENDER_EXEC_H_


#include "Writer_SenderEC.h"

#include /**/ "Sender_exec_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/LocalObject.h"

#include <map>

namespace CIAO_Writer_Sender_Impl
{
  class Sender_exec_i;
  
  enum WRITER_ASSIGNMENT {
    WRITE_NONE,
    WRITE_UNKEYED,
    WRITE_MULTI
  };

  class pulse_Generator :
    public ACE_Event_Handler
  {
  public:
    pulse_Generator (Sender_exec_i &callback);
    /// Handle the timeout.
    virtual int handle_timeout (const ACE_Time_Value &tv,
                                const void *arg);
  private:
    /// Maintains a handle that actually process the event
    Sender_exec_i &pulse_callback_;
  };

  class Sender_exec_i
    : public virtual Sender_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Sender_exec_i (void);
    virtual ~Sender_exec_i (void);

    virtual ::CORBA::UShort rate (void);

    virtual void rate (::CORBA::UShort rate);

    virtual ::CORBA::UShort iterations (void);

    virtual void iterations (::CORBA::UShort iterations);

    virtual ::CORBA::UShort keys (void);

    virtual void keys (::CORBA::UShort keys);

    virtual void set_session_context (::Components::SessionContext_ptr ctx);

    virtual void configuration_complete (void);

    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);

    void tick ();

  private:
    void start (void);
    void stop (void);

    CCM_DDS::WriterTest::Writer_var writer_;

    pulse_Generator * ticker_;
    ::Writer::CCM_Sender_Context_var context_;
    CORBA::UShort rate_;
    CORBA::UShort iterations_;
    CORBA::UShort keys_;
    WRITER_ASSIGNMENT assignment_;
    CORBA::Long last_iteration_;

    void reset_iterations ();
    void start_new_assignment (
        WRITER_ASSIGNMENT assignment);
    void write_unkeyed ();
    void write_many ();

    TAO_SYNCH_MUTEX mutex_;
    typedef std::map<ACE_CString, WriterTest_var> Writer_Table;
    Writer_Table ktests_;

    Writer_Table::iterator last_key;
  };

  extern "C" SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Writer_Sender_Impl (void);
}

#endif /* ifndef */

