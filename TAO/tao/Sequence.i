/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO
//
// = FILENAME
//    sequence.i
//
// = AUTHOR
//    Aniruddha Gokhale and Carlos O'Ryan
//
// ============================================================================

// Operations on the unbounded sequence class.

ACE_INLINE
TAO_Base_Sequence::TAO_Base_Sequence (void)
  : maximum_ (0),
    length_ (0),
    buffer_ (0),
    release_ (0)
{
}

ACE_INLINE
TAO_Base_Sequence::TAO_Base_Sequence (CORBA::ULong maximum,
                                      CORBA::ULong length,
                                      void *buffer,
                                      CORBA::Boolean release)
  : maximum_ (maximum),
    length_ (length),
    buffer_ (buffer),
    release_ (release)
{
}

ACE_INLINE
TAO_Base_Sequence::TAO_Base_Sequence (CORBA::ULong maximum,
                                      void *data)
  : maximum_ (maximum),
    length_ (0),
    buffer_ (data),
    release_ (1)
{
}

ACE_INLINE
TAO_Base_Sequence::TAO_Base_Sequence (const TAO_Base_Sequence &rhs)
  : maximum_ (rhs.maximum_),
    length_ (rhs.length_),
    release_ (1)
{
}

ACE_INLINE CORBA::Boolean
TAO_Base_Sequence::release (void) const
{
  return this->release_;
}

ACE_INLINE TAO_Base_Sequence &
TAO_Base_Sequence::operator= (const TAO_Base_Sequence &rhs)
{
  this->maximum_ = rhs.maximum_;
  this->length_ = rhs.length_;
  this->release_ = 1;
  return *this;
}

ACE_INLINE CORBA::ULong
TAO_Base_Sequence::maximum (void) const
{
  return this->maximum_;
}

// ****************************************************************

ACE_INLINE
TAO_Unbounded_Base_Sequence::TAO_Unbounded_Base_Sequence (void)
{
}

ACE_INLINE
TAO_Unbounded_Base_Sequence::
TAO_Unbounded_Base_Sequence (CORBA::ULong maximum,
                             CORBA::ULong length,
                             void* buffer,
                             CORBA::Boolean release)
  :  TAO_Base_Sequence (maximum, length, buffer, release)
{
}

ACE_INLINE
TAO_Unbounded_Base_Sequence::
TAO_Unbounded_Base_Sequence (CORBA::ULong maximum,
                             void* buffer)
  :  TAO_Base_Sequence (maximum, buffer)
{
}

ACE_INLINE CORBA::ULong
TAO_Unbounded_Base_Sequence::length (void) const
{
  return this->length_;
}

ACE_INLINE void
TAO_Unbounded_Base_Sequence::length (CORBA::ULong length)
{
  if (length > this->maximum_)
    {
      this->_allocate_buffer (length);
      this->maximum_ = length;
      this->release_ = 1;
    }
  else if (length < this->length_)
    {
      this->_shrink_buffer (length, this->length_);
    }
  this->length_ = length;
}

// ****************************************************************

ACE_INLINE
TAO_Bounded_Base_Sequence::TAO_Bounded_Base_Sequence (void)
{
}

ACE_INLINE
TAO_Bounded_Base_Sequence::
TAO_Bounded_Base_Sequence (CORBA::ULong maximum,
                           CORBA::ULong length,
                           void* buffer,
                           CORBA::Boolean release)
  :  TAO_Base_Sequence (maximum, length, buffer, release)
{
}

ACE_INLINE
TAO_Bounded_Base_Sequence::
TAO_Bounded_Base_Sequence (CORBA::ULong maximum,
                           void* buffer)
  :  TAO_Base_Sequence (maximum, buffer)
{
}

ACE_INLINE CORBA::ULong
TAO_Bounded_Base_Sequence::length (void) const
{
  return this->length_;
}

ACE_INLINE void
TAO_Bounded_Base_Sequence::length (CORBA::ULong length)
{
  if (length > this->maximum_)
    {
      return;
    }
  else if (length < this->length_)
    {
      this->_shrink_buffer (length, this->length_);
    }
  this->length_ = length;
}

// ****************************************************************

ACE_INLINE
TAO_String_Manager::TAO_String_Manager (char **buffer,
                                        CORBA::Boolean release)
  :  ptr_ (buffer),
     release_ (release)
{
}

ACE_INLINE
TAO_String_Manager::TAO_String_Manager(const TAO_String_Manager &rhs)
  :  ptr_ (rhs.ptr_),
     release_ (rhs.release_)
{
}

ACE_INLINE
TAO_String_Manager::~TAO_String_Manager (void)
{
}

ACE_INLINE
TAO_String_Manager::operator const char* (void) const
{
  return *this->ptr_;
}

ACE_INLINE const char *
TAO_String_Manager::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE char *&
TAO_String_Manager::inout (void)
{
  return *this->ptr_;
}

ACE_INLINE char *
TAO_String_Manager::_retn (void)
{
  char *temp = *this->ptr_;
  *this->ptr_ = 0;
  return temp;
}

// ****************************************************************

//default constructor
ACE_INLINE
TAO_Unbounded_String_Sequence::TAO_Unbounded_String_Sequence (void)
{
}

