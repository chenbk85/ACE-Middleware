/* -*- C++ -*- */
// $Id$
  
#define ACE_BUILD_DLL
#include "ace/POSIX_Proactor.h"

#if defined (ACE_HAS_AIO_CALLS)

#include "ace/Task_T.h"
#include "ace/Log_Msg.h"
#include "ace/Object_Manager.h"

#if !defined (__ACE_INLINE__)
#include "ace/POSIX_Proactor.i"
#endif /* __ACE_INLINE__ */

class ACE_Export ACE_POSIX_Wakeup_Completion : public ACE_POSIX_Asynch_Result
{
  // = TITLE
  //     This is result object is used by the <end_event_loop> of the 
  //     ACE_Proactor interface to wake up all the threads blocking
  //     for completions.
public:
  ACE_POSIX_Wakeup_Completion (ACE_Handler &handler,
                               const void *act = 0,
                               ACE_HANDLE event = ACE_INVALID_HANDLE,
                               int priority = 0,
                               int signal_number = ACE_SIGRTMIN);
  // Constructor.
  
  virtual ~ACE_POSIX_Wakeup_Completion (void);
  // Destructor.
  
  
  virtual void complete (u_long bytes_transferred = 0,
                         int success = 1,
                         const void *completion_key = 0,
                         u_long error = 0);
  // This method calls the <handler>'s <handle_wakeup> method.
};

// *********************************************************************

ACE_POSIX_Proactor::~ACE_POSIX_Proactor (void)
{
  this->close ();
}

int
ACE_POSIX_Proactor::close (void)
{
  return 0;
}

int
ACE_POSIX_Proactor::register_handle (ACE_HANDLE handle,
                                     const void *completion_key)
{
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (completion_key);
  return 0;
}

int
ACE_POSIX_Proactor::wake_up_dispatch_threads (void)
{
  return 0;
}

int
ACE_POSIX_Proactor::close_dispatch_threads (int)
{
  return 0;
}

size_t
ACE_POSIX_Proactor::number_of_threads (void) const
{
  // @@ Implement it.
  ACE_NOTSUP_RETURN (0);
}

void
ACE_POSIX_Proactor::number_of_threads (size_t threads)
{
  // @@ Implement it.
  ACE_UNUSED_ARG (threads);
}

ACE_HANDLE
ACE_POSIX_Proactor::get_handle (void) const
{
  return ACE_INVALID_HANDLE;
}

ACE_Asynch_Read_Stream_Result_Impl *
ACE_POSIX_Proactor::create_asynch_read_stream_result (ACE_Handler &handler,
                                                      ACE_HANDLE handle,
                                                      ACE_Message_Block &message_block,
                                                      u_long bytes_to_read,
                                                      const void* act,
                                                      ACE_HANDLE event,
                                                      int priority,
                                                      int signal_number)
{
  ACE_Asynch_Read_Stream_Result_Impl *implementation;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Read_Stream_Result (handler,
                                                       handle,
                                                       message_block,
                                                       bytes_to_read,
                                                       act,
                                                       event,
                                                       priority,
                                                       signal_number),
                  0);
  return implementation;
}

ACE_Asynch_Write_Stream_Result_Impl *
ACE_POSIX_Proactor::create_asynch_write_stream_result (ACE_Handler &handler,
                                                       ACE_HANDLE handle,
                                                       ACE_Message_Block &message_block,
                                                       u_long bytes_to_write,
                                                       const void* act,
                                                       ACE_HANDLE event,
                                                       int priority,
                                                       int signal_number)
{
  ACE_Asynch_Write_Stream_Result_Impl *implementation;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Write_Stream_Result (handler,
                                                        handle,
                                                        message_block,
                                                        bytes_to_write,
                                                        act,
                                                        event,
                                                        priority,
                                                        signal_number),
                  0);
  return implementation;
}

ACE_Asynch_Read_File_Result_Impl *
ACE_POSIX_Proactor::create_asynch_read_file_result (ACE_Handler &handler,
                                                    ACE_HANDLE handle,
                                                    ACE_Message_Block &message_block,
                                                    u_long bytes_to_read,
                                                    const void* act,
                                                    u_long offset,
                                                    u_long offset_high,
                                                    ACE_HANDLE event,
                                                    int priority,
                                                    int signal_number)
{
  ACE_Asynch_Read_File_Result_Impl *implementation;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Read_File_Result (handler,
                                                     handle,
                                                     message_block,
                                                     bytes_to_read,
                                                     act,
                                                     offset,
                                                     offset_high,
                                                     event,
                                                     priority,
                                                     signal_number),
                  0);
  return implementation;
}

ACE_Asynch_Write_File_Result_Impl *
ACE_POSIX_Proactor::create_asynch_write_file_result (ACE_Handler &handler,
                                                     ACE_HANDLE handle,
                                                     ACE_Message_Block &message_block,
                                                     u_long bytes_to_write,
                                                     const void* act,
                                                     u_long offset,
                                                     u_long offset_high,
                                                     ACE_HANDLE event,
                                                     int priority,
                                                     int signal_number)
{
  ACE_Asynch_Write_File_Result_Impl *implementation;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Write_File_Result (handler,
                                                      handle,
                                                      message_block,
                                                      bytes_to_write,
                                                      act,
                                                      offset,
                                                      offset_high,
                                                      event,
                                                      priority,
                                                      signal_number),
                  0);
  return implementation;
}



ACE_Asynch_Read_Dgram_Result_Impl *
ACE_POSIX_Proactor::create_asynch_read_dgram_result(ACE_Handler &handler,
                                                    ACE_HANDLE handle,
                                                    ACE_Message_Block *message_block,
                                                    size_t bytes_to_read,
                                                    int flags,
                                                    int protocol_family,
                                                    const void* act,
                                                    ACE_HANDLE event ,
                                                    int priority ,
                                                    int signal_number)

{
	ACE_Asynch_Read_Dgram_Result_Impl *implementation=0;
	/*
    ACE_NEW_RETURN (implementation,
		ACE_POSIX_Asynch_Read_Dgram_Result(handler,
											handle,		
											bytes_to_read,
											flags,
											addr,
											act,
											event,
											priority,
											signal_number),
											0);
                                            */
	return implementation;
}

ACE_Asynch_Write_Dgram_Result_Impl *
ACE_POSIX_Proactor::create_asynch_write_dgram_result (ACE_Handler &handler,
                                                      ACE_HANDLE handle,
                                                      ACE_Message_Block *message_block,
                                                      size_t bytes_to_write,
                                                      int flags,
                                                      const void* act,
                                                      ACE_HANDLE event,
                                                      int priority ,
                                                      int signal_number) 
{
	ACE_Asynch_Write_Dgram_Result_Impl *implementation=0;
	/*

	ACE_NEW_RETURN (implementation,
		ACE_POSIX_Asynch_Write_Dgram_Result(handler,
											handle,		
											bytes_to_write,
											flags,
											addr,
											act,
											event,
											priority,
											signal_number),
											0);
	*/										

	return implementation;
}


ACE_Asynch_Accept_Result_Impl *
ACE_POSIX_Proactor::create_asynch_accept_result (ACE_Handler &handler,
                                                 ACE_HANDLE listen_handle,
                                                 ACE_HANDLE accept_handle,
                                                 ACE_Message_Block &message_block,
                                                 u_long bytes_to_read,
                                                 const void* act,
                                                 ACE_HANDLE event,
                                                 int priority,
                                                 int signal_number)
{
  ACE_Asynch_Accept_Result_Impl *implementation;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Accept_Result (handler,
                                                  listen_handle,
                                                  accept_handle,
                                                  message_block,
                                                  bytes_to_read,
                                                  act,
                                                  event,
                                                  priority,
                                                  signal_number),
                  0);
  return implementation;
}

ACE_Asynch_Transmit_File_Result_Impl *
ACE_POSIX_Proactor::create_asynch_transmit_file_result (ACE_Handler &handler,
                                                        ACE_HANDLE socket,
                                                        ACE_HANDLE file,
                                                        ACE_Asynch_Transmit_File::Header_And_Trailer *header_and_trailer,
                                                        u_long bytes_to_write,
                                                        u_long offset,
                                                        u_long offset_high,
                                                        u_long bytes_per_send,
                                                        u_long flags,
                                                        const void *act,
                                                        ACE_HANDLE event,
                                                        int priority,
                                                        int signal_number)
{
  ACE_Asynch_Transmit_File_Result_Impl *implementation;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Transmit_File_Result (handler,
                                                         socket,
                                                         file,
                                                         header_and_trailer,
                                                         bytes_to_write,
                                                         offset,
                                                         offset_high,
                                                         bytes_per_send,
                                                         flags,
                                                         act,
                                                         event,
                                                         priority,
                                                         signal_number),
                  0);
  return implementation;
}

ACE_Asynch_Result_Impl *
ACE_POSIX_Proactor::create_asynch_timer (ACE_Handler &handler,
                                         const void *act,
                                         const ACE_Time_Value &tv,
                                         ACE_HANDLE event,
                                         int priority,
                                         int signal_number)
{
  ACE_Asynch_Result_Impl *implementation;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Timer (handler,
                                          act,
                                          tv,
                                          event,
                                          priority,
                                          signal_number),
                  0);
  return implementation;
}

ACE_POSIX_Proactor::ACE_POSIX_Proactor (void)
{
}

#if 0
int
ACE_POSIX_Proactor::handle_signal (int, siginfo_t *, ucontext_t *)
{
  // Perform a non-blocking "poll" for all the I/O events that have
  // completed in the I/O completion queue.

  ACE_Time_Value timeout (0, 0);
  int result = 0;

  for (;;)
    {
      result = this->handle_events (timeout);
      if (result != 0 || errno == ETIME)
        break;
    }

  // If our handle_events failed, we'll report a failure to the
  // Reactor.
  return result == -1 ? -1 : 0;
}

int
ACE_POSIX_Proactor::handle_close (ACE_HANDLE handle,
                                  ACE_Reactor_Mask close_mask)
{
  ACE_UNUSED_ARG (close_mask);
  ACE_UNUSED_ARG (handle);

  return this->close ();
}
#endif /* 0 */

void
ACE_POSIX_Proactor::application_specific_code (ACE_POSIX_Asynch_Result *asynch_result,
                                               u_long bytes_transferred,
                                               int success,
                                               const void */* completion_key*/,
                                               u_long error)
{
  ACE_SEH_TRY
    {
      // Call completion hook
      asynch_result->complete (bytes_transferred,
                               success,
                               0, // No completion key.
                               error);
    }
  ACE_SEH_FINALLY
    {
      // This is crucial to prevent memory leaks
      delete asynch_result;
    }
}

int
ACE_POSIX_Proactor::post_wakeup_completions (int how_many)
{
  ACE_POSIX_Wakeup_Completion *wakeup_completion = 0;

  for (ssize_t ci = 0; ci < how_many; ci++)
    {
      ACE_NEW_RETURN (wakeup_completion,
                      ACE_POSIX_Wakeup_Completion (this->wakeup_handler_),
                      -1);
      
      if (wakeup_completion->post_completion (this) == -1)
        return -1;
    }
  
  return 0;
}  

class ACE_Export ACE_AIOCB_Notify_Pipe_Manager : public ACE_Handler
{
  // = TITLE
  //     This class manages the notify pipe of the AIOCB
  //     Proactor. This class acts as the Handler for the
  //     <Asynch_Read> operations issued on the notify pipe. This
  //     class is very useful in implementing <Asynch_Accept> operation
  //     class for the <AIOCB_Proactor>. This is also useful for
  //     implementing <post_completion> for <AIOCB_Proactor>.
  //
  // = DESCRIPTION
  //     <AIOCB_Proactor> class issues a <Asynch_Read> on
  //     the pipe, using this class as the
  //     Handler. <POSIX_Asynch_Result *>'s are sent through the
  //     notify pipe. When <POSIX_Asynch_Result *>'s show up on the
  //     notify pipe, the <POSIX_AIOCB_Proactor> dispatches the
  //     completion of the <Asynch_Read_Stream> and calls the
  //     <handle_read_stream> of this class. This class calls
  //     <complete> on the <POSIX_Asynch_Result *> and thus calls the
  //     application handler.
  //     Handling the MessageBlock:
  //     We give this message block to read the result pointer through
  //     the notify pipe. We expect that to read 4 bytes from the
  //     notify pipe, for each <accept> call. Before giving this
  //     message block to another <accept>, we update <wr_ptr> and put
  //     it in its initial position.
public:
  ACE_AIOCB_Notify_Pipe_Manager (ACE_POSIX_AIOCB_Proactor *posix_aiocb_proactor);
  // Constructor. You need the posix proactor because you need to call
  // <application_specific_code>

  virtual ~ACE_AIOCB_Notify_Pipe_Manager (void);
  // Destructor.

  int notify (ACE_POSIX_Asynch_Result *result);
  // Send the result pointer through the notification pipe.

  virtual void handle_read_stream (const ACE_Asynch_Read_Stream::Result &result);
  // This is the call back method when <Asynch_Read> from the pipe is
  // complete.

private:
  ACE_POSIX_AIOCB_Proactor  *posix_aiocb_proactor_;
  // The implementation proactor class.

