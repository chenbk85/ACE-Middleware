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

#include "ServicesC.h"
#include "tao/Typecode.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:295

static const CORBA::Long _oc_CORBA_ServiceType[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  34,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f5365), 
  ACE_NTOHL (0x72766963), 
  ACE_NTOHL (0x65547970), 
  ACE_NTOHL (0x653a312e), 
  ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/CORBA/ServiceType:1.0
    12,
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x69636554), 
  ACE_NTOHL (0x79706500),  // name = ServiceType
    CORBA::tk_ushort,

};

static CORBA::TypeCode _tc_TAO_tc_CORBA_ServiceType (
    CORBA::tk_alias,
    sizeof (_oc_CORBA_ServiceType),
    (char *) &_oc_CORBA_ServiceType,
    0,
    0
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_ServiceType =
    &_tc_TAO_tc_CORBA_ServiceType;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:295

static const CORBA::Long _oc_CORBA_ServiceOption[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  36,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f5365), 
  ACE_NTOHL (0x72766963), 
  ACE_NTOHL (0x654f7074), 
  ACE_NTOHL (0x696f6e3a), 
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/ServiceOption:1.0
    14,
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x6963654f), 
  ACE_NTOHL (0x7074696f), 
  ACE_NTOHL (0x6e000000),  // name = ServiceOption
    CORBA::tk_ulong,

};

static CORBA::TypeCode _tc_TAO_tc_CORBA_ServiceOption (
    CORBA::tk_alias,
    sizeof (_oc_CORBA_ServiceOption),
    (char *) &_oc_CORBA_ServiceOption,
    0,
    0
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_ServiceOption =
    &_tc_TAO_tc_CORBA_ServiceOption;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:295

static const CORBA::Long _oc_CORBA_ServiceDetailType[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  40,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f5365), 
  ACE_NTOHL (0x72766963), 
  ACE_NTOHL (0x65446574), 
  ACE_NTOHL (0x61696c54), 
  ACE_NTOHL (0x7970653a), 
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/ServiceDetailType:1.0
    18,
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x69636544), 
  ACE_NTOHL (0x65746169), 
  ACE_NTOHL (0x6c547970), 
  ACE_NTOHL (0x65000000),  // name = ServiceDetailType
    CORBA::tk_ulong,

};

static CORBA::TypeCode _tc_TAO_tc_CORBA_ServiceDetailType (
    CORBA::tk_alias,
    sizeof (_oc_CORBA_ServiceDetailType),
    (char *) &_oc_CORBA_ServiceDetailType,
    0,
    0
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_ServiceDetailType =
    &_tc_TAO_tc_CORBA_ServiceDetailType;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:295

static const CORBA::Long _oc_CORBA_ServiceDetail[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  36,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f5365), 
  ACE_NTOHL (0x72766963), 
  ACE_NTOHL (0x65446574), 
  ACE_NTOHL (0x61696c3a), 
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/ServiceDetail:1.0
    14,
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x69636544), 
  ACE_NTOHL (0x65746169), 
  ACE_NTOHL (0x6c000000),  // name = ServiceDetail
  2, // member count
    20,
  ACE_NTOHL (0x73657276), 
  ACE_NTOHL (0x6963655f), 
  ACE_NTOHL (0x64657461), 
  ACE_NTOHL (0x696c5f74), 
  ACE_NTOHL (0x79706500),  // name = service_detail_type
    CORBA::tk_alias, // typecode kind for typedefs
  76, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    40,
    ACE_NTOHL (0x49444c3a), 
    ACE_NTOHL (0x6f6d672e), 
    ACE_NTOHL (0x6f72672f), 
    ACE_NTOHL (0x434f5242), 
    ACE_NTOHL (0x412f5365), 
    ACE_NTOHL (0x72766963), 
    ACE_NTOHL (0x65446574), 
    ACE_NTOHL (0x61696c54), 
    ACE_NTOHL (0x7970653a), 
    ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/ServiceDetailType:1.0
        18,
    ACE_NTOHL (0x53657276), 
    ACE_NTOHL (0x69636544), 
    ACE_NTOHL (0x65746169), 
    ACE_NTOHL (0x6c547970), 
    ACE_NTOHL (0x65000000),  // name = ServiceDetailType
        CORBA::tk_ulong,


  15,
  ACE_NTOHL (0x73657276), 
  ACE_NTOHL (0x6963655f), 
  ACE_NTOHL (0x64657461), 
  ACE_NTOHL (0x696c0000),  // name = service_detail
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


};

