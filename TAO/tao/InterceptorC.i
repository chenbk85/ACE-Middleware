/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#if defined (TAO_HAS_INTERCEPTORS)

ACE_INLINE
PortableInterceptor::Cookie::Cookie (void) // default constructor
{}

ACE_INLINE
PortableInterceptor::Cookie::Cookie (TAO_Stub *objref, TAO_ServantBase *_tao_servant, CORBA::Boolean _tao_collocated) // constructor
  : CORBA_Object (objref, _tao_servant, _tao_collocated)
{}

ACE_INLINE
PortableInterceptor::Cookie::~Cookie (void) // destructor
{}


#if !defined (_PORTABLEINTERCEPTOR_COOKIE___VAR_CI_)
#define _PORTABLEINTERCEPTOR_COOKIE___VAR_CI_

// *************************************************************
// Inline operations for class PortableInterceptor::Cookie_var
// *************************************************************

ACE_INLINE
PortableInterceptor::Cookie_var::Cookie_var (void) // default constructor
  : ptr_ (PortableInterceptor::Cookie::_nil ())
{}

ACE_INLINE
PortableInterceptor::Cookie_var::Cookie_var (PortableInterceptor::Cookie_ptr p)
  : ptr_ (p)
{}

ACE_INLINE PortableInterceptor::Cookie_ptr
PortableInterceptor::Cookie_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
PortableInterceptor::Cookie_var::Cookie_var (const PortableInterceptor::Cookie_var &p) // copy constructor
  : ptr_ (PortableInterceptor::Cookie::_duplicate (p.ptr ()))
{}

ACE_INLINE
PortableInterceptor::Cookie_var::~Cookie_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

ACE_INLINE PortableInterceptor::Cookie_var &
PortableInterceptor::Cookie_var::operator= (PortableInterceptor::Cookie_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE PortableInterceptor::Cookie_var &
PortableInterceptor::Cookie_var::operator= (const PortableInterceptor::Cookie_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = PortableInterceptor::Cookie::_duplicate (p.ptr ());
  }
  return *this;
}

ACE_INLINE
PortableInterceptor::Cookie_var::operator const PortableInterceptor::Cookie_ptr &() const // cast
{
  return this->ptr_;
}

ACE_INLINE
PortableInterceptor::Cookie_var::operator PortableInterceptor::Cookie_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::Cookie_ptr
PortableInterceptor::Cookie_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::Cookie_ptr
PortableInterceptor::Cookie_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::Cookie_ptr &
PortableInterceptor::Cookie_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::Cookie_ptr &
PortableInterceptor::Cookie_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = PortableInterceptor::Cookie::_nil ();
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::Cookie_ptr
PortableInterceptor::Cookie_var::_retn (void)
{
  // yield ownership of managed obj reference
  PortableInterceptor::Cookie_ptr val = this->ptr_;
  this->ptr_ = PortableInterceptor::Cookie::_nil ();
  return val;
}


#endif /* end #if !defined */


#if !defined (_PORTABLEINTERCEPTOR_COOKIE___OUT_CI_)
#define _PORTABLEINTERCEPTOR_COOKIE___OUT_CI_

// *************************************************************
// Inline operations for class PortableInterceptor::Cookie_out
// *************************************************************

ACE_INLINE
PortableInterceptor::Cookie_out::Cookie_out (PortableInterceptor::Cookie_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = PortableInterceptor::Cookie::_nil ();
}

ACE_INLINE
PortableInterceptor::Cookie_out::Cookie_out (PortableInterceptor::Cookie_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = PortableInterceptor::Cookie::_nil ();
}

ACE_INLINE
PortableInterceptor::Cookie_out::Cookie_out (const PortableInterceptor::Cookie_out &p) // copy constructor
  : ptr_ (ACE_const_cast (PortableInterceptor::Cookie_out&,p).ptr_)
{}