  ACE_Message_Block message_block_;
  // Message block to get ACE_POSIX_Asynch_Result pointer from the
  // pipe.

  ACE_Pipe pipe_;
  // Pipe for the communication between Proactor and the
  // Asynch_Accept.

  ACE_POSIX_AIOCB_Asynch_Read_Stream read_stream_;
  // To do asynch_read on the pipe.

  ACE_AIOCB_Notify_Pipe_Manager (void);
  // Default constructor. Shouldnt be called.
};

ACE_AIOCB_Notify_Pipe_Manager::ACE_AIOCB_Notify_Pipe_Manager (ACE_POSIX_AIOCB_Proactor *posix_aiocb_proactor)
  : posix_aiocb_proactor_ (posix_aiocb_proactor),
    message_block_ (sizeof (ACE_POSIX_Asynch_Accept_Result *)),
    read_stream_ (posix_aiocb_proactor)
{
  // Open the pipe.
  this->pipe_.open ();

  // Let AIOCB_Proactor know about our handle 
  posix_aiocb_proactor_->set_notify_handle (this->pipe_.read_handle ());

  // Open the read stream.
  if (this->read_stream_.open (*this,
                               this->pipe_.read_handle (),
                               0, // Completion Key
                               0) // Proactor
      == -1)
    ACE_ERROR ((LM_ERROR,
                "%N:%l:%p\n",
                "ACE_AIOCB_Notify_Pipe_Manager::ACE_AIOCB_Notify_Pipe_Manager:"
                "Open on Read Stream failed"));

  // Issue an asynch_read on the read_stream of the notify pipe.
  if (this->read_stream_.read (this->message_block_,
                               sizeof (ACE_POSIX_Asynch_Result *),
                               0, // ACT
                               0) // Priority
      == -1)
    ACE_ERROR ((LM_ERROR,
                "%N:%l:%p\n",
                "ACE_AIOCB_Notify_Pipe_Manager::ACE_AIOCB_Notify_Pipe_Manager:"
                "Read from pipe failed"));
}

ACE_AIOCB_Notify_Pipe_Manager::~ACE_AIOCB_Notify_Pipe_Manager (void)
{
}

int
ACE_AIOCB_Notify_Pipe_Manager::notify (ACE_POSIX_Asynch_Result *result)
{
  // Send the result pointer through the pipe.
  int return_val = ACE::send (this->pipe_.write_handle (),
                              ACE_reinterpret_cast (char *,
                                                    &result),
                              sizeof (result));
  if (return_val != sizeof (result))
    ACE_ERROR_RETURN ((LM_ERROR,
                       "(%P %t):%p\n",
                       "ACE_AIOCB_Notify_Pipe_Manager::notify"
                       "Error:Writing on to notify pipe failed"),
                      -1);
  return 0;
}

void
ACE_AIOCB_Notify_Pipe_Manager::handle_read_stream (const ACE_Asynch_Read_Stream::Result &result)
{
  // The message block actually contains the ACE_POSIX_Asynch_Result
  // pointer.
  ACE_POSIX_Asynch_Result *asynch_result = 0;
  asynch_result = *(ACE_POSIX_Asynch_Result **) result.message_block ().rd_ptr ();

  // Do the upcall.
  this->posix_aiocb_proactor_->application_specific_code 
            (asynch_result,
             asynch_result->bytes_transferred(), // 0, No bytes transferred.
             1,  // Result : True.
             0,  // No completion key.
             asynch_result->error());   //0, No error.

  // Set the message block properly. Put the <wr_ptr> back in the
  // initial position.
  if (this->message_block_.length () > 0)
      this->message_block_.wr_ptr (this->message_block_.rd_ptr ());

  // One accept has completed. Issue a read to handle any
  // <post_completion>s in the future.
  if (this->read_stream_.read (this->message_block_,
                               sizeof (ACE_POSIX_Asynch_Result *),
                               0,  // ACT
                               0)  // Priority
      == -1)
    ACE_ERROR ((LM_ERROR,
                "%N:%l:(%P | %t):%p\n",
                "ACE_AIOCB_Notify_Pipe_Manager::handle_read_stream:"
                "Read from pipe failed"));
}

// Public constructor for common use.
ACE_POSIX_AIOCB_Proactor::ACE_POSIX_AIOCB_Proactor (size_t max_aio_operations)
  : aiocb_notify_pipe_manager_ (0),
    aiocb_list_ (0),
    result_list_ (0),
    aiocb_list_max_size_ (max_aio_operations),
    aiocb_list_cur_size_ (0),
    notify_pipe_read_handle_ (ACE_INVALID_HANDLE),  
    num_deferred_aiocb_ (0),
    num_started_aio_(0)
{
  //check for correct value for max_aio_operations
  check_max_aio_num () ;

  ACE_NEW (aiocb_list_, 
           aiocb *[aiocb_list_max_size_]);
  ACE_NEW (result_list_,
           ACE_POSIX_Asynch_Result *[aiocb_list_max_size_]);

  // Initialize the array.
  for (size_t ai = 0; ai < this->aiocb_list_max_size_; ai++)
    {
      aiocb_list_[ai] = 0;
      result_list_[ai] = 0;
    }

  create_notify_manager ();
}

// Special protected constructor for ACE_SUN_Proactor
ACE_POSIX_AIOCB_Proactor::ACE_POSIX_AIOCB_Proactor (size_t max_aio_operations,int Flg)
  : aiocb_notify_pipe_manager_ (0),
    aiocb_list_ (0),
    result_list_ (0),
    aiocb_list_max_size_ (max_aio_operations),
    aiocb_list_cur_size_ (0),
    notify_pipe_read_handle_ (ACE_INVALID_HANDLE),  
    num_deferred_aiocb_ (0),
    num_started_aio_(0)
{
  ACE_UNUSED_ARG (Flg);

  //check for correct value for max_aio_operations
  check_max_aio_num () ;

  ACE_NEW (aiocb_list_, 
           aiocb *[aiocb_list_max_size_]);
  ACE_NEW (result_list_,
           ACE_POSIX_Asynch_Result *[aiocb_list_max_size_]);

  // Initialize the array.
  for (size_t ai = 0; ai < this->aiocb_list_max_size_; ai++)
    {
      aiocb_list_[ai] = 0;
      result_list_[ai] = 0;
    }

  // @@ We should create Notify_Pipe_Manager in the derived class to
  // provide correct calls for virtual functions !!!
}

// Destructor.
ACE_POSIX_AIOCB_Proactor::~ACE_POSIX_AIOCB_Proactor (void)
{
  delete_notify_manager ();

  // delete all uncomlpeted operarion
  // as nobody will notify client since now
  for (size_t ai = 0; ai < aiocb_list_max_size_; ai++)
    {
      delete result_list_[ai] ;
      result_list_[ai] = 0;
      aiocb_list_[ai] = 0;
    }


  delete [] aiocb_list_;
  aiocb_list_ = 0;
        
  delete [] result_list_;
  result_list_ = 0;
}

