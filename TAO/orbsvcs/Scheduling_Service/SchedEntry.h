/* -*- C++ -*- */
//
// $Id$
//
// ============================================================================
//
// = LIBRARY
//    sched
//
// = FILENAME
//    SchedEntry.h
//
// = CREATION DATE
//    7 February 1998
//
// = AUTHOR
//    Chris Gill
//
// ============================================================================


// forward declaration of classes
class Task_Entry;
class Task_Entry_Link;
class Dispatch_Entry;
class Dispatch_Entry_Link;
class Dispatch_Proxy_Iterator;


// Wrapper for the RT_Info, which aggregates all its dispatches
class Task_Entry
{
public:
  // info for DFS traversal, topological sort of call graph
  enum DFS_Status {NOT_VISITED, VISITED, FINISHED};

  // ctor
  Task_Entry ();

  // dtor
  ~Task_Entry ();

  // merge dispatches according to info type, update
  // relevant scheduling characteristics for this entry.
  // Returns 0 if all is well, or -1 if an error occurred
  int merge_dispatches (
    ACE_Unbounded_Set <Dispatch_Entry *> &dispatch_entries);

  // get pointer to underlying RT_Info
  RT_Info *rt_info ();

  // get effective period for the task entry
  Period effective_period ();

  // set/get time when node was discovered in DFS traversal
  void discovered (long l);
  long discovered ();

  // set/get time when node was finished in DFS traversal
  void finished (long l);
  long finished ();
 
  // set/get DFS traversal status of node
  void dfs_status (DFS_Status ds);
  DFS_Status dfs_status ();

  // set/get flag indicating whether node is a thread delineator
  void is_thread_delineator (int i);
  int is_thread_delineator ();

  // get set of links to Task Entries which this entry calls
  ACE_Unbounded_Set <Task_Entry_Link *> & calls ();

  // get set of links to Task Entries which call this entry
  ACE_Unbounded_Set <Task_Entry_Link *> & callers ();

  // get the type of Info the entry wraps
  Info_Type info_type ();

  // effective execution time for the task entry
  u_long effective_execution_time ();

private:

  // prohibit calls of the given type: currently used to enforce
  // the notion that two-way calls to disjunctive or conjunctive
  // RT_Infos do not have any defined meaning, and thus should be
  // considered dependency specification errors: if these constraints
  // are removed in the future, this method should be removed as well
  // Returns 0 if all is well, or -1 if an error has occurred.
  int prohibit_dispatches (Dependency_Type dt);

  // performs disjunctive merge of arrival times of calls of the given 
  // type: all arrival times of all callers of that type are duplicated by
  // the multiplier and repetition over the new frame size and merged.
  // Returns 0 if all is well, or -1 if an error has occurred.
  int disjunctive_merge (
    Dependency_Type dt, 
    ACE_Unbounded_Set <Dispatch_Entry *> &dispatch_entries);

  // perform conjunctive merge of arrival times of calls of the given
  // type: all arrival times of all callers of that type are duplicated
  //  by the multiplier and repetition over the new frame size and then
  // iteratively merged by choosing the maximal arrival time at
  // the current position in each queue (iteration is in lockstep
  // over all queues, and ends when any queue ends).  Returns 0 if
  // all is well, or -1 if an error has occurred.
  int conjunctive_merge (
    Dependency_Type dt, 
    ACE_Unbounded_Set <Dispatch_Entry *> &dispatch_entries);


  // this static method is used to reframe an existing dispatch set
  // to the given new period multiplier, creating new instances of
  // each existing dispatch (with adjusted arrival and deadline)
  // in each successive sub-frame.  Returns 1 if the set was reframed
  // to a new period, 0 if the set was not changed (the new period
  // was not a multiple of the old one), or -1 if an error occurred.
  static int reframe (ACE_Ordered_MultiSet <Dispatch_Entry_Link> &set,
                      u_long &set_period, u_long new_period);

