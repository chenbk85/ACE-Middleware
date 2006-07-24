// $Id$

#include "testS.h"

class client_i : public POA_client
{
public:
  client_i (int quiet,
            server_ptr s);
  // Constructor.

  void ping (CORBA::UShort time_to_live
             ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

private:
  int quiet_;
  // Be quiet.

  server_var server_;
  // Pointer to server.
};
