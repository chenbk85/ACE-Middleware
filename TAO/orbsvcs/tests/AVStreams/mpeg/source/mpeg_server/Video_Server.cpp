#include "Video_Server.h"

/* $Id$  */

// Global Methods

 PLAYpara Video_Server::para;

int
play_send ()
{
  int curGroup = Video_Timer_Global::timerGroup;
  int curFrame = Video_Timer_Global::timerFrame;
  int curHeader = Video_Timer_Global::timerHeader;
  char * sp;
    
  if (VIDEO_SINGLETON::instance ()->preGroup != curGroup || curFrame != VIDEO_SINGLETON::instance ()->preFrame)
    {
      int sendStatus = -1;
      int frameStep = 1;
      if (curGroup == 0)
        {
          int i = curFrame + 1;
          while (i < VIDEO_SINGLETON::instance ()->firstPatternSize && !VIDEO_SINGLETON::instance ()->firstSendPattern[i])
            {
              frameStep ++;
              i++;
            }
        }
      else  /* (curGroup > 0) */
        {
          int i = curFrame + 1;
          sp = VIDEO_SINGLETON::instance ()->sendPattern + ((curGroup - 1) % VIDEO_SINGLETON::instance ()->sendPatternGops) * VIDEO_SINGLETON::instance ()->patternSize;
          while (i < VIDEO_SINGLETON::instance ()->patternSize && !sp[i])
            {
              frameStep ++;
              i++;
            }
        }
      if (curGroup == 0)
        {
          if (VIDEO_SINGLETON::instance ()->firstSendPattern[curFrame])
            sendStatus = 0;
          else /*  (!VIDEO_SINGLETON::instance ()->firstVIDEO_SINGLETON::instance ()->SendVIDEO_SINGLETON::Instance ()->Pattern[curFrame]) */
            {
              int i = curFrame - 1;
              while (i > 0 && !VIDEO_SINGLETON::instance ()->firstSendPattern[i])
                i--;
              if (i > VIDEO_SINGLETON::instance ()->preFrame)
                /* the frame (curGroup, i) hasn't been sent yet */
                {
                  sendStatus = 0;
                  curFrame = i;
                }
              else
                sendStatus = -1;
            }
        }
      else if (sp[curFrame]) /* curGroup > 0 */
	sendStatus = 0;
      else /*  (!sp[curFrame]) */
        {
          int i = curFrame - 1;
          while (i > 0 && !sp[i])
            i--;
          if (curGroup == VIDEO_SINGLETON::instance ()->preGroup && i > VIDEO_SINGLETON::instance ()->preFrame)
            /* the frame (curGroup, i) hasn't been sent yet */
            {
              sendStatus = 0;
              curFrame = i;
            }
          else
            sendStatus = -1;
        }
      if (!sendStatus)
        {
          // Send the current video frame, calls send_to_network which
          // fragments and sends via blocking write .
          sendStatus = Video_Server::SendPacket(VIDEO_SINGLETON::instance ()->preHeader != curHeader,
                                  curGroup, curFrame,
                                  (VIDEO_SINGLETON::instance ()->currentUPF + VIDEO_SINGLETON::instance ()->addedUPF) * frameStep);
          if (!sendStatus)
            {
              VIDEO_SINGLETON::instance ()->preHeader = curHeader;
              VIDEO_SINGLETON::instance ()->preGroup = curGroup;
              VIDEO_SINGLETON::instance ()->preFrame = curFrame;
#ifdef STAT
              if (Video_Server::para.collectStat)
                {
                  int f = VIDEO_SINGLETON::instance ()->gopTable[curGroup].previousFrames + curFrame;
                  VIDEO_SINGLETON::instance ()->framesSent[f>>3] |= (1 << (f % 8));
                }
#endif
            }
        }
    }
  return 0;
}


// Video_Data_Handler methods

Video_Data_Handler::Video_Data_Handler (int video_data_fd)
  :data_handle_ (video_data_fd)
{
}

ACE_HANDLE
Video_Data_Handler::get_handle (void) const
{
  return this->data_handle_ ;
}

