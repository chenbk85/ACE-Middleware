// -*- C++ -*-
//
// $Id$
#include "Manager_i.h"

Manager_i::Manager_i (long retryCount)
: server_instance_(0)
, retry_count_(retryCount)
, retry_attempt_(0)
{
}

Manager_i::~Manager_i (void)
{
}

CORBA::Long Manager_i::registerServer ()
ACE_THROW_SPEC ((CORBA::SystemException))
{
  if (retry_attempt_ < retry_count_)
  {
    ++retry_attempt_;
    return -1;
  }
  return ++server_instance_;
}

void Manager_i::startRetry (CORBA::Long count)
ACE_THROW_SPEC ((CORBA::SystemException))
{
  retry_count_ = count;
  retry_attempt_ = 0;
}

CORBA::Long Manager_i::endRetry ()
ACE_THROW_SPEC ((CORBA::SystemException))
{
  return retry_count_ - retry_attempt_;
}