ACE_INLINE
TAO_Unbounded_String_Sequence::
TAO_Unbounded_String_Sequence (CORBA::ULong maximum,
                               CORBA::ULong length,
                               char* *value,
                               CORBA::Boolean release)
  : TAO_Unbounded_Base_Sequence (maximum, length, value, release)
{
}

ACE_INLINE TAO_String_Manager
TAO_Unbounded_String_Sequence::operator[] (CORBA::ULong index) const
{
  ACE_ASSERT (index < this->maximum_);
  char **const tmp =
    ACE_reinterpret_cast (char **ACE_CAST_CONST, this->buffer_);
  return TAO_String_Manager (tmp + index, this->release_);
}

// ****************************************************************

#if defined (TAO_NO_COPY_OCTET_SEQUENCES)
ACE_INLINE CORBA::Octet *
TAO_Unbounded_Sequence<CORBA::Octet>::allocbuf (CORBA::ULong size)
{
  return new CORBA::Octet[size];
}

ACE_INLINE void
TAO_Unbounded_Sequence<CORBA::Octet>::freebuf (CORBA::Octet *buffer)
{
  delete [] buffer;
}

ACE_INLINE
TAO_Unbounded_Sequence<CORBA::Octet>::TAO_Unbounded_Sequence (void)
  :  mb_ (0)
{
}

ACE_INLINE
TAO_Unbounded_Sequence<CORBA::Octet>::TAO_Unbounded_Sequence (CORBA::ULong maximum)
  : TAO_Unbounded_Base_Sequence (maximum,
                                 TAO_Unbounded_Sequence<CORBA::Octet>::allocbuf (maximum)),
    mb_ (0)
{
}

ACE_INLINE
TAO_Unbounded_Sequence<CORBA::Octet>::TAO_Unbounded_Sequence (CORBA::ULong maximum,
                                                   CORBA::ULong length,
                                                   CORBA::Octet *data,
                                                   CORBA::Boolean release)
  : TAO_Unbounded_Base_Sequence (maximum, length, data, release),
    mb_ (0)
{
}

ACE_INLINE const CORBA::Octet *
TAO_Unbounded_Sequence<CORBA::Octet>::get_buffer (void) const
{
  return ACE_reinterpret_cast(const CORBA::Octet * ACE_CAST_CONST, this->buffer_);
}

// This function is a little too big to be inlined, but some compilers
// (Sun/CC 4.1?) die if it isn't :-(
ACE_INLINE CORBA::Octet *
TAO_Unbounded_Sequence<CORBA::Octet>::get_buffer (CORBA::Boolean orphan)
{
  CORBA::Octet *result = 0;
  if (orphan == 0)
    {
      // We retain ownership.

      if (this->buffer_ == 0)
        {
          // The buffer was not allocated, we must allocate it now.
          result = TAO_Unbounded_Sequence<CORBA::Octet>::allocbuf (this->length_);
          this->buffer_ = result;
        }
      else
        {
          result =
            ACE_reinterpret_cast (CORBA::Octet*,this->buffer_);
        }
    }
  else if (this->mb_ != 0) // (orphan == 1)
    {
      // We must create a copy anyway:
      //   the user is supposed to call freebuf() to release the
      //   buffer, but the buffer is inside a Message_Block...
      //   We thought about storing the pointer to the Message_Block
      //   somewhere at the beginning of the buffer (before the actual
      //   data), but that will not work in 64 bit machines when the
      //   buffer comes from a CDR stream.
      //
      result = TAO_Unbounded_Sequence<CORBA::Octet>::allocbuf (this->length_);
      ACE_OS::memcpy (result, this->buffer_, this->length_);
    }
  else if (this->release_ != 0)
    {
      // We set the state back to default and relinquish
      // ownership.
      result = ACE_reinterpret_cast(CORBA::Octet*,this->buffer_);
      this->maximum_ = 0;
      this->length_ = 0;
      this->buffer_ = 0;
      this->release_ = 0;
    }
  /* else
     // Oops, it's not our buffer to relinquish...
     return 0;
  */
  return result;
}

ACE_INLINE CORBA::Octet &
TAO_Unbounded_Sequence<CORBA::Octet>::operator[] (CORBA::ULong i)
{
  ACE_ASSERT (i < this->maximum_);
  CORBA::Octet* tmp = ACE_reinterpret_cast(CORBA::Octet*,this->buffer_);
  return tmp[i];
}

ACE_INLINE const CORBA::Octet &
TAO_Unbounded_Sequence<CORBA::Octet>::operator[] (CORBA::ULong i) const
{
  ACE_ASSERT (i < this->maximum_);
  CORBA::Octet * const tmp = ACE_reinterpret_cast (CORBA::Octet* ACE_CAST_CONST, this->buffer_);
  return tmp[i];
}

ACE_INLINE ACE_Message_Block*
TAO_Unbounded_Sequence<CORBA::Octet>::mb (void) const
{
  return this->mb_;
}

ACE_INLINE void
TAO_Unbounded_Sequence<CORBA::Octet>::replace (CORBA::ULong length,
                                               const ACE_Message_Block* mb)
{
  this->_deallocate_buffer ();
  this->mb_ = ACE_Message_Block::duplicate (mb);
  this->buffer_ = this->mb_->rd_ptr ();
  this->maximum_ = length;
  this->length_ = length;
  this->release_ = 0;
}

#endif /* defined (TAO_NO_COPY_OCTET_SEQUENCES) */