int
Video_Data_Handler::handle_input (ACE_HANDLE handle)
{
  GetFeedBack ();
  play_send (); // simulating the for loop in vs.cpp
  return 0;
}  

// Video_Control_Handler methods

Video_Control_Handler::Video_Control_Handler (int control_fd)
  :control_handle_ (control_fd)
{
}

ACE_HANDLE
Video_Control_Handler::get_handle (void) const
{
  return this->control_handle_ ;
}

int
Video_Control_Handler::handle_input (ACE_HANDLE handle)
{
  unsigned char tmp;
  int result;

  result = Video_Server::CmdRead((char *)&tmp, 1);
  if (result != 0)
    return result;
        
  if (tmp == CmdCLOSE) {
    exit(0);
  }
  else if (tmp == CmdSTOP) {
    VIDEO_SINGLETON::instance ()->cmd = tmp;
    /*
      fprintf(stderr, "VS: VIDEO_SINGLETON::Instance ()->CmdSTOP. . .\n");
      */
    result = Video_Server::CmdRead((char *)&VIDEO_SINGLETON::instance ()->cmdsn, sizeof(int));
    if (result != 0)
      return result;
#ifdef NeedByteOrderConversion
    VIDEO_SINGLETON::instance ()->cmdsn = ntohl(VIDEO_SINGLETON::instance ()->cmdsn);
#endif
    Video_Timer_Global::StopTimer();

    // End the event loop
    ACE_Reactor::instance ()->end_event_loop ();
  }
  else if (tmp == CmdSPEED)
    {
      SPEEDpara para;
      /*
	fprintf(stderr, "VS: VIDEO_SINGLETON::Instance ()->CmdSPEED. . .\n");
	*/
      result = Video_Server::CmdRead((char *)&para, sizeof(para));
      if (result != 0)
        return result;
#ifdef NeedByteOrderConversion
      para.sn = ntohl(para.sn);
      para.usecPerFrame = ntohl(para.usecPerFrame);
      para.framesPerSecond = ntohl(para.framesPerSecond);
      para.sendPatternGops = ntohl(para.sendPatternGops);
      para.frameRateLimit1000 = ntohl(para.frameRateLimit1000);
#endif
      VIDEO_SINGLETON::instance ()->frameRateLimit = para.frameRateLimit1000 / 1000.0;
      VIDEO_SINGLETON::instance ()->sendPatternGops = para.sendPatternGops;
      VIDEO_SINGLETON::instance ()->currentUPF = para.usecPerFrame;
      VIDEO_SINGLETON::instance ()->addedUPF = 0;
      memcpy(VIDEO_SINGLETON::instance ()->sendPattern, para.sendPattern, PATTERN_SIZE);
      Video_Timer_Global::TimerSpeed ();
    }
  else
    {
      fprintf(stderr, "VS error: VIDEO_SINGLETON::instance ()->cmd=%d while expect STOP/SPEED.\n", tmp);
      VIDEO_SINGLETON::instance ()->normalExit = 0;
      exit(1);
    }
  play_send ();// simulating the for loop in vs.cpp
}

// Video_Server methods

Video_Server::Video_Server (int ctr_fd,
                            int data_fd,
                            int rttag,
                            int max_pkt_size)
  :reactor_ (ACE_Reactor::instance ()),
   data_handler_ (new Video_Data_Handler (data_fd)),
   control_handler_ (new Video_Control_Handler (ctr_fd))
{
  int result;

  VIDEO_SINGLETON::instance ()->serviceSocket = ctr_fd;
  VIDEO_SINGLETON::instance ()->videoSocket = data_fd;
  VIDEO_SINGLETON::instance ()->conn_tag = max_pkt_size;
  
  if (max_pkt_size > 0) VIDEO_SINGLETON::instance ()->msgsize = max_pkt_size;
  else if (max_pkt_size < 0) VIDEO_SINGLETON::instance ()->msgsize = - max_pkt_size;
  else VIDEO_SINGLETON::instance ()->msgsize = 1024 * 1024;
  /*
    SFprintf(stderr, "VS VIDEO_SINGLETON::instance ()->msgsize = %d\n", VIDEO_SINGLETON::instance ()->msgsize);
  */
  VIDEO_SINGLETON::instance ()->msgsize -= sizeof(VideoMessage);
  
  VIDEO_SINGLETON::instance ()->start_time = time(NULL);

  atexit(on_exit_routine);

  VIDEO_SINGLETON::instance ()->lastRef[0] = VIDEO_SINGLETON::instance ()->lastRef[1] = -1;
  VIDEO_SINGLETON::instance ()->lastRefPtr = 0;

  INITvideo();

  if (rttag) {
    if (SetRTpriority("VS", 0) == -1) rttag = 0;
  }
}

