
// $Id$

#ifndef BLOCK_H
#define BLOCK_H

#include "ace/Message_Block.h"

class Block : public ACE_Message_Block
{
public:
  Block (void)
  {
    ACE_DEBUG ((LM_DEBUG, "(%P|%t) Block ctor 0x%x\n", (void *) this));
  }

  Block (size_t size)
  : ACE_Message_Block (size)
  {
    ACE_DEBUG ((LM_DEBUG, "(%P|%t) Block ctor 0x%x\n", (void *) this));
  }

  virtual ~ Block (void)
  {
    ACE_DEBUG ((LM_DEBUG, "(%P|%t) Block dtor 0x%x\n", (void *) this));
  }
};

#endif
