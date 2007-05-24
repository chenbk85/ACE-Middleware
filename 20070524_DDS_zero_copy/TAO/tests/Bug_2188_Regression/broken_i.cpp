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
// be/be_codegen.cpp:932

#include "broken_i.h"



ServerAdmin_i::ServerAdmin_i (ArrayTest_ptr target)
  :target_ (ArrayTest::_duplicate(target))
{
}

ServerAdmin_i::~ServerAdmin_i (void)
{
}

ArrayTest_ptr
ServerAdmin_i::target(void)
{
  return ArrayTest::_duplicate(target_.in());
}

void
ServerAdmin_i::shutdown (void)
{
  int argc = 0;
  char ** argv = 0;
  CORBA::ORB_var orb = CORBA::ORB_init (argc, argv);
  orb->shutdown();
}

// Implementation skeleton constructor
ArrayTest_i::ArrayTest_i (void)
  :longArray_ (LongArray_alloc()),
   ulongArray_ (ULongArray_alloc()),
   stringArray_ (StringArray_alloc()),
   shortArray_ (ShortArray_alloc()),
   ushortArray_ (UShortArray_alloc()),
   charArray_ (CharArray_alloc()),
   octetArray_ (OctetArray_alloc()),
   doubleArray_ (DoubleArray_alloc()),
   floatArray_ (FloatArray_alloc()),
   bucketArray_ (BucketArray_alloc()),
   accountArray_ (AccountArray_alloc()),
   booleanArray_ (BooleanArray_alloc()),
   longArrayArray_ (LongArrayArray_alloc()),
   enumArray_ (MyEnumArray_alloc())
{
}

// Implementation skeleton destructor
ArrayTest_i::~ArrayTest_i (void)
{
  LongArray_free (longArray_);
  ULongArray_free (ulongArray_);
  StringArray_free (stringArray_);
  ShortArray_free (shortArray_);
  UShortArray_free (ushortArray_);
  CharArray_free (charArray_);
  OctetArray_free (octetArray_);
  DoubleArray_free (doubleArray_);
  FloatArray_free (floatArray_);
  BucketArray_free (bucketArray_);
  AccountArray_free (accountArray_);
  BooleanArray_free (booleanArray_);
  LongArrayArray_free (longArrayArray_);
  MyEnumArray_free (enumArray_);
}

::LongArray_slice * ArrayTest_i::longArrayOp (
    const ::LongArray p1,
    ::LongArray p2,
    ::LongArray_out p3
  )
{
  ::LongArray_copy(p3,p2);
  return LongArray_dup(p1);
}

::StringArray_slice * ArrayTest_i::stringArrayOp (
    const ::StringArray p1,
    ::StringArray p2,
    ::StringArray_out p3
  )
{
  // Add your implementation here
  ::StringArray_copy(p3,p2);
  return StringArray_dup(p1);
}

::ShortArray_slice * ArrayTest_i::shortArrayOp (
    const ::ShortArray p1,
    ::ShortArray p2,
    ::ShortArray_out p3
  )
{
  ::ShortArray_copy(p3,p2);
  return ShortArray_dup(p1);
  // Add your implementation here
}

::UShortArray_slice * ArrayTest_i::ushortArrayOp (
    const ::UShortArray p1,
    ::UShortArray p2,
    ::UShortArray_out p3
  )
{
  // Add your implementation here
  ::UShortArray_copy(p3,p2);
  return UShortArray_dup(p1);
}

::CharArray_slice * ArrayTest_i::charArrayOp (
    const ::CharArray p1,
    ::CharArray p2,
    ::CharArray_out p3
  )
{
  // Add your implementation here
  ::CharArray_copy(p3,p2);
  return CharArray_dup(p1);

}

::OctetArray_slice * ArrayTest_i::octetArrayOp (
    const ::OctetArray p1,
    ::OctetArray p2,
    ::OctetArray_out p3
  )
{
  // Add your implementation here
  ::OctetArray_copy(p3,p2);
  return OctetArray_dup(p1);
}

::DoubleArray_slice * ArrayTest_i::doubleArrayOp (
    const ::DoubleArray p1,
    ::DoubleArray p2,
    ::DoubleArray_out p3
  )
{
  // Add your implementation here
  ::DoubleArray_copy(p3,p2);
  return DoubleArray_dup(p1);
}

::LongArray_slice * ArrayTest_i::a_longArray (

  )
{
  // Add your implementation here
  return LongArray_dup(longArray_);
}

void ArrayTest_i::a_longArray (
    const ::LongArray a_longArray
  )
{
  // Add your implementation here
  LongArray_copy(longArray_,a_longArray);
}

::ULongArray_slice * ArrayTest_i::a_ulongArray (

  )
{
  // Add your implementation here
  return ULongArray_dup(ulongArray_);
}

