// This may look like C, but it's really -*- C++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO
//
// = FILENAME
//    object.h
//
// = DESCRIPTION
//     Header file for Win32 interface to CORBA's base "Object" type.
//
//     A "Object" is an entity that can be the target of an invocation
//     using an ORB.  All CORBA objects provide this functionality.
//     See the CORBA 2.0 specification for details.
//
// = AUTHOR
//     Portions Copyright 1994-1995 by Sun Microsystems Inc.
//     Portions Copyright 1997 by Washington University
//
// ============================================================================

#if !defined (CORBA_OBJECT_H)
#  define CORBA_OBJECT_H

class TAO_ServantBase;
class STUB_Object;

class TAO_Export CORBA_Object : public TAO_IUnknown
{
public:
  static CORBA::Object_ptr _duplicate (CORBA::Object_ptr obj);
  // increment the ref count

  static CORBA::Object_ptr _nil (void);
  // return a NUL object

  // These calls correspond to over-the-wire operations, or at least
  // do so in many common cases.  The normal implementation assumes a
  // particular simple, efficient, protocol-neutral interface for
  // making such calls, but may be overridden when it appears
  // appropriate.

  virtual CORBA::InterfaceDef_ptr _get_interface (CORBA::Environment &);
  // Interface repository related operation

  virtual CORBA::Boolean _is_a (const CORBA::Char *logical_type_id,
                                CORBA::Environment &);
  // determine if we are of the type specified by the "logical_type_id"

  virtual const char* _interface_repository_id (void) const;
  // The repository ID for the most derived class, this is an
  // implementation method and does no remote invocations!

  virtual TAO_ServantBase *_servant (void) const;
  // return the associated servant (if one exists)

  virtual CORBA::Boolean _is_collocated (void) const;
  // are we collocated with the servant?

  virtual CORBA::ImplementationDef_ptr _get_implementation (CORBA::Environment &);

  virtual CORBA::Boolean _non_existent (CORBA::Environment &);

  // The mapping for create_request is split into two forms,
  // corresponding to the two usage styles described in CORBA section
  // 6.2.1.
  //
  // The default implementation of this method uses the same simple,
  // multi-protocol remote invocation interface as is assumed by the
  // calls above ... that's how it can have a default implementation.

  virtual void _create_request (const CORBA::Char *operation,
                                CORBA::NVList_ptr arg_list,
                                CORBA::NamedValue_ptr result,
                                CORBA::Request_ptr &request,
                                CORBA::Flags req_flags,
                                CORBA::Environment &env);
  // DII operation to create a request

  virtual CORBA::Request_ptr _request (const CORBA::Char *operation,
                                       CORBA::Environment &env);
  // DII operation to create a request

  // These two rely on the representation of the object reference's
  // private state.  Since that changes easily (when different ORB
  // protocols are in use) there is no default implementation.

  virtual CORBA::ULong _hash (CORBA::ULong maximum,
                              CORBA::Environment &env);

  virtual CORBA::Boolean _is_equivalent (CORBA::Object_ptr other_obj,
                                         CORBA::Environment &env);

  // = COM-like IUnknown Support
  //
  // This class is intended to aggregate or be contained with others,
  // which in combination provide all requisite CORBA/COM support.

  ULONG AddRef (void);
  ULONG Release (void);
  TAO_HRESULT QueryInterface (REFIID riid,
                              void **ppv);

  CORBA_Object (STUB_Object *p = 0,
                TAO_ServantBase *servant = 0,
                CORBA::Boolean collocated = CORBA::B_FALSE);
  // constructor

  virtual ~CORBA_Object (void);
  // destructor

  virtual TAO_ObjectKey *_key (CORBA::Environment &env);
  // Return the object key as an out parameter.  Caller should release
  // return value when finished with it.

  virtual STUB_Object *stubobj (CORBA::Environment &env);
  // get the underlying stub object

  // = Non-standard

  void _set_parent (STUB_Object *p);
  // Set the protocol proxy object.

  STUB_Object *_get_parent (void) const;
  // Get the protocol proxy object.

protected:
  TAO_ServantBase *servant_;
  // Servant pointer.  It is 0 except for collocated objects.

  CORBA::Boolean is_collocated_;
  // Flag to indicate collocation.  It is 0 except for collocated
  // objects.

private:
  STUB_Object *parent_;
  // Pointer to the protocol-specific "object" containing important
  // profiling information regarding this proxy.
  //
  // This used to be a TAO_IUnknown, but that seemed overtly general.
  // It's changed to a STUB_Object to make the relationship of the
  // target more explicit and sensible.

  ACE_SYNCH_MUTEX IUnknown_lock_;
  // Mutex to protect reference counting stuff.

  u_int refcount_;
  // Number of outstanding references to this object.

  // = Unimplemented methods
  CORBA_Object (const CORBA_Object &);
  CORBA_Object &operator = (const CORBA_Object &);
};

class TAO_Export CORBA_Object_var
{
public:
  CORBA_Object_var (void); // default constructor
  CORBA_Object_var (CORBA::Object_ptr);
  CORBA_Object_var (const CORBA_Object_var &); // copy constructor
  ~CORBA_Object_var (void); // destructor

  CORBA_Object_var &operator= (CORBA::Object_ptr);
  CORBA_Object_var &operator= (const CORBA_Object_var &);
  CORBA::Object_ptr operator-> (void) const;

  operator const CORBA::Object_ptr &() const;
  operator CORBA::Object_ptr &();
  // in, inout, out, _retn
  CORBA::Object_ptr in (void) const;
  CORBA::Object_ptr &inout (void);
  CORBA::Object_ptr &out (void);
  CORBA::Object_ptr _retn (void);
  CORBA::Object_ptr ptr (void) const;

private:
  CORBA::Object_ptr ptr_;
};

class TAO_Export CORBA_Object_out
{
public:
  CORBA_Object_out (CORBA::Object_ptr &);
  CORBA_Object_out (CORBA_Object_var &);
  CORBA_Object_out (CORBA_Object_out &);
  CORBA_Object_out &operator= (CORBA_Object_out &);
  CORBA_Object_out &operator= (const CORBA_Object_var &);
  CORBA_Object_out &operator= (CORBA::Object_ptr);
  operator CORBA::Object_ptr &();
  CORBA::Object_ptr &ptr (void);
  CORBA::Object_ptr operator-> (void);

private:
  CORBA::Object_ptr &ptr_;
};

#if defined (__ACE_INLINE__)
# include "tao/Object.i"
#endif /* __ACE_INLINE__ */

#endif /* CORBA_OBJECT_H */
