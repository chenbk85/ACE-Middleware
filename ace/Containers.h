/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    ace
// 
// = FILENAME
//    Containers.h
//
// = AUTHOR
//    Doug Schmidt 
// 
// ============================================================================

#if !defined (ACE_CONTAINERS_H)
#define ACE_CONTAINERS_H

#include "ace/ACE.h"

class ACE_Allocator;

template <class T>
class ACE_Bounded_Stack 
  // = TITLE
  //     Implement a generic LIFO abstract data type.
  //     
  // = DESCRIPTION
  //     This implementation of a Stack uses a bounded array
  //     that is allocated dynamically.
{
public:
  // = Initialization, assignemnt, and termination methods.

  ACE_Bounded_Stack (size_t size);
  // Initialize a new stack so that it is empty. 

  ACE_Bounded_Stack (const ACE_Bounded_Stack<T> &s);
  // The copy constructor (performs initialization). 

  void operator= (const ACE_Bounded_Stack<T> &s);
  // Assignment operator (performs assignment). 

  ~ACE_Bounded_Stack (void); 
 // Perform actions needed when stack goes out of scope. 

  // = Classic Stack operations.

  int push (const T &new_item);
  // Place a new item on top of the stack.  Returns -1 if the stack
  // is already full, 0 if the stack is not already full, and -1 if
  // failure occurs.

  int pop (T &item);
  // Remove and return the top stack item.  Returns -1 if the stack is
  // already empty, 0 if the stack is not already empty, and -1 if
  // failure occurs.

  int top (T &item) const; 
  // Return top stack item without removing it.  Returns -1 if the
  // stack is already empty, 0 if the stack is not already empty, and
  // -1 if failure occurs.

  // = Check boundary conditions.

  int is_empty (void) const;
  // Returns 1 if the container is empty, otherwise returns 0. 

  int is_full (void) const;
  // Returns 1 if the container is full, otherwise returns 0. 

  size_t size (void) const;
  // The number of items in the stack.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  size_t size_;
  // Size of the dynamically allocated data.

  size_t top_; 
  // Keeps track of the current top of stack. 

  T *stack_; 
  // Holds the stack's contents. 
};

//----------------------------------------

template <class T, size_t SIZE>
class ACE_Fixed_Stack 
  // = TITLE
  //     Implement a generic LIFO abstract data type.
  //     
  // = DESCRIPTION
  //     This implementation of a Stack uses a fixed array
  //     with the size fixed at instantiation time.
{
public:
  // = Initialization, assignemnt, and termination methods.
  ACE_Fixed_Stack (void);
  // Initialize a new stack so that it is empty. 

  ACE_Fixed_Stack (const ACE_Fixed_Stack<T, SIZE> &s);
  // The copy constructor (performs initialization). 

  void operator= (const ACE_Fixed_Stack<T, SIZE> &s);
  // Assignment operator (performs assignment). 

  ~ACE_Fixed_Stack (void); 
  // Perform actions needed when stack goes out of scope. 

  // = Classic Stack operations.

  int push (const T &new_item);
  // Place a new item on top of the stack.  Returns -1 if the stack
  // is already full, 0 if the stack is not already full, and -1 if
  // failure occurs.

  int pop (T &item);
  // Remove and return the top stack item.  Returns -1 if the stack is
  // already empty, 0 if the stack is not already empty, and -1 if
  // failure occurs.

  int top (T &item) const; 
  // Return top stack item without removing it.  Returns -1 if the
  // stack is already empty, 0 if the stack is not already empty, and
  // -1 if failure occurs.

  // = Check boundary conditions.

  int is_empty (void) const;
  // Returns 1 if the container is empty, otherwise returns 0. 

  int is_full (void) const;
  // Returns 1 if the container is full, otherwise returns 0. 

  size_t size (void) const;
  // The number of items in the stack.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  size_t size_;
  // Size of the allocated data.

  size_t top_; 
  // Keeps track of the current top of stack. 

  T stack_[SIZE];
  // Holds the stack's contents. 
};

//----------------------------------------

// Forward declarations.
template <class T> class ACE_Unbounded_Set;
template <class T> class ACE_Unbounded_Set_Iterator;
template <class T> class ACE_Unbounded_Queue;
template <class T> class ACE_Unbounded_Queue_Iterator;
template <class T> class ACE_Unbounded_Stack;
template <class T> class ACE_Unbounded_Stack_Iterator;

