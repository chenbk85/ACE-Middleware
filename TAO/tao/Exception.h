// -*- C++ -*-

//=============================================================================
/**
 *  @file    Exception.h
 *
 *  $Id$
 *
 *   This file defines way in which CORBA exceptions are reported.
 *
 *  @author Copyright 1994-1995 by Sun Microsystems Inc.
 *  @author DOC Group at Vanderbilt U., Wash U, and UCI
 */
//=============================================================================

#ifndef TAO_EXCEPTION_H
#define TAO_EXCEPTION_H
#include /**/"ace/pre.h"


#include "tao/corbafwd.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// This is used in the implementation of the _raise methods
#if defined (TAO_HAS_EXCEPTIONS)
#define TAO_RAISE(EXCEPTION) throw EXCEPTION
#else
#define TAO_RAISE(EXCEPTION)
#endif /* TAO_HAS_EXCEPTIONS */

#include "ace/CORBA_macros.h"
#include "ace/SStringfwd.h"
#include "ace/iosfwd.h"

#include <stdarg.h>
#include <stdio.h>   /* For "FILE" typedef. */

class ACE_Allocator;

class TAO_OutputCDR;
class TAO_InputCDR;

#if defined (__Lynx__)

// LynxOS uses macro THREAD_CANCELLED internally, so it must
// be undefined to avoid compilation errors
#if defined (THREAD_CANCELLED)
#undef THREAD_CANCELLED
#endif /* THREAD_CANCELLED */

#endif /*__Lynx__ */

namespace CORBA
{
  /**
   * @class Exception
   *
   * @brief Exception
   *
   * CORBA2-specified exception hierarchy.  All exceptions have a
   * type (represented by a TypeCode) and a widely scoped type ID
   * (in the TypeCode) that generated by any OMG-IDL compiler and
   * available through the Interface Repositories.  Think of it as a
   * "globally scoped" name distinguishing each exception.
   */

  /* NOTE:
     According to the OMG CORBA C++ Mapping version 1.1, all
	 constructors, copy constructors and assignment operators
	 should be moved to "protected" section in class declarations

	 Since the current MS Visual C++ 6.0 compiler will cause some
	 problems to TAO's exception mechanism, so we defer doing this until
	 we full migrate from VC 6.0 to VC 7.0 and higher version.

     This later change only affect the "Exception.h" file and won't
	 affect the "Exception.cpp" file.
  */

  class TAO_Export Exception
  {
  public:

    /// Copy constructor.
    Exception (const Exception &src);

    /// Assignment operator.
    Exception &operator = (const Exception &src);

    /// Destructor.
    virtual ~Exception (void);

    // = To throw the exception (when using the standard mapping).
    virtual void _raise (void) const = 0;

    // = The static narrow operation.
    static Exception *_downcast (Exception *x);

    /// Return the repository ID of the Exception.
    virtual const char *_rep_id (void) const;

    /// Return the name of the Exception.
    virtual const char *_name (void) const;

    // = These are TAO-specific extensions.

    /// Will be overridden in the concrete derived classes.
    virtual CORBA::TypeCode_ptr _type (void) const;

    // = To implement the narrow method.
    virtual int _is_a (const char* repository_id) const;

    /// Constructor from a respository id.
    Exception (const char *repository_id,
               const char *local_name);

    /// Print the exception <ex> to output determined by <f>.  This
    /// function is not CORBA compliant.
    void _tao_print_exception (const char *info,
                               FILE *f = stdout) const;

#if defined (ACE_USES_WCHAR)
    /// ACE_WCHAR_T version of _tao_print_exception.
    void _tao_print_exception (const ACE_WCHAR_T *info,
                               FILE *f = stdout) const;
#endif  // ACE_USES_WCHAR

    /// Returns a string containing information about the exception. This
    /// function is not CORBA compliant.
    virtual ACE_CString _info (void) const = 0;