  // this static method is used to merge an existing dispatch set,
  // multiplied by the given multipliers for the period and number of
  // instances in each period of each existing dispatch, into the
  // given "into" set, without affecting the "from set". Returns 1 if
  // the source set was correctly merged into the destination set,
  // 0 if nothing happened, and -1 if an error occurred.
  static int merge_frames (ACE_Ordered_MultiSet <Dispatch_Entry_Link> &dest,
                           ACE_Ordered_MultiSet <Dispatch_Entry_Link> &src,
                           u_long &dest_period,
                           u_long src_period,
                           u_long number_of_calls = 1,
                           u_long starting_dest_sub_frame = 0);

  // pointer to the underlying RT_Info
  RT_Info *rt_info_;

  // effective period for the task entry
  Period effective_period_;

  // queue of arrivals in the effective period
  ACE_Ordered_MultiSet<Dispatch_Entry_Link> dispatches_;
      
  // count of the arrivals in the effective period
  u_long arrival_count_;

  DFS_Status dfs_status_;
  long discovered_;
  long finished_;

  // info for identifying threads in the oneway call graph
  int is_thread_delineator_;

  // get set of links to Task Entries which this entry calls
  ACE_Unbounded_Set <Task_Entry_Link *> calls_;

  // get set of links to Task Entries which call this entry
  ACE_Unbounded_Set <Task_Entry_Link *> callers_;
};


class Task_Entry_Link
{
public:

  // ctor
  Task_Entry_Link (Task_Entry &caller,
                   Task_Entry &called,
                   CORBA::Long number_of_calls,
                   Dependency_Type dependency_type);

  // accessor: number of calls
CORBA::Long number_of_calls () const;

  // accessor: dependency type
Dependency_Type dependency_type () const;

// accessor: calling task entry
  Task_Entry &caller () const;
  
// accessor: called task entry
Task_Entry &called () const;

private:

  // the number of calls of the operation
  CORBA::Long number_of_calls_;

  // the calling operation
  Task_Entry &caller_;

  // the called operation
  Task_Entry &called_;

// the type of call dependency
Dependency_Type dependency_type_;
};


class Dispatch_Entry
{
// = TITLE
//	  Dispatch Entry
//
// = DESCRIPTION
//     Descriptor object for a single dispatch of an operation.
//
public:

typedef u_long Dispatch_Id;

  // ctor
  Dispatch_Entry (Time arrival,
                  Time deadline,
                  Preemption_Priority priority,
                  Task_Entry &task_entry);

  // copy ctor
  Dispatch_Entry (const Dispatch_Entry &d);

  // id accessor
  Dispatch_Id dispatch_id ();

  // arrival accessor
  Time arrival ();

  // deadline accessor
  Time deadline ();

  // scheduler priority accessor and mutator
  Preemption_Priority priority ();
  void priority (Preemption_Priority p);

  // scheduler priority accessor and mutator
  OS_Priority Dispatch_Entry::OS_priority ();
  void Dispatch_Entry::OS_priority (OS_Priority p);

  // dynamic subpriority accessor and mutator
  Sub_Priority dynamic_subpriority ();
  void dynamic_subpriority (Sub_Priority p);

  // static subpriority accessor and mutator
  Sub_Priority static_subpriority ();
  void static_subpriority (Sub_Priority p);

  // task entry accessor
  Task_Entry &task_entry ();

  // GT comparator
  //  TBD - make this a global comparison operator
  //  instead of a class member function
  int operator < (const Dispatch_Entry &d) const;


private:
  // TBD - add reference counting to Dispatch Entry class,
  // make the link a friend, up/down count as links come and go,
  // and call entry dtor when ref count drops to 0

  // stores the next dispatch entry id to be used
  static Dispatch_Id next_id_;

  // the id of the current dispatch entry
  Dispatch_Id dispatch_id_;

  // scheduler priority of the current dispatch entry
  Preemption_Priority priority_;

  // OS priority of the current dispatch entry
  OS_Priority OS_priority_;

  // scheduler dynamic subpriority of the current dispatch entry
  Sub_Priority dynamic_subpriority_;

  // scheduler static subpriority of the current dispatch entry
  Sub_Priority static_subpriority_;

  // the arrival time of the current dispatch entry
  Time arrival_;

  // the deadline of the current dispatch entry
  Time deadline_;

  // stores the id of the related task entry
  Task_Entry &task_entry_;

};