int
Video_Server::run (void)
{
  int result;

  for (;;)
    {
    
      fprintf(stderr, "VS: waiting for a new command...\n");
    
      VIDEO_SINGLETON::instance ()->precmd = VIDEO_SINGLETON::instance ()->cmd;
      result = Video_Server::CmdRead((char *)&VIDEO_SINGLETON::instance ()->cmd, 1);
      if (result != 0)
        {
          cerr << result;
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%P|%t) VideoServer "),
                            result);
        }
      fprintf(stderr, "VS got VIDEO_SINGLETON::instance ()->cmd %d\n", VIDEO_SINGLETON::instance ()->cmd);
    
      switch (VIDEO_SINGLETON::instance ()->cmd)
        {
        case CmdPOSITION:
        case CmdPOSITIONrelease:
          result = this->position ();
          if (result != 0)
            return result;
          break;
        case CmdSTEP:
          result = this->step_video ();
          if (result != 0)
            return result;
          break;
        case CmdFF:
          this->fast_forward ();
          break;
        case CmdFB:
          this->fast_backward ();
          break;
        case CmdPLAY:
          result = this-> play ();
          if (result != 0)
            return result;
          break;
        case CmdCLOSE:
          /*
            fprintf(stderr, "a session closed.\n");
            VIDEO_SINGLETON::instance ()->normalExit =1;
            */
          //      exit(0);
          return 0;
          break;
        case CmdSTATstream:
          this->stat_stream();
          break;
        case CmdSTATsent:
          this->stat_sent();
          break;
        default:
          fprintf(stderr,
                  "VS error: video channel command %d not known.\n", VIDEO_SINGLETON::instance ()->cmd);
          VIDEO_SINGLETON::instance ()->normalExit = 0;
          return -1;
          break;
        }
    }
}

