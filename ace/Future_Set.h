/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    ace
//
// = FILENAME
//    Future_Set.h
//
// = AUTHOR
//    John Tucker <jtucker@infoglide.com>
//
// ============================================================================

#ifndef ACE_FUTURE_SET_H
#define ACE_FUTURE_SET_H

#include "ace/Thread.h"
#include "ace/Containers_T.h"
#include "ace/Message_Queue.h"

#include "ace/Future.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_THREADS)

// Forward decl.
template <class T> class ACE_Future_Set;

template <class T>
class ACE_Future_Set : public ACE_Future_Observer<T>
{
  // = TITLE
  //     This class implements a mechanism which allows the values of
  //     a collections of ACE_Future<T> objects to be accessed by
  //     reader threads as they become available.
public:
  // = Initialization and termination methods.
	
  ACE_Future_Set (ACE_Message_Queue<ACE_SYNCH> *future_notification_queue_ = 0);
  // Constructor.

  ~ACE_Future_Set (void);
  // Destructor.

  int is_empty (void) const;
  // Return 1 if their are no ACE_Future objects left on its queue and
  // 0 otherwise

  void insert (ACE_Future<T> &future);
  // Enqueus the given ACE_Future into this objects queue when it is
  // readable.

  int next_readable (ACE_Future<T> &result,
                     ACE_Time_Value *tv = 0);
  // Wait up to <tv> time to get the <value>.  Note that <tv> must be
  // specified in absolute time rather than relative time.); get the
  // next ACE_Future<T> that is readable.  If <tv> = 0, the will block
  // forever.
  //
  // If a readable future becomes available, then the input result
  // will be assigned with it and 1 will will be returned.  If the set
  // is empty, then 0 is returned.

  virtual void update (const ACE_Future<T> &future);
  // Called by the ACE_Future<T> subject in which we are subscribed to
  // when its value is written to.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  ACE_Future_Set (const ACE_Future_Set &r);
  // Copy constructor binds <this> and <r> to the same
  // <ACE_Future_Set>. An <ACE_Future_Set> is created if necessary.
	
  typedef ACE_DLList_Future_Node<T> 
          FUTURE_NODE;
  typedef ACE_Double_Linked_List<FUTURE_NODE> 
          FUTURE_LIST;

  FUTURE_LIST future_list_;
  // List of ACE_Futures, subjects, which have not been written to by
  // client's writer thread.

  ACE_Message_Queue<ACE_SYNCH> *future_notification_queue_;
  // Message queue for notifying reader thread of ACE_Futures written
  // to by client's writer thread.

  int delete_queue_;
  // Keeps track of whether we need to delete the message queue.
};

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Future_Set.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Future_Set.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* ACE_HAS_THREADS */
#endif /* ACE_FUTURE_SET_H */

