/* -*- c++ -*- */
// $Id$

#if !defined (JAWS_ASSOC_ARRAY_H)
#define JAWS_ASSOC_ARRAY_H

template <class KEY, class DATA> class JAWS_Assoc_Array_Iterator;

template <class KEY, class DATA>
class JAWS_Assoc_Array
{

friend JAWS_Assoc_Array_Iterator<KEY, DATA>;

public:
  JAWS_Assoc_Array (unsigned long maxsize = 1024U);
  virtual ~JAWS_Assoc_Array (void);

  DATA * find (const KEY &k);
  DATA * operator[] (const KEY &k);
  // Returns the data associated with key k.

  DATA * insert (const KEY &k, const DATA &d);
  // Inserts a *copy* of the key and data into the associated array.
  // Both KEY and DATA must have well defined semantics for copy
  // construction.  This method returns a pointer to the inserted item
  // copy, or 0 if an error occurred.  NOTE: if an identical key
  // already exists in the tree, no new item is created, and the
  // returned pointer addresses the existing item associated with the
  // existing key.

  int remove (const KEY &k);
  // Removes the item associated with the given key from the
  // tree and destroys it.  Returns 1 if it found the item
  // and successfully destroyed it, 0 if it did not find the
  // item, or -1 if an error occurred.

  void clear (void);
  // Destroys all keys and associated data.

protected:

  unsigned long find_i (const KEY &k);
  // If k points to an associated data item, then this function
  // returns the index into the arrays that hold it.  Otherwise, it
  // returns an index suitable to insert the item.  If the item is not
  // found and the table is full, maxsize_ is returned.

private:
  KEY **k_array_;
  DATA **d_array_;
  unsigned long maxsize_;
};

template <class KEY, class DATA>
class JAWS_Assoc_Array_Iterator
{
public:

  JAWS_Assoc_Array_Iterator (const JAWS_Assoc_Array<KEY, DATA> &aa);
  ~JAWS_Assoc_Array_Iterator (void);

  KEY * key (void);
  DATA * data (void);

  int first (void);
  int last (void);
  int next (void);
  int previous (void);
  int is_done (void);

private:

  // declare private and do not define: explicitly
  // prevent assignment and copy construction of iterators
  JAWS_Assoc_Array_Iterator (const JAWS_Assoc_Array_Iterator<KEY, DATA> &);
  void operator= (const JAWS_Assoc_Array_Iterator<KEY, DATA> &);

private:

  const JAWS_Assoc_Array<KEY, DATA> &aa_;

  unsigned long i_;
  // The current item pointed by iterator.

  unsigned long j_;
  // The next item to be pointed to by iterator.

};

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "JAWS/Assoc_Array.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#endif /* !defined (JAWS_ASSOC_ARRAY_H) */