template<class T>
class ACE_Node
  // = TITLE
  //     Implementation element in a Queue.
{
  friend class ACE_Unbounded_Queue<T>;
  friend class ACE_Unbounded_Queue_Iterator<T>;
  friend class ACE_Unbounded_Set<T>;
  friend class ACE_Unbounded_Set_Iterator<T>;
  friend class ACE_Unbounded_Stack<T>;
  friend class ACE_Unbounded_Stack_Iterator<T>;
private:
  // = Initialization methods
  ACE_Node (const T &i, ACE_Node<T> *n);
  ACE_Node (ACE_Node<T> *n = 0, int MS_SUCKS = 0);
  ACE_Node (const ACE_Node<T> &n);

  ~ACE_Node (void);
  // This isn't necessary, but it keeps the compiler happy.

  ACE_Node<T> *next_;
  // Pointer to next element in the list of <ACE_Node>s.

  T item_;
  // Current value of the item in this node.
};

#if defined (NANBOR_EXP_CODES)
class ACE_DNode_Base
  // = TITLE
  //     Implement the minimum stuff a node in a double
  //     linked list should have.
  //
  // = DESCRIPTION
  //     Basic functionalities an element in double-linked
  //     lists.  This is an abstract class and can't be
  //     instantiated.
{
  friend class ACE_Double_Linked_List_Iterator_Base;
  friend class ACE_Double_Linked_List_Base;

public:
  ACE_DNode_Base (void);
  // Default do nothing ctor.

  //  ACE_DNode_Base (ACE_DNode_Base *n, ACE_DNode_Base *p);
  // Build and set ctor.
  
protected:
  ACE_DNode_Base *prev_;
  // Pointer to previous element in the list.

  ACE_DNode_Base *next_;
  // Pointer to next element in the list.
};

class ACE_Double_Linked_List_Base;
// forward declaration

class ACE_Double_Linked_List_Iterator_Base
  // = TITLE
  //      Basic double-linked list iterator functionalities.
  //
  // = DESCRIPTION
  //      
{
public:
  ACE_Double_Linked_List_Iterator_Base
    (ACE_Double_Linked_List_Base &dll);
  // Constructor.

protected:
  ACE_DNode_Base *not_done (void) ;
  // Check if we reach the end of the list.  Can also be used to get
  // the *current* element in the list.  Return the address of the
  // current item if there are still elements left , 0 if we run out of element.

  ACE_DNode_Base *do_advance (void);
  // Advance to the next element in the list.  Return the address of the
  // next element if there are more, 0 otherwise.

  // @@ This function seems redundant.
//   ACE_DNode_Base *next (void);
//   // Get the next unvisit element from the list.  Return address if succeed,
//   // 0 otherwise.

  ACE_DNode_Base *current_;
  // Remember where we are.

  ACE_Double_Linked_List_Base &dllist_;
};

class ACE_Double_Linked_List_Base
  // = TITLE
  //      Basic double-linked list implementation.
  //
  // = DESCRIPTION
  //      This is a barebone implementation of double-linked lists.
  //      It only provide a minimum set of functionalities to
  //      work.  You must subclass from it and other related classes
  //      for them to work correctly.
{
  friend class ACE_Double_Linked_List_Iterator_Base;

public:
  size_t size (void);
  // Return current size of the list.

protected:
  // We hide these function here because they are not supposed to
  // be used directly.  Notice that all these functions have only
  // limited error detections.

  ACE_Double_Linked_List_Base (void);
  // Default ctor.
  
  void init_head (void);
  // Setup header pointer.  Called after we create the head node in ctor.

  int insert_element (ACE_DNode_Base *new_item,
                      int before = 0,
                      ACE_DNode_Base *old_item = 0);
  // Insert a <new_element> into the list.  It will be added before
  // or after <old_item>.  Default is to insert the new item *after*
  // <head_>.  Return 0 if succeed, -1 if error occured.  

  int remove_element (ACE_DNode_Base *item);
  // Remove an <item> from the list.  Return 0 if succeed, -1 otherwise.
  // Notice that this function only checks if item is <head_>.  Users
  // must ensure the item is in the list.
  
  ACE_Double_Linked_List_Iterator_Base *iter (void);
  // Iterator factory.

  ACE_DNode_Base *head_;
  // Head of the circular double-linked list.

  size_t size_;
  // Size of this list. 
};

