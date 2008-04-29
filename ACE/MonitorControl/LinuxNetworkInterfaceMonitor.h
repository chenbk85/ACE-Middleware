// -*- C++ -*-

//=============================================================================
/**
 * @file LinuxNetworkInterfaceMonitor.h
 *
 * $Id$
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef LINUXNETWORKINTERFACEMONITOR_H
#define LINUXNETWORKINTERFACEMONITOR_H

#include /**/ "ace/pre.h"

#include "ace/SString.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "MonitorControl/MonitorControl_export.h"

#if defined (linux)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace MonitorControl
  {
    /**
     * @class LinuxNetworkInterfaceMonitor
     *
     * @brief Mixin class for network interface monitors compiled on
     *        Linux machines.
     */
    class MONITORCONTROL_Export LinuxNetworkInterfaceMonitor
    {
    protected:
      /// The Linux system file /proc/net/dev stores a wealth of
      /// network information about the system. To get the specific
      /// value we want to monitor, we just vary the scan format string.
      LinuxNetworkInterfaceMonitor (const char *scan_format);

      void lin_update (void);

    protected:
      ACE_UINT64 value_;

    private:
      static const unsigned long MAX_INTERFACES = 10UL;
      ACE_UINT64 value_array_[MAX_INTERFACES];
      ACE_UINT64 start_;
      ACE_CString scan_format_;
    };
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* defined (linux) */

#include /**/ "ace/post.h"

#endif // LINUXNETWORKINTERFACEMONITOR_H
