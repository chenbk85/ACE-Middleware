// -*- C++ -*-

//=============================================================================
/**
 *  @file   OS_NS_sys_shm.h
 *
 *  $Id$
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 *
 *  Originally in OS.h.
 */
//=============================================================================

#ifndef ACE_OS_NS_SYS_SHM_H
# define ACE_OS_NS_SYS_SHM_H

# include /**/ "ace/pre.h"

# include "ace/config-all.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#  pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/sys/os_shm.h"

namespace ACE_OS {

  //@{ @name A set of wrappers for System V shared memory.
  void *shmat (int int_id,
               void *shmaddr,
               int shmflg);
  int shmctl (int int_id,
              int cmd,
              struct shmid_ds *buf);
  int shmdt (void *shmaddr);
  int shmget (key_t key,
              int size,
              int flags);
  ///@}

} /* namespace ACE_OS */

# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/OS_NS_sys_shm.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */

# include /**/ "ace/post.h"
#endif /* ACE_OS_NS_SYS_SHM_H */
