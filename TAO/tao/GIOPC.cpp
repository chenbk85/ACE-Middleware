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
// be/be_codegen.cpp:338


#include "GIOPC.h"
#include "tao/Typecode.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "GIOPC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:62

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_GIOP_AddressingDisposition[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  43,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x47494f50), 
  ACE_NTOHL (0x2f416464), 
  ACE_NTOHL (0x72657373), 
  ACE_NTOHL (0x696e6744), 
  ACE_NTOHL (0x6973706f), 
  ACE_NTOHL (0x73697469), 
  ACE_NTOHL (0x6f6e3a31), 
  ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/GIOP/AddressingDisposition:1.0
    22,
  ACE_NTOHL (0x41646472), 
  ACE_NTOHL (0x65737369), 
  ACE_NTOHL (0x6e674469), 
  ACE_NTOHL (0x73706f73), 
  ACE_NTOHL (0x6974696f), 
  ACE_NTOHL (0x6e000000),  // name = AddressingDisposition
    CORBA::tk_short,

};

static CORBA::TypeCode _tc_TAO_tc_GIOP_AddressingDisposition (
    CORBA::tk_alias,
    sizeof (_oc_GIOP_AddressingDisposition),
    (char *) &_oc_GIOP_AddressingDisposition,
    0,
    sizeof (GIOP::AddressingDisposition)
  );

namespace GIOP
{
  ::CORBA::TypeCode_ptr _tc_AddressingDisposition =
    &_tc_TAO_tc_GIOP_AddressingDisposition;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_GIOP_Version[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  29,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x47494f50), 
  ACE_NTOHL (0x2f566572), 
  ACE_NTOHL (0x73696f6e), 
  ACE_NTOHL (0x3a312e30), 
  ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/GIOP/Version:1.0
    8,
  ACE_NTOHL (0x56657273), 
  ACE_NTOHL (0x696f6e00),  // name = Version
  2, // member count
    6,
  ACE_NTOHL (0x6d616a6f), 
  ACE_NTOHL (0x72000000),  // name = major
    CORBA::tk_octet,

  6,
  ACE_NTOHL (0x6d696e6f), 
  ACE_NTOHL (0x72000000),  // name = minor
    CORBA::tk_octet,

};

static CORBA::TypeCode _tc_TAO_tc_GIOP_Version (
    CORBA::tk_struct,
    sizeof (_oc_GIOP_Version),
    (char *) &_oc_GIOP_Version,
    0,
    sizeof (GIOP::Version)
  );

namespace GIOP
{
  ::CORBA::TypeCode_ptr _tc_Version =
    &_tc_TAO_tc_GIOP_Version;
}

// TAO_IDL - Generated from 
// be/be_visitor_structure/structure_cs.cpp:66

void 
GIOP::Version::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  Version *_tao_tmp_pointer =
    ACE_static_cast (Version *, _tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_GIOP_IORAddressingInfo[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  39,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x47494f50), 
  ACE_NTOHL (0x2f494f52), 
  ACE_NTOHL (0x41646472), 
  ACE_NTOHL (0x65737369), 
  ACE_NTOHL (0x6e67496e), 
  ACE_NTOHL (0x666f3a31), 
  ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/GIOP/IORAddressingInfo:1.0
    18,
  ACE_NTOHL (0x494f5241), 
  ACE_NTOHL (0x64647265), 
  ACE_NTOHL (0x7373696e), 
  ACE_NTOHL (0x67496e66), 
  ACE_NTOHL (0x6f000000),  // name = IORAddressingInfo
  2, // member count
    23,
  ACE_NTOHL (0x73656c65), 
  ACE_NTOHL (0x63746564), 
  ACE_NTOHL (0x5f70726f), 
  ACE_NTOHL (0x66696c65), 
  ACE_NTOHL (0x5f696e64), 
  ACE_NTOHL (0x65780000),  // name = selected_profile_index
    CORBA::tk_ulong,

  4,
  ACE_NTOHL (0x696f7200),  // name = ior
    CORBA::tk_struct, // typecode kind
  352, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    24,
    ACE_NTOHL (0x49444c3a), 
    ACE_NTOHL (0x6f6d672e), 
    ACE_NTOHL (0x6f72672f), 
    ACE_NTOHL (0x494f502f), 
    ACE_NTOHL (0x494f523a), 
    ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/IOP/IOR:1.0
        4,
    ACE_NTOHL (0x494f5200),  // name = IOR
    2, // member count
        8,
    ACE_NTOHL (0x74797065), 
    ACE_NTOHL (0x5f696400),  // name = type_id
        CORBA::tk_string, 
    0U, // string length
    9,
    ACE_NTOHL (0x70726f66), 
    ACE_NTOHL (0x696c6573), 
    ACE_NTOHL (0x0),  // name = profiles
        CORBA::tk_sequence, // typecode kind
    264, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      CORBA::tk_struct, // typecode kind
      248, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        34,
        ACE_NTOHL (0x49444c3a), 
        ACE_NTOHL (0x6f6d672e), 
        ACE_NTOHL (0x6f72672f), 
        ACE_NTOHL (0x494f502f), 
        ACE_NTOHL (0x54616767), 
        ACE_NTOHL (0x65645072), 
        ACE_NTOHL (0x6f66696c), 
        ACE_NTOHL (0x653a312e), 
        ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/IOP/TaggedProfile:1.0
                14,
        ACE_NTOHL (0x54616767), 
        ACE_NTOHL (0x65645072), 
        ACE_NTOHL (0x6f66696c), 
        ACE_NTOHL (0x65000000),  // name = TaggedProfile
        2, // member count
                4,
        ACE_NTOHL (0x74616700),  // name = tag
                CORBA::tk_alias, // typecode kind for typedefs
        60, // encapsulation length
          TAO_ENCAP_BYTE_ORDER, // byte order
          30,
          ACE_NTOHL (0x49444c3a), 
          ACE_NTOHL (0x6f6d672e), 
          ACE_NTOHL (0x6f72672f), 
          ACE_NTOHL (0x494f502f), 
          ACE_NTOHL (0x50726f66), 
          ACE_NTOHL (0x696c6549), 
          ACE_NTOHL (0x643a312e), 
          ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/IOP/ProfileId:1.0
                    10,
          ACE_NTOHL (0x50726f66), 
          ACE_NTOHL (0x696c6549), 
          ACE_NTOHL (0x64000000),  // name = ProfileId
                    CORBA::tk_ulong,


        13,
        ACE_NTOHL (0x70726f66), 
        ACE_NTOHL (0x696c655f), 
        ACE_NTOHL (0x64617461), 
        ACE_NTOHL (0x0),  // name = profile_data
                CORBA::tk_alias, // typecode kind for typedefs
        76, // encapsulation length
          TAO_ENCAP_BYTE_ORDER, // byte order
          31,
          ACE_NTOHL (0x49444c3a), 
          ACE_NTOHL (0x6f6d672e), 
          ACE_NTOHL (0x6f72672f), 
          ACE_NTOHL (0x434f5242), 
          ACE_NTOHL (0x412f4f63), 
          ACE_NTOHL (0x74657453), 
          ACE_NTOHL (0x65713a31), 
          ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/CORBA/OctetSeq:1.0
                    9,
          ACE_NTOHL (0x4f637465), 
          ACE_NTOHL (0x74536571), 
          ACE_NTOHL (0x0),  // name = OctetSeq
                    CORBA::tk_sequence, // typecode kind
          12, // encapsulation length
            TAO_ENCAP_BYTE_ORDER, // byte order
            CORBA::tk_octet,

            0U,



      0U,


};

static CORBA::TypeCode _tc_TAO_tc_GIOP_IORAddressingInfo (
    CORBA::tk_struct,
    sizeof (_oc_GIOP_IORAddressingInfo),
    (char *) &_oc_GIOP_IORAddressingInfo,
    0,
    sizeof (GIOP::IORAddressingInfo)
  );

