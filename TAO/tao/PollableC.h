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
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef _TAO_IDL_TMP_POLLABLEC_H_
#define _TAO_IDL_TMP_POLLABLEC_H_
#include "ace/pre.h"

#include "tao/corbafwd.h"

#if (TAO_HAS_AMI_POLLER == 1)

#include "tao/Object.h"
#include "tao/Exception.h"
#include "tao/CDR.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_Export
#endif /* TAO_EXPORT_NESTED_CLASSES */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

class CORBA_PollableSet;

#if !defined (_CORBA_POLLABLESET___PTR_CH_)
#define _CORBA_POLLABLESET___PTR_CH_

typedef CORBA_PollableSet *CORBA_PollableSet_ptr;

#endif /* end #if !defined */


#if !defined (_CORBA_POLLABLESET___VAR_CH_)
#define _CORBA_POLLABLESET___VAR_CH_

class TAO_Export CORBA_PollableSet_var : public TAO_Base_var
{
public:
  CORBA_PollableSet_var (void); // default constructor
  CORBA_PollableSet_var (CORBA_PollableSet_ptr);
  CORBA_PollableSet_var (const CORBA_PollableSet_var &); // copy constructor
  ~CORBA_PollableSet_var (void); // destructor

  CORBA_PollableSet_var &operator= (CORBA_PollableSet_ptr);
  CORBA_PollableSet_var &operator= (const CORBA_PollableSet_var &);
  CORBA_PollableSet_ptr operator-> (void) const;

  operator const CORBA_PollableSet_ptr &() const;
  operator CORBA_PollableSet_ptr &();
  // in, inout, out, _retn
  CORBA_PollableSet_ptr in (void) const;
  CORBA_PollableSet_ptr &inout (void);
  CORBA_PollableSet_ptr &out (void);
  CORBA_PollableSet_ptr _retn (void);
  CORBA_PollableSet_ptr ptr (void) const;

  // Hooks used by template sequence and object manager classes
  // for non-defined forward declared interfaces.
  static CORBA_PollableSet_ptr duplicate (CORBA_PollableSet_ptr);
  static void release (CORBA_PollableSet_ptr);
  static CORBA_PollableSet_ptr nil (void);
  static CORBA_PollableSet_ptr narrow (CORBA::Object *, CORBA::Environment &);
  static CORBA::Object * upcast (void *);

private:
  CORBA_PollableSet_ptr ptr_;
  // Unimplemented - prevents widening assignment.
  CORBA_PollableSet_var (const TAO_Base_var &rhs);
  CORBA_PollableSet_var &operator= (const TAO_Base_var &rhs);
};


#endif /* end #if !defined */


#if !defined (_CORBA_POLLABLESET___OUT_CH_)
#define _CORBA_POLLABLESET___OUT_CH_

class TAO_Export CORBA_PollableSet_out
{
public:
  CORBA_PollableSet_out (CORBA_PollableSet_ptr &);
  CORBA_PollableSet_out (CORBA_PollableSet_var &);
  CORBA_PollableSet_out (const CORBA_PollableSet_out &);
  CORBA_PollableSet_out &operator= (const CORBA_PollableSet_out &);
  CORBA_PollableSet_out &operator= (const CORBA_PollableSet_var &);
  CORBA_PollableSet_out &operator= (CORBA_PollableSet_ptr);
  operator CORBA_PollableSet_ptr &();
  CORBA_PollableSet_ptr &ptr (void);
  CORBA_PollableSet_ptr operator-> (void);

private:
  CORBA_PollableSet_ptr &ptr_;
};


#endif /* end #if !defined */


#if !defined (_CORBA_POLLABLE___PTR_CH_)
#define _CORBA_POLLABLE___PTR_CH_

class CORBA_Pollable;
typedef CORBA_Pollable *CORBA_Pollable_ptr;

#endif /* end #if !defined */


#if !defined (_CORBA_POLLABLE___VAR_CH_)
#define _CORBA_POLLABLE___VAR_CH_

class TAO_Export CORBA_Pollable_var : public TAO_Base_var
{
public:
  CORBA_Pollable_var (void); // default constructor
  CORBA_Pollable_var (CORBA_Pollable_ptr);
  CORBA_Pollable_var (const CORBA_Pollable_var &); // copy constructor
  ~CORBA_Pollable_var (void); // destructor

