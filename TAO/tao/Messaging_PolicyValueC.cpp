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
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:314


#include "Messaging_PolicyValueC.h"
#include "tao/Stub.h"
#include "tao/Invocation.h"
#include "tao/PortableInterceptor.h"

#if TAO_HAS_INTERCEPTORS == 1
#include "tao/RequestInfo_Util.h"
#include "tao/ClientRequestInfo_i.h"
#include "tao/ClientInterceptorAdapter.h"
#endif  /* TAO_HAS_INTERCEPTORS == 1 */



#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "Messaging_PolicyValueC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_Messaging_PolicyValue[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  38,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x4d657373), 
  ACE_NTOHL (0x6167696e), 
  ACE_NTOHL (0x672f506f), 
  ACE_NTOHL (0x6c696379), 
  ACE_NTOHL (0x56616c75), 
  ACE_NTOHL (0x653a312e), 
  ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/Messaging/PolicyValue:1.0
    12,
  ACE_NTOHL (0x506f6c69), 
  ACE_NTOHL (0x63795661), 
  ACE_NTOHL (0x6c756500),  // name = PolicyValue
  2, // member count
    6,
  ACE_NTOHL (0x70747970), 
  ACE_NTOHL (0x65000000),  // name = ptype
    CORBA::tk_alias, // typecode kind for typedefs
  64, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    33,
    ACE_NTOHL (0x49444c3a), 
    ACE_NTOHL (0x6f6d672e), 
    ACE_NTOHL (0x6f72672f), 
    ACE_NTOHL (0x434f5242), 
    ACE_NTOHL (0x412f506f), 
    ACE_NTOHL (0x6c696379), 
    ACE_NTOHL (0x54797065), 
    ACE_NTOHL (0x3a312e30), 
    ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/CORBA/PolicyType:1.0
        11,
    ACE_NTOHL (0x506f6c69), 
    ACE_NTOHL (0x63795479), 
    ACE_NTOHL (0x70650000),  // name = PolicyType
        CORBA::tk_ulong,


  7,
  ACE_NTOHL (0x7076616c), 
  ACE_NTOHL (0x75650000),  // name = pvalue
    CORBA::tk_sequence, // typecode kind
  12, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_octet,

    0U,

};