int
Video_Server::play (void)
{
  int result;

  fprintf(stderr, "PLAY . . .\n");
  
  result = Video_Server::CmdRead((char *)&para, sizeof(para));
  if (result != 0)
    return result;
#ifdef NeedByteOrderConversion
  para.sn = ntohl(para.sn);
  para.VIDEO_SINGLETON::instance ()->nextFrame = ntohl(para.VIDEO_SINGLETON::instance ()->nextFrame);
  para.usecPerFrame = ntohl(para.usecPerFrame);
  para.framesPerSecond = ntohl(para.framesPerSecond);
  para.VIDEO_SINGLETON::instance ()->frameRateLimit1000 = ntohl(para.VIDEO_SINGLETON::instance ()->frameRateLimit1000);
  para.collectStat = ntohl(para.collectStat);
  para.VIDEO_SINGLETON::instance ()->sendVIDEO_SINGLETON::Instance ()->PatternGops = ntohl(para.VIDEO_SINGLETON::instance ()->sendVIDEO_SINGLETON::Instance ()->PatternGops);
  para.VIDEO_SINGLETON::instance ()->VStimeAdvance = ntohl(para.VIDEO_SINGLETON::instance ()->VStimeAdvance);
#endif

  VIDEO_SINGLETON::instance ()->frameRateLimit = para.frameRateLimit1000 / 1000.0;
  VIDEO_SINGLETON::instance ()->cmdsn = para.sn;
  VIDEO_SINGLETON::instance ()->currentUPF = para.usecPerFrame;
  VIDEO_SINGLETON::instance ()->VStimeAdvance = para.VStimeAdvance;

  {
    int ts = htonl(get_usec());
    Video_Server::CmdWrite((char *)&ts, sizeof(int));
  }
  
  if (VIDEO_SINGLETON::instance ()->live_source || VIDEO_SINGLETON::instance ()->video_format != VIDEO_MPEG1) {
    if (VIDEO_SINGLETON::instance ()->live_source) 
      PLAYliveVideo (&para);
    return 0;
  }
  
  
  fprintf(stderr, "VIDEO_SINGLETON::instance ()->VStimeAdvance from client: %d\n", VIDEO_SINGLETON::instance ()->VStimeAdvance);
  
  VIDEO_SINGLETON::instance ()->sendPatternGops = para.sendPatternGops;
  ComputeFirstSendPattern(VIDEO_SINGLETON::instance ()->frameRateLimit);
#ifdef STAT
  if (para.collectStat)
    memset(VIDEO_SINGLETON::instance ()->framesSent, 0, (VIDEO_SINGLETON::instance ()->numF + 7)>>3);
#endif
  CheckFrameRange(para.nextFrame);
  Video_Timer_Global::timerFrame = para.nextFrame;
  Video_Timer_Global::timerGroup = FrameToGroup(&Video_Timer_Global::timerFrame);
  Video_Timer_Global::timerHeader = VIDEO_SINGLETON::instance ()->gopTable[Video_Timer_Global::timerGroup].systemHeader;
  memcpy(VIDEO_SINGLETON::instance ()->sendPattern, para.sendPattern, PATTERN_SIZE);
  result = SendReferences(Video_Timer_Global::timerGroup, Video_Timer_Global::timerFrame);
  if (result < 0)
    return result;
  Video_Timer_Global::StartTimer ();

  // Wait for a command on serviceSocket or Feedback on videoSocket (UDP)

    // Register the event handlers with the default ACE_REACTOR.

  this->reactor_->register_handler (this->data_handler_, 
                                    ACE_Event_Handler::READ_MASK);

  this->reactor_->register_handler (this->control_handler_,
                                    ACE_Event_Handler::READ_MASK);

  fprintf (stderr, "VS Going into the for loop\n");

  result = play_send ();
  this->reactor_->run_event_loop ();
  return 0;
}