void ArrayTest_i::a_ulongArray (
    const ::ULongArray a_ulongArray
  )
{
  // Add your implementation here
  ULongArray_copy (ulongArray_,a_ulongArray);
}

::StringArray_slice * ArrayTest_i::a_stringArray (

  )
{
  // Add your implementation here
  return StringArray_dup (stringArray_);
}

void ArrayTest_i::a_stringArray (
    const ::StringArray a_stringArray
  )
{
  // Add your implementation here
  StringArray_copy (stringArray_,a_stringArray);
}

::ShortArray_slice * ArrayTest_i::a_shortArray (

  )
{
  // Add your implementation here
  return ShortArray_dup (shortArray_);
}

void ArrayTest_i::a_shortArray (
    const ::ShortArray a_shortArray
  )
{
  // Add your implementation here
  ShortArray_copy (shortArray_,a_shortArray);
}

::UShortArray_slice * ArrayTest_i::a_ushortArray (

  )
{
  // Add your implementation here
  return UShortArray_dup (ushortArray_);
}

void ArrayTest_i::a_ushortArray (
    const ::UShortArray a_ushortArray
  )
{
  // Add your implementation here
  UShortArray_copy (ushortArray_,a_ushortArray);
}

CORBA::Char ArrayTest_i::a_char (

  )
{
  // Add your implementation here
  return char_;
}

void ArrayTest_i::a_char (
    ::CORBA::Char a_char
  )
{
  // Add your implementation here
  char_ = a_char;
}

::CharArray_slice * ArrayTest_i::a_charArray (

  )
{
  return CharArray_dup (charArray_);
}

void ArrayTest_i::a_charArray (
    const ::CharArray a_charArray
  )
{
  // Add your implementation here
  CharArray_copy (charArray_,a_charArray);
}

::OctetArray_slice * ArrayTest_i::a_octetArray (

  )
{
  // Add your implementation here
  return OctetArray_dup (octetArray_);
}

void ArrayTest_i::a_octetArray (
    const ::OctetArray a_octetArray
  )
{
  // Add your implementation here
  OctetArray_copy (octetArray_,a_octetArray);
}

::DoubleArray_slice * ArrayTest_i::a_doubleArray (

  )
{
  // Add your implementation here
  return DoubleArray_dup (doubleArray_);
}

void ArrayTest_i::a_doubleArray (
    const ::DoubleArray a_doubleArray
  )
{
  // Add your implementation here
  DoubleArray_copy (doubleArray_,a_doubleArray);
}

::FloatArray_slice * ArrayTest_i::a_floatArray (

  )
{
  // Add your implementation here
  return FloatArray_dup (floatArray_);
}

void ArrayTest_i::a_floatArray (
    const ::FloatArray a_floatArray
  )
{
  // Add your implementation here
  FloatArray_copy (floatArray_,a_floatArray);
}

::BucketArray_slice * ArrayTest_i::a_bucketArray (

  )
{
  // Add your implementation here
  return BucketArray_dup (bucketArray_);
}

void ArrayTest_i::a_bucketArray (
    const ::BucketArray a_bucketArray
  )
{
  // Add your implementation here
  BucketArray_copy (bucketArray_,a_bucketArray);
}

::AccountArray_slice * ArrayTest_i::a_accountArray (

  )
{
  // Add your implementation here
  return AccountArray_dup (accountArray_);
}

void ArrayTest_i::a_accountArray (
    const ::AccountArray a_accountArray
  )
{
  // Add your implementation here
  AccountArray_copy (accountArray_,a_accountArray);
}

::BooleanArray_slice * ArrayTest_i::a_booleanArray (

  )
{
  // Add your implementation here
  return BooleanArray_dup (booleanArray_);
}

void ArrayTest_i::a_booleanArray (
    const ::BooleanArray a_booleanArray
  )
{
  // Add your implementation here
  BooleanArray_copy (booleanArray_,a_booleanArray);
}

::LongArrayArray_slice * ArrayTest_i::a_longArrayArray (

  )
{
  // Add your implementation here
  return LongArrayArray_dup (longArrayArray_);
}

void ArrayTest_i::a_longArrayArray (
    const ::LongArrayArray a_longArrayArray
  )
{
  // Add your implementation here
  LongArrayArray_copy (longArrayArray_,a_longArrayArray);
}

::MyEnumArray_slice * ArrayTest_i::a_myEnumArray (

  )
{
  // Add your implementation here
  return MyEnumArray_dup (enumArray_);
}

void ArrayTest_i::a_myEnumArray (
    const ::MyEnumArray a_myEnumArray
  )
{
  // Add your implementation here
  MyEnumArray_copy (enumArray_,a_myEnumArray);
}
