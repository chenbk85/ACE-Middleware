// $Id$

/* -*- C++ -*- */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO ORB and the TAO IDL Compiler have been developed by Washington
// University Computer Science's Distributed Object Computing Group.
//
// Information on TAO is available at
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

ACE_INLINE
CORBA_Policy::CORBA_Policy (void) // default constructor
{}

ACE_INLINE
CORBA_Policy::CORBA_Policy (STUB_Object *objref,
                            TAO_ServantBase *_tao_servant,
                            CORBA::Boolean _tao_collocated)
  : CORBA_Object (objref, _tao_servant, _tao_collocated)
{}

ACE_INLINE
CORBA_Policy::~CORBA_Policy (void) // destructor
{}


#if !defined (_CORBA_Policy___VAR_CI_)
#define _CORBA_Policy___VAR_CI_

// *************************************************************
// Inline operations for class CORBA_Policy_var
// *************************************************************

ACE_INLINE
CORBA_Policy_var::CORBA_Policy_var (void) // default constructor
  : ptr_ (CORBA_Policy::_nil ())
{}

ACE_INLINE
CORBA_Policy_var::CORBA_Policy_var (CORBA_Policy_ptr p)
  : ptr_ (p)
{}

ACE_INLINE CORBA_Policy_ptr
CORBA_Policy_var::ptr (void) const
{
  return this->ptr_;
}

// copy constructor
ACE_INLINE
CORBA_Policy_var::CORBA_Policy_var (const CORBA_Policy_var &p)
  : ptr_ (CORBA_Policy::_duplicate (p.ptr ()))
{}

ACE_INLINE
CORBA_Policy_var::~CORBA_Policy_var (void)
{
  CORBA::release (this->ptr_);
}

ACE_INLINE CORBA_Policy_var &
CORBA_Policy_var::operator= (CORBA_Policy_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE CORBA_Policy_var &
CORBA_Policy_var::operator= (const CORBA_Policy_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = CORBA_Policy::_duplicate (p.ptr ());
  }
  return *this;
}

ACE_INLINE
CORBA_Policy_var::operator const CORBA_Policy_ptr &() const // cast
{
  return this->ptr_;
}

ACE_INLINE
CORBA_Policy_var::operator CORBA_Policy_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE CORBA_Policy_ptr
CORBA_Policy_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA_Policy_ptr
CORBA_Policy_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA_Policy_ptr &
CORBA_Policy_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE CORBA_Policy_ptr &
CORBA_Policy_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA_Policy::_nil ();
  return this->ptr_;
}

ACE_INLINE CORBA_Policy_ptr
CORBA_Policy_var::_retn (void)
{
  // yield ownership of managed obj reference
  CORBA_Policy_ptr val = this->ptr_;
  this->ptr_ = CORBA_Policy::_nil ();
  return val;
}


#endif /* end #if !defined */


#if !defined (_CORBA_Policy___OUT_CI_)
#define _CORBA_Policy___OUT_CI_

// *************************************************************
// Inline operations for class CORBA_Policy_out
// *************************************************************

ACE_INLINE
CORBA_Policy_out::CORBA_Policy_out (CORBA_Policy_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = CORBA_Policy::_nil ();
}

ACE_INLINE
CORBA_Policy_out::CORBA_Policy_out (CORBA_Policy_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA_Policy::_nil ();
}

ACE_INLINE
CORBA_Policy_out::CORBA_Policy_out (CORBA_Policy_out &p) // copy constructor
  : ptr_ (p.ptr_)
{}

ACE_INLINE CORBA_Policy_out &
CORBA_Policy_out::operator= (CORBA_Policy_out &p)
{
  this->ptr_ = p.ptr_;
  return *this;
}

ACE_INLINE CORBA_Policy_out &
CORBA_Policy_out::operator= (const CORBA_Policy_var &p)
{
  this->ptr_ = CORBA_Policy::_duplicate (p.ptr ());
  return *this;
}

