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


#include "OctetSeqC.h"
#include "tao/CDR.h"
#include "tao/ORB_Core.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "OctetSeqC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:69

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from 
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_CORBA_OCTETSEQ_CS_)
#define _CORBA_OCTETSEQ_CS_

CORBA::OctetSeq::OctetSeq (void)
{}

CORBA::OctetSeq::OctetSeq (
    CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        CORBA::Octet
      >
    (max)
{}

CORBA::OctetSeq::OctetSeq (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::Octet * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        CORBA::Octet
      >
    (max, length, buffer, release)
{}

CORBA::OctetSeq::OctetSeq (
    const OctetSeq &seq
  )
  : TAO_Unbounded_Sequence<
        CORBA::Octet
      >
    (seq)
{}

CORBA::OctetSeq::~OctetSeq (void)
{}

void CORBA::OctetSeq::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  OctetSeq * _tao_tmp_pointer =
    static_cast<OctetSeq *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_CORBA_OctetSeq_CPP_
#define _TAO_CDR_OP_CORBA_OctetSeq_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::OctetSeq &_tao_sequence
  )
{
  const CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      
#if (TAO_NO_COPY_OCTET_SEQUENCES == 1)
      {
        TAO_Unbounded_Sequence<CORBA::Octet> *_tao_octet_seq = 
          static_cast<TAO_Unbounded_Sequence<CORBA::Octet> *> (const_cast<CORBA::OctetSeq *> (&_tao_sequence));
        if (_tao_octet_seq->mb ())
          return strm.write_octet_array_mb (_tao_octet_seq->mb ());
        else
          return strm.write_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
      }
      
#else /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
      return strm.write_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
    
#endif /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
    }
  
  return false;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::OctetSeq &_tao_sequence
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
      
#if (TAO_NO_COPY_OCTET_SEQUENCES == 1)
      if (ACE_BIT_DISABLED (strm.start ()->flags (),
      ACE_Message_Block::DONT_DELETE))
      {
        TAO_ORB_Core* orb_core = strm.orb_core ();
        if (orb_core != 0 &&
        strm.orb_core ()->resource_factory ()->
        input_cdr_allocator_type_locked () == 1)
        {
          TAO_Unbounded_Sequence<CORBA::Octet> *oseq = 
            static_cast<TAO_Unbounded_Sequence<CORBA::Octet> *> (&_tao_sequence);
          oseq->replace (_tao_seq_len, strm.start ());
          oseq->mb ()->wr_ptr (oseq->mb()->rd_ptr () + _tao_seq_len);
          strm.skip_bytes (_tao_seq_len);
          return 1;
        }
      }
      return strm.read_octet_array (_tao_sequence.get_buffer (), _tao_seq_len);
#else /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
      return strm.read_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
    
#endif /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
    
    }
  
  return false;
}

#endif /* _TAO_CDR_OP_CORBA_OctetSeq_CPP_ */

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1528

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO_FixedSeq_Var_T<
        CORBA::OctetSeq,
        CORBA::Octet
      >;

  template class
    TAO_Seq_Var_Base_T<
        CORBA::OctetSeq,
        CORBA::Octet
      >;

  template class
    TAO_Seq_Out_T<
        CORBA::OctetSeq,
        CORBA::OctetSeq_var,
        CORBA::Octet
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO_FixedSeq_Var_T< \
        CORBA::OctetSeq, \
        CORBA::Octet \
      >

# pragma instantiate \
    TAO_Seq_Var_Base_T< \
        CORBA::OctetSeq, \
        CORBA::Octet \
      >

# pragma instantiate \
    TAO_Seq_Out_T< \
        CORBA::OctetSeq, \
        CORBA::OctetSeq_var, \
        CORBA::Octet \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
