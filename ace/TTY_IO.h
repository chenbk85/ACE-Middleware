/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    ace
//
// = FILENAME
//    TTY_IO.h
//
// = DESCRIPTION
//
// = AUTHOR
//    Douglas C. Schmidt <schmidt@uci.edu>
//
// ============================================================================

#ifndef ACE_TTY_IO_H
#define ACE_TTY_IO_H

#include "ace/OS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/DEV_Addr.h"
#include "ace/DEV_Connector.h"
#include "ace/DEV_IO.h"

class ACE_Export ACE_TTY_IO : public ACE_DEV_IO
{
  // = TITLE
  //     Class definitions for platform specific TTY features.
  //
  // = DESCRIPTION
  //     This class represents an example interface for a specific
  //     device (a serial line) It extends the capability of the
  //     underlying DEV_IO class by adding a control method that takes
  //     a special structure (Serial_Params) as argument to allow a
  //     comfortable user interface (away from that annoying termios
  //     structure, which is very specific to UNIX).
public:
  enum Control_Mode
  {
    SETPARAMS,  // Set control parameters.
    GETPARAMS   // Get control parameters.
  };

  struct Serial_Params
  {
        // Common params
    int baudrate;
    int parityenb;
    const char *paritymode;
    int databits;
    int stopbits;
    int readtimeoutmsec;
    int ctsenb;  // CTS & RTS are the same under unix
    int rtsenb;  // enable & set rts mode (win32)
    int xinenb;  // enable xon/xoff  reception
    int xoutenb;  // enable xon/xoff transmission

    // Posix - unix variant
    int modem;
    int rcvenb;

    //Win32
    int xonlim;  // min bytes in input buffer before xon
    int xofflim; // max bytes in input buffer before xoff
  };

  int control (Control_Mode cmd,
               Serial_Params *arg) const;
  // Interface for reading/writing serial device parameters.

#if defined (ACE_NEEDS_DEV_IO_CONVERSION)
  operator ACE_DEV_IO &();
  // This is necessary to pass ACE_TTY_IO as parameter to DEV_Connector.
#endif /* ACE_NEEDS_DEV_IO_CONVERSION */
};

#endif /* ACE_TTY_IO_H */
