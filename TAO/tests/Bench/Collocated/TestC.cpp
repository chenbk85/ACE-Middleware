// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be/be_codegen.cpp:301


#include "TestC.h"
#include "tao/Stub.h"
#include "tao/Invocation_Adapter.h"
#include "tao/Invocation.h"
#include "tao/PortableInterceptor.h"

#if TAO_HAS_INTERCEPTORS == 1
#include "tao/RequestInfo_Util.h"
#include "tao/ClientRequestInfo_i.h"
#include "tao/ClientInterceptorAdapter.h"
#endif  /* TAO_HAS_INTERCEPTORS == 1 */

#include "tao/Basic_Arguments.h"
#include "tao/UB_String_Arguments.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "TestC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:60

int Test::Hello::_tao_class_id = 0;

Test::Hello_ptr
Test::tao_Hello_life::tao_duplicate (
    Hello_ptr p
  )
{
  return Hello::_duplicate (p);
}

void
Test::tao_Hello_life::tao_release (
    Hello_ptr p
  )
{
  CORBA::release (p);
}

Test::Hello_ptr
Test::tao_Hello_life::tao_nil (
    void
  )
{
  return Hello::_nil ();
}

CORBA::Boolean
Test::tao_Hello_life::tao_marshal (
    Hello_ptr p,
    TAO_OutputCDR &cdr
  )
{
  return p->marshal (cdr);
}

Test::Hello_ptr
Test::tao_Hello_cast::tao_narrow (
    CORBA::Object *p
    ACE_ENV_ARG_DECL
  )
{
  return Hello::_narrow (p ACE_ENV_ARG_PARAMETER);
}

