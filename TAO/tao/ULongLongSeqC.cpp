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
// be\be_codegen.cpp:302


#include "ULongLongSeqC.h"
#include "tao/CDR.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "ULongLongSeqC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:69

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from 
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_CORBA_ULONGLONGSEQ_CS_)
#define _CORBA_ULONGLONGSEQ_CS_

CORBA::ULongLongSeq::ULongLongSeq (void)
{}

CORBA::ULongLongSeq::ULongLongSeq (
    CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        CORBA::ULongLong
      >
    (max)
{}

CORBA::ULongLongSeq::ULongLongSeq (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::ULongLong * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        CORBA::ULongLong
      >
    (max, length, buffer, release)
{}

CORBA::ULongLongSeq::ULongLongSeq (
    const ULongLongSeq &seq
  )
  : TAO_Unbounded_Sequence<
        CORBA::ULongLong
      >
    (seq)
{}

CORBA::ULongLongSeq::~ULongLongSeq (void)
{}

void CORBA::ULongLongSeq::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  ULongLongSeq * _tao_tmp_pointer =
    static_cast<ULongLongSeq *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_CORBA_ULongLongSeq_CPP_
#define _TAO_CDR_OP_CORBA_ULongLongSeq_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::ULongLongSeq &_tao_sequence
  )
{
  const CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      return strm.write_ulonglong_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
    }
  
  return false;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::ULongLongSeq &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;
  
  if (strm >> _tao_seq_len)
    {
      // Add a check to the length of the sequence
      // to make sure it does not exceed the length
      // of the stream. (See bug 58.)
      if (_tao_seq_len > strm.length ())
        {
          return false;
        }
      
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return true;
        }
      
      // Retrieve all the elements.
      return strm.read_ulonglong_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
    
    }
  
  return false;
}

#endif /* _TAO_CDR_OP_CORBA_ULongLongSeq_CPP_ */

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1619

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO_FixedSeq_Var_T<
        CORBA::ULongLongSeq,
        CORBA::ULongLong
      >;

  template class
    TAO_Seq_Var_Base_T<
        CORBA::ULongLongSeq,
        CORBA::ULongLong
      >;

  template class
    TAO_Seq_Out_T<
        CORBA::ULongLongSeq,
        CORBA::ULongLongSeq_var,
        CORBA::ULongLong
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO_FixedSeq_Var_T< \
        CORBA::ULongLongSeq, \
        CORBA::ULongLong \
      >

# pragma instantiate \
    TAO_Seq_Var_Base_T< \
        CORBA::ULongLongSeq, \
        CORBA::ULongLong \
      >

# pragma instantiate \
    TAO_Seq_Out_T< \
        CORBA::ULongLongSeq, \
        CORBA::ULongLongSeq_var, \
        CORBA::ULongLong \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