template <class T>
class ACE_DNode : public ACE_DNode_Base
// = TITLE
//     Implementation element in a Double-linked List.
{
  friend class ACE_Double_Linked_List<T>;
  friend class ACE_Double_Linked_List_Iterator<T>;
protected:
  ACE_DNode (const T &i, ACE_DNode<T> *n = 0, ACE_DNode<T> *p = 0);
  ACE_DNode (const ACE_DNode<T> &i);

  ~ACE_DNode (void);

  T item_;
};
#endif /* NANBOR_EXP_CODES */

template <class T>
class ACE_Unbounded_Stack 
  // = TITLE
  //     Implement a generic LIFO abstract data type.
  //     
  // = DESCRIPTION
  //     This implementation of an unbounded Stack uses a linked list.
{
  friend class ACE_Unbounded_Stack_Iterator<T>;
public:
  // = Initialization, assignemnt, and termination methods.
  ACE_Unbounded_Stack (ACE_Allocator *alloc = 0);
  // Initialize a new stack so that it is empty.  Use user defined
  // allocation strategy if specified.

  ACE_Unbounded_Stack (const ACE_Unbounded_Stack<T> &s);
  // The copy constructor (performs initialization). 

  void operator= (const ACE_Unbounded_Stack<T> &s);
  // Assignment operator (performs assignment). 

  ~ACE_Unbounded_Stack (void); 
  // Perform actions needed when stack goes out of scope. 

  // = Classic Stack operations.

  int push (const T &new_item);
  // Place a new item on top of the stack.  Returns -1 if the stack
  // is already full, 0 if the stack is not already full, and -1 if
  // failure occurs.

  int pop (T &item);
  // Remove and return the top stack item.  Returns -1 if the stack is
  // already empty, 0 if the stack is not already empty, and -1 if
  // failure occurs.

  int top (T &item) const; 
  // Return top stack item without removing it.  Returns -1 if the
  // stack is already empty, 0 if the stack is not already empty, and
  // -1 if failure occurs.

  // = Check boundary conditions.

  int is_empty (void) const;
  // Returns 1 if the container is empty, otherwise returns 0. 

  int is_full (void) const;
  // Returns 1 if the container is full, otherwise returns 0. 

  // = Auxiliary methods (not strictly part of the Stack ADT).

  int insert (const T &new_item);
  // Insert <new_item> into the Stack at the head (but doesn't allow
  // duplicates).  Returns -1 if failures occur, 1 if item is already
  // present, else 0.
  
  int remove (const T &item);
  // Remove <item> from the Stack.  Returns 0 if it removes the item,
  // -1 if it can't find the item, and -1 if a failure occurs.

  int find (const T &item) const;
  // Finds if <item> occurs the set.  Returns 0 if finds, else -1.

  size_t size (void) const;
  // The number of items in the stack.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  void delete_all_nodes (void);
  // Delete all the nodes in the stack.

  void copy_all_nodes (const ACE_Unbounded_Stack<T> &s);
  // Copy all nodes from <s> to <this>.

  ACE_Node<T> *head_;
   // Head of the linked list of Nodes.

  size_t cur_size_;
  // Current size of the stack.

  ACE_Allocator *allocator_;
  // Allocation strategy of the stack.
};

template <class T>
class ACE_Unbounded_Stack_Iterator
  // = TITLE
  //     Implement an iterator over an unbounded Stack.
{
public:
  // = Initialization method.
  ACE_Unbounded_Stack_Iterator (ACE_Unbounded_Stack<T> &);

  // = Iteration methods.

  int next (T *&next_item);
  // Pass back the <next_item> that hasn't been seen in the Stack.
  // Returns 0 when all items have been seen, else 1.

  int advance (void);
  // Move forward by one element in the Stack.  Returns 0 when all the
  // items in the Stack have been seen, else 1.

  int done (void) const;
  // Returns 1 when all items have been seen, else 0.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  ACE_Node<T> *current_;
  // Pointer to the current node in the iteration.

  ACE_Unbounded_Stack<T> &stack_;
  // Pointer to the Stack we're iterating over.
};

