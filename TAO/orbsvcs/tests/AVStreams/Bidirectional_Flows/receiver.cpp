// $Id$

#include "receiver.h"
#include "ace/Get_Opt.h"
#include "ace/High_Res_Timer.h"

static FILE *output_file = 0;
// File handle of the file into which received data is written.

static const char *output_file_name = "output";
// File name of the file into which received data is written.

typedef ACE_Singleton<Receiver,ACE_Null_Mutex> RECEIVER;
//Create a singleton instance of the receiver.

int
Receiver_StreamEndPoint::get_callback (const char *,
                                       TAO_AV_Callback *&callback)
{
  // Return the receiver application callback to the AVStreams for
  // future upcalls.
  callback = &this->callback_;
  return 0;
}


int
Receiver_StreamEndPoint::set_protocol_object (const char * flowname,
					      TAO_AV_Protocol_Object *object)
{
  // Set the sender protocol object corresponding to the transport
  // protocol selected.
  if (ACE_OS::strcmp (flowname, "Data_Receiver1") == 0)
    RECEIVER::instance ()->protocol_object (object);
  return 0;
}

Receiver_Callback::Receiver_Callback (void)
  : frame_count_ (1),
      mb_ (BUFSIZ)
{
}

int
Receiver_Callback::receive_frame (ACE_Message_Block *frame,
                                  TAO_AV_frame_info *,
                                  const ACE_Addr &)
{
  //
  // Upcall from the AVStreams when there is data to be received from
  // the sender.
  //
  ACE_DEBUG ((LM_DEBUG,
              "Receiver_Callback::receive_frame for frame %d\n",
              this->frame_count_++));

  while (frame != 0)
    {
      // Write the received data to the file.
      size_t result =
        ACE_OS::fwrite (frame->rd_ptr (),
                        frame->length (),
                        1,
                        output_file);

      if (result == frame->length ())
        ACE_ERROR_RETURN ((LM_ERROR,
                           "Receiver_Callback::fwrite failed\n"),
                          -1);

      frame = frame->cont ();
    }
  
  // Read from the file into a message block.
  int n = ACE_OS::fread (this->mb_.wr_ptr (),
			 1,
			 this->mb_.size (),
			 RECEIVER::instance ()->input_file ());
  
  if (n < 0)
            ACE_DEBUG ((LM_DEBUG,
			"Receiver::receive_frame fread failed\n"));
  
  if (n == 0)
    {
      // At end of file break the loop and end the sender.
      ACE_DEBUG ((LM_DEBUG,"End of file\n"));
    }
  else
    {
      this->mb_.wr_ptr (n);
      
      // Send frame.
      int result =
	RECEIVER::instance ()->protocol_object ()->send_frame (&this->mb_);
      
      if (result < 0)
	ACE_DEBUG ((LM_DEBUG,
		    "Send Frame Failed\n"));
      
      // Reset the message block.
      this->mb_.reset ();
    }
  return 0;
}

int
Receiver_Callback::handle_destroy (void)
{
  // Called when the distributer requests the stream to be shutdown.
  ACE_DEBUG ((LM_DEBUG,
              "Receiver_Callback::handle_destroy\n"));

  static int count = 0;
  ++count;

  if (count < 2)
    {
      ACE_TRY_NEW_ENV
	{
	  TAO_AV_CORE::instance ()->orb ()->shutdown (0,
						      ACE_TRY_ENV);
	  ACE_TRY_CHECK;
	}
      ACE_CATCHANY
	{
	  ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
			       "Receiver_Callback::handle_destroy Failed\n");
      return -1;
      
	}

      ACE_ENDTRY;
    }

  return 0;
}

Receiver::Receiver (void)
  : mmdevice_ (0),
    frame_rate_ (30),
    input_file_ (0),
    frame_count_ (0),
    filename_ ("input"),
    mb_ (BUFSIZ)
{
}

Receiver::~Receiver (void)
{
}

void
Receiver::protocol_object (TAO_AV_Protocol_Object *object)
{
  // Set the sender protocol object corresponding to the transport
  // protocol selected.
  this->protocol_object_ = object;
}

int
Receiver::parse_args (int argc,
		      char **argv)
{
  // Parse command line arguments
  ACE_Get_Opt opts (argc, argv, "f:r:d");

  int c;
  while ((c= opts ()) != -1)
    {
      switch (c)
        {
        case 'f':
          this->filename_ = opts.optarg;
          break;
        case 'r':
          this->frame_rate_ = ACE_OS::atoi (opts.optarg);
          break;
        case 'd':
          TAO_debug_level++;
          break;
        default:
          ACE_DEBUG ((LM_DEBUG, "Unknown Option\n"));
          return -1;
        }
    }
  return 0;
}

