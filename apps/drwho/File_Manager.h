/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    drwho
//
// = FILENAME
//    File_Manager.h
//
// = AUTHOR
//    Douglas C. Schmidt
//
// ============================================================================

#if !defined (_FILE_MANAGER_H)
#define _FILE_MANAGER_H

#include "global.h"
#include "ace/Singleton.h"
#include "ace/Mem_Map.h"

class File_Manager
{
  // = TITLE
  //   This class provides a file ADT for our friends info.
public:
  int open_file (const char *filename);
  int get_login_and_real_name (char *&login_name,
                               char *&real_name);

  File_Manager (void);
  // Constructor.

private:
  int number_of_friends;
  int max_key_length;

  char *buffer_ptr;
  char *current_ptr;
  int buffer_size;

  int open_friends_file (const char *filename);
  int open_passwd_file (void);

  ACE_Mem_Map mmap_;
};

// Make a Singleton.
typedef ACE_Singleton <File_Manager, ACE_Null_Mutex> FILE_MANAGER;

#endif /* _FILE_MANAGER_H */