int
Video_Server::SendPacket (int shtag,int gop,int frame,int timeToUse)
/* frame maybe out of range (PLAY, STEP), in this case, END_SEQ is sent
   to force display of last frame in VD */
{
  char * buf = ((char *) VIDEO_SINGLETON::instance ()->packet) + sizeof(VideoPacket);
  int f = VIDEO_SINGLETON::instance ()->gopTable[gop].previousFrames + frame;
  int sh = VIDEO_SINGLETON::instance ()->gopTable[gop].systemHeader;
  /*
  SFprintf(stderr, "VS to send VIDEO_SINGLETON::instance ()->packet gop-%d, frame-%d.\n", gop, frame);
  */

  VIDEO_SINGLETON::instance ()->packet->currentUPF = ntohl(VIDEO_SINGLETON::instance ()->currentUPF);

  if (frame >= VIDEO_SINGLETON::instance ()->gopTable[gop].totalFrames)
  {
    VIDEO_SINGLETON::instance ()->packet->cmd = htonl(VIDEO_SINGLETON::instance ()->cmd);
    VIDEO_SINGLETON::instance ()->packet->cmdsn = htonl(VIDEO_SINGLETON::instance ()->cmdsn);
    VIDEO_SINGLETON::instance ()->packet->sh = htonl(sh);
    VIDEO_SINGLETON::instance ()->packet->gop = htonl(gop);
    VIDEO_SINGLETON::instance ()->packet->frame = htonl(VIDEO_SINGLETON::instance ()->numF);
    VIDEO_SINGLETON::instance ()->packet->display = htonl(VIDEO_SINGLETON::instance ()->numF-1);
    VIDEO_SINGLETON::instance ()->packet->future = htonl((unsigned)-1);
    VIDEO_SINGLETON::instance ()->packet->past = htonl((unsigned)-1);
    VIDEO_SINGLETON::instance ()->packet->dataBytes = htonl(4);
    *(int*)((char*)VIDEO_SINGLETON::instance ()->packet + sizeof(*VIDEO_SINGLETON::instance ()->packet)) = htonl(SEQ_END_CODE);

    return send_to_network(timeToUse);
  }

  if (frame)
    shtag = 0;
  else if (VIDEO_SINGLETON::instance ()->needHeader)
  {
    shtag = 1;
    VIDEO_SINGLETON::instance ()->needHeader = 0;
  }
  
  VIDEO_SINGLETON::instance ()->packet->cmd = htonl(VIDEO_SINGLETON::instance ()->cmd);
  VIDEO_SINGLETON::instance ()->packet->cmdsn = htonl(VIDEO_SINGLETON::instance ()->cmdsn);
  VIDEO_SINGLETON::instance ()->packet->sh = htonl(sh);
  VIDEO_SINGLETON::instance ()->packet->gop = htonl(gop);
  VIDEO_SINGLETON::instance ()->packet->frame = htonl(f);
  if (VIDEO_SINGLETON::instance ()->frameTable[f].type == 'B')
  {
    int pre1 = -1, pre2 = -1, i = f;
    while (i>0)
      if (VIDEO_SINGLETON::instance ()->frameTable[--i].type != 'B')
      {
	pre1 = i;
	break;
      }
    while (i>0)
      if (VIDEO_SINGLETON::instance ()->frameTable[--i].type != 'B')
      {
	pre2 = i;
	break;
      }
    if (pre2 ==  -1)
    {
      /*
      fprintf(stderr,
	      "frame %d-%d (%d) is a B without past ref, no to be sent.\n",
	      gop, frame, f);
       */
      return -1;
    }
    if (pre1 != VIDEO_SINGLETON::instance ()->lastRef[VIDEO_SINGLETON::instance ()->lastRefPtr] ||
	pre2 != VIDEO_SINGLETON::instance ()->lastRef[1 - VIDEO_SINGLETON::instance ()->lastRefPtr])
    {
      /*
      fprintf(stderr,
	      "send of B frame %d gaveup for past %d/future %d ref not sent.\n",
	      f, pre2, pre1);
       */
      return -1;
    }
    VIDEO_SINGLETON::instance ()->packet->display = htonl(f);
    VIDEO_SINGLETON::instance ()->packet->future = htonl(pre1);
    VIDEO_SINGLETON::instance ()->packet->past = htonl(pre2);
  }
  else
  {
    int next = f;
    int pre = f;

    while (next < VIDEO_SINGLETON::instance ()->numF && VIDEO_SINGLETON::instance ()->frameTable[++next].type == 'B');
    while (pre > 0 && VIDEO_SINGLETON::instance ()->frameTable[--pre].type == 'B');
    if (VIDEO_SINGLETON::instance ()->frameTable[f].type == 'P' && pre != VIDEO_SINGLETON::instance ()->lastRef[VIDEO_SINGLETON::instance ()->lastRefPtr])
    {
      /*
      fprintf(stderr,
	      "send of P frame %d gaveup for past ref %d not sent.\n",
	      f, pre);
      fprintf(stderr, "ref0=%d, ref1=%d, ptr=%d.\n",
	      VIDEO_SINGLETON::instance ()->lastRef[0], VIDEO_SINGLETON::instance ()->lastRef[1], VIDEO_SINGLETON::instance ()->lastRefPtr);
       */
      return -1;
    }
    VIDEO_SINGLETON::instance ()->packet->display = htonl(next);
    VIDEO_SINGLETON::instance ()->packet->future = htonl((unsigned)-1);
    VIDEO_SINGLETON::instance ()->packet->past = htonl(VIDEO_SINGLETON::instance ()->frameTable[f].type == 'P' ? pre : (unsigned)-1);
  }
  {
    char * ptr = buf;
    int size = 0, offset = 0, i;
    if (shtag)   /* send system header */
    {
      size = VIDEO_SINGLETON::instance ()->systemHeader[sh].size;
      FileRead(VIDEO_SINGLETON::instance ()->systemHeader[sh].offset, ptr, size);
      ptr += size;
    }
    if (!frame)   /* send gop header */
    {
      size = VIDEO_SINGLETON::instance ()->gopTable[gop].headerSize;
      FileRead(VIDEO_SINGLETON::instance ()->gopTable[gop].offset, ptr, size);
      ptr += size;
    }
    size = VIDEO_SINGLETON::instance ()->frameTable[f].size;
    for (i=VIDEO_SINGLETON::instance ()->gopTable[gop].previousFrames; i<f; i++)
      offset += VIDEO_SINGLETON::instance ()->frameTable[i].size;
    FileRead((VIDEO_SINGLETON::instance ()->gopTable[gop].firstIoffset + offset), ptr, size);
    ptr += size;
    VIDEO_SINGLETON::instance ()->packet->dataBytes = htonl(ptr - buf);
  }

  {
    int sent = send_to_network(timeToUse);
    if (!sent)
    {
      /*
      fprintf(stderr, "%c%d\n", VIDEO_SINGLETON::instance ()->frameTable[f].type, f);
      fprintf(stderr, "%c frame %d sent.\n", VIDEO_SINGLETON::instance ()->frameTable[f].type, f);
      */
      if (VIDEO_SINGLETON::instance ()->frameTable[f].type != 'B')
      {
	VIDEO_SINGLETON::instance ()->lastRefPtr = 1 - VIDEO_SINGLETON::instance ()->lastRefPtr;
	VIDEO_SINGLETON::instance ()->lastRef[VIDEO_SINGLETON::instance ()->lastRefPtr] = f;
      }
    }
    return sent;
  }
}