ACE_INLINE CORBA_Policy_out &
CORBA_Policy_out::operator= (CORBA_Policy_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
CORBA_Policy_out::operator CORBA_Policy_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE CORBA_Policy_ptr &
CORBA_Policy_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE CORBA_Policy_ptr
CORBA_Policy_out::operator-> (void)
{
  return this->ptr_;
}


#endif /* end #if !defined */

// *************************************************************
// Inline operations for class CORBA_PolicyList_var
// *************************************************************

ACE_INLINE
CORBA_PolicyList_var::CORBA_PolicyList_var (void) // default constructor
  : ptr_ (0)
{}

ACE_INLINE
CORBA_PolicyList_var::CORBA_PolicyList_var (CORBA_PolicyList *p)
  : ptr_ (p)
{}

ACE_INLINE
CORBA_PolicyList_var::CORBA_PolicyList_var (const CORBA_PolicyList_var &p) // copy constructor
{
  if (p.ptr_)
    this->ptr_ = new CORBA_PolicyList(*p.ptr_);
  else
    this->ptr_ = 0;
}

ACE_INLINE
CORBA_PolicyList_var::~CORBA_PolicyList_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE CORBA_PolicyList_var &
CORBA_PolicyList_var::operator= (CORBA_PolicyList *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE CORBA_PolicyList_var &
CORBA_PolicyList_var::operator= (const CORBA_PolicyList_var &p) // deep copy
{
  if (this != &p)
  {
    delete this->ptr_;
    this->ptr_ = new CORBA_PolicyList (*p.ptr_);
  }
  return *this;
}

ACE_INLINE const CORBA_PolicyList *
CORBA_PolicyList_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA_PolicyList *
CORBA_PolicyList_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
CORBA_PolicyList_var::operator const CORBA_PolicyList &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
CORBA_PolicyList_var::operator CORBA_PolicyList &() // cast
{
  return *this->ptr_;
}

ACE_INLINE
CORBA_PolicyList_var::operator CORBA_PolicyList &() const// cast
{
  return *this->ptr_;
}

ACE_INLINE TAO_Object_Manager <CORBA_Policy >
CORBA_PolicyList_var::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

ACE_INLINE const CORBA_PolicyList &
CORBA_PolicyList_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE CORBA_PolicyList &
CORBA_PolicyList_var::inout (void)
{
  return *this->ptr_;
}

// mapping for variable size
ACE_INLINE CORBA_PolicyList *&
CORBA_PolicyList_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE CORBA_PolicyList *
CORBA_PolicyList_var::_retn (void)
{
  CORBA_PolicyList *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE CORBA_PolicyList *
CORBA_PolicyList_var::ptr (void) const
{
  return this->ptr_;
}

// *************************************************************
// Inline operations for class CORBA_PolicyList_out
// *************************************************************

ACE_INLINE
CORBA_PolicyList_out::CORBA_PolicyList_out (CORBA_PolicyList *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
CORBA_PolicyList_out::CORBA_PolicyList_out (CORBA_PolicyList_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
CORBA_PolicyList_out::CORBA_PolicyList_out (CORBA_PolicyList_out &p) // copy constructor
  : ptr_ (p.ptr_)
{}

ACE_INLINE CORBA_PolicyList_out &
CORBA_PolicyList_out::operator= (CORBA_PolicyList_out &p)
{
  this->ptr_ = p.ptr_;
  return *this;
}

ACE_INLINE CORBA_PolicyList_out &
CORBA_PolicyList_out::operator= (CORBA_PolicyList *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
CORBA_PolicyList_out::operator CORBA_PolicyList *&() // cast
{
  return this->ptr_;
}

ACE_INLINE CORBA_PolicyList *&
CORBA_PolicyList_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE CORBA_PolicyList *
CORBA_PolicyList_out::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE TAO_Object_Manager <CORBA_Policy >
CORBA_PolicyList_out::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}
