//
// $Id$
//

#ifndef ROUNDTRIP_HANDLER_H
#define ROUNDTRIP_HANDLER_H
#include /**/ "ace/pre.h"

#include "TestS.h"
#include "ace/Basic_Stats.h"

#if defined (_MSC_VER)
# pragma warning(push)
# pragma warning (disable:4250)
#endif /* _MSC_VER */

/// Implement the Test::Roundtrip interface
class Roundtrip_Handler
  : public virtual POA_Test::AMI_RoundtripHandler
{
public:
  /// Constructor
  Roundtrip_Handler (int expected_callbacks);

  /// Return the number of pending callbacks
  int pending_callbacks (void) const;

  /// Dump the results
  void dump_results (ACE_UINT32 gsf);

  // = The skeleton methods for test octet load
  virtual void test_octet_method (Test::Timestamp send_time);

  virtual void test_octet_method_excep (::Messaging::ExceptionHolder *holder);

  // = The skeleton methods for test char load
  virtual void test_char_method (Test::Timestamp send_time);
  virtual void test_char_method_excep (::Messaging::ExceptionHolder *holder);

  // = The skeleton methods for test long load
  virtual void test_long_method  (Test::Timestamp send_time);
  virtual void test_long_method_excep (::Messaging::ExceptionHolder *holder);

  // = The skeleton methods for test short load
  virtual void test_short_method (Test::Timestamp send_time);
  virtual void test_short_method_excep (::Messaging::ExceptionHolder *holder);

  // = The skeleton methods for test longlong load
  virtual void test_longlong_method (Test::Timestamp send_time);
  virtual void test_longlong_method_excep (::Messaging::ExceptionHolder *holder);

  // = The skeleton methods for test double load
  virtual void test_double_method (Test::Timestamp send_time);
  virtual void test_double_method_excep (::Messaging::ExceptionHolder *holder);

  // = Other methods

  virtual void shutdown (void);
  virtual void shutdown_excep (::Messaging::ExceptionHolder *holder);

private:
  /// The number of callbacks not received yet
  int pending_callbacks_;

  /// Collect the latency results
  ACE_Basic_Stats latency_stats_;
};

#if defined(_MSC_VER)
# pragma warning(pop)
#endif /* _MSC_VER */

#include /**/ "ace/post.h"
#endif /* ROUNDTRIP_H */
