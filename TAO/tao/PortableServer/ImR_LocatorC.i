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
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ci.cpp:68

#if !defined (_IMPLEMENTATIONREPOSITORY_LOCATOR___CI_)
#define _IMPLEMENTATIONREPOSITORY_LOCATOR___CI_

ACE_INLINE
ImplementationRepository::Locator::Locator (
    TAO_Stub *objref,
    CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant
  )
  : Object (objref, _tao_collocated, servant)
{
  this->ImplementationRepository_Locator_setup_collocation (_tao_collocated);
}


#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_ci.cpp:72

TAO_PortableServer_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const ImplementationRepository::Locator_ptr
  );

TAO_PortableServer_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    ImplementationRepository::Locator_ptr &
  );