    virtual void _tao_encode (TAO_OutputCDR &cdr
                              ACE_ENV_ARG_DECL_NOT_USED) const = 0;
    virtual void _tao_decode (TAO_InputCDR &cdr
                              ACE_ENV_ARG_DECL_NOT_USED) = 0;

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
     *     return new SomeException (*this);
     *   }
     * };
     * </PRE>
     */
    virtual CORBA::Exception *_tao_duplicate (void) const = 0;

  protected:
    /// Default constructor is protected.
    Exception (void);

  private:
    /// Storage of our repository id and local name.
    char *id_;
    char *name_;
  };

  /**
   * @class UserException
   *
   * @brief User exceptions are those defined by application developers
   * using OMG-IDL.
   */
  class TAO_Export UserException : public Exception
  {
  public:

    /// Copy constructor.
    UserException (const UserException &src);

    /// Destructor.
    ~UserException (void);

    /// Assignment operator.
    UserException &operator= (const UserException &src);

    /// The narrow operation.
    static UserException *_downcast (CORBA::Exception *exception);

	/// The const version of narrow operation
    static const UserException *_downcast (const CORBA::Exception *exception);

    virtual void _raise (void) const = 0;

    // = TAO specific extension.

    /// Constructor from a repository id.
    UserException (const char *repository_id,
                   const char *local_name);

    virtual int _is_a (const char *interface_id) const;

    // Used for narrowing

    /// Returns a string containing information about the exception. This
    /// function is not CORBA compliant.
    virtual ACE_CString _info (void) const;

    //protected:
    /// Default constructor.
    UserException (void);
  };

  /**
   * @class SystemException
   *
   * @brief SystemException
   *
   * System exceptions are those defined in the CORBA spec; OMG-IDL
   * defines these.
   */
  class TAO_Export SystemException : public CORBA::Exception
  {
  public:

    /// Default constructtor
    SystemException (void);

    /// Copy constructor.
    SystemException (const SystemException &src);

    /// Destructor.
    ~SystemException (void);

    /// Assignment operator.
    SystemException &operator= (const SystemException &src);

    /// Get the minor status.
    CORBA::ULong minor (void) const;

    /// Set the minor status.
    void minor (CORBA::ULong m);

    /// Get the completion status.
    CORBA::CompletionStatus completed (void) const;

    /// Set the operation completion status.
    void completed (CORBA::CompletionStatus c);

    /// Narrow to a SystemException.
    static SystemException *_downcast (CORBA::Exception *exception);

	/// The const version of narrow operation to a SystemException
    static const SystemException *_downcast(const CORBA::Exception *exception);

    virtual void _raise (void) const = 0;

    // = TAO-specific extension.

    /// Helper for the _downcast operation.
    virtual int _is_a (const char *type_id) const;

    /// Print the system exception @c ex to output determined by @c f.
    /// This function is not CORBA compliant.
    void _tao_print_system_exception (FILE *f = stdout) const;

    /// Create an exception from the available exception
    /// virtual CORBA::Exception *_tao_duplicate (void) const;

    /// Returns a string containing information about the exception. This
    /// function is not CORBA compliant.
    virtual ACE_CString _info (void) const;

    virtual void _tao_encode (TAO_OutputCDR &cdr
                              ACE_ENV_ARG_DECL_NOT_USED) const;
    virtual void _tao_decode (TAO_InputCDR &cdr
                              ACE_ENV_ARG_DECL_NOT_USED);

    /// Helper to create a minor status value.
    static CORBA::ULong _tao_minor_code (u_int location,
                                         int errno_value);

    /// Helper to translate a platform-specific errno to a TAO errno
    /// value.
    static CORBA::ULong _tao_errno (int errno_value);

    /// Overridden base class method to help compilers that use
    /// explicit template instantiations going
    virtual CORBA::Exception *_tao_duplicate (void) const {return 0;}

  protected:

    /// Constructor using a repository id.
    SystemException (CORBA::ULong code,
                     CORBA::CompletionStatus completed);

    /// Constructor using a repository id.
    SystemException (const char *repository_id,
                     const char *local_name,
                     CORBA::ULong code,
                     CORBA::CompletionStatus completed);

    /// Return the exception description associated with the given OMG
    /// minor code.
    static const char *_tao_get_omg_exception_description (
      const CORBA::SystemException &exc,
      CORBA::ULong minor_code);

  private:
    /// Minor code.
    CORBA::ULong minor_;

    /// Completion status.
    CORBA::CompletionStatus completed_;

  };

  // Declarations for all of the CORBA standard exceptions.
  //
  // @@ - shouldn't have a default minor code, at least for code that's
  // inside the ORB.  All minor codes should be symbolically catalogued.

