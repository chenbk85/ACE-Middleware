/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/orbsvcs/Concurrency_Service
//
// = FILENAME
//    CC_Lock.h
//
// = DESCRIPTION
//      This class implements a lock used by the lock set from the
//      concurrency control service
//
// = AUTHORS
//    Torben Worm <tworm@cs.wustl.edu>
//
// ============================================================================

#if !defined (_CC_LOCK_H)
#define _CC_LOCK_H

#include "ace/Synch.h"
#include "orbsvcs/CosConcurrencyControlC.h"

class TAO_ORBSVCS_Export CC_Lock 
{
  // = TITLE
  //     CC_Lock
  //
  // = DESCRIPTION
  //     This class implements the lock concept from the concurrency
  //     control service. The lock holds its mode - this might later
  //     be changed to subclasses depending on the differences of the
  //     locks.  At present the is only a lock-pr-thread/client-type
  //     which is essentially a write lock since it is not allowed to
  //     have more than one lock pr. servant in this implementation.
public:
  CC_Lock (CosConcurrencyControl::lock_mode mode);
  // Creates the lock with the desired mode

  ~CC_Lock (void);
  // Deletes the lock

  void lock (CORBA::Environment &env);
  // Acquires this lock. Blocks until lock is obtained

  CORBA::Boolean try_lock (CORBA::Environment &env);
  // Tries to acquire this lock. If it is not possible to acquire the
  // lock, false is returned

  void unlock (CORBA::Environment &env);
  // Releases this lock.

  void change_mode (CosConcurrencyControl::lock_mode new_mode,
                   CORBA::Environment &env);
  // Changes the mode of this lock.
  
  CORBA::Boolean Compatible (const CC_Lock &other);
  // returns true if this lock is compatible with the other lock.

  CORBA::Boolean Compatible (CosConcurrencyControl::lock_mode mode);
  // Returns true is this lock is compatible with the referenced mode.

  CosConcurrencyControl::lock_mode GetMode (void);
  // Returns the mode of the lock.

protected:
  CosConcurrencyControl::lock_mode mode_;
  // Holds the lock's mode.

private:
  ACE_Thread_Semaphore semaphore_;
  // Holds the semaphore for this lock.
  // @@ Torben, can you please explain this implementation in a bit more detail? 

  int lock_held_;
  // If greater than zero the lock is held (that number of times).

  static CORBA::Boolean compatible_[5][5];
  // Defines the compatibility of the locks. 5 = number of lock modes.
  // @@ Torben, can you please make sure that you use an enum value
  // rather than a magic number for this?  Ideally, this enum value
  // would be defined in the same place as the "number of lock modes."
  // 
};

#endif /* !defined (_CC_LOCK_H) */
