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

#ifndef _TAO_IDL_ORIG_POLLABLEC_H_
#define _TAO_IDL_ORIG_POLLABLEC_H_

#include "ace/pre.h"
#include "tao/corbafwd.h"

#if (TAO_HAS_AMI_POLLER == 1)
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "TAO_Export.h"
#include "Exception.h"
#include "Object.h"

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

TAO_NAMESPACE  CORBA
{
  class PollableSet;
  
#if !defined (_CORBA_POLLABLESET___PTR_CH_)
#define _CORBA_POLLABLESET___PTR_CH_
  
  typedef PollableSet *PollableSet_ptr;
  
#endif /* end #if !defined */
  
  
#if !defined (_CORBA_POLLABLESET___VAR_CH_)
#define _CORBA_POLLABLESET___VAR_CH_
  
  class TAO_Export PollableSet_var : public TAO_Base_var
  {
  public:
    PollableSet_var (void); // default constructor
    PollableSet_var (PollableSet_ptr p) : ptr_ (p) {} 
    PollableSet_var (const PollableSet_var &); // copy constructor
    ~PollableSet_var (void); // destructor
    
    PollableSet_var &operator= (PollableSet_ptr);
    PollableSet_var &operator= (const PollableSet_var &);
    PollableSet_ptr operator-> (void) const;
    
    operator const PollableSet_ptr &() const;
    operator PollableSet_ptr &();
    // in, inout, out, _retn 
    PollableSet_ptr in (void) const;
    PollableSet_ptr &inout (void);
    PollableSet_ptr &out (void);
    PollableSet_ptr _retn (void);
    PollableSet_ptr ptr (void) const;
    
    // Hooks used by template sequence and object manager classes
    // for non-defined forward declared interfaces.
    static PollableSet_ptr tao_duplicate (PollableSet_ptr);
    static void tao_release (PollableSet_ptr);
    static PollableSet_ptr tao_nil (void);
    static PollableSet_ptr tao_narrow (
        CORBA::Object *
        ACE_ENV_ARG_DECL_NOT_USED
      );
    static CORBA::Object * tao_upcast (void *);
  
  private:
    PollableSet_ptr ptr_;
    // Unimplemented - prevents widening assignment.
    PollableSet_var (const TAO_Base_var &rhs);
    PollableSet_var &operator= (const TAO_Base_var &rhs);
  };


#endif /* end #if !defined */
  
  
#if !defined (_CORBA_POLLABLESET___OUT_CH_)
#define _CORBA_POLLABLESET___OUT_CH_
  
  class TAO_Export PollableSet_out
  {
  public:
    PollableSet_out (PollableSet_ptr &);
    PollableSet_out (PollableSet_var &);
    PollableSet_out (const PollableSet_out &);
    PollableSet_out &operator= (const PollableSet_out &);
    PollableSet_out &operator= (const PollableSet_var &);
    PollableSet_out &operator= (PollableSet_ptr);
    operator PollableSet_ptr &();
    PollableSet_ptr &ptr (void);
    PollableSet_ptr operator-> (void);
  
  private:
    PollableSet_ptr &ptr_;
  };
  
  
#endif /* end #if !defined */
  
  
#if !defined (_CORBA_POLLABLE___PTR_CH_)
#define _CORBA_POLLABLE___PTR_CH_
  
  class Pollable;
  typedef Pollable *Pollable_ptr;
  
#endif /* end #if !defined */
  
  
#if !defined (_CORBA_POLLABLE___VAR_CH_)
#define _CORBA_POLLABLE___VAR_CH_
  
  class TAO_Export Pollable_var : public TAO_Base_var
  {
  public:
    Pollable_var (void); // default constructor
    Pollable_var (Pollable_ptr p) : ptr_ (p) {} 
    Pollable_var (const Pollable_var &); // copy constructor
    ~Pollable_var (void); // destructor
    
    Pollable_var &operator= (Pollable_ptr);
    Pollable_var &operator= (const Pollable_var &);
    Pollable_ptr operator-> (void) const;
    
    operator const Pollable_ptr &() const;
    operator Pollable_ptr &();
    // in, inout, out, _retn 
    Pollable_ptr in (void) const;
    Pollable_ptr &inout (void);
    Pollable_ptr &out (void);
    Pollable_ptr _retn (void);
    Pollable_ptr ptr (void) const;
    
    // Hooks used by template sequence and object manager classes
    // for non-defined forward declared interfaces.
    static Pollable_ptr tao_duplicate (Pollable_ptr);
    static void tao_release (Pollable_ptr);
    static Pollable_ptr tao_nil (void);
    static Pollable_ptr tao_narrow (
        CORBA::Object *
        ACE_ENV_ARG_DECL_NOT_USED
      );
    static CORBA::Object * tao_upcast (void *);
  
  private:
    Pollable_ptr ptr_;
    // Unimplemented - prevents widening assignment.
    Pollable_var (const TAO_Base_var &rhs);
    Pollable_var &operator= (const TAO_Base_var &rhs);
  };


#endif /* end #if !defined */
  
  
#if !defined (_CORBA_POLLABLE___OUT_CH_)
#define _CORBA_POLLABLE___OUT_CH_
  
  class TAO_Export Pollable_out
  {
  public:
    Pollable_out (Pollable_ptr &);
    Pollable_out (Pollable_var &);
    Pollable_out (const Pollable_out &);
    Pollable_out &operator= (const Pollable_out &);
    Pollable_out &operator= (const Pollable_var &);
    Pollable_out &operator= (Pollable_ptr);
    operator Pollable_ptr &();
    Pollable_ptr &ptr (void);
    Pollable_ptr operator-> (void);
  
  private:
    Pollable_ptr &ptr_;
  };
  
  
#endif /* end #if !defined */
  
  
#if !defined (_CORBA_POLLABLE_CH_)
#define _CORBA_POLLABLE_CH_
  
  class TAO_Export Pollable
    : public virtual CORBA::Object
  {
  public:
  #if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
    typedef Pollable_ptr _ptr_type;
    typedef Pollable_var _var_type;
  #endif /* ! __GNUC__ || g++ >= 2.8 */

    static int _tao_class_id;
    
    // The static operations.
    static Pollable_ptr _duplicate (Pollable_ptr obj);
    
    static Pollable_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static Pollable_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static Pollable_ptr _nil (void)
      {
        return (Pollable_ptr)0;
      }
    
    virtual CORBA::Boolean is_ready (
        CORBA::ULong timeout
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    virtual ::CORBA::PollableSet_ptr create_pollable_set (
        
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    virtual void *_tao_QueryInterface (ptr_arith_t type);
    
    virtual const char* _interface_repository_id (void) const;

  protected:
    Pollable (void);
    
    virtual ~Pollable (void);
  
  private:
    Pollable (const Pollable &);
    void operator= (const Pollable &);
  };
  
  
#endif /* end #if !defined */
  
  
#if !defined (_CORBA_DIIPOLLABLE___PTR_CH_)
#define _CORBA_DIIPOLLABLE___PTR_CH_
  
  class DIIPollable;
  typedef DIIPollable *DIIPollable_ptr;
  
#endif /* end #if !defined */
  
  
#if !defined (_CORBA_DIIPOLLABLE___VAR_CH_)
#define _CORBA_DIIPOLLABLE___VAR_CH_
  
  class TAO_Export DIIPollable_var : public TAO_Base_var
  {
  public:
    DIIPollable_var (void); // default constructor
    DIIPollable_var (DIIPollable_ptr p) : ptr_ (p) {} 
    DIIPollable_var (const DIIPollable_var &); // copy constructor
    ~DIIPollable_var (void); // destructor
    
    DIIPollable_var &operator= (DIIPollable_ptr);
    DIIPollable_var &operator= (const DIIPollable_var &);
    DIIPollable_ptr operator-> (void) const;
    
    operator const DIIPollable_ptr &() const;
    operator DIIPollable_ptr &();
    // in, inout, out, _retn 
    DIIPollable_ptr in (void) const;
    DIIPollable_ptr &inout (void);
    DIIPollable_ptr &out (void);
    DIIPollable_ptr _retn (void);
    DIIPollable_ptr ptr (void) const;
    
    // Hooks used by template sequence and object manager classes
    // for non-defined forward declared interfaces.
    static DIIPollable_ptr tao_duplicate (DIIPollable_ptr);
    static void tao_release (DIIPollable_ptr);
    static DIIPollable_ptr tao_nil (void);
    static DIIPollable_ptr tao_narrow (
        CORBA::Object *
        ACE_ENV_ARG_DECL_NOT_USED
      );
    static CORBA::Object * tao_upcast (void *);
  
  private:
    DIIPollable_ptr ptr_;
    // Unimplemented - prevents widening assignment.
    DIIPollable_var (const TAO_Base_var &rhs);
    DIIPollable_var &operator= (const TAO_Base_var &rhs);
  };


#endif /* end #if !defined */
  
  
#if !defined (_CORBA_DIIPOLLABLE___OUT_CH_)
#define _CORBA_DIIPOLLABLE___OUT_CH_
  
  class TAO_Export DIIPollable_out
  {
  public:
    DIIPollable_out (DIIPollable_ptr &);
    DIIPollable_out (DIIPollable_var &);
    DIIPollable_out (const DIIPollable_out &);
    DIIPollable_out &operator= (const DIIPollable_out &);
    DIIPollable_out &operator= (const DIIPollable_var &);
    DIIPollable_out &operator= (DIIPollable_ptr);
    operator DIIPollable_ptr &();
    DIIPollable_ptr &ptr (void);
    DIIPollable_ptr operator-> (void);
  
  private:
    DIIPollable_ptr &ptr_;
  };
  
  
#endif /* end #if !defined */
  
  
#if !defined (_CORBA_DIIPOLLABLE_CH_)
#define _CORBA_DIIPOLLABLE_CH_
  
  class TAO_Export DIIPollable
    : public virtual CORBA::Pollable
  {
  public:
  #if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
    typedef DIIPollable_ptr _ptr_type;
    typedef DIIPollable_var _var_type;
  #endif /* ! __GNUC__ || g++ >= 2.8 */

    static int _tao_class_id;
    
    // The static operations.
    static DIIPollable_ptr _duplicate (DIIPollable_ptr obj);
    
    static DIIPollable_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static DIIPollable_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static DIIPollable_ptr _nil (void)
      {
        return (DIIPollable_ptr)0;
      }
    
    virtual void *_tao_QueryInterface (ptr_arith_t type);
    
    virtual const char* _interface_repository_id (void) const;

  protected:
    DIIPollable (void);
    
    virtual ~DIIPollable (void);
  
  private:
    DIIPollable (const DIIPollable &);
    void operator= (const DIIPollable &);
  };
  
  
#endif /* end #if !defined */
  
  
#if !defined (_CORBA_POLLABLESET___PTR_CH_)
#define _CORBA_POLLABLESET___PTR_CH_
  
  class PollableSet;
  typedef PollableSet *PollableSet_ptr;
  
#endif /* end #if !defined */
  
  
#if !defined (_CORBA_POLLABLESET___VAR_CH_)
#define _CORBA_POLLABLESET___VAR_CH_
  
  class TAO_Export PollableSet_var : public TAO_Base_var
  {
  public:
    PollableSet_var (void); // default constructor
    PollableSet_var (PollableSet_ptr p) : ptr_ (p) {} 
    PollableSet_var (const PollableSet_var &); // copy constructor
    ~PollableSet_var (void); // destructor
    
    PollableSet_var &operator= (PollableSet_ptr);
    PollableSet_var &operator= (const PollableSet_var &);
    PollableSet_ptr operator-> (void) const;
    
    operator const PollableSet_ptr &() const;
    operator PollableSet_ptr &();
    // in, inout, out, _retn 
    PollableSet_ptr in (void) const;
    PollableSet_ptr &inout (void);
    PollableSet_ptr &out (void);
    PollableSet_ptr _retn (void);
    PollableSet_ptr ptr (void) const;
    
    // Hooks used by template sequence and object manager classes
    // for non-defined forward declared interfaces.
    static PollableSet_ptr tao_duplicate (PollableSet_ptr);
    static void tao_release (PollableSet_ptr);
    static PollableSet_ptr tao_nil (void);
    static PollableSet_ptr tao_narrow (
        CORBA::Object *
        ACE_ENV_ARG_DECL_NOT_USED
      );
    static CORBA::Object * tao_upcast (void *);
  
  private:
    PollableSet_ptr ptr_;
    // Unimplemented - prevents widening assignment.
    PollableSet_var (const TAO_Base_var &rhs);
    PollableSet_var &operator= (const TAO_Base_var &rhs);
  };


#endif /* end #if !defined */
  
  
#if !defined (_CORBA_POLLABLESET___OUT_CH_)
#define _CORBA_POLLABLESET___OUT_CH_
  
  class TAO_Export PollableSet_out
  {
  public:
    PollableSet_out (PollableSet_ptr &);
    PollableSet_out (PollableSet_var &);
    PollableSet_out (const PollableSet_out &);
    PollableSet_out &operator= (const PollableSet_out &);
    PollableSet_out &operator= (const PollableSet_var &);
    PollableSet_out &operator= (PollableSet_ptr);
    operator PollableSet_ptr &();
    PollableSet_ptr &ptr (void);
    PollableSet_ptr operator-> (void);
  
  private:
    PollableSet_ptr &ptr_;
  };
  
  
#endif /* end #if !defined */
  
  
#if !defined (_CORBA_POLLABLESET_CH_)
#define _CORBA_POLLABLESET_CH_
  
  class TAO_Export PollableSet
    : public virtual CORBA::Object
  {
  public:
  #if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
    typedef PollableSet_ptr _ptr_type;
    typedef PollableSet_var _var_type;
  #endif /* ! __GNUC__ || g++ >= 2.8 */

    static int _tao_class_id;
    
    // The static operations.
    static PollableSet_ptr _duplicate (PollableSet_ptr obj);
    
    static PollableSet_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static PollableSet_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static PollableSet_ptr _nil (void)
      {
        return (PollableSet_ptr)0;
      }
    
    
#if !defined (_CORBA_POLLABLESET_NOPOSSIBLEPOLLABLE_CH_)
#define _CORBA_POLLABLESET_NOPOSSIBLEPOLLABLE_CH_
    
    class TAO_Export NoPossiblePollable : public CORBA::UserException
    {
    public:
      
      NoPossiblePollable (void);
      NoPossiblePollable (const NoPossiblePollable &);
      ~NoPossiblePollable (void);

      NoPossiblePollable &operator= (const NoPossiblePollable &);

      static NoPossiblePollable *_downcast (CORBA::Exception *);
      static CORBA::Exception *_alloc (void);

      virtual CORBA::Exception *_tao_duplicate (void) const;

      virtual void _raise (void);

      virtual void _tao_encode (
          TAO_OutputCDR &
          ACE_ENV_ARG_DECL_NOT_USED
        ) const;
      
      virtual void _tao_decode (
          TAO_InputCDR &
          ACE_ENV_ARG_DECL_NOT_USED
        );
      
      
    };


#endif /* end #if !defined */
    
    
#if !defined (_CORBA_POLLABLESET_UNKNOWNPOLLABLE_CH_)
#define _CORBA_POLLABLESET_UNKNOWNPOLLABLE_CH_
    
    class TAO_Export UnknownPollable : public CORBA::UserException
    {
    public:
      
      UnknownPollable (void);
      UnknownPollable (const UnknownPollable &);
      ~UnknownPollable (void);

      UnknownPollable &operator= (const UnknownPollable &);

      static UnknownPollable *_downcast (CORBA::Exception *);
      static CORBA::Exception *_alloc (void);

      virtual CORBA::Exception *_tao_duplicate (void) const;

      virtual void _raise (void);

      virtual void _tao_encode (
          TAO_OutputCDR &
          ACE_ENV_ARG_DECL_NOT_USED
        ) const;
      
      virtual void _tao_decode (
          TAO_InputCDR &
          ACE_ENV_ARG_DECL_NOT_USED
        );
      
      
    };


#endif /* end #if !defined */
    
    virtual ::CORBA::DIIPollable_ptr create_dii_pollable (
        
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    virtual void add_pollable (
        CORBA::Pollable_ptr potential
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    virtual ::CORBA::Pollable_ptr poll (
        CORBA::ULong timeout
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , CORBA::PollableSet::NoPossiblePollable
      )) = 0;
    
    virtual void remove (
        CORBA::Pollable_ptr potential
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , CORBA::PollableSet::UnknownPollable
      )) = 0;
    
    virtual CORBA::UShort number_left (
        
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    virtual void *_tao_QueryInterface (ptr_arith_t type);
    
    virtual const char* _interface_repository_id (void) const;

  protected:
    PollableSet (void);
    
    virtual ~PollableSet (void);
  
  private:
    PollableSet (const PollableSet &);
    void operator= (const PollableSet &);
  };
  
  
#endif /* end #if !defined */
  
  
}
TAO_NAMESPACE_CLOSE // module CORBA


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