#define TAO_SYSTEM_EXCEPTION(name) \
  class TAO_Export name : public SystemException \
  { \
  public: \
    name (void); \
    name (CORBA::ULong code, \
          CORBA::CompletionStatus completed); \
    static name * _downcast (CORBA::Exception* exception); \
    virtual void _raise (void) const; \
    virtual CORBA::TypeCode_ptr _type (void) const; \
    static void _tao_any_destructor (void*); \
    virtual CORBA::Exception *_tao_duplicate (void) const; \
    static CORBA::SystemException *_tao_create (void); \
  }; \
TAO_Export void operator<<= (CORBA::Any &, const CORBA::name &); \
TAO_Export void operator<<= (CORBA::Any &, CORBA::name *); \
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, \
                                       const CORBA::name *&)

TAO_SYSTEM_EXCEPTION(UNKNOWN);          // the unknown exception
TAO_SYSTEM_EXCEPTION(BAD_PARAM);        // an invalid parameter was passed
TAO_SYSTEM_EXCEPTION(NO_MEMORY);        // memory allocation failure
TAO_SYSTEM_EXCEPTION(IMP_LIMIT);        // violated implementation limit
TAO_SYSTEM_EXCEPTION(COMM_FAILURE);     // communication failure
TAO_SYSTEM_EXCEPTION(INV_OBJREF);       // invalid object reference
TAO_SYSTEM_EXCEPTION(OBJECT_NOT_EXIST); // no such object
TAO_SYSTEM_EXCEPTION(NO_PERMISSION);    // no permission for operation
TAO_SYSTEM_EXCEPTION(INTERNAL);         // ORB internal error
TAO_SYSTEM_EXCEPTION(MARSHAL);          // error marshaling param/result
TAO_SYSTEM_EXCEPTION(INITIALIZE);       // ORB initialization failure
TAO_SYSTEM_EXCEPTION(NO_IMPLEMENT);     // implementation unavailable
TAO_SYSTEM_EXCEPTION(BAD_TYPECODE);     // bad typecode
TAO_SYSTEM_EXCEPTION(BAD_OPERATION);    // invalid operation
TAO_SYSTEM_EXCEPTION(NO_RESOURCES);     // out of resources for request
TAO_SYSTEM_EXCEPTION(NO_RESPONSE);      // response not yet available
TAO_SYSTEM_EXCEPTION(PERSIST_STORE);    // persistent storage failure
TAO_SYSTEM_EXCEPTION(BAD_INV_ORDER);    // routine invocations out of order
TAO_SYSTEM_EXCEPTION(TRANSIENT);        // transient error, try again later
TAO_SYSTEM_EXCEPTION(FREE_MEM);         // cannot free memory
TAO_SYSTEM_EXCEPTION(INV_IDENT);        // invalid identifier syntax
TAO_SYSTEM_EXCEPTION(INV_FLAG);         // invalid flag was specified
TAO_SYSTEM_EXCEPTION(INTF_REPOS);       // interface repository unavailable
TAO_SYSTEM_EXCEPTION(BAD_CONTEXT);      // error processing context object
TAO_SYSTEM_EXCEPTION(OBJ_ADAPTER);      // object adapter failure
TAO_SYSTEM_EXCEPTION(DATA_CONVERSION);  // data conversion error
TAO_SYSTEM_EXCEPTION(INV_POLICY);       // invalid policies present
TAO_SYSTEM_EXCEPTION(REBIND);           // rebind needed
TAO_SYSTEM_EXCEPTION(TIMEOUT);          // operation timed out
TAO_SYSTEM_EXCEPTION(TRANSACTION_UNAVAILABLE); // no transaction
TAO_SYSTEM_EXCEPTION(TRANSACTION_MODE);        // invalid transaction mode
TAO_SYSTEM_EXCEPTION(TRANSACTION_REQUIRED);    // operation needs transaction
TAO_SYSTEM_EXCEPTION(TRANSACTION_ROLLEDBACK);  // operation was a no-op
TAO_SYSTEM_EXCEPTION(INVALID_TRANSACTION);     // invalid TP context passed
TAO_SYSTEM_EXCEPTION(CODESET_INCOMPATIBLE);    // incompatible code set
TAO_SYSTEM_EXCEPTION(BAD_QOS);          // bad quality of service
TAO_SYSTEM_EXCEPTION(INVALID_ACTIVITY);
TAO_SYSTEM_EXCEPTION(ACTIVITY_COMPLETED);
TAO_SYSTEM_EXCEPTION(ACTIVITY_REQUIRED);
TAO_SYSTEM_EXCEPTION(THREAD_CANCELLED);

#undef TAO_SYSTEM_EXCEPTION

} // End CORBA namespace

#if !defined (ACE_LACKS_IOSTREAM_TOTALLY)

// Convenient ostream operator.
TAO_Export ostream& operator<< (ostream &os,
                                const CORBA::Exception &e);

#endif /* (ACE_LACKS_IOSTREAM_TOTALLY) */

/**
 * @class TAO_Exceptions
 *
 * @brief This class is a namespace for exception-related static data and
 * methods.
 */
class TAO_Export TAO_Exceptions
{
public:
  /**
   * Make the TypeCode for a standard exception.  When used correctly,
   * initializing system exceptions is only an exercise in CPU time;
   * it allocates no new memory.
   */
  static void make_standard_typecode (CORBA::TypeCode_ptr &tcp,
                                      const char *name,
                                      char *buf,
                                      size_t buflen
                                      ACE_ENV_ARG_DECL);

  /// Make the TypeCode for the CORBA::UnknownUserException standard
  /// exception.
  static void make_unknown_user_typecode (CORBA::TypeCode_ptr &tcp
                                          ACE_ENV_ARG_DECL);

  /// Runtime initialization of all standard exception typecodes.
  /// Called from <CORBA::ORB_init>.
  static void init (ACE_ENV_SINGLE_ARG_DECL);

  /// Runtime finalization of all standard exception typecodes.
  static void fini (void);

  /// Create a CORBA::SystemException given the interface repository ID.
  static CORBA::SystemException *create_system_exception (
      const char *id
      ACE_ENV_ARG_DECL
    );

  /**
   * This global allocator is used to initialize system exception
   * typecodes.  Since at the time, the ORB is mostly still not
   * available.  Using a separate allocator prevents CDR routines from
   * accessing the optimized allocators from the ORB.
   */
  static ACE_Allocator *global_allocator_;

private:
  /// Flag that denotes that the TAO's CORBA exceptions have been
  /// initialized.
  static int initialized_;
};

#if defined (TAO_DONT_CATCH_DOT_DOT_DOT)
/**
 * @class TAO_DONT_CATCH
 *
 * @brief This class is only used internally in TAO as an exception
 * that never gets thrown.  Never use this class anywhere.
 */
class TAO_Export TAO_DONT_CATCH
{
public:
  TAO_DONT_CATCH (void);
};
#endif /* TAO_DONT_CATCH_DOT_DOT_DOT */

#if defined (__ACE_INLINE__)
# include "tao/Exception.i"
#endif /* __ACE_INLINE__ */

#include /**/"ace/post.h"
#endif /* TAO_EXCEPTION_H */
