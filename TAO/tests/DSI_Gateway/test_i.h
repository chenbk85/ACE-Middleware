// $Id$

// ============================================================================
//
// = LIBRARY
//   TAO/tests/DSI_Gateway
//
// = FILENAME
//   test_i.h
//
// = AUTHOR
//   Carlos O'Ryan
//
// ============================================================================

#ifndef TAO_DSI_GATEWAY_TEST_I_H
#define TAO_DSI_GATEWAY_TEST_I_H

#include "testS.h"

class Simple_Server_i : public POA_Simple_Server
{
  // = TITLE
  //   Simpler Server implementation
  //
  // = DESCRIPTION
  //   Implements the Simple_Server interface in test.idl
  //
public:
  Simple_Server_i (CORBA::ORB_ptr orb);
  // ctor

  // = The Simple_Server methods.
  CORBA::Long test_method (CORBA::Long x,
                           const Structure& the_in_structure,
                           Structure_out the_out_structure,
                           char *&name,
                           CORBA::Environment&)
    ACE_THROW_SPEC (());

  void shutdown (CORBA::Environment&)
    ACE_THROW_SPEC (());

private:
  CORBA::ORB_var orb_;
  // The ORB
};

#if defined(__ACE_INLINE__)
#include "test_i.i"
#endif /* __ACE_INLINE__ */

#endif /* TAO_DSI_GATEWAY_TEST_I_H */
