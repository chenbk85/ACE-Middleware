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
// be/be_codegen.cpp:553

#ifndef _TAO_IDL_ORIG_DOMAINS_T_H_
#define _TAO_IDL_ORIG_DOMAINS_T_H_

#include /**/ "ace/pre.h"

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */


// TAO_IDL - Generated from 
// be/be_visitor_root/root_sth.cpp:116

#if defined (ACE_HAS_USING_KEYWORD)
namespace POA_CORBA
{
  
  // TAO_IDL - Generated from
  // be/be_visitor_interface/tie_sh.cpp:87
  
  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class  DomainManager_tie : public DomainManager
  {
  public:
    DomainManager_tie (T &t);
    // the T& ctor
    DomainManager_tie (T &t, PortableServer::POA_ptr poa);
    // ctor taking a POA
    DomainManager_tie (T *tp, CORBA::Boolean release = 1);
    // ctor taking pointer and an ownership flag
    DomainManager_tie (
        T *tp,
        PortableServer::POA_ptr poa,
        CORBA::Boolean release = 1
      );
    // ctor with T*, ownership flag and a POA
    ~DomainManager_tie (void);
    // dtor
    
    // TIE specific functions
    T *_tied_object (void);
    // return the underlying object
    void _tied_object (T &obj);
    // set the underlying object
    void _tied_object (T *obj, CORBA::Boolean release = 1);
    // set the underlying object and the ownership flag
    CORBA::Boolean _is_owner (void);
    // do we own it
    void _is_owner (CORBA::Boolean b);
    // set the ownership
    
    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      );
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/tie_sh.cpp:60
    
    ::CORBA::Policy_ptr get_domain_policy (
        CORBA::PolicyType policy_type
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
  
  private:
    T *ptr_;
    PortableServer::POA_var poa_;
    CORBA::Boolean rel_;
    
    // copy and assignment are not allowed
    DomainManager_tie (const DomainManager_tie &);
    void operator= (const DomainManager_tie &);
  };
  
  // TAO_IDL - Generated from
  // be/be_visitor_interface/tie_sh.cpp:87
  
  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class  ConstructionPolicy_tie : public ConstructionPolicy
  {
  public:
    ConstructionPolicy_tie (T &t);
    // the T& ctor
    ConstructionPolicy_tie (T &t, PortableServer::POA_ptr poa);
    // ctor taking a POA
    ConstructionPolicy_tie (T *tp, CORBA::Boolean release = 1);
    // ctor taking pointer and an ownership flag
    ConstructionPolicy_tie (
        T *tp,
        PortableServer::POA_ptr poa,
        CORBA::Boolean release = 1
      );
    // ctor with T*, ownership flag and a POA
    ~ConstructionPolicy_tie (void);
    // dtor
    
    // TIE specific functions
    T *_tied_object (void);
    // return the underlying object
    void _tied_object (T &obj);
    // set the underlying object
    void _tied_object (T *obj, CORBA::Boolean release = 1);
    // set the underlying object and the ownership flag
    CORBA::Boolean _is_owner (void);
    // do we own it
    void _is_owner (CORBA::Boolean b);
    // set the ownership
    
    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      );
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/tie_sh.cpp:60
    
    CORBA::PolicyType policy_type (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/tie_sh.cpp:60
    
    ::CORBA::Policy_ptr copy (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/tie_sh.cpp:60
    
    void destroy (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/tie_sh.cpp:60
    
    void make_domain_manager (
        CORBA::InterfaceDef_ptr object_type,
        CORBA::Boolean constr_policy
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
  
  private:
    T *ptr_;
    PortableServer::POA_var poa_;
    CORBA::Boolean rel_;
    
    // copy and assignment are not allowed
    ConstructionPolicy_tie (const ConstructionPolicy_tie &);
    void operator= (const ConstructionPolicy_tie &);
  };
} // module CORBA
#endif /* ACE_HAS_USING_KEYWORD */

// TAO_IDL - Generated from 
// be/be_codegen.cpp:1101

#if defined (__ACE_INLINE__)
#include "DomainS_T.i"
#endif /* defined INLINE */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "DomainS_T.cpp"
#endif /* defined REQUIRED SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("DomainS_T.cpp")
#endif /* defined REQUIRED PRAGMA */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#include /**/ "ace/post.h"
#endif /* ifndef */
