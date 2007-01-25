// -*- C++ -*-

//============================================================
/**
 * @file RoundTrip_exec.h
 *
 * Header file for the Executor implementation.
 *
 * $Id$
 *
 * @author Diego Sevilla <dsevilla@um.es>
 * @author Arvind S. Krishna <arvindk@dre.vanderbilt.edu>
 */
//============================================================

#ifndef ROUNDTRIP_EXEC_H
#define ROUNDTRIP_EXEC_H

#include "RoundTripEIC.h"
#include "tao/LocalObject.h"
#include "ace/Thread_Manager.h"
#include "ace/Task.h"

namespace MyImpl
{

  /**
   * @class RoundTrip_exec_i
   *
   * RoundTrip executor implementation class.
   */

  class ROUNDTRIP_EXEC_Export RoundTrip_exec_i :
    public virtual Benchmark::RoundTrip_Exec,
    public virtual TAO_Local_RefCounted_Object
  {

  public:
    /// Default constructor.
    RoundTrip_exec_i ();

    /// Operation to test the data
    virtual CORBA::Long makeCall (CORBA::Long data)
      ACE_THROW_SPEC ((CORBA::SystemException));

    virtual ::Benchmark::CCM_LatencyTest*
                        get_latency ()
                ACE_THROW_SPEC ((CORBA::SystemException));

    // Operations from Components::SessionComponent
    virtual void set_session_context (Components::SessionContext_ptr ctx)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::CCMException));

    virtual void ciao_preactivate ()
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::CCMException));

    virtual void ccm_activate ()
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::CCMException));

    virtual void ciao_postactivate  ()
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::CCMException));

    virtual void ccm_passivate ()
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::CCMException));

    virtual void ccm_remove ()
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::CCMException));

    /// Helper function to be called back by timeout_Handler
    void pulse (void);

  protected:

    /// Destructor.
    ~RoundTrip_exec_i ();

  protected:
    /// Copmponent specific context
    Benchmark::CCM_RoundTrip_Context_var context_;

  };

  /**
   * @class RoundTripHome_exec_i
   *
   * RoundTrip home executor implementation class.
   */
  class ROUNDTRIP_EXEC_Export RoundTripHome_exec_i :
    public virtual Benchmark::CCM_RoundTripHome,
    public virtual TAO_Local_RefCounted_Object
  {
  public:
    /// Default ctor.
    RoundTripHome_exec_i ();

    // Implicit home operations.

    virtual ::Components::EnterpriseComponent_ptr
    create ()
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::CCMException));

  protected:

    /// Destructor.
    ~RoundTripHome_exec_i ();

  };

}

extern "C" ROUNDTRIP_EXEC_Export ::Components::HomeExecutorBase_ptr
createRoundTripHome_Impl (void);

#endif /* ROUNDTRIP_EXEC_H */