  CORBA_Pollable_var &operator= (CORBA_Pollable_ptr);
  CORBA_Pollable_var &operator= (const CORBA_Pollable_var &);
  CORBA_Pollable_ptr operator-> (void) const;

  operator const CORBA_Pollable_ptr &() const;
  operator CORBA_Pollable_ptr &();
  // in, inout, out, _retn
  CORBA_Pollable_ptr in (void) const;
  CORBA_Pollable_ptr &inout (void);
  CORBA_Pollable_ptr &out (void);
  CORBA_Pollable_ptr _retn (void);
  CORBA_Pollable_ptr ptr (void) const;

  // Hooks used by template sequence and object manager classes
  // for non-defined forward declared interfaces.
  static CORBA_Pollable_ptr duplicate (CORBA_Pollable_ptr);
  static void release (CORBA_Pollable_ptr);
  static CORBA_Pollable_ptr nil (void);
  static CORBA_Pollable_ptr narrow (CORBA::Object *, CORBA::Environment &);
  static CORBA::Object * upcast (void *);

private:
  CORBA_Pollable_ptr ptr_;
  // Unimplemented - prevents widening assignment.
  CORBA_Pollable_var (const TAO_Base_var &rhs);
  CORBA_Pollable_var &operator= (const TAO_Base_var &rhs);
};


#endif /* end #if !defined */


#if !defined (_CORBA_POLLABLE___OUT_CH_)
#define _CORBA_POLLABLE___OUT_CH_

class TAO_Export CORBA_Pollable_out
{
public:
  CORBA_Pollable_out (CORBA_Pollable_ptr &);
  CORBA_Pollable_out (CORBA_Pollable_var &);
  CORBA_Pollable_out (const CORBA_Pollable_out &);
  CORBA_Pollable_out &operator= (const CORBA_Pollable_out &);
  CORBA_Pollable_out &operator= (const CORBA_Pollable_var &);
  CORBA_Pollable_out &operator= (CORBA_Pollable_ptr);
  operator CORBA_Pollable_ptr &();
  CORBA_Pollable_ptr &ptr (void);
  CORBA_Pollable_ptr operator-> (void);

private:
  CORBA_Pollable_ptr &ptr_;
};


#endif /* end #if !defined */


#if !defined (_CORBA_POLLABLE_CH_)
#define _CORBA_POLLABLE_CH_

class TAO_Export CORBA_Pollable : public virtual CORBA_Object
{
public:
#if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
  typedef CORBA_Pollable_ptr _ptr_type;
  typedef CORBA_Pollable_var _var_type;
#endif /* ! __GNUC__ || g++ >= 2.8 */

  // the static operations
  static CORBA_Pollable_ptr _duplicate (CORBA_Pollable_ptr obj);
  static CORBA_Pollable_ptr _narrow (
      CORBA::Object_ptr obj,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  static CORBA_Pollable_ptr _unchecked_narrow (
      CORBA::Object_ptr obj,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  static CORBA_Pollable_ptr _nil (void)
    {
      return (CORBA_Pollable_ptr)0;
    }

  virtual CORBA::Boolean is_ready (
      CORBA::ULong timeout,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    )) = 0;

  virtual CORBA_PollableSet_ptr create_pollable_set (
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    )) = 0;

  virtual void *_tao_QueryInterface (ptr_arith_t type);

  virtual const char* _interface_repository_id (void) const;

protected:
  CORBA_Pollable (void);

  virtual ~CORBA_Pollable (void);
private:
  CORBA_Pollable (const CORBA_Pollable &);
  void operator= (const CORBA_Pollable &);
};


#endif /* end #if !defined */


#if !defined (_CORBA_DIIPOLLABLE___PTR_CH_)
#define _CORBA_DIIPOLLABLE___PTR_CH_

class CORBA_DIIPollable;
typedef CORBA_DIIPollable *CORBA_DIIPollable_ptr;

#endif /* end #if !defined */


#if !defined (_CORBA_DIIPOLLABLE___VAR_CH_)
#define _CORBA_DIIPOLLABLE___VAR_CH_

class TAO_Export CORBA_DIIPollable_var : public TAO_Base_var
{
public:
  CORBA_DIIPollable_var (void); // default constructor
  CORBA_DIIPollable_var (CORBA_DIIPollable_ptr);
  CORBA_DIIPollable_var (const CORBA_DIIPollable_var &); // copy constructor
  ~CORBA_DIIPollable_var (void); // destructor

  CORBA_DIIPollable_var &operator= (CORBA_DIIPollable_ptr);
  CORBA_DIIPollable_var &operator= (const CORBA_DIIPollable_var &);
  CORBA_DIIPollable_ptr operator-> (void) const;

  operator const CORBA_DIIPollable_ptr &() const;
  operator CORBA_DIIPollable_ptr &();
  // in, inout, out, _retn
  CORBA_DIIPollable_ptr in (void) const;
  CORBA_DIIPollable_ptr &inout (void);
  CORBA_DIIPollable_ptr &out (void);
  CORBA_DIIPollable_ptr _retn (void);
  CORBA_DIIPollable_ptr ptr (void) const;

  // Hooks used by template sequence and object manager classes
  // for non-defined forward declared interfaces.
  static CORBA_DIIPollable_ptr duplicate (CORBA_DIIPollable_ptr);
  static void release (CORBA_DIIPollable_ptr);
  static CORBA_DIIPollable_ptr nil (void);
  static CORBA_DIIPollable_ptr narrow (CORBA::Object *, CORBA::Environment &);
  static CORBA::Object * upcast (void *);

private:
  CORBA_DIIPollable_ptr ptr_;
  // Unimplemented - prevents widening assignment.
  CORBA_DIIPollable_var (const TAO_Base_var &rhs);
  CORBA_DIIPollable_var &operator= (const TAO_Base_var &rhs);
};


#endif /* end #if !defined */


#if !defined (_CORBA_DIIPOLLABLE___OUT_CH_)
#define _CORBA_DIIPOLLABLE___OUT_CH_

class TAO_Export CORBA_DIIPollable_out
{
public:
  CORBA_DIIPollable_out (CORBA_DIIPollable_ptr &);
  CORBA_DIIPollable_out (CORBA_DIIPollable_var &);
  CORBA_DIIPollable_out (const CORBA_DIIPollable_out &);
  CORBA_DIIPollable_out &operator= (const CORBA_DIIPollable_out &);
  CORBA_DIIPollable_out &operator= (const CORBA_DIIPollable_var &);
  CORBA_DIIPollable_out &operator= (CORBA_DIIPollable_ptr);
  operator CORBA_DIIPollable_ptr &();
  CORBA_DIIPollable_ptr &ptr (void);
  CORBA_DIIPollable_ptr operator-> (void);

private:
  CORBA_DIIPollable_ptr &ptr_;
};


#endif /* end #if !defined */


#if !defined (_CORBA_DIIPOLLABLE_CH_)
#define _CORBA_DIIPOLLABLE_CH_

class TAO_Export CORBA_DIIPollable: public virtual CORBA_Pollable
{
public:
#if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
  typedef CORBA_DIIPollable_ptr _ptr_type;
  typedef CORBA_DIIPollable_var _var_type;
#endif /* ! __GNUC__ || g++ >= 2.8 */

  // the static operations
  static CORBA_DIIPollable_ptr _duplicate (CORBA_DIIPollable_ptr obj);
  static CORBA_DIIPollable_ptr _narrow (
      CORBA::Object_ptr obj,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  static CORBA_DIIPollable_ptr _unchecked_narrow (
      CORBA::Object_ptr obj,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  static CORBA_DIIPollable_ptr _nil (void)
    {
      return (CORBA_DIIPollable_ptr)0;
    }

  virtual void *_tao_QueryInterface (ptr_arith_t type);

  virtual const char* _interface_repository_id (void) const;

protected:
  CORBA_DIIPollable (void);

  virtual ~CORBA_DIIPollable (void);
private:
  CORBA_DIIPollable (const CORBA_DIIPollable &);
  void operator= (const CORBA_DIIPollable &);
};


#endif /* end #if !defined */


#if !defined (_CORBA_POLLABLESET___PTR_CH_)
#define _CORBA_POLLABLESET___PTR_CH_

class CORBA_PollableSet;
typedef CORBA_PollableSet *CORBA_PollableSet_ptr;

#endif /* end #if !defined */


#if !defined (_CORBA_POLLABLESET_CH_)
#define _CORBA_POLLABLESET_CH_

class TAO_Export CORBA_PollableSet : public virtual CORBA_Object
{
public:
#if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
  typedef CORBA_PollableSet_ptr _ptr_type;
  typedef CORBA_PollableSet_var _var_type;
#endif /* ! __GNUC__ || g++ >= 2.8 */

  // the static operations
  static CORBA_PollableSet_ptr _duplicate (CORBA_PollableSet_ptr obj);
  static CORBA_PollableSet_ptr _narrow (
      CORBA::Object_ptr obj,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  static CORBA_PollableSet_ptr _unchecked_narrow (
      CORBA::Object_ptr obj,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  static CORBA_PollableSet_ptr _nil (void)
    {
      return (CORBA_PollableSet_ptr)0;
    }


#if !defined (_CORBA_POLLABLESET_NOPOSSIBLEPOLLABLE_CH_)
#define _CORBA_POLLABLESET_NOPOSSIBLEPOLLABLE_CH_

  class TAO_Export NoPossiblePollable : public CORBA::UserException
  {
  public:

    NoPossiblePollable (void);
    // Default constructor.
    
    NoPossiblePollable (const NoPossiblePollable &);
    // Copy constructor.
    
    ~NoPossiblePollable (void);
    // Destructor.
    
    NoPossiblePollable &operator= (const NoPossiblePollable &);
    
    virtual void _raise (void);

    virtual void _tao_encode (
        TAO_OutputCDR &,
        CORBA::Environment &
      ) const;
    
    virtual void _tao_decode (
        TAO_InputCDR &,
        CORBA::Environment &
      );
    
    static NoPossiblePollable *_downcast (CORBA::Exception *);


    // = TAO extension.
    static CORBA::Exception *_alloc (void);
  }; // Exception CORBA_PollableSet::NoPossiblePollable.


#endif /* end #if !defined */


#if !defined (_CORBA_POLLABLESET_UNKNOWNPOLLABLE_CH_)
#define _CORBA_POLLABLESET_UNKNOWNPOLLABLE_CH_

  class TAO_Export UnknownPollable : public CORBA::UserException
  {
  public:

    UnknownPollable (void);
    // Default constructor.
    
    UnknownPollable (const UnknownPollable &);
    // Copy constructor.
    
    ~UnknownPollable (void);
    // Destructor.
    
    UnknownPollable &operator= (const UnknownPollable &);
    
    virtual void _raise (void);

    virtual void _tao_encode (
        TAO_OutputCDR &,
        CORBA::Environment &
      ) const;
    
    virtual void _tao_decode (
        TAO_InputCDR &,
        CORBA::Environment &
      );
    
    static UnknownPollable *_downcast (CORBA::Exception *);


    // = TAO extension.
    static CORBA::Exception *_alloc (void);
  }; // Exception CORBA_PollableSet::UnknownPollable.


#endif /* end #if !defined */

virtual CORBA_DIIPollable_ptr create_dii_pollable (
    CORBA::Environment &ACE_TRY_ENV =
      TAO_default_environment ()
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  )) = 0;

virtual void add_pollable (
    CORBA_Pollable_ptr potential,
    CORBA::Environment &ACE_TRY_ENV =
      TAO_default_environment ()
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  )) = 0;

virtual CORBA_Pollable_ptr poll (
    CORBA::ULong timeout,
    CORBA::Environment &ACE_TRY_ENV =
      TAO_default_environment ()
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    CORBA_PollableSet::NoPossiblePollable
  )) = 0;

virtual void remove (
    CORBA_Pollable_ptr potential,
    CORBA::Environment &ACE_TRY_ENV =
      TAO_default_environment ()
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    CORBA_PollableSet::UnknownPollable
  )) = 0;

virtual CORBA::UShort number_left (
    CORBA::Environment &ACE_TRY_ENV =
      TAO_default_environment ()
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  )) = 0;

virtual void *_tao_QueryInterface (ptr_arith_t type);

virtual const char* _interface_repository_id (void) const;

protected:
  CORBA_PollableSet (void);

  virtual ~CORBA_PollableSet (void);
private:
  CORBA_PollableSet (const CORBA_PollableSet &);
  void operator= (const CORBA_PollableSet &);
};


#endif /* end #if !defined */


#ifndef __ACE_INLINE__


#endif /* __ACE_INLINE__ */


#if defined (__ACE_INLINE__)
#include "PollableC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#endif /* TAO_HAS_AMI_POLLER == 1 */

#include "ace/post.h"
#endif /* ifndef */