static CORBA::TypeCode _tc_TAO_tc_CORBA_ServiceDetail (
    CORBA::tk_struct,
    sizeof (_oc_CORBA_ServiceDetail),
    (char *) &_oc_CORBA_ServiceDetail,
    0,
    0
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_ServiceDetail =
    &_tc_TAO_tc_CORBA_ServiceDetail;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:295

static const CORBA::Long _oc_CORBA_ServiceOptionSeq[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  39,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f5365), 
  ACE_NTOHL (0x72766963), 
  ACE_NTOHL (0x654f7074), 
  ACE_NTOHL (0x696f6e53), 
  ACE_NTOHL (0x65713a31), 
  ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/CORBA/ServiceOptionSeq:1.0
    17,
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x6963654f), 
  ACE_NTOHL (0x7074696f), 
  ACE_NTOHL (0x6e536571), 
  ACE_NTOHL (0x0),  // name = ServiceOptionSeq
    CORBA::tk_sequence, // typecode kind
  84, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_alias, // typecode kind for typedefs
    68, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      36,
      ACE_NTOHL (0x49444c3a), 
      ACE_NTOHL (0x6f6d672e), 
      ACE_NTOHL (0x6f72672f), 
      ACE_NTOHL (0x434f5242), 
      ACE_NTOHL (0x412f5365), 
      ACE_NTOHL (0x72766963), 
      ACE_NTOHL (0x654f7074), 
      ACE_NTOHL (0x696f6e3a), 
      ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/ServiceOption:1.0
            14,
      ACE_NTOHL (0x53657276), 
      ACE_NTOHL (0x6963654f), 
      ACE_NTOHL (0x7074696f), 
      ACE_NTOHL (0x6e000000),  // name = ServiceOption
            CORBA::tk_ulong,


    0U,

};

