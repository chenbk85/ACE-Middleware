// -*- C++ -*-

//=============================================================================
/**
 *  @file    Exception.h
 *
 *  $Id$
 *
 *   This file defines way in which CORBA exceptions are reported.
 *
 *  @author DOC Group at Vanderbilt U., Wash U, and UCI
 */
//=============================================================================

#ifndef TAO_EXCEPTION_H
#define TAO_EXCEPTION_H

#include /**/ "ace/pre.h"

// Do not try removing this. If you remove this for subsetting lots of
// things go wrong in TAO.
#include "tao/orbconf.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// This is used in the implementation of the _raise methods
#if defined (TAO_HAS_EXCEPTIONS)
#define TAO_RAISE(EXCEPTION) throw EXCEPTION
#else
#define TAO_RAISE(EXCEPTION)
#endif /* ACE_HAS_EXCEPTIONS */

#include "tao/TAO_Export.h"
#include "tao/Basic_Types.h"
#include "tao/CORBA_String.h"
#include "ace/SStringfwd.h"
#include "ace/iosfwd.h"
#include "ace/CORBA_macros.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Allocator;

class TAO_OutputCDR;
class TAO_InputCDR;

#if defined (ACE_HAS_PREDEFINED_THREAD_CANCELLED_MACRO)
#undef THREAD_CANCELLED
#endif /* ACE_HAS_PREDEFINED_THREAD_CANCELLED_MACRO */

// This is already done in orbconf.h. But this file is totally
// decoupled from its contents that we have to do this here. Including
// orbconf.h is probably going to be a overhead.
#if defined (minor)
#undef minor
#endif /* minor */

namespace CORBA
{
  class TypeCode;
  typedef TypeCode * TypeCode_ptr;

  class Environment;

  class Any;
  typedef Any * Any_ptr;

  class SystemException;

  /**
   * @enum exception_type
   *
   * @brief Enumeration used to identify the type of CORBA exception.
   *
   * CORBA exceptions generally fall into two categories, user
   * exceptions and system exceptions.  This enumeration is used when
   * identifying the type of CORBA exception.
   */
  enum exception_type
  {
    NO_EXCEPTION,
    USER_EXCEPTION,
    SYSTEM_EXCEPTION
  };

  /**
   * @class Exception
   *
   * @brief Exception
   *
   * CORBA2-specified exception hierarchy.  All exceptions have a
   * type (represented by a @c TypeCode) and a widely scoped type ID
   * (in the @c TypeCode) that are generated by any OMG-IDL compiler
   * and available through the Interface Repository.  Think of it as a
   * "globally scoped" name distinguishing each exception.
   *
   * @todo According to the OMG CORBA C++ Mapping version 1.1, all
   *       constructors, copy constructors and assignment operators
   *       should be moved to "protected" section in class
   *       declarations.  Since the current MS Visual C++ 6.0 compiler
   *       will cause some problems to TAO's exception mechanism, we
   *       defer doing this until we drop support for MSVC++ 6.
   */
  class TAO_Export Exception
  {
  public:

    /// Copy constructor.
    Exception (const Exception &src);

    /// Assignment operator.
    Exception & operator = (const Exception & src);

    /// Construct from a respository id.
    Exception (const char *repository_id,
               const char *local_name);

    /// Destructor.
    virtual ~Exception (void);

    // = To throw the exception (when using the standard mapping).
    virtual void _raise (void) const = 0;

    // = The static narrow operations.
    static Exception * _downcast (Exception * x);
    static Exception const * _downcast (Exception const * x);

    /// Return the repository ID of the Exception.
    virtual const char * _rep_id (void) const;

    /// Return the name of the Exception.
    virtual const char * _name (void) const;

    // = These are TAO-specific extensions.

    /// Will be overridden in the concrete derived classes.
    virtual CORBA::TypeCode_ptr _tao_type (void) const = 0;

    /// Print the exception to output determined by @a f.
    /**
     * @note This method is TAO-specific.
     */
    void _tao_print_exception (const char *info,
                               FILE *f = stdout) const;

#if defined (ACE_USES_WCHAR)
    /// ACE_WCHAR_T version of _tao_print_exception.
    /**
     * @note This method is TAO-specific.
     */
    void _tao_print_exception (const ACE_WCHAR_T *info,
                               FILE *f = stdout) const;
#endif  // ACE_USES_WCHAR

    /// Returns a string containing information about the exception. This
    /// function is not CORBA compliant.
    virtual ACE_CString _info (void) const = 0;

    virtual void _tao_encode (TAO_OutputCDR &cdr
                              ACE_ENV_ARG_DECL) const = 0;

    virtual void _tao_decode (TAO_InputCDR &cdr
                              ACE_ENV_ARG_DECL) = 0;

    /// Used in the non-copying Any insertion operator.
    static void _tao_any_destructor (void *);

    /// Deep copy
    /**
     * The following operation is used in the implementation of
     * it performs a deep copy of the
     * exception, normally it is implemented as:
     *
     * <PRE>
     * class SomeException : public // Derives from CORBA::Exception
     * {
     * public:
     *   virtual CORBA::Exception *_tao_duplicate (void) const
     *   {
     *     CORBA::Exception *result = 0;
     *     ACE_NEW_RETURN (
     *         result,
     *         SomeException (*this),
     *         0
     *       );
     *     return result;
     *   }
     * };
     * </PRE>
     */
    virtual CORBA::Exception *_tao_duplicate (void) const = 0;

  protected:

    /// Default constructor.
    Exception (void);

  private:

    /// Repository Id
    CORBA::String_var id_;

    /// Local name.
    CORBA::String_var name_;

  };

#if !defined (ACE_LACKS_IOSTREAM_TOTALLY)

  // Required by C++ mapping.
  TAO_Export ACE_OSTREAM_TYPE& operator<< (ACE_OSTREAM_TYPE &os,
                                          const CORBA::Exception &e);

  TAO_Export ACE_OSTREAM_TYPE& operator<< (ACE_OSTREAM_TYPE &os,
                                           const CORBA::Exception *e);

#endif /* (ACE_LACKS_IOSTREAM_TOTALLY) */
} // End CORBA namespace

/**
 * @class TAO_Exceptions
 *
 * @brief This class is a namespace for exception-related static data and
 * methods.
 */
class TAO_Export TAO_Exceptions
{
public:

  /// Create a CORBA::SystemException given the interface repository ID.
  static CORBA::SystemException *create_system_exception (const char *id);
};

TAO_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
# include "tao/Exception.i"
#endif /* __ACE_INLINE__ */

#include /**/"ace/post.h"

#endif /* TAO_EXCEPTION_H */
