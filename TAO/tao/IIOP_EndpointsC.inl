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
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ci.cpp:70

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const TAO::IIOP_Endpoint_Info &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.host.in ()) &&
    (strm << _tao_aggregate.port) &&
    (strm << _tao_aggregate.priority);
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    TAO::IIOP_Endpoint_Info &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.host.out ()) &&
    (strm >> _tao_aggregate.port) &&
    (strm >> _tao_aggregate.priority);
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_TAO_IIOPEndpointSequence_I_
#define _TAO_CDR_OP_TAO_IIOPEndpointSequence_I_

CORBA::Boolean TAO_Export operator<< (
    TAO_OutputCDR &,
    const TAO::IIOPEndpointSequence &
  );

CORBA::Boolean TAO_Export operator>> (
    TAO_InputCDR &,
    TAO::IIOPEndpointSequence &
  );

#endif /* _TAO_CDR_OP_TAO_IIOPEndpointSequence_I_ */

