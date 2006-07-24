// -*- C++ -*-
//
// $Id$

//=============================================================================
//
// = FILENAME
//     test_i.h
//
// = DESCRIPTION
//     Defines implementation classes for the interfaces
//
// = AUTHOR
//     Irfan Pyarali
//
//=============================================================================

#include "testS.h"

class Tie_i
{
public:
  // constructor - takes a POA and a value parameter
  Tie_i (CORBA::Long value);

  /// Destructor.
  virtual ~Tie_i (void);

  // Simple doit method
  virtual CORBA::Long doit (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

protected:

  CORBA::Long value_;
};

class A_i : public POA_A
{
public:
  // constructor - takes a POA and a value parameter
  A_i (CORBA::Long value,
       PortableServer::POA_ptr poa);

  // Simple doit method
  virtual CORBA::Long doit (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  // Returns the Default POA of this Servant object
  virtual PortableServer::POA_ptr _default_POA (ACE_ENV_SINGLE_ARG_DECL);

protected:

  CORBA::Long value_;

  PortableServer::POA_var poa_;
  // Default poa associated with this servant
};

class Outer_i
{
public:

  class B_i : public POA_Outer::B
  {
  public:
    // constructor - takes a POA and a value parameter
    B_i (CORBA::Long value,
         PortableServer::POA_ptr poa);

    // Simple doit method
    virtual CORBA::Long doit (ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC ((CORBA::SystemException));

    // Returns the Default POA of this Servant object
    virtual PortableServer::POA_ptr _default_POA (ACE_ENV_SINGLE_ARG_DECL);

  protected:

    CORBA::Long value_;

    PortableServer::POA_var poa_;
    // Default poa associated with this servant
  };

  class Inner_i
  {
  public:

    class C_i : public POA_Outer::Inner::C
    {
    public:
      // constructor - takes a POA and a value parameter
      C_i (CORBA::Long value,
           PortableServer::POA_ptr poa);

      // Simple doit method
      virtual CORBA::Long doit (ACE_ENV_SINGLE_ARG_DECL)
        ACE_THROW_SPEC ((CORBA::SystemException));

      // Returns the Default POA of this Servant object
      virtual PortableServer::POA_ptr _default_POA (ACE_ENV_SINGLE_ARG_DECL);

    protected:

      CORBA::Long value_;

      PortableServer::POA_var poa_;
      // Default poa associated with this servant
    };
  };
};