template <class T>
class ACE_Unbounded_Queue;

template <class T>
class ACE_Unbounded_Queue_Iterator
  // = TITLE
  //     Implement an iterator over an unbounded queue.
{
public:
  // = Initialization method.
  ACE_Unbounded_Queue_Iterator (ACE_Unbounded_Queue<T> &);

  // = Iteration methods.

  int next (T *&next_item);
  // Pass back the <next_item> that hasn't been seen in the queue.
  // Returns 0 when all items have been seen, else 1.

  int advance (void);
  // Move forward by one element in the set.  Returns 0 when all the
  // items in the queue have been seen, else 1.

  int done (void) const;
  // Returns 1 when all items have been seen, else 0.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  ACE_Node<T> *current_;
  // Pointer to the current node in the iteration.

  ACE_Unbounded_Queue<T> &queue_;
  // Pointer to the queue we're iterating over.
};

template <class T>
class ACE_Unbounded_Queue
  // = TITLE
  //     A Queue of "infinite" length.
  //
  // = DESCRIPTION
  //     This implementation of an unbounded queue uses a circular
  //     linked list with a dummy node.
{
  friend class ACE_Unbounded_Queue_Iterator<T>;
public:
  // = Initialization and termination methods.
  ACE_Unbounded_Queue (ACE_Allocator *alloc = 0);
  // construction.  Use user specified allocation strategy
  // if specified.

  ACE_Unbounded_Queue (const ACE_Unbounded_Queue<T> &);
  // Copy constructor. 

  void operator= (const ACE_Unbounded_Queue<T> &);
  // Assignment operator.

  ~ACE_Unbounded_Queue (void);
  // construction.

  // = Check boundary conditions.

  int is_empty (void) const;
  // Returns 1 if the container is empty, otherwise returns 0. 

  int is_full (void) const;
  // Returns 1 if the container is full, otherwise returns 0. 

  // = Classic queue operations.

  int enqueue_tail (const T &new_item);
  // Adds <new_item> to the tail of the queue.  Returns 0 on success,
  // -1 on failure.

  int enqueue_head (const T &new_item);
  // Adds <new_item> to the head of the queue.  Returns 0 on success,
  // -1 on failure.

  int dequeue_head (T &item);
  // Removes and returns the first <item> on the queue.  Returns 0 on
  // success, -1 if the queue was empty.

  // = Additional utility methods.

  void reset (void);
  // Reset the <ACE_Unbounded_Queue> to be empty.

  int get (T *&item, size_t index = 0) const;
  // Get the <index>th element in the set.  Returns -1 if the element
  // isn't in the range <0..size() - 1>, else 0.

  int set (const T &item, size_t index);
  // Set the <index>th element in the set.  Will pad out the set with
  // empty nodes if <index> is beyond the range <0..size() - 1>.
  // Returns -1 on failure, 0 if <index> isn't initially in range, and
  // 0 otherwise.

  size_t size (void) const;
  // The number of items in the queue.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

protected:
  void delete_nodes (void);
  // Delete all the nodes in the queue.

  void copy_nodes (const ACE_Unbounded_Queue<T> &);
  // Copy nodes into this queue.

  ACE_Node<T> *head_;
  // Pointer to the dummy node in the circular linked Queue.

  size_t cur_size_;
  // Current size of the queue.

  ACE_Allocator *allocator_;
  // Allocation Strategy of the queue.
};

#if defined (NANBOR_EXP_CODES)
template <class T>
class ACE_Double_Linked_List;

template <class T>
class ACE_Double_Linked_List_Iterator
  // = TITLE
  //     Implement an iterator over a container double-linked list
  //
  // = DESCRIPTION
  //     Iterate thru the double-linked list.  This class provide
  //     an interface that let users access the internal element
  //     addresses directly, which (IMHO) seems to break the
  //     encasulation.
{
public:
  // = Initialization method.
  ACE_Double_Linked_List_Iterator (ACE_Double_Linked_List<T> &);

  // = Iteration methods.

  ACE_DNode<T> *next (void);
  // Return the address of next (current) unvisited ACE_DNode,
  // 0 if there is no more element available.

  int next (T *&next_item);
  // Pass back the <next_item> that hasn't been seen in the Stack.
  // Returns 0 when all items have been seen, else 1.

  int advance (void);
  // Move forward by one element in the Stack.  Returns 0 when all the
  // items in the Stack have been seen, else 1.

  int done (void) const;
  // Returns 1 when all items have been seen, else 0.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.
};


