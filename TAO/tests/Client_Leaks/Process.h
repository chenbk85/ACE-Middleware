//
// $Id$
//

#ifndef CLIENT_LEAKS_PROCESS_H
#define CLIENT_LEAKS_PROCESS_H
#include /**/ "ace/pre.h"

#include "TestS.h"

#if defined (_MSC_VER)
# pragma warning(push)
# pragma warning (disable:4250)
#endif /* _MSC_VER */

/// Implement the Test::Process interface
class Process
  : public virtual POA_Test::Process
  , public virtual PortableServer::RefCountServantBase
{
public:
  /// Constructor
  Process (CORBA::ORB_ptr orb);

  // = The skeleton methods
  virtual CORBA::Long get_process_id (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void shutdown (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

private:
  /// Use an ORB reference to conver strings to objects and shutdown
  /// the application.
  CORBA::ORB_var orb_;
};

#if defined(_MSC_VER)
# pragma warning(pop)
#endif /* _MSC_VER */

#include /**/ "ace/post.h"
#endif /* CLIENT_LEAKS_PROCESS_H */
