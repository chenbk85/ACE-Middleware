// $Id$

// Test the capability of <ACE_Malloc> to handle multiple mallocs
// rooted at different base addresses.

#include "ace/Malloc.h"
#include "ace/Synch.h"
#include "ace/Auto_Ptr.h"

ACE_RCSID(Shared_Malloc, test_multiple_mallocs, "$Id$")

typedef ACE_Malloc <ACE_MMAP_MEMORY_POOL, ACE_Process_Mutex> MALLOC;

#if (ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1)
// The Address for the shared memory mapped files defaults to wherever
// the OS wants to map it.
const void *REQUEST_BASE_ADDR = 0;
const void *RESPONSE_BASE_ADDR = 0;
#else
// Default address for shared memory mapped files and SYSV shared
// memory (defaults to 64 M).
const void *REQUEST_BASE_ADDR = ((void *) (64 * 1024 * 1024));

// Default address for shared memory mapped files and SYSV shared
// memory (defaults to 64 M).
const void *RESPONSE_BASE_ADDR = ((void *) (128 * 1024 * 1024));
#endif /* ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1 */

static const char *request_string = "hello from request repository";
static const char *response_string = "hello from response repository";

int
main (int, char *[])
{
  ACE_MMAP_Memory_Pool_Options request_options (REQUEST_BASE_ADDR);

  // Create an adapter version of an allocator.
  ACE_Allocator_Adapter<MALLOC> *adapter_ptr = 0;
  ACE_NEW_RETURN (adapter_ptr,
                  ACE_Allocator_Adapter<MALLOC> ("request_file",
                                                 "request_lock",
                                                 &request_options),
                  1);

  auto_ptr <ACE_Allocator_Adapter<MALLOC> > shmem_request (adapter_ptr);
  ACE_MMAP_Memory_Pool_Options response_options (RESPONSE_BASE_ADDR);

  MALLOC *ptr = 0;
  // Create a non-adapter version of an allocator.
  ACE_NEW_RETURN (ptr,
                  MALLOC ("response_file",
                          "response_lock",
                          &response_options),
                  1);
  auto_ptr <MALLOC> shmem_response (ptr);
  void *data = 0;

  // If we find "foo" then we're running the "second" time, so we must
  // release the resources.
  if (shmem_request->find ("foo",
                           data) == 0)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "%s\n",
                  data));
      shmem_request->remove ();
    }

  // This is the first time in, so we allocate the memory and bind it
  // to the name "foo".
  else
    {
      ACE_ALLOCATOR_RETURN (data,
                            shmem_request->malloc (ACE_OS::strlen (request_string) + 1),
                            1);
      ACE_OS::strcpy ((char *) data,
                      request_string);

      if (shmem_request->bind ("foo",
                               data) == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "%p\n",
                           "bind"),
                          1);
    }
  data = 0;

  // If we find "foo" then we're running the "second" time, so we must
  // release the resources.
  if (shmem_response->find ("foo",
                            data) == 0)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "%s\n",
                  data));
      shmem_response->remove ();
      ACE_DEBUG ((LM_DEBUG,
                  "all shared memory resources have been released\n"));
    }

  // This is the first time in, so we allocate the memory and bind it
  // to the name "foo".
  else
    {
      ACE_ALLOCATOR_RETURN (data,
                            shmem_response->malloc (ACE_OS::strlen (response_string) + 1),
                            1);
      ACE_OS::strcpy ((char *) data,
                      response_string);

      if (shmem_response->bind ("foo",
                                data) == -1)
        ACE_ERROR ((LM_ERROR,
                    "%p\n",
                    "bind"));
      else
        ACE_DEBUG ((LM_DEBUG,
                    "Run again to see results and release resources.\n"));
    }

  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class auto_ptr <ACE_Allocator_Adapter<MALLOC> >;
template class ACE_Auto_Basic_Ptr<ACE_Allocator_Adapter<MALLOC> >;
template class auto_ptr <MALLOC>;
template class ACE_Auto_Basic_Ptr<MALLOC>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate auto_ptr <ACE_Allocator_Adapter<MALLOC> >
#pragma instantiate ACE_Auto_Basic_Ptr<ACE_Allocator_Adapter<MALLOC> >
#pragma instantiate auto_ptr <MALLOC>
#pragma instantiate ACE_Auto_Basic_Ptr<MALLOC>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
