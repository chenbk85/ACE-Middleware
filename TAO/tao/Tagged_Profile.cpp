// $Id$

#include "Tagged_Profile.h"
#include "ORB_Core.h"
#include "Acceptor_Registry.h"
#include "Transport_Acceptor.h"
#include "Thread_Lane_Resources.h"
#include "debug.h"
#include "target_specification.h"

#if !defined (__ACE_INLINE__)
# include "tao/Tagged_Profile.i"
#endif /* ! __ACE_INLINE__ */

ACE_RCSID (tao, 
           Tagged_Profile, 
           "$Id$")

CORBA::Boolean
TAO_Tagged_Profile::extract_object_key (IOP::TaggedProfile &profile)
{
  // Get our Acceptor registry
  TAO_Acceptor_Registry &acceptor_registry =
    this->orb_core_->lane_resources ().acceptor_registry ();

  // Get the right acceptor for the tag in the TaggedProfile
  TAO_Acceptor *acceptor =
    acceptor_registry.get_acceptor (profile.tag);

  if (acceptor)
    {
      // Get the object key
      int retval =
        acceptor->object_key (profile,
                              this->object_key_);
      if (retval == -1)
        {
          return 0;
        }
    }
  else
    {
      if (TAO_debug_level)
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("(%P|%t)TAO_Tagged_Profile \n")));
        }

      return 0;
    }

  return 1;
}

CORBA::Boolean
TAO_Tagged_Profile::unmarshall_target_address (TAO_InputCDR &cdr)
{
  CORBA::Boolean hdr_status = cdr.read_short (this->discriminator_);

  if (hdr_status)
    {
      switch (this->discriminator_)
        {
        case TAO_Target_Specification::Key_Addr:
          hdr_status = this->unmarshall_object_key_i (cdr);
          break;

        case TAO_Target_Specification::Profile_Addr:
          hdr_status = this->unmarshall_iop_profile_i (cdr);
          break;

        case TAO_Target_Specification::Reference_Addr:
          hdr_status = this->unmarshall_ref_addr_i (cdr);
          break;

        default:
          hdr_status = 0;
          break;
        }
    }

  return hdr_status;
}

CORBA::Boolean
TAO_Tagged_Profile::unmarshall_object_key (
    TAO_InputCDR &input)
{
  this->discriminator_ = TAO_Target_Specification::Key_Addr;

  return this->unmarshall_object_key_i (input);
}


CORBA::Boolean
TAO_Tagged_Profile::unmarshall_object_key_i (
    TAO_InputCDR &input)
{
  CORBA::Boolean hdr_status =
    (CORBA::Boolean) input.good_bit ();

  CORBA::Long key_length = 0;
  hdr_status = hdr_status && input.read_long (key_length);

  if (hdr_status)
    {
      this->object_key_.replace (key_length,
                                 key_length,
                                 (CORBA::Octet*)input.rd_ptr (),
                                 0);
      input.skip_bytes (key_length);

      this->object_key_extracted_ = 1;
    }

  return hdr_status;
}


CORBA::Boolean
TAO_Tagged_Profile::unmarshall_iop_profile_i (
    TAO_InputCDR &input)
{
  CORBA::Boolean hdr_status =
    (CORBA::Boolean) input.good_bit ();

  // Extract into the IOP::Tagged profile.
  hdr_status &= input >> this->profile_;

  return hdr_status;
}

CORBA::Boolean
TAO_Tagged_Profile::unmarshall_ref_addr_i (
    TAO_InputCDR &input)
{
  CORBA::Boolean hdr_status =
    (CORBA::Boolean) input.good_bit ();

  /*
   * The GIOP::IORAddressingInfo is defined as follows
   *   struct IORAddressingInfo
   *     {
   *       unsigned long selected_profile_index;
   *       IOP::IOR ior;
   *     };
   *
   * and the IOP::IOR is defined to be
   *   struct IOR
   *      {
   *        string type_id;
   *        sequence<TaggedProfile>   profiles;
   *      };
   */

  // First read the profile index
  CORBA::ULong prof_index =  0;

  hdr_status =
    hdr_status && input.read_ulong (prof_index);

  // Set the value in TAO_Tagged_Profile
  if (hdr_status)
    {
      this->profile_index_ = prof_index;
    }

  // Get the length of the type_id
  CORBA::Long id_length = 0;
  hdr_status = hdr_status && input.read_long (id_length);

  if (hdr_status)
    {
      // Set the type_id
      this->type_id_.set (input.rd_ptr (),
                          0);

      input.skip_bytes (id_length);
    }

  // Unmarshall the sequnce of TaggedProfiles
  IOP::IOR::_profiles_seq ior_profiles;

  hdr_status &= input >> ior_profiles;

  // Get the right TaggedProfile from the <ior_profiles>
  if (hdr_status)
    {
      this->profile_ = ior_profiles [prof_index];
    }

  return hdr_status;
}