namespace GIOP
{
  ::CORBA::TypeCode_ptr _tc_IORAddressingInfo =
    &_tc_TAO_tc_GIOP_IORAddressingInfo;
}

// TAO_IDL - Generated from 
// be/be_visitor_structure/structure_cs.cpp:66

void 
GIOP::IORAddressingInfo::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  IORAddressingInfo *_tao_tmp_pointer =
    ACE_static_cast (IORAddressingInfo *, _tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from
// be/be_visitor_union/union_cs.cpp:91

GIOP::TargetAddress::TargetAddress (void)
{
  ACE_OS::memset (&this->disc_, 0, sizeof (this->disc_));
  ACE_OS::memset (&this->u_, 0, sizeof (this->u_));
  this->disc_ = 0;
}

GIOP::TargetAddress::TargetAddress (const ::GIOP::TargetAddress &u)
{
  this->disc_ = u.disc_;
  switch (this->disc_)
  {
    case 0:
    {
      if (u.u_.object_key_ == 0)
        {
          this->u_.object_key_ = 0;
        }
      else
        {
          ACE_NEW (
              this->u_.object_key_,
              CORBA::OctetSeq (*u.u_.object_key_)
            );
        }
    }
    break;
    case 1:
    {
      if (u.u_.profile_ == 0)
        {
          this->u_.profile_ = 0;
        }
      else
        {
          ACE_NEW (
              this->u_.profile_,
              IOP::TaggedProfile (*u.u_.profile_)
            );
        }
    }
    break;
    case 2:
    {
      if (u.u_.ior_ == 0)
        {
          this->u_.ior_ = 0;
        }
      else
        {
          ACE_NEW (
              this->u_.ior_,
              GIOP::IORAddressingInfo (*u.u_.ior_)
            );
        }
    }
    break;
    default:
    break;
  }
}

GIOP::TargetAddress::~TargetAddress (void)
{
  // Finalize.
  this->_reset (this->disc_, 1);
}

void GIOP::TargetAddress::_tao_any_destructor (void *_tao_void_pointer)
{
  TargetAddress *tmp =
    ACE_static_cast (TargetAddress *, _tao_void_pointer);
  delete tmp;
}

GIOP::TargetAddress &
GIOP::TargetAddress::operator= (const ::GIOP::TargetAddress &u)
{
  if (&u == this)
    {
      return *this;
    }
  
  this->_reset (u.disc_, 0);
  this->disc_ = u.disc_;
  
  switch (this->disc_)
  {
    case 0:
    {
      if (u.u_.object_key_ == 0)
        {
          this->u_.object_key_ = 0;
        }
      else
        {
          ACE_NEW_RETURN (
              this->u_.object_key_,
              CORBA::OctetSeq (*u.u_.object_key_),
              *this
            );
        }
    }
    break;
    case 1:
    {
      if (u.u_.profile_ == 0)
        {
          this->u_.profile_ = 0;
        }
      else
        {
          ACE_NEW_RETURN (
              this->u_.profile_,
              IOP::TaggedProfile (*u.u_.profile_),
              *this
            );
        }
    }
    break;
    case 2:
    {
      if (u.u_.ior_ == 0)
        {
          this->u_.ior_ = 0;
        }
      else
        {
          ACE_NEW_RETURN (
              this->u_.ior_,
              GIOP::IORAddressingInfo (*u.u_.ior_),
              *this
            );
        }
    }
    break;
    default:
    break;
  }
  
  return *this;
}

// Reset method to reset old values of a union.
void GIOP::TargetAddress::_reset (CORBA::Short, CORBA::Boolean /*finalize*/)
{
  switch (this->disc_)
  {
    case 0:
      delete this->u_.object_key_;
      this->u_.object_key_ = 0;
      break;
    case 1:
      delete this->u_.profile_;
      this->u_.profile_ = 0;
      break;
    case 2:
      delete this->u_.ior_;
      this->u_.ior_ = 0;
      break;
    default:
      break;
  }
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_GIOP_TargetAddress[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  35,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x47494f50), 
  ACE_NTOHL (0x2f546172), 
  ACE_NTOHL (0x67657441), 
  ACE_NTOHL (0x64647265), 
  ACE_NTOHL (0x73733a31), 
  ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/GIOP/TargetAddress:1.0
  14,
  ACE_NTOHL (0x54617267), 
  ACE_NTOHL (0x65744164), 
  ACE_NTOHL (0x64726573), 
  ACE_NTOHL (0x73000000),  // name = TargetAddress
    CORBA::tk_short,

-1, // default used index
  3, // member count
    ACE_IDL_NSTOHL (0x0000), // union case label (evaluated value)
  11,
  ACE_NTOHL (0x6f626a65), 
  ACE_NTOHL (0x63745f6b), 
  ACE_NTOHL (0x65790000),  // name = object_key
    CORBA::tk_alias, // typecode kind for typedefs
  76, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    31,
    ACE_NTOHL (0x49444c3a), 
    ACE_NTOHL (0x6f6d672e), 
    ACE_NTOHL (0x6f72672f), 
    ACE_NTOHL (0x434f5242), 
    ACE_NTOHL (0x412f4f63), 
    ACE_NTOHL (0x74657453), 
    ACE_NTOHL (0x65713a31), 
    ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/CORBA/OctetSeq:1.0
        9,
    ACE_NTOHL (0x4f637465), 
    ACE_NTOHL (0x74536571), 
    ACE_NTOHL (0x0),  // name = OctetSeq
        CORBA::tk_sequence, // typecode kind
    12, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      CORBA::tk_octet,

      0U,


  ACE_IDL_NSTOHL (0x0001), // union case label (evaluated value)
  8,
  ACE_NTOHL (0x70726f66), 
  ACE_NTOHL (0x696c6500),  // name = profile
    CORBA::tk_struct, // typecode kind
  248, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    34,
    ACE_NTOHL (0x49444c3a), 
    ACE_NTOHL (0x6f6d672e), 
    ACE_NTOHL (0x6f72672f), 
    ACE_NTOHL (0x494f502f), 
    ACE_NTOHL (0x54616767), 
    ACE_NTOHL (0x65645072), 
    ACE_NTOHL (0x6f66696c), 
    ACE_NTOHL (0x653a312e), 
    ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/IOP/TaggedProfile:1.0
        14,
    ACE_NTOHL (0x54616767), 
    ACE_NTOHL (0x65645072), 
    ACE_NTOHL (0x6f66696c), 
    ACE_NTOHL (0x65000000),  // name = TaggedProfile
    2, // member count
        4,
    ACE_NTOHL (0x74616700),  // name = tag
        CORBA::tk_alias, // typecode kind for typedefs
    60, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      30,
      ACE_NTOHL (0x49444c3a), 
      ACE_NTOHL (0x6f6d672e), 
      ACE_NTOHL (0x6f72672f), 
      ACE_NTOHL (0x494f502f), 
      ACE_NTOHL (0x50726f66), 
      ACE_NTOHL (0x696c6549), 
      ACE_NTOHL (0x643a312e), 
      ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/IOP/ProfileId:1.0
            10,
      ACE_NTOHL (0x50726f66), 
      ACE_NTOHL (0x696c6549), 
      ACE_NTOHL (0x64000000),  // name = ProfileId
            CORBA::tk_ulong,


    13,
    ACE_NTOHL (0x70726f66), 
    ACE_NTOHL (0x696c655f), 
    ACE_NTOHL (0x64617461), 
    ACE_NTOHL (0x0),  // name = profile_data
        CORBA::tk_alias, // typecode kind for typedefs
    76, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      31,
      ACE_NTOHL (0x49444c3a), 
      ACE_NTOHL (0x6f6d672e), 
      ACE_NTOHL (0x6f72672f), 
      ACE_NTOHL (0x434f5242), 
      ACE_NTOHL (0x412f4f63), 
      ACE_NTOHL (0x74657453), 
      ACE_NTOHL (0x65713a31), 
      ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/CORBA/OctetSeq:1.0
            9,
      ACE_NTOHL (0x4f637465), 
      ACE_NTOHL (0x74536571), 
      ACE_NTOHL (0x0),  // name = OctetSeq
            CORBA::tk_sequence, // typecode kind
      12, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        CORBA::tk_octet,

        0U,



  ACE_IDL_NSTOHL (0x0002), // union case label (evaluated value)
  4,
  ACE_NTOHL (0x696f7200),  // name = ior
    CORBA::tk_struct, // typecode kind
  476, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    39,
    ACE_NTOHL (0x49444c3a), 
    ACE_NTOHL (0x6f6d672e), 
    ACE_NTOHL (0x6f72672f), 
    ACE_NTOHL (0x47494f50), 
    ACE_NTOHL (0x2f494f52), 
    ACE_NTOHL (0x41646472), 
    ACE_NTOHL (0x65737369), 
    ACE_NTOHL (0x6e67496e), 
    ACE_NTOHL (0x666f3a31), 
    ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/GIOP/IORAddressingInfo:1.0
        18,
    ACE_NTOHL (0x494f5241), 
    ACE_NTOHL (0x64647265), 
    ACE_NTOHL (0x7373696e), 
    ACE_NTOHL (0x67496e66), 
    ACE_NTOHL (0x6f000000),  // name = IORAddressingInfo
    2, // member count
        23,
    ACE_NTOHL (0x73656c65), 
    ACE_NTOHL (0x63746564), 
    ACE_NTOHL (0x5f70726f), 
    ACE_NTOHL (0x66696c65), 
    ACE_NTOHL (0x5f696e64), 
    ACE_NTOHL (0x65780000),  // name = selected_profile_index
        CORBA::tk_ulong,

    4,
    ACE_NTOHL (0x696f7200),  // name = ior
        CORBA::tk_struct, // typecode kind
    352, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      24,
      ACE_NTOHL (0x49444c3a), 
      ACE_NTOHL (0x6f6d672e), 
      ACE_NTOHL (0x6f72672f), 
      ACE_NTOHL (0x494f502f), 
      ACE_NTOHL (0x494f523a), 
      ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/IOP/IOR:1.0
            4,
      ACE_NTOHL (0x494f5200),  // name = IOR
      2, // member count
            8,
      ACE_NTOHL (0x74797065), 
      ACE_NTOHL (0x5f696400),  // name = type_id
            CORBA::tk_string, 
      0U, // string length
      9,
      ACE_NTOHL (0x70726f66), 
      ACE_NTOHL (0x696c6573), 
      ACE_NTOHL (0x0),  // name = profiles
            CORBA::tk_sequence, // typecode kind
      264, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        CORBA::tk_struct, // typecode kind
        248, // encapsulation length
          TAO_ENCAP_BYTE_ORDER, // byte order
          34,
          ACE_NTOHL (0x49444c3a), 
          ACE_NTOHL (0x6f6d672e), 
          ACE_NTOHL (0x6f72672f), 
          ACE_NTOHL (0x494f502f), 
          ACE_NTOHL (0x54616767), 
          ACE_NTOHL (0x65645072), 
          ACE_NTOHL (0x6f66696c), 
          ACE_NTOHL (0x653a312e), 
          ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/IOP/TaggedProfile:1.0
                    14,
          ACE_NTOHL (0x54616767), 
          ACE_NTOHL (0x65645072), 
          ACE_NTOHL (0x6f66696c), 
          ACE_NTOHL (0x65000000),  // name = TaggedProfile
          2, // member count
                    4,
          ACE_NTOHL (0x74616700),  // name = tag
                    CORBA::tk_alias, // typecode kind for typedefs
          60, // encapsulation length
            TAO_ENCAP_BYTE_ORDER, // byte order
            30,
            ACE_NTOHL (0x49444c3a), 
            ACE_NTOHL (0x6f6d672e), 
            ACE_NTOHL (0x6f72672f), 
            ACE_NTOHL (0x494f502f), 
            ACE_NTOHL (0x50726f66), 
            ACE_NTOHL (0x696c6549), 
            ACE_NTOHL (0x643a312e), 
            ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/IOP/ProfileId:1.0
                        10,
            ACE_NTOHL (0x50726f66), 
            ACE_NTOHL (0x696c6549), 
            ACE_NTOHL (0x64000000),  // name = ProfileId
                        CORBA::tk_ulong,


          13,
          ACE_NTOHL (0x70726f66), 
          ACE_NTOHL (0x696c655f), 
          ACE_NTOHL (0x64617461), 
          ACE_NTOHL (0x0),  // name = profile_data
                    CORBA::tk_alias, // typecode kind for typedefs
          76, // encapsulation length
            TAO_ENCAP_BYTE_ORDER, // byte order
            31,
            ACE_NTOHL (0x49444c3a), 
            ACE_NTOHL (0x6f6d672e), 
            ACE_NTOHL (0x6f72672f), 
            ACE_NTOHL (0x434f5242), 
            ACE_NTOHL (0x412f4f63), 
            ACE_NTOHL (0x74657453), 
            ACE_NTOHL (0x65713a31), 
            ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/CORBA/OctetSeq:1.0
                        9,
            ACE_NTOHL (0x4f637465), 
            ACE_NTOHL (0x74536571), 
            ACE_NTOHL (0x0),  // name = OctetSeq
                        CORBA::tk_sequence, // typecode kind
            12, // encapsulation length
              TAO_ENCAP_BYTE_ORDER, // byte order
              CORBA::tk_octet,

              0U,



        0U,



};

static CORBA::TypeCode _tc_TAO_tc_GIOP_TargetAddress (
    CORBA::tk_union,
    sizeof (_oc_GIOP_TargetAddress),
    (char *) &_oc_GIOP_TargetAddress,
    0,
    sizeof (GIOP::TargetAddress)
  );

namespace GIOP
{
  ::CORBA::TypeCode_ptr _tc_TargetAddress =
    &_tc_TAO_tc_GIOP_TargetAddress;
}

// TAO_IDL - Generated from
// be/be_visitor_root/root.cpp:1725

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO_Fixed_Var_T<
        GIOP::Version
      >;

  template class
    TAO_Var_Base_T<
        GIOP::Version
      >;

  template class
    TAO_Var_Var_T<
        GIOP::IORAddressingInfo
      >;

  template class
    TAO_Var_Base_T<
        GIOP::IORAddressingInfo
      >;

  template class
    TAO_Out_T<
        GIOP::IORAddressingInfo,
        GIOP::IORAddressingInfo_var
      >;

  template class
    TAO_Var_Var_T<
        GIOP::TargetAddress
      >;

  template class
    TAO_Var_Base_T<
        GIOP::TargetAddress
      >;

  template class
    TAO_Out_T<
        GIOP::TargetAddress,
        GIOP::TargetAddress_var
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO_Fixed_Var_T< \
        GIOP::Version \
      >

# pragma instantiate \
    TAO_Var_Base_T< \
        GIOP::Version \
      >

# pragma instantiate \
    TAO_Var_Var_T< \
        GIOP::IORAddressingInfo \
      >

# pragma instantiate \
    TAO_Var_Base_T< \
        GIOP::IORAddressingInfo \
      >

# pragma instantiate \
    TAO_Out_T< \
        GIOP::IORAddressingInfo, \
        GIOP::IORAddressingInfo_var \
      >

# pragma instantiate \
    TAO_Var_Var_T< \
        GIOP::TargetAddress \
      >

# pragma instantiate \
    TAO_Var_Base_T< \
        GIOP::TargetAddress \
      >

# pragma instantiate \
    TAO_Out_T< \
        GIOP::TargetAddress, \
        GIOP::TargetAddress_var \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