int
Video_Server::CmdRead (char *buf, int psize)
{
  int res = wait_read_bytes (VIDEO_SINGLETON::instance ()->serviceSocket, 
                             buf, 
                             psize);
  if (res == 0) return(1);
  if (res == -1) {
    fprintf(stderr, "VS error on read VIDEO_SINGLETON::instance ()->cmdSocket, size %d", psize);
    perror("");
    return(-1);
  }
  return 0;
}

void
Video_Server::CmdWrite(char *buf, int size)
{
  int res = wait_write_bytes(VIDEO_SINGLETON::instance ()->serviceSocket, buf, size);
  if (res == -1) {
    if (errno != EPIPE) perror("VS writes to VIDEO_SINGLETON::instance ()->serviceSocket");
    exit(errno != EPIPE);
  }
}

void
Video_Server::on_exit_routine(void)
{
  struct sockaddr_in peeraddr_in;
  int size = sizeof(peeraddr_in);
  /*
  if (!VIDEO_SINGLETON::instance ()->normalExit) {
    fprintf(stderr, "VS exitting abnormally, dump core...\n");
    kill(getpid(), SIGSEGV);
    usleep(2000000);
  }
  */
  /*
  fprintf(stderr, "A VS session terminated.\n");
  */
  if (getpeername(VIDEO_SINGLETON::instance ()->serviceSocket,
		  (struct sockaddr *)&peeraddr_in, &size) == 0 &&
      peeraddr_in.sin_family == AF_INET) {
    if (strncmp(inet_ntoa(peeraddr_in.sin_addr), "129.95.50", 9)) {
      struct hostent *hp;
      time_t val = time(NULL);
      char * buf = ctime(&VIDEO_SINGLETON::instance ()->start_time);
      
      hp = gethostbyaddr((char *)&(peeraddr_in.sin_addr), 4, AF_INET);
      buf[strlen(buf)-1] = 0;
      printf("%s: %s %3dm%02ds %dP %s\n",
	     buf,
	     hp == NULL ? inet_ntoa(peeraddr_in.sin_addr) : hp->h_name,
	     (val - VIDEO_SINGLETON::instance ()->start_time) / 60, (val - VIDEO_SINGLETON::instance ()->start_time) % 60,
	     VIDEO_SINGLETON::instance ()->pkts_sent, VIDEO_SINGLETON::instance ()->videoFile);
    }
  }
  ComCloseConn(VIDEO_SINGLETON::instance ()->serviceSocket);
  ComCloseConn(VIDEO_SINGLETON::instance ()->videoSocket);
}

