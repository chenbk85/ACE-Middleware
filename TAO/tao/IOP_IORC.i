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
// be/be_visitor_structure/cdr_op_ci.cpp:70

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IOP::TaggedProfile &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.tag) &&
    (strm << _tao_aggregate.profile_data);
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IOP::TaggedProfile &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.tag) &&
    (strm >> _tao_aggregate.profile_data);
}

// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_IOP_IOR__tao_seq_IOP_TaggedProfile__I_
#define _TAO_CDR_OP_IOP_IOR__tao_seq_IOP_TaggedProfile__I_

CORBA::Boolean TAO_Export operator<< (
    TAO_OutputCDR &,
    const IOP::IOR::_tao_seq_IOP_TaggedProfile_ &
  );

CORBA::Boolean TAO_Export operator>> (
    TAO_InputCDR &,
    IOP::IOR::_tao_seq_IOP_TaggedProfile_ &
  );

#endif /* _TAO_CDR_OP_IOP_IOR__tao_seq_IOP_TaggedProfile__I_ */

// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_ci.cpp:70

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IOP::IOR &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.type_id.in ()) &&
    (strm << _tao_aggregate.profiles);
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IOP::IOR &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.type_id.out ()) &&
    (strm >> _tao_aggregate.profiles);
}

// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_ci.cpp:70

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IOP::TaggedComponent &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.tag) &&
    (strm << _tao_aggregate.component_data);
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IOP::TaggedComponent &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.tag) &&
    (strm >> _tao_aggregate.component_data);
}

// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_IOP_MultipleComponentProfile_I_
#define _TAO_CDR_OP_IOP_MultipleComponentProfile_I_

CORBA::Boolean TAO_Export operator<< (
    TAO_OutputCDR &,
    const IOP::MultipleComponentProfile &
  );

CORBA::Boolean TAO_Export operator>> (
    TAO_InputCDR &,
    IOP::MultipleComponentProfile &
  );

#endif /* _TAO_CDR_OP_IOP_MultipleComponentProfile_I_ */

// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_IOP_TaggedComponentList_I_
#define _TAO_CDR_OP_IOP_TaggedComponentList_I_

CORBA::Boolean TAO_Export operator<< (
    TAO_OutputCDR &,
    const IOP::TaggedComponentList &
  );

CORBA::Boolean TAO_Export operator>> (
    TAO_InputCDR &,
    IOP::TaggedComponentList &
  );

#endif /* _TAO_CDR_OP_IOP_TaggedComponentList_I_ */

// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_IOP_TaggedComponentSeq_I_
#define _TAO_CDR_OP_IOP_TaggedComponentSeq_I_

CORBA::Boolean TAO_Export operator<< (
    TAO_OutputCDR &,
    const IOP::TaggedComponentSeq &
  );

CORBA::Boolean TAO_Export operator>> (
    TAO_InputCDR &,
    IOP::TaggedComponentSeq &
  );

#endif /* _TAO_CDR_OP_IOP_TaggedComponentSeq_I_ */

// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_IOP_ServiceContext__tao_seq_CORBA_Octet__I_
#define _TAO_CDR_OP_IOP_ServiceContext__tao_seq_CORBA_Octet__I_

CORBA::Boolean TAO_Export operator<< (
    TAO_OutputCDR &,
    const IOP::ServiceContext::_tao_seq_CORBA_Octet_ &
  );

CORBA::Boolean TAO_Export operator>> (
    TAO_InputCDR &,
    IOP::ServiceContext::_tao_seq_CORBA_Octet_ &
  );

#endif /* _TAO_CDR_OP_IOP_ServiceContext__tao_seq_CORBA_Octet__I_ */

// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_ci.cpp:70

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IOP::ServiceContext &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.context_id) &&
    (strm << _tao_aggregate.context_data);
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IOP::ServiceContext &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.context_id) &&
    (strm >> _tao_aggregate.context_data);
}

// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_IOP_ServiceContextList_I_
#define _TAO_CDR_OP_IOP_ServiceContextList_I_

CORBA::Boolean TAO_Export operator<< (
    TAO_OutputCDR &,
    const IOP::ServiceContextList &
  );

CORBA::Boolean TAO_Export operator>> (
    TAO_InputCDR &,
    IOP::ServiceContextList &
  );

#endif /* _TAO_CDR_OP_IOP_ServiceContextList_I_ */

