// SOCK_IO.cpp
// $Id$

#define ACE_BUILD_DLL
#include "ace/SOCK_IO.h"

#if defined (ACE_LACKS_INLINE_FUNCTIONS)
#include "ace/SOCK_IO.i"
#endif /* ACE_LACKS_INLINE_FUNCTIONS */

ACE_RCSID(ace, SOCK_IO, "$Id$")

ACE_ALLOC_HOOK_DEFINE(ACE_SOCK_IO)

void
ACE_SOCK_IO::dump (void) const
{
  ACE_TRACE ("ACE_SOCK_IO::dump");
}

// Allows a client to read from a socket without having to provide
// a buffer to read.  This method determines how much data is in the
// socket, allocates a buffer of this size, reads in the data, and
// returns the number of bytes read.

ssize_t
ACE_SOCK_IO::recv (iovec *io_vec)
{
#if defined (FIONREAD)
  u_long inlen;

  if (ACE_OS::ioctl (this->get_handle (), FIONREAD,
                     (u_long *) &inlen) == -1)
    return -1;
  else if (inlen > 0)
    {
      ACE_NEW_RETURN (io_vec->iov_base, char[inlen], -1);
      io_vec->iov_len = this->recv (io_vec->iov_base, inlen);
      return io_vec->iov_len;
    }
  else
    return 0; 
#else
    io_vec = io_vec;
    ACE_NOTSUP_RETURN (-1);
#endif /* FIONREAD */
}

ssize_t
ACE_SOCK_IO::recv (ACE_IO_Vector *io_vec)
{
#if defined (FIONREAD)
  u_long inlen;

  if (ACE_OS::ioctl (this->get_handle (), FIONREAD,
                     (u_long *) &inlen) == -1)
    return -1;
  else if (inlen > 0)
    {
      char *buffer = 0;
      ACE_NEW_RETURN (buffer, char[inlen], -1);
      io_vec->buffer (buffer);
      io_vec->length (this->recv (io_vec->buffer (), inlen));
      return io_vec->length ();
    }
  else
    return 0; 
#else
    io_vec = io_vec;
    ACE_NOTSUP_RETURN (-1);
#endif /* FIONREAD */
}

// Send N char *ptrs and int lengths.  Note that the char *'s precede
// the ints (basically, an varargs version of writev).  The count N is
// the *total* number of trailing arguments, *not* a couple of the
// number of tuple pairs!

ssize_t
ACE_SOCK_IO::send (size_t n, ...) const
{
  ACE_TRACE ("ACE_SOCK_IO::send");

  va_list argp;  
  size_t total_tuples = n / 2;
  ACE_IO_Vector *iovp;
#if defined (ACE_HAS_ALLOCA)
  iovp = (ACE_IO_Vector *) alloca (total_tuples * sizeof (ACE_IO_Vector));
#else 
  ACE_NEW_RETURN (iovp, ACE_IO_Vector[total_tuples], -1);
#endif /* !defined (ACE_HAS_ALLOCA) */

  va_start (argp, n);

  for (size_t i = 0; i < total_tuples; i++)
    {
      iovp[i].buffer (va_arg (argp, void *));
      iovp[i].length (va_arg (argp, ssize_t));
    }

  ssize_t result = ACE_OS::writev (this->get_handle (), iovp, total_tuples);
#if !defined (ACE_HAS_ALLOCA)
  delete [] iovp;
#endif /* !defined (ACE_HAS_ALLOCA) */
  va_end (argp);
  return result;
}

// This is basically an interface to ACE_OS::readv, that doesn't use
// the struct iovec explicitly.  The ... can be passed as an arbitrary
// number of (char *ptr, int len) tuples.  However, the count N is the
// *total* number of trailing arguments, *not* a couple of the number
// of tuple pairs!

ssize_t
ACE_SOCK_IO::recv (size_t n, ...) const
{
  ACE_TRACE ("ACE_SOCK_IO::recv");

  va_list argp;  
  size_t total_tuples = n / 2;
  ACE_IO_Vector *iovp;
#if defined (ACE_HAS_ALLOCA)
  iovp = (ACE_IO_Vector *) alloca (total_tuples * sizeof (ACE_IO_Vector));
#else
  ACE_NEW_RETURN (iovp, ACE_IO_Vector[total_tuples], -1);
#endif /* !defined (ACE_HAS_ALLOCA) */

  va_start (argp, n);

  for (size_t i = 0; i < total_tuples; i++)
    {
      iovp[i].buffer (va_arg (argp, void *));
      iovp[i].length (va_arg (argp, ssize_t));
    }

  ssize_t result = ACE_OS::readv (this->get_handle (), iovp, total_tuples);
#if !defined (ACE_HAS_ALLOCA)
  delete [] iovp;
#endif /* !defined (ACE_HAS_ALLOCA) */
  va_end (argp);
  return result;
}

