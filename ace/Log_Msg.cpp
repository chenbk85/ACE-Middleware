// $Id$

#define ACE_BUILD_DLL

// We need this to get the status of ACE_NTRACE...
#include "ace/config.h"

// Turn off tracing for the duration of this file.
#if defined (ACE_NTRACE)
#undef ACE_NTRACE
#endif /* ACE_NTRACE */
#define ACE_NTRACE 1

// This must come first to avoid "order of include" problems...

#if !defined (ACE_HAS_INLINED_OSCALLS) && !defined (ACE_WIN32)
#define ACE_HAS_INLINED_OSCALLS
#include "ace/ACE.h"
#undef ACE_HAS_INLINED_OSCALLS
#else
#include "ace/ACE.h"
#endif /* !ACE_HAS_INLINED_OSCALLS */

#include "ace/Thread.h"
#include "ace/Synch_T.h"
#include "ace/Signal.h"
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
# include "ace/Object_Manager.h"
#endif /* ACE_MT_SAFE */

#if defined (ACE_HAS_UNICODE)
#define ACE_WSPRINTF(BUF,VALUE) ::wsprintf (BUF, "%S", VALUE)
#else
#define ACE_WSPRINTF(BUF,VALUE) ACE_OS::sprintf (BUF, "%s", VALUE)
#endif /* ACE_HAS_UNICODE */

// IPC conduit between sender and client daemon.  This should be
// included in the <ACE_Log_Msg> class, but due to "order of include"
// problems it can't be...
#if defined (ACE_HAS_STREAM_PIPES)
# include "ace/SPIPE_Connector.h"
typedef ACE_SPIPE_Stream ACE_LOG_MSG_IPC_STREAM;
typedef ACE_SPIPE_Connector ACE_LOG_MSG_IPC_CONNECTOR;
typedef ACE_SPIPE_Addr ACE_LOG_MSG_IPC_ADDR;
#else
# include "ace/SOCK_Connector.h"
typedef ACE_SOCK_Stream ACE_LOG_MSG_IPC_STREAM;
typedef ACE_SOCK_Connector ACE_LOG_MSG_IPC_CONNECTOR;
typedef ACE_INET_Addr ACE_LOG_MSG_IPC_ADDR;
#endif /* ACE_HAS_STREAM_PIPES */

static ACE_LOG_MSG_IPC_STREAM *ACE_Log_Msg_message_queue = 0;

#if defined (ACE_HAS_MINIMUM_IOSTREAMH_INCLUSION)
# include /**/ <iostream.h>
#endif /* ACE_HAS_MINIMUM_IOSTREAMH_INCLUSION */

ACE_ALLOC_HOOK_DEFINE(ACE_Log_Msg)

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
static int ACE_Log_Msg_key_created_ = 0;
static ACE_thread_key_t ACE_Log_Msg_key_;
#endif /* ACE_MT_SAFE */

// This is only needed here because we can't afford to call
// ACE_LOG_MSG->instance() from within ACE_Log_Msg::instance() or else
// we will recurse infinitely!

#define ACE_NEW_RETURN_I(POINTER,CONSTRUCTOR,RET_VAL) \
   do { POINTER = new CONSTRUCTOR; \
     if (POINTER == 0) { errno = ENOMEM; return RET_VAL; } \
     } while (0)

// Instance count for Log_Msg - used to know when dynamically
// allocated storage (program name and host name) can be safely
// deleted.
int ACE_Log_Msg::instance_count_ = 0;

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)

class ACE_Log_Msg_Manager
  // = TITLE
  //      Synchronize output operations.
{
public:
  static ACE_Thread_Mutex *get_lock (void);

  static void close (void);

private:
  static ACE_Thread_Mutex *lock_;
};

ACE_Thread_Mutex *ACE_Log_Msg_Manager::lock_ = 0;

ACE_Thread_Mutex *
ACE_Log_Msg_Manager::get_lock (void)
{
  // This function is called by the first thread to create an ACE_Log_Msg
  // instance.  It makes the call while holding a mutex, so we don't have
  // to grab another one here.

  if (ACE_Log_Msg_Manager::lock_ == 0)
    {
      ACE_NO_HEAP_CHECK;

      ACE_NEW_RETURN_I (ACE_Log_Msg_Manager::lock_, ACE_Thread_Mutex, 0);

      // Allocated the ACE_Log_Msg IPC instance.
      ACE_NEW_RETURN (ACE_Log_Msg_message_queue, ACE_LOG_MSG_IPC_STREAM, 0);
    }

  return ACE_Log_Msg_Manager::lock_;
}

void
ACE_Log_Msg_Manager::close (void)
{
#if defined (ACE_WIN32) || defined (ACE_HAS_STHREADS) && ! defined (ACE_HAS_TSS_EMULATION) && ! defined (ACE_HAS_EXCEPTIONS)
  // Delete the (main thread's) Log_Msg instance.  I think that this
  // is only "necessary" if exception handling is not enabled.
  // Without exception handling, main thread TSS destructors don't
  // seem to be called.  It's not really necessary anyways, because
  // this one leak is harmless on Solaris.
  delete ACE_Log_Msg::instance ();
#endif /* ACE_HAS_STHREADS && ! TSS_EMULATION && ! ACE_HAS_EXCEPTIONS */

  ACE_OS::thr_keyfree (ACE_Log_Msg_key_);

  // Ugly, ugly, but don't know a better way.
  delete ACE_Log_Msg_Manager::lock_;
  ACE_Log_Msg_Manager::lock_ = 0;

  // Destroy the static message queue instance.
  ACE_Log_Msg_message_queue->close ();
  delete ACE_Log_Msg_message_queue;
  ACE_Log_Msg_message_queue = 0;
}

/* static */
#if defined (ACE_HAS_THR_C_FUNC)
extern "C"
#endif /* ACE_HAS_THR_C_FUNC */
void
ACE_TSS_cleanup (void *ptr)
{
  delete (ACE_Log_Msg *) ptr;
}
#endif /* ACE_MT_SAFE */

/* static */
int
ACE_Log_Msg::exists (void)
{
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
# if defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || defined (ACE_HAS_TSS_EMULATION)
  ACE_Log_Msg *tss_log_msg = 0;

  // Get the tss_log_msg from thread-specific storage.
  return ACE_Log_Msg_key_created_
    && ACE_OS::thr_getspecific (ACE_Log_Msg_key_, (void **) &tss_log_msg) != -1
    && tss_log_msg;
# else
#   error "Platform must support thread-specific storage if threads are used..."
# endif /* ACE_HAS_THREAD_SPECIFIC_STORAGE || ACE_HAS_TSS_EMULATION */
#else
  return 1;
#endif /* defined (ACE_MT_SAFE) */
}

ACE_Log_Msg *
ACE_Log_Msg::instance (void)
{
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
# if defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || defined (ACE_HAS_TSS_EMULATION)
  // TSS Singleton implementation.

  if (ACE_Log_Msg_key_created_ == 0)
    {
      ACE_Thread_Mutex *lock =
        ACE_Managed_Object<ACE_Thread_Mutex>::get_preallocated_object
          (ACE_Object_Manager::ACE_LOG_MSG_INSTANCE_LOCK);

      ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, *lock, 0);

      if (ACE_Log_Msg_key_created_ == 0)
        {
          // Allocate the Singleton lock.
          ACE_Log_Msg_Manager::get_lock ();

          {
            ACE_NO_HEAP_CHECK;
            if (ACE_OS::thr_keycreate (&ACE_Log_Msg_key_,
                                       &ACE_TSS_cleanup) != 0)
              {
                return 0; // Major problems, this should *never* happen!
              }
          }

          ACE_Log_Msg_key_created_ = 1;
        }
    }

  ACE_Log_Msg *tss_log_msg = 0;

  // Get the tss_log_msg from thread-specific storage.
  if (ACE_OS::thr_getspecific (ACE_Log_Msg_key_,
                               (void **) &tss_log_msg) == -1)
    return 0; // This should not happen!

  // Check to see if this is the first time in for this thread.
  if (tss_log_msg == 0)
    {
      // Allocate memory off the heap and store it in a pointer in
      // thread-specific storage (on the stack...).
      // Stop heap checking, the memory will always be freed by the
      // thread rundown because of the TSS callback set up when the key
      // was created. This prevents from getting these blocks
      // reported as memory leaks.
      {
        ACE_NO_HEAP_CHECK;

        ACE_NEW_RETURN_I (tss_log_msg, ACE_Log_Msg, 0);
        // Store the dynamically allocated pointer in thread-specific
        // storage.  It gets deleted via the ACE_TSS_cleanup function
        // when the thread terminates.

        if (ACE_OS::thr_setspecific (ACE_Log_Msg_key_,
                                     (void *) tss_log_msg) != 0)
          return 0; // Major problems, this should *never* happen!
      }
    }

  return tss_log_msg;
# else
#  error "Platform must support thread-specific storage if threads are used..."
# endif /* ACE_HAS_THREAD_SPECIFIC_STORAGE || ACE_HAS_TSS_EMULATION */
#else
  // We don't have threads, we cannot call
  // ACE_Log_Msg_Manager::get_lock() to initialize the message queue,
  // we do it here.
  ACE_NEW_RETURN (ACE_Log_Msg_message_queue, ACE_LOG_MSG_IPC_STREAM, 0);

  // Singleton implementation.
  static ACE_Log_Msg log_msg;

  return &log_msg;
#endif /* defined (ACE_MT_SAFE) */
}
#undef ACE_NEW_RETURN_I

// Name of the local host.
const char *ACE_Log_Msg::local_host_ = 0;

// Records the program name.
const char *ACE_Log_Msg::program_name_ = 0;

// Default is to use stderr.
u_long ACE_Log_Msg::flags_ = ACE_Log_Msg::STDERR;

// Process id of the current process.
pid_t ACE_Log_Msg::pid_ = -1;