int
Video_Server::position (void)
{
  int result;
  POSITIONpara para;
  /*
  fprintf(stderr, "POSITION . . .\n");
  */
  result = CmdRead((char *)&para, sizeof(para));
  if (result != 0)
    return result;

  if (VIDEO_SINGLETON::instance ()->live_source) return 0;
  
#ifdef NeedByteOrderConversion
  para.VIDEO_SINGLETON::instance ()->nextGroup = ntohl(para.VIDEO_SINGLETON::instance ()->nextGroup);
  para.sn = ntohl(para.sn);
#endif
  
  CheckGroupRange(para.nextGroup);
  VIDEO_SINGLETON::instance ()->cmdsn = para.sn;
  result = SendPacket(VIDEO_SINGLETON::instance ()->numS>1 || para.nextGroup == 0, para.nextGroup, 0, 0);
  return result;
}

int
Video_Server::step_video()
{
  int group;
  STEPpara para;
  int tag = 0;
  int result;

  result = CmdRead((char *)&para, sizeof(para));
  if (result != 0)
    return result;
#ifdef NeedByteOrderConversion
  para.sn = ntohl(para.sn);
  para.VIDEO_SINGLETON::instance ()->nextFrame = ntohl(para.VIDEO_SINGLETON::instance ()->nextFrame);
#endif

  VIDEO_SINGLETON::instance ()->cmdsn = para.sn;

  if (!VIDEO_SINGLETON::instance ()->live_source) {
    if (para.nextFrame >= VIDEO_SINGLETON::instance ()->numF)  /* send SEQ_END */
    {
      tag = 1;
      para.nextFrame --;
    }
    /*
    fprintf(stderr, "STEP . . .frame-%d\n", para.VIDEO_SINGLETON::instance ()->nextFrame);
    */
    CheckFrameRange(para.nextFrame);
    group = FrameToGroup(&para.nextFrame);
    if (VIDEO_SINGLETON::instance ()->precmd != CmdSTEP && !tag ) {
      result = SendReferences(group, para.nextFrame);
      if (result < 0 )
        return result;
    }
  }
  if (VIDEO_SINGLETON::instance ()->live_source) StartPlayLiveVideo();
  
  if (VIDEO_SINGLETON::instance ()->live_source) {
    SendPicture(&para.nextFrame);
  }
  else if (VIDEO_SINGLETON::instance ()->video_format == VIDEO_MPEG1) {
    SendPacket(VIDEO_SINGLETON::instance ()->numS>1, group, tag ? VIDEO_SINGLETON::instance ()->numF : para.nextFrame, 0);
  }
  else {
    fprintf(stderr, "VS: wierd1\n");
  }
  
  if (VIDEO_SINGLETON::instance ()->live_source) StopPlayLiveVideo();
  return 0;
}

