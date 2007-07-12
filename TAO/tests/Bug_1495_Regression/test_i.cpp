// -*- C++ -*-
//
// $Id$

/**
 * @file test_i.cpp
 * @author Will Otte <wotte@dre.vanderbilt.edu>
 */

#include "test_i.h"
#include "ace/Thread.h"

Bug1495_i::Bug1495_i (CORBA::ORB_ptr orb)
  : orb_ (CORBA::ORB::_duplicate (orb))
{
}

Bug1495_i::~Bug1495_i (void)
{
}

void
Bug1495_i::get_thread_id (Bug1495_Regression::ThreadId_out thread_id)
{
  thread_id = (Bug1495_Regression::ThreadId_type) ACE_Thread::self ();
}

void
Bug1495_i::shutdown (void)
{
  ACE_DEBUG ((LM_INFO,
              "Shutting down orb %Q\n",
              ACE_Thread::self ()));

  this->_remove_ref ();

  this->orb_->shutdown (false);
}

