
// $Id$

#include "shmem.h"

#if ! defined(ACE_LACKS_SYSV_SHMEM)
/*
  Set the available_ flag to zero & optionally initialize the buf_
  area.
*/
SharedData::SharedData(int _initialize)
    : available_(0)
{
    if( _initialize )
    {
        ACE_OS::sprintf(buf_,"UNSET\n");
    }
}

/*
  Write the process ID into the buffer.  This will prove to us that
  the data really is shared between the client and server.
*/
void SharedData::set(void)
{
    ACE_OS::sprintf(buf_,"My PID is (%d)\n",ACE_OS::getpid());
}

/*
  Display the buffer to the user
*/
void SharedData::show(void)
{
    ACE_DEBUG ((LM_INFO, "(%P|%t) Shared Data text is (%s)\n",
                buf_ ));
}

// Show flag
int SharedData::available(void)
{
    return available_;
}

// Set flag
void SharedData::available(int _available)
{
    available_ = _available;
}
#endif // ACE_LACKS_SYSV_SHMEM
