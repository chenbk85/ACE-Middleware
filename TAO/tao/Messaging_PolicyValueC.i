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
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_structure.cpp:194

// *************************************************************
// Inline operations for class Messaging::PolicyValue_var
// *************************************************************

ACE_INLINE
Messaging::PolicyValue_var::PolicyValue_var (void)
  : ptr_ (0)
{}

ACE_INLINE
Messaging::PolicyValue_var::PolicyValue_var (PolicyValue *p)
  : ptr_ (p)
{}

ACE_INLINE
Messaging::PolicyValue_var::PolicyValue_var (const ::Messaging::PolicyValue_var &p)
{
  if (p.ptr_)
    {
      ACE_NEW (this->ptr_, ::Messaging::PolicyValue (*p.ptr_));
    }
  else
    {
      this->ptr_ = 0;
    }
}

ACE_INLINE
Messaging::PolicyValue_var::~PolicyValue_var (void)
{
  delete this->ptr_;
}

ACE_INLINE
Messaging::PolicyValue_var &
Messaging::PolicyValue_var::operator= (PolicyValue *_tao_struct_var)
{
  delete this->ptr_;
  this->ptr_ = _tao_struct_var;
  return *this;
}

ACE_INLINE
::Messaging::PolicyValue_var &
Messaging::PolicyValue_var::operator= (const ::Messaging::PolicyValue_var &_tao_struct_var)
{
  if (this != &_tao_struct_var)
    {
      if (_tao_struct_var.ptr_ == 0)
        {
          delete this->ptr_;
          this->ptr_ = 0;
        }
      else
        {
          PolicyValue *deep_copy = 0;
          ACE_NEW_RETURN (
              deep_copy,
              PolicyValue (*_tao_struct_var.ptr_),
              *this
            );
          
          if (deep_copy != 0)
            {
              PolicyValue *tmp = deep_copy;
              deep_copy = this->ptr_;
              this->ptr_ = tmp;
              delete deep_copy;
            }
        }
    }
  
  return *this;
}

ACE_INLINE const ::Messaging::PolicyValue *
Messaging::PolicyValue_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE ::Messaging::PolicyValue *
Messaging::PolicyValue_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
Messaging::PolicyValue_var::operator const ::Messaging::PolicyValue &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
Messaging::PolicyValue_var::operator ::Messaging::PolicyValue &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE
Messaging::PolicyValue_var::operator ::Messaging::PolicyValue &() const // cast 
{
  return *this->ptr_;
}

// Variable-size types only.
ACE_INLINE
Messaging::PolicyValue_var::operator ::Messaging::PolicyValue *&() // cast 
{
  return this->ptr_;
}

ACE_INLINE const ::Messaging::PolicyValue &
Messaging::PolicyValue_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE ::Messaging::PolicyValue &
Messaging::PolicyValue_var::inout (void)
{
  return *this->ptr_;
}