void ACE_POSIX_AIOCB_Proactor::set_notify_handle (ACE_HANDLE h)
{
  notify_pipe_read_handle_ = h ;
}

void ACE_POSIX_AIOCB_Proactor::check_max_aio_num ()
{
  long max_os_aio_num = ACE_OS ::sysconf ( _SC_AIO_MAX );

  // Define max limit AIO's for concrete OS
  // -1 means that there is no limit, but it is not true
  // ( example, SunOS 5.6)

  if (  max_os_aio_num > 0  
     && aiocb_list_max_size_ > ( unsigned long ) max_os_aio_num 
     )
     aiocb_list_max_size_ = max_os_aio_num ;

#if defined(HPUX)

  // Although HPUX 11.00 allows to start 2048 AIO's
  // for all process in system
  // it has a limit 256 max elements for aio_suspend ()
  // It is a pity, but ...

  long max_os_listio_num = ACE_OS ::sysconf ( _SC_AIO_LISTIO_MAX );
  if (  max_os_listio_num > 0  
     && aiocb_list_max_size_ > ( unsigned long ) max_os_listio_num 
     )
     aiocb_list_max_size_ = max_os_listio_num ;

#endif 

  // The last check for user-defined value
  // ACE_AIO_MAX_SIZE if defined in POSIX_Proactor.h

  if (  aiocb_list_max_size_ <= 0
     || aiocb_list_max_size_ > ACE_AIO_MAX_SIZE
     )
     aiocb_list_max_size_ = ACE_AIO_MAX_SIZE;

  ACE_DEBUG ((LM_DEBUG,
             "(%P | %t) ACE_POSIX_AIOCB_Proactor::Max Number of AIOs=%d\n",
              aiocb_list_max_size_)); 

}

void  
ACE_POSIX_AIOCB_Proactor::create_notify_manager (void)
{
  // Accept Handler for aio_accept. Remember! this issues a Asynch_Read
  // on the notify pipe for doing the Asynch_Accept.

  if (aiocb_notify_pipe_manager_ == 0)
    ACE_NEW (aiocb_notify_pipe_manager_,
             ACE_AIOCB_Notify_Pipe_Manager (this));
}

void  
ACE_POSIX_AIOCB_Proactor::delete_notify_manager (void)
{
  // We are responsible for delete as all pointers set to 0 after
  // delete, it is save to delete twice

  delete aiocb_notify_pipe_manager_;
  aiocb_notify_pipe_manager_ = 0;
}

int
ACE_POSIX_AIOCB_Proactor::handle_events (ACE_Time_Value &wait_time)
{
  // Decrement <wait_time> with the amount of time spent in the method
  ACE_Countdown_Time countdown (&wait_time);
  return this->handle_events (wait_time.msec ());
}

int
ACE_POSIX_AIOCB_Proactor::handle_events (void)
{
  return this->handle_events (ACE_INFINITE);
}

int
ACE_POSIX_AIOCB_Proactor::post_completion (ACE_POSIX_Asynch_Result *result)
{
  // Notify to the completion queue.
  return this->aiocb_notify_pipe_manager_->notify (result);
}

ACE_Asynch_Read_Stream_Impl *
ACE_POSIX_AIOCB_Proactor::create_asynch_read_stream (void)
{
  ACE_Asynch_Read_Stream_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_AIOCB_Asynch_Read_Stream (this),
                  0);
  return implementation;
}

ACE_Asynch_Write_Stream_Impl *
ACE_POSIX_AIOCB_Proactor::create_asynch_write_stream (void)
{
  ACE_Asynch_Write_Stream_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_AIOCB_Asynch_Write_Stream (this),
                  0);
  return implementation;
}
 
ACE_Asynch_Read_Dgram_Impl *
ACE_POSIX_AIOCB_Proactor::create_asynch_read_dgram (void)
{
    ACE_Asynch_Read_Dgram_Impl *implementation = 0;
    ACE_NEW_RETURN (implementation,
		ACE_POSIX_AIOCB_Asynch_Read_Dgram (this),
		0);
    return implementation;
}

ACE_Asynch_Write_Dgram_Impl *
ACE_POSIX_AIOCB_Proactor::create_asynch_write_dgram (void)
{
	ACE_Asynch_Write_Dgram_Impl *implementation = 0;
	ACE_NEW_RETURN (implementation,
		ACE_POSIX_AIOCB_Asynch_Write_Dgram (this),
		0);
	
    return implementation;
}

ACE_Asynch_Read_File_Impl *
ACE_POSIX_AIOCB_Proactor::create_asynch_read_file (void)
{
  ACE_Asynch_Read_File_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_AIOCB_Asynch_Read_File (this),
                  0);
  return  implementation;
}

ACE_Asynch_Write_File_Impl *
ACE_POSIX_AIOCB_Proactor::create_asynch_write_file (void)
{
  ACE_Asynch_Write_File_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_AIOCB_Asynch_Write_File (this),
                  0);
  return  implementation;
}

ACE_Asynch_Accept_Impl *
ACE_POSIX_AIOCB_Proactor::create_asynch_accept (void)
{
  ACE_Asynch_Accept_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Accept (this),
                  0);
  //was ACE_POSIX_AIOCB_Asynch_Accept (this)

  return implementation;
}

ACE_Asynch_Transmit_File_Impl *
ACE_POSIX_AIOCB_Proactor::create_asynch_transmit_file (void)
{
  ACE_Asynch_Transmit_File_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_AIOCB_Asynch_Transmit_File (this),
                  0);
  return  implementation;
}

int
ACE_POSIX_AIOCB_Proactor::handle_events (u_long milli_seconds)
{
  int result_suspend = 0;

  if (milli_seconds == ACE_INFINITE)
    // Indefinite blocking.
    result_suspend = aio_suspend (aiocb_list_,
                                  aiocb_list_max_size_,
                                  0);
  else
    {
      // Block on <aio_suspend> for <milli_seconds>
      timespec timeout;
      timeout.tv_sec = milli_seconds / 1000;
      timeout.tv_nsec = (milli_seconds - (timeout.tv_sec * 1000)) * 1000;
      result_suspend = aio_suspend (aiocb_list_,
                                    aiocb_list_max_size_,
                                    &timeout);
    }

  // Check for errors
  if (result_suspend == -1)
    {
      if (errno == EAGAIN)  // Timeout
        return 0;

      ACE_ERROR_RETURN ((LM_ERROR,
                         "%N:%l:(%P | %t)::%p\n",
                         "ACE_POSIX_AIOCB_Proactor::handle_events:"
                         "aio_suspend failed\n"),
                        0);  // let continue work
    }

  size_t index = 0;
  int error_status = 0;
  int return_status = 0;

  int retval= 0;

  for ( ; ; )
  {
    ACE_POSIX_Asynch_Result *asynch_result =
      find_completed_aio (error_status, return_status,index);

    if (asynch_result == 0)
      break;

    //at least one processed
    retval = 1 ; // more informative retval++  

    // Call the application code.
    this->application_specific_code (asynch_result,
                                   return_status, // Bytes transferred.
                                   1,             // Success
                                   0,             // No completion key.
                                   error_status); // Error
  }

  return retval;    
}

