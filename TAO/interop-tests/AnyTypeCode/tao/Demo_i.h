// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.1.4
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// be/be_codegen.cpp:1616

#ifndef DEMOI_I6ARGD_H_
#define DEMOI_I6ARGD_H_

#include "DemoS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class  ATC_Test_i : public virtual POA_Demo::ATC_Test
{
public:
  ATC_Test_i (void);

  virtual ~ATC_Test_i (void);

  virtual char * do_union (const ::CORBA::Any & a);
  virtual char * do_struct (const ::CORBA::Any & a);
  virtual char * do_value (const ::CORBA::Any & a);

  virtual void shutdown (void);

};


#endif /* DEMOI_H_  */
