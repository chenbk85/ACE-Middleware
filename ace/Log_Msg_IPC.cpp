// $Id$

#include "ace/Log_Msg_IPC.h"
#include "ace/Log_Record.h"
#include "ace/CDR_Stream.h"

ACE_RCSID(ace, Log_Msg_IPC, "$Id$")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Log_Msg_IPC::ACE_Log_Msg_IPC (void)
{
}

ACE_Log_Msg_IPC::~ACE_Log_Msg_IPC (void)
{
  (void) this->close ();
}

int
ACE_Log_Msg_IPC::open (const ACE_TCHAR *logger_key)
{
  ACE_LOG_MSG_IPC_CONNECTOR con;
  return con.connect (this->message_queue_,
                      ACE_LOG_MSG_IPC_ADDR (logger_key));
}

int
ACE_Log_Msg_IPC::reset (void)
{
  if (this->message_queue_.get_handle () != ACE_INVALID_HANDLE)
    {
      // If we don't do this, handles aren't reused on Win32 and the
      // server eventually crashes!
#if defined (ACE_WIN32)
      ACE_INT32 dummy = ~0;
      this->message_queue_.send_n ((const void *) &dummy,
                                    sizeof (ACE_INT32));
#endif /* ACE_WIN32 */
      return this->close ();
    }
  return 0;
}

int
ACE_Log_Msg_IPC::close (void)
{
  return this->message_queue_.close ();
}

int
ACE_Log_Msg_IPC::log (ACE_Log_Record &log_record)
{
  // Serialize the log record using a CDR stream, allocate enough
  // space for the complete <ACE_Log_Record>.
  const size_t max_payload_size =
    4 // type()
    + 8 // timestamp
    + 4 // process id
    + 4 // data length
    + ACE_Log_Record::MAXLOGMSGLEN // data
    + ACE_CDR::MAX_ALIGNMENT; // padding;

  // Insert contents of <log_record> into payload stream.
  ACE_OutputCDR payload (max_payload_size);
  payload << log_record;

  // Get the number of bytes used by the CDR stream.
  ACE_CDR::ULong length = payload.total_length ();

  // Send a header so the receiver can determine the byte order and
  // size of the incoming CDR stream.
  ACE_OutputCDR header (ACE_CDR::MAX_ALIGNMENT + 8);
  header << ACE_OutputCDR::from_boolean (ACE_CDR_BYTE_ORDER);

  // Store the size of the payload that follows
  header << ACE_CDR::ULong (length);

  // Use an iovec to send both buffer and payload simultaneously.
  iovec iov[2];
  iov[0].iov_base = header.begin ()->rd_ptr ();
  iov[0].iov_len  = 8;
  iov[1].iov_base = payload.begin ()->rd_ptr ();
  iov[1].iov_len  = length;

#if defined (ACE_HAS_STREAM_PIPES)
  // Use the <putpmsg> API if supported to ensure correct message
  // queueing according to priority.

  ACE_Str_Buf header (static_cast<void *> (header.begin ()->rd_ptr ()),
                      static_cast<int> (8);

  ACE_Str_Buf payload (static_cast<void *> (payload.begin ()->rd_ptr ()),
                      static_cast<int> (length));

  return this->message_queue_.send (&header,
                                    &payload,
                                    static_cast<int> (log_record.priority ()),
                                    MSG_BAND);
#else
  // We're running over sockets, so send header and payload
  // efficiently using "gather-write".
  return this->message_queue_.sendv_n (iov, 2);
#endif /* ACE_HAS_STREAM_PIPES */
}

ACE_END_VERSIONED_NAMESPACE_DECL