class Dispatch_Entry_Link
// = TITLE
//	  Dispatch Entry Link
//
// = DESCRIPTION
//    Light-weight sortable "smart pointer" to a dispatch entry.
//
{
  Dispatch_Entry_Link (Dispatch_Entry &d);
    // ctor

  Dispatch_Entry_Link (const Dispatch_Entry_Link &d);
    // copy ctor

  ~Dispatch_Entry_Link ();
    // dtor

  void operator = (const Dispatch_Entry_Link &d);
    // assignment operator

  // TBD - make this a global comparison operator
  // instead of a class member function
  int operator < (const Dispatch_Entry_Link &d) const;
    // GT comparator

  Dispatch_Entry &dispatch_entry () const;
    // accessor for reference to dispatch entry

  private:

    Dispatch_Entry &dispatch_entry_;
};

class Dispatch_Proxy_Iterator
// = TITLE
//   This class implements an iterator abstraction over a virtual
//   frame size and number of calls, using an actual ordered 
//   multiset of dispatch entries over an actual frame size.
//   It also serves as a proxy for the virtual dispatch to which
//   it refers.  Rhetorical question: is it possible to separate
//   the iterator and proxy abstractions here without defeating the
//   purpose of the design, which is to avoid constructing 
//   superfluous dispatch entries (per the conjunctive merge use case) ?
{
public:

  Dispatch_Proxy_Iterator (ACE_Ordered_MultiSet <Dispatch_Entry_Link> set,
                           u_long actual_frame_size,
                           u_long virtual_frame_size,
                           u_long number_of_calls_ = 1, 
                           u_long starting_sub_frame = 0);
    // ctor

  ////////////////////////
  // iterator interface //
  ////////////////////////

  int done ();
    // returns 0 if there are more entries to see, 1 if not

  int first (u_int sub_frame = 0);
    // positions the iterator at the first entry of the passed 
    // sub-frame, returns 1 if it could position the iterator
    // correctly, 0 if not, and -1 if an error occurred.

  in last ();
    // positions the iterator at the last entry of the total
    // frame, returns 1 if it could position the iterator
    // correctly, 0 if not, and -1 if an error occurred.

  int advance ();
    // positions the iterator at the next entry of the total
    // frame, returns 1 if it could position the iterator
    // correctly, 0 if not, and -1 if an error occurred.

  int retreat ();
    // positions the iterator at the previous entry of the total
    // frame, returns 1 if it could position the iterator
    // correctly, 0 if not, and -1 if an error occurred.

  /////////////////////
  // proxy interface //
  /////////////////////

  u_long arrival ();
    // returns the adjusted arrival time of the virtual entry

  u_long deadline ();
    // returns the adjusted deadline time of the virtual entry

  Preemption_Priority priority ();
    // returns the scheduler priority of the virtual entry
                 

private:

  u_long number_of_calls_;
    // the number of calls corresponding to each actual dispatch

  u_long current_call_;
    // the current call number for this dispatch (zero based)

  u_long actual_frame_size_;
    // the frame size of the actual dispatches

  u_long virtual_frame_size_;
    // the virtaul frame size over which to iterate

  u_long current_frame_offset_;
    // the current offset into the virtual frame 
    // (should be a multiple of the actual frame size)

  ACE_Ordered_MultiSet_Iterator <Dispatch_Entry_Link> iter_;
};



class TimeLine_Entry
{
public:

    // time slice constructor 
    TimeLine_Entry (Dispatch_Entry &dispatch_entry,
                    u_long start,
                    u_long stop,
                    TimeLine_Entry *next = 0,
                    TimeLine_Entry *prev = 0);

    // dispatch entry accessor
    Dispatch_Entry &dispatch_entry ();

    // accessors for time slice start and stop times (100 nanoseconds)
    u_long start ();  
    u_long stop (); 

    // accessor and mutator for next and prev slices for this dispatch
    TimeLine_Entry *next (void);
    void next (TimeLine_Entry *);
    TimeLine_Entry *prev (void);
    void prev (TimeLine_Entry *);

private:

    // the dispatch entry to which the time slice corresponds
    Dispatch_Entry &dispatch_entry_;

    // priority time slice start and stop times (100 nanoseconds)
    u_long start_;  
    u_long stop_; 

    // next and previous priority time slices for this dispatch entry
    TimeLine_Entry *next_;
    TimeLine_Entry *prev_;

};

