/* -*- C++ -*- */
// @(#)nametest.h	1.1	10/18/96

#include "ace/Service_Object.h"

class Nametest : public ACE_Service_Object
{
public:
  virtual int init (int argc, char *argv[]);
  virtual int fini (void);
  virtual int info (char **, size_t) const;

  void listopt (void);
};

