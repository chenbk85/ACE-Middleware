/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    ace
//
// = FILENAME
//    SOCK_CODgram.h
//
// = AUTHOR
//    Doug Schmidt
//
// ============================================================================

#ifndef ACE_SOCK_CODGRAM_H
#include "ace/pre.h"
#define ACE_SOCK_CODGRAM_H

#include "ace/SOCK_IO.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Addr.h"

class ACE_Export ACE_SOCK_CODgram : public ACE_SOCK_IO
{
  // = TITLE
  //     Defines the member functions for the ACE_SOCK connected
  //     datagram abstraction.
public:
  // = Initialization methods.
  ACE_SOCK_CODgram (void);
  // Default constructor.

  ACE_SOCK_CODgram (const ACE_Addr &remote_sap,
                    const ACE_Addr &local_sap = ACE_Addr::sap_any,
                    int protocol_family = PF_INET,
                    int protocol = 0,
                    int reuse_addr = 0);

  ~ACE_SOCK_CODgram (void);
  // Default dtor.

  // Initiate a connected dgram.

  int open (const ACE_Addr &remote_sap,
            const ACE_Addr &local_sap = ACE_Addr::sap_any,
            int protocol_family = PF_INET,
            int protocol = 0,
            int reuse_addr = 0);
  // Initiate a connected dgram.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.
};

#if !defined (ACE_LACKS_INLINE_FUNCTIONS)
#include "ace/SOCK_CODgram.i"
#endif

#include "ace/post.h"
#endif /* ACE_SOCK_CODGRAM_H */