static CORBA::TypeCode _tc_TAO_tc_CORBA_ServiceOptionSeq (
    CORBA::tk_alias,
    sizeof (_oc_CORBA_ServiceOptionSeq),
    (char *) &_oc_CORBA_ServiceOptionSeq,
    0,
    0
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_ServiceOptionSeq =
    &_tc_TAO_tc_CORBA_ServiceOptionSeq;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:295

static const CORBA::Long _oc_CORBA_ServiceDetailSeq[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  39,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f5365), 
  ACE_NTOHL (0x72766963), 
  ACE_NTOHL (0x65446574), 
  ACE_NTOHL (0x61696c53), 
  ACE_NTOHL (0x65713a31), 
  ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/CORBA/ServiceDetailSeq:1.0
    17,
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x69636544), 
  ACE_NTOHL (0x65746169), 
  ACE_NTOHL (0x6c536571), 
  ACE_NTOHL (0x0),  // name = ServiceDetailSeq
    CORBA::tk_sequence, // typecode kind
  296, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_struct, // typecode kind
    280, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      36,
      ACE_NTOHL (0x49444c3a), 
      ACE_NTOHL (0x6f6d672e), 
      ACE_NTOHL (0x6f72672f), 
      ACE_NTOHL (0x434f5242), 
      ACE_NTOHL (0x412f5365), 
      ACE_NTOHL (0x72766963), 
      ACE_NTOHL (0x65446574), 
      ACE_NTOHL (0x61696c3a), 
      ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/ServiceDetail:1.0
            14,
      ACE_NTOHL (0x53657276), 
      ACE_NTOHL (0x69636544), 
      ACE_NTOHL (0x65746169), 
      ACE_NTOHL (0x6c000000),  // name = ServiceDetail
      2, // member count
            20,
      ACE_NTOHL (0x73657276), 
      ACE_NTOHL (0x6963655f), 
      ACE_NTOHL (0x64657461), 
      ACE_NTOHL (0x696c5f74), 
      ACE_NTOHL (0x79706500),  // name = service_detail_type
            CORBA::tk_alias, // typecode kind for typedefs
      76, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        40,
        ACE_NTOHL (0x49444c3a), 
        ACE_NTOHL (0x6f6d672e), 
        ACE_NTOHL (0x6f72672f), 
        ACE_NTOHL (0x434f5242), 
        ACE_NTOHL (0x412f5365), 
        ACE_NTOHL (0x72766963), 
        ACE_NTOHL (0x65446574), 
        ACE_NTOHL (0x61696c54), 
        ACE_NTOHL (0x7970653a), 
        ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/ServiceDetailType:1.0
                18,
        ACE_NTOHL (0x53657276), 
        ACE_NTOHL (0x69636544), 
        ACE_NTOHL (0x65746169), 
        ACE_NTOHL (0x6c547970), 
        ACE_NTOHL (0x65000000),  // name = ServiceDetailType
                CORBA::tk_ulong,


      15,
      ACE_NTOHL (0x73657276), 
      ACE_NTOHL (0x6963655f), 
      ACE_NTOHL (0x64657461), 
      ACE_NTOHL (0x696c0000),  // name = service_detail
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

