// This may look like C, but it's really -*- C++ -*-

// ============================================================================
//
// = LIBRARY
//    TAO
// 
// = FILENAME
//    nvlist.h
//
// = DESCRIPTION
//     Header file for Win32 interface to CORBA's base "Object" type.
//
//     A "Object" is an entity that can be the target of an invocation
//     using an ORB.  All CORBA objects provide this functionality.
//     See the CORBA 2.0 specification for details.
//
// = AUTHOR
//     Copyright 1994-1995 by Sun Microsystems Inc.
// 
// ============================================================================

#if !defined (CORBA_OBJECT_H)
#  define CORBA_OBJECT_H

#  include "ace/OS.h"

#  include "request.h"
#  include "optable.h"

void CORBA_release (CORBA_Object_ptr obj);
CORBA_Boolean CORBA_is_nil (CORBA_Object_ptr obj);

extern const IID IID_CORBA_Object;

class ACE_Svc_Export CORBA_Object : public IUnknown
{
public:
  static CORBA_Object_ptr _duplicate (CORBA_Object_ptr obj);
  static CORBA_Object_ptr _nil (void);

  // These calls correspond to over-the-wire operations, or at least
  // do so in many common cases.  The normal implementation assumes a
  // particular simple, efficient, protocol-neutral interface for
  // making such calls, but may be overridden when it appears
  // appropriate.

  virtual CORBA_InterfaceDef_ptr __stdcall _get_interface (CORBA_Environment &);

  virtual CORBA_Boolean __stdcall _is_a (const CORBA_Char *logical_type_id,
                                         CORBA_Environment &);

  virtual CORBA_ImplementationDef_ptr __stdcall _get_implementation (CORBA_Environment &);

  virtual CORBA_Boolean __stdcall _non_existent (CORBA_Environment &);

  // The mapping for create_request is split into two forms,
  // corresponding to the two usage styles described in CORBA section
  // 6.2.1.
  //
  // The default implementation of this method uses the same simple,
  // multi-protocol remote invocation interface as is assumed by the
  // calls above ... that's how it can have a default implementation.

  virtual void __stdcall _create_request (const CORBA_Char *operation,
					  CORBA_NVList_ptr arg_list,
					  CORBA_NamedValue_ptr result,
					  CORBA_Request_ptr &request,
					  CORBA_Flags req_flags,
					  CORBA_Environment &env);

  virtual CORBA_Request_ptr __stdcall _request (const CORBA_Char *operation,
                                                CORBA_Environment &env);
    
  // These two rely on the representation of the object reference's
  // private state.  Since that changes easily (when different ORB
  // protocols are in use) there is no default implementation.

  virtual CORBA_ULong __stdcall _hash (CORBA_ULong maximum,
                                       CORBA_Environment &env);

  virtual CORBA_Boolean __stdcall _is_equivalent (CORBA_Object_ptr other_obj,
                                                  CORBA_Environment &env);
  // Stuff required for COM IUnknown support ... this class is
  // intended to aggregate or be contained with others, which in
  // combination provide all requisite CORBA/COM support.

  ULONG __stdcall AddRef (void);
  ULONG __stdcall Release (void);
  HRESULT __stdcall QueryInterface (REFIID riid,
                                    void **ppv);

  CORBA_Object (IUnknown *p = 0);
  virtual ~CORBA_Object (void);

  virtual int find (const CORBA_String &opname, 
		    TAO_Skeleton &skelfunc);

  virtual int bind (const CORBA_String &opname, 
		    const TAO_Skeleton skel_ptr);
  // Register a CORBA IDL operation name.  TAO extension that
  // retrieves the name (key) assigned to the object.
    
  virtual CORBA_String _get_name (CORBA_Environment &env);
  // @@ Can we change the name of the <get_subclass> method to
  // something more meaningful?
  virtual void *get_subclass (void);
  
  // = ORB ASSOCIATION MAINTAINENCE
  void orb(CORBA_ORB_ptr orb);
  // Set the ORB with which we're associated.
  CORBA_ORB_ptr orb(void) const;
  // Get the ORB with which we're associated.

protected:
  TAO_Operation_Table *optable_;

  void *sub_;  
  // keeps track of the most derived class.

  void set_parent (IUnknown *p);

private:
  IUnknown *parent_;
  // Still confused regarding this IUnknown stuff.
  
  CORBA_ORB_ptr orb_;
  // Pointer to the ORB with which this object is associated.

  // these two are not provided!

  CORBA_Object (const CORBA_Object &);
  CORBA_Object &operator = (const CORBA_Object &);
};

// XXX need CORBA_Object_var class typedef

#if defined(__ACE_INLINE__)
#  include "object.i"
#endif

#endif /* CORBA_OBJECT_H */