static CORBA::TypeCode _tc_TAO_tc_Messaging_PolicyValue (
    CORBA::tk_struct,
    sizeof (_oc_Messaging_PolicyValue),
    (char *) &_oc_Messaging_PolicyValue,
    0,
    sizeof (Messaging::PolicyValue)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (Messaging)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_PolicyValue,
    &_tc_TAO_tc_Messaging_PolicyValue
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/structure_cs.cpp:67

void Messaging::PolicyValue::_tao_any_destructor (void *_tao_void_pointer)
{
  PolicyValue *tmp = ACE_static_cast (PolicyValue*, _tao_void_pointer);
  delete tmp;
}

#if !defined (_MESSAGING_POLICYVALUE__TAO_SEQ_OCTET_CS_)
#define _MESSAGING_POLICYVALUE__TAO_SEQ_OCTET_CS_

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_cs.cpp:250

// *************************************************************
// Messaging::PolicyValue::_tao_seq_Octet
// *************************************************************

Messaging::PolicyValue::_tao_seq_Octet::_tao_seq_Octet (void)
{}

Messaging::PolicyValue::_tao_seq_Octet::_tao_seq_Octet (CORBA::ULong max)
  : 

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
TAO_Unbounded_Sequence<CORBA::Octet>
#else /* TAO_USE_SEQUENCE_TEMPLATES */
TAO_Unbounded_Sequence<CORBA::Octet>

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
 (max)
{}

Messaging::PolicyValue::_tao_seq_Octet::_tao_seq_Octet (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::Octet *buffer,
    CORBA::Boolean release
  )
  : 

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
TAO_Unbounded_Sequence<CORBA::Octet>
#else /* TAO_USE_SEQUENCE_TEMPLATES */
TAO_Unbounded_Sequence<CORBA::Octet>

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
 (max, length, buffer, release)
{}

Messaging::PolicyValue::_tao_seq_Octet::_tao_seq_Octet (const _tao_seq_Octet &seq)
  : 

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
TAO_Unbounded_Sequence<CORBA::Octet>
#else /* TAO_USE_SEQUENCE_TEMPLATES */
TAO_Unbounded_Sequence<CORBA::Octet>

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
 (seq)
{}

Messaging::PolicyValue::_tao_seq_Octet::~_tao_seq_Octet (void) // dtor
{}

void Messaging::PolicyValue::_tao_seq_Octet::_tao_any_destructor (void *_tao_void_pointer)
{
  _tao_seq_Octet *tmp = ACE_static_cast (_tao_seq_Octet*, _tao_void_pointer);
  delete tmp;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/gen_unbounded_sequence_cs.cpp:101

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_SEQUENCE_MESSAGING_POLICYVALUESEQ_CS_)
#define __TAO_UNBOUNDED_SEQUENCE_MESSAGING_POLICYVALUESEQ_CS_

void
Messaging::_TAO_Unbounded_Sequence_Messaging_PolicyValueSeq::_allocate_buffer (CORBA::ULong length)
{
  Messaging::PolicyValue* tmp = 0;
  tmp = _TAO_Unbounded_Sequence_Messaging_PolicyValueSeq::allocbuf (length);
  
  if (this->buffer_ != 0)
    {
      Messaging::PolicyValue *old =
        ACE_reinterpret_cast (Messaging::PolicyValue *, this->buffer_);
      
      for (CORBA::ULong i = 0; i < this->length_; ++i)
        {
          tmp[i] = old[i];
        }
      
      if (this->release_)
        {
          _TAO_Unbounded_Sequence_Messaging_PolicyValueSeq::freebuf (old);
        }
    }
  
  this->buffer_ = tmp;
}

void
Messaging::_TAO_Unbounded_Sequence_Messaging_PolicyValueSeq::_deallocate_buffer (void)
{
  if (this->buffer_ == 0 || this->release_ == 0)
    {
      return;
    }
  
  Messaging::PolicyValue *tmp =
    ACE_reinterpret_cast (Messaging::PolicyValue *, this->buffer_);
  _TAO_Unbounded_Sequence_Messaging_PolicyValueSeq::freebuf (tmp);
  this->buffer_ = 0;
} 

Messaging::_TAO_Unbounded_Sequence_Messaging_PolicyValueSeq::~_TAO_Unbounded_Sequence_Messaging_PolicyValueSeq (void)
{
  this->_deallocate_buffer ();
}

#endif /* end #if !defined */

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 

#if !defined (_MESSAGING_POLICYVALUESEQ_CS_)
#define _MESSAGING_POLICYVALUESEQ_CS_

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_cs.cpp:250

// *************************************************************
// Messaging::PolicyValueSeq
// *************************************************************

Messaging::PolicyValueSeq::PolicyValueSeq (void)
{}

Messaging::PolicyValueSeq::PolicyValueSeq (CORBA::ULong max)
  : 

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
_TAO_Unbounded_Sequence_Messaging_PolicyValueSeq
#else /* TAO_USE_SEQUENCE_TEMPLATES */
TAO_Unbounded_Sequence<Messaging::PolicyValue>

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
 (max)
{}

Messaging::PolicyValueSeq::PolicyValueSeq (
    CORBA::ULong max,
    CORBA::ULong length,
    Messaging::PolicyValue *buffer,
    CORBA::Boolean release
  )
  : 

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
_TAO_Unbounded_Sequence_Messaging_PolicyValueSeq
#else /* TAO_USE_SEQUENCE_TEMPLATES */
TAO_Unbounded_Sequence<Messaging::PolicyValue>

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
 (max, length, buffer, release)
{}

Messaging::PolicyValueSeq::PolicyValueSeq (const PolicyValueSeq &seq)
  : 

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
_TAO_Unbounded_Sequence_Messaging_PolicyValueSeq
#else /* TAO_USE_SEQUENCE_TEMPLATES */
TAO_Unbounded_Sequence<Messaging::PolicyValue>

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
 (seq)
{}

Messaging::PolicyValueSeq::~PolicyValueSeq (void) // dtor
{}

void Messaging::PolicyValueSeq::_tao_any_destructor (void *_tao_void_pointer)
{
  PolicyValueSeq *tmp = ACE_static_cast (PolicyValueSeq*, _tao_void_pointer);
  delete tmp;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_Messaging_PolicyValueSeq[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  41,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x4d657373), 
  ACE_NTOHL (0x6167696e), 
  ACE_NTOHL (0x672f506f), 
  ACE_NTOHL (0x6c696379), 
  ACE_NTOHL (0x56616c75), 
  ACE_NTOHL (0x65536571), 
  ACE_NTOHL (0x3a312e30), 
  ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/Messaging/PolicyValueSeq:1.0
    15,
  ACE_NTOHL (0x506f6c69), 
  ACE_NTOHL (0x63795661), 
  ACE_NTOHL (0x6c756553), 
  ACE_NTOHL (0x65710000),  // name = PolicyValueSeq
    CORBA::tk_sequence, // typecode kind
  200, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_struct, // typecode kind
    184, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      38,
      ACE_NTOHL (0x49444c3a), 
      ACE_NTOHL (0x6f6d672e), 
      ACE_NTOHL (0x6f72672f), 
      ACE_NTOHL (0x4d657373), 
      ACE_NTOHL (0x6167696e), 
      ACE_NTOHL (0x672f506f), 
      ACE_NTOHL (0x6c696379), 
      ACE_NTOHL (0x56616c75), 
      ACE_NTOHL (0x653a312e), 
      ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/Messaging/PolicyValue:1.0
            12,
      ACE_NTOHL (0x506f6c69), 
      ACE_NTOHL (0x63795661), 
      ACE_NTOHL (0x6c756500),  // name = PolicyValue
      2, // member count
            6,
      ACE_NTOHL (0x70747970), 
      ACE_NTOHL (0x65000000),  // name = ptype
            CORBA::tk_alias, // typecode kind for typedefs
      64, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        33,
        ACE_NTOHL (0x49444c3a), 
        ACE_NTOHL (0x6f6d672e), 
        ACE_NTOHL (0x6f72672f), 
        ACE_NTOHL (0x434f5242), 
        ACE_NTOHL (0x412f506f), 
        ACE_NTOHL (0x6c696379), 
        ACE_NTOHL (0x54797065), 
        ACE_NTOHL (0x3a312e30), 
        ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/CORBA/PolicyType:1.0
                11,
        ACE_NTOHL (0x506f6c69), 
        ACE_NTOHL (0x63795479), 
        ACE_NTOHL (0x70650000),  // name = PolicyType
                CORBA::tk_ulong,


      7,
      ACE_NTOHL (0x7076616c), 
      ACE_NTOHL (0x75650000),  // name = pvalue
            CORBA::tk_sequence, // typecode kind
      12, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        CORBA::tk_octet,

        0U,


    0U,

};

static CORBA::TypeCode _tc_TAO_tc_Messaging_PolicyValueSeq (
    CORBA::tk_alias,
    sizeof (_oc_Messaging_PolicyValueSeq),
    (char *) &_oc_Messaging_PolicyValueSeq,
    0,
    sizeof (Messaging::PolicyValueSeq)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (Messaging)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_PolicyValueSeq,
    &_tc_TAO_tc_Messaging_PolicyValueSeq
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const Messaging::PolicyValue &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<Messaging::PolicyValue>::insert_copy (
      _tao_any,
      Messaging::PolicyValue::_tao_any_destructor,
      Messaging::_tc_PolicyValue,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    Messaging::PolicyValue *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<Messaging::PolicyValue>::insert (
      _tao_any,
      Messaging::PolicyValue::_tao_any_destructor,
      Messaging::_tc_PolicyValue,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    Messaging::PolicyValue *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const Messaging::PolicyValue *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const Messaging::PolicyValue *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<Messaging::PolicyValue>::extract (
        _tao_any,
        Messaging::PolicyValue::_tao_any_destructor,
        Messaging::_tc_PolicyValue,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  template class TAO::Any_Dual_Impl_T<Messaging::PolicyValue>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO::Any_Dual_Impl_T<Messaging::PolicyValue>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const Messaging::PolicyValueSeq &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<Messaging::PolicyValueSeq>::insert_copy (
      _tao_any,
      Messaging::PolicyValueSeq::_tao_any_destructor,
      Messaging::_tc_PolicyValueSeq,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    Messaging::PolicyValueSeq *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<Messaging::PolicyValueSeq>::insert (
      _tao_any,
      Messaging::PolicyValueSeq::_tao_any_destructor,
      Messaging::_tc_PolicyValueSeq,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    Messaging::PolicyValueSeq *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const Messaging::PolicyValueSeq *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const Messaging::PolicyValueSeq *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<Messaging::PolicyValueSeq>::extract (
        _tao_any,
        Messaging::PolicyValueSeq::_tao_any_destructor,
        Messaging::_tc_PolicyValueSeq,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_cs.cpp:125

#if !defined _TAO_CDR_OP_Messaging_PolicyValue__tao_seq_Octet_CPP_
#define _TAO_CDR_OP_Messaging_PolicyValue__tao_seq_Octet_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Messaging::PolicyValue::_tao_seq_Octet &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      
#if (TAO_NO_COPY_OCTET_SEQUENCES == 1)
      {
        TAO_Unbounded_Sequence<CORBA::Octet> *oseq = 
          ACE_static_cast (TAO_Unbounded_Sequence<CORBA::Octet>*, (Messaging::PolicyValue::_tao_seq_Octet *)&_tao_sequence);
        if (oseq->mb ())
          return strm.write_octet_array_mb (oseq->mb ());
        else
          return strm.write_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
      }
      
#else /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
      return strm.write_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
    
#endif /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
    }
  
  return 0;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    Messaging::PolicyValue::_tao_seq_Octet &_tao_sequence
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
          return 0;
        }
      
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return 1;
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
            ACE_static_cast(TAO_Unbounded_Sequence<CORBA::Octet>*, &_tao_sequence);
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
  
  return 0;
}

#endif /* _TAO_CDR_OP_Messaging_PolicyValue__tao_seq_Octet_CPP_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_cs.cpp:125

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Messaging::PolicyValueSeq &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      CORBA::Boolean _tao_marshal_flag = 1;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm << _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    }
  
  return 0;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    Messaging::PolicyValueSeq &_tao_sequence
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
          return 0;
        }
      
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return 1;
        }
      
      // Retrieve all the elements.
      CORBA::Boolean _tao_marshal_flag = 1;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm >> _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    }
  
  return 0;
}

