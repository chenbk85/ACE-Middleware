// $Id$

#include "Non_Servant_Upcall.h"
#include "Object_Adapter.h"
#include "Root_POA.h"

#if !defined (__ACE_INLINE__)
# include "Non_Servant_Upcall.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID (PortableServer,
           Non_Servant_Upcall,
           "$Id$")

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{
  namespace Portable_Server
  {
    Non_Servant_Upcall::Non_Servant_Upcall (::TAO_Root_POA &poa)
      : object_adapter_ (poa.object_adapter ()),
        poa_ (poa),
        previous_ (0)
    {
      // Check if this is a nested non_servant_upcall.
      if (this->object_adapter_.non_servant_upcall_nesting_level_ != 0)
        {
          // Remember previous instance of non_servant_upcall.
          this->previous_ = this->object_adapter_.non_servant_upcall_in_progress_;

          // Assert that the thread is the same as the one before.
          ACE_ASSERT (ACE_OS::thr_equal (this->object_adapter_.non_servant_upcall_thread_,
                                         ACE_OS::thr_self ()));
        }

      // Remember which thread is calling the adapter activators.
      this->object_adapter_.non_servant_upcall_thread_ = ACE_OS::thr_self ();

      // Mark the fact that a non-servant upcall is in progress.
      this->object_adapter_.non_servant_upcall_in_progress_ = this;

      // Adjust the nesting level.
      this->object_adapter_.non_servant_upcall_nesting_level_++;

      // We always release
      this->object_adapter_.lock ().release ();
    }

    Non_Servant_Upcall::~Non_Servant_Upcall (void)
    {
      // Reacquire the Object Adapter lock.
      this->object_adapter_.lock ().acquire ();

      // Adjust the nesting level.
      this->object_adapter_.non_servant_upcall_nesting_level_--;

      // We are done with this nested upcall.
      this->object_adapter_.non_servant_upcall_in_progress_ = this->previous_;

      // If we are at the outer nested upcall.
      if (this->object_adapter_.non_servant_upcall_nesting_level_ == 0)
        {
          // Reset thread id.
          this->object_adapter_.non_servant_upcall_thread_ =
            ACE_OS::NULL_thread;

          // Check if all pending requests are over.
          if (this->poa_.waiting_destruction () &&
              this->poa_.outstanding_requests () == 0)
            {
              ACE_TRY_NEW_ENV
                {
                  this->poa_.complete_destruction_i (ACE_ENV_SINGLE_ARG_PARAMETER);
                  ACE_TRY_CHECK;
                }
              ACE_CATCHANY
                {
                  // Ignore exceptions
                  ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                                       "TAO_POA::complete_destruction_i");
                }
              ACE_ENDTRY;
            }

          // If locking is enabled.
          if (this->object_adapter_.enable_locking_)
            // Wakeup all waiting threads.
            this->object_adapter_.non_servant_upcall_condition_.broadcast ();
        }
    }
  }
}

TAO_END_VERSIONED_NAMESPACE_DECL
