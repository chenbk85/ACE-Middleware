/**
 * @author Johnny Willemsen <jwillemsen@remedy.nl>
 *
 * $Id$
 *
 * Wrapper facade for NDDS.
 */

#ifndef CIAO_RTI_GROUPDATAQOSPOLICY_H
#define CIAO_RTI_GROUPDATAQOSPOLICY_H

// @todo here
inline void
operator<<= (::DDS::GroupDataQosPolicy &ddsqos, const ::DDS_GroupDataQosPolicy & qos)
{
//  ddsqos.value <<= qos.value;
}

inline void
operator<<= (::DDS_GroupDataQosPolicy &ddsqos, const ::DDS::GroupDataQosPolicy & qos)
{
//  ddsqos.value <<= qos.value;
}

inline void
operator>>= (const ::DDS_GroupDataQosPolicy &qos, ::DDS::GroupDataQosPolicy & ddsqos)
{
//  ddsqos.value <<= qos.value;
}

inline void
operator>>= (const ::DDS::GroupDataQosPolicy &qos, ::DDS_GroupDataQosPolicy & ddsqos)
{
//  ddsqos.value <<= qos.value;
}

#endif /* CIAO_RTI_GROUPDATAQOSPOLICY_H */
