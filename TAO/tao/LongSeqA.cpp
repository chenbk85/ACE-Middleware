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

#include "LongSeqC.h"
#include "tao/Typecode.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:295

static const CORBA::Long _oc_CORBA_LongSeq[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  30,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f4c6f), 
  ACE_NTOHL (0x6e675365), 
  ACE_NTOHL (0x713a312e), 
  ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/CORBA/LongSeq:1.0
    8,
  ACE_NTOHL (0x4c6f6e67), 
  ACE_NTOHL (0x53657100),  // name = LongSeq
    CORBA::tk_sequence, // typecode kind
  12, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_long,

    0U,

};

static CORBA::TypeCode _tc_TAO_tc_CORBA_LongSeq (
    CORBA::tk_alias,
    sizeof (_oc_CORBA_LongSeq),
    (char *) &_oc_CORBA_LongSeq,
    0,
    0
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_LongSeq =
    &_tc_TAO_tc_CORBA_LongSeq;
}

// TAO_IDL - Generated from 
// be\be_visitor_sequence/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::LongSeq &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::LongSeq>::insert_copy (
      _tao_any,
      CORBA::LongSeq::_tao_any_destructor,
      CORBA::_tc_LongSeq,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::LongSeq *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::LongSeq>::insert (
      _tao_any,
      CORBA::LongSeq::_tao_any_destructor,
      CORBA::_tc_LongSeq,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::LongSeq *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const CORBA::LongSeq *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::LongSeq *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::LongSeq>::extract (
        _tao_any,
        CORBA::LongSeq::_tao_any_destructor,
        CORBA::_tc_LongSeq,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Dual_Impl_T<
        CORBA::LongSeq
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        CORBA::LongSeq \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
