//
// $Id$
//

#ifndef MEMORY_GROWTH_H
#define MEMORY_GROWTH_H
#include "ace/pre.h"

#include "TestS.h"

#if defined (_MSC_VER)
# if (_MSC_VER >= 1200)
#  pragma warning(push)
# endif /* _MSC_VER >= 1200 */
# pragma warning (disable:4250)
#endif /* _MSC_VER */

/// Implement the Test::Hello interface
class Memory_Growth
  : public virtual POA_Test::Memory_Growth
  , public virtual PortableServer::RefCountServantBase
{
public:
  /// Constructor
  Memory_Growth (CORBA::ORB_ptr orb);

  // = The skeleton methods
  virtual void ping (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void shutdown (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

private:
  /// Use an ORB reference to conver strings to objects and shutdown
  /// the application.
  CORBA::ORB_var orb_;
};

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma warning(pop)
#endif /* _MSC_VER */

#include "ace/post.h"
#endif /* MEMORY_GROWTH_H */
