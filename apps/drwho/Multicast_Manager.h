/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    drwho
//
// = FILENAME
//    Multicast_Manager.h
//
// = AUTHOR
//    Douglas C. Schmidt
//
// ============================================================================

#if !defined (_MULTICAST_MANAGER_H)
#define _MULTICAST_MANAGER_H

#include "global.h"

struct Host_Elem 
{
  char *host_name;
  in_addr host_addr;
  int checked_off;
  Host_Elem *next;

  Host_Elem (char *h_name, Host_Elem *n);
};

class Multicast_Manager 
{
  // = TITLE
  //   This file handles all the operations upon host machines names
  //   and addresses.
public:
  static void add_host (const char *host_name);
  static void checkoff_host (in_addr host_addr);
  static int get_next_host_addr (in_addr &host_addr);
  static int outstanding_hosts_remain (void);
  static int get_next_non_responding_host (char *&host_name);
  static int insert_hosts_from_file (char *filename);
  static void insert_default_hosts (void);

private:
  static hostent *get_host_entry (const char *host);

  static int received_host_count;
  static char *host_names[];
  static Host_Elem *drwho_list;
  static Host_Elem *current_ptr;
};

#endif /* _MULTICAST_MANAGER_H */