static CORBA::TypeCode _tc_TAO_tc_CORBA_ServiceDetailSeq (
    CORBA::tk_alias,
    sizeof (_oc_CORBA_ServiceDetailSeq),
    (char *) &_oc_CORBA_ServiceDetailSeq,
    0,
    0
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_ServiceDetailSeq =
    &_tc_TAO_tc_CORBA_ServiceDetailSeq;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:295

static const CORBA::Long _oc_CORBA_ServiceInformation[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  41,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f5365), 
  ACE_NTOHL (0x72766963), 
  ACE_NTOHL (0x65496e66), 
  ACE_NTOHL (0x6f726d61), 
  ACE_NTOHL (0x74696f6e), 
  ACE_NTOHL (0x3a312e30), 
  ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/CORBA/ServiceInformation:1.0
    19,
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x69636549), 
  ACE_NTOHL (0x6e666f72), 
  ACE_NTOHL (0x6d617469), 
  ACE_NTOHL (0x6f6e0000),  // name = ServiceInformation
  2, // member count
    16,
  ACE_NTOHL (0x73657276), 
  ACE_NTOHL (0x6963655f), 
  ACE_NTOHL (0x6f707469), 
  ACE_NTOHL (0x6f6e7300),  // name = service_options
    CORBA::tk_alias, // typecode kind for typedefs
  164, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    39,
    ACE_NTOHL (0x49444c3a), 
    ACE_NTOHL (0x6f6d672e), 
    ACE_NTOHL (0x6f72672f), 
    ACE_NTOHL (0x434f5242), 
    ACE_NTOHL (0x412f5365), 
    ACE_NTOHL (0x72766963), 
    ACE_NTOHL (0x654f7074), 
    ACE_NTOHL (0x696f6e53), 
    ACE_NTOHL (0x65713a31), 
    ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/CORBA/ServiceOptionSeq:1.0
        17,
    ACE_NTOHL (0x53657276), 
    ACE_NTOHL (0x6963654f), 
    ACE_NTOHL (0x7074696f), 
    ACE_NTOHL (0x6e536571), 
    ACE_NTOHL (0x0),  // name = ServiceOptionSeq
        CORBA::tk_sequence, // typecode kind
    84, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      CORBA::tk_alias, // typecode kind for typedefs
      68, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        36,
        ACE_NTOHL (0x49444c3a), 
        ACE_NTOHL (0x6f6d672e), 
        ACE_NTOHL (0x6f72672f), 
        ACE_NTOHL (0x434f5242), 
        ACE_NTOHL (0x412f5365), 
        ACE_NTOHL (0x72766963), 
        ACE_NTOHL (0x654f7074), 
        ACE_NTOHL (0x696f6e3a), 
        ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/ServiceOption:1.0
                14,
        ACE_NTOHL (0x53657276), 
        ACE_NTOHL (0x6963654f), 
        ACE_NTOHL (0x7074696f), 
        ACE_NTOHL (0x6e000000),  // name = ServiceOption
                CORBA::tk_ulong,


      0U,


  16,
  ACE_NTOHL (0x73657276), 
  ACE_NTOHL (0x6963655f), 
  ACE_NTOHL (0x64657461), 
  ACE_NTOHL (0x696c7300),  // name = service_details
    CORBA::tk_alias, // typecode kind for typedefs
  376, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    39,
    ACE_NTOHL (0x49444c3a), 
    ACE_NTOHL (0x6f6d672e), 
    ACE_NTOHL (0x6f72672f), 
    ACE_NTOHL (0x434f5242), 
    ACE_NTOHL (0x412f5365), 
    ACE_NTOHL (0x72766963), 
    ACE_NTOHL (0x65446574), 
    ACE_NTOHL (0x61696c53), 
    ACE_NTOHL (0x65713a31), 
    ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/CORBA/ServiceDetailSeq:1.0
        17,
    ACE_NTOHL (0x53657276), 
    ACE_NTOHL (0x69636544), 
    ACE_NTOHL (0x65746169), 
    ACE_NTOHL (0x6c536571), 
    ACE_NTOHL (0x0),  // name = ServiceDetailSeq
        CORBA::tk_sequence, // typecode kind
    296, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      CORBA::tk_struct, // typecode kind
      280, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        36,
        ACE_NTOHL (0x49444c3a), 
        ACE_NTOHL (0x6f6d672e), 
        ACE_NTOHL (0x6f72672f), 
        ACE_NTOHL (0x434f5242), 
        ACE_NTOHL (0x412f5365), 
        ACE_NTOHL (0x72766963), 
        ACE_NTOHL (0x65446574), 
        ACE_NTOHL (0x61696c3a), 
        ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/ServiceDetail:1.0
                14,
        ACE_NTOHL (0x53657276), 
        ACE_NTOHL (0x69636544), 
        ACE_NTOHL (0x65746169), 
        ACE_NTOHL (0x6c000000),  // name = ServiceDetail
        2, // member count
                20,
        ACE_NTOHL (0x73657276), 
        ACE_NTOHL (0x6963655f), 
        ACE_NTOHL (0x64657461), 
        ACE_NTOHL (0x696c5f74), 
        ACE_NTOHL (0x79706500),  // name = service_detail_type
                CORBA::tk_alias, // typecode kind for typedefs
        76, // encapsulation length
          TAO_ENCAP_BYTE_ORDER, // byte order
          40,
          ACE_NTOHL (0x49444c3a), 
          ACE_NTOHL (0x6f6d672e), 
          ACE_NTOHL (0x6f72672f), 
          ACE_NTOHL (0x434f5242), 
          ACE_NTOHL (0x412f5365), 
          ACE_NTOHL (0x72766963), 
          ACE_NTOHL (0x65446574), 
          ACE_NTOHL (0x61696c54), 
          ACE_NTOHL (0x7970653a), 
          ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/ServiceDetailType:1.0
                    18,
          ACE_NTOHL (0x53657276), 
          ACE_NTOHL (0x69636544), 
          ACE_NTOHL (0x65746169), 
          ACE_NTOHL (0x6c547970), 
          ACE_NTOHL (0x65000000),  // name = ServiceDetailType
                    CORBA::tk_ulong,


        15,
        ACE_NTOHL (0x73657276), 
        ACE_NTOHL (0x6963655f), 
        ACE_NTOHL (0x64657461), 
        ACE_NTOHL (0x696c0000),  // name = service_detail
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