// Mapping for variable size.
ACE_INLINE ::Messaging::PolicyValue *&
Messaging::PolicyValue_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE ::Messaging::PolicyValue *
Messaging::PolicyValue_var::_retn (void)
{
  ::Messaging::PolicyValue *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE ::Messaging::PolicyValue *
Messaging::PolicyValue_var::ptr (void) const
{
  return this->ptr_;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_structure.cpp:523

// *************************************************************
// Inline operations for class Messaging::PolicyValue_out
// *************************************************************

ACE_INLINE
Messaging::PolicyValue_out::PolicyValue_out (::Messaging::PolicyValue *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
Messaging::PolicyValue_out::PolicyValue_out (PolicyValue_var &p)
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
Messaging::PolicyValue_out::PolicyValue_out (const ::Messaging::PolicyValue_out &p)
  : ptr_ (ACE_const_cast (PolicyValue_out&, p).ptr_)
{}

ACE_INLINE
Messaging::PolicyValue_out &
Messaging::PolicyValue_out::operator= (const ::Messaging::PolicyValue_out &p)
{
  this->ptr_ = ACE_const_cast (PolicyValue_out&, p).ptr_;
  return *this;
}

ACE_INLINE
Messaging::PolicyValue_out &
Messaging::PolicyValue_out::operator= (PolicyValue *_tao_struct_out)
{
  this->ptr_ = _tao_struct_out;
  return *this;
}

ACE_INLINE 
Messaging::PolicyValue_out::operator ::Messaging::PolicyValue *&() // cast
{
  return this->ptr_;
}

ACE_INLINE ::Messaging::PolicyValue *&
Messaging::PolicyValue_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE ::Messaging::PolicyValue *
Messaging::PolicyValue_out::operator-> (void)
{
  return this->ptr_;
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/gen_unbounded_sequence_ci.cpp:99

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_SEQUENCE_MESSAGING_POLICYVALUESEQ_CI_)
#define __TAO_UNBOUNDED_SEQUENCE_MESSAGING_POLICYVALUESEQ_CI_

ACE_INLINE
Messaging::PolicyValue *
Messaging::_TAO_Unbounded_Sequence_Messaging_PolicyValueSeq::allocbuf (CORBA::ULong size)
{
  Messaging::PolicyValue *retval = 0;
  ACE_NEW_RETURN (retval, Messaging::PolicyValue[size], 0);
  return retval;
}

ACE_INLINE
void Messaging::_TAO_Unbounded_Sequence_Messaging_PolicyValueSeq::freebuf (Messaging::PolicyValue *buffer)
{
  delete [] buffer;
}

ACE_INLINE
Messaging::_TAO_Unbounded_Sequence_Messaging_PolicyValueSeq::_TAO_Unbounded_Sequence_Messaging_PolicyValueSeq (void)
{
}

ACE_INLINE
Messaging::_TAO_Unbounded_Sequence_Messaging_PolicyValueSeq::_TAO_Unbounded_Sequence_Messaging_PolicyValueSeq (CORBA::ULong maximum) 
  : TAO_Unbounded_Base_Sequence (maximum, _TAO_Unbounded_Sequence_Messaging_PolicyValueSeq::allocbuf (maximum))
{
}

ACE_INLINE
Messaging::_TAO_Unbounded_Sequence_Messaging_PolicyValueSeq::_TAO_Unbounded_Sequence_Messaging_PolicyValueSeq (
    CORBA::ULong maximum,
    CORBA::ULong length,
    Messaging::PolicyValue *data,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Base_Sequence (maximum, length, data, release)
{
}

ACE_INLINE
Messaging::_TAO_Unbounded_Sequence_Messaging_PolicyValueSeq::_TAO_Unbounded_Sequence_Messaging_PolicyValueSeq (
    const _TAO_Unbounded_Sequence_Messaging_PolicyValueSeq &rhs
  )
  : TAO_Unbounded_Base_Sequence (rhs)
{
  if (rhs.buffer_ != 0)
    {
      Messaging::PolicyValue *tmp1 =
        _TAO_Unbounded_Sequence_Messaging_PolicyValueSeq::allocbuf (this->maximum_);
      Messaging::PolicyValue * const tmp2 =
        ACE_reinterpret_cast (Messaging::PolicyValue * ACE_CAST_CONST, rhs.buffer_);
      
      for (CORBA::ULong i = 0; i < this->length_; ++i)
        {
          tmp1[i] = tmp2[i];
        }
      
      this->buffer_ = tmp1;
    }
  else
    {
      this->buffer_ = 0;
    }
}

ACE_INLINE
Messaging::_TAO_Unbounded_Sequence_Messaging_PolicyValueSeq &
Messaging::_TAO_Unbounded_Sequence_Messaging_PolicyValueSeq::operator= (
    const _TAO_Unbounded_Sequence_Messaging_PolicyValueSeq &rhs
  )
{
  if (this == &rhs)
    {
      return *this;
    }
  
  if (this->release_)
    {
      if (this->maximum_ < rhs.maximum_)
        {
          // Free the old buffer.
          Messaging::PolicyValue *tmp =
            ACE_reinterpret_cast (Messaging::PolicyValue *, this->buffer_);
          
          _TAO_Unbounded_Sequence_Messaging_PolicyValueSeq::freebuf (tmp);
          
          this->buffer_ =
            _TAO_Unbounded_Sequence_Messaging_PolicyValueSeq::allocbuf (rhs.maximum_);
        }
    }
  else
    {
      this->buffer_ =
        _TAO_Unbounded_Sequence_Messaging_PolicyValueSeq::allocbuf (rhs.maximum_);
    }
  
  TAO_Unbounded_Base_Sequence::operator= (rhs);
  
  Messaging::PolicyValue *tmp1 =
    ACE_reinterpret_cast (Messaging::PolicyValue *, this->buffer_);
  Messaging::PolicyValue * const tmp2 =
    ACE_reinterpret_cast (Messaging::PolicyValue * ACE_CAST_CONST, rhs.buffer_);
  
  for (CORBA::ULong i = 0; i < this->length_; ++i)
    {
      tmp1[i] = tmp2[i];
    }
  
  return *this;
}

// = Accessors.
ACE_INLINE
Messaging::PolicyValue &
Messaging::_TAO_Unbounded_Sequence_Messaging_PolicyValueSeq::operator[] (CORBA::ULong i)
{
  ACE_ASSERT (i < this->maximum_);
  Messaging::PolicyValue* tmp =
    ACE_reinterpret_cast (Messaging::PolicyValue*, this->buffer_);
  return tmp[i];
}

ACE_INLINE
const Messaging::PolicyValue &
Messaging::_TAO_Unbounded_Sequence_Messaging_PolicyValueSeq::operator[] (CORBA::ULong i) const
{
  ACE_ASSERT (i < this->maximum_);
  Messaging::PolicyValue * const tmp =
    ACE_reinterpret_cast (Messaging::PolicyValue* ACE_CAST_CONST, this->buffer_);
  return tmp[i];
}

// Implement the TAO_Base_Sequence methods (see Sequence.h)

ACE_INLINE
Messaging::PolicyValue *
Messaging::_TAO_Unbounded_Sequence_Messaging_PolicyValueSeq::get_buffer (CORBA::Boolean orphan)
{
  Messaging::PolicyValue *result = 0;
  
  if (orphan == 0)
    {
      // We retain ownership.
      if (this->buffer_ == 0)
        {
          result =
            _TAO_Unbounded_Sequence_Messaging_PolicyValueSeq::allocbuf (this->length_);
          this->buffer_ = result;
          this->release_ = 1;
        }
      else
        {
          result =
            ACE_reinterpret_cast (Messaging::PolicyValue*, this->buffer_);
        }
    }
  else // if (orphan == 1)
    {
      if (this->release_ != 0)
        {
          // We set the state back to default and relinquish ownership.
          result =
            ACE_reinterpret_cast(Messaging::PolicyValue*,this->buffer_);
          this->maximum_ = 0;
          this->length_ = 0;
          this->buffer_ = 0;
          this->release_ = 0;
        }
    }
  
  return result;
}

ACE_INLINE
const Messaging::PolicyValue *
Messaging::_TAO_Unbounded_Sequence_Messaging_PolicyValueSeq::get_buffer (void) const
{
  return ACE_reinterpret_cast (const Messaging::PolicyValue * ACE_CAST_CONST, this->buffer_);
}

ACE_INLINE
void
Messaging::_TAO_Unbounded_Sequence_Messaging_PolicyValueSeq::replace (
    CORBA::ULong max,
    CORBA::ULong length,
    Messaging::PolicyValue *data,
    CORBA::Boolean release
  )
{
  this->maximum_ = max;
  this->length_ = length;
  
  if (this->buffer_ && this->release_ == 1)
    {
      Messaging::PolicyValue *tmp =
        ACE_reinterpret_cast (Messaging::PolicyValue*, this->buffer_);
      _TAO_Unbounded_Sequence_Messaging_PolicyValueSeq::freebuf (tmp);
    }
  
  this->buffer_ = data;
  this->release_ = release;
}

#endif /* end #if !defined */

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 

#if !defined (_MESSAGING_POLICYVALUESEQ_CI_)
#define _MESSAGING_POLICYVALUESEQ_CI_

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_ci.cpp:226

// *************************************************************
// Inline operations for class Messaging::PolicyValueSeq_var
// *************************************************************

ACE_INLINE
Messaging::PolicyValueSeq_var::PolicyValueSeq_var (void)
  : ptr_ (0)
{}

ACE_INLINE
Messaging::PolicyValueSeq_var::PolicyValueSeq_var (PolicyValueSeq *p)
  : ptr_ (p)
{}

ACE_INLINE
Messaging::PolicyValueSeq_var::PolicyValueSeq_var (const ::Messaging::PolicyValueSeq_var &p)
{
  if (p.ptr_)
    {
      ACE_NEW (this->ptr_, ::Messaging::PolicyValueSeq (*p.ptr_));
    }
  else
    {
      this->ptr_ = 0;
    }
}

ACE_INLINE
Messaging::PolicyValueSeq_var::~PolicyValueSeq_var (void)
{
  delete this->ptr_;
}

ACE_INLINE
Messaging::PolicyValueSeq_var &
Messaging::PolicyValueSeq_var::operator= (PolicyValueSeq *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
::Messaging::PolicyValueSeq_var &
Messaging::PolicyValueSeq_var::operator= (const ::Messaging::PolicyValueSeq_var &p)
{
  if (this != &p)
    {
      if (p.ptr_ == 0)
        {
          delete this->ptr_;
          this->ptr_ = 0;
        }
      else
        {
          PolicyValueSeq *deep_copy = 0;
          ACE_NEW_RETURN (
              deep_copy,
              PolicyValueSeq (*p.ptr_),
              *this
            );
          
          if (deep_copy != 0)
            {
              PolicyValueSeq *tmp = deep_copy;
              deep_copy = this->ptr_;
              this->ptr_ = tmp;
              delete deep_copy;
            }
        }
    }
  
  return *this;
}

ACE_INLINE
const ::Messaging::PolicyValueSeq *
Messaging::PolicyValueSeq_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE
::Messaging::PolicyValueSeq *
Messaging::PolicyValueSeq_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
Messaging::PolicyValueSeq_var::operator const ::Messaging::PolicyValueSeq &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
Messaging::PolicyValueSeq_var::operator ::Messaging::PolicyValueSeq &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE
Messaging::PolicyValueSeq_var::operator ::Messaging::PolicyValueSeq &() const // cast 
{
  return *this->ptr_;
}

// Variable-size types only.
ACE_INLINE
Messaging::PolicyValueSeq_var::operator ::Messaging::PolicyValueSeq *&() // cast 
{
  return this->ptr_;
}

ACE_INLINE
Messaging::PolicyValue &
Messaging::PolicyValueSeq_var::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

ACE_INLINE
const Messaging::PolicyValue &
Messaging::PolicyValueSeq_var::operator[] (CORBA::ULong index) const
{
  return ACE_const_cast (const Messaging::PolicyValue &, this->ptr_->operator[] (index));
}

ACE_INLINE
const ::Messaging::PolicyValueSeq &
Messaging::PolicyValueSeq_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE
::Messaging::PolicyValueSeq &
Messaging::PolicyValueSeq_var::inout (void)
{
  return *this->ptr_;
}

ACE_INLINE
::Messaging::PolicyValueSeq *&
Messaging::PolicyValueSeq_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE
::Messaging::PolicyValueSeq *
Messaging::PolicyValueSeq_var::_retn (void)
{
  ::Messaging::PolicyValueSeq *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE
::Messaging::PolicyValueSeq *
Messaging::PolicyValueSeq_var::ptr (void) const
{
  return this->ptr_;
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_ci.cpp:567

// *************************************************************
// Inline operations for class Messaging::PolicyValueSeq_out
// *************************************************************

ACE_INLINE
Messaging::PolicyValueSeq_out::PolicyValueSeq_out (PolicyValueSeq *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
Messaging::PolicyValueSeq_out::PolicyValueSeq_out (PolicyValueSeq_var &p)
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
Messaging::PolicyValueSeq_out::PolicyValueSeq_out (const ::Messaging::PolicyValueSeq_out &p)
  : ptr_ (ACE_const_cast (PolicyValueSeq_out&, p).ptr_)
{}

ACE_INLINE
::Messaging::PolicyValueSeq_out &
Messaging::PolicyValueSeq_out::operator= (const ::Messaging::PolicyValueSeq_out &p)
{
  this->ptr_ = ACE_const_cast (PolicyValueSeq_out&, p).ptr_;
  return *this;
}

ACE_INLINE
::Messaging::PolicyValueSeq_out &
Messaging::PolicyValueSeq_out::operator= (PolicyValueSeq *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
Messaging::PolicyValueSeq_out::operator ::Messaging::PolicyValueSeq *&() // cast
{
  return this->ptr_;
}

ACE_INLINE
::Messaging::PolicyValueSeq *&
Messaging::PolicyValueSeq_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE
::Messaging::PolicyValueSeq *
Messaging::PolicyValueSeq_out::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
Messaging::PolicyValue &
Messaging::PolicyValueSeq_out::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:84

#if !defined _TAO_CDR_OP_Messaging_PolicyValue__tao_seq_Octet_I_
#define _TAO_CDR_OP_Messaging_PolicyValue__tao_seq_Octet_I_

CORBA::Boolean TAO_Export operator<< (
    TAO_OutputCDR &,
    const Messaging::PolicyValue::_tao_seq_Octet &
  );

CORBA::Boolean TAO_Export operator>> (
    TAO_InputCDR &,
    Messaging::PolicyValue::_tao_seq_Octet &
  );

#endif /* _TAO_CDR_OP_Messaging_PolicyValue__tao_seq_Octet_I_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ci.cpp:103

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Messaging::PolicyValue &_tao_aggregate
  )
{
  if (
    (strm << _tao_aggregate.ptype) &&
    (strm << _tao_aggregate.pvalue)
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
    Messaging::PolicyValue &_tao_aggregate
  )
{
  if (
    (strm >> _tao_aggregate.ptype) &&
    (strm >> _tao_aggregate.pvalue)
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

#if !defined _TAO_CDR_OP_Messaging_PolicyValueSeq_I_
#define _TAO_CDR_OP_Messaging_PolicyValueSeq_I_

CORBA::Boolean TAO_Export operator<< (
    TAO_OutputCDR &,
    const Messaging::PolicyValueSeq &
  );

CORBA::Boolean TAO_Export operator>> (
    TAO_InputCDR &,
    Messaging::PolicyValueSeq &
  );

#endif /* _TAO_CDR_OP_Messaging_PolicyValueSeq_I_ */

