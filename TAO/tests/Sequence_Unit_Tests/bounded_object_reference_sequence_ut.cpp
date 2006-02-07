/**
 * @file
 *
 * @brief Unit test for unbounded sequences of object references.
 *
 * $Id$
 *
 * @author Carlos O'Ryan
 */
#include "testing_object_reference_traits.hpp"
#include "object_reference_traits.hpp"
#include "testing_allocation_traits.hpp"
#include "testing_range_checking.hpp"

#include "mock_reference.hpp"

#include "bounded_object_reference_sequence.hpp"

#include <boost/test/unit_test.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

using namespace boost::unit_test_framework;
using namespace TAO_VERSIONED_NAMESPACE_NAME::TAO;

CORBA::ULong const TMAX = 64;

struct Tester
{
  typedef bounded_object_reference_sequence<mock_reference,mock_reference_var,TMAX> tested_sequence;
  typedef tested_sequence::value_type value_type;
  typedef tested_sequence::const_value_type const_value_type;

  typedef tested_sequence::element_traits tested_element_traits;
  typedef tested_sequence::allocation_traits tested_allocation_traits;
  typedef TAO::details::range_checking<value_type,true> range;

  void test_default_constructor()
  {
    expected_calls a(tested_allocation_traits::allocbuf_calls);
    expected_calls f(tested_allocation_traits::freebuf_calls);
    expected_calls i(tested_element_traits::default_initializer_calls);
    {
      tested_sequence x;

      BOOST_CHECK_EQUAL(TMAX, x.maximum());
      BOOST_CHECK_EQUAL(CORBA::ULong(0), x.length());
      BOOST_CHECK_EQUAL(true, x.release());
    }
    BOOST_CHECK_MESSAGE(a.expect(0), a);
    BOOST_CHECK_MESSAGE(f.expect(1), f);
    BOOST_CHECK_MESSAGE(i.expect(0), i);
  }

  void test_buffer_constructor_release_true()
  {
    expected_calls a(tested_allocation_traits::allocbuf_calls);
    expected_calls f(tested_allocation_traits::freebuf_calls);
    expected_calls i(tested_element_traits::default_initializer_calls);
    {
      CORBA::ULong maximum = 32;
      tested_sequence::value_type * data = tested_sequence::allocbuf(maximum);
      a.reset();
      tested_sequence x(maximum / 2, data, true);

      BOOST_CHECK_EQUAL(TMAX, x.maximum());
      BOOST_CHECK_EQUAL(x.length(), maximum / 2);
      BOOST_CHECK_EQUAL(x.get_buffer(), data);
      BOOST_CHECK_EQUAL(x.release(), true);
    }
    BOOST_CHECK_MESSAGE(a.expect(0), a);
    BOOST_CHECK_MESSAGE(f.expect(1), f);
    BOOST_CHECK_MESSAGE(i.expect(0), i);
  }

  void test_buffer_constructor_release_false()
  {
    expected_calls a(tested_allocation_traits::allocbuf_calls);
    expected_calls f(tested_allocation_traits::freebuf_calls);
    expected_calls i(tested_element_traits::default_initializer_calls);
    {
      CORBA::ULong maximum = 64;
      tested_sequence::value_type * data = tested_sequence::allocbuf(maximum);
      a.reset();
      {
        tested_sequence x(maximum / 2, data, false);

        BOOST_CHECK_EQUAL(TMAX, x.maximum());
        BOOST_CHECK_EQUAL(x.length(), maximum / 2);
        BOOST_CHECK_EQUAL(x.get_buffer(), data);
        BOOST_CHECK_EQUAL(x.release(), false);
      }
      BOOST_CHECK_MESSAGE(a.expect(0), a);
      BOOST_CHECK_MESSAGE(f.expect(0), f);
      BOOST_CHECK_MESSAGE(i.expect(0), i);

      tested_sequence::freebuf(data);
    }
    BOOST_CHECK_MESSAGE(a.expect(0), a);
    BOOST_CHECK_MESSAGE(f.expect(1), f);
    BOOST_CHECK_MESSAGE(i.expect(0), i);
  }

  void test_copy_constructor_from_default()
  {
    expected_calls a(tested_allocation_traits::allocbuf_calls);
    expected_calls f(tested_allocation_traits::freebuf_calls);
    expected_calls i(tested_element_traits::default_initializer_calls);
    {
      tested_sequence x;

      tested_sequence y(x);
    }
    BOOST_CHECK_MESSAGE(a.expect(1), a);
    BOOST_CHECK_MESSAGE(f.expect(2), f);
    BOOST_CHECK_MESSAGE(i.expect(0), i);
  }

  void test_copy_constructor()
  {
    expected_calls a(tested_allocation_traits::allocbuf_calls);
    expected_calls da(tested_allocation_traits::default_buffer_allocation_calls);
    expected_calls f(tested_allocation_traits::freebuf_calls);
    expected_calls i(tested_element_traits::default_initializer_calls);
    expected_calls d(mock_reference::duplicate_calls);
    expected_calls r(mock_reference::release_calls);
    CORBA::ULong const l = 16;
    {
      tested_sequence x;
      BOOST_CHECK_MESSAGE(da.expect(1), da);
      BOOST_CHECK_MESSAGE(a.expect(0), a);

      x.length(l);
      BOOST_CHECK_MESSAGE(i.expect(l), i);
      BOOST_CHECK_MESSAGE(a.expect(0), a);
      BOOST_CHECK_MESSAGE(f.expect(0), f);
      BOOST_CHECK_EQUAL(l, x.length());
      for(CORBA::ULong i = 0; i != l; ++i)
      {
        x[i] = mock_reference::allocate(i);
      }

      d.reset(); r.reset();

      tested_sequence y(x);
      BOOST_CHECK_MESSAGE(a.expect(1), a);
      BOOST_CHECK_MESSAGE(f.expect(0), f);
      BOOST_CHECK_EQUAL(l, x.length());
      BOOST_CHECK_MESSAGE(d.expect(l), d);
      for(CORBA::ULong i = 0; i != l; ++i)
      {
        BOOST_CHECK_EQUAL(int(i), y[i]->id());
      }
    }
    BOOST_CHECK_MESSAGE(d.expect(0), d);
    BOOST_CHECK_MESSAGE(r.expect(2*TMAX), r);
    BOOST_CHECK_MESSAGE(a.expect(0), a);
    BOOST_CHECK_MESSAGE(f.expect(2), f);
    BOOST_CHECK_MESSAGE(i.expect(0), i);
  }

  void test_copy_constructor_throw_duplicate()
  {
    expected_calls a(tested_allocation_traits::allocbuf_calls);
    expected_calls da(tested_allocation_traits::default_buffer_allocation_calls);
    expected_calls f(tested_allocation_traits::freebuf_calls);
    expected_calls i(tested_element_traits::default_initializer_calls);
    expected_calls d(mock_reference::duplicate_calls);
    expected_calls r(mock_reference::release_calls);
    CORBA::ULong const l = 16;
    {
      tested_sequence x;
      BOOST_CHECK_MESSAGE(da.expect(1), da);
      BOOST_CHECK_MESSAGE(a.expect(0), a);

      x.length(l);
      BOOST_CHECK_MESSAGE(i.expect(l), i);

      BOOST_CHECK_MESSAGE(a.expect(0), a);
      BOOST_CHECK_MESSAGE(f.expect(0), f);
      BOOST_CHECK_EQUAL(l, x.length());
      for(CORBA::ULong i = 0; i != l; ++i)
      {
        x[i] = mock_reference::allocate(i);
      }

      d.reset(); r.reset();

      mock_reference::duplicate_calls.failure_countdown(8);
      BOOST_CHECK_THROW(tested_sequence y(x), testing_exception);
      BOOST_CHECK_MESSAGE(a.expect(1), a);
      BOOST_CHECK_MESSAGE(da.expect(0), da);
      BOOST_CHECK_MESSAGE(f.expect(1), f);
      BOOST_CHECK_MESSAGE(d.expect(8), d);
      BOOST_CHECK_MESSAGE(r.expect(TMAX), r);
    }
    BOOST_CHECK_MESSAGE(d.expect(0), d);
    BOOST_CHECK_MESSAGE(r.expect(TMAX), r);
    BOOST_CHECK_MESSAGE(a.expect(0), a);
    BOOST_CHECK_MESSAGE(f.expect(1), f);
    BOOST_CHECK_MESSAGE(i.expect(0), i);
  }

  void test_set_length_less_than_maximum()
  {
    expected_calls a(tested_allocation_traits::allocbuf_calls);
    expected_calls da(tested_allocation_traits::default_buffer_allocation_calls);
    expected_calls f(tested_allocation_traits::freebuf_calls);
    expected_calls i(tested_element_traits::default_initializer_calls);
    {
      tested_sequence x;

      x.length(8);
      BOOST_CHECK_EQUAL(TMAX, x.maximum());
      BOOST_CHECK_EQUAL(CORBA::ULong(8), x.length());
      BOOST_CHECK_EQUAL(true, x.release());

      BOOST_CHECK_MESSAGE(i.expect(8), i);
    }
    BOOST_CHECK_MESSAGE(a.expect(0), a);
    BOOST_CHECK_MESSAGE(da.expect(1), da);
    BOOST_CHECK_MESSAGE(f.expect(1), f);
  }

  void test_set_length_more_than_maximum()
  {
    expected_calls a(tested_allocation_traits::allocbuf_calls);
    expected_calls da(tested_allocation_traits::default_buffer_allocation_calls);
    expected_calls f(tested_allocation_traits::freebuf_calls);
    expected_calls i(tested_element_traits::default_initializer_calls);
    {
      tested_sequence x;
      BOOST_CHECK_MESSAGE(da.expect(1), da);
      BOOST_CHECK_MESSAGE(a.expect(0), a);
      x.length(16);
      BOOST_CHECK_MESSAGE(i.expect(16), i);

      BOOST_CHECK_THROW(x.length(2 * TMAX), std::runtime_error);
      BOOST_CHECK_MESSAGE(a.expect(0), a);
      BOOST_CHECK_MESSAGE(f.expect(0), f);
      BOOST_CHECK_MESSAGE(i.expect(0), i);

      BOOST_CHECK_EQUAL(TMAX, x.maximum());
      BOOST_CHECK_EQUAL(CORBA::ULong(16), x.length());
      BOOST_CHECK_EQUAL(true, x.release());
    }
    BOOST_CHECK_MESSAGE(f.expect(1), f);
  }

  value_type * alloc_and_init_buffer()
  {
    value_type * buf = tested_sequence::allocbuf(TMAX);
    buf[0] = mock_reference::allocate(1);
    buf[1] = mock_reference::allocate(4);
    buf[2] = mock_reference::allocate(9);
    buf[3] = mock_reference::allocate(16);

    return buf;
  }

  void check_values(tested_sequence const & a)
  {
    BOOST_CHECK_EQUAL( 1, a[0]->id());
    BOOST_CHECK_EQUAL( 4, a[1]->id());
    BOOST_CHECK_EQUAL( 9, a[2]->id());
    BOOST_CHECK_EQUAL(16, a[3]->id());
  }

  void test_replace_release_true()
  {
    value_type * buffer = alloc_and_init_buffer();

    expected_calls c(tested_allocation_traits::allocbuf_calls);
    expected_calls f(tested_allocation_traits::freebuf_calls);
    expected_calls r(tested_element_traits::release_calls);
    {
      tested_sequence a;
      a.replace(4, buffer, false);
      BOOST_CHECK_MESSAGE(c.expect(0), c);
      BOOST_CHECK_MESSAGE(f.expect(1), f);
      BOOST_CHECK_MESSAGE(r.expect(TMAX), r);

      BOOST_CHECK_EQUAL(TMAX, a.maximum());
      BOOST_CHECK_EQUAL(CORBA::ULong(4), a.length());
      BOOST_CHECK_EQUAL(buffer, a.get_buffer());
      BOOST_CHECK_EQUAL(false, a.release());
      check_values(a);
    }
    BOOST_CHECK_MESSAGE(c.expect(0), c);
    BOOST_CHECK_MESSAGE(f.expect(0), f);
    tested_sequence::freebuf(buffer);
    BOOST_CHECK_MESSAGE(r.expect(TMAX), r);
  }

  void test_replace_release_false()
  {
    value_type * buffer = alloc_and_init_buffer();

    expected_calls c(tested_allocation_traits::allocbuf_calls);
    expected_calls f(tested_allocation_traits::freebuf_calls);
    expected_calls r(tested_element_traits::release_calls);
    {
      tested_sequence a;
      a.replace(4, buffer, false);
      BOOST_CHECK_MESSAGE(c.expect(0), c);
      BOOST_CHECK_MESSAGE(f.expect(1), f);
      BOOST_CHECK_MESSAGE(r.expect(TMAX), r);

      BOOST_CHECK_EQUAL(TMAX, a.maximum());
      BOOST_CHECK_EQUAL(CORBA::ULong(4), a.length());
      BOOST_CHECK_EQUAL(buffer, a.get_buffer());
      BOOST_CHECK_EQUAL(false, a.release());
      check_values(a);
    }
    BOOST_CHECK_MESSAGE(c.expect(0), c);
    BOOST_CHECK_MESSAGE(f.expect(0), f);
    tested_sequence::freebuf(buffer);
    BOOST_CHECK_MESSAGE(r.expect(TMAX), r);
  }

  void test_replace_release_default()
  {
    value_type * buffer = alloc_and_init_buffer();

    expected_calls c(tested_allocation_traits::allocbuf_calls);
    expected_calls f(tested_allocation_traits::freebuf_calls);
    expected_calls r(tested_element_traits::release_calls);
    {
      tested_sequence a;
      a.replace(4, buffer);
      BOOST_CHECK_MESSAGE(c.expect(0), c);
      BOOST_CHECK_MESSAGE(f.expect(1), f);
      BOOST_CHECK_MESSAGE(r.expect(TMAX), r);

      BOOST_CHECK_EQUAL(TMAX, a.maximum());
      BOOST_CHECK_EQUAL(CORBA::ULong(4), a.length());
      BOOST_CHECK_EQUAL(buffer, a.get_buffer());
      BOOST_CHECK_EQUAL(false, a.release());
      check_values(a);
    }
    BOOST_CHECK_MESSAGE(c.expect(0), c);
    BOOST_CHECK_MESSAGE(f.expect(0), f);
    tested_sequence::freebuf(buffer);
    BOOST_CHECK_MESSAGE(r.expect(TMAX), r);
  }

  void add_all(test_suite * ts)
  {
    boost::shared_ptr<Tester> shared_this(self_);
    ts->add(BOOST_CLASS_TEST_CASE(
                &Tester::test_default_constructor,
                shared_this));
    ts->add(BOOST_CLASS_TEST_CASE(
                &Tester::test_buffer_constructor_release_true,
                shared_this));
    ts->add(BOOST_CLASS_TEST_CASE(
                &Tester::test_buffer_constructor_release_false,
                shared_this));
    ts->add(BOOST_CLASS_TEST_CASE(
                &Tester::test_copy_constructor_from_default,
                shared_this));
    ts->add(BOOST_CLASS_TEST_CASE(
                &Tester::test_copy_constructor,
                shared_this));
    ts->add(BOOST_CLASS_TEST_CASE(
                &Tester::test_copy_constructor_throw_duplicate,
                shared_this));
    ts->add(BOOST_CLASS_TEST_CASE(
                &Tester::test_set_length_less_than_maximum,
                shared_this));
    ts->add(BOOST_CLASS_TEST_CASE(
                &Tester::test_set_length_more_than_maximum,
                shared_this));
    ts->add(BOOST_CLASS_TEST_CASE(
                &Tester::test_replace_release_true,
                shared_this));
    ts->add(BOOST_CLASS_TEST_CASE(
                &Tester::test_replace_release_false,
                shared_this));
    ts->add(BOOST_CLASS_TEST_CASE(
                &Tester::test_replace_release_default,
                shared_this));
  }

  static boost::shared_ptr<Tester> allocate()
  {
    boost::shared_ptr<Tester> ptr(new Tester);
    ptr->self_ = ptr;

    return ptr;
  }

private:
  Tester() {}

  boost::weak_ptr<Tester> self_;
};

ACE_Proper_Export_Flag test_suite *
init_unit_test_suite(int, char*[])
{
  test_suite * ts =
      BOOST_TEST_SUITE("unbounded object reference sequence unit test");

  boost::shared_ptr<Tester> tester(Tester::allocate());
  tester->add_all(ts);

  return ts;
}

