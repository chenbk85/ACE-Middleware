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


#include "RTScheduler.h"
#include "tao/ORB_Core.h"
#include "tao/Typecode.h"
#include "tao/Var_Size_Argument_T.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "RTSchedulerC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:62

// Arg traits specializations.
namespace TAO
{

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:265

#if !defined (_CORBA_POLICYLIST__ARG_TRAITS_CS_)
#define _CORBA_POLICYLIST__ARG_TRAITS_CS_

  ACE_TEMPLATE_SPECIALIZATION
  class TAO_RTScheduler_Export Arg_Traits<CORBA::PolicyList>
    : public
        Var_Size_Arg_Traits_T<
            CORBA::PolicyList,
            CORBA::PolicyList_var,
            CORBA::PolicyList_out
          >
  {
  };

#endif /* end #if !defined */
}


// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:60

// Traits specializations for RTScheduling::ThreadAction.

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
RTScheduling::ThreadAction_ptr
TAO::Objref_Traits<RTScheduling::ThreadAction>::tao_duplicate (
    RTScheduling::ThreadAction_ptr p
  )
{
  return RTScheduling::ThreadAction::_duplicate (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Objref_Traits<RTScheduling::ThreadAction>::tao_release (
    RTScheduling::ThreadAction_ptr p
  )
{
  CORBA::release (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
RTScheduling::ThreadAction_ptr
TAO::Objref_Traits<RTScheduling::ThreadAction>::tao_nil (void)
{
  return RTScheduling::ThreadAction::_nil ();
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Boolean
TAO::Objref_Traits<RTScheduling::ThreadAction>::tao_marshal (
    RTScheduling::ThreadAction_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return p->marshal (cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker *
(*RTScheduling__TAO_ThreadAction_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

RTScheduling::ThreadAction::ThreadAction (void)
{}

RTScheduling::ThreadAction::~ThreadAction (void)
{}

RTScheduling::ThreadAction_ptr
RTScheduling::ThreadAction::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return ThreadAction::_nil ();
    }

  ThreadAction_ptr proxy =
    dynamic_cast<ThreadAction_ptr> (_tao_objref);

  return ThreadAction::_duplicate (proxy);
}

RTScheduling::ThreadAction_ptr
RTScheduling::ThreadAction::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return ThreadAction::_nil ();
    }

  ThreadAction_ptr proxy =
    dynamic_cast<ThreadAction_ptr> (_tao_objref);

  return ThreadAction::_duplicate (proxy);
}

RTScheduling::ThreadAction_ptr
RTScheduling::ThreadAction::_duplicate (ThreadAction_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

CORBA::Boolean
RTScheduling::ThreadAction::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:RTScheduling/ThreadAction:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
     )
    {
      return 1; // success using local knowledge
    }
  else
    {
      return 0;
    }
}

const char* RTScheduling::ThreadAction::_interface_repository_id (void) const
{
  return "IDL:RTScheduling/ThreadAction:1.0";
}

CORBA::Boolean
RTScheduling::ThreadAction::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_RTScheduling_ThreadAction[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  34,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x52545363),
  ACE_NTOHL (0x68656475),
  ACE_NTOHL (0x6c696e67),
  ACE_NTOHL (0x2f546872),
  ACE_NTOHL (0x65616441),
  ACE_NTOHL (0x6374696f),
  ACE_NTOHL (0x6e3a312e),
  ACE_NTOHL (0x30000000),  // repository ID = IDL:RTScheduling/ThreadAction:1.0
    13,
  ACE_NTOHL (0x54687265),
  ACE_NTOHL (0x61644163),
  ACE_NTOHL (0x74696f6e),
  ACE_NTOHL (0x0),  // name = ThreadAction
  };

static CORBA::TypeCode _tc_TAO_tc_RTScheduling_ThreadAction (
    CORBA::tk_objref,
    sizeof (_oc_RTScheduling_ThreadAction),
    (char *) &_oc_RTScheduling_ThreadAction,
    0,
    sizeof (RTScheduling::ThreadAction)
  );

namespace RTScheduling
{
  ::CORBA::TypeCode_ptr _tc_ThreadAction =
    &_tc_TAO_tc_RTScheduling_ThreadAction;
}

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:60

// Traits specializations for RTScheduling::DistributableThread.

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
RTScheduling::DistributableThread_ptr
TAO::Objref_Traits<RTScheduling::DistributableThread>::tao_duplicate (
    RTScheduling::DistributableThread_ptr p
  )
{
  return RTScheduling::DistributableThread::_duplicate (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Objref_Traits<RTScheduling::DistributableThread>::tao_release (
    RTScheduling::DistributableThread_ptr p
  )
{
  CORBA::release (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
RTScheduling::DistributableThread_ptr
TAO::Objref_Traits<RTScheduling::DistributableThread>::tao_nil (void)
{
  return RTScheduling::DistributableThread::_nil ();
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Boolean
TAO::Objref_Traits<RTScheduling::DistributableThread>::tao_marshal (
    RTScheduling::DistributableThread_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return p->marshal (cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker *
(*RTScheduling__TAO_DistributableThread_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_RTScheduling_DistributableThread_DT_State[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  50,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x52545363),
  ACE_NTOHL (0x68656475),
  ACE_NTOHL (0x6c696e67),
  ACE_NTOHL (0x2f446973),
  ACE_NTOHL (0x74726962),
  ACE_NTOHL (0x75746162),
  ACE_NTOHL (0x6c655468),
  ACE_NTOHL (0x72656164),
  ACE_NTOHL (0x2f44545f),
  ACE_NTOHL (0x53746174),
  ACE_NTOHL (0x653a312e),
  ACE_NTOHL (0x30000000),  // repository ID = IDL:RTScheduling/DistributableThread/DT_State:1.0
  9,
  ACE_NTOHL (0x44545f53),
  ACE_NTOHL (0x74617465),
  ACE_NTOHL (0x0),  // name = DT_State
  2, // member count
  7,
  ACE_NTOHL (0x41435449),
  ACE_NTOHL (0x56450000),  // name = ACTIVE
  10,
  ACE_NTOHL (0x43414e43),
  ACE_NTOHL (0x454c4c45),
  ACE_NTOHL (0x44000000),  // name = CANCELLED
  };

static CORBA::TypeCode _tc_TAO_tc_RTScheduling_DistributableThread_DT_State (
    CORBA::tk_enum,
    sizeof (_oc_RTScheduling_DistributableThread_DT_State),
    (char *) &_oc_RTScheduling_DistributableThread_DT_State,
    0,
    sizeof (RTScheduling::DistributableThread::DT_State)
  );

::CORBA::TypeCode_ptr RTScheduling::DistributableThread::_tc_DT_State =
  &_tc_TAO_tc_RTScheduling_DistributableThread_DT_State;

RTScheduling::DistributableThread::DistributableThread (void)
{}

RTScheduling::DistributableThread::~DistributableThread (void)
{}

RTScheduling::DistributableThread_ptr
RTScheduling::DistributableThread::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return DistributableThread::_nil ();
    }

  DistributableThread_ptr proxy =
    dynamic_cast<DistributableThread_ptr> (_tao_objref);

  return DistributableThread::_duplicate (proxy);
}

RTScheduling::DistributableThread_ptr
RTScheduling::DistributableThread::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return DistributableThread::_nil ();
    }

  DistributableThread_ptr proxy =
    dynamic_cast<DistributableThread_ptr> (_tao_objref);

  return DistributableThread::_duplicate (proxy);
}

RTScheduling::DistributableThread_ptr
RTScheduling::DistributableThread::_duplicate (DistributableThread_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

CORBA::Boolean
RTScheduling::DistributableThread::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:RTScheduling/DistributableThread:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
     )
    {
      return 1; // success using local knowledge
    }
  else
    {
      return 0;
    }
}

const char* RTScheduling::DistributableThread::_interface_repository_id (void) const
{
  return "IDL:RTScheduling/DistributableThread:1.0";
}

CORBA::Boolean
RTScheduling::DistributableThread::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_RTScheduling_DistributableThread[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  41,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x52545363),
  ACE_NTOHL (0x68656475),
  ACE_NTOHL (0x6c696e67),
  ACE_NTOHL (0x2f446973),
  ACE_NTOHL (0x74726962),
  ACE_NTOHL (0x75746162),
  ACE_NTOHL (0x6c655468),
  ACE_NTOHL (0x72656164),
  ACE_NTOHL (0x3a312e30),
  ACE_NTOHL (0x0),  // repository ID = IDL:RTScheduling/DistributableThread:1.0
    20,
  ACE_NTOHL (0x44697374),
  ACE_NTOHL (0x72696275),
  ACE_NTOHL (0x7461626c),
  ACE_NTOHL (0x65546872),
  ACE_NTOHL (0x65616400),  // name = DistributableThread
  };

static CORBA::TypeCode _tc_TAO_tc_RTScheduling_DistributableThread (
    CORBA::tk_objref,
    sizeof (_oc_RTScheduling_DistributableThread),
    (char *) &_oc_RTScheduling_DistributableThread,
    0,
    sizeof (RTScheduling::DistributableThread)
  );

namespace RTScheduling
{
  ::CORBA::TypeCode_ptr _tc_DistributableThread =
    &_tc_TAO_tc_RTScheduling_DistributableThread;
}

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:60

// Traits specializations for RTScheduling::Current.

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
RTScheduling::Current_ptr
TAO::Objref_Traits<RTScheduling::Current>::tao_duplicate (
    RTScheduling::Current_ptr p
  )
{
  return RTScheduling::Current::_duplicate (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Objref_Traits<RTScheduling::Current>::tao_release (
    RTScheduling::Current_ptr p
  )
{
  CORBA::release (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
RTScheduling::Current_ptr
TAO::Objref_Traits<RTScheduling::Current>::tao_nil (void)
{
  return RTScheduling::Current::_nil ();
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Boolean
TAO::Objref_Traits<RTScheduling::Current>::tao_marshal (
    RTScheduling::Current_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return p->marshal (cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker *
(*RTScheduling__TAO_Current_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

// TAO_IDL - Generated from
// be/be_visitor_exception/exception_cs.cpp:63

RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE::UNSUPPORTED_SCHEDULING_DISCIPLINE (void)
  : CORBA::UserException (
        "IDL:RTScheduling/Current/UNSUPPORTED_SCHEDULING_DISCIPLINE:1.0",
        "UNSUPPORTED_SCHEDULING_DISCIPLINE"
      )
{
}

RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE::~UNSUPPORTED_SCHEDULING_DISCIPLINE (void)
{
}

RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE::UNSUPPORTED_SCHEDULING_DISCIPLINE (const ::RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE&
RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE::operator= (const ::RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE *
RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE::_downcast (CORBA::Exception *_tao_excp)
{
  if (!ACE_OS::strcmp ("IDL:RTScheduling/Current/UNSUPPORTED_SCHEDULING_DISCIPLINE:1.0", _tao_excp->_rep_id ()))
    {
      return ACE_dynamic_cast (UNSUPPORTED_SCHEDULING_DISCIPLINE *, _tao_excp);
    }
  else
    {
      return 0;
    }
}

CORBA::Exception *RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE, 0);
  return retval;
}

CORBA::Exception *
RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE::_tao_duplicate (void) const
{
  CORBA::Exception *result;
  ACE_NEW_RETURN (
      result,
      ::RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE (*this),
      0
    );
  return result;
}

void RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE::_raise (void) const
{
  TAO_RAISE (*this);
}

void RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW (CORBA::MARSHAL ());
}

void RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
CORBA::TypeCode_ptr RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE::_type (void) const
{
  return ::RTScheduling::Current::_tc_UNSUPPORTED_SCHEDULING_DISCIPLINE;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_RTScheduling_Current_UNSUPPORTED_SCHEDULING_DISCIPLINE[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  63,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x52545363),
  ACE_NTOHL (0x68656475),
  ACE_NTOHL (0x6c696e67),
  ACE_NTOHL (0x2f437572),
  ACE_NTOHL (0x72656e74),
  ACE_NTOHL (0x2f554e53),
  ACE_NTOHL (0x5550504f),
  ACE_NTOHL (0x52544544),
  ACE_NTOHL (0x5f534348),
  ACE_NTOHL (0x4544554c),
  ACE_NTOHL (0x494e475f),
  ACE_NTOHL (0x44495343),
  ACE_NTOHL (0x49504c49),
  ACE_NTOHL (0x4e453a31),
  ACE_NTOHL (0x2e300000),  // repository ID = IDL:RTScheduling/Current/UNSUPPORTED_SCHEDULING_DISCIPLINE:1.0
    34,
  ACE_NTOHL (0x554e5355),
  ACE_NTOHL (0x50504f52),
  ACE_NTOHL (0x5445445f),
  ACE_NTOHL (0x53434845),
  ACE_NTOHL (0x44554c49),
  ACE_NTOHL (0x4e475f44),
  ACE_NTOHL (0x49534349),
  ACE_NTOHL (0x504c494e),
  ACE_NTOHL (0x45000000),  // name = UNSUPPORTED_SCHEDULING_DISCIPLINE
  0, // member count
  };

static CORBA::TypeCode _tc_TAO_tc_RTScheduling_Current_UNSUPPORTED_SCHEDULING_DISCIPLINE (
    CORBA::tk_except,
    sizeof (_oc_RTScheduling_Current_UNSUPPORTED_SCHEDULING_DISCIPLINE),
    (char *) &_oc_RTScheduling_Current_UNSUPPORTED_SCHEDULING_DISCIPLINE,
    0,
    sizeof (RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE)
  );

::CORBA::TypeCode_ptr RTScheduling::Current::_tc_UNSUPPORTED_SCHEDULING_DISCIPLINE =
  &_tc_TAO_tc_RTScheduling_Current_UNSUPPORTED_SCHEDULING_DISCIPLINE;

// TAO_IDL - Generated from
// be/be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_RTSCHEDULING_CURRENT_IDTYPE_CS_)
#define _RTSCHEDULING_CURRENT_IDTYPE_CS_

RTScheduling::Current::IdType::IdType (void)
{}

RTScheduling::Current::IdType::IdType (
    CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        CORBA::Octet
      >
    (max)
{}

RTScheduling::Current::IdType::IdType (
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

RTScheduling::Current::IdType::IdType (
    const IdType &seq
  )
  : TAO_Unbounded_Sequence<
        CORBA::Octet
      >
    (seq)
{}

RTScheduling::Current::IdType::~IdType (void)
{}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_RTScheduling_Current_IdType[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  36,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x52545363),
  ACE_NTOHL (0x68656475),
  ACE_NTOHL (0x6c696e67),
  ACE_NTOHL (0x2f437572),
  ACE_NTOHL (0x72656e74),
  ACE_NTOHL (0x2f496454),
  ACE_NTOHL (0x7970653a),
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:RTScheduling/Current/IdType:1.0
    7,
  ACE_NTOHL (0x49645479),
  ACE_NTOHL (0x70650000),  // name = IdType
    CORBA::tk_sequence, // typecode kind
  12, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_octet,

    0U,

};

static CORBA::TypeCode _tc_TAO_tc_RTScheduling_Current_IdType (
    CORBA::tk_alias,
    sizeof (_oc_RTScheduling_Current_IdType),
    (char *) &_oc_RTScheduling_Current_IdType,
    0,
    sizeof (RTScheduling::Current::IdType)
  );

::CORBA::TypeCode_ptr RTScheduling::Current::_tc_IdType =
  &_tc_TAO_tc_RTScheduling_Current_IdType;

// TAO_IDL - Generated from
// be/be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_RTSCHEDULING_CURRENT_NAMELIST_CS_)
#define _RTSCHEDULING_CURRENT_NAMELIST_CS_

RTScheduling::Current::NameList::NameList (void)
{}

RTScheduling::Current::NameList::NameList (
    CORBA::ULong max
  )
  : TAO_Unbounded_String_Sequence
    (max)
{}

RTScheduling::Current::NameList::NameList (
    CORBA::ULong max,
    CORBA::ULong length,
    char * * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_String_Sequence
    (max, length, buffer, release)
{}

RTScheduling::Current::NameList::NameList (
    const NameList &seq
  )
  : TAO_Unbounded_String_Sequence
    (seq)
{}

RTScheduling::Current::NameList::~NameList (void)
{}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_RTScheduling_Current_NameList[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  38,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x52545363),
  ACE_NTOHL (0x68656475),
  ACE_NTOHL (0x6c696e67),
  ACE_NTOHL (0x2f437572),
  ACE_NTOHL (0x72656e74),
  ACE_NTOHL (0x2f4e616d),
  ACE_NTOHL (0x654c6973),
  ACE_NTOHL (0x743a312e),
  ACE_NTOHL (0x30000000),  // repository ID = IDL:RTScheduling/Current/NameList:1.0
    9,
  ACE_NTOHL (0x4e616d65),
  ACE_NTOHL (0x4c697374),
  ACE_NTOHL (0x0),  // name = NameList
    CORBA::tk_sequence, // typecode kind
  16, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_string,
    0U, // string length
    0U,

};

static CORBA::TypeCode _tc_TAO_tc_RTScheduling_Current_NameList (
    CORBA::tk_alias,
    sizeof (_oc_RTScheduling_Current_NameList),
    (char *) &_oc_RTScheduling_Current_NameList,
    0,
    sizeof (RTScheduling::Current::NameList)
  );

::CORBA::TypeCode_ptr RTScheduling::Current::_tc_NameList =
  &_tc_TAO_tc_RTScheduling_Current_NameList;

RTScheduling::Current::Current (void)
{}

RTScheduling::Current::~Current (void)
{}

RTScheduling::Current_ptr
RTScheduling::Current::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return Current::_nil ();
    }

  Current_ptr proxy =
    dynamic_cast<Current_ptr> (_tao_objref);

  return Current::_duplicate (proxy);
}

RTScheduling::Current_ptr
RTScheduling::Current::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return Current::_nil ();
    }

  Current_ptr proxy =
    dynamic_cast<Current_ptr> (_tao_objref);

  return Current::_duplicate (proxy);
}

RTScheduling::Current_ptr
RTScheduling::Current::_duplicate (Current_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

CORBA::Boolean
RTScheduling::Current::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Current:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/RTCORBA/Current:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:RTScheduling/Current:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
     )
    {
      return 1; // success using local knowledge
    }
  else
    {
      return 0;
    }
}

const char* RTScheduling::Current::_interface_repository_id (void) const
{
  return "IDL:RTScheduling/Current:1.0";
}

CORBA::Boolean
RTScheduling::Current::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_RTScheduling_Current[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  29,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x52545363),
  ACE_NTOHL (0x68656475),
  ACE_NTOHL (0x6c696e67),
  ACE_NTOHL (0x2f437572),
  ACE_NTOHL (0x72656e74),
  ACE_NTOHL (0x3a312e30),
  ACE_NTOHL (0x0),  // repository ID = IDL:RTScheduling/Current:1.0
    8,
  ACE_NTOHL (0x43757272),
  ACE_NTOHL (0x656e7400),  // name = Current
  };

static CORBA::TypeCode _tc_TAO_tc_RTScheduling_Current (
    CORBA::tk_objref,
    sizeof (_oc_RTScheduling_Current),
    (char *) &_oc_RTScheduling_Current,
    0,
    sizeof (RTScheduling::Current)
  );

namespace RTScheduling
{
  ::CORBA::TypeCode_ptr _tc_Current =
    &_tc_TAO_tc_RTScheduling_Current;
}

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:60

// Traits specializations for RTScheduling::ResourceManager.

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
RTScheduling::ResourceManager_ptr
TAO::Objref_Traits<RTScheduling::ResourceManager>::tao_duplicate (
    RTScheduling::ResourceManager_ptr p
  )
{
  return RTScheduling::ResourceManager::_duplicate (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Objref_Traits<RTScheduling::ResourceManager>::tao_release (
    RTScheduling::ResourceManager_ptr p
  )
{
  CORBA::release (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
RTScheduling::ResourceManager_ptr
TAO::Objref_Traits<RTScheduling::ResourceManager>::tao_nil (void)
{
  return RTScheduling::ResourceManager::_nil ();
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Boolean
TAO::Objref_Traits<RTScheduling::ResourceManager>::tao_marshal (
    RTScheduling::ResourceManager_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return p->marshal (cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker *
(*RTScheduling__TAO_ResourceManager_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

RTScheduling::ResourceManager::ResourceManager (void)
{}

RTScheduling::ResourceManager::~ResourceManager (void)
{}

RTScheduling::ResourceManager_ptr
RTScheduling::ResourceManager::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return ResourceManager::_nil ();
    }

  ResourceManager_ptr proxy =
    dynamic_cast<ResourceManager_ptr> (_tao_objref);

  return ResourceManager::_duplicate (proxy);
}

RTScheduling::ResourceManager_ptr
RTScheduling::ResourceManager::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return ResourceManager::_nil ();
    }

  ResourceManager_ptr proxy =
    dynamic_cast<ResourceManager_ptr> (_tao_objref);

  return ResourceManager::_duplicate (proxy);
}

RTScheduling::ResourceManager_ptr
RTScheduling::ResourceManager::_duplicate (ResourceManager_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

CORBA::Boolean
RTScheduling::ResourceManager::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/RTCORBA/Mutex:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:RTScheduling/ResourceManager:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
     )
    {
      return 1; // success using local knowledge
    }
  else
    {
      return 0;
    }
}

const char* RTScheduling::ResourceManager::_interface_repository_id (void) const
{
  return "IDL:RTScheduling/ResourceManager:1.0";
}

CORBA::Boolean
RTScheduling::ResourceManager::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_RTScheduling_ResourceManager[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  37,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x52545363),
  ACE_NTOHL (0x68656475),
  ACE_NTOHL (0x6c696e67),
  ACE_NTOHL (0x2f526573),
  ACE_NTOHL (0x6f757263),
  ACE_NTOHL (0x654d616e),
  ACE_NTOHL (0x61676572),
  ACE_NTOHL (0x3a312e30),
  ACE_NTOHL (0x0),  // repository ID = IDL:RTScheduling/ResourceManager:1.0
    16,
  ACE_NTOHL (0x5265736f),
  ACE_NTOHL (0x75726365),
  ACE_NTOHL (0x4d616e61),
  ACE_NTOHL (0x67657200),  // name = ResourceManager
  };

static CORBA::TypeCode _tc_TAO_tc_RTScheduling_ResourceManager (
    CORBA::tk_objref,
    sizeof (_oc_RTScheduling_ResourceManager),
    (char *) &_oc_RTScheduling_ResourceManager,
    0,
    sizeof (RTScheduling::ResourceManager)
  );

namespace RTScheduling
{
  ::CORBA::TypeCode_ptr _tc_ResourceManager =
    &_tc_TAO_tc_RTScheduling_ResourceManager;
}

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:60

// Traits specializations for RTScheduling::Scheduler.

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
RTScheduling::Scheduler_ptr
TAO::Objref_Traits<RTScheduling::Scheduler>::tao_duplicate (
    RTScheduling::Scheduler_ptr p
  )
{
  return RTScheduling::Scheduler::_duplicate (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Objref_Traits<RTScheduling::Scheduler>::tao_release (
    RTScheduling::Scheduler_ptr p
  )
{
  CORBA::release (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
RTScheduling::Scheduler_ptr
TAO::Objref_Traits<RTScheduling::Scheduler>::tao_nil (void)
{
  return RTScheduling::Scheduler::_nil ();
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Boolean
TAO::Objref_Traits<RTScheduling::Scheduler>::tao_marshal (
    RTScheduling::Scheduler_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return p->marshal (cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker *
(*RTScheduling__TAO_Scheduler_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

// TAO_IDL - Generated from
// be/be_visitor_exception/exception_cs.cpp:63

RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES::INCOMPATIBLE_SCHEDULING_DISCIPLINES (void)
  : CORBA::UserException (
        "IDL:RTScheduling/Scheduler/INCOMPATIBLE_SCHEDULING_DISCIPLINES:1.0",
        "INCOMPATIBLE_SCHEDULING_DISCIPLINES"
      )
{
}

RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES::~INCOMPATIBLE_SCHEDULING_DISCIPLINES (void)
{
}

RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES::INCOMPATIBLE_SCHEDULING_DISCIPLINES (const ::RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES&
RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES::operator= (const ::RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES *
RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES::_downcast (CORBA::Exception *_tao_excp)
{
  if (!ACE_OS::strcmp ("IDL:RTScheduling/Scheduler/INCOMPATIBLE_SCHEDULING_DISCIPLINES:1.0", _tao_excp->_rep_id ()))
    {
      return ACE_dynamic_cast (INCOMPATIBLE_SCHEDULING_DISCIPLINES *, _tao_excp);
    }
  else
    {
      return 0;
    }
}

CORBA::Exception *RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES, 0);
  return retval;
}

CORBA::Exception *
RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES::_tao_duplicate (void) const
{
  CORBA::Exception *result;
  ACE_NEW_RETURN (
      result,
      ::RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES (*this),
      0
    );
  return result;
}

void RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES::_raise (void) const
{
  TAO_RAISE (*this);
}

void RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW (CORBA::MARSHAL ());
}

void RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
CORBA::TypeCode_ptr RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES::_type (void) const
{
  return ::RTScheduling::Scheduler::_tc_INCOMPATIBLE_SCHEDULING_DISCIPLINES;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_RTScheduling_Scheduler_INCOMPATIBLE_SCHEDULING_DISCIPLINES[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  67,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x52545363),
  ACE_NTOHL (0x68656475),
  ACE_NTOHL (0x6c696e67),
  ACE_NTOHL (0x2f536368),
  ACE_NTOHL (0x6564756c),
  ACE_NTOHL (0x65722f49),
  ACE_NTOHL (0x4e434f4d),
  ACE_NTOHL (0x50415449),
  ACE_NTOHL (0x424c455f),
  ACE_NTOHL (0x53434845),
  ACE_NTOHL (0x44554c49),
  ACE_NTOHL (0x4e475f44),
  ACE_NTOHL (0x49534349),
  ACE_NTOHL (0x504c494e),
  ACE_NTOHL (0x45533a31),
  ACE_NTOHL (0x2e300000),  // repository ID = IDL:RTScheduling/Scheduler/INCOMPATIBLE_SCHEDULING_DISCIPLINES:1.0
    36,
  ACE_NTOHL (0x494e434f),
  ACE_NTOHL (0x4d504154),
  ACE_NTOHL (0x49424c45),
  ACE_NTOHL (0x5f534348),
  ACE_NTOHL (0x4544554c),
  ACE_NTOHL (0x494e475f),
  ACE_NTOHL (0x44495343),
  ACE_NTOHL (0x49504c49),
  ACE_NTOHL (0x4e455300),  // name = INCOMPATIBLE_SCHEDULING_DISCIPLINES
  0, // member count
  };

static CORBA::TypeCode _tc_TAO_tc_RTScheduling_Scheduler_INCOMPATIBLE_SCHEDULING_DISCIPLINES (
    CORBA::tk_except,
    sizeof (_oc_RTScheduling_Scheduler_INCOMPATIBLE_SCHEDULING_DISCIPLINES),
    (char *) &_oc_RTScheduling_Scheduler_INCOMPATIBLE_SCHEDULING_DISCIPLINES,
    0,
    sizeof (RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES)
  );

::CORBA::TypeCode_ptr RTScheduling::Scheduler::_tc_INCOMPATIBLE_SCHEDULING_DISCIPLINES =
  &_tc_TAO_tc_RTScheduling_Scheduler_INCOMPATIBLE_SCHEDULING_DISCIPLINES;

RTScheduling::Scheduler::Scheduler (void)
{}

RTScheduling::Scheduler::~Scheduler (void)
{}

RTScheduling::Scheduler_ptr
RTScheduling::Scheduler::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return Scheduler::_nil ();
    }

  Scheduler_ptr proxy =
    dynamic_cast<Scheduler_ptr> (_tao_objref);

  return Scheduler::_duplicate (proxy);
}

RTScheduling::Scheduler_ptr
RTScheduling::Scheduler::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return Scheduler::_nil ();
    }

  Scheduler_ptr proxy =
    dynamic_cast<Scheduler_ptr> (_tao_objref);

  return Scheduler::_duplicate (proxy);
}

RTScheduling::Scheduler_ptr
RTScheduling::Scheduler::_duplicate (Scheduler_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

CORBA::Boolean
RTScheduling::Scheduler::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:RTScheduling/Scheduler:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
     )
    {
      return 1; // success using local knowledge
    }
  else
    {
      return 0;
    }
}

const char* RTScheduling::Scheduler::_interface_repository_id (void) const
{
  return "IDL:RTScheduling/Scheduler:1.0";
}

CORBA::Boolean
RTScheduling::Scheduler::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_RTScheduling_Scheduler[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  31,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x52545363),
  ACE_NTOHL (0x68656475),
  ACE_NTOHL (0x6c696e67),
  ACE_NTOHL (0x2f536368),
  ACE_NTOHL (0x6564756c),
  ACE_NTOHL (0x65723a31),
  ACE_NTOHL (0x2e300000),  // repository ID = IDL:RTScheduling/Scheduler:1.0
    10,
  ACE_NTOHL (0x53636865),
  ACE_NTOHL (0x64756c65),
  ACE_NTOHL (0x72000000),  // name = Scheduler
  };

static CORBA::TypeCode _tc_TAO_tc_RTScheduling_Scheduler (
    CORBA::tk_objref,
    sizeof (_oc_RTScheduling_Scheduler),
    (char *) &_oc_RTScheduling_Scheduler,
    0,
    sizeof (RTScheduling::Scheduler)
  );

namespace RTScheduling
{
  ::CORBA::TypeCode_ptr _tc_Scheduler =
    &_tc_TAO_tc_RTScheduling_Scheduler;
}

// TAO_IDL - Generated from
// be/be_visitor_root/root.cpp:1725

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

#if !defined (_CORBA_SEQUENCE__ARG_TRAITS_TMPLINST_CS_)
#define _CORBA_SEQUENCE__ARG_TRAITS_TMPLINST_CS_

  template class TAO::Arg_Traits<CORBA::PolicyList>;

  template class
    TAO::Var_Size_Arg_Traits_T<
        CORBA::PolicyList,
        CORBA::PolicyList_var,
        CORBA::PolicyList_out
      >;

#endif /* end #if !defined */

  template class
    TAO::Objref_Traits<
        RTScheduling::ThreadAction
      >;

  template class
    TAO_Objref_Var_T<
        RTScheduling::ThreadAction
      >;

  template class
    TAO_Objref_Out_T<
        RTScheduling::ThreadAction
      >;

  template class
    TAO::Objref_Traits<
        RTScheduling::DistributableThread
      >;

  template class
    TAO_Objref_Var_T<
        RTScheduling::DistributableThread
      >;

  template class
    TAO_Objref_Out_T<
        RTScheduling::DistributableThread
      >;

  template class
    TAO_FixedSeq_Var_T<
        RTScheduling::Current::IdType,
        CORBA::Octet
      >;

  template class
    TAO_Seq_Var_Base_T<
        RTScheduling::Current::IdType,
        CORBA::Octet
      >;

  template class
    TAO_Seq_Out_T<
        RTScheduling::Current::IdType,
        RTScheduling::Current::IdType_var,
        CORBA::Octet
      >;

  template class
    TAO_MngSeq_Var_T<
        RTScheduling::Current::NameList,
        TAO_SeqElem_String_Manager
      >;

  template class
    TAO_Seq_Var_Base_T<
        RTScheduling::Current::NameList,
        TAO_SeqElem_String_Manager
      >;

  template class
    TAO_MngSeq_Out_T<
        RTScheduling::Current::NameList,
        RTScheduling::Current::NameList_var,
        TAO_SeqElem_String_Manager
      >;

  template class
    TAO::Objref_Traits<
        RTScheduling::Current
      >;

  template class
    TAO_Objref_Var_T<
        RTScheduling::Current
      >;

  template class
    TAO_Objref_Out_T<
        RTScheduling::Current
      >;

  template class
    TAO::Objref_Traits<
        RTScheduling::ResourceManager
      >;

  template class
    TAO_Objref_Var_T<
        RTScheduling::ResourceManager
      >;

  template class
    TAO_Objref_Out_T<
        RTScheduling::ResourceManager
      >;

  template class
    TAO::Objref_Traits<
        RTScheduling::Scheduler
      >;

  template class
    TAO_Objref_Var_T<
        RTScheduling::Scheduler
      >;

  template class
    TAO_Objref_Out_T<
        RTScheduling::Scheduler
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#if !defined (_CORBA_SEQUENCE__ARG_TRAITS_TMPLINST_CS_)
#define _CORBA_SEQUENCE__ARG_TRAITS_TMPLINST_CS_

# pragma instantiate TAO::Arg_Traits<CORBA::PolicyList>

# pragma instantiate \
    TAO::Var_Size_Arg_Traits_T< \
        CORBA::PolicyList, \
        CORBA::PolicyList_var, \
        CORBA::PolicyList_out \
      >

#endif /* end #if !defined */

# pragma instantiate \
    TAO::Objref_Traits< \
        RTScheduling::ThreadAction \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        RTScheduling::ThreadAction
      >

# pragma instantiate \
    TAO_Objref_Out_T< \
        RTScheduling::ThreadAction
      >

# pragma instantiate \
    TAO::Objref_Traits< \
        RTScheduling::DistributableThread \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        RTScheduling::DistributableThread
      >

# pragma instantiate \
    TAO_Objref_Out_T< \
        RTScheduling::DistributableThread
      >

# pragma instantiate \
    TAO_FixedSeq_Var_T< \
        RTScheduling::Current::IdType, \
        CORBA::Octet \
      >

# pragma instantiate \
    TAO_Seq_Var_Base_T< \
        RTScheduling::Current::IdType, \
        CORBA::Octet \
      >

# pragma instantiate \
    TAO_Seq_Out_T< \
        RTScheduling::Current::IdType, \
        RTScheduling::Current::IdType_var, \
        CORBA::Octet \
      >

# pragma instantiate \
    TAO_MngSeq_Var_T< \
        RTScheduling::Current::NameList, \
        TAO_SeqElem_String_Manager \
      >

# pragma instantiate \
    TAO_Seq_Var_Base_T< \
        RTScheduling::Current::NameList, \
        TAO_SeqElem_String_Manager \
      >

# pragma instantiate \
    TAO_MngSeq_Out_T< \
        RTScheduling::Current::NameList, \
        RTScheduling::Current::NameList_var, \
        TAO_SeqElem_String_Manager \
      >

# pragma instantiate \
    TAO::Objref_Traits< \
        RTScheduling::Current \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        RTScheduling::Current
      >

# pragma instantiate \
    TAO_Objref_Out_T< \
        RTScheduling::Current
      >

# pragma instantiate \
    TAO::Objref_Traits< \
        RTScheduling::ResourceManager \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        RTScheduling::ResourceManager
      >

# pragma instantiate \
    TAO_Objref_Out_T< \
        RTScheduling::ResourceManager
      >

# pragma instantiate \
    TAO::Objref_Traits< \
        RTScheduling::Scheduler \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        RTScheduling::Scheduler
      >

# pragma instantiate \
    TAO_Objref_Out_T< \
        RTScheduling::Scheduler
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