template <class T>
class ACE_Double_Linked_List
  // = TITLE
  //     A double-linked list implementation.
  //
  // = DESCRIPTION
  //     This implementation of an unbounded double-linked list uses a circular
  //     linked list with a dummy node.  It is pretty much like the ACE_Unbounded_Queue
  //     except that it allows removing of a specific element from a specific location.
{
  friend class ACE_Double_Linked_List_Iterator<T>;
public:
  // = Initialization and termination methods.
  ACE_Double_Linked_List (ACE_Allocator *alloc = 0);
  // construction.  Use user specified allocation strategy
  // if specified.

  ACE_Double_Linked_List (const ACE_Double_Linked_List<T> &);
  // Copy constructor. 

  void operator= (const ACE_Double_Linked_List<T> &);
  // Assignment operator.

  ~ACE_Double_Linked_List (void);
  // Destructor.

  // = Check boundary conditions.

  int is_empty (void) const;
  // Returns 1 if the container is empty, otherwise returns 0. 

  int is_full (void) const;
  // Returns 1 if the container is full, otherwise returns 0. 

  // = Classic queue operations.

  ACE_DNode<T> *insert_tail (const T &new_item);
  // Adds <new_item> to the tail of the list.  Returns 0 on success,
  // -1 on failure.

  ACE_DNode<T> *insert_head (const T &new_item);
  // Adds <new_item> to the head of the list.  Returns 0 on success,
  // -1 on failure.

  int delete_head (T &item);
  // Removes and returns the first <item> in the list.  Returns 0 on
  // success, -1 if the queue was empty.  This method will free the
  // internal node.

  int delete_tail (T &item);
  // Removes and returns the last <item> in the list.  Returns 0 on
  // success, -1 if the queue was empty. This method will free the
  // internal node.

  // = Additional utility methods.

  void reset (void);
  // Reset the <ACE_Double_Linked_List> to be empty.

  int get (T *&item, size_t index = 0) const;
  // Get the <index>th element in the set.  Returns -1 if the element
  // isn't in the range <0..size() - 1>, else 0.

  int set (const T &item, size_t index);
  // Set the <index>th element in the set.  Will pad out the set with
  // empty nodes if <index> is beyond the range <0..size() - 1>.
  // Returns -1 on failure, 0 if <index> isn't initially in range, and
  // 0 otherwise.

  size_t size (void) const;
  // The number of items in the queue.

  void dump (void) const;
  // Dump the state of an object.

  ACE_DNode<T> *find (const T &item);
  // Locate the DNode address that contains the item. Return
  // an address if succeed, 0 otherwise.

  int remove (const T &item);
  // This function will iterate thru the double-linked list and remove
  // it from the list.  Return Node address if succeed, 0 otherwise.
  // Notice that this method will *not* free the internal node.  The
  // node is simple unlinked from the list.

  int remove (ACE_DNode<T> *n);
  // Use DNode address directly.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

protected:
  void delete_nodes (void);
  // Delete all the nodes in the list.

  void copy_nodes (const ACE_Double_Linked_List<T> &);
  // Copy nodes into this list.

  ACE_Allocator *allocator_;
  // Allocation Strategy of the queue.
};
#endif /* NANBOR_EXP_CODES */

template <class T>
class ACE_Unbounded_Set_Iterator
  // = TITLE
  //     Implement an iterator over an unbounded set.
{
public:
  // = Initialization method.
  ACE_Unbounded_Set_Iterator (ACE_Unbounded_Set<T> &s);

  // = Iteration methods.

  int next (T *&next_item);
  // Pass back the <next_item> that hasn't been seen in the Set.
  // Returns 0 when all items have been seen, else 1.

  int advance (void);
  // Move forward by one element in the set.  Returns 0 when all the
  // items in the set have been seen, else 1.

  int done (void) const;
  // Returns 1 when all items have been seen, else 0.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  ACE_Node<T> *current_;
  // Pointer to the current node in the iteration.

  ACE_Unbounded_Set<T> &set_;
  // Pointer to the set we're iterating over.
};

