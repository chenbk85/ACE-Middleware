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
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/cdr_op_ci.cpp:70

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const FP_Scheduling::SegmentSchedulingParameter &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.base_priority);
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    FP_Scheduling::SegmentSchedulingParameter &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.base_priority);
}

