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
// be/be_visitor_union/union_ci.cpp:51

// *************************************************************
// Inline operations for union GIOP::TargetAddress
// *************************************************************

// TAO_IDL - Generated from
// be/be_visitor_union/discriminant_ci.cpp:164

ACE_INLINE
void 
GIOP::TargetAddress::_default ()
{
  this->disc_ = -32768;
}

// Accessor to set the discriminant.
ACE_INLINE
void
GIOP::TargetAddress::_d (CORBA::Short discval)
{
  this->disc_ = discval;
}

// Accessor to get the discriminant.
ACE_INLINE
CORBA::Short
GIOP::TargetAddress::_d (void) const
{
  return this->disc_;
}

// TAO_IDL - Generated from
// be/be_visitor_union_branch/public_ci.cpp:906

// Accessor to set the member.
ACE_INLINE
void
GIOP::TargetAddress::object_key (const CORBA::OctetSeq &val)
{
  // Set the discriminant value.
  this->_reset (0, 0);
  this->disc_ = 0;
  ACE_NEW (
      this->u_.object_key_,
      CORBA::OctetSeq (val)
    );
}

// Readonly get method.
ACE_INLINE
const CORBA::OctetSeq &
GIOP::TargetAddress::object_key (void) const
{
  return *this->u_.object_key_;
}

// Read/write get method.
ACE_INLINE
CORBA::OctetSeq &
GIOP::TargetAddress::object_key (void)
{
  return *this->u_.object_key_;
}

// TAO_IDL - Generated from
// be/be_visitor_union_branch/public_ci.cpp:1215

// Accessor to set the member.
ACE_INLINE
void
GIOP::TargetAddress::profile (const IOP::TaggedProfile &val)
{
  // Set the discriminant value.
  this->_reset (1, 0);
  this->disc_ = 1;
  ACE_NEW (
      this->u_.profile_,
      IOP::TaggedProfile (val)
    );
}

// Readonly get method.
ACE_INLINE
const IOP::TaggedProfile &
GIOP::TargetAddress::profile (void) const
{
  return *this->u_.profile_;
}

// Read/write get method.
ACE_INLINE
IOP::TaggedProfile &
GIOP::TargetAddress::profile (void)
{
  return *this->u_.profile_;
}

// TAO_IDL - Generated from
// be/be_visitor_union_branch/public_ci.cpp:1215

// Accessor to set the member.
ACE_INLINE
void
GIOP::TargetAddress::ior (const GIOP::IORAddressingInfo &val)
{
  // Set the discriminant value.
  this->_reset (2, 0);
  this->disc_ = 2;
  ACE_NEW (
      this->u_.ior_,
      GIOP::IORAddressingInfo (val)
    );
}

// Readonly get method.
ACE_INLINE
const GIOP::IORAddressingInfo &
GIOP::TargetAddress::ior (void) const
{
  return *this->u_.ior_;
}

// Read/write get method.
ACE_INLINE
GIOP::IORAddressingInfo &
GIOP::TargetAddress::ior (void)
{
  return *this->u_.ior_;
}

// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_ci.cpp:70

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const GIOP::Version &_tao_aggregate
  )
{
  return
    (strm << CORBA::Any::from_octet (_tao_aggregate.major)) &&
    (strm << CORBA::Any::from_octet (_tao_aggregate.minor));
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    GIOP::Version &_tao_aggregate
  )
{
  return
    (strm >> CORBA::Any::to_octet (_tao_aggregate.major)) &&
    (strm >> CORBA::Any::to_octet (_tao_aggregate.minor));
}

// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_ci.cpp:70

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const GIOP::IORAddressingInfo &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.selected_profile_index) &&
    (strm << _tao_aggregate.ior);
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    GIOP::IORAddressingInfo &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.selected_profile_index) &&
    (strm >> _tao_aggregate.ior);
}

// TAO_IDL - Generated from
// be/be_visitor_union/cdr_op_ci.cpp:69

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const GIOP::TargetAddress &_tao_union
  )
{
  if ( !(strm << _tao_union._d ()) )
    {
      return 0;
    }
  
  CORBA::Boolean result = 1;
  
  switch (_tao_union._d ())
  {
    case 0:
      {
        result = strm << _tao_union.object_key ();
      }
      break;
    case 1:
      {
        result = strm << _tao_union.profile ();
      }
      break;
    case 2:
      {
        result = strm << _tao_union.ior ();
      }
      break;
    default:
      break;
  }
  
  return result;
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    GIOP::TargetAddress &_tao_union
  )
{
  CORBA::Short _tao_discriminant;
  if ( !(strm >> _tao_discriminant) )
    {
      return 0;
    }
  
  CORBA::Boolean result = 1;
  
  switch (_tao_discriminant)
  {
    case 0:
      {
        CORBA::OctetSeq _tao_union_tmp;
        result = strm >> _tao_union_tmp;
        
        if (result)
          {
            _tao_union.object_key (_tao_union_tmp);
            _tao_union._d (_tao_discriminant);
          }
      }
      break;
    case 1:
      {
        IOP::TaggedProfile _tao_union_tmp;
        result = strm >> _tao_union_tmp;
        
        if (result)
          {
            _tao_union.profile (_tao_union_tmp);
            _tao_union._d (_tao_discriminant);
          }
      }
      break;
    case 2:
      {
        GIOP::IORAddressingInfo _tao_union_tmp;
        result = strm >> _tao_union_tmp;
        
        if (result)
          {
            _tao_union.ior (_tao_union_tmp);
            _tao_union._d (_tao_discriminant);
          }
      }
      break;
    default:
      _tao_union._d (_tao_discriminant);
      break;
  }
  
  return result;
}