static CORBA::TypeCode _tc_TAO_tc_CORBA_ServiceInformation (
    CORBA::tk_struct,
    sizeof (_oc_CORBA_ServiceInformation),
    (char *) &_oc_CORBA_ServiceInformation,
    0,
    0
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_ServiceInformation =
    &_tc_TAO_tc_CORBA_ServiceInformation;
}

// TAO_IDL - Generated from 
// be\be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::ServiceDetail &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ServiceDetail>::insert_copy (
      _tao_any,
      CORBA::ServiceDetail::_tao_any_destructor,
      CORBA::_tc_ServiceDetail,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ServiceDetail *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ServiceDetail>::insert (
      _tao_any,
      CORBA::ServiceDetail::_tao_any_destructor,
      CORBA::_tc_ServiceDetail,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::ServiceDetail *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const CORBA::ServiceDetail *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::ServiceDetail *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::ServiceDetail>::extract (
        _tao_any,
        CORBA::ServiceDetail::_tao_any_destructor,
        CORBA::_tc_ServiceDetail,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_sequence/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::ServiceOptionSeq &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ServiceOptionSeq>::insert_copy (
      _tao_any,
      CORBA::ServiceOptionSeq::_tao_any_destructor,
      CORBA::_tc_ServiceOptionSeq,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ServiceOptionSeq *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ServiceOptionSeq>::insert (
      _tao_any,
      CORBA::ServiceOptionSeq::_tao_any_destructor,
      CORBA::_tc_ServiceOptionSeq,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::ServiceOptionSeq *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const CORBA::ServiceOptionSeq *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::ServiceOptionSeq *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::ServiceOptionSeq>::extract (
        _tao_any,
        CORBA::ServiceOptionSeq::_tao_any_destructor,
        CORBA::_tc_ServiceOptionSeq,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_sequence/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::ServiceDetailSeq &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ServiceDetailSeq>::insert_copy (
      _tao_any,
      CORBA::ServiceDetailSeq::_tao_any_destructor,
      CORBA::_tc_ServiceDetailSeq,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ServiceDetailSeq *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ServiceDetailSeq>::insert (
      _tao_any,
      CORBA::ServiceDetailSeq::_tao_any_destructor,
      CORBA::_tc_ServiceDetailSeq,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::ServiceDetailSeq *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const CORBA::ServiceDetailSeq *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::ServiceDetailSeq *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::ServiceDetailSeq>::extract (
        _tao_any,
        CORBA::ServiceDetailSeq::_tao_any_destructor,
        CORBA::_tc_ServiceDetailSeq,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::ServiceInformation &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ServiceInformation>::insert_copy (
      _tao_any,
      CORBA::ServiceInformation::_tao_any_destructor,
      CORBA::_tc_ServiceInformation,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ServiceInformation *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ServiceInformation>::insert (
      _tao_any,
      CORBA::ServiceInformation::_tao_any_destructor,
      CORBA::_tc_ServiceInformation,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::ServiceInformation *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const CORBA::ServiceInformation *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::ServiceInformation *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::ServiceInformation>::extract (
        _tao_any,
        CORBA::ServiceInformation::_tao_any_destructor,
        CORBA::_tc_ServiceInformation,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Dual_Impl_T<
        CORBA::ServiceDetail
      >;

  template class
    TAO::Any_Dual_Impl_T<
        CORBA::ServiceOptionSeq
      >;

  template class
    TAO::Any_Dual_Impl_T<
        CORBA::ServiceDetailSeq
      >;

  template class
    TAO::Any_Dual_Impl_T<
        CORBA::ServiceInformation
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        CORBA::ServiceDetail \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        CORBA::ServiceOptionSeq \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        CORBA::ServiceDetailSeq \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        CORBA::ServiceInformation \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
