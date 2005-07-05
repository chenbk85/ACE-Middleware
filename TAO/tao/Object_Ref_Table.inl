// -*- C++ -*-
//
// $Id$

ACE_INLINE
TAO_Object_Ref_Table::TAO_Object_Ref_Table (void)
  : table_ (TAO_DEFAULT_OBJECT_REF_TABLE_SIZE)
  , lock_ ()
{
}

ACE_INLINE void
TAO_Object_Ref_Table::register_initial_reference (
  const char *id,
  CORBA::Object_ptr obj
  ACE_ENV_ARG_DECL)
{
  if (this->bind (id, obj) != 0)
    {
      ACE_THROW (CORBA::ORB::InvalidName ());
    }
}

ACE_INLINE CORBA::Object_ptr
TAO_Object_Ref_Table::resolve_initial_references (
  const char * id
  ACE_ENV_ARG_DECL_NOT_USED)
{
  return this->find (id);  // Returns a duplicate.
}

ACE_INLINE void
TAO_Object_Ref_Table::destroy (void)
{
  Table tmp;

  ACE_GUARD (TAO_SYNCH_MUTEX, 
             guard, 
             this->lock_);

  this->table_.swap (tmp);  // Force release of memory held by our table.
}

ACE_INLINE TAO_Object_Ref_Table::iterator
TAO_Object_Ref_Table::begin (void)
{
  return this->table_.begin ();
}

ACE_INLINE TAO_Object_Ref_Table::iterator
TAO_Object_Ref_Table::end (void)
{
  return this->table_.end ();
}

ACE_INLINE size_t
TAO_Object_Ref_Table::current_size (void) const
{
  return this->table_.size ();
}

ACE_INLINE int
TAO_Object_Ref_Table::unbind (const char *id)
{
  return
    (this->table_.erase (CORBA::String_var (id)) == 0 ? -1 : 0);
}