int
Video_Server::fast_video_play (void)
{
  int result;
  FFpara para;
  int preGroup = -1;
  int preHeader = -1;
  int nfds = (VIDEO_SINGLETON::instance ()->serviceSocket > VIDEO_SINGLETON::instance ()->videoSocket ? VIDEO_SINGLETON::instance ()->serviceSocket : VIDEO_SINGLETON::instance ()->videoSocket) + 1;
  
  result = CmdRead((char *)&para, sizeof(para));
  if (result != 0)
    return result;
#ifdef NeedByteOrderConversion
  para.sn = ntohl(para.sn);
  para.VIDEO_SINGLETON::instance ()->nextGroup = ntohl(para.VIDEO_SINGLETON::instance ()->nextGroup);
  para.usecPerFrame = ntohl(para.usecPerFrame);
  para.framesPerSecond = ntohl(para.framesPerSecond);
  para.VIDEO_SINGLETON::instance ()->VStimeAdvance = ntohl(para.VIDEO_SINGLETON::instance ()->VStimeAdvance);
#endif

  if (VIDEO_SINGLETON::instance ()->live_source) return 0;
  
  VIDEO_SINGLETON::instance ()->VStimeAdvance = para.VStimeAdvance;
  /*
  fprintf(stderr, "VIDEO_SINGLETON::instance ()->VStimeAdvance from client: %d\n", VIDEO_SINGLETON::instance ()->VStimeAdvance);
  */
  CheckGroupRange(para.nextGroup);
  VIDEO_SINGLETON::instance ()->cmdsn = para.sn;
  Video_Timer_Global::timerGroup = para.nextGroup;
  Video_Timer_Global::timerFrame = 0;
  Video_Timer_Global::timerHeader = VIDEO_SINGLETON::instance ()->gopTable[Video_Timer_Global::timerGroup].systemHeader;
  VIDEO_SINGLETON::instance ()->currentUPF = para.usecPerFrame;
  Video_Timer_Global::StartTimer();
  
  for (;;)
  {
    struct fd_set read_mask;
/*
    fprintf(stderr, "VS: FF/FB - a loop begines. . .\n");
*/
    if (preGroup != Video_Timer_Global::timerGroup)
    {
      SendPacket(preHeader != Video_Timer_Global::timerHeader, Video_Timer_Global::timerGroup, 0,
		 para.usecPerFrame * VIDEO_SINGLETON::instance ()->patternSize >> 2);
      preHeader = Video_Timer_Global::timerHeader;
      preGroup = Video_Timer_Global::timerGroup;
    }

    FD_ZERO(&read_mask);
    FD_SET(VIDEO_SINGLETON::instance ()->serviceSocket, &read_mask);
    FD_SET(VIDEO_SINGLETON::instance ()->videoSocket, &read_mask);
#ifdef _HPUX_SOURCE
    if (select(nfds, (int *)&read_mask, NULL, NULL, NULL) == -1)
#else
    if (select(nfds, &read_mask, NULL, NULL, NULL) == -1)
#endif
    {
      if (errno == EINTR)
        continue;
      perror("Error - VS select between service and video sockets");
      exit(1);
      
    }
    if (FD_ISSET(VIDEO_SINGLETON::instance ()->serviceSocket, &read_mask))   /* stop */
    {
      result = CmdRead((char *)&VIDEO_SINGLETON::instance ()->cmd, 1);
      if (result != 0)
        return result;
      if (VIDEO_SINGLETON::instance ()->cmd == CmdCLOSE) {
	exit(0);
      }
      else if (VIDEO_SINGLETON::instance ()->cmd != CmdSTOP) {
	fprintf(stderr, "VS error: VIDEO_SINGLETON::instance ()->cmd=%d while STOP is expected.\n", VIDEO_SINGLETON::instance ()->cmd);
	VIDEO_SINGLETON::instance ()->normalExit = 0;
	exit(1);
      }
      result = CmdRead((char *)&VIDEO_SINGLETON::instance ()->cmdsn, sizeof(int));
      if (result != 0 )
        return result;
#ifdef NeedByteOrderConversion
      VIDEO_SINGLETON::instance ()->cmdsn = ntohl(VIDEO_SINGLETON::instance ()->cmdsn);
#endif
      Video_Timer_Global::StopTimer();
      break;
    }
    if (FD_ISSET(VIDEO_SINGLETON::instance ()->videoSocket, &read_mask))  /* feedback, speed adjustment */
    {
      GetFeedBack();
    }
  }
  return 0;
}

int
Video_Server::fast_forward (void)
{
  return this->fast_video_play ();
}

int
Video_Server::fast_backward (void)
{
  return this->fast_video_play ();
}

int
Video_Server::stat_stream(void)
{
  int i, j = 0;
  for (i = 0; i < VIDEO_SINGLETON::instance ()->numF; i++)
  {
    short size = htons(VIDEO_SINGLETON::instance ()->frameTable[i].size);
    char type = VIDEO_SINGLETON::instance ()->frameTable[i].type;
    if (i == VIDEO_SINGLETON::instance ()->gopTable[j].previousFrames)
    {
      type = tolower(type);
      j ++;
    }
    CmdWrite((char *)&type, 1);
    CmdWrite((char *)&size, 2);
  }
  return 0;
}

int
Video_Server::stat_sent(void)
{
#ifdef STAT
  CmdWrite((char *)VIDEO_SINGLETON::instance ()->framesSent, (VIDEO_SINGLETON::instance ()->numF + 7) / 8);
#else
  int i;
  char zeroByte = 0;
  for (i = 0; i < (VIDEO_SINGLETON::instance ()->numF + 7) / 8; i++)
    CmdWrite((char *)&zeroByte, 1);
#endif
  return 0;
}