// Current offset of msg_[].
int ACE_Log_Msg::msg_off_ = 0;

// Call after a fork to resynchronize the PID and PROGRAM_NAME
// variables.

void
ACE_Log_Msg::close (void)
{
  // Please note that this will be called by a statement that is
  // harded coded into the ACE_Object_Manager's shutdown sequence,
  // in its destructor.

  ACE_MT (ACE_Log_Msg_Manager::close ());
}

void
ACE_Log_Msg::sync (const char *prog_name)
{
  ACE_TRACE ("ACE_Log_Msg::sync");

  if (prog_name)
    {
      // Must free if already allocated!!!
      ACE_OS::free ((void *) ACE_Log_Msg::program_name_);

      // Stop heap checking, block will be freed by the destructor when
      // the last ACE_Log_Msg instance is deleted.
      // Heap checking state will be restored when the block is left.
      {
        ACE_NO_HEAP_CHECK;

        ACE_Log_Msg::program_name_ = ACE_OS::strdup (prog_name);
      }
    }

  ACE_Log_Msg::pid_ = ACE_OS::getpid ();
  ACE_Log_Msg::msg_off_ = 0;
}

u_long
ACE_Log_Msg::flags (void)
{
  ACE_TRACE ("ACE_Log_Msg::flags");
  u_long result;
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, *ACE_Log_Msg_Manager::get_lock (), 0));

  result = ACE_Log_Msg::flags_;
  return result;
}

void
ACE_Log_Msg::set_flags (u_long flgs)
{
  ACE_TRACE ("ACE_Log_Msg::set_flags");
  ACE_MT (ACE_GUARD (ACE_Thread_Mutex, ace_mon, *ACE_Log_Msg_Manager::get_lock ()));

  ACE_SET_BITS (ACE_Log_Msg::flags_, flgs);
}

void
ACE_Log_Msg::clr_flags (u_long flgs)
{
  ACE_TRACE ("ACE_Log_Msg::clr_flags");
  ACE_MT (ACE_GUARD (ACE_Thread_Mutex, ace_mon, *ACE_Log_Msg_Manager::get_lock ()));

  ACE_CLR_BITS (ACE_Log_Msg::flags_, flgs);
}

int
ACE_Log_Msg::acquire (void)
{
  ACE_TRACE ("ACE_Log_Msg::acquire");
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
  return ACE_Log_Msg_Manager::get_lock ()->acquire ();
#else
  return 0;
#endif /* ACE_MT_SAFE */
}

u_long
ACE_Log_Msg::priority_mask (u_long n_mask)
{
  u_long o_mask = this->priority_mask_;
  this->priority_mask_ = n_mask;
  return o_mask;
}

u_long
ACE_Log_Msg::priority_mask (void)
{
  return this->priority_mask_;
}

int
ACE_Log_Msg::release (void)
{
  ACE_TRACE ("ACE_Log_Msg::release");

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
  return ACE_Log_Msg_Manager::get_lock ()->release ();
#else
  return 0;
#endif /* ACE_MT_SAFE */
}

ACE_Log_Msg::ACE_Log_Msg (void)
  : status_ (0),
    errnum_ (0),
    linenum_ (0),
    restart_ (1),  // Restart by default...
    ostream_ (0),
    trace_depth_ (0),
    thr_handle_ (0),
    trace_active_ (0),
    tracing_enabled_ (1), // On by default?
    thr_state_ (0),
    priority_mask_ (LM_SHUTDOWN // By default, all priorities are enabled.
                    | LM_TRACE
                    | LM_DEBUG
                    | LM_INFO
                    | LM_NOTICE
                    | LM_WARNING
                    | LM_STARTUP
                    | LM_ERROR
                    | LM_CRITICAL
                    | LM_ALERT
                    | LM_EMERGENCY)
{
  // ACE_TRACE ("ACE_Log_Msg::ACE_Log_Msg");

  ++instance_count_;
}

ACE_Log_Msg::~ACE_Log_Msg (void)
{
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)

  int instance_count;

  // Only hold the guard while updating the instance_count_.
  // If ACE_Log_Msg_Manager::close () is called, the lock will
  // be deleted.
  {
    ACE_MT (ACE_GUARD (ACE_Thread_Mutex, ace_mon,
                       *ACE_Log_Msg_Manager::get_lock ()));
    instance_count = --instance_count_;
  }
  // Release the guard.

  // If this is the last instance then cleanup.  Only the last
  // thread to destroy its ACE_Log_Msg instance should execute
  // this block.
  if (instance_count == 0)
    {
#     if defined (ACE_HAS_TSS_EMULATION)
        ACE_Log_Msg_Manager::close ();
#     endif /* ACE_HAS_TSS_EMULATION */

      if (ACE_Log_Msg::program_name_)
        {
          ACE_OS::free ((void *) ACE_Log_Msg::program_name_);
          ACE_Log_Msg::program_name_ = 0;
        }

      if (ACE_Log_Msg::local_host_)
        {
          ACE_OS::free ((void *) ACE_Log_Msg::local_host_);
          ACE_Log_Msg::local_host_ = 0;
        }
    }
