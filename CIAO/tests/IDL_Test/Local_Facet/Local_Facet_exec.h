// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.7.4
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
 *       http://doc.ece.uci.edu/
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
// be/be_codegen.cpp:1217

#ifndef CIAO_LOCAL_FACET_EXEC_H_
#define CIAO_LOCAL_FACET_EXEC_H_

#include /**/ "ace/pre.h"

#include "Local_FacetEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Local_Facet_exec_export.h"
#include "tao/LocalObject.h"


namespace CIAO_Bar_Impl
{
  class LOCAL_FACET_EXEC_Export Foo_exec_i
    : public virtual ::CCM_Foo,
      public virtual ::CORBA::LocalObject
  {
  public:
    Foo_exec_i (void);
    virtual ~Foo_exec_i (void);
    
    // Operations and attributes from ::Foo
  };
  
  class LOCAL_FACET_EXEC_Export Bar_exec_i
    : public virtual Bar_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Bar_exec_i (void);
    virtual ~Bar_exec_i (void);
    
    //@{
    /** Supported operations and attributes. */
    
    //@}
    
    //@{
    /** Component attributes and port operations. */
    
    
    virtual ::CCM_Foo_ptr
    get_foo_out (void);
    //@}
    
    //@{
    /** Operations from Components::SessionComponent. */
    
    virtual void
    set_session_context (
      ::Components::SessionContext_ptr ctx);
    
    virtual void configuration_complete (void);
    
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}
    
  
  private:
    ::CCM_Bar_Context_var context_;
  };
  
  extern "C" LOCAL_FACET_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Bar_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */
