/* $Id$ -*- C -*- */

/* ===================================================================== */
/*                                                                       */
/* = FILENAME                                                            */
/*    Stdio_Test.c                                                       */
/*                                                                       */
/* =  DESCRIPTION                                                        */
/*     Testing the platform for POSIX standard I/O. This is not meant    */
/*     to be an exhaustive test at this point but more a sanity check    */
/*     that PACE works (at least somewhat) as advertised.                */
/*     This program creates/opens a temporary file, writes to the file,  */
/*     reads from the file to make sure it's what was written, and       */
/*     then closes/deletes the file.                                     */
/*                                                                       */
/* = AUTHOR                                                              */
/*    Joe Hoffert <joeh@cs.wustl.edu>                                    */
/*                                                                       */
/* ===================================================================== */

#include "pace/stdio.h"
#include "pace/unistd.h"

const char * filename = "temp";
const char * mode = "w+";
const char * string1 = "line 1\n";
const char * success = "SUCCEEDED";
const char * failure = "***FAILED***";
const int SLEEPTIME = 20;

int
main (int argc, char **argv)
{
  /* Test creating/opening a file. */
  PACE_FILE *file;
  int retval;
  char* retval2;
  char buffer[256];

  file = pace_fopen (filename,
                     mode);
  if (file == 0)
    {
      printf("pace_fopen %s\n", failure);
      return -1;
    }

  printf("pace_fopen %s\n", success);

  /* Test writing to a file. */
  retval = pace_fputs (string1,
                       file);
  if (retval == EOF)
    {
      printf("pace_fputs %s\n", failure);
      return -1;
    }

  printf("pace_fputs %s\n", success);

  /* Test flushing a file. */
  retval = pace_fflush (file);
  if (retval != 0)
    {
      printf("pace_fflush %s\n", failure);
      return -1;
    }

  printf("pace_fflush %s\n", success);

  /* Test seeking in a file. */
  retval = pace_fseek (file,
                       0,
                       0);
  if (retval != 0)
    {
      printf("pace_fseek %s\n", failure);
      return -1;
    }

  printf("pace_fseek %s\n", success);

  /* Test reading from a file. */
  retval2 = pace_fgets (buffer,
                        sizeof(buffer),
                        file);
  if (retval2 == 0)
    {
      printf("pace_fgets %s\n", failure);
      return -1;
    }

  printf("pace_fgets %s\n", success);

  if (strcmp(buffer,
             string1) != 0)
    {
      printf("strcmp of pace_fgets %s\n", failure);
      return -1;
    }

  printf("strcmp of pace_fgets %s\n", success);

  /* Test closing a file. */
  retval = pace_fclose (file);
  if (retval != 0)
    {
      printf("pace_fclose %s\n", failure);
      return -1;
    }

  printf("pace_fclose %s\n", success);


  // use this to pause the program to test the size of the exe
  // Cntr-Alt-Del and then look at the task manager to
  // find the size
  pace_sleep (SLEEPTIME);

  PACE_UNUSED_ARG (argc);
  PACE_UNUSED_ARG (argv);
  return 0;
}
