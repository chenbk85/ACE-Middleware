// -*- C++ -*-
//=============================================================================
/**
 *  @file    Any_Impl.h
 *
 *  $Id$
 *
 *  @authors  Carlos O'Ryan and Jeff Parsons
 */
//=============================================================================

#ifndef TAO_ANY_IMPL_H
#define TAO_ANY_IMPL_H

#include /**/ "ace/pre.h"
#include "ace/CORBA_macros.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Basic_Types.h"
#include "tao/TAO_Export.h"
#include "tao/orbconf.h"
#include "ace/Synch_Traits.h"
#include "ace/Null_Mutex.h"
#include "ace/Thread_Mutex.h"
#include "ace/Atomic_Op.h"

class TAO_OutputCDR;
class TAO_InputCDR;
class ACE_Message_Block;

namespace CORBA
{
  class TypeCode;
  typedef TypeCode *TypeCode_ptr;

  class Object;
  typedef Object *Object_ptr;

  class ValueBase;
  class AbstractBase;
  typedef AbstractBase *AbstractBase_ptr;

  class Environment;
}

namespace TAO
{
  /**
   * @class Any_Impl
   *
   * @brief Base class for the Any template subclasses.
   *
   * Contains common functionality and some pure virtual methods.
   */
  class TAO_Export Any_Impl
  {
  public:
    /// Generated data types define a 'destructor' function that
    /// correctly destroys an object stored in an Any.
    typedef void (*_tao_destructor)(void *);

    CORBA::Boolean marshal (TAO_OutputCDR &);
    virtual CORBA::Boolean marshal_value (TAO_OutputCDR &) = 0;

    /// @deprecated
    /// Deprecated by the OMG. This no longer appears in
    /// the C++ mapping. It is here only for backward
    /// compatibility. It is no longer (as of 5/26/04)
    /// used anywhere in TAO.
    virtual const void *value (void) const;

    virtual void free_value (void);

    CORBA::TypeCode_ptr type (void) const;
    CORBA::TypeCode_ptr _tao_get_typecode (void) const;
    void type (CORBA::TypeCode_ptr);

    virtual int _tao_byte_order (void) const;

    virtual void _add_ref (void);
    virtual void _remove_ref (void);

    /// Used to release these CORBA basic types.
    static void _tao_any_string_destructor (void *);
    static void _tao_any_wstring_destructor (void *);

    virtual void _tao_decode (TAO_InputCDR &
                              ACE_ENV_ARG_DECL);

    virtual CORBA::Boolean to_object (CORBA::Object_ptr &) const;
    virtual CORBA::Boolean to_value (CORBA::ValueBase *&) const;
    virtual CORBA::Boolean to_abstract_base (CORBA::AbstractBase_ptr &) const;

    bool encoded (void) const;

  protected:
    Any_Impl (_tao_destructor,
              CORBA::TypeCode_ptr,
              bool encoded = false);
    virtual ~Any_Impl (void);

    TAO::Any_Impl::_tao_destructor value_destructor_;
    CORBA::TypeCode_ptr type_;
    bool encoded_;

  private:
    /// Reference counter.
    ACE_Atomic_Op<TAO_SYNCH_MUTEX, CORBA::ULong> refcount_;
  };
}

#include /**/ "ace/post.h"

#endif /* TAO_ANY_IMPL_H */