ACE_POSIX_Asynch_Result *
ACE_POSIX_AIOCB_Proactor::find_completed_aio (int &error_status,
                                              int &return_status,
                                              size_t &index )
{
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->mutex_, 0));
  
  ACE_POSIX_Asynch_Result *asynch_result = 0;

  error_status = 0;
  return_status= 0;

  if ( num_started_aio_ == 0 )  // save time
    return asynch_result;
        
  for (; index < aiocb_list_max_size_; index++)
    {
      if (aiocb_list_[index] == 0) // Dont process null blocks.
        continue;

      // Get the error status of the aio_ operation.
      error_status = aio_error (aiocb_list_[index]);

      if (error_status == -1)   // <aio_error> itself has failed.
        {
          ACE_ERROR ((LM_ERROR,
                      "%N:%l:(%P | %t)::%p\n",
                      "ACE_POSIX_AIOCB_Proactor::find_completed_aio:"
                      "<aio_error> has failed\n"));

          break;

          // we should notify user, otherwise : 
          // memory leak for result and "hanging" user
          // what was before skip this operation  

          //aiocb_list_[index] = 0;
          //result_list_[index] = 0;
          //aiocb_list_cur_size_--;
          //continue;
        }

      // Continue the loop if <aio_> operation is still in progress.
      if (error_status != EINPROGRESS)
        break;

    } // end for

  if (index >= this->aiocb_list_max_size_) // all processed
    return asynch_result;
  else if (error_status == ECANCELED)
    return_status = 0;
  else if (error_status == -1)
    return_status = 0;
  else 
    return_status = aio_return (aiocb_list_[index]);
    
  if (return_status == -1) 
    {
      return_status = 0; // zero bytes transferred

      if (error_status == 0)  // nonsense 
        ACE_ERROR ((LM_ERROR,   
                  "%N:%l:(%P | %t)::%p\n",
                  "ACE_POSIX_AIOCB_Proactor::find_completed_aio:"
                  "<aio_return> failed\n"));
    }

  
  asynch_result = result_list_[index];

  aiocb_list_[index] = 0;
  result_list_[index] = 0;
  aiocb_list_cur_size_--;

  num_started_aio_--;  // decrement count active aios
  index++ ;            // for next iteration

  this->start_deferred_aio ();
  //make attempt to start deferred AIO
  //It is safe as we are protected by mutex_

  return asynch_result;
}

void
ACE_POSIX_AIOCB_Proactor::application_specific_code (ACE_POSIX_Asynch_Result *asynch_result,
                                                     u_long bytes_transferred,
                                                     int success,
                                                     const void *completion_key,
                                                     u_long error)
{
  ACE_POSIX_Proactor::application_specific_code (asynch_result,
                                                 bytes_transferred,
                                                 success,
                                                 completion_key,
                                                 error);
}

int
ACE_POSIX_AIOCB_Proactor::register_and_start_aio 
  (ACE_POSIX_Asynch_Result *result, int op)
{
  ACE_TRACE ("ACE_POSIX_AIOCB_Proactor::register_and_start_aio");

  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->mutex_, -1));
  
  int ret_val = (aiocb_list_cur_size_ >= aiocb_list_max_size_) ? -1 : 0;

  if (result == 0) // Just check the status of the list
    return ret_val;

  // Save operation code in the aiocb
  switch ( op )
  {
    case 0 : 
      result->aio_lio_opcode = LIO_READ;
      break;

    case 1 : 
      result->aio_lio_opcode = LIO_WRITE;
      break;
    
    default:
      ACE_ERROR_RETURN ((LM_ERROR,
                "%N:%l:(%P | %t)::\n"
                "register_and_start_aio: Invalid operation code\n"),
                -1);
  }

  if (ret_val != 0)   // No free slot
    {                                   
      errno   = EAGAIN;
      ACE_ERROR_RETURN ((LM_ERROR,
              "%N:%l:(%P | %t)::\n"
              "register_and_start_aio: "
              "No space to store the <aio>info\n"),
              -1);
    }

  // Find a free slot and store.
  // we reserve zero slot for ACE_AIOCB_Notify_Pipe_Manager
  // so make check for ACE_AIOCB_Notify_Pipe_Manager request

  size_t i = 0;

  if ( notify_pipe_read_handle_ == result->aio_fildes ) // Notify_Pipe ?
    {                                       // should be free,
      if ( result_list_[i] != 0 )           // only 1 request 
        {                                   // is allowed
          errno   = EAGAIN;
          ACE_ERROR_RETURN ((LM_ERROR,
                     "%N:%l:(%P | %t)::\n"
                     "register_and_start_aio:"
                     "internal Proactor error 0\n"),
                     -1 );
        }
    }
  else  //try to find free slot as usual, but starting from 1
    {
      for ( i= 1; i < this->aiocb_list_max_size_; i++) 
        if (result_list_[i] == 0)  
          break ;
    }
  
  if ( i >= this->aiocb_list_max_size_ )
    ACE_ERROR_RETURN ((LM_ERROR,
              "%N:%l:(%P | %t)::\n"
              "register_and_start_aio: "
              "internal Proactor error 1\n"),
              -1);

  result_list_[i] = result;   //Store result ptr anyway
  aiocb_list_cur_size_++;

  ret_val = start_aio (result);

  switch ( ret_val )
    {
    case 0 :     // started OK
      aiocb_list_[i] = result;
      return 0 ;

    case 1 :     //OS AIO queue overflow
      num_deferred_aiocb_ ++ ;
      return 0 ;
  
    default:    //Invalid request, there is no point
      break;    // to start it later 
    }

  result_list_[i] = 0;
  aiocb_list_cur_size_--;
                                 
  ACE_ERROR ((LM_ERROR,
              "%N:%l:(%P | %t)::%p\n",
              "register_and_start_aio: Invalid request to start <aio>\n"));
  return -1;
}

// start_aio  has new return codes
//     0    AIO was started successfully
//     1    AIO was not started, OS AIO queue overflow
//     -1   AIO was not started, other errors

