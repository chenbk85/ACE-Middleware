// $Id$

#if !defined (ACE_MAP_MANAGER_C)
#define ACE_MAP_MANAGER_C

#define ACE_BUILD_DLL
#include "ace/Synch.h"
#include "ace/Malloc.h"
#include "ace/Service_Config.h"
#include "ace/Map_Manager.h"

#if !defined (__ACE_INLINE__)
#include "ace/Map_Manager.i"
#endif /* __ACE_INLINE__ */

ACE_ALLOC_HOOK_DEFINE(ACE_Map_Entry)

template <class EXT_ID, class INT_ID>
ACE_Map_Entry<EXT_ID, INT_ID>::~ACE_Map_Entry (void)
{
  // No-op just to keep some compilers happy...
}

template <class EXT_ID, class INT_ID> void
ACE_Map_Entry<EXT_ID, INT_ID>::dump (void) const
{
  ACE_TRACE ("ACE_Map_Entry<EXT_ID, INT_ID>::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ASYS_TEXT ("is_free_ = %d"), this->is_free_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
}

ACE_ALLOC_HOOK_DEFINE(ACE_Map_Manager)

template <class EXT_ID, class INT_ID, class ACE_LOCK> void
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::dump (void) const
{
  ACE_TRACE ("ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ASYS_TEXT ("total_size_ = %d"), this->total_size_));
  ACE_DEBUG ((LM_DEBUG,  ASYS_TEXT ("\ncur_size_ = %d"), this->cur_size_));
  this->allocator_->dump ();
  this->lock_.dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::ACE_Map_Manager (size_t size,
                                                            ACE_Allocator *alloc)
  : search_structure_ (0),
    allocator_ (0),
    total_size_ (0),
    cur_size_ (0)
{
  ACE_TRACE ("ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::ACE_Map_Manager");

  if (this->open (size, alloc) == -1)
    ACE_ERROR ((LM_ERROR, ASYS_TEXT ("ACE_Map_Manager\n")));
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::ACE_Map_Manager (ACE_Allocator *alloc)
  : search_structure_ (0),
    allocator_ (0),
    total_size_ (0),
    cur_size_ (0)
{
  ACE_TRACE ("ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::ACE_Map_Manager");
  if (this->open (ACE_DEFAULT_MAP_SIZE, alloc) == -1)
    ACE_ERROR ((LM_ERROR, ASYS_TEXT ("ACE_Map_Manager\n")));
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::close_i (void)
{
  ACE_TRACE ("ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::close_i");

  this->free_search_structure ();
  return 0;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::close (void)
{
  ACE_TRACE ("ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::close");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->close_i ();
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::~ACE_Map_Manager (void)
{
  ACE_TRACE ("ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::~ACE_Map_Manager");
  this->close ();
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::resize_i (size_t size)
{
  ACE_TRACE ("ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::resize_i");

  // If we need to grow buffer, then remove the existing buffer.
  void *ptr;

  ACE_ALLOCATOR_RETURN (ptr,
                        this->allocator_->malloc (size * sizeof (ACE_Map_Entry<EXT_ID, INT_ID>)),
                        -1);

  size_t i;

  ACE_Map_Entry<EXT_ID, INT_ID> *temp = (ACE_Map_Entry<EXT_ID, INT_ID> *) ptr;

  // Copy over the currently active elements.
  for (i = 0; i < this->cur_size_; i++)
    {
      temp[i] = this->search_structure_[i]; // Structure assignment.
    }

  this->total_size_ = size;

  // Mark the newly allocated elements as being "free".

  for (i = this->cur_size_; i < this->total_size_; i++)
    {
      // Call the constructor for each element in the array.  Note
      // that this requires a default constructor for <EXT_ID> and
      // <INT_ID>.
      new (&(temp[i])) ACE_Map_Entry<EXT_ID, INT_ID>;
      temp[i].is_free_ = 1;
    }

  this->free_search_structure ();

  this->search_structure_ = temp;
  return 0;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::begin (void)
{
  return ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK> (*this);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::end (void)
{
  return ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK> (*this, 1);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::rbegin (void)
{
  return ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK> (*this);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::rend (void)
{
  return ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK> (*this, 1);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> void
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::free_search_structure (void)
{
  if (this->search_structure_ != 0)
    {
      for (size_t i = 0; i < this->total_size_; i++)
        // Explicitly call the destructor.
        {
          ACE_Map_Entry<EXT_ID, INT_ID> *ss = &this->search_structure_[i];
          // The "if" second argument results in a no-op instead of
          // deallocation.
          ACE_DES_FREE_TEMPLATE2 (ss, if,
                                  ACE_Map_Entry, EXT_ID, INT_ID);
        }

      // Actually free the memory.
      this->allocator_->free (this->search_structure_);
      this->search_structure_ = 0;
    }
}

// Create a new search_structure of size SIZE.

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::open (size_t size,
                                                 ACE_Allocator *alloc)
{
  ACE_TRACE ("ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::open");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  if (alloc == 0)
    alloc = ACE_Allocator::instance ();

  this->allocator_ = alloc;

  // This assertion is here to help track a situation that shouldn't happen
  ACE_ASSERT (size != 0);

  return this->resize_i (size);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::shared_find (const EXT_ID &ext_id,
                                                        int &first_free)
{
  // See if the entry is already there, keeping track of the first
  // free slot.

  for (size_t i = 0; i < this->cur_size_; i++)
    {
      ACE_Map_Entry<EXT_ID, INT_ID> &ss = this->search_structure_[i];

      if (ss.is_free_ == 0)
        {
          if (ss.ext_id_ == ext_id)
            return i;
        }
      else if (first_free == -1)
        first_free = int (i);
    }

  errno = ENOENT;
  return -1;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::equal (const EXT_ID &id1,
                                                  const EXT_ID &id2)
{
  return id1 == id2;
}

// Find the <int_id> corresponding to the <ext_id>.

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::shared_find (const EXT_ID &ext_id)
{
  ACE_TRACE ("ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::shared_find");

  for (size_t i = 0; i < this->cur_size_; i++)
    {
      const ACE_Map_Entry<EXT_ID, INT_ID> &ss
        = this->search_structure_[i];

      if (ss.is_free_ == 0 && this->equal (ss.ext_id_, ext_id))
        // We found it!
        return i;
    }

  // not found
  errno = ENOENT;
  return -1;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::shared_bind (const EXT_ID &ext_id,
                                                        const INT_ID &int_id,
                                                        int first_free)
{
  if (first_free > -1)
    {
      // We found a free spot, let's reuse it.

      ACE_Map_Entry<EXT_ID, INT_ID> &ss = this->search_structure_[first_free];

      ss.ext_id_ = ext_id;
      ss.int_id_ = int_id;
      ss.is_free_ = 0;
      this->allocator_->sync ((void *) &this->search_structure_[first_free], sizeof ss);
      return 0;
    }

  // Check if we have reached total_size_
  else if (this->cur_size_ == this->total_size_)
    // We are out of room so grow the map
    if (this->resize_i (this->total_size_ + ACE_DEFAULT_MAP_SIZE) == -1)
      return -1;

  // Insert at the end of the active portion.

  ACE_Map_Entry<EXT_ID, INT_ID> &ss = this->search_structure_[this->cur_size_];

  ss.int_id_ = int_id;
  ss.ext_id_ = ext_id;
  ss.is_free_ = 0;
  this->allocator_->sync ((void *) &this->search_structure_[this->cur_size_], sizeof ss);
  this->cur_size_++;
  this->allocator_->sync ((void *) &this->cur_size_, sizeof this->cur_size_);
  return 0;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::trybind_i (const EXT_ID &ext_id,
                                                      INT_ID &int_id)
{
  ACE_TRACE ("ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::trybind_i");
  int first_free = -1;
  int index = this->shared_find (ext_id, first_free);

  if (index >= 0)
    {
      // There was already something there, so make a copy, but
      // *don't* update anything in the map!

      int_id = this->search_structure_[index].int_id_;
      return 1;
    }
  else
    // We didn't find it, so let's bind it!
    return this->shared_bind (ext_id, int_id, first_free);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::trybind (const EXT_ID &ext_id,
                                                    INT_ID &int_id)
{
  ACE_TRACE ("ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::trybind");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->trybind_i (ext_id, int_id);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::find_i (const EXT_ID &ext_id)
{
  ACE_TRACE ("ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::find_i");
  return this->shared_find (ext_id);
}

// Find the INT_ID corresponding to the EXT_ID.

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::find (const EXT_ID &ext_id)
{
  ACE_TRACE ("ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::find");
  ACE_READ_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->find_i (ext_id);
}

// Unbind (remove) the EXT_ID from the map and return it via an out
// parameter.  Note that this method does *not* free up the INT_ID
// structure.  Thus, if there is dynamic memory associated with this,
// the caller is responsible for freeing this memory.

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::unbind_i (const EXT_ID &ext_id,
                                                     INT_ID &int_id)
{
  ACE_TRACE ("ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::unbind_i");

  ssize_t index = this->shared_unbind (ext_id);

  if (index == -1)
    return -1;
  else
    {
      int_id = this->search_structure_[index].int_id_;
      return 0;
    }
}

// Associate <ext_id> with <int_id>.  If <ext_id> is already in the
// map then the <Map_Entry> is not changed.  Returns 0 if a new
// entry is bound successfully, returns 1 if an attempt is made to
// bind an existing entry, and returns -1 if failures occur.

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::bind_i (const EXT_ID &ext_id,
                                                   const INT_ID &int_id)
{
  ACE_TRACE ("ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::bind_i");

  int first_free = -1;
  // We need to save errno since <shared_find> may set errno to
  // ENOENT.
  int error = errno;
  int index = this->shared_find (ext_id, first_free);

  if (index >= 0)
    // It was already bound, so return 1.
    return 1;

  else
    {
      // Restore errno.
      errno = error;
      // We didn't find it, so let's bind it!
      return this->shared_bind (ext_id, int_id, first_free);
    }
}

// Associate <ext_id> with <int_id>.  If <ext_id> is not in the
// map then behaves just like <bind>.  Otherwise, store the old
// values of <ext_id> and <int_id> into the "out" parameters and
// rebind the new parameters.  This is very useful if you need to
// have an atomic way of updating <Map_Entries> and you also need
// full control over memory allocation.  Returns 0 if a new entry is
// bound successfully, returns 1 if an existing entry was rebound,
// and returns -1 if failures occur.

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::rebind_i (const EXT_ID &ext_id,
                                                     const INT_ID &int_id,
                                                     EXT_ID &old_ext_id,
                                                     INT_ID &old_int_id)
{
  ACE_TRACE ("ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::rebind_i");

  int first_free = -1;
  int index = this->shared_find (ext_id, first_free);

  if (index >= 0)
    {
      // We found it, so make copies of the old entries and rebind
      // current entries.

      ACE_Map_Entry<EXT_ID, INT_ID> &ss = this->search_structure_[index];

      old_ext_id = ss.ext_id_;
      old_int_id = ss.int_id_;
      ss.ext_id_ = ext_id;
      ss.int_id_ = int_id;
      this->allocator_->sync ((void *) &this->search_structure_[index], sizeof ss);
      return 1;
    }
  else
    // We didn't find it, so let's bind it!
    return this->shared_bind (ext_id, int_id, first_free);
}

// Find the INT_ID corresponding to the EXT_ID.

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::find_i (const EXT_ID &ext_id,
                                                   INT_ID &int_id)
{
  ACE_TRACE ("ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::find_i");

  int index = this->shared_find (ext_id);

  if (index == -1)
    // Didn't find it.
    return -1;
  else
    {
      // Found it, so assign a copy.
      int_id = this->search_structure_[index].int_id_;
      return index;
    }
}

// Unbind (remove) the EXT_ID from the map.  Keeps track of where
// the EXT_ID was found so that this->unbind (EXT_ID, INT_ID)
// can return it to the caller.

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::shared_unbind (const EXT_ID &ext_id)
{
  ACE_TRACE ("ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::shared_unbind");
  for (size_t i = 0; i < this->cur_size_; i++)
    {
      ACE_Map_Entry<EXT_ID, INT_ID> &ss = this->search_structure_[i];

      if (ss.is_free_ == 0 && this->equal (ss.ext_id_, ext_id))
        {
          size_t index = i;

          // Mark this entry as being free.
          ss.is_free_ = 1;

          this->allocator_->sync ((void *) &ss.is_free_,
                                  sizeof ss.is_free_);

          // If we just unbound the highest active entry, then we need
          // to figure out where the next highest active entry is.

          if (i + 1 == this->cur_size_)
            {
              while (i > 0 && this->search_structure_[--i].is_free_)
                continue;

              if (i == 0 && this->search_structure_[i].is_free_)
                this->cur_size_ = 0;
              else
                this->cur_size_ = i + 1;
              this->allocator_->sync ((void *) &this->cur_size_,
                                      sizeof this->cur_size_);
            }
          return index;
        }
    }
  errno = ENOENT;
  return -1;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::unbind (const EXT_ID &ext_id,
                                                   INT_ID &int_id)
{
  ACE_TRACE ("ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::unbind");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->unbind_i (ext_id, int_id);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::bind (const EXT_ID &ext_id,
                                                 const INT_ID &int_id)
{
  ACE_TRACE ("ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::bind");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->bind_i (ext_id, int_id);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::rebind (const EXT_ID &ext_id,
                                                   const INT_ID &int_id,
                                                   EXT_ID &old_ext_id,
                                                   INT_ID &old_int_id)
{
  ACE_TRACE ("ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::rebind");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->rebind_i (ext_id, int_id, old_ext_id, old_int_id);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::find (const EXT_ID &ext_id,
                                                 INT_ID &int_id)
{
  ACE_TRACE ("ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::find");
  ACE_READ_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->find_i (ext_id, int_id);
}

// Unbind (remove) the EXT_ID from the map.  Don't return the INT_ID
// to the caller (this is useful for collections where the INT_IDs are
// *not* dynamically allocated...)

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::unbind_i (const EXT_ID &ext_id)
{
  ACE_TRACE ("ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::unbind_i");
  return this->shared_unbind (ext_id) == -1 ? -1 : 0;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::unbind (const EXT_ID &ext_id)
{
  ACE_TRACE ("ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::unbind");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);
  return this->unbind_i (ext_id) == -1 ? -1 : 0;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> size_t
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::current_size (void)
{
  ACE_TRACE ("ACE_Map_Manager::current_size");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_,
                          ACE_static_cast(size_t, -1));
  return this->cur_size_;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> size_t
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::total_size (void)
{
  ACE_TRACE ("ACE_Map_Manager::total_size");
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_,
                          ACE_static_cast(size_t, -1));
  return this->total_size_;
}

// @@ && @@

ACE_ALLOC_HOOK_DEFINE(ACE_Map_Iterator_Base)

template <class EXT_ID, class INT_ID, class ACE_LOCK> void
ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::dump_i (void) const
{
  ACE_TRACE ("ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ASYS_TEXT ("next_ = %d"), this->next_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::ACE_Map_Iterator_Base (ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK> &mm, int head)
  : map_man_ (&mm),
    next_ (-1)
{
  ACE_TRACE ("ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::ACE_Map_Iterator_Base");
  if (head == 0)
    this->next_ = this->map_man_->cur_size_;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::next (ACE_Map_Entry<EXT_ID, INT_ID> *&mm)
{
  ACE_TRACE ("ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::next");
  ACE_READ_GUARD_RETURN (ACE_LOCK, ace_mon, this->map_man_->lock_, -1);

  if (this->map_man_->search_structure_ != 0
      // Note that this->next_ is never negative at this point...
      && ACE_static_cast(size_t, this->next_) < this->map_man_->cur_size_
      && this->next_ > -1)
    {
      mm = &this->map_man_->search_structure_[this->next_];
      return 1;
    }
  else
    return 0;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::done (void) const
{
  ACE_TRACE ("ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::done");
  ACE_READ_GUARD_RETURN (ACE_LOCK, ace_mon, this->map_man_->lock_, -1);

  return this->map_man_->search_structure_ == 0
    // Note that this->next_ is never negative at this point...
    || ACE_static_cast (size_t, this->next_) >= this->map_man_->cur_size_
    || this->next_ <= -1;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::forward_i (void)
{
  ACE_TRACE ("ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::forward_i");
  ACE_READ_GUARD_RETURN (ACE_LOCK, ace_mon, this->map_man_->lock_, -1);

  for (++this->next_;
       ACE_static_cast(size_t, this->next_) < this->map_man_->cur_size_
         && this->map_man_->search_structure_[this->next_].is_free_;
       this->next_++)
    continue;
  return ACE_static_cast(size_t, this->next_) < this->map_man_->cur_size_;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::reverse_i (void)
{
  ACE_TRACE ("ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::reverse_i");
  ACE_READ_GUARD_RETURN (ACE_LOCK, ace_mon, this->map_man_->lock_, -1);

  for (--this->next_;
       this->next_ >= 0
         && this->map_man_->search_structure_[this->next_].is_free_;
       this->next_--)
    continue;
  return this->next_ >= 0;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Map_Entry<EXT_ID, INT_ID>&
ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::operator* (void)
{
  ACE_TRACE ("ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::operator*");
  ACE_Map_Entry<EXT_ID, INT_ID> *retv = 0;

  ACE_ASSERT (this->next (retv) != 0);
  return *retv;
}

// Returns the reference to the map_manager that is being
// iterated over.
template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>&
ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::map (void)
{
  ACE_TRACE ("ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::map");
  return *this->map_man_;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::operator== (const ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK> &rhs) const
{
  ACE_TRACE ("ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::operator==");
  return (this->map_man_ == rhs.map_man_ && this->next_ == rhs.next_);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::operator!= (const ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK> &rhs) const
{
  ACE_TRACE ("ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::operator!=");
  return (this->next_ != rhs.next_ || this->map_man_ != rhs.map_man_);
}

ACE_ALLOC_HOOK_DEFINE(ACE_Map_Iterator)

template <class EXT_ID, class INT_ID, class ACE_LOCK> void
ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>::dump (void) const
{
  ACE_TRACE ("ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>::dump");

  this->dump_i ();
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>::ACE_Map_Iterator (ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK> &mm, int tail)
  : ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK> (mm, (tail == 0 ? 1 : 0))
{
  ACE_TRACE ("ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>::ACE_Map_Iterator");
  if (tail == 0 && this->map_man_->search_structure_ != 0)
    this->forward_i ();
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>::advance (void)
{
  ACE_TRACE ("ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>::advance");
  return this->forward_i ();
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>
ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator++ (void)
{
  ACE_TRACE ("ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator++ (void)");
  ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK> retv (*this);

  this->forward_i ();
  return retv;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>&
ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator++ (int)
{
  ACE_TRACE ("ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator++ (int)");
  this->forward_i ();
  return *this;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>
ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator-- (void)
{
  ACE_TRACE ("ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator-- (void)");
  ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK> retv (*this);

  this->reverse_i ();
  return retv;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>&
ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator-- (int)
{
  ACE_TRACE ("ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator-- (int)");
  this->reverse_i ();
  return *this;
}

ACE_ALLOC_HOOK_DEFINE(ACE_Map_Reverse_Iterator)

template <class EXT_ID, class INT_ID, class ACE_LOCK> void
ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>::dump (void) const
{
  ACE_TRACE ("ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>::dump");

  this->dump_i ();
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>::ACE_Map_Reverse_Iterator (ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK> &mm, int head)
  : ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK> (mm, head)
{
  ACE_TRACE ("ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>::ACE_Map_Reverse_Iterator");
  if (head == 0 && this->map_man_->search_structure_ != 0)
    this->reverse_i ();
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>::advance (void)
{
  ACE_TRACE ("ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>::advance");
  return this->reverse_i ();
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>
ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator++ (void)
{
  ACE_TRACE ("ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator++ (void)");
  ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK> retv (*this);

  this->reverse_i ();
  return retv;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>&
ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator++ (int)
{
  ACE_TRACE ("ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator++ (int)");
  this->reverse_i ();
  return *this;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>
ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator-- (void)
{
  ACE_TRACE ("ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator-- (void)");
  ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK> retv (*this);

  this->forward_i ();
  return retv;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>&
ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator-- (int)
{
  ACE_TRACE ("ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator-- (int)");
  this->forward_i ();
  return *this;
}

#endif /* ACE_MAP_MANAGER_C */
