/* $Id$

 * ============================================================================
 *
 * = LIBRARY
 *    pace
 *
 * = FILENAME
 *    pace/posix/fnctl.h
 *
 * = AUTHOR
 *    Luther Baker
 *
 * ============================================================================ */

#ifndef PACE_FCNTL_H
#define PACE_FCNTL_H

#include "pace/sys/types.h"
#include "pace/unistd.h"
#include "pace/sys/stat.h"
#include <fcntl.h>

#if defined (PACE_HAS_CPLUSPLUS)
extern "C" {
#endif /* PACE_HAS_CPLUSPLUS */

#define PACE_FD_CLOEXEC FD_CLOEXEC
#define PACE_F_DUPFD D_DUPFD
#define PACE_F_GETFD F_GETFD
#define PACE_F_GETFL F_GETFL
#define PACE_F_GETLK F_GETLK
#define PACE_F_RDLCK F_RDLCK
#define PACE_F_SETFD F_SETFD
#define PACE_F_SETFL F_SETFL
#define PACE_F_SETLK F_SETLK
#define PACE_F_SETLKW F_SETLKW
#define PACE_F_UNLCK F_UNLCK
#define PACE_F_WRLCK F_WRLCK
#define PACE_O_ACCMODE O_ACCMODE
#define PACE_O_APPEND O_APPEND
#define PACE_O_CREAT O_CREAT
#define PACE_O_DSYNC O_DSYNC
#define PACE_O_EXCL O_EXCL
#define PACE_O_NOCTTY O_NOCTTY
#define PACE_O_NONBLOCK O_NONBLOCK
#define PACE_O_RDONLY O_RDONLY
#define PACE_O_RDWR O_RDWR
#define PACE_O_RSYNC O_RSYNC
#define PACE_O_SYNC O_SYNC
#define PACE_O_TRUNC O_TRUNC
#define PACE_O_WRONLY O_WRONLY

#ifndef PACE_FLOCK
#define PACE_FLOCK
typedef struct flock pace_flock;
#endif /* PACE_FLOCK */

  /**
     PACE's implementation of the POSIX function creat.
     See POSIX standard (Internation Standard ISO/IEC 9945-1:1996;
     IEEE Std 1003.1, 1996 Edition), Section 5.3.2.
   */
  PACE_INLINE int pace_creat (const char * path, pace_mode_t mode);

  /**
     PACE's implementation of the POSIX function fcntl.
     See POSIX standard (Internation Standard ISO/IEC 9945-1:1996;
     IEEE Std 1003.1, 1996 Edition), Section 6.5.2.
   */
  # define pace_fcntl(X) fcntl X
  /* int fcntl (int fildes, int cmd, *//* arg *//* ... );
   *
   * PLEASE PAY SPECIAL ATTENTION HERE!
   * This is a macro and requires an additional set of parenthesis
   * surrounding the arguments.
   */

  /**
     PACE's implementation of the POSIX function open.
     See POSIX standard (Internation Standard ISO/IEC 9945-1:1996;
     IEEE Std 1003.1, 1996 Edition), Section 5.3.1.
   */
  # define pace_open(X) open X
  /* int open (const char *path, int oflag, *//* pace_mode_t mode *//* ... );
   *
   * PLEASE PAY SPECIAL ATTENTION HERE!
   * This is a macro and requires an additional set of parenthesis
   * surrounding the arguments.
   */

#if defined (PACE_HAS_CPLUSPLUS)
}
#endif /* PACE_HAS_CPLUSPLUS */

#if defined (PACE_HAS_INLINE)
# include "pace/posix/fcntl.inl"
#endif /* PACE_HAS_INLINE */

#endif /* PACE_FCNTL_H */
