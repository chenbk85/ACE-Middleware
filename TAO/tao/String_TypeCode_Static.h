// -*- C++ -*-

//=============================================================================
/**
 *  @file    String_TypeCode_Static.h
 *
 *  $Id$
 *
 *  Header file for static @c CORBA::tk_string or @c CORBA::tk_wstring
 *  @c CORBA::TypeCodes.
 *
 *  @author Ossama Othman <ossama@dre.vanderbilt.edu>
 */
//=============================================================================

#ifndef TAO_STRING_TYPECODE_STATIC_H
#define TAO_STRING_TYPECODE_STATIC_H

#include /**/ "ace/pre.h"

#include "tao/TypeCode.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Null_RefCount_Policy.h"


namespace TAO
{
  namespace TypeCode
  {
    template <class RefCountPolicy> class String;

    /**
     * @class String
     *
     * @brief @c CORBA::TypeCode implementation for OMG IDL string
     *        types.
     *
     * This class implements a @c CORBA::TypeCode for OMG IDL string
     * types, including @c wstring.
     */
    template<>
    class TAO_Export String<TAO::Null_RefCount_Policy>
      : public CORBA::TypeCode,
        private TAO::Null_RefCount_Policy
    {
    public:

      /// Constructor.
      String (CORBA::TCKind kind, CORBA::ULong length);

      /**
       * @name TAO-specific @c CORBA::TypeCode Methods
       *
       * Methods required by TAO's implementation of the
       * @c CORBA::TypeCode class.
       *
       * @see @c CORBA::TypeCode
       */
      //@{
      virtual bool tao_marshal (TAO_OutputCDR & cdr) const;
      virtual void tao_duplicate (void);
      virtual void tao_release (void);
      //@}

    protected:

      /**
       * @name @c TAO CORBA::TypeCode Template Methods
       *
       * @c CORBA::TypeCode template methods specific to @c tk_string
       * @c TypeCodes.
       *
       * @see @c CORBA::TypeCode
       */
      //@{
      virtual CORBA::Boolean equal_i (CORBA::TypeCode_ptr tc
                                      ACE_ENV_ARG_DECL) const;
      virtual CORBA::Boolean equivalent_i (CORBA::TypeCode_ptr tc
                                           ACE_ENV_ARG_DECL) const;
      virtual CORBA::TypeCode_ptr get_compact_typecode_i (
        ACE_ENV_SINGLE_ARG_DECL) const;
      virtual CORBA::ULong length_i (ACE_ENV_SINGLE_ARG_DECL) const;

    private:

      /// Length of the @c string.  A length of zero indicates an
      /// unbounded @c string.
      CORBA::ULong const length_;

    };

  }  // End namespace TypeCode
}  // End namespace TAO


#ifdef __ACE_INLINE__
# include "tao/String_TypeCode_Static.inl"
#endif  /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* TAO_STRING_TYPECODE_STATIC_H */
