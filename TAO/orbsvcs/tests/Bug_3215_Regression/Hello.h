//
// $Id$
//

#ifndef HELLO_H
#define HELLO_H
#include /**/ "ace/pre.h"

#include "TestS.h"

#if defined (_MSC_VER)
# pragma warning(push)
# pragma warning (disable:4250)
#endif /* _MSC_VER */

/// Implement the Test::Hello interface
class Hello
  : public virtual POA_Test::Hello
{
public:
  /// Constructor
  Hello (CORBA::ORB_ptr orb, Test::Hello_ptr server, CORBA::ULong server_id = 0);

  // = The skeleton methods
  virtual void shutdown ()
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void ping ()
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void throw_location_forward ()
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
#endif /* HELLO_H */