ACE_INLINE PortableInterceptor::Cookie_out &
PortableInterceptor::Cookie_out::operator= (const PortableInterceptor::Cookie_out &p)
{
  this->ptr_ = ACE_const_cast (PortableInterceptor::Cookie_out&,p).ptr_;
  return *this;
}

ACE_INLINE PortableInterceptor::Cookie_out &
PortableInterceptor::Cookie_out::operator= (const PortableInterceptor::Cookie_var &p)
{
  this->ptr_ = PortableInterceptor::Cookie::_duplicate (p.ptr ());
  return *this;
}

ACE_INLINE PortableInterceptor::Cookie_out &
PortableInterceptor::Cookie_out::operator= (PortableInterceptor::Cookie_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
PortableInterceptor::Cookie_out::operator PortableInterceptor::Cookie_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::Cookie_ptr &
PortableInterceptor::Cookie_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::Cookie_ptr
PortableInterceptor::Cookie_out::operator-> (void)
{
  return this->ptr_;
}


#endif /* end #if !defined */


#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_OBJECT_SEQUENCE_PORTABLEINTERCEPTOR_COOKIES_CI_)
#define __TAO_UNBOUNDED_OBJECT_SEQUENCE_PORTABLEINTERCEPTOR_COOKIES_CI_

  ACE_INLINE PortableInterceptor::Cookie **
  PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::allocbuf (CORBA::ULong nelems)
  {
    PortableInterceptor::Cookie **buf = 0;

    ACE_NEW_RETURN (buf, PortableInterceptor::Cookie*[nelems], 0);

    for (CORBA::ULong i = 0; i < nelems; i++)
      buf[i] = PortableInterceptor::Cookie::_nil ();

    return buf;
  }

  ACE_INLINE void
  PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::freebuf (PortableInterceptor::Cookie **buffer)
  {
    if (buffer == 0)
      return;
    delete[] buffer;
  }

  ACE_INLINE
  PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies (void)
  {
  }

  ACE_INLINE
  PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies (CORBA::ULong maximum)
    : TAO_Unbounded_Base_Sequence (maximum, PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::allocbuf (maximum))
  {
  }

  ACE_INLINE
  PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies (CORBA::ULong maximum,
    CORBA::ULong length,
    PortableInterceptor::Cookie* *value,
    CORBA::Boolean release)
  : TAO_Unbounded_Base_Sequence (maximum, length, value, release)
  {
  }

  ACE_INLINE
  PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies(const PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies &rhs)
    : TAO_Unbounded_Base_Sequence (rhs)
  {
    PortableInterceptor::Cookie **tmp1 = PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::allocbuf (this->maximum_);
    PortableInterceptor::Cookie ** const tmp2 = ACE_reinterpret_cast (PortableInterceptor::Cookie ** ACE_CAST_CONST, rhs.buffer_);

    for (CORBA::ULong i = 0; i < rhs.length_; ++i)
      tmp1[i] = PortableInterceptor::Cookie::_duplicate (tmp2[i]);

    this->buffer_ = tmp1;
  }

  ACE_INLINE PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies &
  PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::operator= (const PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies &rhs)
  {
    if (this == &rhs)
      return *this;

    if (this->release_)
    {
      PortableInterceptor::Cookie **tmp = ACE_reinterpret_cast (PortableInterceptor::Cookie **, this->buffer_);

      for (CORBA::ULong i = 0; i < this->length_; ++i)
      {
        CORBA::release (tmp[i]);
        tmp[i] = PortableInterceptor::Cookie::_nil ();
      }
      if (this->maximum_ < rhs.maximum_)
      {
        PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::freebuf (tmp);
        this->buffer_ = PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::allocbuf (rhs.maximum_);
      }
    }
    else
      this->buffer_ = PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::allocbuf (rhs.maximum_);

    TAO_Unbounded_Base_Sequence::operator= (rhs);

    PortableInterceptor::Cookie **tmp1 = ACE_reinterpret_cast (PortableInterceptor::Cookie **, this->buffer_);
    PortableInterceptor::Cookie ** const tmp2 = ACE_reinterpret_cast (PortableInterceptor::Cookie ** ACE_CAST_CONST, rhs.buffer_);

    for (CORBA::ULong i = 0; i < rhs.length_; ++i)
      tmp1[i] = PortableInterceptor::Cookie::_duplicate (tmp2[i]);

    return *this;
  }

  ACE_INLINE TAO_Object_Manager<PortableInterceptor::Cookie,PortableInterceptor::Cookie_var>
  PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::operator[] (CORBA::ULong index) const
  // read-write accessor
  {
    ACE_ASSERT (index < this->maximum_);
    PortableInterceptor::Cookie ** const tmp = ACE_reinterpret_cast (PortableInterceptor::Cookie ** ACE_CAST_CONST, this->buffer_);
    return TAO_Object_Manager<PortableInterceptor::Cookie,PortableInterceptor::Cookie_var> (tmp + index, this->release_);
  }

  ACE_INLINE PortableInterceptor::Cookie* *
  PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::get_buffer (CORBA::Boolean orphan)
  {
    PortableInterceptor::Cookie **result = 0;
    if (orphan == 0)
    {
      // We retain ownership.
      if (this->buffer_ == 0)
      {
        result = PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::allocbuf (this->maximum_);
        this->buffer_ = result;
      }
      else
      {
        result = ACE_reinterpret_cast (PortableInterceptor::Cookie**, this->buffer_);
      }
    }
    else // if (orphan == 1)
    {
      if (this->release_ != 0)
      {
        // We set the state back to default and relinquish
        // ownership.
        result = ACE_reinterpret_cast(PortableInterceptor::Cookie**,this->buffer_);
        this->maximum_ = 0;
        this->length_ = 0;
        this->buffer_ = 0;
        this->release_ = 0;
      }
    }
    return result;
  }

  ACE_INLINE const PortableInterceptor::Cookie* *
  PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::get_buffer (void) const
  {
    return ACE_reinterpret_cast(const PortableInterceptor::Cookie ** ACE_CAST_CONST, this->buffer_);
  }


#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */

#if !defined (_PORTABLEINTERCEPTOR_COOKIES_CI_)
#define _PORTABLEINTERCEPTOR_COOKIES_CI_

// *************************************************************
// Inline operations for class PortableInterceptor::Cookies_var
// *************************************************************

ACE_INLINE
PortableInterceptor::Cookies_var::Cookies_var (void) // default constructor
  : ptr_ (0)
{}

ACE_INLINE
PortableInterceptor::Cookies_var::Cookies_var (PortableInterceptor::Cookies *p)
  : ptr_ (p)
{}

ACE_INLINE
PortableInterceptor::Cookies_var::Cookies_var (const PortableInterceptor::Cookies_var &p) // copy constructor
{
  if (p.ptr_)
    ACE_NEW (this->ptr_, PortableInterceptor::Cookies(*p.ptr_));
  else
    this->ptr_ = 0;
}

ACE_INLINE
PortableInterceptor::Cookies_var::~Cookies_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE PortableInterceptor::Cookies_var &
PortableInterceptor::Cookies_var::operator= (PortableInterceptor::Cookies *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE PortableInterceptor::Cookies_var &
PortableInterceptor::Cookies_var::operator= (const PortableInterceptor::Cookies_var &p) // deep copy
{
  if (this != &p)
  {
    delete this->ptr_;
    ACE_NEW_RETURN (this->ptr_, 
                    PortableInterceptor::Cookies (*p.ptr_), 
		    *this);
  }
  return *this;
}

ACE_INLINE const PortableInterceptor::Cookies *
PortableInterceptor::Cookies_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::Cookies *
PortableInterceptor::Cookies_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
PortableInterceptor::Cookies_var::operator const PortableInterceptor::Cookies &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
PortableInterceptor::Cookies_var::operator PortableInterceptor::Cookies &() // cast
{
  return *this->ptr_;
}

ACE_INLINE
PortableInterceptor::Cookies_var::operator PortableInterceptor::Cookies &() const// cast
{
  return *this->ptr_;
}

ACE_INLINE TAO_Object_Manager<PortableInterceptor::Cookie,PortableInterceptor::Cookie_var>
PortableInterceptor::Cookies_var::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

ACE_INLINE const PortableInterceptor::Cookies &
PortableInterceptor::Cookies_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE PortableInterceptor::Cookies &
PortableInterceptor::Cookies_var::inout (void)
{
  return *this->ptr_;
}

// mapping for variable size
ACE_INLINE PortableInterceptor::Cookies *&
PortableInterceptor::Cookies_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::Cookies *
PortableInterceptor::Cookies_var::_retn (void)
{
  PortableInterceptor::Cookies *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE PortableInterceptor::Cookies *
PortableInterceptor::Cookies_var::ptr (void) const
{
  return this->ptr_;
}

// *************************************************************
// Inline operations for class PortableInterceptor::Cookies_out
// *************************************************************

ACE_INLINE
PortableInterceptor::Cookies_out::Cookies_out (PortableInterceptor::Cookies *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
PortableInterceptor::Cookies_out::Cookies_out (PortableInterceptor::Cookies_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
PortableInterceptor::Cookies_out::Cookies_out (const PortableInterceptor::Cookies_out &p) // copy constructor
  : ptr_ (ACE_const_cast (PortableInterceptor::Cookies_out&,p).ptr_)
{}

ACE_INLINE PortableInterceptor::Cookies_out &
PortableInterceptor::Cookies_out::operator= (const PortableInterceptor::Cookies_out &p)
{
  this->ptr_ = ACE_const_cast (PortableInterceptor::Cookies_out&,p).ptr_;
  return *this;
}

ACE_INLINE PortableInterceptor::Cookies_out &
PortableInterceptor::Cookies_out::operator= (PortableInterceptor::Cookies *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
PortableInterceptor::Cookies_out::operator PortableInterceptor::Cookies *&() // cast
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::Cookies *&
PortableInterceptor::Cookies_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::Cookies *
PortableInterceptor::Cookies_out::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE TAO_Object_Manager<PortableInterceptor::Cookie,PortableInterceptor::Cookie_var>
PortableInterceptor::Cookies_out::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}


#endif /* end #if !defined */

ACE_INLINE
PortableInterceptor::Interceptor::Interceptor (void) // default constructor
{}

ACE_INLINE
PortableInterceptor::Interceptor::Interceptor (TAO_Stub *objref, TAO_ServantBase *_tao_servant, CORBA::Boolean _tao_collocated) // constructor
  : CORBA_Object (objref, _tao_servant, _tao_collocated)
{}

ACE_INLINE
PortableInterceptor::Interceptor::~Interceptor (void) // destructor
{}


#if !defined (_PORTABLEINTERCEPTOR_INTERCEPTOR___VAR_CI_)
#define _PORTABLEINTERCEPTOR_INTERCEPTOR___VAR_CI_

// *************************************************************
// Inline operations for class PortableInterceptor::Interceptor_var
// *************************************************************

ACE_INLINE
PortableInterceptor::Interceptor_var::Interceptor_var (void) // default constructor
  : ptr_ (PortableInterceptor::Interceptor::_nil ())
{}

ACE_INLINE
PortableInterceptor::Interceptor_var::Interceptor_var (PortableInterceptor::Interceptor_ptr p)
  : ptr_ (p)
{}

ACE_INLINE PortableInterceptor::Interceptor_ptr
PortableInterceptor::Interceptor_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
PortableInterceptor::Interceptor_var::Interceptor_var (const PortableInterceptor::Interceptor_var &p) // copy constructor
  : ptr_ (PortableInterceptor::Interceptor::_duplicate (p.ptr ()))
{}

ACE_INLINE
PortableInterceptor::Interceptor_var::~Interceptor_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

ACE_INLINE PortableInterceptor::Interceptor_var &
PortableInterceptor::Interceptor_var::operator= (PortableInterceptor::Interceptor_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE PortableInterceptor::Interceptor_var &
PortableInterceptor::Interceptor_var::operator= (const PortableInterceptor::Interceptor_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = PortableInterceptor::Interceptor::_duplicate (p.ptr ());
  }
  return *this;
}

ACE_INLINE
PortableInterceptor::Interceptor_var::operator const PortableInterceptor::Interceptor_ptr &() const // cast
{
  return this->ptr_;
}

ACE_INLINE
PortableInterceptor::Interceptor_var::operator PortableInterceptor::Interceptor_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::Interceptor_ptr
PortableInterceptor::Interceptor_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::Interceptor_ptr
PortableInterceptor::Interceptor_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::Interceptor_ptr &
PortableInterceptor::Interceptor_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::Interceptor_ptr &
PortableInterceptor::Interceptor_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = PortableInterceptor::Interceptor::_nil ();
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::Interceptor_ptr
PortableInterceptor::Interceptor_var::_retn (void)
{
  // yield ownership of managed obj reference
  PortableInterceptor::Interceptor_ptr val = this->ptr_;
  this->ptr_ = PortableInterceptor::Interceptor::_nil ();
  return val;
}


#endif /* end #if !defined */


#if !defined (_PORTABLEINTERCEPTOR_INTERCEPTOR___OUT_CI_)
#define _PORTABLEINTERCEPTOR_INTERCEPTOR___OUT_CI_

// *************************************************************
// Inline operations for class PortableInterceptor::Interceptor_out
// *************************************************************

ACE_INLINE
PortableInterceptor::Interceptor_out::Interceptor_out (PortableInterceptor::Interceptor_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = PortableInterceptor::Interceptor::_nil ();
}

ACE_INLINE
PortableInterceptor::Interceptor_out::Interceptor_out (PortableInterceptor::Interceptor_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = PortableInterceptor::Interceptor::_nil ();
}

ACE_INLINE
PortableInterceptor::Interceptor_out::Interceptor_out (const PortableInterceptor::Interceptor_out &p) // copy constructor
  : ptr_ (ACE_const_cast (PortableInterceptor::Interceptor_out&,p).ptr_)
{}

ACE_INLINE PortableInterceptor::Interceptor_out &
PortableInterceptor::Interceptor_out::operator= (const PortableInterceptor::Interceptor_out &p)
{
  this->ptr_ = ACE_const_cast (PortableInterceptor::Interceptor_out&,p).ptr_;
  return *this;
}

ACE_INLINE PortableInterceptor::Interceptor_out &
PortableInterceptor::Interceptor_out::operator= (const PortableInterceptor::Interceptor_var &p)
{
  this->ptr_ = PortableInterceptor::Interceptor::_duplicate (p.ptr ());
  return *this;
}

ACE_INLINE PortableInterceptor::Interceptor_out &
PortableInterceptor::Interceptor_out::operator= (PortableInterceptor::Interceptor_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
PortableInterceptor::Interceptor_out::operator PortableInterceptor::Interceptor_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::Interceptor_ptr &
PortableInterceptor::Interceptor_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::Interceptor_ptr
PortableInterceptor::Interceptor_out::operator-> (void)
{
  return this->ptr_;
}


#endif /* end #if !defined */

ACE_INLINE
PortableInterceptor::ServerRequestInterceptor::ServerRequestInterceptor (void) // default constructor
{}

ACE_INLINE
PortableInterceptor::ServerRequestInterceptor::ServerRequestInterceptor (TAO_Stub *objref, TAO_ServantBase *_tao_servant, CORBA::Boolean _tao_collocated) // constructor
  : CORBA_Object (objref, _tao_servant, _tao_collocated)
{}

ACE_INLINE
PortableInterceptor::ServerRequestInterceptor::~ServerRequestInterceptor (void) // destructor
{}


#if !defined (_PORTABLEINTERCEPTOR_SERVERREQUESTINTERCEPTOR___VAR_CI_)
#define _PORTABLEINTERCEPTOR_SERVERREQUESTINTERCEPTOR___VAR_CI_

// *************************************************************
// Inline operations for class PortableInterceptor::ServerRequestInterceptor_var
// *************************************************************

ACE_INLINE
PortableInterceptor::ServerRequestInterceptor_var::ServerRequestInterceptor_var (void) // default constructor
  : ptr_ (PortableInterceptor::ServerRequestInterceptor::_nil ())
{}

ACE_INLINE
PortableInterceptor::ServerRequestInterceptor_var::ServerRequestInterceptor_var (PortableInterceptor::ServerRequestInterceptor_ptr p)
  : ptr_ (p)
{}

ACE_INLINE PortableInterceptor::ServerRequestInterceptor_ptr
PortableInterceptor::ServerRequestInterceptor_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
PortableInterceptor::ServerRequestInterceptor_var::ServerRequestInterceptor_var (const PortableInterceptor::ServerRequestInterceptor_var &p) // copy constructor
  : ptr_ (PortableInterceptor::ServerRequestInterceptor::_duplicate (p.ptr ()))
{}

ACE_INLINE
PortableInterceptor::ServerRequestInterceptor_var::~ServerRequestInterceptor_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

ACE_INLINE PortableInterceptor::ServerRequestInterceptor_var &
PortableInterceptor::ServerRequestInterceptor_var::operator= (PortableInterceptor::ServerRequestInterceptor_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE PortableInterceptor::ServerRequestInterceptor_var &
PortableInterceptor::ServerRequestInterceptor_var::operator= (const PortableInterceptor::ServerRequestInterceptor_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = PortableInterceptor::ServerRequestInterceptor::_duplicate (p.ptr ());
  }
  return *this;
}

ACE_INLINE
PortableInterceptor::ServerRequestInterceptor_var::operator const PortableInterceptor::ServerRequestInterceptor_ptr &() const // cast
{
  return this->ptr_;
}

ACE_INLINE
PortableInterceptor::ServerRequestInterceptor_var::operator PortableInterceptor::ServerRequestInterceptor_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::ServerRequestInterceptor_ptr
PortableInterceptor::ServerRequestInterceptor_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::ServerRequestInterceptor_ptr
PortableInterceptor::ServerRequestInterceptor_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::ServerRequestInterceptor_ptr &
PortableInterceptor::ServerRequestInterceptor_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::ServerRequestInterceptor_ptr &
PortableInterceptor::ServerRequestInterceptor_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = PortableInterceptor::ServerRequestInterceptor::_nil ();
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::ServerRequestInterceptor_ptr
PortableInterceptor::ServerRequestInterceptor_var::_retn (void)
{
  // yield ownership of managed obj reference
  PortableInterceptor::ServerRequestInterceptor_ptr val = this->ptr_;
  this->ptr_ = PortableInterceptor::ServerRequestInterceptor::_nil ();
  return val;
}


#endif /* end #if !defined */


#if !defined (_PORTABLEINTERCEPTOR_SERVERREQUESTINTERCEPTOR___OUT_CI_)
#define _PORTABLEINTERCEPTOR_SERVERREQUESTINTERCEPTOR___OUT_CI_

// *************************************************************
// Inline operations for class PortableInterceptor::ServerRequestInterceptor_out
// *************************************************************

ACE_INLINE
PortableInterceptor::ServerRequestInterceptor_out::ServerRequestInterceptor_out (PortableInterceptor::ServerRequestInterceptor_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = PortableInterceptor::ServerRequestInterceptor::_nil ();
}

ACE_INLINE
PortableInterceptor::ServerRequestInterceptor_out::ServerRequestInterceptor_out (PortableInterceptor::ServerRequestInterceptor_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = PortableInterceptor::ServerRequestInterceptor::_nil ();
}

ACE_INLINE
PortableInterceptor::ServerRequestInterceptor_out::ServerRequestInterceptor_out (const PortableInterceptor::ServerRequestInterceptor_out &p) // copy constructor
  : ptr_ (ACE_const_cast (PortableInterceptor::ServerRequestInterceptor_out&,p).ptr_)
{}

ACE_INLINE PortableInterceptor::ServerRequestInterceptor_out &
PortableInterceptor::ServerRequestInterceptor_out::operator= (const PortableInterceptor::ServerRequestInterceptor_out &p)
{
  this->ptr_ = ACE_const_cast (PortableInterceptor::ServerRequestInterceptor_out&,p).ptr_;
  return *this;
}

ACE_INLINE PortableInterceptor::ServerRequestInterceptor_out &
PortableInterceptor::ServerRequestInterceptor_out::operator= (const PortableInterceptor::ServerRequestInterceptor_var &p)
{
  this->ptr_ = PortableInterceptor::ServerRequestInterceptor::_duplicate (p.ptr ());
  return *this;
}

ACE_INLINE PortableInterceptor::ServerRequestInterceptor_out &
PortableInterceptor::ServerRequestInterceptor_out::operator= (PortableInterceptor::ServerRequestInterceptor_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
PortableInterceptor::ServerRequestInterceptor_out::operator PortableInterceptor::ServerRequestInterceptor_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::ServerRequestInterceptor_ptr &
PortableInterceptor::ServerRequestInterceptor_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::ServerRequestInterceptor_ptr
PortableInterceptor::ServerRequestInterceptor_out::operator-> (void)
{
  return this->ptr_;
}


#endif /* end #if !defined */

ACE_INLINE
PortableInterceptor::ClientRequestInterceptor::ClientRequestInterceptor (void) // default constructor
{}

ACE_INLINE
PortableInterceptor::ClientRequestInterceptor::ClientRequestInterceptor (TAO_Stub *objref, TAO_ServantBase *_tao_servant, CORBA::Boolean _tao_collocated) // constructor
  : CORBA_Object (objref, _tao_servant, _tao_collocated)
{}

ACE_INLINE
PortableInterceptor::ClientRequestInterceptor::~ClientRequestInterceptor (void) // destructor
{}


#if !defined (_PORTABLEINTERCEPTOR_CLIENTREQUESTINTERCEPTOR___VAR_CI_)
#define _PORTABLEINTERCEPTOR_CLIENTREQUESTINTERCEPTOR___VAR_CI_

// *************************************************************
// Inline operations for class PortableInterceptor::ClientRequestInterceptor_var
// *************************************************************

ACE_INLINE
PortableInterceptor::ClientRequestInterceptor_var::ClientRequestInterceptor_var (void) // default constructor
  : ptr_ (PortableInterceptor::ClientRequestInterceptor::_nil ())
{}

ACE_INLINE
PortableInterceptor::ClientRequestInterceptor_var::ClientRequestInterceptor_var (PortableInterceptor::ClientRequestInterceptor_ptr p)
  : ptr_ (p)
{}

ACE_INLINE PortableInterceptor::ClientRequestInterceptor_ptr
PortableInterceptor::ClientRequestInterceptor_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
PortableInterceptor::ClientRequestInterceptor_var::ClientRequestInterceptor_var (const PortableInterceptor::ClientRequestInterceptor_var &p) // copy constructor
  : ptr_ (PortableInterceptor::ClientRequestInterceptor::_duplicate (p.ptr ()))
{}

ACE_INLINE
PortableInterceptor::ClientRequestInterceptor_var::~ClientRequestInterceptor_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

ACE_INLINE PortableInterceptor::ClientRequestInterceptor_var &
PortableInterceptor::ClientRequestInterceptor_var::operator= (PortableInterceptor::ClientRequestInterceptor_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE PortableInterceptor::ClientRequestInterceptor_var &
PortableInterceptor::ClientRequestInterceptor_var::operator= (const PortableInterceptor::ClientRequestInterceptor_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = PortableInterceptor::ClientRequestInterceptor::_duplicate (p.ptr ());
  }
  return *this;
}

ACE_INLINE
PortableInterceptor::ClientRequestInterceptor_var::operator const PortableInterceptor::ClientRequestInterceptor_ptr &() const // cast
{
  return this->ptr_;
}

ACE_INLINE
PortableInterceptor::ClientRequestInterceptor_var::operator PortableInterceptor::ClientRequestInterceptor_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::ClientRequestInterceptor_ptr
PortableInterceptor::ClientRequestInterceptor_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::ClientRequestInterceptor_ptr
PortableInterceptor::ClientRequestInterceptor_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::ClientRequestInterceptor_ptr &
PortableInterceptor::ClientRequestInterceptor_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::ClientRequestInterceptor_ptr &
PortableInterceptor::ClientRequestInterceptor_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = PortableInterceptor::ClientRequestInterceptor::_nil ();
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::ClientRequestInterceptor_ptr
PortableInterceptor::ClientRequestInterceptor_var::_retn (void)
{
  // yield ownership of managed obj reference
  PortableInterceptor::ClientRequestInterceptor_ptr val = this->ptr_;
  this->ptr_ = PortableInterceptor::ClientRequestInterceptor::_nil ();
  return val;
}


#endif /* end #if !defined */


#if !defined (_PORTABLEINTERCEPTOR_CLIENTREQUESTINTERCEPTOR___OUT_CI_)
#define _PORTABLEINTERCEPTOR_CLIENTREQUESTINTERCEPTOR___OUT_CI_

// *************************************************************
// Inline operations for class PortableInterceptor::ClientRequestInterceptor_out
// *************************************************************

ACE_INLINE
PortableInterceptor::ClientRequestInterceptor_out::ClientRequestInterceptor_out (PortableInterceptor::ClientRequestInterceptor_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = PortableInterceptor::ClientRequestInterceptor::_nil ();
}

ACE_INLINE
PortableInterceptor::ClientRequestInterceptor_out::ClientRequestInterceptor_out (PortableInterceptor::ClientRequestInterceptor_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = PortableInterceptor::ClientRequestInterceptor::_nil ();
}

ACE_INLINE
PortableInterceptor::ClientRequestInterceptor_out::ClientRequestInterceptor_out (const PortableInterceptor::ClientRequestInterceptor_out &p) // copy constructor
  : ptr_ (ACE_const_cast (PortableInterceptor::ClientRequestInterceptor_out&,p).ptr_)
{}

ACE_INLINE PortableInterceptor::ClientRequestInterceptor_out &
PortableInterceptor::ClientRequestInterceptor_out::operator= (const PortableInterceptor::ClientRequestInterceptor_out &p)
{
  this->ptr_ = ACE_const_cast (PortableInterceptor::ClientRequestInterceptor_out&,p).ptr_;
  return *this;
}

ACE_INLINE PortableInterceptor::ClientRequestInterceptor_out &
PortableInterceptor::ClientRequestInterceptor_out::operator= (const PortableInterceptor::ClientRequestInterceptor_var &p)
{
  this->ptr_ = PortableInterceptor::ClientRequestInterceptor::_duplicate (p.ptr ());
  return *this;
}

ACE_INLINE PortableInterceptor::ClientRequestInterceptor_out &
PortableInterceptor::ClientRequestInterceptor_out::operator= (PortableInterceptor::ClientRequestInterceptor_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
PortableInterceptor::ClientRequestInterceptor_out::operator PortableInterceptor::ClientRequestInterceptor_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::ClientRequestInterceptor_ptr &
PortableInterceptor::ClientRequestInterceptor_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE PortableInterceptor::ClientRequestInterceptor_ptr
PortableInterceptor::ClientRequestInterceptor_out::operator-> (void)
{
  return this->ptr_;
}


#endif /* end #if !defined */

#endif /* TAO_HAS_INTERCEPTORS */
