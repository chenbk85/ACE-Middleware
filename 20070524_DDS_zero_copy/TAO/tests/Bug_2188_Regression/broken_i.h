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
// be/be_codegen.cpp:866

#ifndef BROKEN_I_H_
#define BROKEN_I_H_

#include "brokenS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class ServerAdmin_i : public virtual POA_ServerAdmin
{
public:
  ServerAdmin_i (ArrayTest_ptr target);
  virtual ~ServerAdmin_i (void);
  ArrayTest_ptr target(void);

  void shutdown (void);
private:
  ArrayTest_var target_;

};

class  ArrayTest_i : public virtual POA_ArrayTest
{
private:
  LongArray_slice * longArray_;
  ULongArray_slice *  ulongArray_;
  StringArray_slice * stringArray_;
  ShortArray_slice * shortArray_;
  UShortArray_slice * ushortArray_;
  CharArray_slice * charArray_;
  OctetArray_slice * octetArray_;
  DoubleArray_slice * doubleArray_;
  FloatArray_slice * floatArray_;
  BucketArray_slice * bucketArray_;
  AccountArray_slice * accountArray_;
  BooleanArray_slice * booleanArray_;
  LongArrayArray_slice * longArrayArray_;
  MyEnumArray_slice * enumArray_;

  CORBA::Char char_;
public:
  //Constructor
  ArrayTest_i (void);

  //Destructor
  virtual ~ArrayTest_i (void);

  virtual
  ::LongArray_slice * longArrayOp (
      const ::LongArray p1,
      ::LongArray p2,
      ::LongArray_out p3
    );

  virtual
  ::StringArray_slice * stringArrayOp (
      const ::StringArray p1,
      ::StringArray p2,
      ::StringArray_out p3
    );

  virtual
  ::ShortArray_slice * shortArrayOp (
      const ::ShortArray p1,
      ::ShortArray p2,
      ::ShortArray_out p3
    );

  virtual
  ::UShortArray_slice * ushortArrayOp (
      const ::UShortArray p1,
      ::UShortArray p2,
      ::UShortArray_out p3
    );

  virtual
  ::CharArray_slice * charArrayOp (
      const ::CharArray p1,
      ::CharArray p2,
      ::CharArray_out p3
    );

  virtual
  ::OctetArray_slice * octetArrayOp (
      const ::OctetArray p1,
      ::OctetArray p2,
      ::OctetArray_out p3
    );

  virtual
  ::DoubleArray_slice * doubleArrayOp (
      const ::DoubleArray p1,
      ::DoubleArray p2,
      ::DoubleArray_out p3
    );

  virtual
  ::LongArray_slice * a_longArray (

    );

  virtual
  void a_longArray (
      const ::LongArray a_longArray
    );

  virtual
  ::ULongArray_slice * a_ulongArray (

    );

  virtual
  void a_ulongArray (
      const ::ULongArray a_ulongArray
    );

  virtual
  ::StringArray_slice * a_stringArray (

    );

  virtual
  void a_stringArray (
      const ::StringArray a_stringArray
    );

  virtual
  ::ShortArray_slice * a_shortArray (

    );

  virtual
  void a_shortArray (
      const ::ShortArray a_shortArray
    );

  virtual
  ::UShortArray_slice * a_ushortArray (

    );

  virtual
  void a_ushortArray (
      const ::UShortArray a_ushortArray
    );

  virtual
  CORBA::Char a_char (

    );

  virtual
  void a_char (
      ::CORBA::Char a_char
    );

  virtual
  ::CharArray_slice * a_charArray (

    );

  virtual
  void a_charArray (
      const ::CharArray a_charArray
    );

  virtual
  ::OctetArray_slice * a_octetArray (

    );

  virtual
  void a_octetArray (
      const ::OctetArray a_octetArray
    );

  virtual
  ::DoubleArray_slice * a_doubleArray (

    );

  virtual
  void a_doubleArray (
      const ::DoubleArray a_doubleArray
    );

  virtual
  ::FloatArray_slice * a_floatArray (

    );

  virtual
  void a_floatArray (
      const ::FloatArray a_floatArray
    );

  virtual
  ::BucketArray_slice * a_bucketArray (

    );

  virtual
  void a_bucketArray (
      const ::BucketArray a_bucketArray
    );

  virtual
  ::AccountArray_slice * a_accountArray (

    );

  virtual
  void a_accountArray (
      const ::AccountArray a_accountArray
    );

  virtual
  ::BooleanArray_slice * a_booleanArray (

    );

  virtual
  void a_booleanArray (
      const ::BooleanArray a_booleanArray
    );

  virtual
  ::LongArrayArray_slice * a_longArrayArray (

    );

  virtual
  void a_longArrayArray (
      const ::LongArrayArray a_longArrayArray
    );

  virtual
  ::MyEnumArray_slice * a_myEnumArray (

    );

  virtual
  void a_myEnumArray (
      const ::MyEnumArray a_myEnumArray
    );
};


#endif /* BROKEN_I_H_  */