template <class T>
class ACE_Unbounded_Set
  // = TITLE
  //     Implement a simple unordered set of <T> of unbounded size.
  //     
  // = DESCRIPTION
  //     This implementation of an unordered set uses a circular
  //     linked list with a dummy node.  This implementation does not
  //     allow duplicates, but it maintains FIFO ordering of insertions.
{
friend class ACE_Unbounded_Set_Iterator<T>;
public:
  // = Initialization and termination methods.
  ACE_Unbounded_Set (ACE_Allocator *alloc = 0);
  // Constructor.  Use user specified allocation strategy
  // if specified.

  ACE_Unbounded_Set (const ACE_Unbounded_Set<T> &);
  // Copy constructor. 

  void operator= (const ACE_Unbounded_Set<T> &);
  // Assignment operator.

  ~ACE_Unbounded_Set (void);
  // Destructor.

  // = Check boundary conditions.

  int is_empty (void) const;
  // Returns 1 if the container is empty, otherwise returns 0. 

  int is_full (void) const;
  // Returns 1 if the container is full, otherwise returns 0. 

  // = Classic unordered set operations.

  int insert (const T &new_item);
  // Insert <new_item> into the set (doesn't allow duplicates).
  // Returns -1 if failures occur, 1 if item is already present, else
  // 0.
  
  int remove (const T &item);
  // Remove first occurrence of <item> from the set.  Returns 0 if
  // it removes the item, -1 if it can't find the item, and -1 if a
  // failure occurs.

  int find (const T &item) const;
  // Finds if <item> occurs in the set.  Returns 0 if find succeeds,
  // else -1.

  size_t size (void) const;
  // Size of the set.

  void dump (void) const;
  // Dump the state of an object.

  void reset (void);
  // Reset the <ACE_Unbounded_Set> to be empty.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  int insert_tail (const T &item);
  // Insert <item> at the tail of the set (doesn't check for
  // duplicates).

  void delete_nodes (void);
  // Delete all the nodes in the Set.

  void copy_nodes (const ACE_Unbounded_Set<T> &);
  // Copy nodes into this set.

  ACE_Node<T> *head_;
   // Head of the linked list of Nodes.

  size_t cur_size_;
  // Current size of the set.

  ACE_Allocator *allocator_;
  // Allocation strategy of the set.
};

// Forward declaration.
template <class T, size_t SIZE> 
class ACE_Fixed_Set;

template <class T, size_t SIZE>
class ACE_Fixed_Set_Iterator
  // = TITLE
  //     Interates through an unordered set.
  //     
  // = DESCRIPTION
  //     This implementation of an unordered set uses a fixed array.
  //     Allows deletions while iteration is occurring.
{
public:
  // = Initialization method.
  ACE_Fixed_Set_Iterator (ACE_Fixed_Set<T, SIZE> &s);

  // = Iteration methods.

  int next (T *&next_item);
  // Pass back the <next_item> that hasn't been seen in the Set.
  // Returns 0 when all items have been seen, else 1.

  int advance (void);
  // Move forward by one element in the set.  Returns 0 when all the
  // items in the set have been seen, else 1.

  int done (void) const;
  // Returns 1 when all items have been seen, else 0.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  ACE_Fixed_Set<T, SIZE> &s_; 
  // Set we are iterating over.

  ssize_t next_;
  // How far we've advanced over the set.
};

