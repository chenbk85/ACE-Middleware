/* $Id$

 * ============================================================================
 *
 * = LIBRARY
 *    pace
 *
 * = FILENAME
 *    pace/vxworks/pthread.h
 *
 * = AUTHOR
 *    Joe Hoffert. The *VAST* majority of the pthread code for VxWorks
 *    has been supplied by Hughes Network Systems via Braeton Taylor.
 *
 * ============================================================================ */

#ifndef PACE_PTHREAD_H_VXWORKS
#define PACE_PTHREAD_H_VXWORKS

#include <taskLib.h>
#include <taskHookLib.h>
#include <intLib.h>
#include <errnoLib.h>
#include "pace/sys/types.h"
#include "pace/signal.h"

#if defined (PACE_HAS_CPLUSPLUS)
extern "C" {
#endif /* PACE_HAS_CPLUSPLUS */

#define PACE_PTHREAD_CANCELED PTHREAD_CANCELED
#define PACE_PTHREAD_CANCEL_AYNCHRONOUS PTHREAD_CANCEL_ASYNCHRONOUS
#define PACE_PTHREAD_CANCEL_DEFERRED PTHREAD_CANCEL_DEFERRED
#define PACE_PTHREAD_CACEL_DISABLE PTHREAD_CANCEL_DISABLE
#define PACE_PTHREAD_CANCEL_ENABLE PTHREAD_CANCEL_ENABLE
#define PACE_PTHREAD_COND_INITIALIZER PTHREAD_COND_INITIALIZER
#define PACE_PTHREAD_CREATE_DETACHED PTHREAD_CREATE_DETACHED
#define PACE_PTHREAD_CREATE_JOINABLE PTHREAD_CREATE_JOINABLE
#define PACE_PTHREAD_EXPLICIT_SCHED PTHREAD_EXPLICIT_SCHED
#define PACE_PTHREAD_INHERIT_SCHED PTHREAD_INHERIT_SCHED
#define PACE_PTHREAD_MUTEX_INITIALIZER PTHREAD_MUTEX_INITIALIZER
#define PACE_PTHREAD_ONCE_INIT PTHREAD_ONCE_INIT
#define PACE_PTHREAD_PRIO_INHERIT PTHREAD_PRIO_INHERIT
#define PACE_PTHREAD_PRIO_NONE PTHREAD_PRIO_NONE
#define PACE_PTHREAD_PRIO_PROTECT PTHREAD_PRIO_PROTECT
#define PACE_PTHREAD_PROCESS_PRIVATE PTHREAD_PROCESS_PRIVATE
#define PACE_PTHREAD_PROCESS_SHARED PTHREAD_PROCESS_SHARED
#define PACE_PTHREAD_SCOPE_PROCESS PTHREAD_SCOPE_PROCESS
#define PACE_PTHREAD_SCOPE_SYSTEM PTHREAD_SCOPE_SYSTEM

#ifndef PACE_SCHED_PARAM
#define PACE_SCHED_PARAM
  typedef struct sched_param pace_sched_param;
#endif /* PACE_SCHED_PARAM */

#if defined (PACE_HAS_CPLUSPLUS)
# ifndef PACE_ATFORK_PF
# define PACE_ATFORK_PF
  typedef void (*pace_atfork_pf) (void);
# endif /* PACE_ATFORK_PF */

# ifndef PACE_KEYCREATE_PF
# define PACE_KEYCREATE_PF
  typedef void (*pace_keycreate_pf) (void*);
# endif /* PACE_KEYCREATE_PF */

# ifndef PACE_ONCE_PF
# define PACE_ONCE_PF
  typedef void (*pace_once_pf) (void);
# endif /* PACE_ONCE_PF */

# ifndef PACE_CREATE_PF
# define PACE_CREATE_PF
  typedef void* (*pace_create_pf) (void*);
# endif /* PACE_CREATE_PF */

#endif /* PACE_HAS_CPLUPLUS */

  /*
   * VxWorks helper functions
   */
#if (PACE_HAS_POSIX_NONUOF_FUNCS)
  PACE_INLINE int pthread_verify(pace_pthread_t pthread);
  PACE_INLINE void pthread_run_cleanup (WIND_TCB *pTcb);
  PACE_INLINE int pthread_queue_add(pace_pthread_t pthread);
  PACE_INLINE int pthread_queue_remove(pace_pthread_t pthread);
  PACE_INLINE void pthread_cleanup_popall(pace_pthread_t thread);
  PACE_INLINE void pthread_destructor_thread(pace_pthread_t pthread);
  PACE_INLINE int pthread_key_validate(pace_pthread_key_t key);
  PACE_INLINE void pthread_destructor_key(pace_pthread_key_t key, void * arg);
#endif /* PACE_HAS_POSIX_NONUOF_FUNCS */

#if defined (PACE_HAS_CPLUSPLUS)
}
#endif /* PACE_HAS_CPLUSPLUS */

#endif /* PACE_PTHREAD_H_VXWORKS */
