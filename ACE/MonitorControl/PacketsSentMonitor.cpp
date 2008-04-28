// $Id$

#include "MonitorControl/PacketsSentMonitor.h"

#if defined (ACE_HAS_MONITOR_FRAMEWORK) && (ACE_HAS_MONITOR_FRAMEWORK == 1)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace MonitorControl
  {
    const char* PacketsSentMonitor::default_name_ =
      "OS/Network/PacketsSent";

    PacketsSentMonitor::PacketsSentMonitor (const char* name)
      : Monitor_Base (name)
#if defined (ACE_WIN32)
      , WindowsMultiInstanceMonitor (
          "\\Network Interface(*)\\Packets Sent/sec")
#elif defined (linux)
        , LinuxNetworkInterfaceMonitor (
            " %*[^:]: %*u %*u %*u %*u %*u %*u %*u %*u %*u %lu")
            /// Scan format for /proc/net/dev
#endif
    {}

    void
    PacketsSentMonitor::update (void)
    {
#if defined (ACE_WIN32)
      this->win_update ();

      /// Stores value and timestamp with thread-safety.
      this->receive (this->value_.doubleValue);
#elif defined (linux)
      this->lin_update ();

      /// Stores value and timestamp with thread-safety.
      this->receive (static_cast<double> (this->value_));
#endif
    }

    const char*
    PacketsSentMonitor::default_name (void)
    {
      return PacketsSentMonitor::default_name_;
    }
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */

