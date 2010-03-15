/**
 * @author William R. Otte <wotte@dre.vanderbilt.edu>
 * @author Johnny Willemsen <jwillemsen@remedy.nl>
 *
 * $Id$
 *
 * Wrapper facade for NDDS.
 */

#ifndef DDS4CCM_REQUESTEDDEADLINEMISSEDSTATUS_H
#define DDS4CCM_REQUESTEDDEADLINEMISSEDSTATUS_H

#include "InstanceHandle_t.h"

#if (CIAO_DDS4CCM_OPENDDS==1)
typedef ::DDS::RequestedDeadlineMissedStatus DDS_RequestedDeadlineMissedStatus;
#endif

#if (CIAO_DDS4CCM_NDDS==1)
inline void
operator<<= (::DDS::RequestedDeadlineMissedStatus &ddsstatus, const ::DDS_RequestedDeadlineMissedStatus & status)
{
  ddsstatus.total_count = status.total_count;
  ddsstatus.total_count_change = status.total_count_change;
  ddsstatus.last_instance_handle <<= status.last_instance_handle;
}

inline void
operator<<= (::DDS_RequestedDeadlineMissedStatus &ddsstatus, const ::DDS::RequestedDeadlineMissedStatus & status)
{
  ddsstatus.total_count = status.total_count;
  ddsstatus.total_count_change = status.total_count_change;
  ddsstatus.last_instance_handle <<= status.last_instance_handle;
}

#endif

#endif /* DDS4CCM_REQUESTEDDEADLINEMISSEDSTATUS_H */