int
ACE_POSIX_AIOCB_Proactor::start_aio (ACE_POSIX_Asynch_Result *result)
{
  ACE_TRACE ("ACE_POSIX_AIOCB_Proactor::start_aio");

  int ret_val;
  const ACE_TCHAR *ptype;

  // Start IO

  switch (result->aio_lio_opcode  )
    {
    case LIO_READ :
      ptype = "read ";
      ret_val = aio_read (result);
      break;
    case LIO_WRITE :
      ptype = "write";
      ret_val = aio_write (result);
      break;
    default:
      ptype = "?????";
      ret_val = -1;
      break;
    }

  if (ret_val == 0 )
    num_started_aio_ ++ ;
  else // if (ret_val == -1)
    {
      if ( errno == EAGAIN )  //Ok, it will be deferred AIO
         ret_val = 1 ;
      else
        ACE_ERROR ((LM_ERROR,
                "%N:%l:(%P | %t)::start_aio: aio_%s %p\n",
                ptype,
                "queueing failed\n"));
    }

  return ret_val;
}


int
ACE_POSIX_AIOCB_Proactor::start_deferred_aio ()
{
  ACE_TRACE ("ACE_POSIX_AIOCB_Proactor::start_deferred_aio");

  // This protected method is called from 
  // find_completed_aio after any AIO completion
  // We should call this method always with locked 
  //   ACE_POSIX_AIOCB_Proactor::mutex_ 
  //
  // It tries to start the first deferred AIO 
  // if such exists

  if ( num_deferred_aiocb_ == 0 )
    return 0 ;  //  nothing to do

  size_t i = 0;

  for ( i= 0; i < this->aiocb_list_max_size_; i++) 
    if (  result_list_[i] !=0       // check for
       && aiocb_list_[i]  ==0 )     // deferred AIO
      break ;

  if ( i >= this->aiocb_list_max_size_ )
    ACE_ERROR_RETURN ((LM_ERROR,
                 "%N:%l:(%P | %t)::\n"
                 "start_deferred_aio:"
                 "internal Proactor error 3\n"),
                 -1);
    
  ACE_POSIX_Asynch_Result *result = result_list_[i];

  int ret_val = start_aio (result);

  switch ( ret_val )
    {
    case 0 :    //started OK , decrement count of deferred AIOs
      aiocb_list_[i] = result;
      num_deferred_aiocb_ -- ;   
      return 0 ;

    case 1 :
      return 0 ;  //try again later

    default :     // Invalid Parameters , should never be
      break ;
    }
 
  //AL notify  user

  result_list_[i] = 0;
  aiocb_list_cur_size_--;

  num_deferred_aiocb_ -- ;   

  result->set_error (errno);
  result->set_bytes_transferred (0);
  this->post_completion ( result );

  return -1;
}

int
ACE_POSIX_AIOCB_Proactor::cancel_aio ( ACE_HANDLE handle )
{
  // This new method should be called from 
  // ACE_POSIX_Asynch_Operation instead of usual ::aio_cancel
  // It scans the result_list_ and defines all AIO requests 
  // that were issued for handle "handle"
  //
  // For all deferred AIO requests with handle "handle"
  // it removes its from the lists and notifies user
  //
  // For all running AIO requests with handle "handle" 
  // it calls ::aio_cancel. According to the POSIX standards
  // we will receive ECANCELED  for all ::aio_canceled AIO requests
  // later on return from ::aio_suspend

  ACE_TRACE ("ACE_POSIX_AIOCB_Proactor::cancel_aio");

  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->mutex_, -1));
        
  int    num_total     = 0;
  int    num_cancelled = 0;
  size_t ai = 0;

  for (ai = 0; ai < aiocb_list_max_size_; ai++)
    {
      if ( result_list_[ai] == 0 )    //skip empty slot
         continue ;

      if ( result_list_[ai]->aio_fildes != handle )  //skip not our slot
         continue ;

      num_total++ ;  

      ACE_POSIX_Asynch_Result *asynch_result = result_list_[ai];
    
      if ( aiocb_list_ [ai] == 0 )  //deferred aio
        {
          num_cancelled ++ ;
          num_deferred_aiocb_ -- ;

          aiocb_list_[ai] = 0;
          result_list_[ai] = 0;
          aiocb_list_cur_size_--;

          asynch_result->set_error (ECANCELED);
          asynch_result->set_bytes_transferred (0);
          this->post_completion ( asynch_result );
        }
      else      //cancel started aio
        {
          int rc_cancel = this->cancel_aiocb (asynch_result );

          if ( rc_cancel == 0 )    //notification in the future
            num_cancelled ++ ;     //it is OS responsiblity
        }
    }

  if ( num_total == 0 )
    return 1;  // ALLDONE

  if ( num_cancelled == num_total )
    return 0;  // CANCELLED

  return 2; // NOT CANCELLED
}

int
ACE_POSIX_AIOCB_Proactor::cancel_aiocb ( ACE_POSIX_Asynch_Result * result )
{
  // This new method is called from cancel_aio
  // to cancel concrete running AIO request
  int rc = ::aio_cancel (0, result );
  
  // Check the return value and return 0/1/2 appropriately.
  if (rc == AIO_CANCELED)
    return 0;
  else if (rc == AIO_ALLDONE)
    return 1;
  else if (rc == AIO_NOTCANCELED)
    return 2;

  ACE_ERROR_RETURN ((LM_ERROR,
                       "%N:%l:(%P | %t)::%p\n",
                       "cancel_aiocb:"
                       "Unexpected result from <aio_cancel>"),
                      -1);

}


// *********************************************************************

ACE_POSIX_SIG_Proactor::ACE_POSIX_SIG_Proactor (void)
{
  // = Set up the mask we'll use to block waiting for SIGRTMIN. Use that
  // to add it to the signal mask for this thread, and also set the process
  // signal action to pass signal information when we want it.

  // Clear the signal set.
  if (sigemptyset (&this->RT_completion_signals_) == -1)
    ACE_ERROR ((LM_ERROR,
                "Error:%p\n",
                "Couldn't init the RT completion signal set"));

  // Add the signal number to the signal set.
  if (sigaddset (&this->RT_completion_signals_, ACE_SIGRTMIN) == -1)
    ACE_ERROR ((LM_ERROR,
                "Error:%p\n",
                "Couldnt init the RT completion signal set"));
  this->mask_signals (&this->RT_completion_signals_);
  // Set up the signal action for SIGRTMIN.
  this->setup_signal_handler (ACE_SIGRTMIN);
}

