
// $Id$

#include "AccountManager_i.h"
#include "Account_i.h"

ACE_RCSID(AccountManager, AccountManager_i, "$Id$")

// Constructor

AccountManager_i::AccountManager_i (void)
{
  // no-op
}

// Destructor

AccountManager_i::~AccountManager_i (void)
{
  // no-op
}

// Set the ORB pointer

void
AccountManager_i::orb (CORBA::ORB_ptr o)
{
  this->orb_ = CORBA::ORB::_duplicate (o);
}

// Open an account for the given name.

Bank::Account_ptr
AccountManager_i::open (const char *name,
			CORBA::Float initial_balance,
			CORBA::Environment &_env)
{
  Account_i *result;

  // If name is already in the map, <find> will assign <result> to the
  // appropriate value.

  if (hash_map_.find (name, result) != 0)
    {
      ACE_DEBUG ((LM_DEBUG,
                "\nOpening a new Account for %s with balance %f\n",
		  name,
		  initial_balance));

      ACE_NEW_THROW_RETURN (result,
			    Account_i (name,initial_balance),
			    CORBA::NO_MEMORY (CORBA::COMPLETED_NO),
			    Bank::Account::_nil ());
      // Enter the new Account in the hash map. If the <bind> fails
      // throw an UNKNOWN exception. <result> may be valid but since
      // it is not properly bound, it's behaviour may be off, so
      // delete it to be safe.

      if (hash_map_.bind (name, result) == -1)
	{
	  delete result;
	  TAO_THROW_RETURN (CORBA::UNKNOWN (CORBA::COMPLETED_NO),
			    Bank::Account::_nil ());
	}
    }
  else
    if (TAO_debug_level > 0)
    ACE_DEBUG ((LM_DEBUG,
		"\nAccount already exists for %s\n",
		name));

  //  Generate an IOR for the result object and register it with the
  //  POA. In case the object already exists then the previously
  //  generated IOR is returned.

  return result->_this (_env);
}

// Shutdown.

void
AccountManager_i::close (Bank::Account_ptr account,
			 CORBA::Environment &env)
{
  TAO_TRY
    {
      const char *name =
	// @@ I don't think you need to do a string_dup() here.  I
	// think that is automatically handled by name().  Moreover, I
	// don't think you are correctly freeing the name pointer...
	// Make sure you free this up correctly regardless of which
	// exception path is taken...
	CORBA::string_dup (account->name (TAO_TRY_ENV));

      TAO_CHECK_ENV;

      if (hash_map_.unbind (name) == -1)
	{
	  if (TAO_debug_level > 0)
	    ACE_DEBUG((LM_DEBUG,
		     "Unable to close account\n"));
	}
      else if (TAO_debug_level > 0)
	ACE_DEBUG((LM_DEBUG,
		   "Closing Account for %s\n",
		   name));
   }
 TAO_CATCHANY
   {
     TAO_TRY_ENV.print_exception ("Unable to close Account\n");
   }
 TAO_ENDTRY;
 // @@ I suspect you'll want to do a CORBA::string_free (name) here...
}

void
AccountManager_i::shutdown (CORBA::Environment &)
{
  ACE_DEBUG ((LM_DEBUG,
              "%s\n",
              "AccountManager_i is shutting down"));

  // Instruct the ORB to shutdown.
  this->orb_->shutdown ();
}
