/* $Id$

 * ============================================================================
 *
 * = LIBRARY
 *    pace
 *
 * = FILENAME
 *    pace/posix/mman.h
 *
 * = AUTHOR
 *    Luther Baker
 *
 * ============================================================================ */

#ifndef PACE_SYS_MMAN_H
#define PACE_SYS_MMAN_H

#include <sys/mman.h>

#if defined (PACE_HAS_CPLUSPLUS)
extern "C" {
#endif /* PACE_HAS_CPLUSPLUS */

#define PACE_MAP_FAILED MAP_FAILED
#define PACE_MAP_FIXED MAP_FIXED
#define PACE_MAP_PRIVATE MAP_PRIVATE
#define PACE_MAP_SHARED MAP_SHARED
#define PACE_MCL_CURRENT MCL_CURRENT
#define PACE_MS_ASYNC MS_ASYNC
#define PACE_MS_INVALIDATE
#define PACE_MS_SYNC MS_SYNC
#define PACE_PROT_EXEC PROT_EXEC
#define PACE_PROT_NONE PROT_NONE
#define PACE_PROT_READ PROT_READ
#define PACE_PROT_WRITE PROT_WRITE

  /**
     PACE's implementation of the POSIX function mlock.
     See POSIX standard (Internation Standard ISO/IEC 9945-1:1996;
     IEEE Std 1003.1, 1996 Edition), Section 12.1.2.
   */
  PACE_INLINE int pace_mlock (const void * addr, pace_size_t len);

  /**
     PACE's implementation of the POSIX function mlockall.
     See POSIX standard (Internation Standard ISO/IEC 9945-1:1996;
     IEEE Std 1003.1, 1996 Edition), Section 12.1.1.
   */
  PACE_INLINE int pace_mlockall (int flags);

  /**
     PACE's implementation of the POSIX function mmap.
     See POSIX standard (Internation Standard ISO/IEC 9945-1:1996;
     IEEE Std 1003.1, 1996 Edition), Section 12.2.1.
   */
  PACE_INLINE void * pace_mmap (void * addr,
                                pace_size_t len,
                                int prot,
                                int flags,
                                int fildes,
                                pace_off_t off);

  /**
     PACE's implementation of the POSIX function mprotect.
     See POSIX standard (Internation Standard ISO/IEC 9945-1:1996;
     IEEE Std 1003.1, 1996 Edition), Section 12.2.3.
   */
  PACE_INLINE int pace_mprotect (void * addr,
                                 pace_size_t len,
                                 int prot);

  /**
     PACE's implementation of the POSIX function msync.
     See POSIX standard (Internation Standard ISO/IEC 9945-1:1996;
     IEEE Std 1003.1, 1996 Edition), Section 12.2.4.
   */
  PACE_INLINE int pace_msync (void * addr,
                              pace_size_t len,
                              int flags);

  /**
     PACE's implementation of the POSIX function munlock.
     See POSIX standard (Internation Standard ISO/IEC 9945-1:1996;
     IEEE Std 1003.1, 1996 Edition), Section 12.1.2.
   */
  PACE_INLINE int pace_munlock (const void * addr, pace_size_t len);

  /**
     PACE's implementation of the POSIX function munlockall.
     See POSIX standard (Internation Standard ISO/IEC 9945-1:1996;
     IEEE Std 1003.1, 1996 Edition), Section 12.1.1.
   */
  PACE_INLINE int pace_munlockall ();

  /**
     PACE's implementation of the POSIX function munmap.
     See POSIX standard (Internation Standard ISO/IEC 9945-1:1996;
     IEEE Std 1003.1, 1996 Edition), Section 12.2.2.
   */
  PACE_INLINE int pace_munmap (void *addr, pace_size_t len);

  /**
     PACE's implementation of the POSIX function shm_open.
     See POSIX standard (Internation Standard ISO/IEC 9945-1:1996;
     IEEE Std 1003.1, 1996 Edition), Section 12.3.1.
   */
  PACE_INLINE int pace_shm_open (const char * name,
                                 int oflag,
                                 pace_mode_t mode);
  /* Requires PACE_POSIX_C_SOURCE > 2. */

  /**
     PACE's implementation of the POSIX function shm_open.
     See POSIX standard (Internation Standard ISO/IEC 9945-1:1996;
     IEEE Std 1003.1, 1996 Edition), Section 12.3.2.
   */
  PACE_INLINE int pace_shm_unlink (const char * name);
  /* Requires PACE_POSIX_C_SOURCE > 2. */

#if defined (PACE_HAS_CPLUSPLUS)
}
#endif /* PACE_HAS_CPLUSPLUS */

#if defined (PACE_HAS_INLINE)
# include "pace/posix/mman.inl"
#endif /* PACE_HAS_INLINE */

#endif /* PACE_SYS_MMAN_H */