int
Receiver::init (int argc,
                char ** argv,
                CORBA::Environment &ACE_TRY_ENV)
{
  // Initialize the endpoint strategy with the orb and poa.
  int result =
    this->reactive_strategy_.init (TAO_AV_CORE::instance ()->orb (),
                                   TAO_AV_CORE::instance ()->poa ());
  if (result != 0)
    return result;

    // Parse the command line arguments
  result =
    this->parse_args (argc,
                      argv);
  if (result != 0)
    return result;
  
  // Open file to read.
  this->input_file_ =
    ACE_OS::fopen (this->filename_.c_str (),
                   "r");

  if (this->input_file_ == 0)
    ACE_ERROR_RETURN ((LM_DEBUG,
                       "Cannot open input file %s\n",
                       this->filename_.c_str ()),
                      -1);
  else
    ACE_DEBUG ((LM_DEBUG,
                "Input File opened successfully\n"));

  // Register the receiver mmdevice object with the ORB
  ACE_NEW_RETURN (this->mmdevice_,
                  TAO_MMDevice (&this->reactive_strategy_),
                  -1);

  // Servant Reference Counting to manage lifetime
  PortableServer::ServantBase_var safe_mmdevice =
    this->mmdevice_;

  CORBA::Object_var mmdevice =
    this->mmdevice_->_this (ACE_TRY_ENV);
  ACE_CHECK_RETURN (-1);

  // Register the mmdevice with the naming service.
  CosNaming::Name name (1);
  name.length (1);
  name [0].id =
    CORBA::string_dup ("Receiver");

  // Initialize the naming services
  if (this->naming_client_.init (TAO_AV_CORE::instance ()->orb ()) != 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "Unable to initialize "
                       "the TAO_Naming_Client\n"),
                      -1);

  // Register the receiver object with the naming server.
  this->naming_client_->rebind (name,
                                mmdevice.in (),
                                ACE_TRY_ENV);
  ACE_CHECK_RETURN (-1);

  return 0;
}

TAO_AV_Protocol_Object*
Receiver::protocol_object (void)
{
  return this->protocol_object_;
}

FILE *
Receiver::input_file (void)
{
  return this->input_file_;
}

int
main (int argc,
      char **argv)
{
  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      // Initialize the ORB first.
      CORBA::ORB_var orb =
        CORBA::ORB_init (argc,
                         argv,
                         0,
                         ACE_TRY_ENV);
      ACE_TRY_CHECK;

      CORBA::Object_var obj
        = orb->resolve_initial_references ("RootPOA",
                                           ACE_TRY_ENV);
      ACE_TRY_CHECK;

      // Get the POA_var object from Object_var.
      PortableServer::POA_var root_poa =
        PortableServer::POA::_narrow (obj.in (),
                                      ACE_TRY_ENV);
      ACE_TRY_CHECK;

      PortableServer::POAManager_var mgr
        = root_poa->the_POAManager (ACE_TRY_ENV);
      ACE_TRY_CHECK;

      mgr->activate (ACE_TRY_ENV);
      ACE_TRY_CHECK;

      // Initialize the AVStreams components.
      TAO_AV_CORE::instance ()->init (orb.in (),
                                      root_poa.in (),
                                      ACE_TRY_ENV);
      ACE_TRY_CHECK;

      // Initialize the AVStreams components.
      TAO_AV_CORE::instance ()->init (orb.in (), root_poa.in (), ACE_TRY_ENV);
      ACE_TRY_CHECK;
      
      // Make sure we have a valid <output_file>
      output_file = ACE_OS::fopen (output_file_name,
                                   "w");
      if (output_file == 0)
        ACE_ERROR_RETURN ((LM_DEBUG,
                           "Cannot open output file %s\n",
                           output_file_name),
                          -1);

      else
        ACE_DEBUG ((LM_DEBUG,
                    "Output File Opened Successfully\n"));

      int result =
        RECEIVER::instance ()->init (argc,
				     argv,
				     ACE_TRY_ENV);
      ACE_TRY_CHECK;
      
      //        // Start sending data.
      //        result = SENDER::instance ()->pace_data (ACE_TRY_ENV);
      //        ACE_TRY_CHECK;
      
      if (result != 0)
        return result;

      orb->run (ACE_TRY_ENV);
      ACE_TRY_CHECK;
      
      // Hack for now....
      ACE_OS::sleep (1);
      
      //orb->destroy (ACE_TRY_ENV);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,"receiver::init");
      return -1;
    }
  ACE_ENDTRY;
  ACE_CHECK_RETURN (-1);

  ACE_OS::fclose (output_file);

  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_Singleton <Receiver,ACE_Null_Mutex>;
template class TAO_AV_Endpoint_Reactive_Strategy_B<Receiver_StreamEndPoint,TAO_VDev,AV_Null_MediaCtrl>;
template class TAO_AV_Endpoint_Reactive_Strategy<Receiver_StreamEndPoint,TAO_VDev,AV_Null_MediaCtrl>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_Singleton <Receiver,ACE_Null_Mutex>
#pragma instantiate TAO_AV_Endpoint_Reactive_Strategy_B<Receiver_StreamEndPoint,TAO_VDev,AV_Null_MediaCtrl>
#pragma instantiate TAO_AV_Endpoint_Reactive_Strategy<Receiver_StreamEndPoint,TAO_VDev,AV_Null_MediaCtrl>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
