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
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:68

#if !defined (_DYNAMICANY_DYNANY___CI_)
#define _DYNAMICANY_DYNANY___CI_

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:68

#if !defined (_DYNAMICANY_DYNFIXED___CI_)
#define _DYNAMICANY_DYNFIXED___CI_

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:68

#if !defined (_DYNAMICANY_DYNENUM___CI_)
#define _DYNAMICANY_DYNENUM___CI_

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:68

#if !defined (_DYNAMICANY_DYNSTRUCT___CI_)
#define _DYNAMICANY_DYNSTRUCT___CI_

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:68

#if !defined (_DYNAMICANY_DYNUNION___CI_)
#define _DYNAMICANY_DYNUNION___CI_

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:68

#if !defined (_DYNAMICANY_DYNSEQUENCE___CI_)
#define _DYNAMICANY_DYNSEQUENCE___CI_

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:68

#if !defined (_DYNAMICANY_DYNARRAY___CI_)
#define _DYNAMICANY_DYNARRAY___CI_

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:68

#if !defined (_DYNAMICANY_DYNVALUE___CI_)
#define _DYNAMICANY_DYNVALUE___CI_

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:68

#if !defined (_DYNAMICANY_DYNANYFACTORY___CI_)
#define _DYNAMICANY_DYNANYFACTORY___CI_

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ci.cpp:71

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const DynamicAny::NameValuePair &_tao_aggregate
  )
{
  if (
    (strm << _tao_aggregate.id.in ()) &&
    (strm << _tao_aggregate.value)
   )
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    DynamicAny::NameValuePair &_tao_aggregate
  )
{
  if (
    (strm >> _tao_aggregate.id.out ()) &&
    (strm >> _tao_aggregate.value)
   )
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:84

#if !defined _TAO_CDR_OP_DynamicAny_NameValuePairSeq_I_
#define _TAO_CDR_OP_DynamicAny_NameValuePairSeq_I_

CORBA::Boolean TAO_DynamicAny_Export operator<< (
    TAO_OutputCDR &,
    const DynamicAny::NameValuePairSeq &
  );

CORBA::Boolean TAO_DynamicAny_Export operator>> (
    TAO_InputCDR &,
    DynamicAny::NameValuePairSeq &
  );

#endif /* _TAO_CDR_OP_DynamicAny_NameValuePairSeq_I_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:84

#if !defined _TAO_CDR_OP_DynamicAny_AnySeq_I_
#define _TAO_CDR_OP_DynamicAny_AnySeq_I_

CORBA::Boolean TAO_DynamicAny_Export operator<< (
    TAO_OutputCDR &,
    const DynamicAny::AnySeq &
  );

CORBA::Boolean TAO_DynamicAny_Export operator>> (
    TAO_InputCDR &,
    DynamicAny::AnySeq &
  );

#endif /* _TAO_CDR_OP_DynamicAny_AnySeq_I_ */