#endif /* ACE_MT_SAFE */
}

// Open the sender-side of the Message ACE_Queue.
int
ACE_Log_Msg::open (const char *prog_name,
                   u_long flags,
                   LPCTSTR logger_key)
{
  ACE_TRACE ("ACE_Log_Msg::open");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, *ACE_Log_Msg_Manager::get_lock (), -1));

  if (prog_name)
    {
      ACE_OS::free ((void *) ACE_Log_Msg::program_name_);

      // Stop heap checking, block will be freed by the destructor.
      {
        ACE_NO_HEAP_CHECK;

        ACE_Log_Msg::program_name_ = ACE_OS::strdup (prog_name);
      }
    }

  int status = 0;

  // Note that if we fail to open the message queue the default action
  // is to use stderr (set via static initialization in the
  // ACE_Log_Msg.C file).

  if (ACE_BIT_ENABLED (flags, ACE_Log_Msg::LOGGER))
    {
      if (logger_key == 0)
        status = -1;
      else
        {
          if (ACE_Log_Msg_message_queue->get_handle () != ACE_INVALID_HANDLE)
            ACE_Log_Msg_message_queue->close ();

          ACE_LOG_MSG_IPC_CONNECTOR con;
          status = con.connect (*ACE_Log_Msg_message_queue,
                                ACE_LOG_MSG_IPC_ADDR (ACE_MULTIBYTE_STRING (logger_key)));
        }

      if (status == -1)
        ACE_SET_BITS (ACE_Log_Msg::flags_, ACE_Log_Msg::STDERR);
      else
        ACE_SET_BITS (ACE_Log_Msg::flags_, ACE_Log_Msg::LOGGER);
    }

  // Remember, ACE_Log_Msg::STDERR bit is on by default...
  if (status != -1
      && ACE_BIT_ENABLED (flags, ACE_Log_Msg::STDERR) == 0)
    ACE_CLR_BITS (ACE_Log_Msg::flags_, ACE_Log_Msg::STDERR);

  if (ACE_BIT_ENABLED (flags, ACE_Log_Msg::VERBOSE))
    ACE_SET_BITS (ACE_Log_Msg::flags_, ACE_Log_Msg::VERBOSE);

  if (ACE_BIT_ENABLED (flags, ACE_Log_Msg::OSTREAM))
    {
      ACE_SET_BITS (ACE_Log_Msg::flags_, ACE_Log_Msg::OSTREAM);
      // Only set this to cerr if it hasn't already been set.
      if (this->msg_ostream () == 0)
        this->msg_ostream (&cerr);
    }
  if (ACE_BIT_ENABLED (flags, ACE_Log_Msg::SILENT))
    ACE_SET_BITS (ACE_Log_Msg::flags_, ACE_Log_Msg::SILENT);

  return status;
}

// Valid Options (prefixed by '%', as in printf format strings) include:
//   'a': exit the program at this point (var-argument is the exit status!)
//   'c': print a character
//   'i', 'd': print a decimal number
//   'I', indent according to nesting depth
//   'e', 'E', 'f', 'F', 'g', 'G': print a double
//   'l', print line number where an error occurred.
//   'N': print file name where the error occurred.
//   'n': print the name of the program (or "<unknown>" if not set)
//   'o': print as an octal number
//   'P': format the current process id
//   'p': format the appropriate errno value from sys_errlist
//   'r': call the function pointed to by the corresponding argument
//   'R': print return status
//   'S': format the appropriate _sys_siglist entry corresponding to var-argument.
//   's': format a character string
//   'T': print timestamp in hour:minute:sec:usec format.
//   't': print thread id (1 if single-threaded)
//   'u': print as unsigned int
//   'X', 'x': print as a hex number
//   '%': format a single percent sign, '%'

ssize_t
ACE_Log_Msg::log (ACE_Log_Priority log_priority,
                  const char *format_str, ...)
{
  ACE_TRACE ("ACE_Log_Msg::log");

  // Start of variable args section.
  va_list argp;

  va_start (argp, format_str);

  int result = this->log (format_str, log_priority, argp);

  va_end (argp);

  return result;
}

ssize_t
ACE_Log_Msg::log (const char *format_str,
                  ACE_Log_Priority log_priority,
                  va_list argp)
{
  ACE_TRACE ("ACE_Log_Msg::log");
  // External decls.

  extern int sys_nerr;
  typedef void (*PTF)(...);

  // Only print the message if <priority_mask_> hasn't been reset to
  // exclude this logging priority.

  if (ACE_BIT_DISABLED (this->priority_mask_, log_priority))
    return 0;

  ACE_Log_Record log_record (log_priority,
                             ACE_OS::gettimeofday (),
                             this->getpid ());
  char *bp = this->msg ();
  int abort_prog = 0;
  int exit_value = 0;
  int result = 0;
  char *format = ACE_OS::strdup (format_str);
  char *save_p = format; // Remember pointer for ACE_OS::free()

  if (format == 0)
    return -1;

  if (ACE_BIT_ENABLED (ACE_Log_Msg::flags_, ACE_Log_Msg::VERBOSE))
    {
      // Prepend the program name onto this message

      if (ACE_Log_Msg::program_name_ != 0)
        {
          for (const char *s = ACE_Log_Msg::program_name_; (*bp = *s) != '\0'; s++)
            bp++;

          *bp++ = '|';
        }
    }

  while (*format != '\0')
    {
      // Copy input to output until we encounter a %, however a
      // % followed by another % is not a format specification.

      if (*format != '%')
        *bp++ = *format++;
      else if (format[1] == '%') // An "escaped" '%' (just print one '%').
        {
          *bp++ = *format++;    // Store first %
          format++;     // but skip second %
        }
      else
        {
          char c;               // high use character
          char *fp;             // local format pointer
          int  wpc;             // width/precision cnt
          const int CONTINUE = 0;
          const int SKIP_SPRINTF = -1;  // We must skip the sprintf phase
          const int SKIP_NUL_LOCATE = -2; // Skip locating the NUL character
          int type = CONTINUE;  // conversion type
          int  w[2];            // width/precision vals

          // % starts a format specification that ends with one of
          // "arnPpSsdciIouxXfFeEgG".  An optional width and/or precision
          // (indicated by an "*") may be encountered prior to the
          // nend of the specification, each consumes an int arg.
          // A call to sprintf() does the actual conversion.

          fp = format++;        // Remember beginning of format.
          wpc = 0;              // Assume no width/precision seen.

          while (type == CONTINUE)
            {
              switch (*format++)
                {
                case 'a': // Abort program after handling all of format string.
                  type = SKIP_SPRINTF;
                  abort_prog = 1;
                  exit_value = va_arg (argp, int);
                  ACE_OS::sprintf (bp, ""); // Make sure to NUL-terminate this...
                  break;
                case 'l':
                  ACE_OS::sprintf (bp, "%d", this->linenum ());
                  type = SKIP_SPRINTF;
                  break;
                case 'N':
                  {
                    // @@ UNICODE
                    const char *file = this->file ();
                    ACE_OS::sprintf (bp, "%s", file ? file : "<unknown file>");
                    type = SKIP_SPRINTF;
                    break;
                  }
                case 'n': // Print the name of the program.
                  type = SKIP_SPRINTF;
                  // @@ UNICODE
                  ACE_OS::strcpy (bp, ACE_Log_Msg::program_name_ ?
                                  ACE_Log_Msg::program_name_ : "<unknown>");
                  break;
                case 'P': // Format the current process id.
                  type = SKIP_SPRINTF;
                  ACE_OS::sprintf (bp, "%d", this->getpid ());
                  break;
                case 'p': // Format the string assocated with the value of errno.
                  {
                    type = SKIP_SPRINTF;
                    errno = ACE::map_errno (this->errnum ());
                    if (errno >= 0 && errno < sys_nerr)
                      ACE_OS::sprintf (bp, "%s: %s",
                                       va_arg (argp, char *), strerror (errno));
                    else
                      {
#if defined (ACE_WIN32)
                        LPTSTR lpMsgBuf = 0;

                        ::FormatMessage (FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
                                         NULL,
                                         errno,
                                         MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
                                         (LPTSTR) &lpMsgBuf,
                                         0,
                                         NULL);

                        // If we don't get a valid response from
                        // <FormatMessage>, we'll assume this is a
                        // WinSock error and so we'll try to convert
                        // it into a string.  If this doesn't work it
                        // returns "unknown error" which is fine for
                        // our purposes.
                        if (lpMsgBuf == 0)
                          {
                            const char *message = ACE::sock_error (errno);
                            ACE_OS::sprintf (bp, "%s: %s",
                                             va_arg (argp, const char *), message);
                          }
                        else
                          {
                            ACE_OS::sprintf (bp, "%s: %s",
                                             va_arg (argp, char *), lpMsgBuf);
                            // Free the buffer.
                            ::LocalFree (lpMsgBuf);
                          }
#else
                        ACE_OS::sprintf (bp, "%s: <unknown error> = %d",
                                         va_arg (argp, char *), errno);
#endif /* ACE_WIN32 */
                      }
                    break;
                  }
                case 'R': // Format the return status of the operation.
                  this->op_status (va_arg (argp, int));
                  ACE_OS::sprintf (bp, "%d", this->op_status ());
                  break;

                case 'I': // Indent with nesting_depth*width spaces
                  type = SKIP_SPRINTF;
                  if (!wpc) w[wpc++] = 1;
                  w[wpc-1] *=   this->trace_depth_;
                  memset(bp, ' ', w[wpc-1]);
                  bp += w[wpc-1];
                  *bp = '\0';
                  break;

                case 'r': // Run (invoke) this subroutine.
                  {
                    int osave = ACE_Log_Msg::msg_off_;

                    if (ACE_BIT_ENABLED (ACE_Log_Msg::flags_, ACE_Log_Msg::SILENT))
                      *bp++ = '{';
                    ACE_Log_Msg::msg_off_ =  bp - this->msg_;

                    type = SKIP_SPRINTF;
                    (*va_arg (argp, PTF))();

                    if (ACE_BIT_ENABLED (ACE_Log_Msg::flags_, ACE_Log_Msg::SILENT))
                      {
                        bp += ACE_OS::strlen (bp);
                        *bp++ =  '}';
                      }
                    *bp = '\0';

                    ACE_Log_Msg::msg_off_ = osave;
                    break;
                  }
                case 'S': // format the string associated with this signal number.
                  {
                    int sig = va_arg (argp, int);
                    type = SKIP_SPRINTF;
#if defined (ACE_HAS_SYS_SIGLIST)
                    if (sig >= 0 && sig < NSIG)
                      ACE_OS::strcpy (bp, _sys_siglist[sig]);
                    else
                      ACE_OS::sprintf (bp, "<unknown signal> %d", sig);
#else
                    ACE_OS::sprintf (bp, "signal %d", sig);
#endif /* ACE_HAS_SYS_SIGLIST */
                    break;
                  }
                case 'T': // Format the timestamp.
                  {
                    type = SKIP_SPRINTF;
                    char day_and_time[35];
                    ACE_OS::sprintf (bp, "%s",
                                     ACE::timestamp (day_and_time,
                                                     sizeof day_and_time));
                    break;
                  }
                case 't': // Format thread id.
                  type = SKIP_SPRINTF;
#if defined (ACE_WIN32)
                  ACE_OS::sprintf (bp, "%u", ACE_Thread::self ());
#elif defined (AIX)
                  // AIX's pthread_t (ACE_hthread_t) is a pointer, and it's
                  // a little ugly to send that through a %u format.  So,
                  // get the kernel thread ID (tid_t) via thread_self() and
                  // display that instead.
                  // This isn't conditionalized on ACE_HAS_THREAD_SELF because
                  // 1. AIX 4.2 doesn't have that def anymore (it messes up
                  //    other things)
                  // 2. OSF/1 V3.2 has that def, and I'm not sure what affect
                  //   this would have on that.
                  // -Steve Huston, 19-Aug-97
                  ACE_OS::sprintf (bp, "%u", thread_self());
#else
                  ACE_hthread_t t_id;
                  ACE_Thread::self (t_id);
                  ACE_OS::sprintf (bp, "%u", t_id);
#endif /* ACE_WIN32 */
                  break;
                case 's':
                  type = 1 + wpc; // 1, 2, 3
                  break;
                case 'W':
                  // @@ UNICODE
                case 'd': case 'c': case 'i': case 'o':
                case 'u': case 'x': case 'X':
                  type = 4 + wpc; // 4, 5, 6
                  break;
                case 'F': case 'f': case 'e': case 'E':
                case 'g': case 'G':
                  type = 7 + wpc; // 7, 8, 9
                  break;
                case '*':       // consume width/precision
                  w[wpc++] = va_arg (argp, int);
                  break;
                default:
                  // ?
                  break;
                }
            }

          if (type != SKIP_SPRINTF)
            {
              c = *format;      // Remember char before we overwrite.
              *format = 0;      // Overwrite, terminating format.

              switch (type)
                {
                case 1:
                  ACE_OS::sprintf (bp, fp, va_arg (argp, char *));
                  break;
                case 2:
                  ACE_OS::sprintf (bp, fp, w[0], va_arg (argp, char *));
                  bp += w[0];
                  type = SKIP_NUL_LOCATE;
                  break;
                case 3:
                  ACE_OS::sprintf (bp, fp, w[0], w[1], va_arg (argp, char *));
                  bp += w[0];
                  type = SKIP_NUL_LOCATE;
                  break;
                case 4:
                  ACE_OS::sprintf (bp, fp, va_arg (argp, int));
                  break;
                case 5:
                  ACE_OS::sprintf (bp, fp, w[0], va_arg (argp, int));
                  break;
                case 6:
                  ACE_OS::sprintf (bp, fp, w[0], w[1], va_arg (argp, int));
                  break;
                case 7:
                  ACE_OS::sprintf (bp, fp, va_arg (argp, double));
                  break;
                case 8:
                  ACE_OS::sprintf (bp, fp, w[0], va_arg (argp, double));
                  break;
                case 9:
                  ACE_OS::sprintf (bp, fp, w[0], w[1], va_arg (argp, double));
                  break;
                }
              *format = c;      // Restore char we overwrote.
            }

          if (type != SKIP_NUL_LOCATE)
            while (*bp != '\0') // Locate end of bp.
              bp++;
        }
    }

  *bp = '\0'; // Terminate bp, but don't auto-increment this!

  ACE_OS::free (ACE_MALLOC_T (save_p));

  // Only print the message if "SILENT" mode is disabled.
  if (ACE_BIT_DISABLED (ACE_Log_Msg::flags_, ACE_Log_Msg::SILENT))
    {
      // Copy the message from thread-specific storage into the
      // transfer buffer (this can be optimized away by changing other
      // code...).
      log_record.msg_data (this->msg ());
      this->stop_tracing ();

#if !defined (ACE_WIN32)
      // Make this block signal-safe.
      ACE_Sig_Guard sb;
#endif /* ACE_WIN32 */

      // Make sure that the lock is held during all this.
      ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, *ACE_Log_Msg_Manager::get_lock (), -1));

      if (ACE_BIT_ENABLED (ACE_Log_Msg::flags_, ACE_Log_Msg::STDERR)
          && abort_prog == 0) // We'll get this further down.
        log_record.print (ACE_Log_Msg::local_host_,
                          ACE_BIT_ENABLED (ACE_Log_Msg::flags_, ACE_Log_Msg::VERBOSE),
                          stderr);
      if (ACE_BIT_ENABLED (ACE_Log_Msg::flags_, ACE_Log_Msg::LOGGER))
        {
#if defined (ACE_HAS_STREAM_PIPES)
          ACE_Str_Buf log_msg ((void *) &log_record,
                               int (log_record.length ()));

          // Try to use the <putpmsg> API if possible in order to
          // ensure correct message queueing according to priority.
          result = ACE_Log_Msg_message_queue->send ((const ACE_Str_Buf *) 0,
						    &log_msg,
						    int (log_record.priority ()),
						    MSG_BAND);
#else
	  // We're running over sockets, so we'll need to indicate the
	  // number of bytes to send.
          result = ACE_Log_Msg_message_queue->send_n ((void *) &log_record,
						      log_record.length ());
#endif /* ACE_HAS_STREAM_PIPES */
        }
      // Format the message and print it to stderr and/or ship it off
      // to the log_client daemon, and/or print it to the ostream.
      // This must come last, after the other two print operations
      // (see the ACE_Log_Record::print method for details).

      if (ACE_BIT_ENABLED (ACE_Log_Msg::flags_, ACE_Log_Msg::OSTREAM)
          && this->msg_ostream () != 0)
        log_record.print (ACE_Log_Msg::local_host_,
                          ACE_BIT_ENABLED (ACE_Log_Msg::flags_, ACE_Log_Msg::VERBOSE),
                          *this->msg_ostream ());
      this->start_tracing ();
    }

  if (abort_prog)
    {
      // *Always* print a message to stderr if we're aborting.  We
      // don't use verbose, however, to avoid recursive aborts if
      // something is hosed.
      log_record.print (ACE_Log_Msg::local_host_, 0);
      ACE_OS::exit (exit_value);
    }

  return result;
}

// Calls log to do the actual print, but formats first.

int
ACE_Log_Msg::log_hexdump (ACE_Log_Priority log_priority,
                          const char *buffer,
                          int size,
                          const char *text)
{
  char buf[ACE_Log_Record::MAXLOGMSGLEN - ACE_Log_Record::VERBOSE_LEN - 58];
  // 58 for the HEXDUMP header;

  char msg_buf[80];

  buf[0] = 0; // in case size = 0

  int len = ACE::format_hexdump (buffer, size, buf, sizeof buf);

  int sz = 0;

  if (text)
    sz = ACE_OS::sprintf (msg_buf, "%s - ", text);

  sz += ACE_OS::sprintf (msg_buf + sz, "HEXDUMP %d bytes", size);

  if (len < size)
    ACE_OS::sprintf (msg_buf + sz, " (showing first %d bytes)", len);

  // Now print out the formatted buffer.
  this->log (log_priority, "%s\n%s", msg_buf, buf);
  return 0;
}

void
ACE_Log_Msg::set (const char *filename,
                  int line,
                  int status,
                  int err,
                  int rs,
                  ostream *os)
{
  ACE_TRACE ("ACE_Log_Msg::set");
  this->file (filename);
  this->linenum (line);
  this->op_status (status);
  this->errnum (err);
  this->restart (rs);
  this->msg_ostream (os);
}

void
ACE_Log_Msg::dump (void) const
{
  ACE_TRACE ("ACE_Log_Msg::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, "status_ = %d\n", this->status_));
  ACE_DEBUG ((LM_DEBUG, "\nerrnum_ = %d\n", this->errnum_));
  ACE_DEBUG ((LM_DEBUG, "\nlinenum_ = %d\n", this->linenum_));
  ACE_DEBUG ((LM_DEBUG, "\nfile_ = %s\n", this->file_));
  ACE_DEBUG ((LM_DEBUG, "\nmsg_ = %s\n", this->msg_));
  ACE_DEBUG ((LM_DEBUG, "\nrestart_ = %d\n", this->restart_));
  ACE_DEBUG ((LM_DEBUG, "\nostream_ = %x\n", this->ostream_));
  ACE_DEBUG ((LM_DEBUG, "\nprogram_name_ = %s\n", this->program_name_ ? this->program_name_ : "<unknown>"));
  ACE_DEBUG ((LM_DEBUG, "\nlocal_host_ = %s\n", this->local_host_ ? this->local_host_ : "<unknown>"));
  ACE_DEBUG ((LM_DEBUG, "\npid_ = %d\n", this->getpid ()));
  ACE_DEBUG ((LM_DEBUG, "\nflags_ = %x\n", this->flags_));
  ACE_DEBUG ((LM_DEBUG, "\ntrace_depth_ = %d\n", this->trace_depth_));
  ACE_DEBUG ((LM_DEBUG, "\trace_active_ = %d\n", this->trace_active_));
  ACE_DEBUG ((LM_DEBUG, "\tracing_enabled_ = %d\n", this->tracing_enabled_));
  ACE_DEBUG ((LM_DEBUG, "\npriority_mask_ = %d\n", this->priority_mask_));
  if (this->thr_state_ != 0)
    ACE_DEBUG ((LM_DEBUG, "\thr_state_ = %d\n", *this->thr_state_));
  ACE_DEBUG ((LM_DEBUG, "\nmsg_off_ = %d\n", this->msg_off_));
  ACE_Log_Msg_message_queue->dump ();

  ACE_MT (ACE_Log_Msg_Manager::get_lock ()->dump ());
  // Synchronize output operations.

  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
}

void
ACE_Log_Msg::op_status (int status)
{
  this->status_ = status;
}

int
ACE_Log_Msg::op_status (void)
{
  return this->status_;
}

void
ACE_Log_Msg::restart (int r)
{
  this->restart_ = r;
}

int
ACE_Log_Msg::restart (void)
{
  return this->restart_;
}

int
ACE_Log_Msg::errnum (void)
{
  return this->errnum_;
}

void
ACE_Log_Msg::errnum (int e)
{
  this->errnum_ = e;
}

int
ACE_Log_Msg::linenum (void)
{
  return this->linenum_;
}

void
ACE_Log_Msg::linenum (int l)
{
  this->linenum_ = l;
}

int
ACE_Log_Msg::inc (void)
{
  return this->trace_depth_++;
}

int
ACE_Log_Msg::dec (void)
{
  return --this->trace_depth_;
}

int
ACE_Log_Msg::trace_depth (void)
{
  return this->trace_depth_;
}

void
ACE_Log_Msg::trace_depth (int depth)
{
  this->trace_depth_ = depth;
}

int
ACE_Log_Msg::trace_active (void)
{
  return this->trace_active_;
}

void
ACE_Log_Msg::trace_active (int value)
{
  this->trace_active_ = value;
}

ACE_Thread_State *
ACE_Log_Msg::thr_state (void)
{
  return this->thr_state_;
}

void
ACE_Log_Msg::thr_state (ACE_Thread_State *ts)
{
  this->thr_state_ = ts;
}

ACE_hthread_t *
ACE_Log_Msg::thr_handle (void)
{
  return this->thr_handle_;
}

void
ACE_Log_Msg::thr_handle (ACE_hthread_t *th)
{
  this->thr_handle_ = th;
}

// Enable the tracing facility on a per-thread basis.

void
ACE_Log_Msg::start_tracing (void)
{
  this->tracing_enabled_ = 1;
}

// Disable the tracing facility on a per-thread basis.

void
ACE_Log_Msg::stop_tracing (void)
{
  this->tracing_enabled_ = 0;
}

int
ACE_Log_Msg::tracing_enabled (void)
{
  return this->tracing_enabled_;
}

const char *
ACE_Log_Msg::file (void)
{
  return this->file_;
}

void
ACE_Log_Msg::file (const char *s)
{
  ACE_OS::strncpy (this->file_, s,
                   (sizeof this->file_ / sizeof (char)));
}

char *
ACE_Log_Msg::msg (void)
{
  return this->msg_ + ACE_Log_Msg::msg_off_;
}

void
ACE_Log_Msg::msg (char *m)
{
  ACE_OS::strncpy (this->msg_, m,
                   (sizeof this->msg_ / sizeof (char)));
}

ostream *
ACE_Log_Msg::msg_ostream (void)
{
  return this->ostream_;
}

void
ACE_Log_Msg::msg_ostream (ostream *m)
{
  this->ostream_ = m;
}

void
ACE_Log_Msg::local_host (const char *s)
{
  if (s)
    {
      ACE_OS::free ((void *) ACE_Log_Msg::local_host_);
          {
                  ACE_NO_HEAP_CHECK;

              ACE_Log_Msg::local_host_ = ACE_OS::strdup (s);
          }
    }
}

const char *
ACE_Log_Msg::local_host (void) const
{
  return ACE_Log_Msg::local_host_;
}

pid_t
ACE_Log_Msg::getpid (void) const
{
  if (ACE_Log_Msg::pid_ == -1)
    ACE_Log_Msg::pid_ = ACE_OS::getpid ();

  return ACE_Log_Msg::pid_;
}