template <class T, size_t SIZE>
class ACE_Fixed_Set
  // = TITLE
  //     Implement a simple unordered set of <T> with maximum <SIZE>.
  //     
  // = DESCRIPTION
  //     This implementation of an unordered set uses a fixed array.
  //     This implementation does not allow duplicates...
{
friend class ACE_Fixed_Set_Iterator<T, SIZE>;
public:
  // = Initialization and termination methods.
  ACE_Fixed_Set (void);
  // Constructor.

  ACE_Fixed_Set (const ACE_Fixed_Set<T, SIZE> &);
  // Copy constructor. 

  void operator= (const ACE_Fixed_Set<T, SIZE> &);
  // Assignment operator.

  ~ACE_Fixed_Set (void);
  // Destructor.

  // = Check boundary conditions.

  int is_empty (void) const;
  // Returns 1 if the container is empty, otherwise returns 0. 

  int is_full (void) const;
  // Returns 1 if the container is full, otherwise returns 0. 

  // = Classic unordered set operations.

  int insert (const T &new_item);
  // Insert <new_item> into the set (doesn't allow duplicates).
  // Returns -1 if failures occur, 1 if item is already present, else
  // 0.
  
  int remove (const T &item);
  // Remove first occurrence of <item> from the set.  Returns 0 if
  // it removes the item, -1 if it can't find the item, and -1 if a
  // failure occurs.
  
  int find (const T &item) const;
  // Finds if <item> occurs in the set.  Returns 0 if finds, else -1.

  size_t size (void) const;
  // Size of the set.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  struct
  {
    T item_;
    // Item in the set.

    int is_free_;
    // Keeps track of whether this item is in use or not.
  } search_structure_[SIZE];
  // Holds the contents of the set.

  size_t cur_size_;
  // Current size of the set.
  
  size_t max_size_;
  // Maximum size of the set.
};

// Forward declaration.
template <class T> 
class ACE_Bounded_Set;

template <class T>
class ACE_Bounded_Set_Iterator
  // = TITLE
  //     Interates through an unordered set.
  //     
  // = DESCRIPTION
  //     This implementation of an unordered set uses a Bounded array.
  //     Allows deletions while iteration is occurring.
{
public:
  // = Initialization method.
  ACE_Bounded_Set_Iterator (ACE_Bounded_Set<T> &s);

  // = Iteration methods.

  int next (T *&next_item);
  // Pass back the <next_item> that hasn't been seen in the Set.
  // Returns 0 when all items have been seen, else 1.

  int advance (void);
  // Move forward by one element in the set.  Returns 0 when all the
  // items in the set have been seen, else 1.

  int done (void) const;
  // Returns 1 when all items have been seen, else 0.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  ACE_Bounded_Set<T> &s_; 
  // Set we are iterating over.

  ssize_t next_;
  // How far we've advanced over the set.
};

template <class T>
class ACE_Bounded_Set
  // = TITLE
  //     Implement a simple unordered set of <T> with maximum 
  //     set at creation time.
  // 
  // = DESCRIPTION
  //     This implementation of an unordered set uses a Bounded array.
  //     This implementation does not allow duplicates...
{
friend class ACE_Bounded_Set_Iterator<T>;
public:
  enum 
  {
    DEFAULT_SIZE = 10
  };

  // = Initialization and termination methods.
  ACE_Bounded_Set (void);
  // Constructor.

  ACE_Bounded_Set (size_t size);
  // Constructor.

  ACE_Bounded_Set (const ACE_Bounded_Set<T> &);
  // Copy constructor. 

  void operator= (const ACE_Bounded_Set<T> &);
  // Assignment operator.

  ~ACE_Bounded_Set (void);
  // Destructor

  // = Check boundary conditions.

  int is_empty (void) const;
  // Returns 1 if the container is empty, otherwise returns 0. 

  int is_full (void) const;
  // Returns 1 if the container is full, otherwise returns 0. 

  // = Classic unordered set operations.

  int insert (const T &new_item);
  // Insert <new_item> into the set (doesn't allow duplicates).
  // Returns -1 if failures occur, 1 if item is already present, else
  // 0.
  
  int remove (const T &item);
  // Remove first occurrence of <item> from the set.  Returns 0 if it
  // removes the item, -1 if it can't find the item, and -1 if a
  // failure occurs.
  
  int find (const T &item) const;
  // Finds if <item> occurs in the set.  Returns 0 if finds, else -1.

  size_t size (void) const;
  // Size of the set.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  struct Search_Structure
  {
    T item_;
    // Item in the set.

    int is_free_;
    // Keeps track of whether this item is in use or not.
  };

  Search_Structure *search_structure_;
  // Holds the contents of the set.

  size_t cur_size_;
  // Current size of the set.
  
  size_t max_size_;
  // Maximum size of the set.
};

#if defined (__ACE_INLINE__)
#include "ace/Containers.i"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Containers.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Containers.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* ACE_CONTAINERS_H */