ACE_POSIX_SIG_Proactor::ACE_POSIX_SIG_Proactor (const sigset_t signal_set)
{
  // = Keep <Signal_set> with the Proactor, mask all the signals and
  //   setup signal actions for the signals in the <signal_set>.

  // = Keep <signal_set> with the Proactor.

  // Empty the signal set first.
  if (sigemptyset (&this->RT_completion_signals_) == -1)
    ACE_ERROR ((LM_ERROR,
                "Error:(%P | %t):%p\n",
                "sigemptyset failed"));

  // For each signal number present in the <signal_set>, add it to
  // the signal set we use, and also set up its process signal action
  // to allow signal info to be passed into sigwait/sigtimedwait.
  int member = 0;
  for (int si = ACE_SIGRTMIN; si <= ACE_SIGRTMAX; si++)
    {
      member = sigismember (&signal_set,
                            si);
      if (member == -1)
        ACE_ERROR ((LM_ERROR,
                    "%N:%l:(%P | %t)::%p\n",
                    "ACE_POSIX_SIG_Proactor::ACE_POSIX_SIG_Proactor:"
                    "sigismember failed"));
      else if (member == 1)
        {
          sigaddset (&this->RT_completion_signals_, si);
          this->setup_signal_handler (si);
        }
    }

  // Mask all the signals.
  this->mask_signals (&this->RT_completion_signals_);

  return;
}

ACE_POSIX_SIG_Proactor::~ACE_POSIX_SIG_Proactor (void)
{
  // @@ Enable the masked signals again.
}

int
ACE_POSIX_SIG_Proactor::handle_events (ACE_Time_Value &wait_time)
{
  // Decrement <wait_time> with the amount of time spent in the method
  ACE_Countdown_Time countdown (&wait_time);
  return this->handle_events (wait_time.msec ());
}

int
ACE_POSIX_SIG_Proactor::handle_events (void)
{
  return this->handle_events (ACE_INFINITE);
}

int
ACE_POSIX_SIG_Proactor::post_completion (ACE_POSIX_Asynch_Result *result)
{
  // Get this process id.
  pid_t pid = ACE_OS::getpid ();
  if (pid == (pid_t) -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "Error:%N:%l(%P | %t):%p",
                       "<getpid> failed"),
                      -1);

  // Set the signal information.
  sigval value;
  value.sival_ptr = ACE_reinterpret_cast (void *,
                                          result);

  // Queue the signal.
  if (sigqueue (pid, result->signal_number (), value) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "Error:%N:%l:(%P | %t):%p\n",
                       "<sigqueue> failed"),
                      -1);
  return 0;
}

ACE_Asynch_Read_Stream_Impl *
ACE_POSIX_SIG_Proactor::create_asynch_read_stream (void)
{
  ACE_Asynch_Read_Stream_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_SIG_Asynch_Read_Stream (this),
                  0);
  return  implementation;
}

ACE_Asynch_Write_Stream_Impl *
ACE_POSIX_SIG_Proactor::create_asynch_write_stream (void)
{
  ACE_Asynch_Write_Stream_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_SIG_Asynch_Write_Stream (this),
                  0);
  return  implementation;
}

ACE_Asynch_Read_Dgram_Impl *
ACE_POSIX_SIG_Proactor::create_asynch_read_dgram (void)
{
    ACE_Asynch_Read_Dgram_Impl *implementation = 0;
	ACE_NEW_RETURN (implementation,
		ACE_POSIX_SIG_Asynch_Read_Dgram(this),
		0);

    return implementation;
}

ACE_Asynch_Write_Dgram_Impl *
ACE_POSIX_SIG_Proactor::create_asynch_write_dgram (void)
{
    ACE_Asynch_Write_Dgram_Impl *implementation = 0;
	ACE_NEW_RETURN (implementation,
		ACE_POSIX_SIG_Asynch_Write_Dgram(this),
		0);
	

    return implementation;
}

ACE_Asynch_Read_File_Impl *
ACE_POSIX_SIG_Proactor::create_asynch_read_file (void)
{
  ACE_Asynch_Read_File_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_SIG_Asynch_Read_File (this),
                  0);
  return  implementation;
}

ACE_Asynch_Write_File_Impl *
ACE_POSIX_SIG_Proactor::create_asynch_write_file (void)
{
  ACE_Asynch_Write_File_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_SIG_Asynch_Write_File (this),
                  0);
  return  implementation;
}

ACE_Asynch_Accept_Impl *
ACE_POSIX_SIG_Proactor::create_asynch_accept (void)
{
  ACE_Asynch_Accept_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Accept (this),
                  0);

  // was  ACE_POSIX_SIG_Asynch_Accept (this),
  return implementation;
}

ACE_Asynch_Transmit_File_Impl *
ACE_POSIX_SIG_Proactor::create_asynch_transmit_file (void)
{
  ACE_Asynch_Transmit_File_Impl *implementation = 0;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_SIG_Asynch_Transmit_File (this),
                  0);
  return  implementation;
}

ACE_Asynch_Result_Impl *
ACE_POSIX_SIG_Proactor::create_asynch_timer (ACE_Handler &handler,
                                             const void *act,
                                             const ACE_Time_Value &tv,
                                             ACE_HANDLE event,
                                             int priority,
                                             int signal_number)
{
  int is_member = 0;

  // Fix the signal number.
  if (signal_number == -1)
    {
      int si;
      for (si = ACE_SIGRTMAX;
           (is_member == 0) && (si >= ACE_SIGRTMIN);
           si--)
        {
          is_member = sigismember (&this->RT_completion_signals_,
                                   si);
          if (is_member == -1)
            ACE_ERROR_RETURN ((LM_ERROR,
                               "%N:%l:(%P | %t)::%s\n",
                               "ACE_POSIX_SIG_Proactor::create_asynch_timer:"
                               "sigismember failed"),
                              0);
        }

      if (is_member == 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "Error:%N:%l:(%P | %t)::%s\n",
                           "ACE_POSIX_SIG_Proactor::ACE_POSIX_SIG_Proactor:"
                           "Signal mask set empty"),
                          0);
      else
        // + 1 to nullify loop increment.
        signal_number = si + 1;
    }

  ACE_Asynch_Result_Impl *implementation;
  ACE_NEW_RETURN (implementation,
                  ACE_POSIX_Asynch_Timer (handler,
                                          act,
                                          tv,
                                          event,
                                          priority,
                                          signal_number),
                  0);
  return implementation;
}

