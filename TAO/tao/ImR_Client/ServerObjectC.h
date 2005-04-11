// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be\be_codegen.cpp:153

#ifndef _TAO_IDL_ORIG_SERVEROBJECTC_H_
#define _TAO_IDL_ORIG_SERVEROBJECTC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "imr_client_export.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Environment.h"
#include "tao/Object.h"
#include "tao/Objref_VarOut_T.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_IMR_Client_Export

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from 
// be\be_visitor_root/root_ch.cpp:62

namespace TAO
{
  class Collocation_Proxy_Broker;
  template<typename T> class Narrow_Utils;
}

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:48

namespace ImplementationRepository
{
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:598

#if !defined (_IMPLEMENTATIONREPOSITORY_SERVEROBJECT__VAR_OUT_CH_)
#define _IMPLEMENTATIONREPOSITORY_SERVEROBJECT__VAR_OUT_CH_
  
  class ServerObject;
  typedef ServerObject *ServerObject_ptr;
  
  typedef
    TAO_Objref_Var_T<
        ServerObject
      >
    ServerObject_var;
  
  typedef
    TAO_Objref_Out_T<
        ServerObject
      >
    ServerObject_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_IMPLEMENTATIONREPOSITORY_SERVEROBJECT_CH_)
#define _IMPLEMENTATIONREPOSITORY_SERVEROBJECT_CH_
  
  class TAO_IMR_Client_Export ServerObject
    : public virtual CORBA::Object
  {
  public:
    friend class TAO::Narrow_Utils<ServerObject>;
    typedef ServerObject_ptr _ptr_type;
    typedef ServerObject_var _var_type;
    
    // The static operations.
    static ServerObject_ptr _duplicate (ServerObject_ptr obj);
    
    static void _tao_release (ServerObject_ptr obj);
    
    static ServerObject_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static ServerObject_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static ServerObject_ptr _nil (void)
    {
      return static_cast<ServerObject_ptr> (0);
    }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void ping (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void shutdown (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_interface/interface_ch.cpp:210
    
    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  private:
    TAO::Collocation_Proxy_Broker *the_TAO_ServerObject_Proxy_Broker_;
  
  protected:
    // Concrete interface only.
    ServerObject (void);
    
    // These methods travese the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void ImplementationRepository_ServerObject_setup_collocation (void);
    
    // Concrete non-local interface only.
    ServerObject (
        IOP::IOR *ior,
        TAO_ORB_Core *orb_core = 0
      );
    
    // Non-local interface only.
    ServerObject (
        TAO_Stub *objref,
        CORBA::Boolean _tao_collocated = 0,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0
      );
    
    virtual ~ServerObject (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    ServerObject (const ServerObject &);
    
    void operator= (const ServerObject &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_IMR_Client_Export ::CORBA::TypeCode_ptr const _tc_ServerObject;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module ImplementationRepository

// Proxy Broker Factory function pointer declarations.

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:139

extern TAO_IMR_Client_Export
TAO::Collocation_Proxy_Broker *
(*ImplementationRepository__TAO_ServerObject_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  );

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:61

// Traits specializations.
namespace TAO
{

#if !defined (_IMPLEMENTATIONREPOSITORY_SERVEROBJECT__TRAITS_CH_)
#define _IMPLEMENTATIONREPOSITORY_SERVEROBJECT__TRAITS_CH_
  
  template<>
  struct TAO_IMR_Client_Export Objref_Traits< ::ImplementationRepository::ServerObject>
  {
    static ::ImplementationRepository::ServerObject_ptr duplicate (
        ::ImplementationRepository::ServerObject_ptr
      );
    static void release (
        ::ImplementationRepository::ServerObject_ptr
      );
    static ::ImplementationRepository::ServerObject_ptr nil (void);
    static CORBA::Boolean marshal (
        ::ImplementationRepository::ServerObject_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_ch.cpp:52

TAO_IMR_Client_Export void operator<<= (CORBA::Any &, ImplementationRepository::ServerObject_ptr); // copying
TAO_IMR_Client_Export void operator<<= (CORBA::Any &, ImplementationRepository::ServerObject_ptr *); // non-copying
TAO_IMR_Client_Export CORBA::Boolean operator>>= (const CORBA::Any &, ImplementationRepository::ServerObject_ptr &);

// TAO_IDL - Generated from
// be\be_visitor_interface/cdr_op_ch.cpp:55

TAO_IMR_Client_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const ImplementationRepository::ServerObject_ptr );
TAO_IMR_Client_Export CORBA::Boolean operator>> (TAO_InputCDR &, ImplementationRepository::ServerObject_ptr &);

// TAO_IDL - Generated from
// be\be_codegen.cpp:955

#if defined (__ACE_INLINE__)
#include "ServerObjectC.inl"
#endif /* defined INLINE */

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */


