#ifndef guard_testing_sequence_traits_hpp
#define guard_testing_sequence_traits_hpp
/**
 * @file
 *
 * @brief Specialize the allocation traits in a manner suitable for
 * testing.
 *
 * $Id$
 *
 * @author Carlos O'Ryan
 */

#include "unbounded_value_allocation_traits.hpp"
#include "bounded_value_allocation_traits.hpp"
#include "unbounded_reference_allocation_traits.hpp"
#include "bounded_reference_allocation_traits.hpp"
#include "testing_exception.hpp"
#include "testing_counters.hpp"

template<typename T, class base>
struct testing_allocation_traits : public base
{
  typedef typename base::value_type value_type;

  static call_counter default_buffer_allocation_calls;
  inline static value_type * default_buffer_allocation()
  {
    default_buffer_allocation_calls();
    return base::default_buffer_allocation();
  }

  static call_counter allocbuf_calls;
  inline static value_type * allocbuf(CORBA::ULong maximum)
  {
    allocbuf_calls();
    return base::allocbuf(maximum);
  }

  static call_counter freebuf_calls;
  inline static void freebuf(value_type * buffer)
  {
    freebuf_calls();
    base::freebuf(buffer);
  }
};

template<typename T, class base> call_counter
testing_allocation_traits<T,base>::allocbuf_calls;

template<typename T, class base> call_counter
testing_allocation_traits<T,base>::freebuf_calls;

template<typename T, class base> call_counter
testing_allocation_traits<T,base>::default_buffer_allocation_calls;

namespace TAO
{
namespace details
{

template<typename T>
struct unbounded_value_allocation_traits<T,true>
  : public testing_allocation_traits<T, unbounded_value_allocation_traits<T,false> >
{
};

template<typename T, CORBA::ULong MAX>
struct bounded_value_allocation_traits<T,MAX,true>
  : public testing_allocation_traits<T, bounded_value_allocation_traits<T,MAX,false> >
{
};

template<typename T, class reference_traits>
struct unbounded_reference_allocation_traits<T,reference_traits,true>
  : public testing_allocation_traits<T, unbounded_reference_allocation_traits<T,reference_traits,false> >
{
};

template<typename T, class reference_traits, CORBA::ULong MAX>
struct bounded_reference_allocation_traits<T,reference_traits,MAX,true>
  : public testing_allocation_traits<T, bounded_reference_allocation_traits<T,reference_traits,MAX,false> >
{
};

} // namespace details
} // namespace TAO

#endif // guard_testing_sequence_traits_hpp
