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

#include "Policy_ForwardC.h"

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
#include "Policy_ForwardC.i"
#endif /* !defined INLINE */

static const CORBA::Long _oc_CORBA_PolicyType[] =
{
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

};

static CORBA::TypeCode _tc_TAO_tc_CORBA_PolicyType (
    CORBA::tk_alias,
    sizeof (_oc_CORBA_PolicyType),
    (char *) &_oc_CORBA_PolicyType,
    0,
    sizeof (CORBA::PolicyType)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (::CORBA::TypeCode_ptr, _tc_PolicyType, &_tc_TAO_tc_CORBA_PolicyType)
TAO_NAMESPACE_END


#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_OBJECT_SEQUENCE_CORBA_POLICYLIST_CS_)
#define __TAO_UNBOUNDED_OBJECT_SEQUENCE_CORBA_POLICYLIST_CS_

// The Base_Sequence functions, please see tao/Sequence.h
void
CORBA::_TAO_Unbounded_Object_Sequence_CORBA_PolicyList::_allocate_buffer (CORBA::ULong length)
{
  CORBA::Policy **tmp = 0;
  tmp = _TAO_Unbounded_Object_Sequence_CORBA_PolicyList::allocbuf (length);
  
  if (this->buffer_ != 0)
  {
    CORBA::Policy **old = ACE_reinterpret_cast (CORBA::Policy**, this->buffer_);
    for (CORBA::ULong i = 0; i < this->length_; ++i)
      {
        if (!this->release_)
          {
            tmp[i] = tao_CORBA_Policy_duplicate (old[i]);
          }
        else
          {
            tmp[i] = old[i];
          }
      }
    
    if (this->release_)
      {
        delete[] old;
      }
  }
  this->buffer_ = tmp;
}

void
CORBA::_TAO_Unbounded_Object_Sequence_CORBA_PolicyList::_deallocate_buffer (void)
{
  if (this->buffer_ == 0 || this->release_ == 0)
    return;
  CORBA::Policy **tmp = ACE_reinterpret_cast (CORBA::Policy**, this->buffer_);
  
  for (CORBA::ULong i = 0; i < this->length_; ++i)
    {
      tao_CORBA_Policy_release (tmp[i]);
      tmp[i] = tao_CORBA_Policy_nil ();
    }
  
  _TAO_Unbounded_Object_Sequence_CORBA_PolicyList::freebuf (tmp);
  this->buffer_ = 0;
}

CORBA::_TAO_Unbounded_Object_Sequence_CORBA_PolicyList::~_TAO_Unbounded_Object_Sequence_CORBA_PolicyList (void)
{
  this->_deallocate_buffer ();
}

void
CORBA::_TAO_Unbounded_Object_Sequence_CORBA_PolicyList::_shrink_buffer (CORBA::ULong nl, CORBA::ULong ol)
{
  CORBA::Policy **tmp = ACE_reinterpret_cast (CORBA::Policy**, this->buffer_);
  
  for (CORBA::ULong i = nl; i < ol; ++i)
    {
      tao_CORBA_Policy_release (tmp[i]);
      tmp[i] = tao_CORBA_Policy_nil ();
    }
}

void 
CORBA::_TAO_Unbounded_Object_Sequence_CORBA_PolicyList::_downcast (
    void* target,
    CORBA::Object *src
    ACE_ENV_ARG_DECL
  )
{
  CORBA::Policy **tmp = ACE_static_cast (CORBA::Policy**, target);
  *tmp = tao_CORBA_Policy_narrow (src ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

CORBA::Object*
CORBA::_TAO_Unbounded_Object_Sequence_CORBA_PolicyList::_upcast (void *src) const
{
  return tao_CORBA_Policy_upcast (src);
}

#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 

#if !defined (_CORBA_POLICYLIST_CS_)
#define _CORBA_POLICYLIST_CS_

// *************************************************************
// CORBA::PolicyList
// *************************************************************

CORBA::PolicyList::PolicyList (void)
{}
CORBA::PolicyList::PolicyList (CORBA::ULong max) // uses max size
  : 
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
_TAO_Unbounded_Object_Sequence_CORBA_PolicyList
#else /* TAO_USE_SEQUENCE_TEMPLATES */
TAO_Unbounded_Object_Sequence<CORBA::Policy,CORBA::Policy_var>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
 (max)
{}
CORBA::PolicyList::PolicyList (CORBA::ULong max, CORBA::ULong length, CORBA::Policy_ptr *buffer, CORBA::Boolean release)
  : 
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
_TAO_Unbounded_Object_Sequence_CORBA_PolicyList
#else /* TAO_USE_SEQUENCE_TEMPLATES */
TAO_Unbounded_Object_Sequence<CORBA::Policy,CORBA::Policy_var>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
 (max, length, buffer, release)
{}
CORBA::PolicyList::PolicyList (const PolicyList &seq) // copy ctor
  : 
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
_TAO_Unbounded_Object_Sequence_CORBA_PolicyList
#else /* TAO_USE_SEQUENCE_TEMPLATES */
TAO_Unbounded_Object_Sequence<CORBA::Policy,CORBA::Policy_var>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
 (seq)
{}
CORBA::PolicyList::~PolicyList (void) // dtor
{}
void CORBA::PolicyList::_tao_any_destructor (void *_tao_void_pointer)
{
  PolicyList *tmp = ACE_static_cast (PolicyList*, _tao_void_pointer);
  delete tmp;
}


#endif /* end #if !defined */

static const CORBA::Long _oc_CORBA_PolicyList[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  33,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f506f), 
  ACE_NTOHL (0x6c696379), 
  ACE_NTOHL (0x4c697374), 
  ACE_NTOHL (0x3a312e30), 
  ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/CORBA/PolicyList:1.0
  11,
  ACE_NTOHL (0x506f6c69), 
  ACE_NTOHL (0x63794c69), 
  ACE_NTOHL (0x73740000),  // name = PolicyList
  CORBA::tk_sequence, // typecode kind
  68, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_objref, // typecode kind
    52, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      29,
      ACE_NTOHL (0x49444c3a), 
      ACE_NTOHL (0x6f6d672e), 
      ACE_NTOHL (0x6f72672f), 
      ACE_NTOHL (0x434f5242), 
      ACE_NTOHL (0x412f506f), 
      ACE_NTOHL (0x6c696379), 
      ACE_NTOHL (0x3a312e30), 
      ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/CORBA/Policy:1.0
      7,
      ACE_NTOHL (0x506f6c69), 
      ACE_NTOHL (0x63790000),  // name = Policy

    0U,

};

static CORBA::TypeCode _tc_TAO_tc_CORBA_PolicyList (
    CORBA::tk_alias,
    sizeof (_oc_CORBA_PolicyList),
    (char *) &_oc_CORBA_PolicyList,
    0,
    sizeof (CORBA::PolicyList)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (::CORBA::TypeCode_ptr, _tc_PolicyList, &_tc_TAO_tc_CORBA_PolicyList)
TAO_NAMESPACE_END


#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_SEQUENCE_CORBA_POLICYTYPESEQ_CS_)
#define __TAO_UNBOUNDED_SEQUENCE_CORBA_POLICYTYPESEQ_CS_

void
CORBA::_TAO_Unbounded_Sequence_CORBA_PolicyTypeSeq::_allocate_buffer (CORBA::ULong length)
{
  CORBA::ULong* tmp = 0;
  tmp = _TAO_Unbounded_Sequence_CORBA_PolicyTypeSeq::allocbuf (length);
  
  if (this->buffer_ != 0)
  {
    CORBA::ULong *old = ACE_reinterpret_cast (CORBA::ULong *,this->buffer_);
    
    for (CORBA::ULong i = 0; i < this->length_; ++i)
      tmp[i] = old[i];
    
    if (this->release_)
      _TAO_Unbounded_Sequence_CORBA_PolicyTypeSeq::freebuf (old);
    
  }
  this->buffer_ = tmp;
}

void
CORBA::_TAO_Unbounded_Sequence_CORBA_PolicyTypeSeq::_deallocate_buffer (void)
{
  if (this->buffer_ == 0 || this->release_ == 0)
    return;
  
  CORBA::ULong *tmp = ACE_reinterpret_cast (CORBA::ULong *,this->buffer_);
  
  _TAO_Unbounded_Sequence_CORBA_PolicyTypeSeq::freebuf (tmp);
  this->buffer_ = 0;
} 

CORBA::_TAO_Unbounded_Sequence_CORBA_PolicyTypeSeq::~_TAO_Unbounded_Sequence_CORBA_PolicyTypeSeq (void) // Dtor.
{
  this->_deallocate_buffer ();
}


#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 

#if !defined (_CORBA_POLICYTYPESEQ_CS_)
#define _CORBA_POLICYTYPESEQ_CS_

// *************************************************************
// CORBA::PolicyTypeSeq
// *************************************************************

CORBA::PolicyTypeSeq::PolicyTypeSeq (void)
{}
CORBA::PolicyTypeSeq::PolicyTypeSeq (CORBA::ULong max) // uses max size
  : 
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
_TAO_Unbounded_Sequence_CORBA_PolicyTypeSeq
#else /* TAO_USE_SEQUENCE_TEMPLATES */
TAO_Unbounded_Sequence<CORBA::ULong>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
 (max)
{}
CORBA::PolicyTypeSeq::PolicyTypeSeq (CORBA::ULong max, CORBA::ULong length, CORBA::ULong *buffer, CORBA::Boolean release)
  : 
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
_TAO_Unbounded_Sequence_CORBA_PolicyTypeSeq
#else /* TAO_USE_SEQUENCE_TEMPLATES */
TAO_Unbounded_Sequence<CORBA::ULong>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
 (max, length, buffer, release)
{}
CORBA::PolicyTypeSeq::PolicyTypeSeq (const PolicyTypeSeq &seq) // copy ctor
  : 
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
_TAO_Unbounded_Sequence_CORBA_PolicyTypeSeq
#else /* TAO_USE_SEQUENCE_TEMPLATES */
TAO_Unbounded_Sequence<CORBA::ULong>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
 (seq)
{}
CORBA::PolicyTypeSeq::~PolicyTypeSeq (void) // dtor
{}
void CORBA::PolicyTypeSeq::_tao_any_destructor (void *_tao_void_pointer)
{
  PolicyTypeSeq *tmp = ACE_static_cast (PolicyTypeSeq*, _tao_void_pointer);
  delete tmp;
}


#endif /* end #if !defined */

static const CORBA::Long _oc_CORBA_PolicyTypeSeq[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  36,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f506f), 
  ACE_NTOHL (0x6c696379), 
  ACE_NTOHL (0x54797065), 
  ACE_NTOHL (0x5365713a), 
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/PolicyTypeSeq:1.0
  14,
  ACE_NTOHL (0x506f6c69), 
  ACE_NTOHL (0x63795479), 
  ACE_NTOHL (0x70655365), 
  ACE_NTOHL (0x71000000),  // name = PolicyTypeSeq
  CORBA::tk_sequence, // typecode kind
  80, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
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


    0U,

};

static CORBA::TypeCode _tc_TAO_tc_CORBA_PolicyTypeSeq (
    CORBA::tk_alias,
    sizeof (_oc_CORBA_PolicyTypeSeq),
    (char *) &_oc_CORBA_PolicyTypeSeq,
    0,
    sizeof (CORBA::PolicyTypeSeq)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (::CORBA::TypeCode_ptr, _tc_PolicyTypeSeq, &_tc_TAO_tc_CORBA_PolicyTypeSeq)
TAO_NAMESPACE_END

static const CORBA::Long _oc_CORBA_SetOverrideType[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  38,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f5365), 
  ACE_NTOHL (0x744f7665), 
  ACE_NTOHL (0x72726964), 
  ACE_NTOHL (0x65547970), 
  ACE_NTOHL (0x653a312e), 
  ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/CORBA/SetOverrideType:1.0
  16,
  ACE_NTOHL (0x5365744f), 
  ACE_NTOHL (0x76657272), 
  ACE_NTOHL (0x69646554), 
  ACE_NTOHL (0x79706500),  // name = SetOverrideType
  2, // member count
  13,
  ACE_NTOHL (0x5345545f), 
  ACE_NTOHL (0x4f564552), 
  ACE_NTOHL (0x52494445), 
  ACE_NTOHL (0x0),  // name = SET_OVERRIDE
  13,
  ACE_NTOHL (0x4144445f), 
  ACE_NTOHL (0x4f564552), 
  ACE_NTOHL (0x52494445), 
  ACE_NTOHL (0x0),  // name = ADD_OVERRIDE
};

static CORBA::TypeCode _tc_TAO_tc_CORBA_SetOverrideType (
    CORBA::tk_enum,
    sizeof (_oc_CORBA_SetOverrideType),
    (char *) &_oc_CORBA_SetOverrideType,
    0,
    sizeof (CORBA::SetOverrideType)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (::CORBA::TypeCode_ptr, _tc_SetOverrideType, &_tc_TAO_tc_CORBA_SetOverrideType)
TAO_NAMESPACE_END


// TAO_IDL - Generated from 
// be/be_visitor_sequence/any_op_cs.cpp:61

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::PolicyList &_tao_elem
  )
{
  TAO_OutputCDR stream;
  
  if (stream << _tao_elem)
    {
      _tao_any._tao_replace (
          CORBA::_tc_PolicyList,
          TAO_ENCAP_BYTE_ORDER,
          stream.begin ()
        );
    }
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::PolicyList *_tao_elem
  )
{
  TAO_OutputCDR stream;
  
  if (stream << *_tao_elem)
    {
      _tao_any._tao_replace (
          CORBA::_tc_PolicyList,
          TAO_ENCAP_BYTE_ORDER,
          stream.begin (),
          1,
          _tao_elem,
          CORBA::PolicyList::_tao_any_destructor
        );
    }
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::PolicyList *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast(
      const CORBA::PolicyList*&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::PolicyList *&_tao_elem
  )
{
  _tao_elem = 0;
  
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    
    CORBA::Boolean result =
      type->equivalent (
          CORBA::_tc_PolicyList
          ACE_ENV_ARG_PARAMETER
        );
    ACE_TRY_CHECK;
    
    if (!result)
      {
        return 0; // not equivalent
      }
    
    if (_tao_any.any_owns_data ())
      {
        _tao_elem = ACE_static_cast(
            const CORBA::PolicyList*,
            _tao_any.value ()
          );
        
        return 1;
      }
    else
      {
        CORBA::PolicyList *tmp = 0;
        ACE_NEW_RETURN (
            tmp,
            CORBA::PolicyList,
            0
          );
        
        TAO_InputCDR stream (
            _tao_any._tao_get_cdr (),
            _tao_any._tao_byte_order ()
          );
        
        if (stream >> *tmp)
          {
            ((CORBA::Any *)&_tao_any)->_tao_replace (
                CORBA::_tc_PolicyList,
                1,
                ACE_static_cast (void *, tmp),
                CORBA::PolicyList::_tao_any_destructor
              );
            
            _tao_elem = tmp;
            return 1;
          }
        else
          {
            delete tmp;
          }
      }
  }
  ACE_CATCHANY
  {
  }
  ACE_ENDTRY;
  
  return 0;
}


// TAO_IDL - Generated from 
// be/be_visitor_sequence/any_op_cs.cpp:61

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::PolicyTypeSeq &_tao_elem
  )
{
  TAO_OutputCDR stream;
  
  if (stream << _tao_elem)
    {
      _tao_any._tao_replace (
          CORBA::_tc_PolicyTypeSeq,
          TAO_ENCAP_BYTE_ORDER,
          stream.begin ()
        );
    }
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::PolicyTypeSeq *_tao_elem
  )
{
  TAO_OutputCDR stream;
  
  if (stream << *_tao_elem)
    {
      _tao_any._tao_replace (
          CORBA::_tc_PolicyTypeSeq,
          TAO_ENCAP_BYTE_ORDER,
          stream.begin (),
          1,
          _tao_elem,
          CORBA::PolicyTypeSeq::_tao_any_destructor
        );
    }
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::PolicyTypeSeq *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast(
      const CORBA::PolicyTypeSeq*&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::PolicyTypeSeq *&_tao_elem
  )
{
  _tao_elem = 0;
  
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    
    CORBA::Boolean result =
      type->equivalent (
          CORBA::_tc_PolicyTypeSeq
          ACE_ENV_ARG_PARAMETER
        );
    ACE_TRY_CHECK;
    
    if (!result)
      {
        return 0; // not equivalent
      }
    
    if (_tao_any.any_owns_data ())
      {
        _tao_elem = ACE_static_cast(
            const CORBA::PolicyTypeSeq*,
            _tao_any.value ()
          );
        
        return 1;
      }
    else
      {
        CORBA::PolicyTypeSeq *tmp = 0;
        ACE_NEW_RETURN (
            tmp,
            CORBA::PolicyTypeSeq,
            0
          );
        
        TAO_InputCDR stream (
            _tao_any._tao_get_cdr (),
            _tao_any._tao_byte_order ()
          );
        
        if (stream >> *tmp)
          {
            ((CORBA::Any *)&_tao_any)->_tao_replace (
                CORBA::_tc_PolicyTypeSeq,
                1,
                ACE_static_cast (void *, tmp),
                CORBA::PolicyTypeSeq::_tao_any_destructor
              );
            
            _tao_elem = tmp;
            return 1;
          }
        else
          {
            delete tmp;
          }
      }
  }
  ACE_CATCHANY
  {
  }
  ACE_ENDTRY;
  
  return 0;
}

void operator<<= (CORBA::Any &_tao_any, CORBA::SetOverrideType _tao_elem)
{
  TAO_OutputCDR stream;
  stream << _tao_elem;
  _tao_any._tao_replace (
      CORBA::_tc_SetOverrideType,
      TAO_ENCAP_BYTE_ORDER,
      stream.begin ()
    );
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA::SetOverrideType &_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    
    CORBA::Boolean result = type->equivalent (CORBA::_tc_SetOverrideType ACE_ENV_ARG_PARAMETER);
    ACE_TRY_CHECK;
    
    if (!result)
      return 0; // not equivalent
    
    TAO_InputCDR stream (
        _tao_any._tao_get_cdr (),
        _tao_any._tao_byte_order ()
      );
    if (stream >> _tao_elem)
    {
      return 1;
    }
  }
  ACE_CATCHANY
  {
    return 0;
  }
  ACE_ENDTRY;
  return 0;
}

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::PolicyList &_tao_sequence
  )
{
  if (strm << _tao_sequence.length ())
  {
    // encode all elements
    CORBA::Boolean _tao_marshal_flag = 1;
    for (CORBA::ULong i = 0; i < _tao_sequence.length () && _tao_marshal_flag; i++)
    {
      _tao_marshal_flag = (strm << _tao_sequence[i].in ());
    }
    return _tao_marshal_flag;
  }
  return 0; // error
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::PolicyList &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;
  if (strm >> _tao_seq_len)
  {
    // Add a check to the length of the sequence
    // to make sure it does not exceed the length
    // of the stream. (See bug 1159.)
    if (_tao_seq_len > strm.length())
      return 0;
    // set the length of the sequence
    _tao_sequence.length (_tao_seq_len);
    // If length is 0 we return true.
    if (0 >= _tao_seq_len) 
      return 1;
    // retrieve all the elements
    CORBA::Boolean _tao_marshal_flag = 1;
    for (CORBA::ULong i = 0; i < _tao_sequence.length () && _tao_marshal_flag; i++)
    {
      _tao_marshal_flag = (strm >> _tao_sequence[i].out ());
    }
    return _tao_marshal_flag;
  }
  return 0; // error
}

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::PolicyTypeSeq &_tao_sequence
  )
{
  if (strm << _tao_sequence.length ())
  {
    // encode all elements
    return strm.write_ulong_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
  }
  return 0; // error
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::PolicyTypeSeq &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;
  if (strm >> _tao_seq_len)
  {
    // Add a check to the length of the sequence
    // to make sure it does not exceed the length
    // of the stream. (See bug 1159.)
    if (_tao_seq_len > strm.length())
      return 0;
    // set the length of the sequence
    _tao_sequence.length (_tao_seq_len);
    // If length is 0 we return true.
    if (0 >= _tao_seq_len) 
      return 1;
    // retrieve all the elements
    return strm.read_ulong_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
  }
  return 0; // error
}

