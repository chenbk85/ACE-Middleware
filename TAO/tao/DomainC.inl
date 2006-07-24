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
// be\be_visitor_interface/interface_ci.cpp:70

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

#if !defined (_CORBA_DOMAINMANAGER___CI_)
#define _CORBA_DOMAINMANAGER___CI_

ACE_INLINE
CORBA::DomainManager::DomainManager (
    TAO_Stub *objref,
    CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc
  )
  : ::CORBA::Object (objref, _tao_collocated, servant, oc),
    the_TAO_DomainManager_Proxy_Broker_ (0)
{
  this->CORBA_DomainManager_setup_collocation ();
}

ACE_INLINE
CORBA::DomainManager::DomainManager (
    IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ::CORBA::Object (ior, oc),
    the_TAO_DomainManager_Proxy_Broker_ (0)
{
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_ci.cpp:70

#if !defined (_CORBA_CONSTRUCTIONPOLICY___CI_)
#define _CORBA_CONSTRUCTIONPOLICY___CI_

ACE_INLINE
CORBA::ConstructionPolicy::ConstructionPolicy (
    TAO_Stub *objref,
    CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc
  )
  : ::CORBA::Object (objref, _tao_collocated, servant, oc),
    the_TAO_ConstructionPolicy_Proxy_Broker_ (0)
{
  this->CORBA_ConstructionPolicy_setup_collocation ();
}

ACE_INLINE
CORBA::ConstructionPolicy::ConstructionPolicy (
    IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ::CORBA::Object (ior, oc),
    the_TAO_ConstructionPolicy_Proxy_Broker_ (0)
{
}

#endif /* end #if !defined */

TAO_END_VERSIONED_NAMESPACE_DECL
