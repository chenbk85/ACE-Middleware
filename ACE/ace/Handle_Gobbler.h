// -*- C++ -*-

//=============================================================================
/**
 *  @file    Handle_Gobbler.h
 *
 *  $Id$
 *
 *  @author Kirthika Parameswaran <kirthika@cs.wustl.edu>
 *  @author Irfan Pyarali <irfan@cs.wustl.edu>
 */
//=============================================================================


#ifndef ACE_HANDLE_GOBBLER_H
#define ACE_HANDLE_GOBBLER_H
#include /**/ "ace/pre.h"

#if 0
#include "ace/Unbounded_Set.h"
#else
#include "ace/Handle_Set.h"
#endif

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Handle_Gobbler
 *
 * @brief This class gobbles up handles.
 *
 * This is useful when we need to control the number of handles
 * available for a process.  This class is mostly used for
 * testing purposes.
 */
class ACE_Handle_Gobbler
{
public:

  /// Destructor.  Cleans up any remaining handles.
  inline ~ACE_Handle_Gobbler (void);

  /**
   * Handles are opened continously until the process runs out of
   * them, and then <n_handles_to_keep_available> handles are closed
   * (freed) thereby making them usable in the future.
   */
  inline int consume_handles (size_t n_handles_to_keep_available);

  /// Free up @a n_handles.
  inline int free_handles (size_t n_handles);

  /// All remaining handles are closed.
  inline void close_remaining_handles (void);

private:
#if 0
  typedef ACE_Unbounded_Set<ACE_HANDLE> HANDLE_SET;
#else
  typedef ACE_Handle_Set HANDLE_SET;
#endif
  /// The container which holds the open descriptors.
  HANDLE_SET handle_set_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include "ace/Handle_Gobbler.inl"

#include /**/ "ace/post.h"
#endif /* ACE_HANDLE_GOBBLER_H */
