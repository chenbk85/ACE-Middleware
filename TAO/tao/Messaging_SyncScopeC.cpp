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

#include "Messaging_SyncScopeC.h"

#include "tao/Typecode.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "Messaging_SyncScopeC.i"
#endif /* !defined INLINE */

static const CORBA::Long _oc_Messaging_SyncScope[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  36,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x4d657373),
  ACE_NTOHL (0x6167696e),
  ACE_NTOHL (0x672f5379),
  ACE_NTOHL (0x6e635363),
  ACE_NTOHL (0x6f70653a),
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/Messaging/SyncScope:1.0
  10,
  ACE_NTOHL (0x53796e63),
  ACE_NTOHL (0x53636f70),
  ACE_NTOHL (0x65000000),  // name = SyncScope
  CORBA::tk_short,

};

static CORBA::TypeCode _tc_TAO_tc_Messaging_SyncScope (
    CORBA::tk_alias,
    sizeof (_oc_Messaging_SyncScope),
    (char *) &_oc_Messaging_SyncScope,
    0,
    sizeof (Messaging::SyncScope)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (Messaging)
TAO_NAMESPACE_DEFINE (::CORBA::TypeCode_ptr, _tc_SyncScope, &_tc_TAO_tc_Messaging_SyncScope)
TAO_NAMESPACE_END

TAO_NAMESPACE_TYPE (const CORBA::Short)
TAO_NAMESPACE_BEGIN (Messaging)
TAO_NAMESPACE_DEFINE (const CORBA::Short, SYNC_NONE, 0)
TAO_NAMESPACE_END
TAO_NAMESPACE_TYPE (const CORBA::Short)
TAO_NAMESPACE_BEGIN (Messaging)
TAO_NAMESPACE_DEFINE (const CORBA::Short, SYNC_WITH_TRANSPORT, 1)
TAO_NAMESPACE_END
TAO_NAMESPACE_TYPE (const CORBA::Short)
TAO_NAMESPACE_BEGIN (Messaging)
TAO_NAMESPACE_DEFINE (const CORBA::Short, SYNC_WITH_SERVER, 2)
TAO_NAMESPACE_END
TAO_NAMESPACE_TYPE (const CORBA::Short)
TAO_NAMESPACE_BEGIN (Messaging)
TAO_NAMESPACE_DEFINE (const CORBA::Short, SYNC_WITH_TARGET, 3)
TAO_NAMESPACE_END
