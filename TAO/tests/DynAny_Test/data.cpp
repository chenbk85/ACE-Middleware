// -*- c++ -*-
// $Id$
// ============================================================================
//
// = LIBRARY
//    TAO/tests/DynAny_Test
//
// = FILENAME
//    data.cpp
//
// = DESCRIPTION
//    Implementation file for the class containing test constants.
//
// = AUTHOR
//    Jeff Parsons <jp4@cs.wustl.edu>
//
// ============================================================================

#include "data.h"

Data::Data (CORBA::ORB_var orb)
  : m_bool1 (1),                                m_bool2 (0),
    m_octet1 (8),                               m_octet2 (0),
    m_char1 ('z'),                              m_char2 (0),
    m_short1 (-5),                              m_short2 (0),
    m_long1 (-123456),                          m_long2 (0),
    m_ushort1 (5),                              m_ushort2 (0),
    m_ulong1 (123456),                          m_ulong2 (0),
    m_float1 (0.142857f),                       m_float2 (0.0f),
    m_double1 (3.14159),                        m_double2 (0.0),
    m_longlong1 (-654321),                      m_longlong2 (0),
    m_ulonglong1 (654321),                      m_ulonglong2 (0),
    m_string1 (CORBA::string_dup ("upchuck")),  m_string2 (0),

    m_typecode1 (CORBA::TypeCode::_duplicate (CORBA::_tc_long)),
    m_typecode2 (CORBA::TypeCode::_duplicate (CORBA::_tc_null)),

    m_wchar1 (666),                             m_wchar2 (0),
    m_any1 (CORBA::_tc_long),
    orb_ (orb)
{
  CORBA::Environment env;

  labels[0] = "type boolean";
  labels[1] = "type octet";
  labels[2] = "type char";
  labels[3] = "type short";
  labels[4] = "type long",
  labels[5] = "type ushort";
  labels[6] = "type ulong";
  labels[7] = "type float";
  labels[8] = "type double";
  labels[9] = "type longlong";
  labels[10] = "type ulonglong";
  labels[11] = "type string";
  labels[12] = "type typecode";
  labels[13] = "type wchar";
  labels[14] = "type any";
  labels[15] = "type objref";

  // Getting the RootPOA so we can generate object references.
  CORBA::Object_var obj = this->orb_->resolve_initial_references ("RootPOA");

  // Get the POA_var object from Object_var.
  PortableServer::POA_var root_poa =
    PortableServer::POA::_narrow (obj.in (), 
                                  env);

  if (env.exception () != 0)
    env.print_exception ("PortableServer::POA::_narrow");

  // Generate values for the member variables.
  this->m_objref1 =
    root_poa->create_reference ("foo", 
                                env);

  if (env.exception () != 0)
    env.print_exception ("PortableServer::POA::create_reference_with_id");

  this->m_objref2 =
    root_poa->create_reference ("foo", 
                                env);

  if (env.exception () != 0)
    env.print_exception ("PortableServer::POA::create_reference_with_id"); 
}

Data::~Data (void)
{
  CORBA::string_free (m_string1);
}

