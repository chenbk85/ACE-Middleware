// $Id$

// ===========================================================
//
// = LIBRARY
//    TAO/examples/Callback_Quoter
//
// = FILENAME
//    Notifier_i.cpp
//
// = DESCRIPTION
//   Implementation of the Notifier_i class. This class is the servant
//   object for the callback quoter server.
//
// = AUTHOR
//    Kirthika Parameswaran <kirthika@cs.wustl.edu>
//
// ===========================================================

#include "Notifier_i.h"

Notifier_i::Notifier_i (void)
{
  // No-op
}

Notifier_i::~Notifier_i (void)
{
  // No-op
}

// Register a distributed callback handler that is invoked when the
// given stock reaches the desired threshold value.

void
Notifier_i::register_callback (const char *stock_name,
				     CORBA::Long threshold_value,
				     Callback_Quoter::Consumer_ptr consumer_handler,
				     CORBA::Environment &TAO_TRY_ENV)
{
  // Store the client information.
  Consumer_Data consumer_data;

  // Necessary to make another copy of the consumer_handler using
  // <_duplicate> so that we dont lose the consumer object reference
  // after the method invocation is done.
  consumer_data.consumer_ =
    Callback_Quoter::Consumer::_duplicate (consumer_handler);
  consumer_data.desired_value_= threshold_value;

  CONSUMERS *consumers = 0;

  // *done* @@ Please add a comment explaining what you're doing ;-)
  // The consumer_map consists of the stockname and various consumers with their
  // threshold values. To register a consumer into this map, first the stockname
  // is matched with an existing one (if any) and the consumer and the threshold
  // value is attached. Else, a new entry is created for the stockname.

  if (this->consumer_map_.find (stock_name, consumers) == 0)
    {
      // @@ Always make sure to check the return values of all
      // calls...
     if ( consumers->insert (consumer_data) == -1)
       ACE_ERROR ((LM_ERROR,
		   "register_callback: Insert failed!/n"));

     else
      ACE_DEBUG ((LM_DEBUG,
		  "Inserted map entry: stockname %s threshold %d",
		  stock_name,
		  threshold_value));
    }
  else
    {
      // @@ Make sure to use the ACE_NEW_THROW macro, which works with
      // CORBA exceptions...
      consumers = new CONSUMERS;

      // *done* @@ Always make sure to check the return values of all
      // calls...
      if (consumers->insert (consumer_data) == -1)
	ACE_ERROR ((LM_ERROR,
		   "register_callback: Insert failed!/n"));

      // *done* @@ Always make sure to check the return values of all
      // calls...
      if (this->consumer_map_.bind (stock_name, consumers) == -1)
         ACE_ERROR ((LM_ERROR,
		   "register_callback: Bind failed!/n"));
      else
      ACE_DEBUG ((LM_DEBUG,
		  "new map entry: stockname %s threshold %d",
		  stock_name,
		  threshold_value));
    }

}

// Obtain a pointer to the orb.

void
Notifier_i::orb (CORBA::ORB_ptr orb)
{
  this->orb_ = orb;
}

// Remove the client handler.

void
Notifier_i::unregister_callback (Callback_Quoter::Consumer_ptr consumer,
				       CORBA::Environment &TAO_TRY_ENV)
{
  // *done* @@ Make sure to add a comment here.

  // The consumer_map consists of a map of stocknames with consumers
  // and their threshold values attached to it. To unregister a consumer
  // it is necessary to remove that entry from the map. Hence, the map
  // is iterated till the consumer entry to be removed is found and then
  // removed from the map.

  for (CONSUMER_MAP::ITERATOR iter = this->consumer_map_.begin ();
       iter!= this->consumer_map_.end ();
       iter ++)
    {
      // The *iter is nothing but the stockname + unbounded set of
      // consumers+threshold values, i.e a ACE_Hash_Map_Entry.

       Consumer_Data consumer_to_remove;
       // @@ I don't think you need to do this duplicate(), but make
       // sure to run purify to double-check this.
       consumer_to_remove.consumer_ = Callback_Quoter::Consumer::_duplicate (consumer);

       // int_id is a member of the ACE_Hash_Map_Entry.  The remove
       // method will do a find internally using operator == which
       // will check only the consumer pointers.  If match found it
       // will be removed from the set.

       // *done*  @@ Make sure to check the return value.
       if ((*iter).int_id_->remove (consumer_to_remove) == -1)
	 ACE_ERROR ((LM_ERROR,
		     "unregister_callback: Remove failed!/n"));
       else
        ACE_DEBUG ((LM_DEBUG,
		    "unregister_callback:consumer removed\n"));
    }
}

// Gets the market status and sends the information to the consumer
// who is interested in it.

void
Notifier_i::market_status (const char *stock_name,
				 CORBA::Long stock_value,
				 CORBA::Environment &TAO_TRY_ENV)
{
  ACE_DEBUG ((LM_DEBUG,
	      "Notifier_i:: The stockname is %s with price %d\n",
	      stock_name,
              stock_value));

  CONSUMERS *consumers;

  if (this->consumer_map_.find (stock_name, consumers) == 0)
    {
      // Go through the list of <Consumer_Data> to find which registered
      // client wants to be notified.

      for (CONSUMERS::ITERATOR iter = consumers->begin ();
           iter != consumers->end ();
           iter++)
        {
          // Check whether the stockname is equal before proceeding
          // further.
          if (stock_value >= (*iter).desired_value_)
            {
              Callback_Quoter::Info interested_consumer_data;

	      // @@ Please check this when you run purify.
              interested_consumer_data.stock_name =
		CORBA::string_dup (stock_name);
              interested_consumer_data.value =
		stock_value;

	      ACE_DEBUG ((LM_DEBUG,
			  "pushing information to consumer\n"));

	      // *done* @@ Please add a comment.
	      // The status desired by the consumer is then passed to it.
              (*iter).consumer_->push (interested_consumer_data);

	    }
        }
    }
  else
    // @@ Please add a user defined exception called something like
    // NOT_FOUND.
    ACE_DEBUG ((LM_DEBUG,
		"Consumer not found having stockname \"%s\" with threshold value %d!\n",
		stock_name,
		stock_value));
}

void
Notifier_i::shutdown (CORBA::Environment &env)
{
  ACE_DEBUG ((LM_DEBUG,
	      "The Callback Quoter server is shutting down..."));

  /* CONSUMERS *consumers;
  for (CONSUMER_MAP::ITERATOR iter = this->consumer_map_.begin ();
       iter!= this->consumer_map_.end ();
       iter ++)
    {
      consumers =  (*iter).int_id_;

      for (CONSUMERS::ITERATOR inner_iter= consumers->begin ();
           inner_iter != consumers->end();
           inner_iter ++ )
	 {
	   ACE_DEBUG ((LM_DEBUG,
		       " Removing consumer: Stockname %s Threshold %d\n",
		       (*iter).ext_id_,
		       (*inner_iter).desired_value_));

	  if ( consumers->remove(*inner_iter) == -1)
	    ACE_ERROR ((LM_ERROR,
		    "shutdown: remove failed!/n"));;

	 }
      if ( this->consumer_map_.unbind ((*iter).ext_id_,
				       (*iter).int_id_) == -1)
	ACE_ERROR ((LM_ERROR,
		    "shutdown: unbind failed!/n"));
    }

  ACE_DEBUG ((LM_DEBUG,
  " All consumers  removed!\n"));*/

  if ( this->consumer_map_.close () == -1)
    ACE_ERROR ((LM_ERROR,
		"Consumer_map_close error!\n"));

  // Instruct the ORB to shutdown.
  this->orb_->shutdown ();

}

int
Notifier_i::Consumer_Data::operator== (const Consumer_Data &rhs)
{
  // The <_is_equivalent> function checks if the _var and _ptr objects
  // are the same.  NOTE: this call might not behave well on other
  // ORBs since <_is_equivalent> isn't guaranteed to differentiate
  // object references.

  return this->consumer_->_is_equivalent (rhs.consumer_.in ());
}

/*CONSUMER_MAP*
Notifier_i::get_consumer_map_ptr ()
{
return (&consumer_map_);
}
*/


#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class ACE_Node<Notifier_i::Consumer_Data>;
template class ACE_Unbounded_Set<Notifier_i::Consumer_Data>;
template class ACE_Unbounded_Set_Iterator<Notifier_i::Consumer_Data>;

template class ACE_Hash_Map_Entry<ACE_CString,ACE_Unbounded_Set<Notifier_i::Consumer_Data>*>;
template class ACE_Hash_Map_Manager<ACE_CString,ACE_Unbounded_Set<Notifier_i::Consumer_Data>*,ACE_Null_Mutex>;
template class ACE_Hash_Map_Iterator_Base<ACE_CString,ACE_Unbounded_Set<Notifier_i::Consumer_Data>*,ACE_Null_Mutex>;
template class ACE_Hash_Map_Iterator<ACE_CString,ACE_Unbounded_Set<Notifier_i::Consumer_Data>*,ACE_Null_Mutex>;
template class ACE_Hash_Map_Reverse_Iterator<ACE_CString,ACE_Unbounded_Set<Notifier_i::Consumer_Data>*,ACE_Null_Mutex>;

#elif defined(ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate ACE_Node<Notifier_i::Consumer_Data>
#pragma instantiate ACE_Unbounded_Set<Notifier_i::Consumer_Data>
#pragma instantiate ACE_Unbounded_Set_Iterator<Notifier_i::Consumer_Data>

#pragma instantiate ACE_Hash_Map_Entry<ACE_CString,ACE_Unbounded_Set<Notifier_i::Consumer_Data>*>
#pragma instantiate ACE_Hash_Map_Manager<ACE_CString,ACE_Unbounded_Set<Notifier_i::Consumer_Data>*,ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Iterator_Base<ACE_CString,ACE_Unbounded_Set<Notifier_i::Consumer_Data>*,ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Iterator<ACE_CString,ACE_Unbounded_Set<Notifier_i::Consumer_Data>*,ACE_Null_Mutex>
#pragma instantiate ACE_Hash_Map_Reverse_Iterator<ACE_CString,ACE_Unbounded_Set<Notifier_i::Consumer_Data>*,ACE_Null_Mutex>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