CORBA::Object *
Test::tao_Hello_cast::tao_upcast (
    void *src
  )
{
  Hello **tmp =
    ACE_static_cast (Hello **, src);
  return *tmp;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
  template class
    TAO_Objref_Var_T<
        Test::Hello,
        Test::tao_Hello_life
      >;
  template class
    TAO_Objref_Out_T<
        Test::Hello,
        Test::tao_Hello_life
      >;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate \
    TAO_Objref_Var_T< \
        Test::Hello, \
        Test::tao_Hello_life \
      >
# pragma instantiate \
    TAO_Objref_Out_T< \
        Test::Hello, \
        Test::tao_Hello_life \
      >
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */


///////////////////////////////////////////////////////////
///// Function pointer for collocation factory initialization
//////////////////////////////////////////////////////////

TAO::Collocation_Proxy_Broker *
(*Test__TAO_Hello_Collocation_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

////////////////////////////////////////////////////////////////////
///// Function pointer for collocation factory initialization end
////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
/// Proxy implementation
////////////////////////////////////////////////////////////////
char * Test::Hello::get_string (
    ACE_ENV_SINGLE_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  if (!this->is_evaluated ())
    {
      ACE_NESTED_CLASS (CORBA, Object)::tao_object_initialize (this);
    }

  if (this->the_TAO_Hello_Proxy_Broker_ == 0)
    {
      Test_Hello_setup_collocation (
          this->ACE_NESTED_CLASS (CORBA, Object)::_is_collocated ()
        );
    }

  TAO::Arg_Traits<CORBA::Char *>::stub_ret_val _tao_retval;

  TAO::Argument *_tao_signature [] =
    {
      &_tao_retval
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _tao_signature,
      1,
      "get_string",
      10,
      this->the_TAO_Hello_Proxy_Broker_
    );

  _tao_call.invoke (0, 0 ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (_tao_retval.excp ());

  return _tao_retval.retn ();
}

// TAO_IDL - Generated from
// be/be_visitor_operation/remote_proxy_impl_cs.cpp:63

void Test::Hello::shutdown (
     ACE_ENV_SINGLE_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  if (!this->is_evaluated ())
    {
      ACE_NESTED_CLASS (CORBA, Object)::tao_object_initialize (this);
    }

  if (this->the_TAO_Hello_Proxy_Broker_ == 0)
    {
      Test_Hello_setup_collocation (
          this->ACE_NESTED_CLASS (CORBA, Object)::_is_collocated ()
        );
    }

  TAO::Arg_Traits<void>::stub_ret_val _tao_retval;

  TAO::Argument *_tao_signature [] =
    {
      &_tao_retval
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _tao_signature,
      1,
      "shutdown",
      8,
      this->the_TAO_Hello_Proxy_Broker_,
      TAO::TAO_ONEWAY_INVOCATION
    );

  _tao_call.invoke (0, 0 ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

Test::Hello::Hello (int collocated)
  : the_TAO_Hello_Proxy_Broker_ (0)
{
  this->Test_Hello_setup_collocation (collocated);
}

void
Test::Hello::Test_Hello_setup_collocation (int collocated)
{
  if (collocated)
    this->the_TAO_Hello_Proxy_Broker_ =
      ::Test__TAO_Hello_Collocation_Proxy_Broker_Factory_function_pointer (this);
}

Test::Hello::~Hello (void)
{}

void
Test::Hello::_tao_any_destructor (void *_tao_void_pointer)
{
  Hello *tmp = ACE_static_cast (Hello *, _tao_void_pointer);
  CORBA::release (tmp);
}

Test::Hello_ptr
Test::Hello::_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL
  )
{
  if (CORBA::is_nil (obj))
    {
      return Hello::_nil ();
    }

  if (! obj->_is_local ())
    {
      CORBA::Boolean is_a =
        obj->_is_a (
            "IDL:Test/Hello:1.0"
            ACE_ENV_ARG_PARAMETER
          );
      ACE_CHECK_RETURN (Hello::_nil ());

      if (is_a == 0)
        {
          return Hello::_nil ();
        }
    }

  return Hello::_unchecked_narrow (obj ACE_ENV_ARG_PARAMETER);
}

Test::Hello_ptr
Test::Hello::_unchecked_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (obj))
    {
      return Hello::_nil ();
    }

  Hello_ptr default_proxy = Hello::_nil ();

  // Code for lazily evaluated IOR's
  if (!obj->is_evaluated ())
    {
      ACE_NEW_RETURN (
          default_proxy,
          ::Test::Hello (
              obj->steal_ior (),
              obj->orb_core ()
            ),
          Hello::_nil ()
        );

      return default_proxy;
    }

  if (! obj->_is_local ())
    {
      TAO_Stub* stub = obj->_stubobj ();

      if (stub != 0)
        {
          stub->_incr_refcnt ();
        }

      if (
          !CORBA::is_nil (stub->servant_orb_var ().ptr ()) &&
          stub->servant_orb_var ()->orb_core ()->optimize_collocation_objects () &&
          obj->_is_collocated () &&
          Test__TAO_Hello_Collocation_Proxy_Broker_Factory_function_pointer != 0
        )
        {
          ACE_NEW_RETURN (
              default_proxy,
              ::Test::Hello (
                  stub,
                  1,
                  obj->_servant ()
                ),
              Hello::_nil ()
            );
        }

      if (CORBA::is_nil (default_proxy))
        {
          ACE_NEW_RETURN (
              default_proxy,
              ::Test::Hello (
                  stub,
                  0,
                  obj->_servant ()
                ),
              Hello::_nil ()
            );
        }

      return default_proxy;
    }
  else
    return
      ACE_reinterpret_cast (
          Hello_ptr,
          obj->_tao_QueryInterface (
              ACE_reinterpret_cast (
                  ptrdiff_t,
                  &Hello::_tao_class_id
                )
            )
        );
}

Test::Hello_ptr
Test::Hello::_duplicate (Hello_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

CORBA::Boolean
Test::Hello::_is_a (
    const char *value
    ACE_ENV_ARG_DECL
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:Test/Hello:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
     )
    {
      return 1; // success using local knowledge
    }
  else
    {
      return this->ACE_NESTED_CLASS (CORBA, Object)::_is_a (
          value
          ACE_ENV_ARG_PARAMETER
        );
    }
}

void *Test::Hello::_tao_QueryInterface (ptrdiff_t type)
{
  void *retv = 0;

  if (type == ACE_reinterpret_cast (
              ptrdiff_t,
              &ACE_NESTED_CLASS (::Test, Hello)::_tao_class_id)
            )
    {
      retv = ACE_reinterpret_cast (void*, this);
    }
  else if (type == ACE_reinterpret_cast (
               ptrdiff_t,
               &CORBA::Object::_tao_class_id)
             )
    {
      retv =
        ACE_reinterpret_cast (
            void *,
            ACE_static_cast (CORBA::Object_ptr, this)
          );
    }

  if (retv != 0)
    {
      this->_add_ref ();
    }

  return retv;
}

const char* Test::Hello::_interface_repository_id (void) const
{
  return "IDL:Test/Hello:1.0";
}

CORBA::Boolean
Test::Hello::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

static const CORBA::Long _oc_Test_Hello[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  19,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x54657374),
  ACE_NTOHL (0x2f48656c),
  ACE_NTOHL (0x6c6f3a31),
  ACE_NTOHL (0x2e300000),  // repository ID = IDL:Test/Hello:1.0
    6,
  ACE_NTOHL (0x48656c6c),
  ACE_NTOHL (0x6f000000),  // name = Hello
  };

static CORBA::TypeCode _tc_TAO_tc_Test_Hello (
    CORBA::tk_objref,
    sizeof (_oc_Test_Hello),
    (char *) &_oc_Test_Hello,
    0,
    sizeof (Test::Hello)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (Test)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_Hello,
    &_tc_TAO_tc_Test_Hello
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:50

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    Test::Hello_ptr _tao_elem
  )
{
  Test::Hello_ptr _tao_objptr =
    Test::Hello::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    Test::Hello_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<Test::Hello>::insert (
      _tao_any,
      Test::Hello::_tao_any_destructor,
      Test::_tc_Hello,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    Test::Hello_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<Test::Hello>::extract (
        _tao_any,
        Test::Hello::_tao_any_destructor,
        Test::_tc_Hello,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  template class TAO::Any_Impl_T<Test::Hello>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO::Any_Impl_T<Test::Hello>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_cs.cpp:63

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Test::Hello_ptr _tao_objref
  )
{
  CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    Test::Hello_ptr &_tao_objref
  )
{
  ACE_TRY_NEW_ENV
  {
    CORBA::Object_var obj;

    if ((strm >> obj.inout ()) == 0)
      {
        return 0;
      }

    // Narrow to the right type.
    _tao_objref =
      Test::Hello::_unchecked_narrow (
          obj.in ()
          ACE_ENV_ARG_PARAMETER
        );
    ACE_TRY_CHECK;
    return 1;
  }
  ACE_CATCHANY
  {
    // do nothing
  }
  ACE_ENDTRY;
  return 0;
}
