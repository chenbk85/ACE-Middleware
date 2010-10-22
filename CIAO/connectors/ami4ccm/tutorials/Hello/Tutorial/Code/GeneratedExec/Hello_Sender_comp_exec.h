// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.8.2
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
#ifndef CIAO__________TUTORIAL_CODE_GENERATEDEXEC_HELLO_SENDER_COMP_EXEC_F5TEI4_H_
#define CIAO__________TUTORIAL_CODE_GENERATEDEXEC_HELLO_SENDER_COMP_EXEC_F5TEI4_H_

#include /**/ "ace/pre.h"

#include "Hello_Sender_compEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/LocalObject.h"

namespace CIAO_Hello_Sender_comp_Impl
{

  //============================================================
  // Component Executor Implementation Class: Sender_comp_exec_i
  //============================================================

  class  Sender_comp_exec_i
    : public virtual Sender_comp_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Sender_comp_exec_i (void);
    virtual ~Sender_comp_exec_i (void);

    //@{
    /** Supported operations and attributes. */

    //@}

    //@{
    /** Component attributes and port operations. *///@}

    //@{
    /** Operations from Components::SessionComponent. */

    virtual void set_session_context (::Components::SessionContext_ptr ctx);

    virtual void configuration_complete (void);

    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}

    //@{
    /** User defined operations */

    //@}

  private:
    ::Hello::CCM_Sender_comp_Context_var ciao_context_;
  };

  extern "C"  ::Components::EnterpriseComponent_ptr
  create_Hello_Sender_comp_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */
