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
// be\be_codegen.cpp:291


#include "tao/Typecode_typesC.h"
#include "tao/CDR.h"

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:70

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_enum/cdr_op_cs.cpp:51

CORBA::Boolean operator<< (TAO_OutputCDR & strm, CORBA::TCKind _tao_enumerator)
{
  return strm << static_cast<CORBA::ULong> (_tao_enumerator);
}

CORBA::Boolean operator>> (TAO_InputCDR & strm, CORBA::TCKind & _tao_enumerator)
{
  CORBA::ULong _tao_temp = 0;
  CORBA::Boolean const _tao_success = strm >> _tao_temp;

  if (_tao_success)
    {
      _tao_enumerator = static_cast<CORBA::TCKind> (_tao_temp);
    }

  return _tao_success;
}

std::ostream& operator<< (std::ostream &strm, const CORBA::TCKind _tao_enumerator)
{
  switch (_tao_enumerator)
    {
      case 0: return strm << "CORBA::tk_null";
      case 1: return strm << "CORBA::tk_void";
      case 2: return strm << "CORBA::tk_short";
      case 3: return strm << "CORBA::tk_long";
      case 4: return strm << "CORBA::tk_ushort";
      case 5: return strm << "CORBA::tk_ulong";
      case 6: return strm << "CORBA::tk_float";
      case 7: return strm << "CORBA::tk_double";
      case 8: return strm << "CORBA::tk_boolean";
      case 9: return strm << "CORBA::tk_char";
      case 10: return strm << "CORBA::tk_octet";
      case 11: return strm << "CORBA::tk_any";
      case 12: return strm << "CORBA::tk_TypeCode";
      case 13: return strm << "CORBA::tk_Principal";
      case 14: return strm << "CORBA::tk_objref";
      case 15: return strm << "CORBA::tk_struct";
      case 16: return strm << "CORBA::tk_union";
      case 17: return strm << "CORBA::tk_enum";
      case 18: return strm << "CORBA::tk_string";
      case 19: return strm << "CORBA::tk_sequence";
      case 20: return strm << "CORBA::tk_array";
      case 21: return strm << "CORBA::tk_alias";
      case 22: return strm << "CORBA::tk_except";
      case 23: return strm << "CORBA::tk_longlong";
      case 24: return strm << "CORBA::tk_ulonglong";
      case 25: return strm << "CORBA::tk_longdouble";
      case 26: return strm << "CORBA::tk_wchar";
      case 27: return strm << "CORBA::tk_wstring";
      case 28: return strm << "CORBA::tk_fixed";
      case 29: return strm << "CORBA::tk_value";
      case 30: return strm << "CORBA::tk_value_box";
      case 31: return strm << "CORBA::tk_native";
      case 32: return strm << "CORBA::tk_abstract_interface";
      case 33: return strm << "CORBA::tk_local_interface";
      case 34: return strm << "CORBA::tk_component";
      case 35: return strm << "CORBA::tk_home";
      case 36: return strm << "CORBA::tk_event";
      default: return strm;
    }
}

TAO_END_VERSIONED_NAMESPACE_DECL