int
ACE_POSIX_SIG_Proactor::setup_signal_handler (int signal_number) const
{
  // Set up the specified signal so that signal information will be
  // passed to sigwaitinfo/sigtimedwait. Don't change the default
  // signal handler - having a handler and waiting for the signal can
  // produce undefined behavior.
  struct sigaction reaction;
  sigemptyset (&reaction.sa_mask);   // Nothing else to mask.
  reaction.sa_flags = SA_SIGINFO;    // Realtime flag.
  reaction.sa_sigaction = ACE_SIGNAL_C_FUNC (SIG_DFL);
  int sigaction_return = ACE_OS::sigaction (signal_number,
                                            &reaction,
                                            0);
  if (sigaction_return == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "Error:%p\n",
                       "Proactor couldnt do sigaction for the RT SIGNAL"),
                      -1);
  return 0;
}


int
ACE_POSIX_SIG_Proactor::mask_signals (const sigset_t *signals) const
{
  if (ACE_OS::pthread_sigmask (SIG_BLOCK, signals, 0) != 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "Error:(%P | %t):%p\n",
                       "pthread_sigmask failed"),
                      -1);
  return 0;
}

int
ACE_POSIX_SIG_Proactor::handle_events (unsigned long milli_seconds)
{
  int result_sigwait = 0;
  siginfo_t sig_info;

  // Mask all the signals.
  if (this->mask_signals (&this->RT_completion_signals_) != 0)
    return -1;

  // Wait for the signals.
  if (milli_seconds == ACE_INFINITE)
    {
      result_sigwait = sigwaitinfo (&this->RT_completion_signals_,
                                    &sig_info);
    }
  else
    {
      // Wait for <milli_seconds> amount of time.
      timespec timeout;
      timeout.tv_sec = milli_seconds / 1000;
      timeout.tv_nsec = (milli_seconds - (timeout.tv_sec * 1000)) * 1000;
      result_sigwait = sigtimedwait (&this->RT_completion_signals_,
                                     &sig_info,
                                     &timeout);
    }

  // Check for errors
  if (result_sigwait == -1)
    {
      // If failure is coz of timeout, then return *0* but set errno
      // appropriately.
      if (errno == EAGAIN)
        return 0;
      else
        ACE_ERROR_RETURN ((LM_ERROR,
                           "%N:%l:(%P | %t)::%p\n",
                           "ACE_POSIX_SIG_Proactor::handle_events:"
                           "sigtimedwait/sigwaitinfo failed"),
                          -1);
    }

  // No errors, RT compleion signal is received.

  // Is the signo returned consistent with the sig info?
  if (sig_info.si_signo != result_sigwait)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "Error:%N:%l:(%P | %t):"
                       "ACE_POSIX_SIG_Proactor::handle_events:"
                       "Inconsistent signal number (%d) in the signal info block",
                       sig_info.si_signo),
                      -1);

  // Retrive the result pointer.
  ACE_POSIX_Asynch_Result *asynch_result = ACE_reinterpret_cast (ACE_POSIX_Asynch_Result *,
                                                                 sig_info.si_value.sival_ptr);

  // Check the <signal code> and act according to that.
  if (sig_info.si_code == SI_ASYNCIO)
    {
      // Analyze error and return values.
      
      int error_status = 0;
      int return_status = 0;
      
      // Check the error status
      error_status = aio_error (asynch_result);

      // <aio_error> itself has failed.
      if (error_status == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "%N:%l:(%P | %t)::%p\n",
                           "ACE_POSIX_SIG_Proactor::handle_events:"
                           "<aio_error> has failed"),
                          -1);

      // Completion signal has been received, so it can't be in
      // progress.
      if (error_status == EINPROGRESS)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "%N:%l:(%P | %t)::%p\n",
                           "ACE_POSIX_SIG_Proactor::handle_events:"
                           "Internal error: AIO in progress. "
                           "But completion signal was received"),
                          -1);

      // Handle cancel'ed asynchronous operation. We dont have to call
      // <aio_return> in this case, since return_status is going to be
      // -1. We will pass 0 for the <bytes_transferred> in this case
      if (error_status == ECANCELED)
        {
          return_status = 0;
        }
      else 
        {
          // Get the return_status of the <aio_> operation.
          return_status = aio_return (asynch_result);

          // Failure.
          if (return_status == -1)
            {                                           
              ACE_ERROR ((LM_ERROR,
                          "%N:%l:(%P | %t)::%p\n",
                          "ACE_POSIX_SIG_Proactor::handle_events:"
                          "<aio_return> failed"));
              return_status = 0; // zero bytes transferred
            }

        }

      // Error status and return status are obtained. Dispatch the
      // completion.
      this->application_specific_code (asynch_result,
                                       return_status,
                                       1,             // Result : True.
                                       0,             // No completion key.
                                       error_status); // Error.
    }
  else if (sig_info.si_code == SI_QUEUE)
    {
      this->application_specific_code 
            (asynch_result,
             asynch_result->bytes_transferred(), // 0, No bytes transferred.
             1,  // Result : True.
             0,  // No completion key.
             asynch_result->error());   //0, No error.
    }
  else
    // Unknown signal code.
    ACE_ERROR_RETURN ((LM_DEBUG,
                       "%N:%l:(%P | %t):",
                       "ACE_POSIX_SIG_Proactor::handle_events:\n"
                       "Unexpected signal code (%d) returned on completion querying\n",
                       sig_info.si_code),
                      -1);

  // Success
  return 1;
}

// *********************************************************************

ACE_POSIX_Asynch_Timer::ACE_POSIX_Asynch_Timer (ACE_Handler &handler,
                                                const void *act,
                                                const ACE_Time_Value &tv,
                                                ACE_HANDLE event,
                                                int priority,
                                                int signal_number)
  : ACE_Asynch_Result_Impl (),
    ACE_POSIX_Asynch_Result (handler, act, event, 0, 0, priority, signal_number),
    time_ (tv)
{
}

void
ACE_POSIX_Asynch_Timer::complete (u_long       /* bytes_transferred */,
                                  int          /* success */,
                                  const void * /* completion_key */,
                                  u_long       /* error */)
{
  this->handler_.handle_time_out (this->time_, this->act ());
}

// *********************************************************************

ACE_POSIX_Wakeup_Completion::ACE_POSIX_Wakeup_Completion (ACE_Handler &handler,
                                                          const void *act,
                                                          ACE_HANDLE event,
                                                          int priority,
                                                          int signal_number)
  : ACE_Asynch_Result_Impl (),
    ACE_POSIX_Asynch_Result (handler, act, event, 0, 0, priority, signal_number)
{
}

ACE_POSIX_Wakeup_Completion::~ACE_POSIX_Wakeup_Completion (void)
{
}

void
ACE_POSIX_Wakeup_Completion::complete (u_long       /* bytes_transferred */,
                                       int          /* success */,
                                       const void * /* completion_key */,
                                       u_long       /*  error */)
{
  this->handler_.handle_wakeup ();
}

#endif /* ACE_HAS_AIO_CALLS */
