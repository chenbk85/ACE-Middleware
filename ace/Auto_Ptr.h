/* -*- C++ -*- */
// $Id$


// ============================================================================
//
// = LIBRARY
//    ace
// 
// = FILENAME
//    Auto_Ptr.h
//
// = AUTHOR
//    Doug Schmidt, based on code from Jack Reeves (jack@fx.com) and 
//    Dr. Harald M. Mueller (mueller@garwein.hai.siemens.co.at)
// 
// ============================================================================

#if !defined (ACE_AUTO_PTR_H)
#define ACE_AUTO_PTR_H

#include "ace/ACE.h"

template <class X>
class ACE_Auto_Basic_Ptr 
  // = TITLE
  //     Implements the draft C++ standard ACE_Auto_Ptr abstraction.
  //     This class allows one to work on non-object (basic) types
{
public:
  // = Initialization and termination methods
  ACE_Auto_Basic_Ptr (X *p = 0);
  ACE_Auto_Basic_Ptr (ACE_Auto_Basic_Ptr<X> &ap);
  ~ACE_Auto_Basic_Ptr (void);
  void operator= (ACE_Auto_Basic_Ptr<X> &rhs);

  // = Accessor methods.
  X &operator *() const;
  X *get (void) const;
  X *release (void);
  X *reset (X *p);

  static void remove (X* &x);

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

protected:
  X *p_;
};

template <class X>
class ACE_Auto_Ptr : public ACE_Auto_Basic_Ptr <X>
  // = TITLE
  //     Implements the draft C++ standard ACE_Auto_Ptr abstraction.
{
public:
  // = Initialization and termination methods
  ACE_Auto_Ptr (X *p = 0);

  X *operator-> () const;  
};


template<class X>
class ACE_Auto_Basic_Array_Ptr 
  // = TITLE
  //     Implements an extension to the draft C++ standard ACE_Auto_Ptr
  //     abstraction.  This class allows one to work on non-object
  //     (basic) types
{
public:
  // = Initialization and termination methods.
  ACE_Auto_Basic_Array_Ptr (X *p = 0);
  ACE_Auto_Basic_Array_Ptr (ACE_Auto_Basic_Array_Ptr<X> &ap);
  ~ACE_Auto_Basic_Array_Ptr (void);
  void operator= (ACE_Auto_Basic_Array_Ptr<X> &rhs);

  // = Accessor methods.
  X &operator* ();
  X &operator[] (int i);
  X operator[] (int i) const;
  X *get (void) const;
  X *release (void);
  X *reset (X *p);

  static void remove (X *&x);

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

protected:
  X *p_;
};

template<class X>
class ACE_Auto_Array_Ptr : public ACE_Auto_Basic_Array_Ptr<X>
  // = TITLE
  //     Implements an extension to the draft C++ standard ACE_Auto_Ptr
  //     abstraction.
{
public:
  // = Initialization and termination methods.
  ACE_Auto_Array_Ptr (X *p = 0);

  X *operator-> () const;
};

#if defined (__ACE_INLINE__)
#include "ace/Auto_Ptr.i"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Auto_Ptr.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Auto_Ptr.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* ACE_AUTO_PTR_H */
