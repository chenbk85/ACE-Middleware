// $Id$

// This is the main CPP file associated with the
// release non-unicode version of ACE.

#if defined(__BORLANDC__) && __BORLANDC__ >= 0x0530
#include <vcl.h>

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
  return 1;
}

USEUNIT("ACE.cpp");
USEUNIT("Activation_Queue.cpp");
USEUNIT("Acceptor.cpp");
USEUNIT("Addr.cpp");
USEUNIT("Arg_Shifter.cpp");
USEUNIT("ARGV.cpp");
USEUNIT("Array.cpp");
USEUNIT("Asynch_Acceptor.cpp");
USEUNIT("Asynch_IO.cpp");
USEUNIT("Auto_Ptr.cpp");
USEUNIT("Basic_Types.cpp");
USEUNIT("Connector.cpp");
USEUNIT("Containers.cpp");
USEUNIT("CORBA_Handler.cpp");
USEUNIT("CORBA_Ref.cpp");
USEUNIT("Date_Time.cpp");
USEUNIT("DEV.cpp");
USEUNIT("DEV_Addr.cpp");
USEUNIT("DEV_Connector.cpp");
USEUNIT("DEV_IO.cpp");
USEUNIT("Dump.cpp");
USEUNIT("Dump_T.cpp");
USEUNIT("Dynamic.cpp");
USEUNIT("Dynamic_Service.cpp");
USEUNIT("Env_Value_T.cpp");
USEUNIT("Event_Handler.cpp");
USEUNIT("Event_Handler_T.cpp");
USEUNIT("FIFO.cpp");
USEUNIT("FIFO_Recv.cpp");
USEUNIT("FIFO_Recv_Msg.cpp");
USEUNIT("FIFO_Send.cpp");
USEUNIT("FIFO_Send_Msg.cpp");
USEUNIT("FILE.cpp");
USEUNIT("FILE_Addr.cpp");
USEUNIT("FILE_Connector.cpp");
USEUNIT("FILE_IO.cpp");
USEUNIT("Filecache.cpp");
USEUNIT("Free_List.cpp");
USEUNIT("Future.cpp");
USEUNIT("Get_Opt.cpp");
USEUNIT("Handle_Set.cpp");
USEUNIT("Hash_Map_Manager.cpp");
USEUNIT("High_Res_Timer.cpp");
USEUNIT("INET_Addr.cpp");
USEUNIT("IO_Cntl_Msg.cpp");
USEUNIT("IO_SAP.cpp");
USEUNIT("IOStream.cpp");
USEUNIT("IOStream_T.cpp");
USEUNIT("IPC_SAP.cpp");
USEUNIT("Local_Name_Space.cpp");
USEUNIT("Local_Name_Space_T.cpp");
USEUNIT("Local_Tokens.cpp");
USEUNIT("LOCK_SOCK_Acceptor.cpp");
USEUNIT("Log_Msg.cpp");
USEUNIT("Log_Record.cpp");
USEUNIT("LSOCK.cpp");
USEUNIT("LSOCK_Acceptor.cpp");
USEUNIT("LSOCK_CODgram.cpp");
USEUNIT("LSOCK_Connector.cpp");
USEUNIT("LSOCK_Dgram.cpp");
USEUNIT("LSOCK_Stream.cpp");
USEUNIT("Malloc.cpp");
USEUNIT("Malloc_T.cpp");
USEUNIT("Managed_Object.cpp");
USEUNIT("Map_Manager.cpp");
USEUNIT("Mem_Map.cpp");
USEUNIT("Memory_Pool.cpp");
USEUNIT("Message_Block.cpp");
USEUNIT("Message_Queue.cpp");
USEUNIT("Method_Object.cpp");
USEUNIT("Module.cpp");
USEUNIT("Msg_WFMO_Reactor.cpp");
USEUNIT("Multiplexor.cpp");
USEUNIT("Name_Proxy.cpp");
USEUNIT("Name_Request_Reply.cpp");
USEUNIT("Name_Space.cpp");
USEUNIT("Naming_Context.cpp");
USEUNIT("Object_Manager.cpp");
USEUNIT("Obstack.cpp");
USEUNIT("OS.cpp");
USEUNIT("Parse_Node.cpp");
USEUNIT("Pipe.cpp");
USEUNIT("Priority_Reactor.cpp");
USEUNIT("Proactor.cpp");
USEUNIT("Process.cpp");
USEUNIT("Process_Manager.cpp");
USEUNIT("Profile_Timer.cpp");
USEUNIT("Reactor.cpp");
USEUNIT("Read_Buffer.cpp");
USEUNIT("Registry.cpp");
USEUNIT("Registry_Name_Space.cpp");
USEUNIT("Remote_Name_Space.cpp");
USEUNIT("Remote_Tokens.cpp");
USEUNIT("Sched_Params.cpp");
USEUNIT("Select_Reactor.cpp");
USEUNIT("Service_Config.cpp");
USEUNIT("Service_Manager.cpp");
USEUNIT("Service_Object.cpp");
USEUNIT("Service_Repository.cpp");
USEUNIT("Service_Types.cpp");
USEUNIT("Shared_Memory.cpp");
USEUNIT("Shared_Memory_MM.cpp");
USEUNIT("Shared_Memory_SV.cpp");
USEUNIT("Shared_Object.cpp");
USEUNIT("Signal.cpp");
USEUNIT("Singleton.cpp");
USEUNIT("SOCK.cpp");
USEUNIT("SOCK_Acceptor.cpp");
USEUNIT("SOCK_CODgram.cpp");
USEUNIT("SOCK_Connector.cpp");
USEUNIT("SOCK_Dgram.cpp");
USEUNIT("SOCK_Dgram_Bcast.cpp");
USEUNIT("SOCK_Dgram_Mcast.cpp");
USEUNIT("SOCK_IO.cpp");
USEUNIT("SOCK_Stream.cpp");
USEUNIT("SPIPE.cpp");
USEUNIT("SPIPE_Acceptor.cpp");
USEUNIT("SPIPE_Addr.cpp");
USEUNIT("SPIPE_Connector.cpp");
USEUNIT("SPIPE_Stream.cpp");
USEUNIT("SString.cpp");
USEUNIT("Strategies.cpp");
USEUNIT("Strategies_T.cpp");
USEUNIT("Stream.cpp");
USEUNIT("Stream_Modules.cpp");
USEUNIT("SV_Message.cpp");
USEUNIT("SV_Message_Queue.cpp");
USEUNIT("SV_Semaphore_Complex.cpp");
USEUNIT("SV_Semaphore_Simple.cpp");
USEUNIT("SV_Shared_Memory.cpp");
USEUNIT("Svc_Conf_l.cpp");
USEUNIT("Svc_Conf_y.cpp");
USEUNIT("Svc_Handler.cpp");
USEUNIT("Synch.cpp");
USEUNIT("Synch_Options.cpp");
USEUNIT("Synch_T.cpp");
USEUNIT("System_Time.cpp");
USEUNIT("Task.cpp");
USEUNIT("Task_T.cpp");
USEUNIT("Thread.cpp");
USEUNIT("Thread_Manager.cpp");
USEUNIT("Time_Request_Reply.cpp");
USEUNIT("Timer_Hash.cpp");
USEUNIT("Timer_Hash_T.cpp");
USEUNIT("Timer_Heap.cpp");
USEUNIT("Timer_Heap_T.cpp");
USEUNIT("Timer_List.cpp");
USEUNIT("Timer_List_T.cpp");
USEUNIT("Timer_Queue.cpp");
USEUNIT("Timer_Queue_Adapters.cpp");
USEUNIT("Timer_Queue_T.cpp");
USEUNIT("Timer_Wheel.cpp");
USEUNIT("Timer_Wheel_T.cpp");
USEUNIT("TLI.cpp");
USEUNIT("TLI_Acceptor.cpp");
USEUNIT("TLI_Connector.cpp");
USEUNIT("TLI_Stream.cpp");
USEUNIT("Token.cpp");
USEUNIT("Token_Collection.cpp");
USEUNIT("Token_Invariants.cpp");
USEUNIT("Token_Manager.cpp");
USEUNIT("Token_Request_Reply.cpp");
USEUNIT("Trace.cpp");
USEUNIT("TTY_IO.cpp");
USEUNIT("Typed_SV_Message.cpp");
USEUNIT("Typed_SV_Message_Queue.cpp");
USEUNIT("UNIX_Addr.cpp");
USEUNIT("UPIPE_Acceptor.cpp");
USEUNIT("UPIPE_Connector.cpp");
USEUNIT("UPIPE_Stream.cpp");
USEUNIT("WFMO_Reactor.cpp");
USEUNIT("XtReactor.cpp");
//---------------------------------------------------------------------------
#endif
