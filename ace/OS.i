// -*- C++ -*-
// $Id$

#if !defined (ACE_HAS_INLINED_OSCALLS)
# undef ACE_INLINE
# define ACE_INLINE
#endif /* ACE_HAS_INLINED_OSCALLS */

#if defined (ACE_LACKS_RLIMIT_PROTOTYPE)
int getrlimit (int resource, struct rlimit *rlp);
int setrlimit (int resource, const struct rlimit *rlp);
#endif /* ACE_LACKS_RLIMIT_PROTOTYPE */

#if !defined (ACE_HAS_STRERROR)
# if defined (ACE_HAS_SYS_ERRLIST)
extern char *sys_errlist[];
#   define strerror(err) sys_errlist[err]
# else
#   define strerror(err) "strerror is unsupported"
# endif /* ACE_HAS_SYS_ERRLIST */
#endif /* !ACE_HAS_STERROR */

#if defined (ACE_HAS_SYS_SIGLIST)
# if !defined (_sys_siglist)
#   define _sys_siglist sys_siglist
# endif /* !defined (sys_siglist) */
//extern char **_sys_siglist;
#endif /* ACE_HAS_SYS_SIGLIST */

#if defined (ACE_HAS_SOCKLEN_T)
typedef socklen_t ACE_SOCKET_LEN;
#elif defined (ACE_HAS_SIZET_SOCKET_LEN)
typedef size_t ACE_SOCKET_LEN;
#else
typedef int ACE_SOCKET_LEN;
#endif /* ACE_HAS_SIZET_SOCKET_LEN */

#if defined (ACE_LACKS_CONST_STRBUF_PTR)
typedef struct strbuf *ACE_STRBUF_TYPE;
#else
typedef const struct strbuf *ACE_STRBUF_TYPE;
#endif /* ACE_LACKS_CONST_STRBUF_PTR */

#if defined (ACE_HAS_VOIDPTR_SOCKOPT)
typedef void *ACE_SOCKOPT_TYPE1;
#elif defined (ACE_HAS_CHARPTR_SOCKOPT)
typedef char *ACE_SOCKOPT_TYPE1;
#else
typedef const char *ACE_SOCKOPT_TYPE1;
#endif /* ACE_HAS_VOIDPTR_SOCKOPT */

#if !defined (_BSD_SOURCE) && \
    !defined (_XOPEN_SOURCE) && !defined (_XOPEN_SOURCE_EXTENDED)
# if defined (ACE_LACKS_SETREUID_PROTOTYPE)
extern "C" {
extern int setreuid (uid_t ruid, uid_t euid);
}
# endif /* ACE_LACKS_SETREUID_PROTOTYPE */

# if defined (ACE_LACKS_SETREGID_PROTOTYPE)
extern "C" {
extern int setregid (gid_t rgid, gid_t egid);
}
# endif /* ACE_LACKS_SETREGID_PROTOTYPE */
#endif  /* !_BSD_SOURCE && !_XOPEN_SOURCE && !_XOPEN_SOURCE_EXTENDED */

#if defined (ACE_LACKS_WRITEV)
extern "C" ACE_Export int writev (ACE_HANDLE handle, ACE_WRITEV_TYPE *iov, int iovcnt);
#endif /* ACE_LACKS_WRITEV */

#if defined (ACE_LACKS_READV)
extern "C" ACE_Export ssize_t readv (ACE_HANDLE handle, ACE_READV_TYPE *iov, int iovcnt);
#endif /* ACE_LACKS_READV */

#if defined (ACE_NEEDS_FTRUNCATE)
extern "C" ACE_Export int ftruncate (ACE_HANDLE handle, long len);
#endif /* ACE_NEEDS_FTRUNCATE */

#if defined (ACE_HAS_VOIDPTR_MMAP)
// Needed for some odd OS's (e.g., SGI).
typedef void *ACE_MMAP_TYPE;
#else
typedef char *ACE_MMAP_TYPE;
#endif /* ACE_HAS_VOIDPTR_MMAP */

#if defined (ACE_HAS_XLI)
# include /**/ <xliuser.h>
#endif /* ACE_HAS_XLI */

#if defined (_M_UNIX)
extern "C" int _dlclose (void *);
extern "C" char *_dlerror (void);
extern "C" void *_dlopen (const char *, int);
extern "C" void * _dlsym (void *, const char *);
#endif /* _M_UNIX */

#if !defined (ACE_HAS_CPLUSPLUS_HEADERS)
# include /**/ <libc.h>
# include /**/ <osfcn.h>
#endif /* ACE_HAS_CPLUSPLUS_HEADERS */

#if defined (ACE_HAS_SYSENT_H)
# include /**/ <sysent.h>
#endif /* ACE_HAS_SYSENT_H_*/

#if defined (ACE_USES_STD_NAMESPACE_FOR_STDC_LIB) && \
            (ACE_USES_STD_NAMESPACE_FOR_STDC_LIB != 0)
using std::bsearch;
using std::qsort;
# if defined (ACE_WIN32)
using std::_tzset;
using std::_timezone;
# else
using std::tzset;
using std::timezone;
# endif
using std::difftime;
using std::ctime;
using std::localtime;
using std::gmtime;
using std::asctime;
using std::strftime;
#endif /* ACE_USES_STD_NAMESPACE_FOR_STDC_LIB */

#if defined (ACE_HAS_SVR4_GETTIMEOFDAY)
# if !defined (m88k) && !defined (SCO)
extern "C" int gettimeofday (struct timeval *tp, void * = 0);
# else
extern "C" int gettimeofday (struct timeval *tp);
# endif  /*  !m88k && !SCO */
#elif defined (ACE_HAS_OSF1_GETTIMEOFDAY)
extern "C" int gettimeofday (struct timeval *tp, struct timezone * = 0);
#elif defined (ACE_HAS_SUNOS4_GETTIMEOFDAY)
# define ACE_HAS_SVR4_GETTIMEOFDAY
#endif /* ACE_HAS_SVR4_GETTIMEOFDAY */

#if defined (ACE_LACKS_CONST_TIMESPEC_PTR)
typedef struct timespec * ACE_TIMESPEC_PTR;
#else
typedef const struct timespec * ACE_TIMESPEC_PTR;
#endif /* HPUX */

#if !defined (ACE_LACKS_MALLOC_H)
# include /**/ <malloc.h>
#endif /* ACE_LACKS_MALLOC_H */

ACE_INLINE
ACE_Errno_Guard::ACE_Errno_Guard (ACE_ERRNO_TYPE &errno_ref,
                                  int error)
  :
#if defined (ACE_MT_SAFE)
    errno_ptr_ (&errno_ref),
#endif /* ACE_MT_SAFE */
    error_ (error)
{
#if !defined(ACE_MT_SAFE)
  ACE_UNUSED_ARG (errno_ref);
#endif /* ACE_MT_SAFE */
}

ACE_INLINE
ACE_Errno_Guard::ACE_Errno_Guard (ACE_ERRNO_TYPE &errno_ref)
  :
#if defined (ACE_MT_SAFE)
    errno_ptr_ (&errno_ref),
#endif /* ACE_MT_SAFE */
    error_ (errno_ref)
{
}

ACE_INLINE
ACE_Errno_Guard::~ACE_Errno_Guard (void)
{
#if defined (ACE_MT_SAFE)
  *errno_ptr_ = this->error_;
#else
  errno = this->error_;
#endif /* ACE_MT_SAFE */
}

#if defined (ACE_HAS_WINCE_BROKEN_ERRNO)
ACE_INLINE int
ACE_Errno_Guard::operator= (const ACE_ERRNO_TYPE &error)
{
  return this->error_ = error;
}
#endif /* ACE_HAS_WINCE_BROKEN_ERRNO */

ACE_INLINE int
ACE_Errno_Guard::operator= (int error)
{
  return this->error_ = error;
}

ACE_INLINE int
ACE_Errno_Guard::operator== (int error)
{
  return this->error_ == error;
}

ACE_INLINE int
ACE_Errno_Guard::operator!= (int error)
{
  return this->error_ != error;
}

#if defined (ACE_HAS_WINCE_BROKEN_ERRNO)
ACE_INLINE ACE_CE_Errno *
ACE_CE_Errno::instance ()
{
  // This should be inlined.
  return ACE_CE_Errno::instance_;
}

ACE_INLINE
ACE_CE_Errno::operator int (void) const
{
  return (int) TlsGetValue (ACE_CE_Errno::errno_key_);
}

ACE_INLINE int
ACE_CE_Errno::operator= (int x)
{
  // error checking?
  TlsSetValue (ACE_CE_Errno::errno_key_, (void *) x);
  return x;
}
#endif /* ACE_HAS_WINCE_BROKEN_ERRNO */

// Returns the value of the object as a timeval.

ACE_INLINE
ACE_Time_Value::operator timeval () const
{
  ACE_TRACE ("ACE_Time_Value::operator timeval");
  return this->tv_;
}

// Returns a pointer to the object as a timeval.

ACE_INLINE
ACE_Time_Value::operator const timeval * () const
{
  ACE_TRACE ("ACE_Time_Value::operator timeval");
  return (const timeval *) &this->tv_;
}

ACE_INLINE void
ACE_Time_Value::set (long sec, long usec)
{
  // ACE_TRACE ("ACE_Time_Value::set");
  this->tv_.tv_sec = sec;
  this->tv_.tv_usec = usec;
}

ACE_INLINE void
ACE_Time_Value::set (double d)
{
  // ACE_TRACE ("ACE_Time_Value::set");
  long l = (long) d;
  this->tv_.tv_sec = l;
  this->tv_.tv_usec = (long) ((d - (double) l) * ACE_ONE_SECOND_IN_USECS);
  this->normalize ();
}

// Initializes a timespec_t.  Note that this approach loses precision
// since it converts the nano-seconds into micro-seconds.  But then
// again, do any real systems have nano-second timer precision?!

ACE_INLINE void
ACE_Time_Value::set (const timespec_t &tv)
{
  // ACE_TRACE ("ACE_Time_Value::set");
#if ! defined(ACE_HAS_BROKEN_TIMESPEC_MEMBERS)
  this->tv_.tv_sec = tv.tv_sec;
  // Convert nanoseconds into microseconds.
  this->tv_.tv_usec = tv.tv_nsec / 1000;
#else
  this->tv_.tv_sec = tv.ts_sec;
  // Convert nanoseconds into microseconds.
  this->tv_.tv_usec = tv.ts_nsec / 1000;
#endif /* ACE_HAS_BROKEN_TIMESPEC_MEMBERS */

  this->normalize ();
}

ACE_INLINE void
ACE_Time_Value::set (const timeval &tv)
{
  // ACE_TRACE ("ACE_Time_Value::set");
  this->tv_.tv_sec = tv.tv_sec;
  this->tv_.tv_usec = tv.tv_usec;

  this->normalize ();
}

ACE_INLINE
ACE_Time_Value::ACE_Time_Value (const timeval &tv)
  // : tv_ ()
{
  // ACE_TRACE ("ACE_Time_Value::ACE_Time_Value");
  this->set (tv);
}

ACE_INLINE
ACE_Time_Value::ACE_Time_Value (void)
  // : tv_ ()
{
  // ACE_TRACE ("ACE_Time_Value::ACE_Time_Value");
  this->set (0, 0);

  // Don't need to normalize time value of (0, 0).
}

ACE_INLINE
ACE_Time_Value::ACE_Time_Value (long sec, long usec)
{
  // ACE_TRACE ("ACE_Time_Value::ACE_Time_Value");
  this->set (sec, usec);
  this->normalize ();
}

// Returns number of seconds.

ACE_INLINE long
ACE_Time_Value::sec (void) const
{
  ACE_TRACE ("ACE_Time_Value::sec");
  return this->tv_.tv_sec;
}

// Sets the number of seconds.

ACE_INLINE void
ACE_Time_Value::sec (long sec)
{
  ACE_TRACE ("ACE_Time_Value::sec");
  this->tv_.tv_sec = sec;
}

// Converts from Time_Value format into milli-seconds format.

ACE_INLINE long
ACE_Time_Value::msec (void) const
{
  ACE_TRACE ("ACE_Time_Value::msec");
  return this->tv_.tv_sec * 1000 + this->tv_.tv_usec / 1000;
}

// Converts from milli-seconds format into Time_Value format.

ACE_INLINE void
ACE_Time_Value::msec (long milliseconds)
{
  ACE_TRACE ("ACE_Time_Value::msec");
  // Convert millisecond units to seconds;
  this->tv_.tv_sec = milliseconds / 1000;
  // Convert remainder to microseconds;
  this->tv_.tv_usec = (milliseconds - (this->tv_.tv_sec * 1000)) * 1000;
}

// Returns number of micro-seconds.

ACE_INLINE long
ACE_Time_Value::usec (void) const
{
  ACE_TRACE ("ACE_Time_Value::usec");
  return this->tv_.tv_usec;
}

// Sets the number of micro-seconds.

ACE_INLINE void
ACE_Time_Value::usec (long usec)
{
  ACE_TRACE ("ACE_Time_Value::usec");
  this->tv_.tv_usec = usec;
}

ACE_INLINE ACE_Time_Value &
ACE_Time_Value::operator *= (double d)
{
  double time = this->sec () * ACE_ONE_SECOND_IN_USECS + this->usec ();
  time *= d;
  this->sec ((long)(time / ACE_ONE_SECOND_IN_USECS));
  this->usec (((long)time) % ACE_ONE_SECOND_IN_USECS);

  return *this;
}

ACE_INLINE ACE_Time_Value
operator * (double d, const ACE_Time_Value &tv)
{
  return ACE_Time_Value (tv) *= d;
}

ACE_INLINE ACE_Time_Value
operator * (const ACE_Time_Value &tv, double d)
{
  return ACE_Time_Value (tv) *= d;
}

// True if tv1 > tv2.

ACE_INLINE int
operator > (const ACE_Time_Value &tv1,
            const ACE_Time_Value &tv2)
{
  ACE_TRACE ("operator >");
  if (tv1.sec () > tv2.sec ())
    return 1;
  else if (tv1.sec () == tv2.sec ()
           && tv1.usec () > tv2.usec ())
    return 1;
  else
    return 0;
}

// True if tv1 >= tv2.

ACE_INLINE int
operator >= (const ACE_Time_Value &tv1,
             const ACE_Time_Value &tv2)
{
  ACE_TRACE ("operator >=");
  if (tv1.sec () > tv2.sec ())
    return 1;
  else if (tv1.sec () == tv2.sec ()
           && tv1.usec () >= tv2.usec ())
    return 1;
  else
    return 0;
}

// Returns the value of the object as a timespec_t.

ACE_INLINE
ACE_Time_Value::operator timespec_t () const
{
  ACE_TRACE ("ACE_Time_Value::operator timespec_t");
  timespec_t tv;
#if ! defined(ACE_HAS_BROKEN_TIMESPEC_MEMBERS)
  tv.tv_sec = this->sec ();
  // Convert microseconds into nanoseconds.
  tv.tv_nsec = this->tv_.tv_usec * 1000;
#else
  tv.ts_sec = this->sec ();
  // Convert microseconds into nanoseconds.
  tv.ts_nsec = this->tv_.tv_usec * 1000;
#endif /* ACE_HAS_BROKEN_TIMESPEC_MEMBERS */
  return tv;
}

// Initializes the ACE_Time_Value object from a timespec_t.

ACE_INLINE
ACE_Time_Value::ACE_Time_Value (const timespec_t &tv)
  // : tv_ ()
{
  // ACE_TRACE ("ACE_Time_Value::ACE_Time_Value");
  this->set (tv);
}

// Initializes the ACE_Time_Value object from another ACE_Time_Value

ACE_INLINE
ACE_Time_Value::ACE_Time_Value (const ACE_Time_Value &tv)
  : tv_ (tv.tv_)
{
  // ACE_TRACE ("ACE_Time_Value::ACE_Time_Value");
}

// True if tv1 < tv2.

ACE_INLINE int
operator < (const ACE_Time_Value &tv1,
            const ACE_Time_Value &tv2)
{
  ACE_TRACE ("operator <");
  return tv2 > tv1;
}

// True if tv1 >= tv2.

ACE_INLINE int
operator <= (const ACE_Time_Value &tv1,
             const ACE_Time_Value &tv2)
{
  ACE_TRACE ("operator <=");
  return tv2 >= tv1;
}

// True if tv1 == tv2.

ACE_INLINE int
operator == (const ACE_Time_Value &tv1,
             const ACE_Time_Value &tv2)
{
  // ACE_TRACE ("operator ==");
  return tv1.sec () == tv2.sec ()
    && tv1.usec () == tv2.usec ();
}

// True if tv1 != tv2.

ACE_INLINE int
operator != (const ACE_Time_Value &tv1,
             const ACE_Time_Value &tv2)
{
  // ACE_TRACE ("operator !=");
  return !(tv1 == tv2);
}

// Add TV to this.

ACE_INLINE void
ACE_Time_Value::operator+= (const ACE_Time_Value &tv)
{
  ACE_TRACE ("ACE_Time_Value::operator+=");
  this->sec (this->sec () + tv.sec ());
  this->usec (this->usec () + tv.usec ());
  this->normalize ();
}

// Subtract TV to this.

ACE_INLINE void
ACE_Time_Value::operator-= (const ACE_Time_Value &tv)
{
  ACE_TRACE ("ACE_Time_Value::operator-=");
  this->sec (this->sec () - tv.sec ());
  this->usec (this->usec () - tv.usec ());
  this->normalize ();
}

// Adds two ACE_Time_Value objects together, returns the sum.

ACE_INLINE ACE_Time_Value
operator + (const ACE_Time_Value &tv1,
            const ACE_Time_Value &tv2)
{
  ACE_TRACE ("operator +");
  ACE_Time_Value sum (tv1.sec () + tv2.sec (),
                      tv1.usec () + tv2.usec ());

  sum.normalize ();
  return sum;
}

// Subtracts two ACE_Time_Value objects, returns the difference.

ACE_INLINE ACE_Time_Value
operator - (const ACE_Time_Value &tv1,
            const ACE_Time_Value &tv2)
{
  ACE_TRACE ("operator -");
  ACE_Time_Value delta (tv1.sec () - tv2.sec (),
                        tv1.usec () - tv2.usec ());
  delta.normalize ();
  return delta;
}

ACE_INLINE int
ACE_OS::fcntl (ACE_HANDLE handle, int cmd, long arg)
{
  ACE_TRACE ("ACE_OS::fcntl");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_fcntl (handle, cmd, arg), int, -1);
# elif defined (ACE_LACKS_FCNTL)
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (cmd);
  ACE_UNUSED_ARG (arg);
  ACE_NOTSUP_RETURN (-1);
# else
  ACE_OSCALL_RETURN (::fcntl (handle, cmd, arg), int, -1);
# endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::chdir (const ACE_TCHAR *path)
{
  ACE_TRACE ("ACE_OS::chdir");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_chdir (path), int, -1);
#elif defined (VXWORKS)
  ACE_OSCALL_RETURN (::chdir (ACE_const_cast (char *, path)), int, -1);

#elif defined (ACE_PSOS_LACKS_PHILE)
  ACE_UNUSED_ARG (path);
  ACE_NOTSUP_RETURN (-1);

#elif defined (ACE_PSOS)
    ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::change_dir ((char *) path), ace_result_),
                     int, -1);

#elif !defined (ACE_WIN32) && defined (__IBMCPP__) && (__IBMCPP__ >= 400)
  ACE_OSCALL_RETURN (::_chdir (path), int, -1);

#elif defined (ACE_HAS_WINCE)
  ACE_UNUSED_ARG (path);
  ACE_NOTSUP_RETURN (-1);

#elif defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
  ACE_OSCALL_RETURN (::_wchdir (path), int, -1);

#else
  ACE_OSCALL_RETURN (::chdir (path), int, -1);

#endif /* ACE_HAS_PACE */
}

#if !defined (ACE_LACKS_MKTEMP)
ACE_INLINE ACE_TCHAR *
ACE_OS::mktemp (ACE_TCHAR *s)
{
# if defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
  return ::_wmktemp (s);
# elif defined (ACE_WIN32)
  return ::_mktemp (s);
# else /* ACE_WIN32 */
  return ::mktemp (s);
# endif /* ACE_WIN32 */
}
#endif /* !ACE_LACKS_MKTEMP */

ACE_INLINE int
ACE_OS::mkfifo (const ACE_TCHAR *file, mode_t mode)
{
  ACE_TRACE ("ACE_OS::mkfifo");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_mkfifo (file, mode), int, -1);
#elif defined (ACE_LACKS_MKFIFO)
  ACE_UNUSED_ARG (file);
  ACE_UNUSED_ARG (mode);
  ACE_NOTSUP_RETURN (-1);
#else
  ACE_OSCALL_RETURN (::mkfifo (file, mode), int, -1);
#   endif /* ACE_HAS_PACE */
}

#if !defined (ACE_WIN32)

// Matthew Stevens 7-10-95 Fix GNU GCC 2.7 for memchr() problem.
# if defined (ACE_HAS_GNU_CSTRING_H)
// Define this file to keep /usr/include/memory.h from being included.
#   include /**/ <cstring>
# else
#   if defined (ACE_LACKS_MEMORY_H)
#     if !defined (ACE_PSOS_DIAB_MIPS)
#       include /**/ <string.h>
#     endif /* ACE_PSOS_DIAB_MIPS */
#   else
#     include /**/ <memory.h>
#   endif /* VXWORKS */
# endif /* ACE_HAS_GNU_CSTRING_H */

// These prototypes are chronically lacking from many versions of
// UNIX.
extern "C" int isastream (int);
# if !defined (ACE_HAS_GETRUSAGE_PROTO)
extern "C" int getrusage (int who, struct rusage *rusage);
# endif /* ! ACE_HAS_GETRUSAGE_PROTO */

# if defined (ACE_LACKS_SYSCALL)
extern "C" int syscall (int, ACE_HANDLE, struct rusage *);
# endif /* ACE_LACKS_SYSCALL */

# if defined (ACE_LACKS_MKTEMP)
extern "C" char *mktemp (char *);
# endif /* ACE_LACKS_MKTEMP */

// The following are #defines and #includes that must be visible for
// ACE to compile it's OS wrapper class implementation correctly.  We
// put them inside of here to reduce compiler overhead if we're not
// inlining...

# if defined (ACE_HAS_REGEX)
#   include /**/ <regexpr.h>
# endif /* ACE_HAS_REGEX */

# if defined (ACE_HAS_SYSINFO)
#   include /**/ <sys/systeminfo.h>
# endif /* ACE_HAS_SYS_INFO */

# if defined (ACE_HAS_SYSCALL_H)
#   include /**/ <sys/syscall.h>
# endif /* ACE_HAS_SYSCALL_H */

# if defined (UNIXWARE)  /* See strcasecmp, below */
#   include /**/ <ctype.h>
# endif /* UNIXWARE */

// Adapt the weird threading and synchronization routines (which
// return errno rather than -1) so that they return -1 and set errno.
// This is more consistent with the rest of ACE_OS and enables use to
// use the ACE_OSCALL* macros.
# if defined (VXWORKS)
#   define ACE_ADAPT_RETVAL(OP,RESULT) ((RESULT = (OP)) != OK ? (errno = RESULT, -1) : 0)
# else
#   define ACE_ADAPT_RETVAL(OP,RESULT) ((RESULT = (OP)) != 0 ? (errno = RESULT, -1) : 0)
# endif /* VXWORKS */

ACE_INLINE int
ACE_OS::fstat (ACE_HANDLE handle, struct stat *stp)
{
  ACE_TRACE ("ACE_OS::fstat");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_fstat (handle, stp), int, -1);
#elif defined (ACE_PSOS_LACKS_PHILE)
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (stp);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_PSOS)
  ACE_OSCALL_RETURN (::fstat_f (handle, stp), int, -1);
#else
# if defined (ACE_HAS_X86_STAT_MACROS)
    // Solaris for intel uses an macro for fstat(), this is a wrapper
    // for _fxstat() use of the macro.
    // causes compile and runtime problems.
    ACE_OSCALL_RETURN (::_fxstat (_STAT_VER, handle, stp), int, -1);
# else  /* !ACE_HAS_X86_STAT_MACROS */
    ACE_OSCALL_RETURN (::fstat (handle, stp), int, -1);
# endif /* !ACE_HAS_X86_STAT_MACROS */
#endif /* defined (ACE_HAS_PACE) */
}

ACE_INLINE int
ACE_OS::lstat (const char *file, struct stat *stp)
{
  ACE_TRACE ("ACE_OS::lstat");
# if defined (ACE_LACKS_LSTAT) || \
     defined (ACE_HAS_WINCE) || defined (ACE_WIN32)
  ACE_UNUSED_ARG (file);
  ACE_UNUSED_ARG (stp);
  ACE_NOTSUP_RETURN (-1);
#else
# if defined (ACE_HAS_X86_STAT_MACROS)
   // Solaris for intel uses an macro for lstat(), this macro is a
   // wrapper for _lxstat().
  ACE_OSCALL_RETURN (::_lxstat (_STAT_VER, file, stp), int, -1);
#else /* !ACE_HAS_X86_STAT_MACROS */
  ACE_OSCALL_RETURN (::lstat (file, stp), int, -1);
#endif /* !ACE_HAS_X86_STAT_MACROS */
# endif /* VXWORKS */
}

ACE_INLINE int
ACE_OS::fsync (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_OS::fsync");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_fsync (handle), int, -1);
# elif defined (ACE_LACKS_FSYNC)
  ACE_UNUSED_ARG (handle);
  ACE_NOTSUP_RETURN (-1);
# else
  ACE_OSCALL_RETURN (::fsync (handle), int, -1);
# endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::getopt (int argc, char *const *argv, const char *optstring)
{
  ACE_TRACE ("ACE_OS::getopt");
#if defined (VXWORKS) || defined (ACE_PSOS)
  ACE_UNUSED_ARG (argc);
  ACE_UNUSED_ARG (argv);
  ACE_UNUSED_ARG (optstring);
  ACE_NOTSUP_RETURN (-1);
# elif defined (ACE_LACKS_GETOPT_PROTO)
  ACE_OSCALL_RETURN (::getopt (argc, (char**) argv, optstring), int, -1);
# elif defined (ACE_LACKS_POSIX_PROTOTYPES)
  ACE_OSCALL_RETURN (::getopt (argc, (const char* const *) argv, optstring), int, -1);
# else
  ACE_OSCALL_RETURN (::getopt (argc, argv, optstring), int, -1);
# endif /* VXWORKS */
}

ACE_INLINE int
ACE_OS::pipe (ACE_HANDLE fds[])
{
  ACE_TRACE ("ACE_OS::pipe");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_pipe (fds), int, -1);
#elif defined (VXWORKS) || defined (ACE_PSOS)
  ACE_UNUSED_ARG (fds);
  ACE_NOTSUP_RETURN (-1);
# else
  ACE_OSCALL_RETURN (::pipe (fds), int, -1);
# endif /* ACE_HAS_PACE */
}

# if defined (DIGITAL_UNIX)
extern "C" {
  extern char *_Pctime_r (const time_t *, char *);
  extern struct tm *_Plocaltime_r (const time_t *, struct tm *);
  extern struct tm *_Pgmtime_r (const time_t *, struct tm *);
  extern char *_Pasctime_r (const struct tm *, char *);
  extern int _Prand_r (unsigned int *seedptr);
  extern int _Pgetpwnam_r (const char *, struct passwd *,
                           char *, size_t, struct passwd **);
}
# endif /* DIGITAL_UNIX */

// VAC++ doesn't correctly grok the ::getpwnam_r - the function is redefined
// in pwd.h, and that redefinition is used here
# if defined (_AIX) && defined (__IBMCPP__) && (__IBMCPP__ >= 400)
extern "C" {
  extern int _posix_getpwnam_r(const char *, struct passwd *, char *,
                               int, struct passwd **);
           }
#endif /* AIX and VAC++ 4 */

ACE_INLINE int
ACE_OS::rand_r (ACE_RANDR_TYPE &seed)
{
  ACE_TRACE ("ACE_OS::rand_r");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_rand_r (&seed), int, -1);
# elif defined (ACE_HAS_REENTRANT_FUNCTIONS) && \
    !defined (ACE_LACKS_RAND_REENTRANT_FUNCTIONS)
#   if defined (DIGITAL_UNIX)
  ACE_OSCALL_RETURN (::_Prand_r (&seed), int, -1);
#   elif defined (HPUX_10)
  // rand() is thread-safe on HP-UX 10.  rand_r's signature is not consistent
  // with latest POSIX and will change in a future HP-UX release so that it
  // is consistent.  At that point, this #elif section can be changed or
  // removed, and just call rand_r.
  ACE_UNUSED_ARG (seed);
  ACE_OSCALL_RETURN (::rand(), int, -1);
#   elif defined (ACE_HAS_BROKEN_RANDR)
  ACE_OSCALL_RETURN (::rand_r (seed), int, -1);
#   else
  ACE_OSCALL_RETURN (::rand_r (&seed), int, -1);
#   endif /* DIGITAL_UNIX */
# else
  ACE_UNUSED_ARG (seed);
  ACE_OSCALL_RETURN (::rand (), int, -1);
# endif /* ACE_HAS_PACE */
}

ACE_INLINE pid_t
ACE_OS::setsid (void)
{
  ACE_TRACE ("ACE_OS::setsid");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_setsid (), int , -1);
#elif defined (VXWORKS) || defined (CHORUS) || defined (ACE_PSOS)
  ACE_NOTSUP_RETURN (-1);
# else
  ACE_OSCALL_RETURN (::setsid (), int, -1);
# endif /* ACE_HAS_PACE */
}

ACE_INLINE mode_t
ACE_OS::umask (mode_t cmask)
{
  ACE_TRACE ("ACE_OS::umask");
#if defined (ACE_HAS_PACE)
  return pace_umask (cmask);
#elif defined (VXWORKS) || defined (ACE_PSOS)
  ACE_UNUSED_ARG (cmask);
  ACE_NOTSUP_RETURN (-1);
# else
  return ::umask (cmask); // This call shouldn't fail...
# endif /* ACE_HAS_PACE */
}

#else /* ACE_WIN32 */

// Adapt the Win32 System Calls (which return BOOLEAN values of TRUE
// and FALSE) into int values expected by the ACE_OSCALL macros.
# define ACE_ADAPT_RETVAL(OP,RESULT) ((RESULT = (OP)) == FALSE ? -1 : 0)

// Perform a mapping of Win32 error numbers into POSIX errnos.
# define ACE_FAIL_RETURN(RESULT) do { \
  switch (ACE_OS::set_errno_to_last_error ()) { \
  case ERROR_NOT_ENOUGH_MEMORY: errno = ENOMEM; break; \
  case ERROR_FILE_EXISTS:       errno = EEXIST; break; \
  case ERROR_SHARING_VIOLATION: errno = EACCES; break; \
  case ERROR_PATH_NOT_FOUND:    errno = ENOENT; break; \
  } \
  return RESULT; } while (0)

ACE_INLINE LPSECURITY_ATTRIBUTES
ACE_OS::default_win32_security_attributes (LPSECURITY_ATTRIBUTES sa)
{
#if defined (ACE_DEFINES_DEFAULT_WIN32_SECURITY_ATTRIBUTES)
  if (sa == 0)
    {
      // @@ This is a good place to use pthread_once.
      static SECURITY_ATTRIBUTES default_sa;
      static SECURITY_DESCRIPTOR sd;
      InitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION);
      SetSecurityDescriptorDacl(&sd, TRUE, NULL, FALSE);
      default_sa.nLength = sizeof(SECURITY_ATTRIBUTES);
      default_sa.lpSecurityDescriptor = &sd;
      default_sa.bInheritHandle       = TRUE;
      sa = &default_sa;
    }
  return sa;
#else /* !ACE_DEFINES_DEFAULT_WIN32_SECURITY_ATTRIBUTES */
  return sa;
#endif /* ACE_DEFINES_DEFAULT_WIN32_SECURITY_ATTRIBUTES */
}

ACE_INLINE int
ACE_OS::getopt (int argc, char *const *argv, const char *optstring)
{
  ACE_UNUSED_ARG (argc);
  ACE_UNUSED_ARG (argv);
  ACE_UNUSED_ARG (optstring);

  ACE_TRACE ("ACE_OS::getopt");
  ACE_NOTSUP_RETURN (-1);
}

ACE_INLINE int
ACE_OS::pipe (ACE_HANDLE fds[])
{
#if (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_pipe (fds), int, -1);
# elif !defined (ACE_HAS_WINCE) && !defined (__IBMCPP__)
  ACE_TRACE ("ACE_OS::pipe");
  ACE_OSCALL_RETURN (::_pipe ((int *) fds, PIPE_BUF, 0),
                     int,
                     -1);   // Use default mode
# else
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::rand_r (ACE_RANDR_TYPE& seed)
{
  ACE_UNUSED_ARG (seed);

  ACE_TRACE ("ACE_OS::rand_r");
  ACE_NOTSUP_RETURN (-1);
}

ACE_INLINE pid_t
ACE_OS::setsid (void)
{
  ACE_TRACE ("ACE_OS::setsid");
  ACE_NOTSUP_RETURN (-1);
}

ACE_INLINE mode_t
ACE_OS::umask (mode_t cmask)
{
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_umask (cmask), int -1);
# elif !defined (ACE_HAS_WINCE)
  ACE_TRACE ("ACE_OS::umask");
  ACE_OSCALL_RETURN (::_umask (cmask), int, -1);
# else
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::fstat (ACE_HANDLE handle, struct stat *stp)
{
  ACE_TRACE ("ACE_OS::fstat");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_fstat (handle, stp), int, -1);
# elif 1
  BY_HANDLE_FILE_INFORMATION fdata;

  if (::GetFileInformationByHandle (handle, &fdata) == FALSE)
    {
      ACE_OS::set_errno_to_last_error ();
      return -1;
    }
  else if (fdata.nFileSizeHigh != 0)
    {
      errno = EINVAL;
      return -1;
    }
  else
    {
      stp->st_size = fdata.nFileSizeLow;
      stp->st_atime = ACE_Time_Value (fdata.ftLastAccessTime).sec ();
      stp->st_mtime = ACE_Time_Value (fdata.ftLastWriteTime).sec ();
#if !defined (ACE_HAS_WINCE)
      stp->st_ctime = ACE_Time_Value (fdata.ftCreationTime).sec ();
      stp->st_nlink = ACE_static_cast (short, fdata.nNumberOfLinks);
      stp->st_dev = stp->st_rdev = 0; // No equivalent conversion.
      stp->st_mode = S_IXOTH | S_IROTH |
        (fdata.dwFileAttributes & FILE_ATTRIBUTE_READONLY ? 0 : S_IWOTH);
#endif /* !ACE_HAS_WINCE */
    }
  return 0;
# else /* 1 */
  // This implementation close the handle.
  int retval = -1;
  int fd = ::_open_osfhandle ((long) handle, 0);
  if (fd != -1)
      retval = ::_fstat (fd, (struct _stat *) stp);

  ::_close (fd);
  // Remember to close the file handle.
  return retval;
# endif /* ACE_HAS_PACE */
}

#endif /* WIN32 */

ACE_INLINE int
ACE_OS::clock_gettime (clockid_t clockid, struct timespec *ts)
{
  ACE_TRACE ("ACE_OS::clock_gettime");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_clock_gettime (clockid, ts), int, -1);
#elif defined (ACE_HAS_CLOCK_GETTIME)
  ACE_OSCALL_RETURN (::clock_gettime (clockid, ts), int, -1);
# elif defined (ACE_PSOS) && ! defined (ACE_PSOS_DIAB_MIPS)
  ACE_UNUSED_ARG (clockid);
  ACE_PSOS_Time_t pt;
  int result = ACE_PSOS_Time_t::get_system_time (pt);
  *ts = ACE_static_cast (struct timespec, pt);
  return result;
#else
  ACE_UNUSED_ARG (clockid);
  ACE_UNUSED_ARG (ts);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE ACE_Time_Value
ACE_OS::gettimeofday (void)
{
  // ACE_TRACE ("ACE_OS::gettimeofday");

  timeval tv;
  int result = 0;
#if defined (ACE_HAS_WINCE)
  SYSTEMTIME tsys;
  FILETIME   tfile;
  ::GetSystemTime (&tsys);
  ::SystemTimeToFileTime (&tsys, &tfile);
  return ACE_Time_Value (tfile);
#elif defined (ACE_WIN32)
  FILETIME   tfile;
  ::GetSystemTimeAsFileTime (&tfile);
  return ACE_Time_Value (tfile);
#if 0
  // From Todd Montgomery...
  struct _timeb tb;
  ::_ftime (&tb);
  tv.tv_sec = tb.time;
  tv.tv_usec = 1000 * tb.millitm;
#endif /* 0 */
#elif defined (ACE_HAS_AIX_HI_RES_TIMER)
  timebasestruct_t tb;

  ::read_real_time (&tb, TIMEBASE_SZ);
  ::time_base_to_time (&tb, TIMEBASE_SZ);

  tv.tv_sec = tb.tb_high;
  tv.tv_usec = tb.tb_low / 1000L;
#else
# if defined (ACE_HAS_TIMEZONE_GETTIMEOFDAY) || \
  (defined (ACE_HAS_SVR4_GETTIMEOFDAY) && !defined (m88k) && !defined (SCO))
  ACE_OSCALL (::gettimeofday (&tv, 0), int, -1, result);
# elif defined (VXWORKS) || defined (CHORUS) || defined (ACE_PSOS)
  // Assumes that struct timespec is same size as struct timeval,
  // which assumes that time_t is a long: it currently (VxWorks
  // 5.2/5.3) is.
  struct timespec ts;

  ACE_OSCALL (ACE_OS::clock_gettime (CLOCK_REALTIME, &ts), int, -1, result);
  tv.tv_sec = ts.tv_sec;
  tv.tv_usec = ts.tv_nsec / 1000L;  // timespec has nsec, but timeval has usec
# else
  ACE_OSCALL (::gettimeofday (&tv), int, -1, result);
# endif /* ACE_HAS_SVR4_GETTIMEOFDAY */
#endif /* ACE_WIN32 */
  if (result == -1)
    return -1;
  else
    return ACE_Time_Value (tv);
}

ACE_INLINE int
ACE_OS::stat (const ACE_TCHAR *file, struct stat *stp)
{
  ACE_TRACE ("ACE_OS::stat");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_stat (file, stp), int, -1);
#elif defined (VXWORKS)
  ACE_OSCALL_RETURN (::stat ((char *) file, stp), int, -1);
#elif defined (ACE_PSOS_LACKS_PHILE)
  ACE_UNUSED_ARG (file);
  ACE_UNUSED_ARG (stp);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_PSOS)
  ACE_OSCALL_RETURN (::stat_f ((char *) file, stp), int, -1);
#elif defined (ACE_HAS_WINCE)
  ACE_TEXT_WIN32_FIND_DATA fdata;

  HANDLE fhandle;

  fhandle = ::FindFirstFile (file, &fdata);
  if (fhandle == INVALID_HANDLE_VALUE)
    {
      ACE_OS::set_errno_to_last_error ();
      return -1;
    }
  else if (fdata.nFileSizeHigh != 0)
    {
      errno = EINVAL;
      return -1;
    }
  else
    {
      stp->st_size = fdata.nFileSizeLow;
      stp->st_atime = ACE_Time_Value (fdata.ftLastAccessTime);
      stp->st_mtime = ACE_Time_Value (fdata.ftLastWriteTime);
    }
  return 0;
#elif defined (ACE_HAS_X86_STAT_MACROS)
   // Solaris for intel uses an macro for stat(), this macro is a
   // wrapper for _xstat().
  ACE_OSCALL_RETURN (::_xstat (_STAT_VER, file, stp), int, -1);
#elif defined (__BORLANDC__)  && (__BORLANDC__ <= 0x540) && defined (ACE_USES_WCHAR)
  ACE_OSCALL_RETURN (::_wstat (file, stp), int, -1);
#elif defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
  ACE_OSCALL_RETURN (::_wstat (file, (struct _stat *) stp), int, -1);
#else /* VXWORKS */
  ACE_OSCALL_RETURN (::stat (file, stp), int, -1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE time_t
ACE_OS::time (time_t *tloc)
{
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_time (tloc), time_t, (time_t) -1);
#elif !defined (ACE_HAS_WINCE)
  ACE_TRACE ("ACE_OS::time");
#  if defined (ACE_PSOS) && ! defined (ACE_PSOS_HAS_TIME)
        unsigned long d_date, d_time, d_tick;
        tm_get(&d_date, &d_time, &d_tick); // get current time
        if (tloc)
                *tloc = d_time; // set time as time_t
        return d_time;
#  else
  ACE_OSCALL_RETURN (::time (tloc), time_t, (time_t) -1);
#  endif /* ACE_PSOS && ! ACE_PSOS_HAS_TIME */
#else
  time_t retv = ACE_OS::gettimeofday ().sec ();
  if (tloc)
    *tloc = retv;
  return retv;
#endif /* ACE_HAS_PACE */
}

ACE_INLINE void
ACE_OS::srand (u_int seed)
{
  ACE_TRACE ("ACE_OS::srand");
#if defined (ACE_HAS_PACE)
  pace_srand (seed);
#else
  ::srand (seed);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::rand (void)
{
  ACE_TRACE ("ACE_OS::rand");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_rand (), int, -1);
#else
  ACE_OSCALL_RETURN (::rand (), int, -1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::unlink (const ACE_TCHAR *path)
{
  ACE_TRACE ("ACE_OS::unlink");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_unlink (path), int, -1);
# elif defined (VXWORKS)
    ACE_OSCALL_RETURN (::unlink (ACE_const_cast (char *, path)), int, -1);
# elif defined (ACE_PSOS) && ! defined (ACE_PSOS_LACKS_PHILE)
    ACE_OSCALL_RETURN (::remove_f ((char *) path), int , -1);
# elif defined (ACE_PSOS) && defined (ACE_PSOS_HAS_C_LIBRARY)
    ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::remove ((char *) path),
                                                   ace_result_),
                       int, -1);
# elif defined (ACE_HAS_WINCE)
  // @@ The problem is, DeleteFile is not actually equals to unlink. ;(
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::DeleteFile (path), ace_result_),
                        int, -1);
# elif defined (ACE_LACKS_UNLINK)
    ACE_UNUSED_ARG (path);
    ACE_NOTSUP_RETURN (-1);
# elif defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
  ACE_OSCALL_RETURN (::_wunlink (path), int, -1);
# else
  ACE_OSCALL_RETURN (::unlink (path), int, -1);
# endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::rename (const ACE_TCHAR *old_name,
                const ACE_TCHAR *new_name,
                int flags)
{
#if (ACE_HAS_PACE)
  ACE_UNUSED_ARG (flags);
  ACE_OSCALL_RETURN (pace_rename (old_name, new_name), int, -1);
# elif (ACE_LACKS_RENAME)
  ACE_UNUSED_ARG (old_name);
  ACE_UNUSED_ARG (new_name);
  ACE_UNUSED_ARG (flags);
  ACE_NOTSUP_RETURN (-1);
# elif defined (ACE_HAS_WINCE)
  ACE_UNUSED_ARG (flags);
  // *** this looks wrong... should be???
  //  if (MoveFile (old_name, new_name) != 0)
  //    ACE_FAIL_RETURN (-1);
  //  return 0;
  ACE_OSCALL_RETURN (::MoveFile (new_name, old_name), int, -1);
# elif defined (ACE_WIN32)&& defined (ACE_HAS_WINNT4)
  // NT4 (and up) provides a way to rename/move a file with similar semantics
  // to what's usually done on UNIX - if there's an existing file with
  // <new_name> it is removed before the file is renamed/moved. The
  // MOVEFILE_COPY_ALLOWED is specified to allow such a rename across drives.
  if (flags == -1)
    flags = MOVEFILE_COPY_ALLOWED | MOVEFILE_REPLACE_EXISTING;
  if (::MoveFileEx(old_name, new_name, flags) == 0)
    ACE_FAIL_RETURN (-1);
  return 0;
# elif defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
  ACE_UNUSED_ARG (flags);
  ACE_OSCALL_RETURN (::_wrename (old_name, new_name), int, -1);
# else /* ACE_LACKS_RENAME */
  ACE_UNUSED_ARG (flags);
  ACE_OSCALL_RETURN (::rename (old_name, new_name), int, -1);
# endif /* ACE_HAS_PACE */
}

ACE_INLINE ACE_TCHAR *
ACE_OS::tempnam (const ACE_TCHAR *dir, const ACE_TCHAR *pfx)
{
  ACE_TRACE ("ACE_OS::tempnam");
#if defined (VXWORKS) || defined (ACE_HAS_WINCE) || defined (ACE_LACKS_TEMPNAM)
  ACE_UNUSED_ARG (dir);
  ACE_UNUSED_ARG (pfx);
  ACE_NOTSUP_RETURN (0);
#elif defined (ACE_PSOS)
  // pSOS only considers the directory prefix
  ACE_UNUSED_ARG (pfx);
  ACE_OSCALL_RETURN (::tmpnam ((char *) dir), char *, 0);
#elif defined (__BORLANDC__) || (defined (ACE_WIN32) && defined (__IBMCPP__))
  ACE_OSCALL_RETURN (::_tempnam ((char *) dir, (char *) pfx), char *, 0);
#elif defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
  ACE_OSCALL_RETURN (::_wtempnam (dir, pfx), wchar_t *, 0);
#else /* VXWORKS */
  ACE_OSCALL_RETURN (::tempnam (dir, pfx), char *, 0);
#endif /* VXWORKS */
}

ACE_INLINE ACE_HANDLE
ACE_OS::shm_open (const ACE_TCHAR *filename,
                  int mode,
                  int perms,
                  LPSECURITY_ATTRIBUTES sa)
{
  ACE_TRACE ("ACE_OS::shm_open");
#if defined (ACE_HAS_PACE)
  ACE_UNUSED_ARG (sa);
  ACE_OSCALL_RETURN (pace_shm_open (filename, mode, perms), ACE_HANDLE, -1);
# elif defined (ACE_HAS_SHM_OPEN)
  ACE_UNUSED_ARG (sa);
  ACE_OSCALL_RETURN (::shm_open (filename, mode, perms), ACE_HANDLE, -1);
# else  /* ! ACE_HAS_SHM_OPEN */
  // Just use ::open.
  return ACE_OS::open (filename, mode, perms, sa);
# endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::shm_unlink (const ACE_TCHAR *path)
{
  ACE_TRACE ("ACE_OS::shm_unlink");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_shm_unlink (path), int, -1);
# elif defined (ACE_HAS_SHM_OPEN)
  ACE_OSCALL_RETURN (::shm_unlink (path), int, -1);
# else  /* ! ACE_HAS_SHM_OPEN */
  // Just use ::unlink.
  return ACE_OS::unlink (path);
# endif /* ACE_HAS_PACE */
}

ACE_INLINE ACE_TCHAR *
ACE_OS::cuserid (ACE_TCHAR *user, size_t maxlen)
{
  ACE_TRACE ("ACE_OS::cuserid");
#if defined (VXWORKS)
  ACE_UNUSED_ARG (maxlen);
  if (user == 0)
    {
      // Require that the user field be non-null, i.e., don't
      // allocate or use static storage.
      ACE_NOTSUP_RETURN (0);
    }
  else
    {
      ::remCurIdGet (user, 0);
      return user;
    }
#elif defined (CHORUS) || defined (ACE_HAS_WINCE) || defined (ACE_PSOS) || defined (__QNXNTO__)
  // @@ WinCE doesn't support GetUserName.  But there should be a way
  // to get around this.
  ACE_UNUSED_ARG (user);
  ACE_UNUSED_ARG (maxlen);
  ACE_NOTSUP_RETURN (0);
#elif defined (ACE_WIN32)
  BOOL result = ACE_TEXT_GetUserName (user, (u_long *) &maxlen);
  if (result == FALSE)
    ACE_FAIL_RETURN (0);
  else
    return user;
#elif defined (ACE_HAS_ALT_CUSERID)
#  if defined (ACE_LACKS_PWD_FUNCTIONS)
#    error Cannot use alternate cuserid() without POSIX password functions!
#  endif  /* ACE_LACKS_PWD_FUNCTIONS */

  // POSIX.1 dropped the cuserid() function.
  // GNU GLIBC and other platforms correctly deprecate the cuserid()
  // function.

  struct passwd *pw = 0;

  // Make sure the file pointer is at the beginning of the password file
  ::setpwent ();
  // Should use ACE_OS::setpwent() but I didn't want to move this
  // method after it.

  // Use the effective user ID to determine the user name.
  pw = ::getpwuid (::geteuid ());

  // Make sure the password file is closed.
  ::endpwent ();

  // Extract the user name from the passwd structure.
  if (::strlen (pw->pw_name) <= maxlen)
    return ::strcpy (user, pw->pw_name);
  else
    return 0;
#else
  // Hackish because of missing buffer size!
  ACE_UNUSED_ARG (maxlen);
  ACE_OSCALL_RETURN (::cuserid (user), char *, 0);
#endif /* VXWORKS */
}

ACE_INLINE int
ACE_OS::atexit (ACE_EXIT_HOOK func)
{
  return ACE_OS_Object_Manager::instance ()->at_exit (func);
}

// Doesn't need a macro since it *never* returns!

ACE_INLINE void
ACE_OS::_exit (int status)
{
  ACE_TRACE ("ACE_OS::_exit");
#if defined (ACE_HAS_PACE)
  pace_exit (status);
#elif defined (VXWORKS)
  ::exit (status);
#elif defined (ACE_PSOSIM)
  ::u_exit (status);
#elif defined (ACE_PSOS)
# if defined (ACE_PSOS_LACKS_PREPC)  /* pSoS TM does not support exit. */
  ACE_UNUSED_ARG (status);
  return;
# else
  ::exit (status);
# endif /* defined (ACE_PSOS_LACKS_PREPC) */
#elif !defined (ACE_HAS_WINCE)
  ::_exit (status);
#else
  ::TerminateProcess (::GetCurrentProcess (),
                      status);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE void
ACE_OS::abort (void)
{
#if defined (ACE_HAS_PACE)
  pace_abort ();
#elif !defined (ACE_HAS_WINCE)
  ::abort ();
#else
  // @@ CE doesn't support abort?
  exit (1);
#endif /* ACE_HAS_PACE */
}

#if !defined (ACE_HAS_WINCE)
ACE_INLINE int
ACE_OS::vsprintf (char *buffer, const char *format, va_list argptr)
{
  return ACE_SPRINTF_ADAPTER (::vsprintf (buffer, format, argptr));
}
#endif /* ACE_HAS_WINCE */

#if defined (ACE_HAS_WCHAR)
ACE_INLINE int
ACE_OS::vsprintf (wchar_t *buffer, const wchar_t *format, va_list argptr)
{
  return ::vswprintf (buffer, format, argptr);
}
#endif /* ACE_HAS_WCHAR */


ACE_INLINE long
ACE_OS::sysconf (int name)
{
  ACE_TRACE ("ACE_OS::sysconf");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_sysconf (name), long, -1);
#elif defined (ACE_WIN32) || defined (VXWORKS) || defined (ACE_PSOS)
  ACE_UNUSED_ARG (name);
  ACE_NOTSUP_RETURN (-1);
#else
  ACE_OSCALL_RETURN (::sysconf (name), long, -1);
#endif /* ACE_HAS_PACE*/
}

ACE_INLINE int
ACE_OS::mutex_init (ACE_mutex_t *m,
                    int type,
                    const ACE_TCHAR *name,
                    ACE_mutexattr_t *attributes,
                    LPSECURITY_ATTRIBUTES sa)
{
  // ACE_TRACE ("ACE_OS::mutex_init");
#if defined (ACE_HAS_PACE)
  pthread_mutexattr_t l_attributes;
  if (attributes == 0)
    attributes = &l_attributes;
  int result = -1;

  // Only do these initializations if the <attributes> parameter
  // wasn't originally set.
  if (attributes == &l_attributes)
  {
    if (pace_pthread_mutexattr_init (attributes) == 0)
      result = 0;
    else
      result = -1;        // ACE_ADAPT_RETVAL used it for intermediate status
  }

  if (result == 0)
  {
    if (
#     if defined (_POSIX_THREAD_PROCESS_SHARED)
        pace_pthread_mutexattr_setpshared (attributes, type) == 0 &&
#     endif /* _POSIX_THREAD_PROCESS_SHARED */
        pace_pthread_mutex_init (m, attributes) == 0)
      result = 0;
    else
      result = -1;        // ACE_ADAPT_RETVAL used it for intermediate status
  }
  ACE_UNUSED_ARG (sa);
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (type);

  // Only do the deletions if the <attributes> parameter wasn't
  // originally set.
  if (attributes == &l_attributes)
    pace_pthread_mutexattr_destroy (&l_attributes);

  return result;

#elif defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_PTHREADS)
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (attributes);
  ACE_UNUSED_ARG (sa);

  pthread_mutexattr_t l_attributes;
  if (attributes == 0)
    attributes = &l_attributes;
  int result = -1;

  // Only do these initializations if the <attributes> parameter
  // wasn't originally set.
  if (attributes == &l_attributes)
    {
#   if defined (ACE_HAS_PTHREADS_DRAFT4)
      if (::pthread_mutexattr_create (attributes) == 0)
#   elif defined (ACE_HAS_PTHREADS_DRAFT7) || defined (ACE_HAS_PTHREADS_STD)
      if (ACE_ADAPT_RETVAL (::pthread_mutexattr_init (attributes), result) == 0)
#   else /* draft 6 */
      if (::pthread_mutexattr_init (attributes) == 0)
#   endif /* ACE_HAS_PTHREADS_DRAFT4 */
        result = 0;
      else
        result = -1;        // ACE_ADAPT_RETVAL used it for intermediate status
    }

  if (result == 0)
    {
#   if defined (ACE_HAS_PTHREADS_DRAFT4)
      if (
#     if defined (ACE_HAS_PTHREAD_MUTEXATTR_SETKIND_NP)
          ::pthread_mutexattr_setkind_np (attributes, type) == 0 &&
#     endif /* ACE_HAS_PTHREAD_MUTEXATTR_SETKIND_NP */
          ::pthread_mutex_init (m, *attributes) == 0)
#   elif defined (ACE_HAS_PTHREADS_DRAFT7) || defined (ACE_HAS_PTHREADS_STD)
      if (
#     if defined (_POSIX_THREAD_PROCESS_SHARED) && !defined (ACE_LACKS_MUTEXATTR_PSHARED)
           ACE_ADAPT_RETVAL (::pthread_mutexattr_setpshared (attributes, type),
                             result) == 0 &&
#     endif /* _POSIX_THREAD_PROCESS_SHARED && ! ACE_LACKS_MUTEXATTR_PSHARED */
           ACE_ADAPT_RETVAL (::pthread_mutex_init (m, attributes), result) == 0)
#   else
        if (
#     if !defined (ACE_LACKS_MUTEXATTR_PSHARED)
            ::pthread_mutexattr_setpshared (attributes, type) == 0 &&
#     endif /* ACE_LACKS_MUTEXATTR_PSHARED */
#     if defined (ACE_HAS_PTHREAD_MUTEXATTR_SETKIND_NP)
            ::pthread_mutexattr_setkind_np (attributes, type) == 0 &&
#     endif /* ACE_HAS_PTHREAD_MUTEXATTR_SETKIND_NP */
            ::pthread_mutex_init (m, attributes) == 0)
#   endif /* ACE_HAS_PTHREADS_DRAFT4 */
        result = 0;
      else
        result = -1;        // ACE_ADAPT_RETVAL used it for intermediate status
    }

#   if (!defined (ACE_HAS_PTHREAD_MUTEXATTR_SETKIND_NP) && !defined (_POSIX_THREAD_PROCESS_SHARED)  ||  defined (ACE_LACKS_MUTEXATTR_PSHARED))
  ACE_UNUSED_ARG (type);
#   endif /* ! ACE_HAS_PTHREAD_MUTEXATTR_SETKIND_NP */

  // Only do the deletions if the <attributes> parameter wasn't
  // originally set.
  if (attributes == &l_attributes)
#   if defined (ACE_HAS_PTHREADS_DRAFT4)
    ::pthread_mutexattr_delete (&l_attributes);
#   else
    ::pthread_mutexattr_destroy (&l_attributes);
#   endif /* ACE_HAS_PTHREADS_DRAFT4 */

  return result;
# elif defined (ACE_HAS_STHREADS)
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (sa);
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::mutex_init (m, type, attributes),
                                       ace_result_),
                     int, -1);
# elif defined (ACE_HAS_WTHREADS)
  m->type_ = type;

  switch (type)
    {
    case USYNC_PROCESS:
      m->proc_mutex_ = ACE_TEXT_CreateMutex (ACE_OS::default_win32_security_attributes (sa),
                                             FALSE,
                                             name);
      if (m->proc_mutex_ == 0)
        ACE_FAIL_RETURN (-1);
      else
        return 0;
    case USYNC_THREAD:
      return ACE_OS::thread_mutex_init (&m->thr_mutex_,
                                        type,
                                        name,
                                        attributes);
    default:
      errno = EINVAL;
      return -1;
    }
  /* NOTREACHED */

# elif defined (ACE_PSOS)
  ACE_UNUSED_ARG (type);
  ACE_UNUSED_ARG (attributes);
  ACE_UNUSED_ARG (sa);
#   if defined (ACE_PSOS_HAS_MUTEX)

    u_long flags = MU_LOCAL;
    u_long ceiling = 0;

#     if defined (ACE_HAS_RECURSIVE_MUTEXES)
    flags |= MU_RECURSIVE;
#     else /* ! ACE_HAS_RECURSIVE_MUTEXES */
    flags |= MU_NONRECURSIVE;
#     endif /* ACE_HAS_RECURSIVE_MUTEXES */

#     if defined (ACE_PSOS_HAS_PRIO_MUTEX)

    flags |= MU_PRIOR;

#       if defined (ACE_PSOS_HAS_PRIO_INHERIT_MUTEX)
    flags |= MU_PRIO_INHERIT;
#       elif defined (ACE_PSOS_HAS_PRIO_PROTECT_MUTEX)
    ceiling =  PSOS_TASK_MAX_PRIORITY;
    flags |= MU_PRIO_PROTECT;
#       else
    flags |= MU_PRIO_NONE;
#       endif /* ACE_PSOS_HAS_PRIO_INHERIT_MUTEX */

#     else /* ! ACE_PSOS_HAS_PRIO_MUTEX */

    flags |= MU_FIFO | MU_PRIO_NONE;

#     endif

    // Fake a pSOS name - it can be any 4-byte value, not necessarily needing
    // to be ASCII. So use the mutex pointer passed in. That should identify
    // each one uniquely.
    union { ACE_mutex_t *p; char n[4]; } m_name;
    m_name.p = m;

    ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::mu_create (m_name.n,
                                                      flags,
                                                      ceiling,
                                                      m),
                                         ace_result_),
                       int, -1);

#   else /* ! ACE_PSOS_HAS_MUTEX */
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::sm_create ((char *) name,
                                                    1,
                                                    SM_LOCAL | SM_PRIOR,
                                                    m),
                                       ace_result_),
                     int, -1);
#   endif /* ACE_PSOS_HAS_MUTEX */
# elif defined (VXWORKS)
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (attributes);
  ACE_UNUSED_ARG (sa);

  return (*m = ::semMCreate (type)) == 0 ? -1 : 0;
# endif /* ACE_HAS_PTHREADS */
#else
  ACE_UNUSED_ARG (m);
  ACE_UNUSED_ARG (type);
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (attributes);
  ACE_UNUSED_ARG (sa);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::mutex_destroy (ACE_mutex_t *m)
{
  ACE_TRACE ("ACE_OS::mutex_destroy");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pace_pthread_mutex_destroy (m),
                                       ace_result_), int, -1);
#elif defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_PTHREADS)
#   if (defined (ACE_HAS_PTHREADS_DRAFT4) || defined (ACE_HAS_PTHREADS_DRAFT6))
  ACE_OSCALL_RETURN (::pthread_mutex_destroy (m), int, -1);
#   else
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::pthread_mutex_destroy (m),
                                       ace_result_), int, -1);
#   endif /* ACE_HAS_PTHREADS_DRAFT4 || ACE_HAS_PTHREADS_DRAFT6*/
# elif defined (ACE_HAS_STHREADS)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::mutex_destroy (m), ace_result_), int, -1);
# elif defined (ACE_HAS_WTHREADS)
  switch (m->type_)
    {
    case USYNC_PROCESS:
      ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::CloseHandle (m->proc_mutex_),
                                              ace_result_),
                            int, -1);
    case USYNC_THREAD:
      return ACE_OS::thread_mutex_destroy (&m->thr_mutex_);
    default:
      errno = EINVAL;
      return -1;
    }
  /* NOTREACHED */
# elif defined (ACE_PSOS)
#   if defined (ACE_PSOS_HAS_MUTEX)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::mu_delete (*m), ace_result_),
                     int, -1);
#   else /* ! ACE_PSOS_HAS_MUTEX */
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::sm_delete (*m), ace_result_),
                     int, -1);
#   endif /* ACE_PSOS_HAS_MUTEX */
# elif defined (VXWORKS)
  return ::semDelete (*m) == OK ? 0 : -1;
# endif /* Threads variety case */
#else
  ACE_UNUSED_ARG (m);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::mutex_lock (ACE_mutex_t *m)
{
  // ACE_TRACE ("ACE_OS::mutex_lock");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pace_pthread_mutex_lock (m),
                                       ace_result_), int, -1);;
#elif defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_PTHREADS)
  // Note, don't use "::" here since the following call is often a macro.
#   if (defined (ACE_HAS_PTHREADS_DRAFT4) || defined (ACE_HAS_PTHREADS_DRAFT6))
  ACE_OSCALL_RETURN (pthread_mutex_lock (m), int, -1);
#   else
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pthread_mutex_lock (m), ace_result_),
                     int, -1);
#   endif /* ACE_HAS_PTHREADS_DRAFT4 || ACE_HAS_PTHREADS_DRAFT6 */
# elif defined (ACE_HAS_STHREADS)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::mutex_lock (m), ace_result_), int, -1);
# elif defined (ACE_HAS_WTHREADS)
  switch (m->type_)
    {
    case USYNC_PROCESS:
      // Timeout can't occur, so don't bother checking...

      switch (::WaitForSingleObject (m->proc_mutex_, INFINITE))
        {
        case WAIT_OBJECT_0:
        case WAIT_ABANDONED:
          // We will ignore abandonments in this method
          // Note that we still hold the lock
          return 0;
        default:
          // This is a hack, we need to find an appropriate mapping...
          ACE_OS::set_errno_to_last_error ();
          return -1;
        }
    case USYNC_THREAD:
      return ACE_OS::thread_mutex_lock (&m->thr_mutex_);
    default:
      errno = EINVAL;
      return -1;
    }
  /* NOTREACHED */
# elif defined (ACE_PSOS)
#   if defined (ACE_PSOS_HAS_MUTEX)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::mu_lock (*m, MU_WAIT, 0),
                                       ace_result_),
                     int, -1);
#   else /* ACE_PSOS_HAS_MUTEX */
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::sm_p (*m, SM_WAIT, 0),
                                       ace_result_),
                     int, -1);
#   endif /* ACE_PSOS_HAS_MUTEX */
# elif defined (VXWORKS)
  return ::semTake (*m, WAIT_FOREVER) == OK ? 0 : -1;
# endif /* Threads variety case */
#else
  ACE_UNUSED_ARG (m);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::mutex_lock (ACE_mutex_t *m,
                    int &abandoned)
{
  ACE_TRACE ("ACE_OS::mutex_lock");
#if defined (ACE_HAS_THREADS) && defined (ACE_HAS_WTHREADS)
  abandoned = 0;
  switch (m->type_)
    {
    case USYNC_PROCESS:
      // Timeout can't occur, so don't bother checking...

      switch (::WaitForSingleObject (m->proc_mutex_, INFINITE))
        {
        case WAIT_OBJECT_0:
          return 0;
        case WAIT_ABANDONED:
          abandoned = 1;
          return 0;  // something goofed, but we hold the lock ...
        default:
          // This is a hack, we need to find an appropriate mapping...
          ACE_OS::set_errno_to_last_error ();
          return -1;
        }
    case USYNC_THREAD:
      return ACE_OS::thread_mutex_lock (&m->thr_mutex_);
    default:
      errno = EINVAL;
      return -1;
    }
  /* NOTREACHED */
#else
  ACE_UNUSED_ARG (m);
  ACE_UNUSED_ARG (abandoned);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS and ACE_HAS_WTHREADS */
}

ACE_INLINE int
ACE_OS::mutex_trylock (ACE_mutex_t *m)
{
  ACE_TRACE ("ACE_OS::mutex_trylock");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pace_pthread_mutex_trylock (m),
                                       ace_result_), int, -1);
#elif defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_PTHREADS)
  // Note, don't use "::" here since the following call is often a macro.
#   if (defined (ACE_HAS_PTHREADS_DRAFT4) || defined (ACE_HAS_PTHREADS_DRAFT6))
  int status = pthread_mutex_trylock (m);
  if (status == 1)
    status = 0;
  else if (status == 0) {
    status = -1;
    errno = EBUSY;
  }
  return status;
#   else
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pthread_mutex_trylock (m), ace_result_),
                     int, -1);
#   endif /* ACE_HAS_PTHREADS_DRAFT4 || ACE_HAS_PTHREADS_DRAFT6 */
# elif defined (ACE_HAS_STHREADS)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::mutex_trylock (m), ace_result_), int, -1);
# elif defined (ACE_HAS_WTHREADS)
  switch (m->type_)
    {
    case USYNC_PROCESS:
      {
        // Try for 0 milliseconds - i.e. nonblocking.
        switch (::WaitForSingleObject (m->proc_mutex_, 0))
          {
          case WAIT_OBJECT_0:
            return 0;
          case WAIT_ABANDONED:
            // We will ignore abandonments in this method.  Note that
            // we still hold the lock.
            return 0;
          case WAIT_TIMEOUT:
            errno = EBUSY;
            return -1;
          default:
            ACE_OS::set_errno_to_last_error ();
            return -1;
          }
      }
    case USYNC_THREAD:
      return ACE_OS::thread_mutex_trylock (&m->thr_mutex_);
    default:
      errno = EINVAL;
      return -1;
    }
  /* NOTREACHED */
# elif defined (ACE_PSOS)
#   if defined (ACE_PSOS_HAS_MUTEX)
   ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::mu_lock (*m, MU_NOWAIT, 0),
                                        ace_result_),
                      int, -1);
#   else /* ! ACE_PSOS_HAS_MUTEX */
   switch (::sm_p (*m, SM_NOWAIT, 0))
   {
     case 0:
       return 0;
     case ERR_NOSEM:
       errno = EBUSY;
       // intentional fall through
     default:
       return -1;
   }
#   endif /* ACE_PSOS_HAS_MUTEX */

# elif defined (VXWORKS)
  if (::semTake (*m, NO_WAIT) == ERROR)
    if (errno == S_objLib_OBJ_TIMEOUT)
      {
        // couldn't get the semaphore
        errno = EBUSY;
        return -1;
      }
    else
      // error
      return -1;
  else
    // got the semaphore
    return 0;
# endif /* Threads variety case */
#else
  ACE_UNUSED_ARG (m);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::mutex_trylock (ACE_mutex_t *m, int &abandoned)
{
#if defined (ACE_HAS_THREADS) && defined (ACE_HAS_WTHREADS)
  abandoned = 0;
  switch (m->type_)
    {
    case USYNC_PROCESS:
      {
        // Try for 0 milliseconds - i.e. nonblocking.
        switch (::WaitForSingleObject (m->proc_mutex_, 0))
          {
          case WAIT_OBJECT_0:
            return 0;
          case WAIT_ABANDONED:
            abandoned = 1;
            return 0;  // something goofed, but we hold the lock ...
          case WAIT_TIMEOUT:
            errno = EBUSY;
            return -1;
          default:
            ACE_OS::set_errno_to_last_error ();
            return -1;
          }
      }
    case USYNC_THREAD:
      return ACE_OS::thread_mutex_trylock (&m->thr_mutex_);
    default:
      errno = EINVAL;
      return -1;
    }
  /* NOTREACHED */
#else
  ACE_UNUSED_ARG (m);
  ACE_UNUSED_ARG (abandoned);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS and ACE_HAS_WTHREADS */
}

ACE_INLINE int
ACE_OS::mutex_unlock (ACE_mutex_t *m)
{
  ACE_TRACE ("ACE_OS::mutex_unlock");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pace_pthread_mutex_unlock (m),
                                       ace_result_), int, -1);
#elif defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_PTHREADS)
  // Note, don't use "::" here since the following call is often a macro.
#   if (defined (ACE_HAS_PTHREADS_DRAFT4) || defined (ACE_HAS_PTHREADS_DRAFT6))
  ACE_OSCALL_RETURN (pthread_mutex_unlock (m), int, -1);
#   else
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pthread_mutex_unlock (m), ace_result_),
                     int, -1);
#   endif /* ACE_HAS_PTHREADS_DRAFT4 || ACE_HAS_PTHREADS_DRAFT6 */
# elif defined (ACE_HAS_STHREADS)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::mutex_unlock (m), ace_result_), int, -1);
# elif defined (ACE_HAS_WTHREADS)
  switch (m->type_)
    {
    case USYNC_PROCESS:
      ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::ReleaseMutex (m->proc_mutex_),
                                              ace_result_),
                            int, -1);
    case USYNC_THREAD:
      return ACE_OS::thread_mutex_unlock (&m->thr_mutex_);
    default:
      errno = EINVAL;
      return -1;
    }
  /* NOTREACHED */
# elif defined (ACE_PSOS)
#   if defined (ACE_PSOS_HAS_MUTEX)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::mu_unlock (*m), ace_result_),
                     int, -1);
#   else /* ! ACE_PSOS_HAS_MUTEX */
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::sm_v (*m), ace_result_),
                     int, -1);
#   endif /* ACE_PSOS_HAS_MUTEX */
# elif defined (VXWORKS)
  return ::semGive (*m) == OK ? 0 : -1;
# endif /* Threads variety case */
#else
  ACE_UNUSED_ARG (m);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::thread_mutex_init (ACE_thread_mutex_t *m,
                           int type,
                           const ACE_TCHAR *name,
                           ACE_mutexattr_t *arg)
{
  // ACE_TRACE ("ACE_OS::thread_mutex_init");
#if defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_STHREADS) || defined (ACE_HAS_PTHREADS) || defined (ACE_HAS_PACE)
  ACE_UNUSED_ARG (type);
  // Force the use of USYNC_THREAD!
  return ACE_OS::mutex_init (m, USYNC_THREAD, name, arg);
# elif defined (ACE_HAS_WTHREADS)
  ACE_UNUSED_ARG (type);
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (arg);

  ::InitializeCriticalSection (m);
  return 0;
# elif defined (VXWORKS) || defined (ACE_PSOS)
  return mutex_init (m, type, name, arg);
# endif /* Threads variety case */
#else
  ACE_UNUSED_ARG (m);
  ACE_UNUSED_ARG (type);
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (arg);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS */
}

ACE_INLINE int
ACE_OS::thread_mutex_destroy (ACE_thread_mutex_t *m)
{
  ACE_TRACE ("ACE_OS::thread_mutex_destroy");
#if defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_STHREADS) || defined (ACE_HAS_PTHREADS) || defined (ACE_HAS_PACE)
  return ACE_OS::mutex_destroy (m);
# elif defined (ACE_HAS_WTHREADS)
  ::DeleteCriticalSection (m);
  return 0;
# elif defined (VXWORKS) || defined (ACE_PSOS)
  return mutex_destroy (m);
# endif /* ACE_HAS_STHREADS || ACE_HAS_PTHREADS */
#else
  ACE_UNUSED_ARG (m);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS */
}

ACE_INLINE int
ACE_OS::thread_mutex_lock (ACE_thread_mutex_t *m)
{
  // ACE_TRACE ("ACE_OS::thread_mutex_lock");
#if defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_STHREADS) || defined (ACE_HAS_PTHREADS) || defined (ACE_HAS_PACE)
  return ACE_OS::mutex_lock (m);
# elif defined (ACE_HAS_WTHREADS)
  ::EnterCriticalSection (m);
  return 0;
#elif defined (VXWORKS) || defined (ACE_PSOS)
  return mutex_lock (m);
# endif /* ACE_HAS_STHREADS || ACE_HAS_PTHREADS */
#else
  ACE_UNUSED_ARG (m);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS */
}

ACE_INLINE int
ACE_OS::thread_mutex_trylock (ACE_thread_mutex_t *m)
{
  ACE_TRACE ("ACE_OS::thread_mutex_trylock");
#if defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_STHREADS) || defined (ACE_HAS_PTHREADS) || defined (ACE_HAS_PACE)
  return ACE_OS::mutex_trylock (m);
# elif defined (ACE_HAS_WTHREADS)
#   if defined (ACE_HAS_WIN32_TRYLOCK)
  BOOL result = ::TryEnterCriticalSection (m);
  if (result == TRUE)
    return 0;
  else
    {
      errno = EBUSY;
      return -1;
    }
#   else
  ACE_UNUSED_ARG (m);
  ACE_NOTSUP_RETURN (-1);
#   endif /* ACE_HAS_WIN32_TRYLOCK */
# elif defined (VXWORKS) || defined (ACE_PSOS)
  return ACE_OS::mutex_trylock (m);
# endif /* Threads variety case */
#else
  ACE_UNUSED_ARG (m);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS */
}

ACE_INLINE int
ACE_OS::thread_mutex_unlock (ACE_thread_mutex_t *m)
{
  ACE_TRACE ("ACE_OS::thread_mutex_unlock");
#if defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_STHREADS) || defined (ACE_HAS_PTHREADS) || defined (ACE_HAS_PACE)
  return ACE_OS::mutex_unlock (m);
# elif defined (ACE_HAS_WTHREADS)
  ::LeaveCriticalSection (m);
  return 0;
# elif defined (VXWORKS) || defined (ACE_PSOS)
  return ACE_OS::mutex_unlock (m);
# endif /* Threads variety case */
#else
  ACE_UNUSED_ARG (m);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS */
}

#if !defined (ACE_LACKS_COND_T)
// NOTE: The ACE_OS::cond_* functions for Unix platforms are defined
// here because the ACE_OS::sema_* functions below need them.
// However, ACE_WIN32 and VXWORKS define the ACE_OS::cond_* functions
// using the ACE_OS::sema_* functions.  So, they are defined in OS.cpp.

ACE_INLINE int
ACE_OS::cond_destroy (ACE_cond_t *cv)
{
  ACE_TRACE ("ACE_OS::cond_destroy");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pace_pthread_cond_destroy (cv),
                                       ace_result_), int, -1);
# elif defined (ACE_HAS_THREADS)
#   if defined (ACE_HAS_PTHREADS)
#     if defined (ACE_HAS_PTHREADS_DRAFT4) || defined (ACE_HAS_PTHREADS_DRAFT6)
  ACE_OSCALL_RETURN (::pthread_cond_destroy (cv), int, -1);
#     else
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::pthread_cond_destroy (cv), ace_result_), int, -1);
#     endif /* ACE_HAS_PTHREADS_DRAFT4 || ACE_HAS_PTHREADS_DRAFT6 */
#   elif defined (ACE_HAS_STHREADS)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::cond_destroy (cv), ace_result_), int, -1);
#   elif defined (ACE_PSOS) && defined (ACE_PSOS_HAS_COND_T)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::cv_delete (*cv), ace_result_),
                     int, -1);
#   endif /* ACE_HAS_STHREADS */
# else
  ACE_UNUSED_ARG (cv);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::condattr_init (ACE_condattr_t &attributes,
                       int type)
{
  ACE_UNUSED_ARG (type);
#if defined (ACE_HAS_PACE)
  int result = -1;

  if (pace_pthread_condattr_init (&attributes) == 0
# if defined (_POSIX_THREAD_PROCESS_SHARED)
      && pace_pthread_condattr_setpshared(&attributes, type) == 0
# endif /* _POSIX_THREAD_PROCESS_SHARED */
      )
    result = 0;
  else
    result = -1;       // ACE_ADAPT_RETVAL used it for intermediate status

  return result;

# elif defined (ACE_HAS_THREADS) && ! defined (__MACOSX__)
#   if defined (ACE_HAS_PTHREADS)
  int result = -1;

  if (
#     if defined  (ACE_HAS_PTHREADS_DRAFT4)
      ::pthread_condattr_create (&attributes) == 0
#     elif defined (ACE_HAS_PTHREADS_STD) || defined (ACE_HAS_PTHREADS_DRAFT7)
      ACE_ADAPT_RETVAL(::pthread_condattr_init (&attributes), result) == 0
#       if defined (_POSIX_THREAD_PROCESS_SHARED) && !defined (ACE_LACKS_MUTEXATTR_PSHARED)
      && ACE_ADAPT_RETVAL(::pthread_condattr_setpshared(&attributes, type),
                          result) == 0
#       endif /* _POSIX_THREAD_PROCESS_SHARED && ! ACE_LACKS_MUTEXATTR_PSHARED */
#     else  /* this is draft 6 */
      ::pthread_condattr_init (&attributes) == 0
#       if !defined (ACE_LACKS_CONDATTR_PSHARED)
      && ::pthread_condattr_setpshared (&attributes, type) == 0
#       endif /* ACE_LACKS_CONDATTR_PSHARED */
#       if defined (ACE_HAS_PTHREAD_CONDATTR_SETKIND_NP)
      && ::pthread_condattr_setkind_np (&attributes, type) == 0
#       endif /* ACE_HAS_PTHREAD_CONDATTR_SETKIND_NP */
#     endif /* ACE_HAS_PTHREADS_DRAFT4 */
      )
     result = 0;
  else
     result = -1;       // ACE_ADAPT_RETVAL used it for intermediate status

  return result;
#   elif defined (ACE_HAS_STHREADS)
  attributes.type = type;

  return 0;

#   elif defined (ACE_PSOS) && defined (ACE_PSOS_HAS_COND_T)
#     if defined (ACE_PSOS_HAS_PRIO_MUTEX)
  attributes = CV_LOCAL | CV_PRIOR;
#     else /* ACE_PSOS_HAS_PRIO_MUTEX */
  attributes = CV_LOCAL | CV_FIFO;
#     endif /* ACE_PSOS_HAS_PRIO_MUTEX */
  return 0;

#   else
  ACE_UNUSED_ARG (attributes);
  ACE_UNUSED_ARG (type);
  ACE_NOTSUP_RETURN (-1);

#   endif /* ACE_HAS_PTHREADS vs. ACE_HAS_STHREADS vs. pSOS */

# elif defined (__MACOSX__)
  ACE_UNUSED_ARG (attributes);
  ACE_UNUSED_ARG (type);
  return 0;

#else
  ACE_UNUSED_ARG (attributes);
  ACE_UNUSED_ARG (type);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::condattr_destroy (ACE_condattr_t &attributes)
{
#if defined (ACE_HAS_PACE)
  return pace_pthread_condattr_destroy (&attributes);
# elif defined (ACE_HAS_THREADS) && ! defined (__MACOSX__)
#   if defined (ACE_HAS_PTHREADS)

#     if defined (ACE_HAS_PTHREADS_DRAFT4)
  ::pthread_condattr_delete (&attributes);
#     else
  ::pthread_condattr_destroy (&attributes);
#     endif /* ACE_HAS_PTHREADS_DRAFT4 */

#   elif defined (ACE_HAS_STHREADS)
  attributes.type = 0;

#   elif defined (ACE_PSOS) && defined (ACE_PSOS_HAS_COND_T)
  attributes = 0;

#   endif /* ACE_HAS_PTHREADS vs. ACE_HAS_STHREADS vs. ACE_PSOS */
  return 0;
# else
  ACE_UNUSED_ARG (attributes);
  return 0;
# endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::cond_init (ACE_cond_t *cv,
                   ACE_condattr_t &attributes,
                   const ACE_TCHAR *name,
                   void *arg)
{
  // ACE_TRACE ("ACE_OS::cond_init");
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (arg);
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pace_pthread_cond_init (cv, &attributes),
                                       ace_result_), int, -1);
# elif defined (ACE_HAS_THREADS)
#   if defined (ACE_HAS_PTHREADS)
  int result = -1;

  if (
#     if defined  (ACE_HAS_PTHREADS_DRAFT4)
      ::pthread_cond_init (cv, attributes) == 0
#     elif defined (ACE_HAS_PTHREADS_STD) || defined (ACE_HAS_PTHREADS_DRAFT7)
      ACE_ADAPT_RETVAL(::pthread_cond_init (cv, &attributes), result) == 0
#     else  /* this is draft 6 */
      ::pthread_cond_init (cv, &attributes) == 0
#     endif /* ACE_HAS_PTHREADS_DRAFT4 */
      )
     result = 0;
  else
     result = -1;       // ACE_ADAPT_RETVAL used it for intermediate status

  return result;
#   elif defined (ACE_HAS_STHREADS)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::cond_init (cv,
                                                    attributes.type,
                                                    arg),
                                       ace_result_),
                     int, -1);
#   elif defined (ACE_PSOS) && defined (ACE_PSOS_HAS_COND_T)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::cv_create (ACE_const_cast (char *, name),
                                                    attributes,
                                                    cv),
                                       ace_result_),
                     int, -1);
#   endif /* ACE_HAS_PTHREADS vs. ACE_HAS_STHREADS vs. ACE_PSOS */
# else
  ACE_UNUSED_ARG (cv);
  ACE_UNUSED_ARG (attributes);
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (arg);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::cond_init (ACE_cond_t *cv, short type, const ACE_TCHAR *name, void *arg)
{
  ACE_condattr_t attributes;
  if (ACE_OS::condattr_init (attributes, type) == 0
      && ACE_OS::cond_init (cv, attributes, name, arg) == 0)
    {
      (void) ACE_OS::condattr_destroy (attributes);
      return 0;
    }
  return -1;
}

ACE_INLINE int
ACE_OS::cond_signal (ACE_cond_t *cv)
{
ACE_TRACE ("ACE_OS::cond_signal");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_pthread_cond_signal (cv), int, -1);
# elif defined (ACE_HAS_THREADS)
#   if defined (ACE_HAS_PTHREADS)
#     if defined (ACE_HAS_PTHREADS_DRAFT4) || defined (ACE_HAS_PTHREADS_DRAFT6)
  ACE_OSCALL_RETURN (::pthread_cond_signal (cv), int, -1);
#     else
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::pthread_cond_signal (cv),ace_result_),
                     int, -1);
#     endif /* ACE_HAS_PTHREADS_DRAFT4 || ACE_HAS_PTHREADS_DRAFT6 */
#   elif defined (ACE_HAS_STHREADS)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::cond_signal (cv), ace_result_), int, -1);
#   elif defined (ACE_PSOS) && defined (ACE_PSOS_HAS_COND_T)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::cv_signal (*cv), ace_result_),
                     int, -1);
#   endif /* ACE_HAS_STHREADS */
# else
  ACE_UNUSED_ARG (cv);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::cond_broadcast (ACE_cond_t *cv)
{
ACE_TRACE ("ACE_OS::cond_broadcast");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_pthread_cond_broadcast (cv), int, -1);
# elif defined (ACE_HAS_THREADS)
#   if defined (ACE_HAS_PTHREADS)
#     if defined (ACE_HAS_PTHREADS_DRAFT4) || defined (ACE_HAS_PTHREADS_DRAFT6)
  ACE_OSCALL_RETURN (::pthread_cond_broadcast (cv), int, -1);
#     else
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::pthread_cond_broadcast (cv),
                                       ace_result_),
                     int, -1);
#     endif /* ACE_HAS_PTHREADS_DRAFT4 || ACE_HAS_PTHREADS_DRAFT6 */
#   elif defined (ACE_HAS_STHREADS)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::cond_broadcast (cv),
                                       ace_result_),
                     int, -1);
#   elif defined (ACE_PSOS) && defined (ACE_PSOS_HAS_COND_T)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::cv_broadcast (*cv), ace_result_),
                     int, -1);
#   endif /* ACE_HAS_STHREADS */
# else
  ACE_UNUSED_ARG (cv);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::cond_wait (ACE_cond_t *cv,
                   ACE_mutex_t *external_mutex)
{
  ACE_TRACE ("ACE_OS::cond_wait");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_pthread_cond_wait (cv, external_mutex), int, -1);
# elif defined (ACE_HAS_THREADS)
#   if defined (ACE_HAS_PTHREADS)
#     if defined (ACE_HAS_PTHREADS_DRAFT4) || defined (ACE_HAS_PTHREADS_DRAFT6)
  ACE_OSCALL_RETURN (::pthread_cond_wait (cv, external_mutex), int, -1);
#     else
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::pthread_cond_wait (cv, external_mutex), ace_result_),
                     int, -1);
#     endif /* ACE_HAS_PTHREADS_DRAFT4 || ACE_HAS_PTHREADS_DRAFT6 */
#   elif defined (ACE_HAS_STHREADS)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::cond_wait (cv, external_mutex), ace_result_),
                     int, -1);
#   elif defined (ACE_PSOS) && defined (ACE_PSOS_HAS_COND_T)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::cv_wait (*cv, *external_mutex, 0),
                                       ace_result_),
                     int, -1);
#   endif /* ACE_HAS_PTHREADS */
# else
  ACE_UNUSED_ARG (cv);
  ACE_UNUSED_ARG (external_mutex);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::cond_timedwait (ACE_cond_t *cv,
                        ACE_mutex_t *external_mutex,
                        ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_OS::cond_timedwait");
#if defined (ACE_HAS_PACE)
  int result;
  timespec_t ts;

  if (timeout != 0)
    ts = *timeout; // Calls ACE_Time_Value::operator timespec_t().
  timeout == 0 ? (result = pace_pthread_cond_wait (cv, external_mutex)) :
                 (result = pace_pthread_cond_timedwait (cv, external_mutex, (ACE_TIMESPEC_PTR) &ts));

  // We need to adjust this to make the POSIX and Solaris return
  // values consistent.  EAGAIN is from Pthreads DRAFT4 (HP-UX 10.20 and
  // down); EINTR is from LynxOS.
  if (result == -1 &&
      (errno == ETIMEDOUT || errno == EAGAIN || errno == EINTR))
    errno = ETIME;

  if (timeout != 0)
    timeout->set (ts); // Update the time value before returning.

  return result;

# elif defined (ACE_HAS_THREADS)
  int result;
  timespec_t ts;

  if (timeout != 0)
    ts = *timeout; // Calls ACE_Time_Value::operator timespec_t().

#   if defined (ACE_HAS_PTHREADS)

#     if defined (ACE_HAS_PTHREADS_DRAFT4) || defined (ACE_HAS_PTHREADS_DRAFT6)
  if (timeout == 0)
    ACE_OSCALL (::pthread_cond_wait (cv, external_mutex),
                int, -1, result);
  else
    {

#     if defined (__Lynx__)
      // Note that we must convert between absolute time (which is
      // passed as a parameter) and relative time (which is what the
      // LynxOS pthread_cond_timedwait expects).  This differs from 1003.4a
      // draft 4.

      timespec_t relative_time = *timeout - ACE_OS::gettimeofday ();

      ACE_OSCALL (::pthread_cond_timedwait (cv, external_mutex,
                                            &relative_time),
                  int, -1, result);
#     else
      ACE_OSCALL (::pthread_cond_timedwait (cv, external_mutex,
                                            (ACE_TIMESPEC_PTR) &ts),
                  int, -1, result);
#     endif /* __Lynx__ */
    }

#     else
  ACE_OSCALL (ACE_ADAPT_RETVAL (timeout == 0
                                ? ::pthread_cond_wait (cv, external_mutex)
                                : ::pthread_cond_timedwait (cv, external_mutex,
                                                            (ACE_TIMESPEC_PTR) &ts),
                                result),
              int, -1, result);
#     endif /* ACE_HAS_PTHREADS_DRAFT4 || ACE_HAS_PTHREADS_DRAFT6*/
  // We need to adjust this to make the POSIX and Solaris return
  // values consistent.  EAGAIN is from Pthreads DRAFT4 (HP-UX 10.20 and
  // down); EINTR is from LynxOS.
  if (result == -1 &&
      (errno == ETIMEDOUT || errno == EAGAIN || errno == EINTR))
    errno = ETIME;

#   elif defined (ACE_HAS_STHREADS)
  ACE_OSCALL (ACE_ADAPT_RETVAL (timeout == 0
                                ? ::cond_wait (cv, external_mutex)
                                : ::cond_timedwait (cv,
                                                    external_mutex,
                                                    (timestruc_t*)&ts),
                                result),
              int, -1, result);
#   elif defined (ACE_PSOS) && defined (ACE_PSOS_HAS_COND_T)
  // pSOS condition value timeout is expressed in ticks. If the
  // cv_wait times out, the mutex is unlocked upon return.
  if (timeout == 0)
    {
      ACE_OSCALL (ACE_ADAPT_RETVAL (::cv_wait (*cv, *external_mutex, 0),
                                    result),
                  int, -1, result);
    }
  else
    {
      // Need to convert the passed absolute time to relative time
      // expressed in ticks.
      ACE_Time_Value relative_time (*timeout - ACE_OS::gettimeofday ());
      int ticks = (relative_time.sec () * KC_TICKS2SEC) +
                  (relative_time.usec () * KC_TICKS2SEC /
                   ACE_ONE_SECOND_IN_USECS);
      if (ticks <= 0)
        ticks = 1;    // Don't wait forever
      ACE_OSCALL (ACE_ADAPT_RETVAL (::cv_wait (*cv, *external_mutex, ticks),
                                    result),
                  int, -1, result);
      if (result == -1 && errno == 1)
        {
          // cv timed out and returned pSOS timeout error 0x01, which
          // ACE_ADAPT_RETVAL stored in errno.
          ::mu_lock (*external_mutex, MU_WAIT, 0);
          errno = ETIME;
        }
    }

  return result;

#   endif /* ACE_HAS_STHREADS */
  if (timeout != 0)
    timeout->set (ts); // Update the time value before returning.

  return result;
# else
  ACE_UNUSED_ARG (cv);
  ACE_UNUSED_ARG (external_mutex);
  ACE_UNUSED_ARG (timeout);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_PACE */
}
#endif /* !ACE_LACKS_COND_T */

ACE_INLINE int
ACE_OS::thr_equal (ACE_thread_t t1, ACE_thread_t t2)
{
#if defined (ACE_HAS_PACE)
  return pace_pthread_equal (t1, t2);
#elif defined (ACE_HAS_PTHREADS)
# if defined (pthread_equal)
  // If it's a macro we can't say "::pthread_equal"...
  return pthread_equal (t1, t2);
# else
  return ::pthread_equal (t1, t2);
# endif /* pthread_equal */
#elif defined (VXWORKS)
  return ! ACE_OS::strcmp (t1, t2);
#else /* For both STHREADS and WTHREADS... */
  // Hum, Do we need to treat WTHREAD differently?
  // levine 13 oct 98 % I don't think so, ACE_thread_t is a DWORD.
  return t1 == t2;
#endif /* ACE_HAS_PACE */
}

ACE_INLINE void
ACE_OS::thr_self (ACE_hthread_t &self)
{
  ACE_TRACE ("ACE_OS::thr_self");
#if defined (ACE_HAS_PACE)
  self = pace_pthread_self ();
#elif defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_PTHREADS)
  // Note, don't use "::" here since the following call is often a macro.
  self = pthread_self ();
# elif defined (ACE_HAS_THREAD_SELF)
  self = ::thread_self ();
# elif defined (ACE_HAS_STHREADS)
  self = ::thr_self ();
# elif defined (ACE_HAS_WTHREADS)
  self = ::GetCurrentThread ();
# elif defined (ACE_PSOS)
  t_ident ((char *) 0, 0, &self);
# elif defined (VXWORKS)
  self = ::taskIdSelf ();
# endif /* ACE_HAS_STHREADS */
#else
  self = 1; // Might as well make it the main thread ;-)
#endif /* ACE_HAS_PACE */
}

ACE_INLINE ACE_thread_t
ACE_OS::thr_self (void)
{
  // ACE_TRACE ("ACE_OS::thr_self");
#if defined (ACE_HAS_PACE)
  return pace_pthread_self ();
#elif defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_PTHREADS)
  // Note, don't use "::" here since the following call is often a macro.
  ACE_OSCALL_RETURN (pthread_self (), int, -1);
# elif defined (ACE_HAS_STHREADS)
  ACE_OSCALL_RETURN (::thr_self (), int, -1);
# elif defined (ACE_HAS_WTHREADS)
  return ::GetCurrentThreadId ();
# elif defined (ACE_PSOS)
  // there does not appear to be a way to get
  // a task's name other than at creation
  return 0;
# elif defined (VXWORKS)
  return ::taskName (::taskIdSelf ());
# endif /* ACE_HAS_STHREADS */
#else
  return 1; // Might as well make it the first thread ;-)
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::recursive_mutex_init (ACE_recursive_thread_mutex_t *m,
                              const ACE_TCHAR *name,
                              ACE_mutexattr_t *arg,
                              LPSECURITY_ATTRIBUTES sa)
{
  ACE_UNUSED_ARG (sa);
#if defined (ACE_HAS_THREADS)
#if defined (ACE_HAS_RECURSIVE_MUTEXES)
  return ACE_OS::thread_mutex_init (m, 0, name, arg);
#else
  if (ACE_OS::thread_mutex_init (&m->nesting_mutex_, 0, name, arg) == -1)
    return -1;
  else if (ACE_OS::cond_init (&m->lock_available_,
                              (short) USYNC_THREAD,
                              name,
                              0) == -1)
    return -1;
  else
    {
      m->nesting_level_ = 0;
      m->owner_id_ = ACE_OS::NULL_thread;
      return 0;
    }
#endif /* ACE_HAS_RECURSIVE_MUTEXES */
#else
  ACE_UNUSED_ARG (m);
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (arg);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS */
}

ACE_INLINE int
ACE_OS::recursive_mutex_destroy (ACE_recursive_thread_mutex_t *m)
{
#if defined (ACE_HAS_THREADS)
#if defined (ACE_HAS_RECURSIVE_MUTEXES)
  return ACE_OS::thread_mutex_destroy (m);
#else
  if (ACE_OS::thread_mutex_destroy (&m->nesting_mutex_) == -1)
    return -1;
  else if (ACE_OS::cond_destroy (&m->lock_available_) == -1)
    return -1;
  else
    return 0;
#endif /* ACE_HAS_RECURSIVE_MUTEXES */
#else
  ACE_UNUSED_ARG (m);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS */
}

ACE_INLINE int
ACE_OS::recursive_mutex_lock (ACE_recursive_thread_mutex_t *m)
{
#if defined (ACE_HAS_THREADS)
#if defined (ACE_HAS_RECURSIVE_MUTEXES)
  return ACE_OS::thread_mutex_lock (m);
#else
  ACE_thread_t t_id = ACE_OS::thr_self ();
  int result = 0;

  // Acquire the guard.
  if (ACE_OS::thread_mutex_lock (&m->nesting_mutex_) == -1)
    result = -1;
  else
    {
      // If there's no contention, just grab the lock immediately
      // (since this is the common case we'll optimize for it).
      if (m->nesting_level_ == 0)
        m->owner_id_ = t_id;
      // If we already own the lock, then increment the nesting level
      // and return.
      else if (ACE_OS::thr_equal (t_id, m->owner_id_) == 0)
        {
          // Wait until the nesting level has dropped to zero, at
          // which point we can acquire the lock.
          while (m->nesting_level_ > 0)
            ACE_OS::cond_wait (&m->lock_available_,
                               &m->nesting_mutex_);

              // At this point the nesting_mutex_ is held...
              m->owner_id_ = t_id;
        }

      // At this point, we can safely increment the nesting_level_ no
      // matter how we got here!
      m->nesting_level_++;
    }

  {
    // Save/restore errno.
    ACE_Errno_Guard error (errno);
    ACE_OS::thread_mutex_unlock (&m->nesting_mutex_);
  }
  return result;
#endif /* ACE_HAS_RECURSIVE_MUTEXES */
#else
  ACE_UNUSED_ARG (m);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS */
}

ACE_INLINE int
ACE_OS::recursive_mutex_trylock (ACE_recursive_thread_mutex_t *m)
{
#if defined (ACE_HAS_THREADS)
#if defined (ACE_HAS_RECURSIVE_MUTEXES)
  return ACE_OS::thread_mutex_trylock (m);
#else
  ACE_thread_t t_id = ACE_OS::thr_self ();
  int result = 0;

  // Acquire the guard.
  if (ACE_OS::thread_mutex_lock (&m->nesting_mutex_) == -1)
    result = -1;
  else
    {
      // If there's no contention, just grab the lock immediately.
      if (m->nesting_level_ == 0)
        {
          m->owner_id_ = t_id;
          m->nesting_level_ = 1;
        }
      // If we already own the lock, then increment the nesting level
      // and proceed.
      else if (ACE_OS::thr_equal (t_id, m->owner_id_))
        m->nesting_level_++;
      else
        {
          errno = EBUSY;
          result = -1;
        }
    }

  {
    // Save/restore errno.
    ACE_Errno_Guard error (errno);
    ACE_OS::thread_mutex_unlock (&m->nesting_mutex_);
  }
  return result;
#endif /* ACE_HAS_RECURSIVE_MUTEXES */
#else
  ACE_UNUSED_ARG (m);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS */
}

ACE_INLINE int
ACE_OS::recursive_mutex_unlock (ACE_recursive_thread_mutex_t *m)
{
#if defined (ACE_HAS_THREADS)
#if defined (ACE_HAS_RECURSIVE_MUTEXES)
  return ACE_OS::thread_mutex_unlock (m);
#else
ACE_TRACE ("ACE_Recursive_Thread_Mutex::release");
#if !defined (ACE_NDEBUG)
  ACE_thread_t t_id = ACE_OS::thr_self ();
#endif /* ACE_NDEBUG */
  int result = 0;

  if (ACE_OS::thread_mutex_lock (&m->nesting_mutex_) == -1)
    result = -1;
  else
    {
#if !defined (ACE_NDEBUG)
      if (m->nesting_level_ == 0
          || ACE_OS::thr_equal (t_id, m->owner_id_) == 0)
        {
          errno = EINVAL;
          result = -1;
        }
      else
#endif /* ACE_NDEBUG */
        {
          m->nesting_level_--;
          if (m->nesting_level_ == 0)
            {
              // This may not be strictly necessary, but it does put
              // the mutex into a known state...
              m->owner_id_ = ACE_OS::NULL_thread;

              // Inform waiters that the lock is free.
              if (ACE_OS::cond_signal (&m->lock_available_) == -1)
                result = -1;
            }
        }
    }

  {
    // Save/restore errno.
    ACE_Errno_Guard error (errno);
    ACE_OS::thread_mutex_unlock (&m->nesting_mutex_);
  }
  return result;
#endif /* ACE_HAS_RECURSIVE_MUTEXES */
#else
  ACE_UNUSED_ARG (m);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS */
}

ACE_INLINE int
ACE_OS::sema_destroy (ACE_sema_t *s)
{
  ACE_TRACE ("ACE_OS::sema_destroy");
#if defined (ACE_HAS_PACE)
  int result;
  if (s->name_)
  {
    result = pace_sem_unlink (s->name_);
    pace_free ((void *) s->name_);
    return pace_sem_close (s->sema_);
  }
  else
  {
    result = pace_sem_destroy (s->sema_);
    delete s->sema_;
    s->sema_ = 0;
    return result;
  }
# elif defined (ACE_HAS_POSIX_SEM)
  int result;
#   if defined (ACE_LACKS_NAMED_POSIX_SEM)
  if (s->name_)
    {
      // Only destroy the semaphore if we're the ones who
      // initialized it.
      ACE_OSCALL (::sem_destroy (s->sema_),int, -1, result);
      ACE_OS::shm_unlink (s->name_);
      delete s->name_;
      return result;
    }
#else
  if (s->name_)
    {
      ACE_OSCALL (::sem_unlink (s->name_), int, -1, result);
      ACE_OS::free ((void *) s->name_);
      ACE_OSCALL_RETURN (::sem_close (s->sema_), int, -1);
    }
#   endif /*  ACE_LACKS_NAMED_POSIX_SEM */
  else
    {
      ACE_OSCALL (::sem_destroy (s->sema_), int, -1, result);
      delete s->sema_;
      s->sema_ = 0;
      return result;
    }
# elif defined (ACE_HAS_THREADS)
#   if defined (ACE_HAS_STHREADS)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::sema_destroy (s), ace_result_), int, -1);
#   elif defined (ACE_HAS_PTHREADS)
  int r1 = ACE_OS::mutex_destroy (&s->lock_);
  int r2 = ACE_OS::cond_destroy (&s->count_nonzero_);
  return r1 != 0 || r2 != 0 ? -1 : 0;
#   elif defined (ACE_HAS_WTHREADS)
#     if !defined (ACE_USES_WINCE_SEMA_SIMULATION)
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::CloseHandle (*s), ace_result_), int, -1);
#     else /* ACE_USES_WINCE_SEMA_SIMULATION */
  // Free up underlying objects of the simulated semaphore.
  int r1 = ACE_OS::thread_mutex_destroy (&s->lock_);
  int r2 = ACE_OS::event_destroy (&s->count_nonzero_);
  return r1 != 0 || r2 != 0 ? -1 : 0;
#     endif /* ACE_USES_WINCE_SEMA_SIMULATION */
#   elif defined (ACE_PSOS)
  int result;
  ACE_OSCALL (ACE_ADAPT_RETVAL (::sm_delete (s->sema_), result), int, -1, result);
  s->sema_ = 0;
  return result;
#   elif defined (VXWORKS)
  int result;
  ACE_OSCALL (::semDelete (s->sema_), int, -1, result);
  s->sema_ = 0;
  return result;
#   endif /* ACE_HAS_STHREADS */
# else
  ACE_UNUSED_ARG (s);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_PACE */
}

// NOTE: The following four function definitions must appear before
// ACE_OS::sema_init ().

ACE_INLINE int
ACE_OS::close (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_OS::close");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_close (handle), int, -1);
#elif defined (ACE_WIN32)
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::CloseHandle (handle), ace_result_), int, -1);
#elif defined (ACE_PSOS) && ! defined (ACE_PSOS_LACKS_PHILE)
  u_long result = ::close_f (handle);
  if (result != 0)
    {
      errno = result;
      return ACE_static_cast (int, -1);
    }
  return ACE_static_cast (int, 0);
#else
  ACE_OSCALL_RETURN (::close (handle), int, -1);
#endif /* ACE_HAS_PACE */
}

// This function returns the number of bytes in the file referenced by
// FD.

ACE_INLINE long
ACE_OS::filesize (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_OS::filesize");
#if defined (ACE_WIN32)
  ACE_WIN32CALL_RETURN (::GetFileSize (handle, NULL), long, -1);
#else /* !ACE_WIN32 */
  struct stat sb;
  return ACE_OS::fstat (handle, &sb) == -1 ? -1 : (long) sb.st_size;
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::ftruncate (ACE_HANDLE handle, off_t offset)
{
  ACE_TRACE ("ACE_OS::ftruncate");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_ftruncate (handle, offset), int, -1);
#elif defined (ACE_WIN32)
  if (::SetFilePointer (handle, offset, NULL, FILE_BEGIN) != (unsigned) -1)
    ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::SetEndOfFile (handle), ace_result_), int, -1);
  else
    ACE_FAIL_RETURN (-1);
  /* NOTREACHED */
#elif defined (ACE_PSOS_LACKS_PHILE)
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (offset);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_PSOS)
  ACE_OSCALL_RETURN (::ftruncate_f (handle, offset), int, -1);
#else
  ACE_OSCALL_RETURN (::ftruncate (handle, offset), int, -1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE void *
ACE_OS::mmap (void *addr,
              size_t len,
              int prot,
              int flags,
              ACE_HANDLE file_handle,
              off_t off,
              ACE_HANDLE *file_mapping,
              LPSECURITY_ATTRIBUTES sa)
{
  ACE_TRACE ("ACE_OS::mmap");
#if defined (ACE_HAS_PACE)
  ACE_UNUSED_ARG (file_mapping);
  ACE_UNUSED_ARG (sa);
  ACE_OSCALL_RETURN ((void *) pace_mmap (addr,
                                         len,
                                         prot,
                                         flags,
                                         file_handle,
                                         off),
                     void *, MAP_FAILED);

#elif defined (ACE_WIN32) && !defined (ACE_HAS_PHARLAP)
  int nt_flags = 0;
  ACE_HANDLE local_handle = ACE_INVALID_HANDLE;

  // Ensure that file_mapping is non-zero.
  if (file_mapping == 0)
    file_mapping = &local_handle;

  if (ACE_BIT_ENABLED (flags, MAP_PRIVATE))
    {
      prot = PAGE_WRITECOPY;
      nt_flags = FILE_MAP_COPY;
    }
  else if (ACE_BIT_ENABLED (flags, MAP_SHARED))
    {
      if (ACE_BIT_ENABLED (prot, PAGE_READONLY))
        nt_flags = FILE_MAP_READ;
      if (ACE_BIT_ENABLED (prot, PAGE_READWRITE))
        nt_flags = FILE_MAP_WRITE;
    }

  // Only create a new handle if we didn't have a valid one passed in.
  if (*file_mapping == ACE_INVALID_HANDLE)
    *file_mapping = ::CreateFileMapping (file_handle,
                                         ACE_OS::default_win32_security_attributes (sa),
                                         prot,
                                         0,
                                         0,
                                         0);
  if (*file_mapping == 0)
    ACE_FAIL_RETURN (MAP_FAILED);

# if defined (ACE_OS_EXTRA_MMAP_FLAGS)
  nt_flags |= ACE_OS_EXTRA_MMAP_FLAGS;
# endif /* ACE_OS_EXTRA_MMAP_FLAGS */

# if !defined (ACE_HAS_WINCE)
  void *addr_mapping = ::MapViewOfFileEx (*file_mapping,
                                          nt_flags,
                                          0,
                                          off,
                                          len,
                                          addr);
# else
  ACE_UNUSED_ARG (addr);        // WinCE doesn't allow specifying <addr>.
  void *addr_mapping = ::MapViewOfFile (*file_mapping,
                                        nt_flags,
                                        0,
                                        off,
                                        len);
# endif /* ! ACE_HAS_WINCE */

  // Only close this down if we used the temporary.
  if (file_mapping == &local_handle)
    ::CloseHandle (*file_mapping);

  if (addr_mapping == 0)
    ACE_FAIL_RETURN (MAP_FAILED);

  else if (ACE_BIT_ENABLED (flags, MAP_FIXED)
           && addr_mapping != addr)
    {
      errno = EINVAL;
      return MAP_FAILED;
    }
  else
    return addr_mapping;
#elif defined (__Lynx__)
  // The LynxOS 2.5.0 mmap doesn't allow operations on plain
  // file descriptors.  So, create a shm object and use that.
  ACE_UNUSED_ARG (sa);

  char name [128];
  sprintf (name, "%d", file_handle);

  // Assumes that this was called by ACE_Mem_Map, so &file_mapping != 0.
  // Otherwise, we don't support the incomplete LynxOS mmap implementation.
  // We do support it by creating a hidden shared memory object, and using
  // that for the mapping.
  int shm_handle;
  if (! file_mapping)
    file_mapping = &shm_handle;
  if ((*file_mapping = ::shm_open (name,
                                   O_RDWR | O_CREAT | O_TRUNC,
                                   ACE_DEFAULT_FILE_PERMS)) == -1)
    return MAP_FAILED;
  else
    {
      // The size of the shared memory object must be explicitly set on LynxOS.
      const off_t filesize = ACE_OS::filesize (file_handle);
      if (::ftruncate (*file_mapping, filesize) == -1)
        return MAP_FAILED;
      else
        {
# if defined (ACE_OS_EXTRA_MMAP_FLAGS)
          flags |= ACE_OS_EXTRA_MMAP_FLAGS;
# endif /* ACE_OS_EXTRA_MMAP_FLAGS */
          char *map = (char *) ::mmap ((ACE_MMAP_TYPE) addr,
                                       len,
                                       prot,
                                       flags,
                                       *file_mapping,
                                       off);
          if (map == MAP_FAILED)
            return MAP_FAILED;
          else
            // Finally, copy the file contents to the shared memory object.
            return ::read (file_handle, map, (int) filesize) == filesize
              ? map
              : MAP_FAILED;
        }
    }
#elif !defined (ACE_LACKS_MMAP)
  ACE_UNUSED_ARG (sa);

# if defined (ACE_OS_EXTRA_MMAP_FLAGS)
  flags |= ACE_OS_EXTRA_MMAP_FLAGS;
# endif /* ACE_OS_EXTRA_MMAP_FLAGS */
  ACE_UNUSED_ARG (file_mapping);
  ACE_OSCALL_RETURN ((void *) ::mmap ((ACE_MMAP_TYPE) addr,
                                      len,
                                      prot,
                                      flags,
                                      file_handle,
                                      off),
                     void *, MAP_FAILED);
#else
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (len);
  ACE_UNUSED_ARG (prot);
  ACE_UNUSED_ARG (flags);
  ACE_UNUSED_ARG (file_handle);
  ACE_UNUSED_ARG (off);
  ACE_UNUSED_ARG (file_mapping);
  ACE_UNUSED_ARG (sa);
  ACE_NOTSUP_RETURN (MAP_FAILED);
#endif /*ACE_HAS_PACE */
}

// NOTE: The previous four function definitions must appear before
// ACE_OS::sema_init ().

ACE_INLINE int
ACE_OS::sema_init (ACE_sema_t *s,
                   u_int count,
                   int type,
                   const ACE_TCHAR *name,
                   void *arg,
                   int max,
                   LPSECURITY_ATTRIBUTES sa)
{
  ACE_TRACE ("ACE_OS::sema_init");
#if defined (ACE_HAS_PACE)
  ACE_UNUSED_ARG (arg);
  ACE_UNUSED_ARG (max);
  ACE_UNUSED_ARG (sa);
  if (name)
  {
    ACE_ALLOCATOR_RETURN (s->name_,
                          ACE_OS::strdup (name),
                          -1);
    s->sema_ = pace_sem_open (s->name_,
                              O_CREAT,
                              ACE_DEFAULT_FILE_PERMS,
                              count);
    if (s->sema_ == (sem_t *) SEM_FAILED)
      return -1;
    else
      return 0;
  }
  else
  {
    ACE_NEW_RETURN (s->sema_, sem_t, -1);
    ACE_OSCALL_RETURN (pace_sem_init (s->sema_,
                                      type != USYNC_THREAD,
                                      count), int, -1);
  }
# elif defined (ACE_HAS_POSIX_SEM)
  ACE_UNUSED_ARG (arg);
  ACE_UNUSED_ARG (max);
  ACE_UNUSED_ARG (sa);

  s->name_ = 0;

#   if defined (ACE_LACKS_NAMED_POSIX_SEM)
  if (type == USYNC_PROCESS)
    {
      // Let's see if it already exists.
      ACE_HANDLE fd = ACE_OS::shm_open (name,
                                        O_RDWR | O_CREAT | O_EXCL,
                                        ACE_DEFAULT_FILE_PERMS);
      if (fd == ACE_INVALID_HANDLE)
        {
          if (errno == EEXIST)
            fd = ACE_OS::shm_open (name,
                                   O_RDWR | O_CREAT,
                                   ACE_DEFAULT_FILE_PERMS);
          else
            return -1;
        }
      else
        {
          // We own this shared memory object!  Let's set its
          // size.
          if (ACE_OS::ftruncate (fd,
                                 sizeof (ACE_sema_t)) == -1)
            return -1;
          s->name_ = ACE_OS::strdup (name);
          if (s->name_ == 0)
            return -1;
        }
      if (fd == -1)
        return -1;

      s->sema_ = (sem_t *)
        ACE_OS::mmap (0,
                      sizeof (ACE_sema_t),
                      PROT_RDWR,
                      MAP_SHARED,
                      fd,
                      0);
      ACE_OS::close (fd);
      if (s->sema_ == (sem_t *) MAP_FAILED)
        return -1;
      if (s->name_
          // @@ According UNIX Network Programming V2 by Stevens,
          //    sem_init() is currently not required to return zero on
          //    success, but it *does* return -1 upon failure.  For
          //    this reason, check for failure by comparing to -1,
          //    instead of checking for success by comparing to zero.
          //        -Ossama
          // Only initialize it if we're the one who created it.
          && ::sem_init (s->sema_, type == USYNC_PROCESS, count) == -1)
        return -1;
      return 0;
    }
#else
  if (name)
    {
      ACE_ALLOCATOR_RETURN (s->name_,
                            ACE_OS::strdup (name),
                            -1);
      s->sema_ = ::sem_open (s->name_,
                             O_CREAT,
                             ACE_DEFAULT_FILE_PERMS,
                             count);
      if (s->sema_ == (sem_t *) SEM_FAILED)
        return -1;
      else
        return 0;
    }
#   endif /* ACE_LACKS_NAMED_POSIX_SEM */
  else
    {
      ACE_NEW_RETURN (s->sema_,
                      sem_t,
                      -1);
      ACE_OSCALL_RETURN (::sem_init (s->sema_,
                                     type != USYNC_THREAD,
                                     count), int, -1);
    }
# elif defined (ACE_HAS_THREADS)
#   if defined (ACE_HAS_STHREADS)
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (max);
  ACE_UNUSED_ARG (sa);
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::sema_init (s, count, type, arg), ace_result_),
                     int, -1);
#   elif defined (ACE_HAS_PTHREADS)
  ACE_UNUSED_ARG (max);
  ACE_UNUSED_ARG (sa);
  int result = -1;

  if (ACE_OS::mutex_init (&s->lock_, type, name,
                          (ACE_mutexattr_t *) arg) == 0
      && ACE_OS::cond_init (&s->count_nonzero_, type, name, arg) == 0
      && ACE_OS::mutex_lock (&s->lock_) == 0)
    {
      s->count_ = count;
      s->waiters_ = 0;

      if (ACE_OS::mutex_unlock (&s->lock_) == 0)
        result = 0;
    }

  if (result == -1)
    {
      ACE_OS::mutex_destroy (&s->lock_);
      ACE_OS::cond_destroy (&s->count_nonzero_);
    }
  return result;
#   elif defined (ACE_HAS_WTHREADS)
#     if ! defined (ACE_USES_WINCE_SEMA_SIMULATION)
  ACE_UNUSED_ARG (type);
  ACE_UNUSED_ARG (arg);
  // Create the semaphore with its value initialized to <count> and
  // its maximum value initialized to <max>.
  *s =
    ACE_TEXT_CreateSemaphore (ACE_OS::default_win32_security_attributes (sa),
                              count,
                              max,
                              name);

  if (*s == 0)
    ACE_FAIL_RETURN (-1);
  /* NOTREACHED */
  else
    return 0;
#     else /* ACE_USES_WINCE_SEMA_SIMULATION */
  int result = -1;

  // Initialize internal object for semaphore simulation.
  // Grab the lock as soon as possible when we initializing
  // the semaphore count.  Notice that we initialize the
  // event object as "manually reset" so we can amortize the
  // cost for singling/reseting the event.
  // @@ I changed the mutex type to thread_mutex.  Notice that this
  // is basically a CriticalSection object and doesn't not has
  // any security attribute whatsoever.  However, since this
  // semaphore implementation only works within a process, there
  // shouldn't any security issue at all.
  if (ACE_OS::thread_mutex_init (&s->lock_, type, name, (ACE_mutexattr_t *)arg) == 0
      && ACE_OS::event_init (&s->count_nonzero_, 1,
                             count > 0, type, name, arg, sa) == 0
      && ACE_OS::thread_mutex_lock (&s->lock_) == 0)
    {
      s->count_ = count;

      if (ACE_OS::thread_mutex_unlock (&s->lock_) == 0)
        result = 0;
    }

  // Destroy the internal objects if we didn't initialize
  // either of them successfully.  Don't bother to check
  // for errors.
  if (result == -1)
    {
      ACE_OS::thread_mutex_destroy (&s->lock_);
      ACE_OS::event_destroy (&s->count_nonzero_);
    }
  return result;
#     endif /* ACE_USES_WINCE_SEMA_SIMULATION */
#   elif defined (ACE_PSOS)
  u_long result;
  ACE_OS::memcpy (s->name_, name, sizeof (s->name_));
  // default semaphore creation flags to priority based, global across nodes
  u_long flags = 0;
  flags |= (type & SM_LOCAL) ? SM_LOCAL : SM_GLOBAL;
  flags |= (type & SM_FIFO) ? SM_FIFO : SM_PRIOR;
  result = ::sm_create (s->name_, count, flags, &(s->sema_));
  return (result == 0) ? 0 : -1;
#   elif defined (VXWORKS)
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (arg);
  ACE_UNUSED_ARG (max);
  ACE_UNUSED_ARG (sa);
  s->name_ = 0;
  s->sema_ = ::semCCreate (type, count);
  return s->sema_ ? 0 : -1;
#   endif /* ACE_HAS_STHREADS */
# else
  ACE_UNUSED_ARG (s);
  ACE_UNUSED_ARG (count);
  ACE_UNUSED_ARG (type);
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (arg);
  ACE_UNUSED_ARG (max);
  ACE_UNUSED_ARG (sa);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::sema_post (ACE_sema_t *s)
{
  ACE_TRACE ("ACE_OS::sema_post");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_sem_post (s->sema_), int, -1);
# elif defined (ACE_HAS_POSIX_SEM)
  ACE_OSCALL_RETURN (::sem_post (s->sema_), int, -1);
# elif defined (ACE_HAS_THREADS)
#   if defined (ACE_HAS_STHREADS)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::sema_post (s), ace_result_), int, -1);
#   elif defined (ACE_HAS_PTHREADS)
  int result = -1;

  if (ACE_OS::mutex_lock (&s->lock_) == 0)
    {
      // Always allow a waiter to continue if there is one.
      if (s->waiters_ > 0)
        result = ACE_OS::cond_signal (&s->count_nonzero_);
      else
        result = 0;

      s->count_++;
      ACE_OS::mutex_unlock (&s->lock_);
    }
  return result;
#   elif defined (ACE_HAS_WTHREADS)
#     if !defined (ACE_USES_WINCE_SEMA_SIMULATION)
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::ReleaseSemaphore (*s, 1, 0),
                                          ace_result_),
                        int, -1);
#     else /* ACE_USES_WINCE_SEMA_SIMULATION */
  int result = -1;

  // Since we are simulating semaphores, we need to update semaphore
  // count manually.  Grab the lock to prevent race condition first.
  if (ACE_OS::thread_mutex_lock (&s->lock_) == 0)
    {
      // Check the original state of event object.  Single the event
      // object in transition from semaphore not available to
      // semaphore available.
      if (s->count_++ <= 0)
        result = ACE_OS::event_signal (&s->count_nonzero_);
      else
        result = 0;

      ACE_OS::thread_mutex_unlock (&s->lock_);
    }
  return result;
#     endif /* ACE_USES_WINCE_SEMA_SIMULATION */
#   elif defined (ACE_PSOS)
  int result;
  ACE_OSCALL (ACE_ADAPT_RETVAL (::sm_v (s->sema_), result), int, -1, result);
  return result;
#   elif defined (VXWORKS)
  ACE_OSCALL_RETURN (::semGive (s->sema_), int, -1);
#   endif /* ACE_HAS_STHREADS */
# else
  ACE_UNUSED_ARG (s);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::sema_post (ACE_sema_t *s, size_t release_count)
{
#if defined (ACE_WIN32) && !defined (ACE_USES_WINCE_SEMA_SIMULATION)
  // Win32 supports this natively.
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::ReleaseSemaphore (*s, release_count, 0),
                                          ace_result_), int, -1);
#else
  // On POSIX platforms we need to emulate this ourselves.
  // @@ We can optimize on this implementation.  However,
  // the semaphore promitive on Win32 doesn't allow one
  // to increase a semaphore to more than the count it was
  // first initialized.  Posix and solaris don't seem to have
  // this restriction.  Should we impose the restriction in
  // our semaphore simulation?
  for (size_t i = 0; i < release_count; i++)
    if (ACE_OS::sema_post (s) == -1)
      return -1;

  return 0;
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::sema_trywait (ACE_sema_t *s)
{
  ACE_TRACE ("ACE_OS::sema_trywait");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_sem_trywait (s->sema_), int, -1);
# elif defined (ACE_HAS_POSIX_SEM)
  // POSIX semaphores set errno to EAGAIN if trywait fails
  ACE_OSCALL_RETURN (::sem_trywait (s->sema_), int, -1);
# elif defined (ACE_HAS_THREADS)
#   if defined (ACE_HAS_STHREADS)
  // STHREADS semaphores set errno to EBUSY if trywait fails.
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::sema_trywait (s),
                                       ace_result_),
                     int, -1);
#   elif defined (ACE_HAS_PTHREADS)

  int result = -1;

  if (ACE_OS::mutex_lock (&s->lock_) == 0)
    {
      if (s->count_ > 0)
        {
          --s->count_;
          result = 0;
        }
      else
        errno = EBUSY;

      ACE_OS::mutex_unlock (&s->lock_);
    }
  return result;
#   elif defined (ACE_HAS_WTHREADS)
#     if !defined (ACE_USES_WINCE_SEMA_SIMULATION)
  int result = ::WaitForSingleObject (*s, 0);

  if (result == WAIT_OBJECT_0)
    return 0;
  else
    {
      if (result == WAIT_TIMEOUT)
        errno = EBUSY;
      else
        ACE_OS::set_errno_to_last_error ();
      // This is a hack, we need to find an appropriate mapping...
      return -1;
    }
#     else /* ACE_USES_WINCE_SEMA_SIMULATION */
  // Check the status of semaphore first.  Return immediately
  // if the semaphore is not available and avoid grabing the
  // lock.
  int result = ::WaitForSingleObject (s->count_nonzero_, 0);

  if (result == WAIT_OBJECT_0)  // Proceed when it is available.
    {
      ACE_OS::thread_mutex_lock (&s->lock_);

      // Need to double check if the semaphore is still available.
      // The double checking scheme will slightly affect the
      // efficiency if most of the time semaphores are not blocked.
      result = ::WaitForSingleObject (s->count_nonzero_, 0);
      if (result == WAIT_OBJECT_0)
        {
          // Adjust the semaphore count.  Only update the event
          // object status when the state changed.
          s->count_--;
          if (s->count_ <= 0)
            ACE_OS::event_reset (&s->count_nonzero_);
          result = 0;
        }

      ACE_OS::thread_mutex_unlock (&s->lock_);
    }

  // Translate error message to errno used by ACE.
  if (result == WAIT_TIMEOUT)
    errno = EBUSY;
  else
    ACE_OS::set_errno_to_last_error ();
  // This is taken from the hack above. ;)
  return -1;
#     endif /* ACE_USES_WINCE_SEMA_SIMULATION */
#   elif defined (ACE_PSOS)
   switch (::sm_p (s->sema_, SM_NOWAIT, 0))
   {
     case 0:
       return 0;
     case ERR_NOSEM:
       errno = EBUSY;
       // intentional fall through
     default:
       return -1;
   }
#   elif defined (VXWORKS)
  if (::semTake (s->sema_, NO_WAIT) == ERROR)
    if (errno == S_objLib_OBJ_TIMEOUT)
      {
        // couldn't get the semaphore
        errno = EBUSY;
        return -1;
      }
    else
      // error
      return -1;
  else
    // got the semaphore
    return 0;
#   endif /* ACE_HAS_STHREADS */
# else
  ACE_UNUSED_ARG (s);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::sema_wait (ACE_sema_t *s)
{
  ACE_TRACE ("ACE_OS::sema_wait");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_sem_wait (s->sema_), int, -1);
# elif defined (ACE_HAS_POSIX_SEM)
  ACE_OSCALL_RETURN (::sem_wait (s->sema_), int, -1);
# elif defined (ACE_HAS_THREADS)
#   if defined (ACE_HAS_STHREADS)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::sema_wait (s), ace_result_), int, -1);
#   elif defined (ACE_HAS_PTHREADS)
  int result = 0;

  ACE_PTHREAD_CLEANUP_PUSH (&s->lock_);

  if (ACE_OS::mutex_lock (&s->lock_) != 0)
    result = -1;
  else
    {
      // Keep track of the number of waiters so that we can signal
      // them properly in <ACE_OS::sema_post>.
      s->waiters_++;

      // Wait until the semaphore count is > 0.
      while (s->count_ == 0)
        if (ACE_OS::cond_wait (&s->count_nonzero_,
                               &s->lock_) == -1)
          {
            result = -2; // -2 means that we need to release the mutex.
            break;
          }

      --s->waiters_;
    }

  if (result == 0)
    --s->count_;

  if (result != -1)
    ACE_OS::mutex_unlock (&s->lock_);
  ACE_PTHREAD_CLEANUP_POP (0);
  return result < 0 ? -1 : result;

#   elif defined (ACE_HAS_WTHREADS)
#     if !defined (ACE_USES_WINCE_SEMA_SIMULATION)
  switch (::WaitForSingleObject (*s, INFINITE))
    {
    case WAIT_OBJECT_0:
      return 0;
    default:
      // This is a hack, we need to find an appropriate mapping...
      ACE_OS::set_errno_to_last_error ();
      return -1;
    }
  /* NOTREACHED */
#     else /* ACE_USES_WINCE_SEMA_SIMULATION */
  // Timed wait.
  int result = -1;
  for (;;)
    // Check if the semaphore is avialable or not and wait forever.
    // Don't bother to grab the lock if it is not available (to avoid
    // deadlock.)
    switch (::WaitForSingleObject (s->count_nonzero_, INFINITE))
      {
      case WAIT_OBJECT_0:
        ACE_OS::thread_mutex_lock (&s->lock_);

        // Need to double check if the semaphore is still available.
        // This time, we shouldn't wait at all.
        if (::WaitForSingleObject (s->count_nonzero_, 0) == WAIT_OBJECT_0)
          {
            // Decrease the internal counter.  Only update the event
            // object's status when the state changed.
            s->count_--;
            if (s->count_ <= 0)
              ACE_OS::event_reset (&s->count_nonzero_);
            result = 0;
          }

        ACE_OS::thread_mutex_unlock (&s->lock_);
        // if we didn't get a hold on the semaphore, the result won't
        // be 0 and thus, we'll start from the beginning again.
        if (result == 0)
          return 0;
        break;

      default:
        // Since we wait indefinitely, anything other than
        // WAIT_OBJECT_O indicates an error.
        ACE_OS::set_errno_to_last_error ();
        // This is taken from the hack above. ;)
        return -1;
      }
  /* NOTREACHED */
#     endif /* ACE_USES_WINCE_SEMA_SIMULATION */
#   elif defined (ACE_PSOS)
  int result;
  ACE_OSCALL (ACE_ADAPT_RETVAL (::sm_p (s->sema_, SM_WAIT, 0), result),
                                int, -1, result);
  return result;
#   elif defined (VXWORKS)
  ACE_OSCALL_RETURN (::semTake (s->sema_, WAIT_FOREVER), int, -1);
#   endif /* ACE_HAS_STHREADS */
# else
  ACE_UNUSED_ARG (s);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::sema_wait (ACE_sema_t *s, ACE_Time_Value &tv)
{
  ACE_TRACE ("ACE_OS::sema_wait");
# if defined (ACE_HAS_POSIX_SEM)
  ACE_UNUSED_ARG (s);
  ACE_UNUSED_ARG (tv);
  ACE_NOTSUP_RETURN (-1);
# elif defined (ACE_HAS_THREADS)
#   if defined (ACE_HAS_STHREADS)
  ACE_UNUSED_ARG (s);
  ACE_UNUSED_ARG (tv);
  ACE_NOTSUP_RETURN (-1);
#   elif defined (ACE_HAS_PTHREADS)
  int result = 0;
  ACE_Errno_Guard error (errno);

  ACE_PTHREAD_CLEANUP_PUSH (&s->lock_);

  if (ACE_OS::mutex_lock (&s->lock_) != 0)
    result = -1;
  else
    {
      // Keep track of the number of waiters so that we can signal
      // them properly in <ACE_OS::sema_post>.
      s->waiters_++;

      // Wait until the semaphore count is > 0 or until we time out.
      while (s->count_ == 0)
        if (ACE_OS::cond_timedwait (&s->count_nonzero_,
                                    &s->lock_,
                                    &tv) == -1)
          {
            error = errno;
            result = -2; // -2 means that we need to release the mutex.
            break;
          }

      --s->waiters_;
    }

  if (result == 0)
    {
#     if defined (ACE_LACKS_COND_TIMEDWAIT_RESET)
      tv = ACE_OS::gettimeofday ();
#     endif /* ACE_LACKS_COND_TIMEDWAIT_RESET */
      --s->count_;
    }

  if (result != -1)
    ACE_OS::mutex_unlock (&s->lock_);
  ACE_PTHREAD_CLEANUP_POP (0);
  return result < 0 ? -1 : result;
#   elif defined (ACE_HAS_WTHREADS)
#     if !defined (ACE_USES_WINCE_SEMA_SIMULATION)
  int msec_timeout;

  if (tv.sec () == 0 && tv.usec () == 0)
    msec_timeout = 0; // Do a "poll."
  else
    {
      // Note that we must convert between absolute time (which is
      // passed as a parameter) and relative time (which is what
      // <WaitForSingleObjects> expects).
      ACE_Time_Value relative_time (tv - ACE_OS::gettimeofday ());

      // Watchout for situations where a context switch has caused the
      // current time to be > the timeout.
      if (relative_time < ACE_Time_Value::zero)
        msec_timeout = 0;
      else
        msec_timeout = relative_time.msec ();
    }

  switch (::WaitForSingleObject (*s, msec_timeout))
    {
    case WAIT_OBJECT_0:
      tv = ACE_OS::gettimeofday ();     // Update time to when acquired
      return 0;
    case WAIT_TIMEOUT:
      errno = ETIME;
      return -1;
    default:
      // This is a hack, we need to find an appropriate mapping...
      ACE_OS::set_errno_to_last_error ();
      return -1;
    }
  /* NOTREACHED */
#     else /* ACE_USES_WINCE_SEMA_SIMULATION */
  // Note that in this mode, the acquire is done in two steps, and
  // we may get signaled but cannot grab the semaphore before
  // timeout.  In that case, we'll need to restart the process with
  // updated timeout value.

  // <tv> is an absolute time
  ACE_Time_Value relative_time = tv - ACE_OS::gettimeofday ();
  int result = -1;

  // While we are not timeout yet.
  while (relative_time > ACE_Time_Value::zero)
    {
      // Wait for our turn to get the object.
      switch (::WaitForSingleObject (s->count_nonzero_, relative_time.msec ()))
        {
        case WAIT_OBJECT_0:
          ACE_OS::thread_mutex_lock (&s->lock_);

          // Need to double check if the semaphore is still available.
          // We can only do a "try lock" styled wait here to avoid
          // blocking threads that want to signal the semaphore.
          if (::WaitForSingleObject (s->count_nonzero_, 0) == WAIT_OBJECT_0)
            {
              // As before, only reset the object when the semaphore
              // is no longer available.
              s->count_--;
              if (s->count_ <= 0)
                ACE_OS::event_reset (&s->count_nonzero_);
              result = 0;
            }

          ACE_OS::thread_mutex_unlock (&s->lock_);

          // Only return when we successfully get the semaphore.
          if (result == 0)
            {
              tv = ACE_OS::gettimeofday ();     // Update to time acquired
              return 0;
            }
          break;

          // We have timed out.
        case WAIT_TIMEOUT:
          errno = ETIME;
          return -1;

          // What?
        default:
          ACE_OS::set_errno_to_last_error ();
          // This is taken from the hack above. ;)
          return -1;
        };

      // Haven't been able to get the semaphore yet, update the
      // timeout value to reflect the remaining time we want to wait.
      relative_time = tv - ACE_OS::gettimeofday ();
    }

  // We have timed out.
  errno = ETIME;
  return -1;
#     endif /* ACE_USES_WINCE_SEMA_SIMULATION */
#   elif defined (ACE_PSOS)
  // Note that we must convert between absolute time (which is
  // passed as a parameter) and relative time (which is what
  // the system call expects).
  ACE_Time_Value relative_time (tv - ACE_OS::gettimeofday ());

  u_long ticks = relative_time.sec() * KC_TICKS2SEC +
                 relative_time.usec () * KC_TICKS2SEC /
                   ACE_ONE_SECOND_IN_USECS;
  if(ticks == 0)
    ACE_OSCALL_RETURN (::sm_p (s->sema_, SM_NOWAIT, 0), int, -1); //no timeout
  else
    ACE_OSCALL_RETURN (::sm_p (s->sema_, SM_WAIT, ticks), int, -1);
#   elif defined (VXWORKS)
  // Note that we must convert between absolute time (which is
  // passed as a parameter) and relative time (which is what
  // the system call expects).
  ACE_Time_Value relative_time (tv - ACE_OS::gettimeofday ());

  int ticks_per_sec = ::sysClkRateGet ();

  int ticks = relative_time.sec() * ticks_per_sec +
              relative_time.usec () * ticks_per_sec / ACE_ONE_SECOND_IN_USECS;
  if (::semTake (s->sema_, ticks) == ERROR)
    {
      if (errno == S_objLib_OBJ_TIMEOUT)
        // Convert the VxWorks errno to one that's common for to ACE
        // platforms.
        errno = ETIME;
      return -1;
    }
  else
    {
      tv = ACE_OS::gettimeofday ();  // Update to time acquired
      return 0;
    }
#   endif /* ACE_HAS_STHREADS */
# else
  ACE_UNUSED_ARG (s);
  ACE_UNUSED_ARG (tv);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_POSIX_SEM */
}


ACE_INLINE int
ACE_OS::rw_tryrdlock (ACE_rwlock_t *rw)
{
  ACE_TRACE ("ACE_OS::rw_tryrdlock");
#if defined (ACE_HAS_THREADS)
# if !defined (ACE_LACKS_RWLOCK_T) || defined (ACE_HAS_PTHREADS_UNIX98_EXT)
#  if defined (ACE_HAS_PTHREADS_UNIX98_EXT)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pthread_rwlock_tryrdlock (rw),
                                       ace_result_),
                     int, -1);
#  else /* Solaris */
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::rw_tryrdlock (rw), ace_result_), int, -1);
#  endif /* ACE_HAS_PTHREADS_UNIX98_EXT */
# else /* NT, POSIX, and VxWorks don't support this natively. */
  int result = -1;

  if (ACE_OS::mutex_lock (&rw->lock_) != -1)
    {
      ACE_Errno_Guard error (errno);

      if (rw->ref_count_ == -1 || rw->num_waiting_writers_ > 0)
        {
          error = EBUSY;
          result = -1;
        }
      else
        {
          rw->ref_count_++;
          result = 0;
        }

      ACE_OS::mutex_unlock (&rw->lock_);
    }
  return result;
# endif /* ! ACE_LACKS_RWLOCK_T */
#else
  ACE_UNUSED_ARG (rw);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS */
}

ACE_INLINE int
ACE_OS::rw_trywrlock (ACE_rwlock_t *rw)
{
  ACE_TRACE ("ACE_OS::rw_trywrlock");
#if defined (ACE_HAS_THREADS)
# if !defined (ACE_LACKS_RWLOCK_T) || defined (ACE_HAS_PTHREADS_UNIX98_EXT)
#  if defined (ACE_HAS_PTHREADS_UNIX98_EXT)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pthread_rwlock_trywrlock (rw),
                                       ace_result_),
                     int, -1);
#  else /* Solaris */
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::rw_trywrlock (rw), ace_result_), int, -1);
#  endif /* ACE_HAS_PTHREADS_UNIX98_EXT */
# else /* NT, POSIX, and VxWorks don't support this natively. */
  int result = -1;

  if (ACE_OS::mutex_lock (&rw->lock_) != -1)
    {
      ACE_Errno_Guard error (errno);

      if (rw->ref_count_ != 0)
        {
          error = EBUSY;
          result = -1;
        }
      else
        {
          rw->ref_count_ = -1;
          result = 0;
        }

      ACE_OS::mutex_unlock (&rw->lock_);
    }
  return result;
# endif /* ! ACE_LACKS_RWLOCK_T */
#else
  ACE_UNUSED_ARG (rw);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS */
}

ACE_INLINE int
ACE_OS::rw_rdlock (ACE_rwlock_t *rw)
{
  ACE_TRACE ("ACE_OS::rw_rdlock");
#if defined (ACE_HAS_THREADS)
# if !defined (ACE_LACKS_RWLOCK_T) || defined (ACE_HAS_PTHREADS_UNIX98_EXT)
#  if defined (ACE_HAS_PTHREADS_UNIX98_EXT)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pthread_rwlock_rdlock (rw),
                                       ace_result_),
                     int, -1);
#  else /* Solaris */
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::rw_rdlock (rw), ace_result_), int, -1);
#  endif /* ACE_HAS_PTHREADS_UNIX98_EXT */
# else /* NT, POSIX, and VxWorks don't support this natively. */
#   if defined (ACE_HAS_PTHREADS)
  ACE_PTHREAD_CLEANUP_PUSH (&rw->lock_);
#   endif /* ACE_HAS_PTHREADS */
  int result = 0;
  if (ACE_OS::mutex_lock (&rw->lock_) == -1)
    result = -1; // -1 means didn't get the mutex.
  else
    {
      // Give preference to writers who are waiting.
      while (rw->ref_count_ < 0 || rw->num_waiting_writers_ > 0)
        {
          rw->num_waiting_readers_++;
          if (ACE_OS::cond_wait (&rw->waiting_readers_, &rw->lock_) == -1)
            {
              result = -2; // -2 means that we need to release the mutex.
              break;
            }
          rw->num_waiting_readers_--;
        }
    }
  if (result == 0)
    rw->ref_count_++;
  if (result != -1)
    ACE_OS::mutex_unlock (&rw->lock_);
#   if defined (ACE_HAS_PTHREADS)
  ACE_PTHREAD_CLEANUP_POP (0);
#   endif /* defined (ACE_HAS_PTHREADS) */
  return 0;
# endif /* ! ACE_LACKS_RWLOCK_T */
#else
  ACE_UNUSED_ARG (rw);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS */
}

ACE_INLINE int
ACE_OS::rw_wrlock (ACE_rwlock_t *rw)
{
  ACE_TRACE ("ACE_OS::rw_wrlock");
#if defined (ACE_HAS_THREADS)
# if !defined (ACE_LACKS_RWLOCK_T) || defined (ACE_HAS_PTHREADS_UNIX98_EXT)
#  if defined (ACE_HAS_PTHREADS_UNIX98_EXT)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pthread_rwlock_wrlock (rw),
                                       ace_result_),
                     int, -1);
#  else /* Solaris */
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::rw_wrlock (rw), ace_result_), int, -1);
#  endif /* ACE_HAS_PTHREADS_UNIX98_EXT */
# else /* NT, POSIX, and VxWorks don't support this natively. */
#   if defined (ACE_HAS_PTHREADS)
  ACE_PTHREAD_CLEANUP_PUSH (&rw->lock_);
#   endif /* defined (ACE_HAS_PTHREADS) */
  int result = 0;

  if (ACE_OS::mutex_lock (&rw->lock_) == -1)
    result = -1; // -1 means didn't get the mutex.
  else
    {
      while (rw->ref_count_ != 0)
        {
          rw->num_waiting_writers_++;

          if (ACE_OS::cond_wait (&rw->waiting_writers_, &rw->lock_) == -1)
            {
              result = -2; // -2 means we need to release the mutex.
              break;
            }

          rw->num_waiting_writers_--;
        }
    }
  if (result == 0)
    rw->ref_count_ = -1;
  if (result != -1)
    ACE_OS::mutex_unlock (&rw->lock_);
#   if defined (ACE_HAS_PTHREADS)
  ACE_PTHREAD_CLEANUP_POP (0);
#   endif /* defined (ACE_HAS_PTHREADS) */
  return 0;
# endif /* ! ACE_LACKS_RWLOCK_T */
#else
  ACE_UNUSED_ARG (rw);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS */
}

ACE_INLINE int
ACE_OS::rw_unlock (ACE_rwlock_t *rw)
{
  ACE_TRACE ("ACE_OS::rw_unlock");
#if defined (ACE_HAS_THREADS)
# if !defined (ACE_LACKS_RWLOCK_T) || defined (ACE_HAS_PTHREADS_UNIX98_EXT)
#  if defined (ACE_HAS_PTHREADS_UNIX98_EXT)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pthread_rwlock_unlock (rw),
                                       ace_result_),
                     int, -1);
#  else /* Solaris */
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::rw_unlock (rw), ace_result_), int, -1);
#  endif /* ACE_HAS_PTHREADS_UNIX98_EXT */
# else /* NT, POSIX, and VxWorks don't support this natively. */
  if (ACE_OS::mutex_lock (&rw->lock_) == -1)
    return -1;

  if (rw->ref_count_ > 0) // Releasing a reader.
    rw->ref_count_--;
  else if (rw->ref_count_ == -1) // Releasing a writer.
    rw->ref_count_ = 0;
  else
    return -1; // @@ ACE_ASSERT (!"count should not be 0!\n");


  int result = 0;
  ACE_Errno_Guard error (errno);

  if (rw->important_writer_ && rw->ref_count_ == 1)
    // only the reader requesting to upgrade its lock is left over.
    {
      result = ACE_OS::cond_signal (&rw->waiting_important_writer_);
      error = errno;
    }
  else if (rw->num_waiting_writers_ > 0 && rw->ref_count_ == 0)
    // give preference to writers over readers...
    {
      result = ACE_OS::cond_signal (&rw->waiting_writers_);
      error =  errno;
    }
  else if (rw->num_waiting_readers_ > 0 && rw->num_waiting_writers_ == 0)
    {
      result = ACE_OS::cond_broadcast (&rw->waiting_readers_);
      error = errno;
    }

  ACE_OS::mutex_unlock (&rw->lock_);
  return result;
# endif /* ! ace_lacks_rwlock_t */
#else
  ACE_UNUSED_ARG (rw);
  ACE_NOTSUP_RETURN (-1);
#endif /* ace_has_threads */
}

// Note that the caller of this method *must* already possess this
// lock as a read lock.
// return {-1 and no errno set means: error,
//         -1 and errno==EBUSY set means: could not upgrade,
//         0 means: upgraded successfully}

ACE_INLINE int
ACE_OS::rw_trywrlock_upgrade (ACE_rwlock_t *rw)
{
  ACE_TRACE ("ACE_OS::rw_wrlock");
#if defined (ACE_HAS_THREADS)
# if !defined (ACE_LACKS_RWLOCK_T)
  // Some native rwlocks, such as those on Solaris and HP-UX 11, don't
  // support the upgrade feature . . .
  ACE_UNUSED_ARG (rw);
  ACE_NOTSUP_RETURN (-1);
# else /* NT, POSIX, and VxWorks don't support this natively. */
  // The ACE rwlock emulation does support upgrade . . .
  int result = 0;

#   if defined (ACE_HAS_PTHREADS)
  ACE_PTHREAD_CLEANUP_PUSH (&rw->lock_);
#   endif /* defined (ACE_HAS_PTHREADS) */

  if (ACE_OS::mutex_lock (&rw->lock_) == -1)
    return -1;
    // -1 means didn't get the mutex, error
  else if (rw->important_writer_)
    // an other reader upgrades already
    {
      result = -1;
      errno = EBUSY;
    }
  else
    {
      while (rw->ref_count_ > 1) // wait until only I am left
        {
          rw->num_waiting_writers_++; // prohibit any more readers
          rw->important_writer_ = 1;

          if (ACE_OS::cond_wait (&rw->waiting_important_writer_, &rw->lock_) == -1)
            {
              result = -1;
              // we know that we have the lock again, we have this guarantee,
              // but something went wrong
            }
          rw->important_writer_ = 0;
          rw->num_waiting_writers_--;
        }
      if (result == 0)
        {
          // nothing bad happend
          rw->ref_count_ = -1;
          // now I am a writer
          // everything is O.K.
        }
    }

  ACE_OS::mutex_unlock (&rw->lock_);

#   if defined (ACE_HAS_PTHREADS)
  ACE_PTHREAD_CLEANUP_POP (0);
#   endif /* defined (ACE_HAS_PTHREADS) */

  return result;

# endif /* ! ACE_LACKS_RWLOCK_T */
#else
  ACE_UNUSED_ARG (rw);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS */
}

#if defined (ACE_HAS_THREADS) && (!defined (ACE_LACKS_RWLOCK_T) || \
                                   defined (ACE_HAS_PTHREADS_UNIX98_EXT))
ACE_INLINE int
ACE_OS::rwlock_init (ACE_rwlock_t *rw,
                     int type,
                     const ACE_TCHAR *name,
                     void *arg)
{
  // ACE_TRACE ("ACE_OS::rwlock_init");
#  if defined (ACE_HAS_PTHREADS_UNIX98_EXT)
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (arg);

  int status;
  pthread_rwlockattr_t attr;
  pthread_rwlockattr_init (&attr);
  pthread_rwlockattr_setpshared (&attr, (type == USYNC_THREAD ?
                                         PTHREAD_PROCESS_PRIVATE :
                                         PTHREAD_PROCESS_SHARED));
  status = ACE_ADAPT_RETVAL (pthread_rwlock_init (rw, &attr), status);
  pthread_rwlockattr_destroy (&attr);

  return status;

#  else
  type = type;
  name = name;
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::rwlock_init (rw, type, arg), ace_result_), int, -1);
#  endif /* ACE_HAS_PTHREADS_UNIX98_EXT */
}
#endif /* ACE_HAS THREADS && !defined (ACE_LACKS_RWLOCK_T) */

ACE_INLINE int
ACE_OS::rwlock_destroy (ACE_rwlock_t *rw)
{
  ACE_TRACE ("ACE_OS::rwlock_destroy");
#if defined (ACE_HAS_THREADS)
# if !defined (ACE_LACKS_RWLOCK_T) || defined (ACE_HAS_PTHREADS_UNIX98_EXT)
#  if defined (ACE_HAS_PTHREADS_UNIX98_EXT)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pthread_rwlock_destroy (rw),
                                       ace_result_),
                     int, -1);
#  else /* Solaris */
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::rwlock_destroy (rw), ace_result_), int, -1);
#  endif /* ACE_HAS_PTHREADS_UNIX98_EXT */
# else /* NT, POSIX, and VxWorks don't support this natively. */
  ACE_OS::mutex_destroy (&rw->lock_);
  ACE_OS::cond_destroy (&rw->waiting_readers_);
  ACE_OS::cond_destroy (&rw->waiting_important_writer_);
  return ACE_OS::cond_destroy (&rw->waiting_writers_);
# endif /* ACE_HAS_STHREADS && !defined (ACE_LACKS_RWLOCK_T) */
#else
  ACE_UNUSED_ARG (rw);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS */
}

ACE_INLINE int
ACE_OS::event_init (ACE_event_t *event,
                    int manual_reset,
                    int initial_state,
                    int type,
                    const ACE_TCHAR *name,
                    void *arg,
                    LPSECURITY_ATTRIBUTES sa)
{
#if defined (ACE_WIN32)
  ACE_UNUSED_ARG (type);
  ACE_UNUSED_ARG (arg);
  *event = ACE_TEXT_CreateEvent (ACE_OS::default_win32_security_attributes(sa),
                                 manual_reset,
                                 initial_state,
                                 name);
  if (*event == NULL)
    ACE_FAIL_RETURN (-1);
  else
    return 0;
#elif defined (ACE_HAS_THREADS)
  ACE_UNUSED_ARG (sa);
  event->manual_reset_ = manual_reset;
  event->is_signaled_ = initial_state;
  event->waiting_threads_ = 0;

  int result = ACE_OS::cond_init (&event->condition_,
                                  ACE_static_cast (short, type),
                                  name,
                                  arg);
  if (result == 0)
    result = ACE_OS::mutex_init (&event->lock_,
                                 type,
                                 name,
                                 (ACE_mutexattr_t *) arg);
  return result;
#else
  ACE_UNUSED_ARG (event);
  ACE_UNUSED_ARG (manual_reset);
  ACE_UNUSED_ARG (initial_state);
  ACE_UNUSED_ARG (type);
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (arg);
  ACE_UNUSED_ARG (sa);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::event_destroy (ACE_event_t *event)
{
#if defined (ACE_WIN32)
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::CloseHandle (*event), ace_result_), int, -1);
#elif defined (ACE_HAS_THREADS)
  int r1 = ACE_OS::mutex_destroy (&event->lock_);
  int r2 = ACE_OS::cond_destroy (&event->condition_);
  return r1 != 0 || r2 != 0 ? -1 : 0;
#else
  ACE_UNUSED_ARG (event);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::event_wait (ACE_event_t *event)
{
#if defined (ACE_WIN32)
  switch (::WaitForSingleObject (*event, INFINITE))
    {
    case WAIT_OBJECT_0:
      return 0;
    default:
      ACE_OS::set_errno_to_last_error ();
      return -1;
    }
#elif defined (ACE_HAS_THREADS)
  int result = 0;
  int error = 0;

  // grab the lock first
  if (ACE_OS::mutex_lock (&event->lock_) == 0)
    {
      if (event->is_signaled_ == 1)
        // Event is currently signaled.
        {
          if (event->manual_reset_ == 0)
            // AUTO: reset state
            event->is_signaled_ = 0;
        }
      else
        // event is currently not signaled
        {
          event->waiting_threads_++;

          if (ACE_OS::cond_wait (&event->condition_,
                                 &event->lock_) != 0)
            {
              result = -1;
              error = errno;
              // Something went wrong...
            }

          event->waiting_threads_--;
        }

      // Now we can let go of the lock.
      ACE_OS::mutex_unlock (&event->lock_);

      if (result == -1)
        // Reset errno in case mutex_unlock() also fails...
        errno = error;
    }
  else
    result = -1;
  return result;
#else
  ACE_UNUSED_ARG (event);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::event_timedwait (ACE_event_t *event,
                         ACE_Time_Value *timeout)
{
#if defined (ACE_WIN32)
  DWORD result;

  if (timeout == 0)
    // Wait forever
    result = ::WaitForSingleObject (*event, INFINITE);
  else if (timeout->sec () == 0 && timeout->usec () == 0)
    // Do a "poll".
    result = ::WaitForSingleObject (*event, 0);
  else
    {
      // Wait for upto <relative_time> number of milliseconds.  Note
      // that we must convert between absolute time (which is passed
      // as a parameter) and relative time (which is what
      // WaitForSingleObjects() expects).
      ACE_Time_Value relative_time (*timeout - ACE_OS::gettimeofday ());

      // Watchout for situations where a context switch has caused the
      // current time to be > the timeout.  Thanks to Norbert Rapp
      // <NRapp@nexus-informatics.de> for pointing this.
      int msec_timeout;
      if (relative_time < ACE_Time_Value::zero)
        msec_timeout = 0;
      else
        msec_timeout = relative_time.msec ();
      result = ::WaitForSingleObject (*event, msec_timeout);
    }

  switch (result)
    {
    case WAIT_OBJECT_0:
      return 0;
    case WAIT_TIMEOUT:
      errno = ETIME;
      return -1;
    default:
      // This is a hack, we need to find an appropriate mapping...
      ACE_OS::set_errno_to_last_error ();
      return -1;
    }
#elif defined (ACE_HAS_THREADS)
  int result = 0;
  int error = 0;

  // grab the lock first
  if (ACE_OS::mutex_lock (&event->lock_) == 0)
    {
      if (event->is_signaled_ == 1)
        // event is currently signaled
        {
          if (event->manual_reset_ == 0)
            // AUTO: reset state
            event->is_signaled_ = 0;
        }
      else
        // event is currently not signaled
        {
          event->waiting_threads_++;

          if (ACE_OS::cond_timedwait (&event->condition_,
                                      &event->lock_,
                                      timeout) != 0)
            {
              result = -1;
              error = errno;
            }

          event->waiting_threads_--;
        }

      // Now we can let go of the lock.
      ACE_OS::mutex_unlock (&event->lock_);

      if (result == -1)
        // Reset errno in case mutex_unlock() also fails...
        errno = error;
    }
  else
    result = -1;
  return result;
#else
  ACE_UNUSED_ARG (event);
  ACE_UNUSED_ARG (timeout);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::event_signal (ACE_event_t *event)
{
#if defined (ACE_WIN32)
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::SetEvent (*event), ace_result_), int, -1);
#elif defined (ACE_HAS_THREADS)
  int result = 0;
  int error = 0;

  // grab the lock first
  if (ACE_OS::mutex_lock (&event->lock_) == 0)
    {
      // Manual-reset event.
      if (event->manual_reset_ == 1)
        {
          // signal event
          event->is_signaled_ = 1;
          // wakeup all
          if (ACE_OS::cond_broadcast (&event->condition_) != 0)
            {
              result = -1;
              error = errno;
            }
        }
      // Auto-reset event
      else
        {
          if (event->waiting_threads_ == 0)
            // No waiters: signal event.
            event->is_signaled_ = 1;

          // Waiters: wakeup one waiter.
          else if (ACE_OS::cond_signal (&event->condition_) != 0)
            {
              result = -1;
              error = errno;
            }
        }

      // Now we can let go of the lock.
      ACE_OS::mutex_unlock (&event->lock_);

      if (result == -1)
        // Reset errno in case mutex_unlock() also fails...
        errno = error;
    }
  else
    result = -1;
  return result;
#else
  ACE_UNUSED_ARG (event);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::event_pulse (ACE_event_t *event)
{
#if defined (ACE_WIN32)
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::PulseEvent (*event), ace_result_), int, -1);
#elif defined (ACE_HAS_THREADS)
  int result = 0;
  int error = 0;

  // grab the lock first
  if (ACE_OS::mutex_lock (&event->lock_) == 0)
    {
      // Manual-reset event.
      if (event->manual_reset_ == 1)
        {
          // Wakeup all waiters.
          if (ACE_OS::cond_broadcast (&event->condition_) != 0)
            {
              result = -1;
              error = errno;
            }
        }
      // Auto-reset event: wakeup one waiter.
      else if (ACE_OS::cond_signal (&event->condition_) != 0)
        {
          result = -1;
          error = errno;
        }

      // Reset event.
      event->is_signaled_ = 0;

      // Now we can let go of the lock.
      ACE_OS::mutex_unlock (&event->lock_);

      if (result == -1)
        // Reset errno in case mutex_unlock() also fails...
        errno = error;
    }
  else
    result = -1;
  return result;
#else
  ACE_UNUSED_ARG (event);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::event_reset (ACE_event_t *event)
{
#if defined (ACE_WIN32)
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::ResetEvent (*event), ace_result_), int, -1);
#elif defined (ACE_HAS_THREADS)
  int result = 0;

  // Grab the lock first.
  if (ACE_OS::mutex_lock (&event->lock_) == 0)
    {
      // Reset event.
      event->is_signaled_ = 0;

      // Now we can let go of the lock.
      ACE_OS::mutex_unlock (&event->lock_);
    }
  else
    result = -1;
  return result;
#else
  ACE_UNUSED_ARG (event);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_WIN32 */
}

#if defined (ACE_WIN32)
# define ACE_SOCKCALL_RETURN(OP,TYPE,FAILVALUE) \
  do { TYPE ace_result_ = (TYPE) OP; \
      if (ace_result_ == FAILVALUE) { int ___ = ::WSAGetLastError (); errno = ___; return (TYPE) FAILVALUE; } else return ace_result_; \
  } while (0)
#else
# define ACE_SOCKCALL_RETURN(OP,TYPE,FAILVALUE) ACE_OSCALL_RETURN(OP,TYPE,FAILVALUE)
#endif /* ACE_WIN32 */

#if defined (ACE_LACKS_NETDB_REENTRANT_FUNCTIONS)
# if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
#   define ACE_NETDBCALL_RETURN(OP,TYPE,FAILVALUE,TARGET,SIZE) \
  do \
  { \
    if (ACE_OS::netdb_acquire ())  \
      return FAILVALUE; \
    else \
      { \
        TYPE ace_result_; \
        ACE_OSCALL (OP, TYPE, FAILVALUE, ace_result_); \
        if (ace_result_ != FAILVALUE) \
          ::memcpy (TARGET, \
                    ace_result_, \
                    SIZE < sizeof (TYPE) ? SIZE : sizeof (TYPE)); \
        ACE_OS::netdb_release (); \
        return ace_result_; \
      } \
  } while(0)
# else /* ! (ACE_MT_SAFE && ACE_MT_SAFE != 0) */
#   define ACE_NETDBCALL_RETURN(OP,TYPE,FAILVALUE,TARGET,SIZE) \
  do \
  { \
        TYPE ace_result_; \
        ACE_OSCALL(OP,TYPE,FAILVALUE,ace_result_); \
        if (ace_result_ != FAILVALUE) \
          ::memcpy (TARGET, \
                    ace_result_, \
                    SIZE < sizeof (TYPE) ? SIZE : sizeof (TYPE)); \
        return ace_result_; \
  } while(0)
# endif /* ACE_MT_SAFE && ACE_MT_SAFE != 0 */
#endif /* ACE_LACKS_NETDB_REENTRANT_FUNCTIONS */

ACE_INLINE
ACE_Flow_Spec::ACE_Flow_Spec (u_long token_rate,
                              u_long token_bucket_size,
                              u_long peak_bandwidth,
                              u_long latency,
                              u_long delay_variation,
                              ACE_SERVICE_TYPE service_type,
                              u_long max_sdu_size,
                              u_long minimum_policed_size,
                              int ttl,
                              int priority)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  this->TokenRate = token_rate;
  this->TokenBucketSize = token_bucket_size;
  this->PeakBandwidth = peak_bandwidth;
  this->Latency = latency;
  this->DelayVariation = delay_variation;
#if defined(ACE_HAS_WINSOCK2_GQOS)
  this->ServiceType = service_type;
  this->MaxSduSize = max_sdu_size;
  this->MinimumPolicedSize = minimum_policed_size;
#else
  ACE_UNUSED_ARG (service_type);
  ACE_UNUSED_ARG (max_sdu_size);
  ACE_UNUSED_ARG (minimum_policed_size);
#endif /* ACE_HAS_WINSOCK2_GQOS */
  ACE_UNUSED_ARG (ttl);
  ACE_UNUSED_ARG (priority);
#else

  this->token_rate_ = token_rate;
  this->token_bucket_size_ = token_bucket_size;
  this->peak_bandwidth_ = peak_bandwidth;
  this->latency_ = latency;
  this->delay_variation_ = delay_variation;
  this->service_type_ = service_type;
  this->max_sdu_size_ = max_sdu_size;
  this->minimum_policed_size_ = minimum_policed_size;
  this->ttl_ = ttl;
  this->priority_ = priority;

#endif /* defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) */
}

ACE_INLINE
ACE_Flow_Spec::ACE_Flow_Spec (void)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  this->TokenRate = 0;
  this->TokenBucketSize = 0;
  this->PeakBandwidth = 0;
  this->Latency = 0;
  this->DelayVariation = 0;
#if defined(ACE_HAS_WINSOCK2_GQOS)
  this->ServiceType = 0;
  this->MaxSduSize = 0;
  this->MinimumPolicedSize = 0;
#endif /* ACE_HAS_WINSOCK2_GQOS */
#else

  this->token_rate_ = 0;
  this->token_bucket_size_ = 0;
  this->peak_bandwidth_ = 0;
  this->latency_ = 0;
  this->delay_variation_ = 0;
  this->service_type_ = 0;
  this->max_sdu_size_ = 0;
  this->minimum_policed_size_ = 0;
  this->ttl_ = 0;
  this->priority_ = 0;

#endif /* defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) */
}

ACE_INLINE u_long
ACE_Flow_Spec::token_rate (void) const
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  return this->TokenRate;
#else
  return this->token_rate_;
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE void
ACE_Flow_Spec::token_rate (u_long tr)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  this->TokenRate = tr;
#else
  this->token_rate_ = tr;
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE u_long
ACE_Flow_Spec::token_bucket_size (void) const
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  return this->TokenBucketSize;
#else
  return this->token_bucket_size_;
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE void
ACE_Flow_Spec::token_bucket_size (u_long tbs)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  this->TokenBucketSize = tbs;
#else
  this->token_bucket_size_ = tbs;
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE u_long
ACE_Flow_Spec::peak_bandwidth (void) const
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  return this->PeakBandwidth;
#else
  return this->peak_bandwidth_;
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE void
ACE_Flow_Spec::peak_bandwidth (u_long pb)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  this->PeakBandwidth = pb;
#else
  this->peak_bandwidth_ = pb;
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE u_long
ACE_Flow_Spec::latency (void) const
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  return this->Latency;
#else
  return this->latency_;
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE void
ACE_Flow_Spec::latency (u_long l)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  this->Latency = l;
#else
  this->latency_ = l;
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE u_long
ACE_Flow_Spec::delay_variation (void) const
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  return this->DelayVariation;
#else
  return this->delay_variation_;
#endif /* ACE_HAS_WINSOCK2 */
}
ACE_INLINE void
ACE_Flow_Spec::delay_variation (u_long dv)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  this->DelayVariation = dv;
#else
  this->delay_variation_ = dv;
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE ACE_SERVICE_TYPE
ACE_Flow_Spec::service_type (void) const
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) && \
    defined (ACE_HAS_WINSOCK2_GQOS)
  return this->ServiceType;
#else
  return this->service_type_;
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE void
ACE_Flow_Spec::service_type (ACE_SERVICE_TYPE st)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) && \
    defined (ACE_HAS_WINSOCK2_GQOS)
  this->ServiceType = st;
#else
  this->service_type_ = st;
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE u_long
ACE_Flow_Spec::max_sdu_size (void) const
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) && \
    defined (ACE_HAS_WINSOCK2_GQOS)
  return this->MaxSduSize;
#else
  return this->max_sdu_size_;
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE void
ACE_Flow_Spec::max_sdu_size (u_long mss)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) && \
    defined (ACE_HAS_WINSOCK2_GQOS)
  this->MaxSduSize = mss;
#else
  this->max_sdu_size_ = mss;
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE u_long
ACE_Flow_Spec::minimum_policed_size (void) const
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) && \
    defined (ACE_HAS_WINSOCK2_GQOS)
  return this->MinimumPolicedSize;
#else
  return this->minimum_policed_size_;
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE void
ACE_Flow_Spec::minimum_policed_size (u_long mps)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) && \
    defined (ACE_HAS_WINSOCK2_GQOS)
  this->MinimumPolicedSize = mps;
#else
  this->minimum_policed_size_ = mps;
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE int
ACE_Flow_Spec::ttl (void) const
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) && \
    defined (ACE_HAS_WINSOCK2_GQOS)
  ACE_NOTSUP_RETURN (-1);
#else
  return this->ttl_;
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE void
ACE_Flow_Spec::ttl (int t)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) && \
    defined (ACE_HAS_WINSOCK2_GQOS)
  ACE_UNUSED_ARG (t);
  // TBD...
#else
  this->ttl_ = t;
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE int
ACE_Flow_Spec::priority (void) const
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) && \
    defined (ACE_HAS_WINSOCK2_GQOS)
  ACE_NOTSUP_RETURN (-1);
#else
  return this->priority_;
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE void
ACE_Flow_Spec::priority (int p)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) && \
    defined (ACE_HAS_WINSOCK2_GQOS)
  ACE_UNUSED_ARG (p);
  // TBD...
#else
  this->priority_ = p;
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE ACE_Flow_Spec
ACE_QoS::sending_flowspec (void) const
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  return (ACE_Flow_Spec &) this->SendingFlowspec;
#else
  return this->sending_flowspec_;
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE void
ACE_QoS::sending_flowspec (const ACE_Flow_Spec &fs)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  this->SendingFlowspec = (FLOWSPEC) fs;
#else
  this->sending_flowspec_ = fs;
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE ACE_Flow_Spec
ACE_QoS::receiving_flowspec (void) const
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  return (ACE_Flow_Spec &) this->ReceivingFlowspec;
#else
  return receiving_flowspec_;
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE void
ACE_QoS::receiving_flowspec (const ACE_Flow_Spec &fs)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  this->ReceivingFlowspec = (FLOWSPEC) fs;
#else
  this->receiving_flowspec_ = fs;
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE iovec
ACE_QoS::provider_specific (void) const
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  return (iovec &) this->ProviderSpecific;
#else
  ACE_NOTSUP_RETURN (iovec ());
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE void
ACE_QoS::provider_specific (const iovec &ps)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  this->ProviderSpecific = (WSABUF) ((iovec &) ps);
#else
  ACE_UNUSED_ARG (ps);
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE
ACE_QoS_Params::ACE_QoS_Params (iovec *caller_data,
                                iovec *callee_data,
                                ACE_QoS *socket_qos,
                                ACE_QoS *group_socket_qos,
                                u_long flags)
  : caller_data_ (caller_data),
    callee_data_ (callee_data),
    socket_qos_ (socket_qos),
    group_socket_qos_ (group_socket_qos),
    flags_ (flags)
{
}

ACE_INLINE iovec *
ACE_QoS_Params::caller_data (void) const
{
  return this->caller_data_;
}

ACE_INLINE void
ACE_QoS_Params::caller_data (iovec *cd)
{
  this->caller_data_ = cd;
}

ACE_INLINE iovec *
ACE_QoS_Params::callee_data (void) const
{
  return this->callee_data_;
}

ACE_INLINE void
ACE_QoS_Params::callee_data (iovec *cd)
{
  this->callee_data_ = cd;
}

ACE_INLINE ACE_QoS *
ACE_QoS_Params::socket_qos (void) const
{
  return this->socket_qos_;
}

ACE_INLINE void
ACE_QoS_Params::socket_qos (ACE_QoS *sq)
{
  this->socket_qos_ = sq;
}

ACE_INLINE ACE_QoS *
ACE_QoS_Params::group_socket_qos (void) const
{
  return this->group_socket_qos_;
}

ACE_INLINE void
ACE_QoS_Params::group_socket_qos (ACE_QoS *gsq)
{
  this->group_socket_qos_ = gsq;
}

ACE_INLINE u_long
ACE_QoS_Params::flags (void) const
{
  return this->flags_;
}

ACE_INLINE void
ACE_QoS_Params::flags (u_long f)
{
  this->flags_ = f;
}

ACE_INLINE
ACE_Accept_QoS_Params::ACE_Accept_QoS_Params (ACE_QOS_CONDITION_FUNC qos_condition_callback,
                                              u_long callback_data)
  : qos_condition_callback_ (qos_condition_callback),
    callback_data_ (callback_data)
{
}

ACE_INLINE ACE_QOS_CONDITION_FUNC
ACE_Accept_QoS_Params::qos_condition_callback (void) const
{
  return this->qos_condition_callback_;
}

ACE_INLINE void
ACE_Accept_QoS_Params::qos_condition_callback (ACE_QOS_CONDITION_FUNC qcc)
{
  this->qos_condition_callback_ = qcc;
}

ACE_INLINE u_long
ACE_Accept_QoS_Params::callback_data (void) const
{
  return this->callback_data_;
}

ACE_INLINE void
ACE_Accept_QoS_Params::callback_data (u_long cd)
{
  this->callback_data_ = cd;
}

ACE_INLINE ACE_HANDLE
ACE_OS::accept (ACE_HANDLE handle,
                struct sockaddr *addr,
                int *addrlen)
{
  ACE_TRACE ("ACE_OS::accept");
#if defined (ACE_PSOS)
#  if !defined (ACE_PSOS_DIAB_PPC)
  ACE_SOCKCALL_RETURN (::accept ((ACE_SOCKET) handle,
                                 (struct sockaddr_in *) addr,
                                 (ACE_SOCKET_LEN *) addrlen),
                       ACE_HANDLE,
                       ACE_INVALID_HANDLE);
#  else
ACE_SOCKCALL_RETURN (::accept ((ACE_SOCKET) handle,
                               (struct sockaddr *) addr,
                               (ACE_SOCKET_LEN *) addrlen),
                     ACE_HANDLE,
                     ACE_INVALID_HANDLE);
#  endif /* defined ACE_PSOS_DIAB_PPC */
#else
  // On a non-blocking socket with no connections to accept, this
  // system call will return EWOULDBLOCK or EAGAIN, depending on the
  // platform.  UNIX 98 allows either errno, and they may be the same
  // numeric value.  So to make life easier for upper ACE layers as
  // well as application programmers, always change EAGAIN to
  // EWOULDBLOCK.  Rather than hack the ACE_OSCALL_RETURN macro, it's
  // handled explicitly here.  If the ACE_OSCALL macro ever changes,
  // this function needs to be reviewed.  On Win32, the regular macros
  // can be used, as this is not an issue.

#  if defined (ACE_WIN32)
  ACE_SOCKCALL_RETURN (::accept ((ACE_SOCKET) handle,
                                 addr,
                                 (ACE_SOCKET_LEN *) addrlen),
                       ACE_HANDLE,
                       ACE_INVALID_HANDLE);
#  else
#    if defined (ACE_HAS_BROKEN_ACCEPT_ADDR)
  // Apparently some platforms like VxWorks can't correctly deal with
  // a NULL addr.

   sockaddr_in fake_addr;
   int fake_addrlen;

   if (addrlen == 0)
     addrlen = &fake_addrlen;

   if (addr == 0)
     {
       addr = (sockaddr *) &fake_addr;
       *addrlen = sizeof fake_addr;
     }
#    endif /* VXWORKS */
  ACE_HANDLE ace_result = ::accept ((ACE_SOCKET) handle,
                                    addr,
                                    (ACE_SOCKET_LEN *) addrlen) ;
  if (ace_result == ACE_INVALID_HANDLE && errno == EAGAIN)
    errno = EWOULDBLOCK;
  return ace_result;

#  endif /* defined (ACE_WIN32) */
#endif /* defined (ACE_PSOS) */
}

ACE_INLINE ACE_HANDLE
ACE_OS::accept (ACE_HANDLE handle,
                struct sockaddr *addr,
                int *addrlen,
                const ACE_Accept_QoS_Params &qos_params)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  ACE_SOCKCALL_RETURN (::WSAAccept ((ACE_SOCKET) handle,
                                    addr,
                                    (ACE_SOCKET_LEN *) addrlen,
                                    (LPCONDITIONPROC) qos_params.qos_condition_callback (),
                                    qos_params.callback_data ()),
                       ACE_HANDLE,
                       ACE_INVALID_HANDLE);
#else
  ACE_UNUSED_ARG (qos_params);
  return ACE_OS::accept (handle,
                         addr,
                         addrlen);
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE int
ACE_OS::enum_protocols (int *protocols,
                        ACE_Protocol_Info *protocol_buffer,
                        u_long *buffer_length)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)

  ACE_SOCKCALL_RETURN (::WSAEnumProtocols (protocols,
                                           protocol_buffer,
                                           buffer_length),
                       int,
                       SOCKET_ERROR);

#else
  ACE_UNUSED_ARG (protocols);
  ACE_UNUSED_ARG (protocol_buffer);
  ACE_UNUSED_ARG (buffer_length);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE ACE_HANDLE
ACE_OS::join_leaf (ACE_HANDLE socket,
                   const sockaddr *name,
                   int namelen,
                   const ACE_QoS_Params &qos_params)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)

  QOS qos;
  // Construct the WinSock2 QOS structure.

  qos.SendingFlowspec = qos_params.socket_qos ()->sending_flowspec ();
  qos.ReceivingFlowspec = qos_params.socket_qos ()->receiving_flowspec ();
  qos.ProviderSpecific = (WSABUF) qos_params.socket_qos ()->provider_specific ();

  ACE_SOCKCALL_RETURN (::WSAJoinLeaf ((ACE_SOCKET) socket,
                                      name,
                                      namelen,
                                      (WSABUF *) qos_params.caller_data (),
                                      (WSABUF *) qos_params.callee_data (),
                                      &qos,
                                      (QOS *) qos_params.group_socket_qos (),
                                      qos_params.flags ()),
                       ACE_HANDLE,
                       ACE_INVALID_HANDLE);

#else
  ACE_UNUSED_ARG (socket);
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (namelen);
  ACE_UNUSED_ARG (qos_params);
  ACE_NOTSUP_RETURN (ACE_INVALID_HANDLE);
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE int
ACE_OS::ioctl (ACE_HANDLE socket,
               u_long io_control_code,
               void *in_buffer_p,
               u_long in_buffer,
               void *out_buffer_p,
               u_long out_buffer,
               u_long *bytes_returned,
               ACE_OVERLAPPED *overlapped,
               ACE_OVERLAPPED_COMPLETION_FUNC func)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  ACE_SOCKCALL_RETURN (::WSAIoctl ((ACE_SOCKET) socket,
                                   io_control_code,
                                   in_buffer_p,
                                   in_buffer,
                                   out_buffer_p,
                                   out_buffer,
                                   bytes_returned,
                                   (WSAOVERLAPPED *) overlapped,
                                   func),
                       int,
                       SOCKET_ERROR);
#else
  ACE_UNUSED_ARG (socket);
  ACE_UNUSED_ARG (io_control_code);
  ACE_UNUSED_ARG (in_buffer_p);
  ACE_UNUSED_ARG (in_buffer);
  ACE_UNUSED_ARG (out_buffer_p);
  ACE_UNUSED_ARG (out_buffer);
  ACE_UNUSED_ARG (bytes_returned);
  ACE_UNUSED_ARG (overlapped);
  ACE_UNUSED_ARG (func);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_WINSOCK2 */
}



ACE_INLINE int
ACE_OS::ioctl (ACE_HANDLE socket,
               u_long io_control_code,
               ACE_QoS &ace_qos,
               u_long *bytes_returned,
               void *buffer_p,
               u_long buffer,
               ACE_OVERLAPPED *overlapped,
               ACE_OVERLAPPED_COMPLETION_FUNC func)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)

  QOS qos;
  u_long qos_len = sizeof (QOS);

  if (io_control_code == SIO_SET_QOS)
    {
      qos.SendingFlowspec = ace_qos.sending_flowspec ();
      qos.ReceivingFlowspec = ace_qos.receiving_flowspec ();
      qos.ProviderSpecific = (WSABUF) ace_qos.provider_specific ();

      qos_len += ace_qos.provider_specific ().iov_len;

      ACE_SOCKCALL_RETURN (::WSAIoctl ((ACE_SOCKET) socket,
                                       io_control_code,
                                       &qos,
                                       qos_len,
                                       buffer_p,
                                       buffer,
                                       bytes_returned,
                                       (WSAOVERLAPPED *) overlapped,
                                       func),
                           int,
                           SOCKET_ERROR);
    }
  else
    {
      u_long dwBufferLen = 0;

      // Query for the buffer size.
      int result = ::WSAIoctl ((ACE_SOCKET) socket,
                                io_control_code,
                                NULL,
                                0,
                                &dwBufferLen,
                                sizeof (dwBufferLen),
                                bytes_returned,
                                NULL,
                                NULL);


      if (result == SOCKET_ERROR)
          {
                u_long dwErr = ::WSAGetLastError ();

                if (dwErr == WSAEWOULDBLOCK)
                {
                        errno = dwErr;
                        return -1;
                }
                else
                        if (dwErr != WSAENOBUFS)
                        {
                                errno = dwErr;
                                return -1;
                        }
          }

    char *qos_buf;
        ACE_NEW_RETURN (qos_buf,
                                        char [dwBufferLen],
                                        -1);

        QOS *qos = ACE_reinterpret_cast (QOS*,
                                                                         qos_buf);

        result = ::WSAIoctl ((ACE_SOCKET) socket,
                                   io_control_code,
                       NULL,
                       0,
                       qos,
                       dwBufferLen,
                       bytes_returned,
                       NULL,
                       NULL);

    if (result == SOCKET_ERROR)
                return result;

    ACE_Flow_Spec sending_flowspec (qos->SendingFlowspec.TokenRate,
                                    qos->SendingFlowspec.TokenBucketSize,
                                    qos->SendingFlowspec.PeakBandwidth,
                                    qos->SendingFlowspec.Latency,
                                    qos->SendingFlowspec.DelayVariation,
#if defined(ACE_HAS_WINSOCK2_GQOS)
                                    qos->SendingFlowspec.ServiceType,
                                    qos->SendingFlowspec.MaxSduSize,
                                    qos->SendingFlowspec.MinimumPolicedSize,
#else /* ACE_HAS_WINSOCK2_GQOS */
                                    0,
                                    0,
                                    0,
#endif /* ACE_HAS_WINSOCK2_GQOS */
                                    0,
                                    0);

    ACE_Flow_Spec receiving_flowspec (qos->ReceivingFlowspec.TokenRate,
                                      qos->ReceivingFlowspec.TokenBucketSize,
                                      qos->ReceivingFlowspec.PeakBandwidth,
                                      qos->ReceivingFlowspec.Latency,
                                      qos->ReceivingFlowspec.DelayVariation,
#if defined(ACE_HAS_WINSOCK2_GQOS)
                                      qos->ReceivingFlowspec.ServiceType,
                                      qos->ReceivingFlowspec.MaxSduSize,
                                      qos->ReceivingFlowspec.MinimumPolicedSize,
#else /* ACE_HAS_WINSOCK2_GQOS */
                                      0,
                                      0,
                                      0,
#endif /* ACE_HAS_WINSOCK2_GQOS */
                                      0,
                                      0);

       ace_qos.sending_flowspec (sending_flowspec);
       ace_qos.receiving_flowspec (receiving_flowspec);
       ace_qos.provider_specific (*((struct iovec *) (&qos->ProviderSpecific)));


      return result;
    }

#else
  ACE_UNUSED_ARG (socket);
  ACE_UNUSED_ARG (io_control_code);
  ACE_UNUSED_ARG (ace_qos);
  ACE_UNUSED_ARG (bytes_returned);
  ACE_UNUSED_ARG (buffer_p);
  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (overlapped);
  ACE_UNUSED_ARG (func);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE int
ACE_OS::bind (ACE_HANDLE handle, struct sockaddr *addr, int addrlen)
{
  ACE_TRACE ("ACE_OS::bind");
#if defined (ACE_PSOS) && !defined (ACE_PSOS_DIAB_PPC)
  ACE_SOCKCALL_RETURN (::bind ((ACE_SOCKET) handle,
                               (struct sockaddr_in *) addr,
                               (ACE_SOCKET_LEN) addrlen),
                       int, -1);
#else /* !defined (ACE_PSOS) || defined (ACE_PSOS_DIAB_PPC) */
  ACE_SOCKCALL_RETURN (::bind ((ACE_SOCKET) handle,
                               addr,
                               (ACE_SOCKET_LEN) addrlen), int, -1);
#endif /* defined (ACE_PSOS) && !defined (ACE_PSOS_DIAB_PPC) */
}

ACE_INLINE int
ACE_OS::connect (ACE_HANDLE handle,
                 struct sockaddr *addr,
                 int addrlen)
{
  ACE_TRACE ("ACE_OS::connect");
#if defined (ACE_PSOS) && !defined (ACE_PSOS_DIAB_PPC)
  ACE_SOCKCALL_RETURN (::connect ((ACE_SOCKET) handle,
                                  (struct sockaddr_in *) addr,
                                  (ACE_SOCKET_LEN) addrlen),
                       int, -1);
#else  /* !defined (ACE_PSOS) || defined (ACE_PSOS_DIAB_PPC) */
  ACE_SOCKCALL_RETURN (::connect ((ACE_SOCKET) handle,
                                  addr,
                                  (ACE_SOCKET_LEN) addrlen), int, -1);
#endif /* defined (ACE_PSOS)  && !defined (ACE_PSOS_DIAB_PPC) */
}

ACE_INLINE int
ACE_OS::connect (ACE_HANDLE handle,
                 const sockaddr *addr,
                 int addrlen,
                 const ACE_QoS_Params &qos_params)
{
  ACE_TRACE ("ACE_OS::connect");
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  ACE_SOCKCALL_RETURN (::WSAConnect ((ACE_SOCKET) handle,
                                     (const sockaddr *) addr,
                                     (ACE_SOCKET_LEN) addrlen,
                                     (WSABUF *) qos_params.caller_data (),
                                     (WSABUF *) qos_params.callee_data (),
                                     (QOS *) qos_params.socket_qos (),
                                     (QOS *) qos_params.group_socket_qos ()),
                       int, -1);
#else
  ACE_UNUSED_ARG (qos_params);
  return ACE_OS::connect (handle,
                          (sockaddr *) addr,
                          addrlen);
#endif /* ACE_HAS_WINSOCK2 */
}

#if !defined (VXWORKS)
ACE_INLINE struct hostent *
ACE_OS::gethostbyname (const ACE_TCHAR *name)
{
  ACE_TRACE ("ACE_OS::gethostbyname");
# if defined (ACE_PSOS)
  ACE_UNUSED_ARG (name);
  ACE_NOTSUP_RETURN (0);
# elif defined (ACE_HAS_NONCONST_GETBY)
  ACE_SOCKCALL_RETURN (::gethostbyname (ACE_const_cast (char *, name)),
                       struct hostent *,
                       0);
# else
  ACE_SOCKCALL_RETURN (::gethostbyname (ACE_TEXT_ALWAYS_CHAR (name)),
                       struct hostent *,
                       0);
# endif /* ACE_HAS_NONCONST_GETBY */
}

ACE_INLINE struct hostent *
ACE_OS::gethostbyname2 (const ACE_TCHAR *name, int family)
{
  ACE_TRACE ("ACE_OS::gethostbyname2");
# if defined (ACE_PSOS)
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (family);
  ACE_NOTSUP_RETURN (0);
# elif defined (ACE_HAS_IP6)
#   if defined (ACE_HAS_NONCONST_GETBY)
  ACE_SOCKCALL_RETURN (::gethostbyname2 (ACE_const_cast (char *, name),
                                         family),
                       struct hostent *,
                       0);
#   else
  ACE_SOCKCALL_RETURN (::gethostbyname2 (ACE_TEXT_ALWAYS_CHAR (name), family),
                       struct hostent *,
                       0);
#   endif /* ACE_HAS_NONCONST_GETBY */
# else
  // IPv4-only implementation
  if (family == AF_INET)
    return ACE_OS::gethostbyname (name);

  ACE_NOTSUP_RETURN (0);
# endif /* ACE_PSOS */
}

ACE_INLINE struct hostent *
ACE_OS::gethostbyaddr (const ACE_TCHAR *addr, int length, int type)
{
  ACE_TRACE ("ACE_OS::gethostbyaddr");
# if defined (ACE_PSOS)
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (length);
  ACE_UNUSED_ARG (type);
  ACE_NOTSUP_RETURN (0);
# elif defined (ACE_HAS_NONCONST_GETBY)
  ACE_SOCKCALL_RETURN (::gethostbyaddr (ACE_const_cast (char *, addr),
                                        (ACE_SOCKET_LEN) length,
                                        type),
                       struct hostent *,
                       0);
# else
  ACE_SOCKCALL_RETURN (::gethostbyaddr (ACE_TEXT_ALWAYS_CHAR (addr),
                                        (ACE_SOCKET_LEN) length,
                                        type),
                       struct hostent *,
                       0);
# endif /* ACE_HAS_NONCONST_GETBY */
}
#endif /* ! VXWORKS */

// It would be really cool to add another version of select that would
// function like the one we're defending against below!
ACE_INLINE int
ACE_OS::select (int width,
                fd_set *rfds, fd_set *wfds, fd_set *efds,
                const ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_OS::select");
#if defined (ACE_HAS_NONCONST_SELECT_TIMEVAL)
  // We must defend against non-conformity!
  timeval copy;
  timeval *timep;

  if (timeout != 0)
    {
      copy = *timeout;
      timep = &copy;
    }
  else
    timep = 0;
#else
  const timeval *timep = (timeout == 0 ? (const timeval *)0 : *timeout);
#endif /* ACE_HAS_NONCONST_SELECT_TIMEVAL */
  ACE_SOCKCALL_RETURN (::select (width,
                                 (ACE_FD_SET_TYPE *) rfds,
                                 (ACE_FD_SET_TYPE *) wfds,
                                 (ACE_FD_SET_TYPE *) efds,
                                 timep),
                       int, -1);
}

ACE_INLINE int
ACE_OS::select (int width,
                fd_set *rfds, fd_set *wfds, fd_set *efds,
                const ACE_Time_Value &timeout)
{
  ACE_TRACE ("ACE_OS::select");
#if defined (ACE_HAS_NONCONST_SELECT_TIMEVAL)
# define ___ACE_TIMEOUT &copy
  timeval copy = timeout;
#else
# define ___ACE_TIMEOUT timep
  const timeval *timep = timeout;
#endif /* ACE_HAS_NONCONST_SELECT_TIMEVAL */
  ACE_SOCKCALL_RETURN (::select (width,
                                 (ACE_FD_SET_TYPE *) rfds,
                                 (ACE_FD_SET_TYPE *) wfds,
                                 (ACE_FD_SET_TYPE *) efds,
                                 ___ACE_TIMEOUT),
                       int, -1);
#undef ___ACE_TIMEOUT
}

ACE_INLINE int
ACE_OS::recv (ACE_HANDLE handle, char *buf, int len, int flags)
{
  ACE_TRACE ("ACE_OS::recv");

  // On UNIX, a non-blocking socket with no data to receive, this
  // system call will return EWOULDBLOCK or EAGAIN, depending on the
  // platform.  UNIX 98 allows either errno, and they may be the same
  // numeric value.  So to make life easier for upper ACE layers as
  // well as application programmers, always change EAGAIN to
  // EWOULDBLOCK.  Rather than hack the ACE_OSCALL_RETURN macro, it's
  // handled explicitly here.  If the ACE_OSCALL macro ever changes,
  // this function needs to be reviewed.  On Win32, the regular macros
  // can be used, as this is not an issue.
#if defined (ACE_WIN32)
  ACE_SOCKCALL_RETURN (::recv ((ACE_SOCKET) handle, buf, len, flags), int, -1);
#else

  int ace_result_;
  ace_result_ = ::recv ((ACE_SOCKET) handle, buf, len, flags);
  if (ace_result_ == -1 && errno == EAGAIN)
    errno = EWOULDBLOCK;
  return ace_result_;

#endif /* defined (ACE_WIN32) */
}

ACE_INLINE int
ACE_OS::recvfrom (ACE_HANDLE handle,
                  char *buf,
                  int len,
                  int flags,
                  struct sockaddr *addr,
                  int *addrlen)
{
  ACE_TRACE ("ACE_OS::recvfrom");
#if defined (ACE_PSOS)
#  if !defined ACE_PSOS_DIAB_PPC
  ACE_SOCKCALL_RETURN (::recvfrom ((ACE_SOCKET) handle, buf, (ACE_SOCKET_LEN) len, flags,
                                   (struct sockaddr_in *) addr, (ACE_SOCKET_LEN *) addrlen),
                       int, -1);
#  else
  ACE_SOCKCALL_RETURN (::recvfrom ((ACE_SOCKET) handle, buf, (ACE_SOCKET_LEN) len, flags,
                                   (struct sockaddr *) addr, (ACE_SOCKET_LEN *) addrlen),
                       int, -1);
#  endif /* defined ACE_PSOS_DIAB_PPC */
#elif defined (ACE_WIN32)
  int result = ::recvfrom ((ACE_SOCKET) handle,
                           buf,
                           (ACE_SOCKET_LEN) len,
                           flags,
                           addr,
                           (ACE_SOCKET_LEN *) addrlen);
  if (result == SOCKET_ERROR)
    {
      ACE_OS::set_errno_to_wsa_last_error ();
      if (errno == WSAEMSGSIZE &&
          ACE_BIT_ENABLED (flags, MSG_PEEK))
        return len;
      else
        return -1;
    }
  else
    return result;
#else /* non Win32 and non PSOS */
  ACE_SOCKCALL_RETURN (::recvfrom ((ACE_SOCKET) handle, buf, (ACE_SOCKET_LEN) len, flags,
                                   addr, (ACE_SOCKET_LEN *) addrlen),
                       int, -1);
#endif /* defined (ACE_PSOS) */
}

ACE_INLINE int
ACE_OS::send (ACE_HANDLE handle, const char *buf, int len, int flags)
{
  ACE_TRACE ("ACE_OS::send");
#if defined (VXWORKS) || defined (HPUX) || defined (ACE_PSOS)
  ACE_SOCKCALL_RETURN (::send ((ACE_SOCKET) handle, (char *) buf, len, flags), int, -1);
#else
  ACE_SOCKCALL_RETURN (::send ((ACE_SOCKET) handle, buf, len, flags), int, -1);
#endif /* VXWORKS */
}

ACE_INLINE int
ACE_OS::recvfrom (ACE_HANDLE handle,
                  iovec *buffers,
                  int buffer_count,
                  size_t &number_of_bytes_recvd,
                  int &flags,
                  struct sockaddr *addr,
                  int *addrlen,
                  ACE_OVERLAPPED *overlapped,
                  ACE_OVERLAPPED_COMPLETION_FUNC func)
{
  ACE_TRACE ("ACE_OS::recvfrom");

#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  DWORD bytes_recvd;
  DWORD the_flags = flags;
  int result = ::WSARecvFrom ((SOCKET) handle,
                              (WSABUF*)buffers,
                              buffer_count,
                              &bytes_recvd,
                              &the_flags,
                              addr,
                              addrlen,
                              overlapped,
                              func);
  flags = the_flags;
  number_of_bytes_recvd = ACE_static_cast (size_t, bytes_recvd);
  return result;
#else
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (buffers);
  ACE_UNUSED_ARG (buffer_count);
  ACE_UNUSED_ARG (number_of_bytes_recvd);
  ACE_UNUSED_ARG (flags);
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (addrlen);
  ACE_UNUSED_ARG (overlapped);
  ACE_UNUSED_ARG (func);
  ACE_NOTSUP_RETURN (-1);
#endif /* defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) */
}

ACE_INLINE int
ACE_OS::sendto (ACE_HANDLE handle,
                const char *buf,
                int len,
                int flags,
                const struct sockaddr *addr,
                int addrlen)
{
  ACE_TRACE ("ACE_OS::sendto");
#if defined (VXWORKS)
  ACE_SOCKCALL_RETURN (::sendto ((ACE_SOCKET) handle, (char *) buf, len, flags,
                                 ACE_const_cast (struct sockaddr *, addr), addrlen),
                       int, -1);
#elif defined (ACE_PSOS)
#  if !defined (ACE_PSOS_DIAB_PPC)
  ACE_SOCKCALL_RETURN (::sendto ((ACE_SOCKET) handle, (char *) buf, len, flags,
                                 (struct sockaddr_in *) addr, addrlen),
                       int, -1);
#  else
  ACE_SOCKCALL_RETURN (::sendto ((ACE_SOCKET) handle, (char *) buf, len, flags,
                                 (struct sockaddr *) addr, addrlen),
                       int, -1);
#  endif /*defined ACE_PSOS_DIAB_PPC */
#else
  ACE_SOCKCALL_RETURN (::sendto ((ACE_SOCKET) handle, buf, len, flags,
                                 ACE_const_cast (struct sockaddr *, addr), addrlen),
                       int, -1);
#endif /* VXWORKS */
}

ACE_INLINE int
ACE_OS::sendto (ACE_HANDLE handle,
                const iovec *buffers,
                int buffer_count,
                size_t &number_of_bytes_sent,
                int flags,
                const struct sockaddr *addr,
                int addrlen,
                ACE_OVERLAPPED *overlapped,
                ACE_OVERLAPPED_COMPLETION_FUNC func)
{
  ACE_TRACE ("ACE_OS::sendto");
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  DWORD bytes_sent;
  int result = ::WSASendTo ((SOCKET) handle,
                            (WSABUF*)buffers,
                            buffer_count,
                            &bytes_sent,
                            flags,
                            addr,
                            addrlen,
                            overlapped,
                            func);
  number_of_bytes_sent = ACE_static_cast (size_t, bytes_sent);
  return result;
#else
  ACE_UNUSED_ARG (overlapped);
  ACE_UNUSED_ARG (func);

  number_of_bytes_sent = 0;

  int result = 0;

  for (int i = 0; i < buffer_count; i++)
    {
       result = ACE_OS::sendto (handle,
                                ACE_reinterpret_cast (char *ACE_CAST_CONST,
                                                      buffers[i].iov_base),
                                buffers[i].iov_len,
                                flags,
                                addr,
                                addrlen);
       if (result == -1)
         break;
       number_of_bytes_sent += result;
    }

  return result;
#endif /* defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) */
}

ACE_INLINE int
ACE_OS::getpeername (ACE_HANDLE handle, struct sockaddr *addr,
                     int *addrlen)
{
  ACE_TRACE ("ACE_OS::getpeername");
#if defined (ACE_PSOS) && !defined ACE_PSOS_DIAB_PPC
  ACE_SOCKCALL_RETURN (::getpeername ((ACE_SOCKET) handle,
                                      (struct sockaddr_in *) addr,
                                      (ACE_SOCKET_LEN *) addrlen),
                       int, -1);
#else
  ACE_SOCKCALL_RETURN (::getpeername ((ACE_SOCKET) handle,
                                      addr,
                                      (ACE_SOCKET_LEN *) addrlen),
                       int, -1);
#endif /* defined (ACE_PSOS) */
}

ACE_INLINE struct protoent *
ACE_OS::getprotobyname (const ACE_TCHAR *name)
{
#if defined (VXWORKS) || defined (ACE_HAS_WINCE) || (defined (ghs) && defined (__Chorus)) || defined (ACE_PSOS)
  ACE_UNUSED_ARG (name);
  ACE_NOTSUP_RETURN (0);
#elif defined (ACE_HAS_NONCONST_GETBY)
  ACE_SOCKCALL_RETURN (::getprotobyname (ACE_const_cast (char *, name)),
                       struct protoent *,
                       0);
#else
  ACE_SOCKCALL_RETURN (::getprotobyname (ACE_TEXT_ALWAYS_CHAR (name)),
                       struct protoent *,
                       0);
#endif /* VXWORKS */
}

ACE_INLINE struct protoent *
ACE_OS::getprotobyname_r (const ACE_TCHAR *name,
                          struct protoent *result,
                          ACE_PROTOENT_DATA buffer)
{
#if defined (VXWORKS) || defined (ACE_HAS_WINCE) || (defined (ghs) && defined (__Chorus)) || defined (ACE_PSOS)
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (result);
  ACE_UNUSED_ARG (buffer);
  ACE_NOTSUP_RETURN (0);
#elif defined (ACE_HAS_REENTRANT_FUNCTIONS) && !defined (UNIXWARE)
# if defined (AIX) || defined (DIGITAL_UNIX) || defined (HPUX_10)
  if (::getprotobyname_r (name, result, (struct protoent_data *) buffer) == 0)
    return result;
  else
    return 0;
# else
#   if defined(ACE_LACKS_NETDB_REENTRANT_FUNCTIONS)
  ACE_UNUSED_ARG (result);
  ACE_NETDBCALL_RETURN (::getprotobyname (name),
                        struct protoent *, 0,
                        buffer, sizeof (ACE_PROTOENT_DATA));
#   else
    ACE_SOCKCALL_RETURN (::getprotobyname_r (name,
                                             result,
                                             buffer,
                                             sizeof (ACE_PROTOENT_DATA)),
                       struct protoent *, 0);
#   endif /* ACE_LACKS_NETDB_REENTRANT_FUNCTIONS */
# endif /* defined (AIX) || defined (DIGITAL_UNIX) */
#elif defined (ACE_HAS_NONCONST_GETBY)
  ACE_UNUSED_ARG (result);
  ACE_UNUSED_ARG (buffer);
  ACE_SOCKCALL_RETURN (::getprotobyname (ACE_const_cast (char *, name)),
                       struct protoent *, 0);
#else
  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (result);

  ACE_SOCKCALL_RETURN (::getprotobyname (ACE_TEXT_ALWAYS_CHAR (name)),
                       struct protoent *,
                       0);
#endif /* defined (ACE_HAS_REENTRANT_FUNCTIONS) !defined (UNIXWARE) */
}

ACE_INLINE struct protoent *
ACE_OS::getprotobynumber (int proto)
{
#if defined (VXWORKS) || defined (ACE_HAS_WINCE) || (defined (ghs) && defined (__Chorus)) || defined (ACE_PSOS)
  ACE_UNUSED_ARG (proto);
  ACE_NOTSUP_RETURN (0);
#else
  ACE_SOCKCALL_RETURN (::getprotobynumber (proto),
                       struct protoent *, 0);
#endif /* VXWORKS */
}

ACE_INLINE struct protoent *
ACE_OS::getprotobynumber_r (int proto,
                            struct protoent *result,
                            ACE_PROTOENT_DATA buffer)
{
#if defined (VXWORKS) || defined (ACE_HAS_WINCE) || (defined (ghs) && defined (__Chorus)) || defined (ACE_PSOS)
  ACE_UNUSED_ARG (proto);
  ACE_UNUSED_ARG (result);
  ACE_UNUSED_ARG (buffer);
  ACE_NOTSUP_RETURN (0);
#elif defined (ACE_HAS_REENTRANT_FUNCTIONS) && !defined (UNIXWARE)
# if defined (AIX) || defined (DIGITAL_UNIX) || defined (HPUX_10)
  if (::getprotobynumber_r (proto, result, (struct protoent_data *) buffer) == 0)
    return result;
  else
    return 0;
# else
#   if defined(ACE_LACKS_NETDB_REENTRANT_FUNCTIONS)
  ACE_UNUSED_ARG (result);
  ACE_NETDBCALL_RETURN (::getprotobynumber (proto),
                        struct protoent *, 0,
                        buffer, sizeof (ACE_PROTOENT_DATA));
#   else
  ACE_SOCKCALL_RETURN (::getprotobynumber_r (proto, result, buffer, sizeof (ACE_PROTOENT_DATA)),
                       struct protoent *, 0);
#   endif /* ACE_LACKS_NETDB_REENTRANT_FUNCTIONS */
# endif /* defined (AIX) || defined (DIGITAL_UNIX) */
#else
  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (result);

  ACE_SOCKCALL_RETURN (::getprotobynumber (proto),
                       struct protoent *, 0);
#endif /* defined (ACE_HAS_REENTRANT_FUNCTIONS) && !defined (UNIXWARE) */
}

ACE_INLINE struct servent *
ACE_OS::getservbyname (const ACE_TCHAR *svc, const ACE_TCHAR *proto)
{
  ACE_TRACE ("ACE_OS::getservbyname");
#if defined (ACE_LACKS_GETSERVBYNAME)
  ACE_UNUSED_ARG (svc);
  ACE_UNUSED_ARG (proto);
  ACE_NOTSUP_RETURN (0);
#elif defined (ACE_HAS_NONCONST_GETBY)
  ACE_SOCKCALL_RETURN (::getservbyname (ACE_const_cast (char *, svc),
                                        ACE_const_cast (char *, proto)),
                       struct servent *,
                       0);
#else
  ACE_SOCKCALL_RETURN (::getservbyname (ACE_TEXT_ALWAYS_CHAR (svc),
                                        ACE_TEXT_ALWAYS_CHAR (proto)),
                       struct servent *,
                       0);
#endif /* ACE_HAS_NONCONST_GETBY */
}

ACE_INLINE int
ACE_OS::getsockname (ACE_HANDLE handle,
                     struct sockaddr *addr,
                     int *addrlen)
{
  ACE_TRACE ("ACE_OS::getsockname");
#if defined (ACE_PSOS) && !defined (ACE_PSOS_DIAB_PPC)
  ACE_SOCKCALL_RETURN (::getsockname ((ACE_SOCKET) handle,
                                      (struct sockaddr_in *) addr,
                                      (ACE_SOCKET_LEN *) addrlen),
                       int, -1);
#else
  ACE_SOCKCALL_RETURN (::getsockname ((ACE_SOCKET) handle,
                                      addr,
                                      (ACE_SOCKET_LEN *) addrlen),
                       int, -1);
#endif /* defined (ACE_PSOS) */
}

ACE_INLINE int
ACE_OS::getsockopt (ACE_HANDLE handle,
                    int level,
                    int optname,
                    char *optval,
                    int *optlen)
{
  ACE_TRACE ("ACE_OS::getsockopt");
  ACE_SOCKCALL_RETURN (::getsockopt ((ACE_SOCKET) handle,
                                     level,
                                     optname,
                                     optval,
                                     (ACE_SOCKET_LEN *) optlen),
                       int,
                       -1);
}

ACE_INLINE int
ACE_OS::listen (ACE_HANDLE handle, int backlog)
{
  ACE_TRACE ("ACE_OS::listen");
  ACE_SOCKCALL_RETURN (::listen ((ACE_SOCKET) handle, backlog), int, -1);
}

ACE_INLINE int
ACE_OS::setsockopt (ACE_HANDLE handle,
                    int level,
                    int optname,
                    const char *optval,
                    int optlen)
{
  ACE_TRACE ("ACE_OS::setsockopt");
  ACE_SOCKCALL_RETURN (::setsockopt ((ACE_SOCKET) handle,
                                     level,
                                     optname,
                                     (ACE_SOCKOPT_TYPE1) optval,
                                     optlen),
                       int,
                       -1);
}

ACE_INLINE int
ACE_OS::shutdown (ACE_HANDLE handle, int how)
{
  ACE_TRACE ("ACE_OS::shutdown");
  ACE_SOCKCALL_RETURN (::shutdown ((ACE_SOCKET) handle, how), int, -1);
}

ACE_INLINE ACE_HANDLE
ACE_OS::socket (int domain,
                int type,
                int proto)
{
  ACE_TRACE ("ACE_OS::socket");
  ACE_SOCKCALL_RETURN (::socket (domain,
                                 type,
                                 proto),
                       ACE_HANDLE,
                       ACE_INVALID_HANDLE);
}

ACE_INLINE ACE_HANDLE
ACE_OS::socket (int domain,
                int type,
                int proto,
                ACE_Protocol_Info *protocolinfo,
                ACE_SOCK_GROUP g,
                u_long flags)
{
  ACE_TRACE ("ACE_OS::socket");

#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  ACE_SOCKCALL_RETURN (::WSASocket (domain,
                                    type,
                                    proto,
                                    protocolinfo,
                                    g,
                                    flags),
                       ACE_HANDLE,
                       ACE_INVALID_HANDLE);
#else
  ACE_UNUSED_ARG (protocolinfo);
  ACE_UNUSED_ARG (g);
  ACE_UNUSED_ARG (flags);

  return ACE_OS::socket (domain,
                         type,
                         proto);
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE int
ACE_OS::atoi (const ACE_TCHAR *s)
{
  ACE_TRACE ("ACE_OS::atoi");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_atoi (s), int, -1);
#elif defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
  ACE_OSCALL_RETURN (::_wtoi (s), int, -1);
#else /* ACE_WIN32 */
  ACE_OSCALL_RETURN (::atoi (s), int, -1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE double
ACE_OS::floor (double x)
{
  // This method computes the largest integral value not greater than x.
  return double (ACE_static_cast (long, x));
}

ACE_INLINE double
ACE_OS::ceil (double x)
{
  // This method computes the smallest integral value not less than x.
  double floor = ACE_OS::floor (x);
  if (floor == x)
    return floor;
  else
    return floor + 1;
}

ACE_INLINE int
ACE_OS::recvmsg (ACE_HANDLE handle, struct msghdr *msg, int flags)
{
  ACE_TRACE ("ACE_OS::recvmsg");
#if !defined (ACE_LACKS_RECVMSG)
# if (defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0))
  DWORD bytes_received = 0;

  int result = ::WSARecvFrom ((SOCKET) handle,
                              (WSABUF *) msg->msg_iov,
                              msg->msg_iovlen,
                              &bytes_received,
                              (DWORD *) &flags,
                              msg->msg_name,
                              &msg->msg_namelen,
                              0,
                              0);

  if (result != 0)
    {
      ACE_OS::set_errno_to_last_error ();
      return -1;
    }
  else
    return (ssize_t) bytes_received;
# else /* ACE_HAS_WINSOCK2 */
  ACE_SOCKCALL_RETURN (::recvmsg (handle, msg, flags), int, -1);
# endif /* ACE_HAS_WINSOCK2 */
#else
  ACE_UNUSED_ARG (flags);
  ACE_UNUSED_ARG (msg);
  ACE_UNUSED_ARG (handle);

  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_LACKS_RECVMSG */
}

ACE_INLINE int
ACE_OS::sendmsg (ACE_HANDLE handle,
                 const struct msghdr *msg,
                 int flags)
{
  ACE_TRACE ("ACE_OS::sendmsg");
#if !defined (ACE_LACKS_SENDMSG)
# if (defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0))
  DWORD bytes_sent = 0;
  int result = ::WSASendTo ((SOCKET) handle,
                            (WSABUF *) msg->msg_iov,
                            msg->msg_iovlen,
                            &bytes_sent,
                            flags,
                            msg->msg_name,
                            msg->msg_namelen,
                            0,
                            0);

  if (result != 0)
    {
      ACE_OS::set_errno_to_last_error ();
      return -1;
    }
  else
    return (ssize_t) bytes_sent;
# elif defined (ACE_LACKS_POSIX_PROTOTYPES) ||  defined (ACE_PSOS)
  ACE_SOCKCALL_RETURN (::sendmsg (handle, (struct msghdr *) msg, flags), int, -1);
# else
  ACE_SOCKCALL_RETURN (::sendmsg (handle, (ACE_SENDMSG_TYPE *) msg, flags), int, -1);
# endif /* ACE_LACKS_POSIX_PROTOTYPES */
#else
  ACE_UNUSED_ARG (flags);
  ACE_UNUSED_ARG (msg);
  ACE_UNUSED_ARG (handle);

  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_LACKS_SENDMSG */
}

ACE_INLINE int
ACE_OS::fclose (FILE *fp)
{
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_fclose (fp), int, -1);
#elif !defined (ACE_HAS_WINCE)
  ACE_TRACE ("ACE_OS::fclose");
  ACE_OSCALL_RETURN (::fclose (fp), int, -1);
#else
  // On CE, FILE * == void * == HANDLE
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL(::CloseHandle (fp), ace_result_),
                        int, -1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE ACE_TCHAR *
ACE_OS::fgets (ACE_TCHAR *buf, int size, FILE *fp)
{
  ACE_TRACE ("ACE_OS::fgets");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_fgets (buf, size, fp), char*, 0);
#elif defined (ACE_HAS_WINCE)
  ACE_UNUSED_ARG (buf);
  ACE_UNUSED_ARG (size);
  ACE_UNUSED_ARG (fp);
  ACE_NOTSUP_RETURN (0);
#elif defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
  ACE_OSCALL_RETURN (::fgetws (buf, size, fp), wchar_t *, 0);
#else /* ACE_WIN32 */
  ACE_OSCALL_RETURN (::fgets (buf, size, fp), char *, 0);
#endif /* ACE_HAS_PACE */
}

#if !defined (ACE_WIN32)
// Win32 implementation of fopen(const ACE_TCHAR*, const ACE_TCHAR*)
// is in OS.cpp.
ACE_INLINE FILE *
ACE_OS::fopen (const ACE_TCHAR *filename, const ACE_TCHAR *mode)
{
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_fopen (filename, mode), FILE*, 0);
#else
  ACE_TRACE ("ACE_OS::fopen");
  ACE_OSCALL_RETURN (::fopen (filename, mode), FILE *, 0);
#endif /* ACE_HAS_PACE */
}
#endif /* ACE_WIN32 */

ACE_INLINE int
ACE_OS::fflush (FILE *fp)
{
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_fflush (fp), int, -1);
#elif !defined (ACE_HAS_WINCE)
  ACE_TRACE ("ACE_OS::fflush");
  ACE_OSCALL_RETURN (::fflush (fp), int, -1);
#else
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL(::FlushFileBuffers (fp),
                                         ace_result_),
                        int, -1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE size_t
ACE_OS::fread (void *ptr, size_t size, size_t nelems, FILE *fp)
{
  ACE_TRACE ("ACE_OS::fread");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_fread (ptr, size, nelems, fp), int, 0);
#elif defined (ACE_HAS_WINCE)
  DWORD len = 0;
  size_t tlen = size * nelems;

  if (::ReadFile (fp, ptr, tlen, &len, NULL) == FALSE)
    {
      ACE_OS::set_errno_to_last_error ();
      return -1;
    }
  else if (tlen != len)
    {
      // only return length of multiple of <size>
      len = (len / size) * size ;
      // then rewind file pointer.
      ::SetFilePointer (fp, (len - tlen), 0, FILE_CURRENT);
    }
  return len;
#elif defined (ACE_LACKS_POSIX_PROTOTYPES)
  ACE_OSCALL_RETURN (::fread ((char *) ptr, size, nelems, fp), int, 0);
#else
  ACE_OSCALL_RETURN (::fread (ptr, size, nelems, fp), int, 0);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE size_t
ACE_OS::fwrite (const void *ptr, size_t size, size_t nitems, FILE *fp)
{
  ACE_TRACE ("ACE_OS::fwrite");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_fwrite (ptr, size, nitems, fp), int, 0);
#elif defined (ACE_HAS_WINCE)
  DWORD len = 0;
  size_t tlen = size * nitems;

  if (::WriteFile (fp, ptr, tlen, &len, NULL) == FALSE)
    {
      ACE_OS::set_errno_to_last_error ();
      return -1;
    }
  else if (tlen != len)
    {
      // only return length of multiple of <size>
      len = (len / size) * size ;
      // then rewind file pointer.
      ::SetFilePointer (fp, (len - tlen), 0, FILE_CURRENT);
    }
  return len;
#elif defined (ACE_LACKS_POSIX_PROTOTYPES)
  ACE_OSCALL_RETURN (::fwrite ((const char *) ptr, size, nitems, fp), int, 0);
#else
  ACE_OSCALL_RETURN (::fwrite (ptr, size, nitems, fp), int, 0);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::truncate (const ACE_TCHAR *filename,
                  off_t offset)
{
  ACE_TRACE ("ACE_OS::truncate");
#if defined (ACE_HAS_PACE)
  int fd = pace_open (filename, O_RDWR, ACE_DEFAULT_FILE_PERMS);
  int result = 0;
  if (fd == -1)
    return -1;
  ACE_OSCALL (pace_ftruncate (fd, offset), int, -1, result);
  pace_close (fd);
  return result;
#elif defined (ACE_WIN32)
  ACE_HANDLE handle = ACE_OS::open (filename,
                                    O_WRONLY,
                                    ACE_DEFAULT_FILE_PERMS);
  if (handle == ACE_INVALID_HANDLE)
    ACE_FAIL_RETURN (-1);
  else
    {
      if (::SetFilePointer (handle,
                            offset,
                            NULL,
                            FILE_BEGIN) != (unsigned) -1)
        ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::SetEndOfFile (handle),
                                                ace_result_), int, -1);
      else
        ACE_FAIL_RETURN (-1);
    }
  /* NOTREACHED */
#elif !defined (ACE_LACKS_TRUNCATE)
  ACE_OSCALL_RETURN (::truncate (filename, offset), int, -1);
#else
  ACE_UNUSED_ARG (filename);
  ACE_UNUSED_ARG (offset);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_PACE */
}

// Accessors to PWD file.

ACE_INLINE struct passwd *
ACE_OS::getpwnam (const char *name)
{
#if defined (ACE_HAS_PACE)
  return pace_getpwnam (name);
#elif !defined (ACE_LACKS_PWD_FUNCTIONS)
# if !defined (ACE_WIN32)
  return ::getpwnam (name);
# else
  ACE_UNUSED_ARG (name);
  ACE_NOTSUP_RETURN (0);
# endif /* ACE_WIN32 */
#else
  ACE_UNUSED_ARG (name);
  ACE_NOTSUP_RETURN (0);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE void
ACE_OS::setpwent (void)
{
#if !defined (ACE_LACKS_PWD_FUNCTIONS)
# if !defined (ACE_WIN32)
  ::setpwent ();
# else
# endif /* ACE_WIN32 */
#else
#endif /* ! ACE_LACKS_PWD_FUNCTIONS */
}

ACE_INLINE void
ACE_OS::endpwent (void)
{
#if !defined (ACE_LACKS_PWD_FUNCTIONS)
# if !defined (ACE_WIN32)
  ::endpwent ();
# else
# endif /* ACE_WIN32 */
#else
#endif /* ! ACE_LACKS_PWD_FUNCTIONS */
}

ACE_INLINE struct passwd *
ACE_OS::getpwent (void)
{
#if !defined (ACE_LACKS_PWD_FUNCTIONS)
# if !defined (ACE_WIN32)
  return ::getpwent ();
# else
  ACE_NOTSUP_RETURN (0);
# endif /* ACE_WIN32 */
#else
  ACE_NOTSUP_RETURN (0);
#endif /* ! ACE_LACKS_PWD_FUNCTIONS */
}

ACE_INLINE struct passwd *
ACE_OS::getpwnam_r (const char *name, struct passwd *pwent,
                    char *buffer, int buflen)
{
#if defined (ACE_HAS_PACE)
  struct passwd *result;
  int status;

  status = pace_getpwnam_r (name, pwent, buffer, buflen, &result);
  if (status != 0)
  {
    errno = status;
    result = 0;
  }
  return result;
#elif !defined (ACE_LACKS_PWD_FUNCTIONS)
# if defined (ACE_HAS_REENTRANT_FUNCTIONS)
#   if !defined (ACE_LACKS_PWD_REENTRANT_FUNCTIONS)
#     if defined (ACE_HAS_PTHREADS_STD) && \
      !defined (ACE_HAS_STHREADS) || \
      defined (__USLC__) // Added by Roland Gigler for SCO UnixWare 7.
  struct passwd *result;
  int status;
#       if defined (DIGITAL_UNIX)
  ::_Pgetpwnam_r (name, pwent, buffer, buflen, &result);
#       else
  // VAC++ doesn't correctly grok the ::getpwnam_r - the function is redefined
  // in pwd.h, and that redefinition is used here
#         if defined (__IBMCPP__) && (__IBMCPP__ >= 400)   /* VAC++ 4 */
  status = _posix_getpwnam_r (name, pwent, buffer, buflen, &result);
#         else
  status = ::getpwnam_r (name, pwent, buffer, buflen, &result);
#         endif /* __IBMCPP__ && (__IBMCPP__ >= 400) */
  if (status != 0)
    {
      errno = status;
      result = 0;
    }
#       endif /* (DIGITAL_UNIX) */
  return result;
#     elif defined (AIX) || defined (HPUX_10)
  if (::getpwnam_r (name, pwent, buffer, buflen) == -1)
    return 0;
  else
    return pwent;
#     else
  return ::getpwnam_r (name, pwent, buffer, buflen);
#     endif /* ACE_HAS_PTHREADS_STD */
#   else
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (pwent);
  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (buflen);
  ACE_NOTSUP_RETURN (0);
#   endif /* ! ACE_LACKS_PWD_REENTRANT_FUNCTIONS */
# else
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (pwent);
  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (buflen);
  ACE_NOTSUP_RETURN (0);
# endif /* ACE_HAS_REENTRANT_FUNCTIONS */
#else
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (pwent);
  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (buflen);
  ACE_NOTSUP_RETURN (0);
#endif /* ACE_HAS_PACE */
}

// DNS accessors.

#if !defined (VXWORKS)
ACE_INLINE struct hostent *
ACE_OS::gethostbyaddr_r (const ACE_TCHAR *addr,
                         int length,
                         int type,
                         hostent *result,
                         ACE_HOSTENT_DATA buffer,
                         int *h_errnop)
{
  ACE_TRACE ("ACE_OS::gethostbyaddr_r");
# if defined (ACE_PSOS)
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (length);
  ACE_UNUSED_ARG (type);
  ACE_UNUSED_ARG (result);
  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (h_errnop);
  ACE_NOTSUP_RETURN (0);
# elif defined (ACE_HAS_REENTRANT_FUNCTIONS) && !defined (UNIXWARE)
#   if defined (AIX) || defined (DIGITAL_UNIX) || defined (HPUX_10)
  ::memset (buffer, 0, sizeof (ACE_HOSTENT_DATA));

  if (::gethostbyaddr_r ((char *) addr, length, type, result,
                         (struct hostent_data *) buffer)== 0)
    return result;
  else
    {
      *h_errnop = h_errno;
      return (struct hostent *) 0;
    }
#   else
#     if defined(ACE_LACKS_NETDB_REENTRANT_FUNCTIONS)
  ACE_UNUSED_ARG (result);
  ACE_UNUSED_ARG (h_errnop);
  ACE_NETDBCALL_RETURN (::gethostbyaddr (addr, (ACE_SOCKET_LEN) length, type),
                        struct hostent *, 0,
                        buffer, sizeof (ACE_HOSTENT_DATA));
#     else
  ACE_SOCKCALL_RETURN (::gethostbyaddr_r (addr, length, type, result,
                                          buffer, sizeof (ACE_HOSTENT_DATA),
                                          h_errnop),
                       struct hostent *, 0);
#     endif /* ACE_LACKS_NETDB_REENTRANT_FUNCTIONS */
#   endif /* defined (AIX) || defined (DIGITAL_UNIX) */
# elif defined (ACE_HAS_NONCONST_GETBY)
  ACE_UNUSED_ARG (result);
  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (h_errnop);
  ACE_SOCKCALL_RETURN (::gethostbyaddr (ACE_const_cast (char *, addr),
                                        (ACE_SOCKET_LEN) length,
                                        type),
                       struct hostent *,
                       0);
# else
  ACE_UNUSED_ARG (h_errnop);
  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (result);

  ACE_SOCKCALL_RETURN (::gethostbyaddr (ACE_TEXT_ALWAYS_CHAR (addr),
                                        (ACE_SOCKET_LEN) length,
                                        type),
                       struct hostent *,
                       0);
# endif /* defined (ACE_HAS_REENTRANT_FUNCTIONS) && !defined (UNIXWARE) */
}

ACE_INLINE struct hostent *
ACE_OS::gethostbyname_r (const ACE_TCHAR *name,
                         hostent *result,
                         ACE_HOSTENT_DATA buffer,
                         int *h_errnop)
{
  ACE_TRACE ("ACE_OS::gethostbyname_r");
#if defined (ACE_PSOS)
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (result);
  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (h_errnop);
  ACE_NOTSUP_RETURN (0);
# elif defined (ACE_HAS_REENTRANT_FUNCTIONS) && !defined (UNIXWARE)
#   if defined (DIGITAL_UNIX) || \
       (defined (ACE_AIX_MINOR_VERS) && (ACE_AIX_MINOR_VERS > 2))
  ACE_UNUSED_ARG (result);
  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (h_errnop);

  // gethostbyname returns thread-specific storage on Digital Unix and
  // AIX 4.3
  ACE_SOCKCALL_RETURN (::gethostbyname (name), struct hostent *, 0);
#   elif defined (AIX) || defined (HPUX_10)
  ::memset (buffer, 0, sizeof (ACE_HOSTENT_DATA));

  if (::gethostbyname_r (name, result, (struct hostent_data *) buffer) == 0)
    return result;
  else
    {
      *h_errnop = h_errno;
      return (struct hostent *) 0;
    }
#   else
#     if defined(ACE_LACKS_NETDB_REENTRANT_FUNCTIONS)
  ACE_UNUSED_ARG (result);
  ACE_UNUSED_ARG (h_errnop);
  ACE_NETDBCALL_RETURN (::gethostbyname (name),
                        struct hostent *, 0,
                        buffer, sizeof (ACE_HOSTENT_DATA));
#     else
  ACE_SOCKCALL_RETURN (::gethostbyname_r (name, result, buffer,
                                          sizeof (ACE_HOSTENT_DATA),
                                          h_errnop),
                       struct hostent *,
                       0);
#     endif /* ACE_LACKS_NETDB_REENTRANT_FUNCTIONS */
#   endif /* defined (AIX) || defined (DIGITAL_UNIX) */
# elif defined (ACE_HAS_NONCONST_GETBY)
  ACE_UNUSED_ARG (result);
  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (h_errnop);
  ACE_SOCKCALL_RETURN (::gethostbyname (ACE_const_cast (char *, name)),
                       struct hostent *,
                       0);
# else
  ACE_UNUSED_ARG (result);
  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (h_errnop);

  ACE_SOCKCALL_RETURN (::gethostbyname (ACE_TEXT_ALWAYS_CHAR (name)),
                       struct hostent *,
                       0);
# endif /* defined (ACE_HAS_REENTRANT_FUNCTIONS) && !defined (UNIXWARE) */
}
#endif /* ! VXWORKS */

#if 0
// @@ gets is evil anyway.
//    and it is *** DEPRECATED *** now.  If you
//    really needs gets, use ACE_OS::gets (char*, int)
//    instead.
ACE_INLINE char *
ACE_OS::gets (char *str)
{
  ACE_TRACE ("ACE_OS::gets");
  ACE_OSCALL_RETURN (::gets (str), char *, 0);
}
#endif /* 0 */

ACE_INLINE struct servent *
ACE_OS::getservbyname_r (const ACE_TCHAR *svc,
                         const ACE_TCHAR *proto,
                         struct servent *result,
                         ACE_SERVENT_DATA buf)
{
  ACE_TRACE ("ACE_OS::getservbyname_r");
#if defined (ACE_LACKS_GETSERVBYNAME)
  ACE_UNUSED_ARG (svc);
  ACE_UNUSED_ARG (proto);
  ACE_UNUSED_ARG (result);
  ACE_UNUSED_ARG (buf);
  ACE_NOTSUP_RETURN (0);
#elif defined (ACE_HAS_REENTRANT_FUNCTIONS) && !defined (UNIXWARE)
# if defined (AIX) || defined (DIGITAL_UNIX) || defined (HPUX_10)
  ::memset (buf, 0, sizeof (ACE_SERVENT_DATA));

  if (::getservbyname_r (svc, proto, result, (struct servent_data *) buf) == 0)
    return result;
  else
    return (struct servent *) 0;
# else
#   if defined(ACE_LACKS_NETDB_REENTRANT_FUNCTIONS)
  ACE_UNUSED_ARG (result);
  ACE_NETDBCALL_RETURN (::getservbyname (svc, proto),
                        struct servent *, 0,
                        buf, sizeof (ACE_SERVENT_DATA));
#   else
  ACE_SOCKCALL_RETURN (::getservbyname_r (svc, proto, result, buf,
                                          sizeof (ACE_SERVENT_DATA)),
                       struct servent *, 0);
#   endif /* ACE_LACKS_NETDB_REENTRANT_FUNCTIONS */
# endif /* defined (AIX) || defined (DIGITAL_UNIX) */
#elif defined (ACE_HAS_NONCONST_GETBY)
  ACE_UNUSED_ARG (buf);
  ACE_UNUSED_ARG (result);
  ACE_SOCKCALL_RETURN (::getservbyname (ACE_const_cast (char *, svc),
                                        ACE_const_cast (char *, proto)),
                       struct servent *,
                       0);
#else
  ACE_UNUSED_ARG (buf);
  ACE_UNUSED_ARG (result);

  ACE_SOCKCALL_RETURN (::getservbyname (ACE_TEXT_ALWAYS_CHAR (svc),
                                        ACE_TEXT_ALWAYS_CHAR (proto)),
                       struct servent *,
                       0);
#endif /* defined (ACE_HAS_REENTRANT_FUNCTIONS) && !defined (UNIXWARE) */
}

ACE_INLINE long
ACE_OS::inet_addr (const ACE_TCHAR *name)
{
  ACE_TRACE ("ACE_OS::inet_addr");
#if defined (VXWORKS) || defined (ACE_PSOS)

  u_long ret = 0;
  u_int segment;
  u_int valid = 1;

  for (u_int i = 0; i < 4; ++i)
    {
      ret <<= 8;
      if (*name != '\0')
        {
          segment = 0;

          while (*name >= '0'  &&  *name <= '9')
            {
              segment *= 10;
              segment += *name++ - '0';
            }
          if (*name != '.' && *name != '\0')
            {
              valid = 0;
              break;
            }

          ret |= segment;

          if (*name == '.')
            {
              ++name;
            }
        }
    }
  return valid ? (long) htonl (ret) : -1L;
#elif defined (ACE_HAS_NONCONST_GETBY)
  return ::inet_addr ((char *) name);
#else
  return ::inet_addr (ACE_TEXT_ALWAYS_CHAR (name));
#endif /* ACE_HAS_NONCONST_GETBY */
}

// For pSOS, this function is in OS.cpp
#if !defined (ACE_PSOS)
ACE_INLINE ACE_TCHAR *
ACE_OS::inet_ntoa (const struct in_addr addr)
{
  ACE_TRACE ("ACE_OS::inet_ntoa");
  ACE_OSCALL_RETURN (ACE_TEXT_CHAR_TO_TCHAR (::inet_ntoa (addr)),
                                             ACE_TCHAR *,
                     0);
}
#endif /* defined (ACE_PSOS) */

ACE_INLINE int
ACE_OS::inet_pton (int family, const ACE_TCHAR *strptr, void *addrptr)
{
  ACE_TRACE ("ACE_OS::inet_pton");

#if defined (ACE_HAS_IP6)
  ACE_OSCALL_RETURN (::inet_pton (family, strptr, addrptr), int, -1);
#else
  if (family == AF_INET)
    {
      struct in_addr in_val;

      if (ACE_OS::inet_aton (strptr, &in_val))
        {
          ACE_OS::memcpy (addrptr, &in_val, sizeof (struct in_addr));
          return 1; // Success
        }

      return 0; // Input is not a valid presentation format
    }

  ACE_NOTSUP_RETURN(-1);
#endif  /* ACE_HAS_IP6 */
}

ACE_INLINE const ACE_TCHAR *
ACE_OS::inet_ntop (int family, const void *addrptr, ACE_TCHAR *strptr, size_t len)
{
  ACE_TRACE ("ACE_OS::inet_ntop");

#if defined (ACE_HAS_IP6)
  ACE_OSCALL_RETURN (::inet_ntop (family, addrptr, strptr, len), const char *, 0);
#else
  const u_char *p =
    ACE_reinterpret_cast (const u_char *, addrptr);

  if (family == AF_INET)
    {
      ACE_TCHAR temp[INET_ADDRSTRLEN];

      // Stevens uses snprintf() in his implementation but snprintf()
      // doesn't appear to be very portable.  For now, hope that using
      // sprintf() will not cause any string/memory overrun problems.
      ACE_OS::sprintf (temp,
                       ACE_TEXT ("%d.%d.%d.%d"),
                       p[0], p[1], p[2], p[3]);

      if (ACE_OS::strlen (temp) >= len)
        {
          errno = ENOSPC;
          return 0; // Failure
        }

      ACE_OS::strcpy (strptr, temp);
      return strptr;
    }

  ACE_NOTSUP_RETURN(0);
#endif /* ACE_HAS_IP6 */
}

ACE_INLINE int
ACE_OS::set_errno_to_last_error (void)
{
# if defined (ACE_WIN32)
// Borland C++ Builder 4 has a bug in the RTL that resets the
// <GetLastError> value to zero when errno is accessed.  Thus, we have
// to use this to set errno to GetLastError.  It's bad, but only for
// WIN32
#   if defined(__BORLANDC__) && (__BORLANDC__ == 0x540) || defined (__IBMCPP__) && (__IBMCPP__ >= 400)
  int last_error = ::GetLastError ();
  return errno = last_error;
#   else /* defined(__BORLANDC__) && (__BORLANDC__ == 0x540) */
  return errno = ::GetLastError ();
#   endif /* defined(__BORLANDC__) && (__BORLANDC__ == 0x540) */
#else
  return errno;
# endif /* defined(ACE_WIN32) */
}

ACE_INLINE int
ACE_OS::set_errno_to_wsa_last_error (void)
{
# if defined (ACE_WIN32)
// Borland C++ Builder 4 has a bug in the RTL that resets the
// <GetLastError> value to zero when errno is accessed.  Thus, we have
// to use this to set errno to GetLastError.  It's bad, but only for
// WIN32
#   if defined(__BORLANDC__) && (__BORLANDC__ == 0x540) || defined (__IBMCPP__) && (__IBMCPP__ >= 400)
  int last_error = ::WSAGetLastError ();
  return errno = last_error;
#   else /* defined(__BORLANDC__) && (__BORLANDC__ == 0x540) */
  return errno = ::WSAGetLastError ();
#   endif /* defined(__BORLANDC__) && (__BORLANDC__ == 0x540) */
#else
  return errno;
# endif /* defined(ACE_WIN32) */
}

ACE_INLINE int
ACE_OS::last_error (void)
{
  // ACE_TRACE ("ACE_OS::last_error");

#if defined (ACE_WIN32)
  int lerror = ::GetLastError ();
  int lerrno = errno;
  return lerrno == 0 ? lerror : lerrno;
#else
  return errno;
#endif /* ACE_WIN32 */
}

ACE_INLINE void
ACE_OS::last_error (int error)
{
  ACE_TRACE ("ACE_OS::last_error");
#if defined (ACE_WIN32)
  ::SetLastError (error);
#else
  errno = error;
#endif /* ACE_WIN32 */
}

ACE_INLINE void
ACE_OS::perror (const ACE_TCHAR *s)
{
  ACE_TRACE ("ACE_OS::perror");
#if defined (ACE_HAS_PACE)
  pace_perror (s);
#elif defined (ACE_HAS_WINCE)
  // @@ WINCE: How should this be handled
  ACE_UNUSED_ARG (s);
#elif defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
  ::_wperror (s);
#else
  ::perror (s);
#endif /* ACE_HAS_PACE */
}


// @@ WINCE: Do we need to implement puts on WinCE???
#if !defined (ACE_HAS_WINCE)
ACE_INLINE int
ACE_OS::puts (const ACE_TCHAR *s)
{
  ACE_TRACE ("ACE_OS::puts");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_puts (s), int, -1);
#elif defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
  ACE_OSCALL_RETURN (::_putws (s), int, -1);
#else /* ACE_WIN32 */
  ACE_OSCALL_RETURN (::puts (s), int, -1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::fputs (const ACE_TCHAR *s, FILE *stream)
{
  ACE_TRACE ("ACE_OS::fputs");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_fputs (s, stream), int, -1);
#elif defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
  ACE_OSCALL_RETURN (::fputws (s, stream), int, -1);
#else /* ACE_WIN32 */
  ACE_OSCALL_RETURN (::fputs (s, stream), int, -1);
#endif /* ACE_HAS_PACE */
}
#endif /* ! ACE_HAS_WINCE */

ACE_INLINE ACE_SignalHandler
ACE_OS::signal (int signum, ACE_SignalHandler func)
{
  if (signum == 0)
    return 0;
  else
#if defined (ACE_HAS_PACE)
    return pace_signal (signum, func);
#elif defined (ACE_PSOS) && !defined (ACE_PSOS_TM) && !defined (ACE_PSOS_DIAB_MIPS) && !defined (ACE_PSOS_DIAB_PPC)
    return (ACE_SignalHandler) ::signal (signum, (void (*)(void)) func);
#elif defined (ACE_PSOS_DIAB_MIPS) || defined (ACE_PSOS_DIAB_PPC)
    return 0;
#elif defined (ACE_PSOS_TM)
    // @@ It would be good to rework this so the ACE_PSOS_TM specific
    //    branch is not needed, but prying it out of ACE_LACKS_UNIX_SIGNALS
    //    will take some extra work - deferred for now.
    return (ACE_SignalHandler) ::signal (signum, (void (*)(int)) func);
#elif defined (ACE_WIN32) && !defined (ACE_HAS_WINCE) || !defined (ACE_LACKS_UNIX_SIGNALS)
#  if !defined (ACE_HAS_TANDEM_SIGNALS) && !defined (ACE_HAS_LYNXOS_SIGNALS)
    return ::signal (signum, func);
#  else
    return (ACE_SignalHandler) ::signal (signum, (void (*)(int)) func);
#  endif /* !ACE_HAS_TANDEM_SIGNALS */
#else
    // @@ WINCE: Don't know how to implement signal on WinCE (yet.)
    ACE_UNUSED_ARG (signum);
    ACE_UNUSED_ARG (func);
    ACE_NOTSUP_RETURN (0);     // Should return SIG_ERR but it is not defined on WinCE.
#endif /*  ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::system (const ACE_TCHAR *s)
{
  // ACE_TRACE ("ACE_OS::system");
#if defined (CHORUS) || defined (ACE_HAS_WINCE) || defined(ACE_PSOS)
  ACE_UNUSED_ARG (s);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
  ACE_OSCALL_RETURN (::_wsystem (s), int, -1);
#else
  ACE_OSCALL_RETURN (::system (s), int, -1);
#endif /* !CHORUS */
}

ACE_INLINE int
ACE_OS::thr_continue (ACE_hthread_t target_thread)
{
  ACE_TRACE ("ACE_OS::thr_continue");
#if defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_STHREADS)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::thr_continue (target_thread), ace_result_), int, -1);
# elif defined (ACE_HAS_PTHREADS)
#  if defined (ACE_HAS_PTHREADS_UNIX98_EXT)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pthread_continue (target_thread),
                                       ace_result_),
                     int, -1);
#  else
  ACE_UNUSED_ARG (target_thread);
  ACE_NOTSUP_RETURN (-1);
#  endif /* ACE_HAS_PTHREADS_UNIX98_EXT */
# elif defined (ACE_HAS_WTHREADS)
  DWORD result = ::ResumeThread (target_thread);
  if (result == ACE_SYSCALL_FAILED)
    ACE_FAIL_RETURN (-1);
  else
    return 0;
# elif defined (ACE_PSOS)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::t_resume (target_thread), ace_result_), int, -1);
# elif defined (VXWORKS)
  ACE_OSCALL_RETURN (::taskResume (target_thread), int, -1);
# endif /* ACE_HAS_STHREADS */
#else
  ACE_UNUSED_ARG (target_thread);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS */
}

ACE_INLINE int
ACE_OS::thr_cmp (ACE_hthread_t t1, ACE_hthread_t t2)
{
#if defined (ACE_HAS_PACE)
  return pace_pthread_equal (t1, t2);
#elif defined (ACE_HAS_PTHREADS)
# if defined (pthread_equal)
  // If it's a macro we can't say "::pthread_equal"...
  return pthread_equal (t1, t2);
# else
  return ::pthread_equal (t1, t2);
# endif /* pthread_equal */
#else /* For STHREADS, WTHREADS, and VXWORKS ... */
  // Hum, Do we need to treat WTHREAD differently?
  // levine 13 oct 98 % Probably, ACE_hthread_t is a HANDLE.
  return t1 == t2;
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::thr_getconcurrency (void)
{
  ACE_TRACE ("ACE_OS::thr_getconcurrency");
#if defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_STHREADS)
  return ::thr_getconcurrency ();
# elif defined (ACE_HAS_PTHREADS) || defined (VXWORKS) || defined (ACE_PSOS)
  ACE_NOTSUP_RETURN (-1);
# elif defined (ACE_HAS_WTHREADS)
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_STHREADS */
#else
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS */
}

ACE_INLINE int
ACE_OS::thr_getprio (ACE_hthread_t thr_id, int &prio)
{
  ACE_TRACE ("ACE_OS::thr_getprio");
#if defined (ACE_HAS_PACE)
  struct sched_param param;
  int result;
  int policy = 0;

  result = pace_pthread_getschedparam (thr_id, &policy, &param);

  prio = param.sched_priority;
  return result;
#elif defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_STHREADS)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::thr_getprio (thr_id, &prio), ace_result_), int, -1);
# elif (defined (ACE_HAS_PTHREADS) && !defined (ACE_LACKS_SETSCHED))

#   if defined (ACE_HAS_PTHREADS_DRAFT4)
  int result;
  result = ::pthread_getprio (thr_id);
  if (result != -1)
    {
      prio = result;
      return 0;
    }
  else
    return -1;
#   elif defined (ACE_HAS_PTHREADS_DRAFT6)

  pthread_attr_t  attr;
  if (pthread_getschedattr (thr_id, &attr) == 0)
    {
      prio = pthread_attr_getprio(&attr);
      return 0;
    }
  return -1;
#   else

  struct sched_param param;
  int result;
  int policy = 0;

  ACE_OSCALL (ACE_ADAPT_RETVAL (::pthread_getschedparam (thr_id, &policy, &param),
                                result), int,
              -1, result);
  prio = param.sched_priority;
  return result;
#   endif /* ACE_HAS_PTHREADS_DRAFT4 */
# elif defined (ACE_HAS_WTHREADS)
  prio = ::GetThreadPriority (thr_id);
  if (prio == THREAD_PRIORITY_ERROR_RETURN)
    ACE_FAIL_RETURN (-1);
  else
    return 0;
# elif defined (ACE_PSOS)
  // passing a 0 in the second argument does not alter task priority, third arg gets existing one
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::t_setpri (thr_id, 0, (u_long *) &prio), ace_result_), int, -1);
# elif defined (VXWORKS)
  ACE_OSCALL_RETURN (::taskPriorityGet (thr_id, &prio), int, -1);
# else
  ACE_UNUSED_ARG (thr_id);
  ACE_UNUSED_ARG (prio);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_STHREADS */
#else
  ACE_UNUSED_ARG (thr_id);
  ACE_UNUSED_ARG (prio);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_PACE */
}


#if defined (ACE_HAS_TSS_EMULATION)

#if defined (ACE_HAS_THREAD_SPECIFIC_STORAGE)
ACE_INLINE int
ACE_OS::thr_getspecific (ACE_OS_thread_key_t key, void **data)
{
  ACE_TRACE ("ACE_OS::thr_getspecific");
#if defined (ACE_HAS_PACE)
  *data = pace_pthread_getspecific (key);
  return 0;
#elif defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_STHREADS)
    ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::thr_getspecific (key, data), ace_result_), int, -1);
# elif defined (ACE_HAS_PTHREADS)
#   if defined (ACE_HAS_PTHREADS_DRAFT4) || defined (ACE_HAS_PTHREADS_DRAFT6)
    return pthread_getspecific (key, data);
#   else /* this is ACE_HAS_PTHREADS_DRAFT7 or STD */
#if (pthread_getspecific)
    // This is a macro on some platforms, e.g., CHORUS!
    *data = pthread_getspecific (key);
#else
    *data = pthread_getspecific (key);
#endif /* pthread_getspecific */
#   endif       /*  ACE_HAS_PTHREADS_DRAFT4, 6 */
    return 0;
#   elif defined (ACE_PSOS) && defined (ACE_PSOS_HAS_TSS)
    ACE_hthread_t tid;
    ACE_OS::thr_self (tid);
    return (::tsd_getval (key, tid, data) == 0) ? 0 : -1;
# elif defined (ACE_HAS_WTHREADS)

  // The following handling of errno is designed like this due to
  // ACE_Log_Msg::instance calling ACE_OS::thr_getspecific.
  // Basically, it is ok for a system call to reset the error to zero.
  // (It really shouldn't, though).  However, we have to remember to
  // store errno *immediately* after an error is detected.  Calling
  // ACE_ERROR_RETURN((..., errno)) did not work because errno was
  // cleared before being passed to the thread-specific instance of
  // ACE_Log_Msg.  The workaround for was to make it so
  // thr_getspecific did not have the side effect of clearing errno.
  // The correct fix is for ACE_ERROR_RETURN to store errno
  //(actually ACE_OS::last_error) before getting the ACE_Log_Msg tss
  // pointer, which is how it is implemented now.  However, other uses
  // of ACE_Log_Msg may not work correctly, so we're keeping this as
  // it is for now.

  ACE_Errno_Guard error (errno);
  *data = ::TlsGetValue (key);
#   if !defined (ACE_HAS_WINCE)
  if (*data == 0 && (error = ::GetLastError ()) != NO_ERROR)
    return -1;
  else
#   endif /* ACE_HAS_WINCE */
    return 0;
# endif /* ACE_HAS_STHREADS */
#else
  ACE_UNUSED_ARG (key);
  ACE_UNUSED_ARG (data);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_PACE */
}
#endif /* ACE_HAS_THREAD_SPECIFIC_STORAGE */

#if !defined (ACE_HAS_THREAD_SPECIFIC_STORAGE)
ACE_INLINE
void **&
ACE_TSS_Emulation::tss_base ()
{
# if defined (VXWORKS)
  return (void **&) taskIdCurrent->ACE_VXWORKS_SPARE;
# elif defined (ACE_PSOS)
  // not supported
  long x=0;   //JINLU
  return (void **&) x;
# else
  // Uh oh.
  ACE_NOTSUP_RETURN (0);
# endif /* VXWORKS */
}
#endif /* ! ACE_HAS_THREAD_SPECIFIC_STORAGE */

ACE_INLINE
ACE_TSS_Emulation::ACE_TSS_DESTRUCTOR
ACE_TSS_Emulation::tss_destructor (const ACE_thread_key_t key)
{
  ACE_KEY_INDEX (key_index, key);
  return tss_destructor_ [key_index];
}

ACE_INLINE
void
ACE_TSS_Emulation::tss_destructor (const ACE_thread_key_t key,
                                   ACE_TSS_DESTRUCTOR destructor)
{
  ACE_KEY_INDEX (key_index, key);
  tss_destructor_ [key_index] = destructor;
}

ACE_INLINE
void *&
ACE_TSS_Emulation::ts_object (const ACE_thread_key_t key)
{
  ACE_KEY_INDEX (key_index, key);

#if defined (ACE_PSOS)
  u_long tss_base;
  t_getreg (0, PSOS_TASK_REG_TSS, &tss_base);
  return ((void **) tss_base)[key_index];
#else
# if defined (VXWORKS)
    /* If someone wants tss_base make sure they get one.  This
       gets used if someone spawns a VxWorks task directly, not
       through ACE.  The allocated array will never be deleted! */
    if (0 == taskIdCurrent->ACE_VXWORKS_SPARE)
      {
        taskIdCurrent->ACE_VXWORKS_SPARE =
          ACE_reinterpret_cast (int, new void *[ACE_TSS_THREAD_KEYS_MAX]);

        // Zero the entire TSS array.  Do it manually instead of using
        // memset, for optimum speed.  Though, memset may be faster :-)
        void **tss_base_p =
          ACE_reinterpret_cast (void **, taskIdCurrent->ACE_VXWORKS_SPARE);
        for (u_int i = 0; i < ACE_TSS_THREAD_KEYS_MAX; ++i, ++tss_base_p)
          {
            *tss_base_p = 0;
          }
      }
#     endif /* VXWORKS */

  return tss_base ()[key_index];
#endif /* defined (ACE_PSOS) */
}

#endif /* ACE_HAS_TSS_EMULATION */


ACE_INLINE int
ACE_OS::thr_getspecific (ACE_thread_key_t key, void **data)
{
  // ACE_TRACE ("ACE_OS::thr_getspecific");
#if defined (ACE_HAS_PACE)
  *data = pace_pthread_getspecific (key);
  return 0;
#elif defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_TSS_EMULATION)
    ACE_KEY_INDEX (key_index, key);
    if (key_index >= ACE_TSS_Emulation::total_keys ())
      {
        errno = EINVAL;
        data = 0;
        return -1;
      }
    else
      {
        *data = ACE_TSS_Emulation::ts_object (key);
        return 0;
      }
# elif defined (ACE_HAS_STHREADS)
    ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::thr_getspecific (key, data), ace_result_), int, -1);
# elif defined (ACE_HAS_PTHREADS)
#   if defined (ACE_HAS_PTHREADS_DRAFT4) || defined (ACE_HAS_PTHREADS_DRAFT6)
      return ::pthread_getspecific (key, data);
#   else /* this is Draft 7 or STD */
      *data = pthread_getspecific (key);
      return 0;
#   endif       /*  ACE_HAS_PTHREADS_DRAFT4, 6 */
# elif defined (ACE_HAS_WTHREADS)

  // The following handling of errno is designed like this due to
  // ACE_Log_Msg::instance calling ACE_OS::thr_getspecific.
  // Basically, it is ok for a system call to reset the error to zero.
  // (It really shouldn't, though).  However, we have to remember to
  // store errno *immediately* after an error is detected.  Calling
  // ACE_ERROR_RETURN((..., errno)) did not work because errno was
  // cleared before being passed to the thread-specific instance of
  // ACE_Log_Msg.  The workaround for was to make it so
  // thr_getspecific did not have the side effect of clearing errno.
  // The correct fix is for ACE_ERROR_RETURN to store errno
  //(actually ACE_OS::last_error) before getting the ACE_Log_Msg tss
  // pointer, which is how it is implemented now.  However, other uses
  // of ACE_Log_Msg may not work correctly, so we're keeping this as
  // it is for now.

  ACE_Errno_Guard error (errno);
  *data = ::TlsGetValue (key);
#   if !defined (ACE_HAS_WINCE)
  if (*data == 0 && (error = ::GetLastError ()) != NO_ERROR)

    return -1;
  else
#   endif /* ACE_HAS_WINCE */
    return 0;
# elif defined (ACE_PSOS) && defined (ACE_PSOS_HAS_TSS)
  ACE_hthread_t tid;
  ACE_OS::thr_self (tid);
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::tsd_getval (key, tid, data),
                                       ace_result_),
                     int, -1);
# else
  ACE_UNUSED_ARG (key);
  ACE_UNUSED_ARG (data);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_STHREADS */
#else
  ACE_UNUSED_ARG (key);
  ACE_UNUSED_ARG (data);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::thr_join (ACE_hthread_t thr_handle,
                  void **status)
{
  ACE_TRACE ("ACE_OS::thr_join");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN ( ACE_ADAPT_RETVAL (pace_pthread_join (thr_handle, status),
                                        ace_result_), int, -1);
#elif defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_STHREADS)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::thr_join (thr_handle, 0, status), ace_result_),
                     int, -1);
# elif defined (ACE_HAS_PTHREADS)
#   if defined (ACE_HAS_PTHREADS_DRAFT4) || defined (ACE_HAS_PTHREADS_DRAFT6)
#     if defined (ACE_LACKS_NULL_PTHREAD_STATUS)
  void *temp;
  ACE_OSCALL_RETURN (::pthread_join (thr_handle,
    status == 0  ?  &temp  :  status), int, -1);
#     else
  ACE_OSCALL_RETURN (::pthread_join (thr_handle, status), int, -1);
#     endif
#   else
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::pthread_join (thr_handle, status), ace_result_),
                     int, -1);
#   endif /* ACE_HAS_PTHREADS_DRAFT4, 6 */
# elif defined (ACE_HAS_WTHREADS)
  void *local_status = 0;

  // Make sure that status is non-NULL.
  if (status == 0)
    status = &local_status;

  if (::WaitForSingleObject (thr_handle, INFINITE) == WAIT_OBJECT_0
      && ::GetExitCodeThread (thr_handle, (LPDWORD) status) != FALSE)
    {
      ::CloseHandle (thr_handle);
      return 0;
    }
  ACE_FAIL_RETURN (-1);
  /* NOTREACHED */
# elif defined (VXWORKS) || defined (ACE_PSOS)
  ACE_UNUSED_ARG (thr_handle);
  ACE_UNUSED_ARG (status);
  ACE_NOTSUP_RETURN (-1);
# else
  ACE_UNUSED_ARG (thr_handle);
  ACE_UNUSED_ARG (status);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_STHREADS */
#else
  ACE_UNUSED_ARG (thr_handle);
  ACE_UNUSED_ARG (status);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::thr_join (ACE_thread_t waiter_id,
                  ACE_thread_t *thr_id,
                  void **status)
{
  ACE_TRACE ("ACE_OS::thr_join");
#if defined (ACE_HAS_PACE)
  ACE_UNUSED_ARG (thr_id);
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pace_pthread_join (waiter_id, status),
                                       ace_result_), int, -1);
#elif defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_STHREADS)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::thr_join (waiter_id, thr_id, status), ace_result_),
                     int, -1);
# elif defined (ACE_HAS_PTHREADS)
  ACE_UNUSED_ARG (thr_id);
#   if defined (ACE_HAS_PTHREADS_DRAFT4) || defined (ACE_HAS_PTHREADS_DRAFT6)
#     if defined (ACE_LACKS_NULL_PTHREAD_STATUS)
  void *temp;
  ACE_OSCALL_RETURN (::pthread_join (waiter_id,
    status == 0  ?  &temp  :  status), int, -1);
#     else
  ACE_OSCALL_RETURN (::pthread_join (waiter_id, status), int, -1);
#     endif
#   else
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::pthread_join (waiter_id, status), ace_result_),
                     int, -1);
#   endif /* ACE_HAS_PTHREADS_DRAFT4, 6 */
# elif defined (ACE_HAS_WTHREADS)
  ACE_UNUSED_ARG (waiter_id);
  ACE_UNUSED_ARG (thr_id);
  ACE_UNUSED_ARG (status);

  // This could be implemented if the DLL-Main function or the
  // task exit base class some log the threads which have exited
  ACE_NOTSUP_RETURN (-1);
# elif defined (VXWORKS) || defined (ACE_PSOS)
  ACE_UNUSED_ARG (waiter_id);
  ACE_UNUSED_ARG (thr_id);
  ACE_UNUSED_ARG (status);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_STHREADS */
#else
  ACE_UNUSED_ARG (waiter_id);
  ACE_UNUSED_ARG (thr_id);
  ACE_UNUSED_ARG (status);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::thr_setcancelstate (int new_state, int *old_state)
{
  ACE_TRACE ("ACE_OS::thr_setcancelstate");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pace_pthread_setcancelstate (new_state, old_state),
                                       ace_result_), int, -1);
#elif defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_PTHREADS) && !defined (ACE_LACKS_PTHREAD_CANCEL)
#   if defined (ACE_HAS_PTHREADS_DRAFT4)
  int old;
  old = pthread_setcancel (new_state);
  if (old == -1)
    return -1;
  *old_state = old;
  return 0;
#   elif defined (ACE_HAS_PTHREADS_DRAFT6)
  ACE_UNUSED_ARG(old_state);
  ACE_OSCALL_RETURN (pthread_setintr (new_state), int, -1);
#   else /* this is draft 7 or std */
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::pthread_setcancelstate (new_state,
                                                                 old_state),
                                       ace_result_),
                     int, -1);
#   endif /* ACE_HAS_PTHREADS_DRAFT4 */
# elif defined (ACE_HAS_STHREADS)
  ACE_UNUSED_ARG (new_state);
  ACE_UNUSED_ARG (old_state);
  ACE_NOTSUP_RETURN (-1);
# elif defined (ACE_HAS_WTHREADS)
  ACE_UNUSED_ARG (new_state);
  ACE_UNUSED_ARG (old_state);
  ACE_NOTSUP_RETURN (-1);
# else /* Could be ACE_HAS_PTHREADS && ACE_LACKS_PTHREAD_CANCEL */
  ACE_UNUSED_ARG (new_state);
  ACE_UNUSED_ARG (old_state);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_PTHREADS */
#else
  ACE_UNUSED_ARG (new_state);
  ACE_UNUSED_ARG (old_state);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::thr_setcanceltype (int new_type, int *old_type)
{
  ACE_TRACE ("ACE_OS::thr_setcanceltype");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pace_pthread_setcanceltype (new_type, old_type),
                                       ace_result_), int, -1);
#elif defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_PTHREADS) && !defined (ACE_LACKS_PTHREAD_CANCEL)
#   if defined (ACE_HAS_PTHREADS_DRAFT4)
  int old;
  old = pthread_setasynccancel(new_type);
  if (old == -1)
    return -1;
  *old_type = old;
  return 0;
#   elif defined (ACE_HAS_PTHREADS_DRAFT6)
  ACE_UNUSED_ARG(old_type);
  ACE_OSCALL_RETURN (pthread_setintrtype (new_type), int, -1);
#   else /* this is draft 7 or std */
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::pthread_setcanceltype (new_type,
                                                                old_type),
                                       ace_result_),
                     int, -1);
#   endif /* ACE_HAS_PTHREADS_DRAFT4 */
# else /* Could be ACE_HAS_PTHREADS && ACE_LACKS_PTHREAD_CANCEL */
  ACE_UNUSED_ARG (new_type);
  ACE_UNUSED_ARG (old_type);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_PTHREADS */
#else
  ACE_UNUSED_ARG (new_type);
  ACE_UNUSED_ARG (old_type);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::thr_cancel (ACE_thread_t thr_id)
{
  ACE_TRACE ("ACE_OS::thr_cancel");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pace_pthread_cancel (thr_id),
                                       ace_result_), int, -1);
#elif defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_PTHREADS) && !defined (ACE_LACKS_PTHREAD_CANCEL)
#   if defined (ACE_HAS_PTHREADS_DRAFT4) || defined (ACE_HAS_PTHREADS_DRAFT6)
  ACE_OSCALL_RETURN (::pthread_cancel (thr_id), int, -1);
#   else
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::pthread_cancel (thr_id),
                                       ace_result_),
                     int, -1);
#   endif /* ACE_HAS_PTHREADS_DRAFT4 || ACE_HAS_PTHREADS_DRAFT6 */
# else /* Could be ACE_HAS_PTHREADS && ACE_LACKS_PTHREAD_CANCEL */
  ACE_UNUSED_ARG (thr_id);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_PTHREADS */
#else
  ACE_UNUSED_ARG (thr_id);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::sigwait (sigset_t *set, int *sig)
{
  ACE_TRACE ("ACE_OS::sigwait");
  int local_sig;
  if (sig == 0)
    sig = &local_sig;
#if defined (ACE_HAS_PACE)
  errno = pace_sigwait (set, sig);
  return errno == 0  ?  *sig  :  -1;
#elif defined (ACE_HAS_THREADS)
# if (defined (__FreeBSD__) && (__FreeBSD__ < 3)) || defined (CHORUS) || defined (ACE_PSOS) || defined (__MACOSX__)
    ACE_UNUSED_ARG (set);
    ACE_NOTSUP_RETURN (-1);
# elif (defined (ACE_HAS_STHREADS) && !defined (_POSIX_PTHREAD_SEMANTICS))
    *sig = ::sigwait (set);
    return *sig;
# elif defined (ACE_HAS_PTHREADS)
  // LynxOS and Digital UNIX have their own hoops to jump through.
#   if defined (__Lynx__)
    // Second arg is a void **, which we don't need (the selected
    // signal number is returned).
    *sig = ::sigwait (set, 0);
    return *sig;
#   elif defined (DIGITAL_UNIX)  &&  defined (__DECCXX_VER)
      // DEC cxx (but not g++) needs this direct call to its internal
      // sigwait ().  This allows us to #undef sigwait, so that we can
      // have ACE_OS::sigwait.  cxx gets confused by ACE_OS::sigwait
      // if sigwait is _not_ #undef'ed.
      errno = ::_Psigwait (set, sig);
      return errno == 0  ?  *sig  :  -1;
#   else /* ! __Lynx __ && ! (DIGITAL_UNIX && __DECCXX_VER) */
#     if (defined (ACE_HAS_PTHREADS_DRAFT4) || (defined (ACE_HAS_PTHREADS_DRAFT6)) && !defined(ACE_HAS_FSU_PTHREADS)) || (defined (_UNICOS) && _UNICOS == 9)
#       if defined (HPUX_10)
        *sig = cma_sigwait (set);
#       else
        *sig = ::sigwait (set);
#       endif  /* HPUX_10 */
        return *sig;
#     elif defined(ACE_HAS_FSU_PTHREADS)
        return ::sigwait (set, sig);
#     else   /* this is draft 7 or std */
        errno = ::sigwait (set, sig);
        return errno == 0  ?  *sig  :  -1;
#     endif /* ACE_HAS_PTHREADS_DRAFT4, 6 */
#   endif /* ! __Lynx__ && ! (DIGITAL_UNIX && __DECCXX_VER) */
# elif defined (ACE_HAS_WTHREADS)
    ACE_UNUSED_ARG (set);
    ACE_NOTSUP_RETURN (-1);
# elif defined (VXWORKS)
    // Second arg is a struct siginfo *, which we don't need (the
    // selected signal number is returned).  Third arg is timeout:  0
    // means forever.
    *sig = ::sigtimedwait (set, 0, 0);
    return *sig;
# endif /* __FreeBSD__ */
#else
    ACE_UNUSED_ARG (set);
    ACE_UNUSED_ARG (sig);
    ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::sigtimedwait (const sigset_t *set,
                      siginfo_t *info,
                      const ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_OS::sigtimedwait");
#if defined (ACE_HAS_PACE)
  timespec ts;
  timespec *tsp;
  if (timeout !=0)
  {
    ts = *timeout;
    tsp = &ts;
  }
  else
    tsp = 0;
  ACE_OSCALL_RETURN (pace_sigtimedwait (set, info, tsp),
                     int, -1);
#elif defined (ACE_HAS_SIGTIMEDWAIT)
  timespec_t ts;
  timespec_t *tsp;

  if (timeout != 0)
    {
      ts = *timeout; // Calls ACE_Time_Value::operator timespec_t().
      tsp = &ts;
    }
  else
    tsp = 0;

  ACE_OSCALL_RETURN (::sigtimedwait (set, info, tsp),
                     int, -1);
#else
    ACE_UNUSED_ARG (set);
    ACE_UNUSED_ARG (info);
    ACE_UNUSED_ARG (timeout);
    ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE void
ACE_OS::thr_testcancel (void)
{
  ACE_TRACE ("ACE_OS::thr_testcancel");
#if defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_PTHREADS) && !defined (ACE_LACKS_PTHREAD_CANCEL)
#if defined(ACE_HAS_PTHREADS_DRAFT6)
  ::pthread_testintr ();
#else /* ACE_HAS_PTHREADS_DRAFT6 */
  ::pthread_testcancel ();
#endif /* !ACE_HAS_PTHREADS_DRAFT6 */
# elif defined (ACE_HAS_STHREADS)
# elif defined (ACE_HAS_WTHREADS)
# elif defined (VXWORKS) || defined (ACE_PSOS)
# else
  // no-op:  can't use ACE_NOTSUP_RETURN because there is no return value
# endif /* ACE_HAS_PTHREADS */
#else
#endif /* ACE_HAS_THREADS */
}

ACE_INLINE int
ACE_OS::thr_sigsetmask (int how,
                        const sigset_t *nsm,
                        sigset_t *osm)
{
  ACE_TRACE ("ACE_OS::thr_sigsetmask");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pace_pthread_sigmask (how, nsm, osm),
                                       ace_result_), int, -1);
#elif defined (ACE_HAS_THREADS)
# if defined (ACE_LACKS_PTHREAD_THR_SIGSETMASK)
  // DCE threads and Solaris 2.4 have no such function.
  ACE_UNUSED_ARG (osm);
  ACE_UNUSED_ARG (nsm);
  ACE_UNUSED_ARG (how);

  ACE_NOTSUP_RETURN (-1);
# elif defined (ACE_HAS_SIGTHREADMASK)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::sigthreadmask (how, nsm, osm),
                                       ace_result_), int, -1);
# elif defined (ACE_HAS_STHREADS)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::thr_sigsetmask (how, nsm, osm),
                                       ace_result_),
                     int, -1);
# elif defined (ACE_HAS_PTHREADS)
#   if defined (AIX)
  ACE_OSCALL_RETURN (sigthreadmask (how, nsm, osm), int, -1);
  // Draft 4 and 6 implementations will sometimes have a sigprocmask () that
  // modifies the calling thread's mask only.  If this is not so for your
  // platform, define ACE_LACKS_PTHREAD_THR_SIGSETMASK.
#   elif defined(ACE_HAS_PTHREADS_DRAFT4) || \
    defined (ACE_HAS_PTHREADS_DRAFT6) || (defined (_UNICOS) && _UNICOS == 9)
  ACE_OSCALL_RETURN (::sigprocmask (how, nsm, osm), int, -1);
#   elif !defined (ACE_LACKS_PTHREAD_SIGMASK)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::pthread_sigmask (how, nsm, osm),
                                       ace_result_), int, -1);
#   endif /* AIX */

#if 0
  /* Don't know if anyt platform actually needs this... */
  // as far as I can tell, this is now pthread_sigaction() -- jwr
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::pthread_sigaction (how, nsm, osm),
                                       ace_result_), int, -1);
#endif /* 0 */

# elif defined (ACE_HAS_WTHREADS) || defined (ACE_PSOS)
  ACE_UNUSED_ARG (osm);
  ACE_UNUSED_ARG (nsm);
  ACE_UNUSED_ARG (how);

  ACE_NOTSUP_RETURN (-1);
# elif defined (VXWORKS)
  switch (how)
    {
    case SIG_BLOCK:
    case SIG_UNBLOCK:
      {
        // get the old mask
        *osm = ::sigsetmask (*nsm);
        // create a new mask:  the following assumes that sigset_t is 4 bytes,
        // which it is on VxWorks 5.2, so bit operations are done simply . . .
        ::sigsetmask (how == SIG_BLOCK ? (*osm |= *nsm) : (*osm &= ~*nsm));
        break;
      }
    case SIG_SETMASK:
      *osm = ::sigsetmask (*nsm);
      break;
    default:
      return -1;
    }

  return 0;
# else /* Should not happen. */
  ACE_UNUSED_ARG (how);
  ACE_UNUSED_ARG (nsm);
  ACE_UNUSED_ARG (osm);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_LACKS_PTHREAD_THR_SIGSETMASK */
#else
  ACE_UNUSED_ARG (how);
  ACE_UNUSED_ARG (nsm);
  ACE_UNUSED_ARG (osm);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::thr_kill (ACE_thread_t thr_id, int signum)
{
  ACE_TRACE ("ACE_OS::thr_kill");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pace_pthread_kill (thr_id, signum),
                                       ace_result_), int, -1);
#elif defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_PTHREADS)
#   if defined (ACE_HAS_PTHREADS_DRAFT4) || defined(ACE_LACKS_PTHREAD_KILL)
  ACE_UNUSED_ARG (signum);
  ACE_UNUSED_ARG (thr_id);
  ACE_NOTSUP_RETURN (-1);
#   else
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::pthread_kill (thr_id, signum),
                                       ace_result_),
                     int, -1);
#   endif /* ACE_HAS_PTHREADS_DRAFT4 */
# elif defined (ACE_HAS_STHREADS)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::thr_kill (thr_id, signum),
                                       ace_result_),
                     int, -1);
# elif defined (ACE_HAS_WTHREADS) || defined (ACE_PSOS)
  ACE_UNUSED_ARG (signum);
  ACE_UNUSED_ARG (thr_id);

  ACE_NOTSUP_RETURN (-1);
# elif defined (VXWORKS)
  ACE_hthread_t tid;
  ACE_OSCALL (::taskNameToId (thr_id), int, ERROR, tid);

  if (tid == ERROR)
    return -1;
  else
    ACE_OSCALL_RETURN (::kill (tid, signum), int, -1);

# else /* This should not happen! */
  ACE_UNUSED_ARG (thr_id);
  ACE_UNUSED_ARG (signum);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_STHREADS */
#else
  ACE_UNUSED_ARG (thr_id);
  ACE_UNUSED_ARG (signum);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE size_t
ACE_OS::thr_min_stack (void)
{
  ACE_TRACE ("ACE_OS::thr_min_stack");
#if defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_STHREADS)
#   if defined (ACE_HAS_THR_MINSTACK)
  // Tandem did some weirdo mangling of STHREAD names...
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::thr_minstack (),
                                       ace_result_),
                     int, -1);
#   else
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::thr_min_stack (),
                                       ace_result_),
                     int, -1);
#   endif /* !ACE_HAS_THR_MINSTACK */
# elif defined (ACE_HAS_PTHREADS)
#   if defined (_SC_THREAD_STACK_MIN)
  return (size_t) ACE_OS::sysconf (_SC_THREAD_STACK_MIN);
#   elif defined (PTHREAD_STACK_MIN)
  return PTHREAD_STACK_MIN;
#   else
  ACE_NOTSUP_RETURN (0);
#   endif /* _SC_THREAD_STACK_MIN */
# elif defined (ACE_HAS_WTHREADS)
  ACE_NOTSUP_RETURN (0);
# elif defined (ACE_PSOS)
  // there does not appear to be a way to get the
  // task stack size except at task creation
  ACE_NOTSUP_RETURN (0);
# elif defined (VXWORKS)
  TASK_DESC taskDesc;
  STATUS status;

  ACE_hthread_t tid;
  ACE_OS::thr_self (tid);

  ACE_OSCALL (ACE_ADAPT_RETVAL (::taskInfoGet (tid, &taskDesc),
                                status),
              STATUS, -1, status);
  return status == OK ? taskDesc.td_stackSize : 0;
# else /* Should not happen... */
  ACE_NOTSUP_RETURN (0);
# endif /* ACE_HAS_STHREADS */
#else
  ACE_NOTSUP_RETURN (0);
#endif /* ACE_HAS_THREADS */
}

ACE_INLINE int
ACE_OS::thr_setconcurrency (int hint)
{
  ACE_TRACE ("ACE_OS::thr_setconcurrency");
#if defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_STHREADS)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::thr_setconcurrency (hint),
                                       ace_result_),
                     int, -1);
# elif defined (ACE_HAS_PTHREADS)
  ACE_UNUSED_ARG (hint);
  ACE_NOTSUP_RETURN (-1);
# elif defined (ACE_HAS_WTHREADS)
  ACE_UNUSED_ARG (hint);

  ACE_NOTSUP_RETURN (-1);
# elif defined (VXWORKS) || defined (ACE_PSOS)
  ACE_UNUSED_ARG (hint);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_STHREADS */
#else
  ACE_UNUSED_ARG (hint);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS */
}

ACE_INLINE int
ACE_OS::thr_setprio (ACE_hthread_t thr_id, int prio)
{
  ACE_TRACE ("ACE_OS::thr_setprio");
#if defined (ACE_HAS_PACE)
  struct sched_param param;
  int policy = 0;
  int result = 0;
  ACE_OSCALL (ACE_ADAPT_RETVAL (pace_pthread_getschedparam (thr_id, &policy, &param),
                                 result), int, -1, result);

  if (result == -1)
    return result; // error in pthread_getschedparam
  param.sched_priority = prio;
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pace_pthread_setschedparam (thr_id, policy, &param),
                                       ace_result_), int, -1);
#elif defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_STHREADS)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::thr_setprio (thr_id, prio),
                                       ace_result_),
                     int, -1);
# elif (defined (ACE_HAS_PTHREADS) && !defined (ACE_LACKS_SETSCHED))

#   if defined (ACE_HAS_PTHREADS_DRAFT4)
  int result;
  result = ::pthread_setprio(thr_id, prio);
  return (result == -1 ? -1 : 0);
#   elif defined (ACE_HAS_PTHREADS_DRAFT6)
  pthread_attr_t  attr;
  if (pthread_getschedattr(thr_id, &attr) == -1)
    return -1;
  if (pthread_attr_setprio (attr, prio) == -1)
    return -1;
  return pthread_setschedattr(thr_id, attr);
#   else
  struct sched_param param;
  int policy = 0;
  int result;

  ACE_OSCALL (ACE_ADAPT_RETVAL (::pthread_getschedparam (thr_id, &policy, &param),
                                result), // not sure if use of result here is cool, cjc
              int, -1, result);
  if (result == -1)
    return result; // error in pthread_getschedparam
  param.sched_priority = prio;
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::pthread_setschedparam (thr_id, policy, &param),
                                       result),
                     int, -1);
#   endif /* ACE_HAS_PTHREADS_DRAFT4 */
# elif defined (ACE_HAS_WTHREADS)
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::SetThreadPriority (thr_id, prio),
                                          ace_result_),
                        int, -1);
# elif defined (ACE_PSOS)
  u_long oldprio;
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::t_setpri (thr_id, prio, &oldprio),
                                       ace_result_),
                     int, -1);
# elif defined (VXWORKS)
  ACE_OSCALL_RETURN (::taskPrioritySet (thr_id, prio), int, -1);
# else
  // For example, platforms that support Pthreads but LACK_SETSCHED.
  ACE_UNUSED_ARG (thr_id);
  ACE_UNUSED_ARG (prio);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_STHREADS */
#else
  ACE_UNUSED_ARG (thr_id);
  ACE_UNUSED_ARG (prio);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::thr_suspend (ACE_hthread_t target_thread)
{
  ACE_TRACE ("ACE_OS::thr_suspend");
#if defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_STHREADS)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::thr_suspend (target_thread), ace_result_), int, -1);
# elif defined (ACE_HAS_PTHREADS)
#  if defined (ACE_HAS_PTHREADS_UNIX98_EXT)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pthread_suspend (target_thread),
                                       ace_result_),
                     int, -1);
#  else
  ACE_UNUSED_ARG (target_thread);
  ACE_NOTSUP_RETURN (-1);
#  endif /* ACE_HAS_PTHREADS_UNIX98_EXT */
# elif defined (ACE_HAS_WTHREADS)
  if (::SuspendThread (target_thread) != ACE_SYSCALL_FAILED)
    return 0;
  else
    ACE_FAIL_RETURN (-1);
  /* NOTREACHED */
# elif defined (ACE_PSOS)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::t_suspend (target_thread), ace_result_), int, -1);
# elif defined (VXWORKS)
  ACE_OSCALL_RETURN (::taskSuspend (target_thread), int, -1);
# endif /* ACE_HAS_STHREADS */
#else
  ACE_UNUSED_ARG (target_thread);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_THREADS */
}

ACE_INLINE void
ACE_OS::thr_yield (void)
{
  ACE_TRACE ("ACE_OS::thr_yield");
#if defined (ACE_HAS_PACE)
  pace_sched_yield ();
#elif defined (ACE_HAS_THREADS)
# if defined (ACE_HAS_STHREADS)
  ::thr_yield ();
# elif defined (ACE_HAS_PTHREADS)
#   if defined (ACE_HAS_PTHREADS_STD)
  // Note - this is a POSIX.4 function - not a POSIX.1c function...
  ::sched_yield ();
#   elif defined (ACE_HAS_PTHREADS_DRAFT6)
  ::pthread_yield (NULL);
#   else    /* Draft 4 and 7 */
  ::pthread_yield ();
#   endif  /* ACE_HAS_PTHREADS_STD */
# elif defined (ACE_HAS_WTHREADS)
  ::Sleep (0);
# elif defined (VXWORKS)
  // An argument of 0 to ::taskDelay doesn't appear to yield the
  // current thread.
  ::taskDelay (1);
# endif /* ACE_HAS_STHREADS */
#else
  ;
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::priority_control (ACE_idtype_t idtype, ACE_id_t id, int cmd, void *arg)
{
  ACE_TRACE ("ACE_OS::priority_control");
#if defined (ACE_HAS_PRIOCNTL)
  ACE_OSCALL_RETURN (priocntl (idtype, id, cmd, ACE_static_cast (caddr_t, arg)),
                     int, -1);
#else  /* ! ACE_HAS_PRIOCNTL*/
  ACE_UNUSED_ARG (idtype);
  ACE_UNUSED_ARG (id);
  ACE_UNUSED_ARG (cmd);
  ACE_UNUSED_ARG (arg);
  ACE_NOTSUP_RETURN (-1);
#endif /* ! ACE_HAS_PRIOCNTL*/
}

ACE_INLINE void
ACE_OS::rewind (FILE *fp)
{
#if defined (ACE_HAS_PACE)
  pace_rewind (fp);
#elif !defined (ACE_HAS_WINCE)
  ACE_TRACE ("ACE_OS::rewind");
  ::rewind (fp);
#else
  // In WinCE, "FILE *" is actually a HANDLE.
  ::SetFilePointer (fp, 0L, 0L, FILE_BEGIN);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE ssize_t
ACE_OS::readv (ACE_HANDLE handle,
               iovec *iov,
               int iovlen)
{
  ACE_TRACE ("ACE_OS::readv");
  ACE_OSCALL_RETURN (::readv (handle, iov, iovlen), ssize_t, -1);
}

ACE_INLINE ssize_t
ACE_OS::writev (ACE_HANDLE handle,
                const iovec *iov,
                int iovcnt)
{
  ACE_TRACE ("ACE_OS::writev");
  ACE_OSCALL_RETURN (::writev (handle, (ACE_WRITEV_TYPE *) iov, iovcnt), int, -1);
}

ACE_INLINE ssize_t
ACE_OS::recvv (ACE_HANDLE handle,
               iovec *buffers,
               int n)
{
#if defined (ACE_HAS_WINSOCK2)

  DWORD bytes_received = 0;
  int result = 1;

  // Winsock 2 has WSARecv and can do this directly, but Winsock 1 needs
  // to do the recvs piece-by-piece.

# if (ACE_HAS_WINSOCK2 != 0)
  DWORD flags = 0;
  result = ::WSARecv ((SOCKET) handle,
                      (WSABUF *) buffers,
                      n,
                      &bytes_received,
                      &flags,
                      0,
                      0);
# else
  int i, chunklen;
  char *chunkp = 0;

  // Step through the buffers requested by caller; for each one, cycle
  // through reads until it's filled or an error occurs.
  for (i = 0; i < n && result > 0; i++)
    {
      chunkp = buffers[i].iov_base;     // Point to part of chunk being read
      chunklen = buffers[i].iov_len;    // Track how much to read to chunk
      while (chunklen > 0 && result > 0)
        {
          result = ::recv ((SOCKET) handle, chunkp, chunklen, 0);
          if (result > 0)
            {
              chunkp += result;
              chunklen -= result;
              bytes_received += result;
            }
        }
    }
# endif /* ACE_HAS_WINSOCK2 != 0 */

  if (result == SOCKET_ERROR)
    {
      ACE_OS::set_errno_to_wsa_last_error ();
      return -1;
    }
  else
    return (ssize_t) bytes_received;
#else
  return ACE_OS::readv (handle, buffers, n);
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE ssize_t
ACE_OS::sendv (ACE_HANDLE handle,
               const iovec *buffers,
               int n)
{
#if defined (ACE_HAS_WINSOCK2)
  DWORD bytes_sent = 0;
  int result = 0;

  // Winsock 2 has WSASend and can do this directly, but Winsock 1 needs
  // to do the sends one-by-one.
# if (ACE_HAS_WINSOCK2 != 0)
  result = ::WSASend ((SOCKET) handle,
                      (WSABUF *) buffers,
                      n,
                      &bytes_sent,
                      0,
                      0,
                      0);
# else
  int i;
  for (i = 0; i < n && result != SOCKET_ERROR; i++)
    {
      result = ::send ((SOCKET) handle,
                       buffers[i].iov_base,
                       buffers[i].iov_len,
                       0);
      bytes_sent += buffers[i].iov_len;     // Gets ignored on error anyway
    }
# endif /* ACE_HAS_WINSOCK2 != 0 */

  if (result == SOCKET_ERROR)
    {
      ACE_OS::set_errno_to_wsa_last_error ();
      return -1;
    }
  else
    return (ssize_t) bytes_sent;

#else
  return ACE_OS::writev (handle, buffers, n);
#endif /* ACE_HAS_WINSOCK2 */
}

ACE_INLINE int
ACE_OS::poll (struct pollfd *pollfds, u_long len, ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_OS::poll");
#if defined (ACE_HAS_POLL)
  int to = timeout == 0 ? -1 : int (timeout->msec ());
  ACE_OSCALL_RETURN (::poll (pollfds, len, to), int, -1);
#else
  ACE_UNUSED_ARG (timeout);
  ACE_UNUSED_ARG (len);
  ACE_UNUSED_ARG (pollfds);

  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_POLL */
}

ACE_INLINE int
ACE_OS::poll (struct pollfd *pollfds, u_long len, const ACE_Time_Value &timeout)
{
  ACE_TRACE ("ACE_OS::poll");
#if defined (ACE_HAS_POLL)
  ACE_OSCALL_RETURN (::poll (pollfds, len, int (timeout.msec ())), int, -1);
#else
  ACE_UNUSED_ARG (timeout);
  ACE_UNUSED_ARG (len);
  ACE_UNUSED_ARG (pollfds);

  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_POLL */
}

ACE_INLINE char *
ACE_OS::compile (const char *instring, char *expbuf, char *endbuf)
{
  ACE_TRACE ("ACE_OS::compile");
#if defined (ACE_HAS_REGEX)
  ACE_OSCALL_RETURN (::compile (instring, expbuf, endbuf), char *, 0);
#else
  ACE_UNUSED_ARG (instring);
  ACE_UNUSED_ARG (expbuf);
  ACE_UNUSED_ARG (endbuf);

  ACE_NOTSUP_RETURN (0);
#endif /* ACE_HAS_REGEX */
}

ACE_INLINE long
ACE_OS::filesize (const ACE_TCHAR *filename)
{
  ACE_TRACE ("ACE_OS::filesize");

  ACE_HANDLE h = ACE_OS::open (filename, O_RDONLY);
  if (h != ACE_INVALID_HANDLE)
    {
      long size = ACE_OS::filesize (h);
      ACE_OS::close (h);
      return size;
    }
  else
    return -1;
}

ACE_INLINE int
ACE_OS::closesocket (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_OS::close");
#if defined (ACE_WIN32)
  ACE_SOCKCALL_RETURN (::closesocket ((SOCKET) handle), int, -1);
#elif defined (ACE_PSOS_DIAB_PPC)
  ACE_OSCALL_RETURN (::pna_close (handle), int, -1);
#else
  ACE_OSCALL_RETURN (::close (handle), int, -1);
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::access (const ACE_TCHAR *path, int amode)
{
  ACE_TRACE ("ACE_OS::access");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_access (path, amode), int, -1);
#elif defined (ACE_LACKS_ACCESS)
  ACE_UNUSED_ARG (path);
  ACE_UNUSED_ARG (amode);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_HAS_WINCE)
  // @@ WINCE: There should be a Win32 API that can do this.
  // Hard coded read access here.
  FILE* handle = ACE_OS::fopen (path, ACE_TEXT ("r"));
  ACE_UNUSED_ARG (amode);

  ACE_OS::fclose (handle);
  return (handle == ACE_INVALID_HANDLE ? -1 : 0);
#elif defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
  ACE_OSCALL_RETURN (::_waccess (path, amode), int, -1);
#else
  ACE_OSCALL_RETURN (::access (path, amode), int, -1);
#endif /* ACE_AS_PACE */
}


ACE_INLINE ACE_HANDLE
ACE_OS::creat (const ACE_TCHAR *filename, mode_t mode)
{
  ACE_TRACE ("ACE_OS::creat");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_creat (filename, mode),
                     ACE_HANDLE, ACE_INVALID_HANDLE);
#elif defined (ACE_WIN32)
  return ACE_OS::open (filename, mode);
#elif defined(ACE_PSOS)
   ACE_OSCALL_RETURN(::create_f((char *)filename, 1024,
                              S_IRUSR | S_IWUSR | S_IXUSR),
                     ACE_HANDLE, ACE_INVALID_HANDLE);
#elif defined(ACE_PSOS_TM)
  ACE_UNUSED_ARG (filename);
  ACE_UNUSED_ARG (mode);
  ACE_NOTSUP_RETURN (-1);
#elif defined(ACE_PSOS)
  ACE_UNUSED_ARG (filename);
  ACE_UNUSED_ARG (mode);
  ACE_NOTSUP_RETURN (-1);
#else
  ACE_OSCALL_RETURN (::creat (filename, mode),
                     ACE_HANDLE, ACE_INVALID_HANDLE);
#endif /* ACE_HAS_PACE */
}

#if !defined (ACE_WIN32) && !defined (VXWORKS) && !defined (CHORUS) && !defined (ACE_PSOS)
// Don't inline on those platforms because this function contains
// string literals, and some compilers, e.g., g++, don't handle those
// efficiently in unused inline functions.
ACE_INLINE int
ACE_OS::uname (struct utsname *name)
{
  ACE_TRACE ("ACE_OS::uname");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_uname (name), int, -1);
#else
  ACE_OSCALL_RETURN (::uname (name), int, -1);
#endif /* ACE_HAS_PACE */
}
#endif /* ! ACE_WIN32 && ! VXWORKS && ! CHORUS */

ACE_INLINE int
ACE_OS::hostname (ACE_TCHAR name[], size_t maxnamelen)
{
  ACE_TRACE ("ACE_OS::hostname");
#if defined (ACE_HAS_WINCE)
  // @@ WINCE: Don't know how to implement this (yet.)  Can probably get around
  // this by peeking into the Register set.
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (maxnamelen);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_HAS_PHARLAP)
  // PharLap only can do net stuff with the RT version.
#   if defined (ACE_HAS_PHARLAP_RT)
  // @@This is not at all reliable... requires ethernet and BOOTP to be used.
  // A more reliable way is to go thru the devices w/ EtsTCPGetDeviceCfg until
  // a legit IP address is found, then get its name w/ gethostbyaddr.
  ACE_SOCKCALL_RETURN (gethostname (name, maxnamelen), int, SOCKET_ERROR);
#   else
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (maxnamelen);
  ACE_NOTSUP_RETURN (-1);
#   endif /* ACE_HAS_PHARLAP_RT */
#elif defined (ACE_WIN32)
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (ACE_TEXT_GetComputerName (name,
                                                        LPDWORD (&maxnamelen)),
                                          ace_result_), int, -1);
#elif defined (VXWORKS)
  ACE_OSCALL_RETURN (::gethostname (name, maxnamelen), int, -1);
#elif defined (CHORUS)
  if (::gethostname (name, maxnamelen) == -1)
    return -1;
  else
    {
      if (ACE_OS::strlen (name) == 0)
        {
          // Try the HOST environment variable.
          ACE_TCHAR *const hostenv = ::getenv (ACE_TEXT ("HOST"));
          if (hostenv)
            ACE_OS::strncpy (name, hostenv, maxnamelen);
        }
      return 0;
    }
#else /* ACE_HAS_WINCE */
  struct utsname host_info;

  if (ACE_OS::uname (&host_info) == -1)
    return -1;
  else
    {
      ACE_OS::strncpy (name, host_info.nodename, maxnamelen);
      return 0;
    }
#endif /* ACE_HAS_WINCE */
}

ACE_INLINE int
ACE_OS::msgctl (int msqid, int cmd, struct msqid_ds *val)
{
  ACE_TRACE ("ACE_OS::msgctl");
#if defined (ACE_HAS_SYSV_IPC)
  ACE_OSCALL_RETURN (::msgctl (msqid, cmd, val), int, -1);
#else
  ACE_UNUSED_ARG (msqid);
  ACE_UNUSED_ARG (cmd);
  ACE_UNUSED_ARG (val);

  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_SYSV_IPC */
}

ACE_INLINE int
ACE_OS::msgget (key_t key, int msgflg)
{
  ACE_TRACE ("ACE_OS::msgget");
#if defined (ACE_HAS_SYSV_IPC)
  ACE_OSCALL_RETURN (::msgget (key, msgflg), int, -1);
#else
  ACE_UNUSED_ARG (key);
  ACE_UNUSED_ARG (msgflg);

  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_SYSV_IPC */
}

ACE_INLINE int
ACE_OS::msgrcv (int int_id, void *buf, size_t len,
                long type, int flags)
{
  ACE_TRACE ("ACE_OS::msgrcv");
#if defined (ACE_HAS_SYSV_IPC)
# if defined (ACE_LACKS_POSIX_PROTOTYPES) || defined (ACE_LACKS_SOME_POSIX_PROTOTYPES)
  ACE_OSCALL_RETURN (::msgrcv (int_id, (msgbuf *) buf, len, type, flags),
                     int, -1);
# else
  ACE_OSCALL_RETURN (::msgrcv (int_id, buf, len, type, flags),
                     int, -1);
# endif /* ACE_LACKS_POSIX_PROTOTYPES */
#else
  ACE_UNUSED_ARG (int_id);
  ACE_UNUSED_ARG (buf);
  ACE_UNUSED_ARG (len);
  ACE_UNUSED_ARG (type);
  ACE_UNUSED_ARG (flags);

  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_SYSV_IPC */
}

ACE_INLINE int
ACE_OS::msgsnd (int int_id, const void *buf, size_t len, int flags)
{
  ACE_TRACE ("ACE_OS::msgsnd");
#if defined (ACE_HAS_SYSV_IPC)
# if defined (ACE_HAS_NONCONST_MSGSND)
  ACE_OSCALL_RETURN (::msgsnd (int_id, (void *) buf, len, flags), int, -1);
# elif defined (ACE_LACKS_POSIX_PROTOTYPES) || defined (ACE_LACKS_SOME_POSIX_PROTOTYPES)
  ACE_OSCALL_RETURN (::msgsnd (int_id, (msgbuf *) buf, len, flags), int, -1);
# else
  ACE_OSCALL_RETURN (::msgsnd (int_id, buf, len, flags), int, -1);
# endif /* ACE_LACKS_POSIX_PROTOTYPES || ACE_HAS_NONCONST_MSGSND */
#else
  ACE_UNUSED_ARG (int_id);
  ACE_UNUSED_ARG (buf);
  ACE_UNUSED_ARG (len);
  ACE_UNUSED_ARG (flags);

  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_SYSV_IPC */
}

ACE_INLINE u_int
ACE_OS::alarm (u_int secs)
{
  ACE_TRACE ("ACE_OS::alarm");
#if defined (ACE_HAS_PACE)
  return pace_alarm (secs);
#elif defined (ACE_WIN32) || defined (VXWORKS) || defined (CHORUS) || defined (ACE_PSOS)
  ACE_UNUSED_ARG (secs);

  ACE_NOTSUP_RETURN (0);
#else
  return ::alarm (secs);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE u_int
ACE_OS::ualarm (u_int usecs, u_int interval)
{
  ACE_TRACE ("ACE_OS::ualarm");

#if defined (ACE_HAS_UALARM)
  return ::ualarm (usecs, interval);
#elif !defined (ACE_LACKS_UNIX_SIGNALS)
  ACE_UNUSED_ARG (interval);
  return ::alarm (usecs * ACE_ONE_SECOND_IN_USECS);
#else
  ACE_UNUSED_ARG (usecs);
  ACE_UNUSED_ARG (interval);
  ACE_NOTSUP_RETURN (0);
#endif /* ACE_HAS_UALARM */
}

ACE_INLINE u_int
ACE_OS::ualarm (const ACE_Time_Value &tv,
                const ACE_Time_Value &tv_interval)
{
  ACE_TRACE ("ACE_OS::ualarm");

#if defined (ACE_HAS_UALARM)
  u_int usecs = (tv.sec () * ACE_ONE_SECOND_IN_USECS) + tv.usec ();
  u_int interval = (tv_interval.sec () * ACE_ONE_SECOND_IN_USECS) + tv_interval.usec ();
  return ::ualarm (usecs, interval);
#elif !defined (ACE_LACKS_UNIX_SIGNALS)
  ACE_UNUSED_ARG (tv_interval);
  return ::alarm (tv.sec ());
#else
  ACE_UNUSED_ARG (tv_interval);
  ACE_UNUSED_ARG (tv);
  ACE_NOTSUP_RETURN (0);
#endif /* ACE_HAS_UALARM */
}

ACE_INLINE int
ACE_OS::dlclose (ACE_SHLIB_HANDLE handle)
{
  ACE_TRACE ("ACE_OS::dlclose");
#if defined (ACE_HAS_SVR4_DYNAMIC_LINKING)

# if !defined (ACE_HAS_AUTOMATIC_INIT_FINI)
  // SunOS4 does not automatically call _fini()!
  void *ptr;

  ACE_OSCALL (::dlsym (handle, ACE_TEXT ("_fini")), void *, 0, ptr);

  if (ptr != 0)
    (*((int (*)(void)) ptr)) (); // Call _fini hook explicitly.
# endif /* ACE_HAS_AUTOMATIC_INIT_FINI */
#if defined (_M_UNIX)
  ACE_OSCALL_RETURN (::_dlclose (handle), int, -1);
#else /* _MUNIX */
    ACE_OSCALL_RETURN (::dlclose (handle), int, -1);
#endif /* _M_UNIX */
#elif defined (ACE_WIN32)
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::FreeLibrary (handle), ace_result_), int, -1);
#elif defined (__hpux)
  // HP-UX 10.x and 32-bit 11.00 do not pay attention to the ref count
  // when unloading a dynamic lib.  So, if the ref count is more than
  // 1, do not unload the lib.  This will cause a library loaded more
  // than once to not be unloaded until the process runs down, but
  // that's life.  It's better than unloading a library that's in use.
  // So far as I know, there's no way to decrement the refcnt that the
  // kernel is looking at - the shl_descriptor is a copy of what the
  // kernel has, not the actual struct.  On 64-bit HP-UX using dlopen,
  // this problem has been fixed.
  struct shl_descriptor  desc;
  if (shl_gethandle_r (handle, &desc) == -1)
    return -1;
  if (desc.ref_count > 1)
    return 0;
# if defined(__GNUC__) || __cplusplus >= 199707L
  ACE_OSCALL_RETURN (::shl_unload (handle), int, -1);
# else
  ACE_OSCALL_RETURN (::cxxshl_unload (handle), int, -1);
# endif  /* aC++ vs. Hp C++ */
#else
  ACE_UNUSED_ARG (handle);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_SVR4_DYNAMIC_LINKING */
}

ACE_INLINE ACE_TCHAR *
ACE_OS::dlerror (void)
{
  ACE_TRACE ("ACE_OS::dlerror");
# if defined (ACE_HAS_SVR4_DYNAMIC_LINKING)
#if defined(_M_UNIX)
  ACE_OSCALL_RETURN ((char *)::_dlerror (), char *, 0);
#else /* _M_UNIX */
  ACE_OSCALL_RETURN ((char *)::dlerror (), char *, 0);
#endif /* _M_UNIX */
# elif defined (__hpux)
  ACE_OSCALL_RETURN (::strerror(errno), char *, 0);
# elif defined (ACE_WIN32)
  static ACE_TCHAR buf[128];
#   if defined (ACE_HAS_PHARLAP)
  ACE_OS::sprintf (buf, "error code %d", GetLastError());
#   else
  ACE_TEXT_FormatMessage (FORMAT_MESSAGE_FROM_SYSTEM,
                          NULL,
                          ::GetLastError (),
                          0,
                          buf,
                          sizeof buf / sizeof buf[0],
                          NULL);
#   endif /* ACE_HAS_PHARLAP */
  return buf;
# else
  ACE_NOTSUP_RETURN (0);
# endif /* ACE_HAS_SVR4_DYNAMIC_LINKING */
}

ACE_INLINE ACE_SHLIB_HANDLE
ACE_OS::dlopen (const ACE_TCHAR *fname,
                int mode)
{
  ACE_TRACE ("ACE_OS::dlopen");

  // Get the correct OS type.
  ACE_DL_TYPE filename = ACE_const_cast (ACE_DL_TYPE, fname);

# if defined (ACE_HAS_SVR4_DYNAMIC_LINKING)
  void *handle;
#   if defined (ACE_HAS_SGIDLADD)
  ACE_OSCALL (::sgidladd (filename, mode), void *, 0, handle);
#   elif defined (_M_UNIX)
  ACE_OSCALL (::_dlopen (filename, mode), void *, 0, handle);
#   else
  ACE_OSCALL (::dlopen (filename, mode), void *, 0, handle);
#   endif /* ACE_HAS_SGIDLADD */
#   if !defined (ACE_HAS_AUTOMATIC_INIT_FINI)
  if (handle != 0)
    {
      void *ptr;
      // Some systems (e.g., SunOS4) do not automatically call _init(), so
      // we'll have to call it manually.

      ACE_OSCALL (::dlsym (handle, ACE_TEXT ("_init")), void *, 0, ptr);

      if (ptr != 0 && (*((int (*)(void)) ptr)) () == -1) // Call _init hook explicitly.
        {
          // Close down the handle to prevent leaks.
          ::dlclose (handle);
          return 0;
        }
    }
#   endif /* ACE_HAS_AUTOMATIC_INIT_FINI */
  return handle;
# elif defined (ACE_WIN32)
  ACE_UNUSED_ARG (mode);

  ACE_WIN32CALL_RETURN (ACE_TEXT_LoadLibrary (filename), ACE_SHLIB_HANDLE, 0);
# elif defined (__hpux)

#   if defined(__GNUC__) || __cplusplus >= 199707L
  ACE_OSCALL_RETURN (::shl_load(filename, mode, 0L), ACE_SHLIB_HANDLE, 0);
#   else
  ACE_OSCALL_RETURN (::cxxshl_load(filename, mode, 0L), ACE_SHLIB_HANDLE, 0);
#   endif  /* aC++ vs. Hp C++ */

# else
  ACE_UNUSED_ARG (filename);
  ACE_UNUSED_ARG (mode);
  ACE_NOTSUP_RETURN (0);
# endif /* ACE_HAS_SVR4_DYNAMIC_LINKING */
}

ACE_INLINE void *
ACE_OS::dlsym (ACE_SHLIB_HANDLE handle,
               const ACE_TCHAR *sname)
{
  ACE_TRACE ("ACE_OS::dlsym");

  // Get the correct OS type.
#if defined (ACE_HAS_WINCE)
  const wchar_t *symbolname = sname;
#elif defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
  char *symbolname = ACE_TEXT_ALWAYS_CHAR (sname);
#elif defined (ACE_HAS_CHARPTR_DL)
  char *symbolname = ACE_const_cast (char *, sname);
#else
  const char *symbolname = sname;
#endif /* ACE_HAS_CHARPTR_DL */

# if defined (ACE_HAS_SVR4_DYNAMIC_LINKING)

#   if defined (ACE_LACKS_POSIX_PROTOTYPES)
  ACE_OSCALL_RETURN (::dlsym (handle, symbolname), void *, 0);
#   elif defined (ACE_USES_ASM_SYMBOL_IN_DLSYM)
  int l = ACE_OS::strlen (symbolname) + 2;
  char *asm_symbolname = 0;
  ACE_NEW_RETURN (asm_symbolname, char[l], 0);
  ACE_OS::strcpy (asm_symbolname, "_") ;
  ACE_OS::strcpy (asm_symbolname + 1, symbolname) ;
  void *ace_result;
  ACE_OSCALL (::dlsym (handle, asm_symbolname), void *, 0, ace_result);
  delete [] asm_symbolname;
  return ace_result;
#   elif defined (_M_UNIX)
  ACE_OSCALL_RETURN (::_dlsym (handle, symbolname), void *, 0);
#   else
  ACE_OSCALL_RETURN (::dlsym (handle, symbolname), void *, 0);
#   endif /* ACE_LACKS_POSIX_PROTOTYPES */

# elif defined (ACE_WIN32)

  ACE_WIN32CALL_RETURN (::GetProcAddress (handle, symbolname), void *, 0);

# elif defined (__hpux)

  void *value;
  int status;
  shl_t _handle = handle;
  ACE_OSCALL (::shl_findsym(&_handle, symbolname, TYPE_UNDEFINED, &value), int, -1, status);
  return status == 0 ? value : NULL;

# else

  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (symbolname);
  ACE_NOTSUP_RETURN (0);

# endif /* ACE_HAS_SVR4_DYNAMIC_LINKING */
}

ACE_INLINE int
ACE_OS::step (const char *str, char *expbuf)
{
  ACE_TRACE ("ACE_OS::step");
#if defined (ACE_HAS_REGEX)
  ACE_OSCALL_RETURN (::step (str, expbuf), int, -1);
#else
  ACE_UNUSED_ARG (str);
  ACE_UNUSED_ARG (expbuf);

  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_REGEX */
}

ACE_INLINE long
ACE_OS::sysinfo (int cmd, char *buf, long count)
{
  ACE_TRACE ("ACE_OS::sysinfo");
#if defined (ACE_HAS_SYSINFO)
  ACE_OSCALL_RETURN (::sysinfo (cmd, buf, count), long, -1);
#else
  ACE_UNUSED_ARG (cmd);
  ACE_UNUSED_ARG (buf);
  ACE_UNUSED_ARG (count);

  ACE_NOTSUP_RETURN (0);
#endif /* ACE_HAS_SYSINFO */
}

ACE_INLINE ssize_t
ACE_OS::write (ACE_HANDLE handle, const void *buf, size_t nbyte)
{
  ACE_TRACE ("ACE_OS::write");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_write (handle, buf, nbyte), ssize_t, -1);
#elif defined (ACE_WIN32)
  DWORD bytes_written; // This is set to 0 byte WriteFile.

  if (::WriteFile (handle, buf, nbyte, &bytes_written, 0))
    return (ssize_t) bytes_written;
  else
    ACE_FAIL_RETURN (-1);
#elif defined (ACE_PSOS)
# if defined (ACE_PSOS_LACKS_PHILE)
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (buf);
  ACE_UNUSED_ARG (nbyte);
  ACE_NOTSUP_RETURN (-1);
# else
  if(::write_f(handle, (void *) buf, nbyte) == 0)
    return (ssize_t) nbyte;
  else
    return -1;
# endif /* defined (ACE_PSOS_LACKS_PHILE) */
#else
# if defined (ACE_LACKS_POSIX_PROTOTYPES)
  ACE_OSCALL_RETURN (::write (handle, (const char *) buf, nbyte), ssize_t, -1);
# elif defined (ACE_PSOS)
  ACE_OSCALL_RETURN (::write_f(handle, (void *) buf, nbyte), ssize_t, -1);
# elif defined (ACE_HAS_CHARPTR_SOCKOPT)
  ACE_OSCALL_RETURN (::write (handle, (char *) buf, nbyte), ssize_t, -1);
# else
  ACE_OSCALL_RETURN (::write (handle, buf, nbyte), ssize_t, -1);
# endif /* ACE_LACKS_POSIX_PROTOTYPES */
#endif /* ACE_HAS_PACE */
}

ACE_INLINE ssize_t
ACE_OS::write (ACE_HANDLE handle, const void *buf, size_t nbyte,
               ACE_OVERLAPPED *overlapped)
{
  ACE_TRACE ("ACE_OS::write");
  overlapped = overlapped;
#if defined (ACE_WIN32)
  DWORD bytes_written; // This is set to 0 byte WriteFile.

  if (::WriteFile (handle, buf, nbyte, &bytes_written, overlapped))
    return (ssize_t) bytes_written;
  else
    return -1;
#else
  return ACE_OS::write (handle, buf, nbyte);
#endif /* ACE_WIN32 */
}

ACE_INLINE ssize_t
ACE_OS::read (ACE_HANDLE handle, void *buf, size_t len)
{
  ACE_TRACE ("ACE_OS::read");
#if defined (ACE_HAS_PACE)
  int result;
  ACE_OSCALL (pace_read (handle, buf, len), ssize_t, -1, result);
  if (result == -1 && errno == EAGAIN)
    errno = EWOULDBLOCK;
  return result;
#elif defined (ACE_WIN32)
  DWORD ok_len;
  if (::ReadFile (handle, buf, len, &ok_len, 0))
    return (ssize_t) ok_len;
  else
    ACE_FAIL_RETURN (-1);
#elif defined (ACE_PSOS)
# if defined (ACE_PSOS_LACKS_PHILE)
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (buf);
  ACE_UNUSED_ARG (len);
  ACE_NOTSUP_RETURN (-1);
# else
  unsigned long count, result;
  result = ::read_f (handle, buf, len, &count);
  if (result != 0)
    {
      return ACE_static_cast (ssize_t, -1);
    }
  else
    {
      return ACE_static_cast (ssize_t,
                              (count = len ? count : 0));
    }
# endif /* defined (ACE_PSOS_LACKS_PHILE */
#else

  int result;

# if defined (ACE_LACKS_POSIX_PROTOTYPES) || defined (ACE_HAS_CHARPTR_SOCKOPT)
  ACE_OSCALL (::read (handle, (char *) buf, len), ssize_t, -1, result);
# else
  ACE_OSCALL (::read (handle, buf, len), ssize_t, -1, result);
# endif /* ACE_LACKS_POSIX_PROTOTYPES */
  if (result == -1 && errno == EAGAIN)
    errno = EWOULDBLOCK;
  return result;
#endif /* ACE_HAS_PACE */
}

ACE_INLINE ssize_t
ACE_OS::read (ACE_HANDLE handle, void *buf, size_t len,
              ACE_OVERLAPPED *overlapped)
{
  ACE_TRACE ("ACE_OS::read");
  overlapped = overlapped;
#if defined (ACE_WIN32)
  DWORD ok_len;
  return ::ReadFile (handle, buf, len, &ok_len, overlapped) ? (ssize_t) ok_len : -1;
#else
  return ACE_OS::read (handle, buf, len);
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::readlink (const char *path, char *buf, size_t bufsiz)
{
  ACE_TRACE ("ACE_OS::readlink");
# if defined (ACE_LACKS_READLINK) || \
     defined (ACE_HAS_WINCE) || defined (ACE_WIN32)
  ACE_UNUSED_ARG (path);
  ACE_UNUSED_ARG (buf);
  ACE_UNUSED_ARG (bufsiz);
  ACE_NOTSUP_RETURN (-1);
# else
#   if !defined(ACE_HAS_NONCONST_READLINK)
      ACE_OSCALL_RETURN (::readlink (path, buf, bufsiz), int, -1);
#   else
      ACE_OSCALL_RETURN (::readlink ((char *)path, buf, bufsiz), int, -1);
#   endif
# endif /* ACE_LACKS_READLINK */
}

ACE_INLINE int
ACE_OS::getmsg (ACE_HANDLE handle,
                struct strbuf *ctl,
                struct strbuf *data,
                int *flags)
{
  ACE_TRACE ("ACE_OS::getmsg");
#if defined (ACE_HAS_STREAM_PIPES)
  ACE_OSCALL_RETURN (::getmsg (handle, ctl, data, flags), int, -1);
#else
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (ctl);
  ACE_UNUSED_ARG (data);
  ACE_UNUSED_ARG (flags);

  // I'm not sure how to implement this correctly.
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_STREAM_PIPES */
}

ACE_INLINE int
ACE_OS::getpmsg (ACE_HANDLE handle,
                 struct strbuf *ctl,
                 struct strbuf *data,
                 int *band,
                 int *flags)
{
  ACE_TRACE ("ACE_OS::getpmsg");
#if defined (ACE_HAS_STREAM_PIPES)
  ACE_OSCALL_RETURN (::getpmsg (handle, ctl, data, band, flags), int, -1);
#else
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (ctl);
  ACE_UNUSED_ARG (data);
  ACE_UNUSED_ARG (band);
  ACE_UNUSED_ARG (flags);

  // I'm not sure how to implement this correctly.
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_STREAM_PIPES */
}

ACE_INLINE int
ACE_OS::getrusage (int who, struct rusage *ru)
{
  ACE_TRACE ("ACE_OS::getrusage");

#if defined (ACE_HAS_SYSCALL_GETRUSAGE)
  // This nonsense is necessary for HP/UX...
  ACE_OSCALL_RETURN (::syscall (SYS_GETRUSAGE, who, ru), int, -1);
#elif defined (ACE_HAS_GETRUSAGE)
# if defined (ACE_WIN32)
  ACE_UNUSED_ARG (who);

  FILETIME dummy_1;
  FILETIME dummy_2;
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::GetProcessTimes (::GetCurrentProcess(),
                                                             &dummy_1,   // start
                                                             &dummy_2,     // exited
                                                             &ru->ru_stime,
                                                             &ru->ru_utime),
                                          ace_result_),
                        int, -1);
# else
#   if defined (ACE_HAS_RUSAGE_WHO_ENUM)
  ACE_OSCALL_RETURN (::getrusage ((ACE_HAS_RUSAGE_WHO_ENUM) who, ru), int, -1);
#   else
  ACE_OSCALL_RETURN (::getrusage (who, ru), int, -1);
#   endif /* ACE_HAS_RUSAGE_WHO_ENUM */
# endif /* ACE_WIN32 */
#else
  who = who;
  ru = ru;
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_SYSCALL_GETRUSAGE */
}

ACE_INLINE int
ACE_OS::isastream (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_OS::isastream");
#if defined (ACE_HAS_STREAM_PIPES)
  ACE_OSCALL_RETURN (::isastream (handle), int, -1);
#else
  ACE_UNUSED_ARG (handle);

  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_STREAM_PIPES */
}

// Implements simple read/write control for pages.  Affects a page if
// part of the page is referenced.  Currently PROT_READ, PROT_WRITE,
// and PROT_RDWR has been mapped in OS.h.  This needn't have anything
// to do with a mmap region.

ACE_INLINE int
ACE_OS::mprotect (void *addr, size_t len, int prot)
{
  ACE_TRACE ("ACE_OS::mprotect");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_mprotect (addr, len, prot), int, -1);
#elif defined (ACE_WIN32) && !defined (ACE_HAS_PHARLAP)
  DWORD dummy; // Sigh!
  return ::VirtualProtect(addr, len, prot, &dummy) ? 0 : -1;
#elif !defined (ACE_LACKS_MPROTECT)
  ACE_OSCALL_RETURN (::mprotect ((ACE_MMAP_TYPE) addr, len, prot), int, -1);
#else
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (len);
  ACE_UNUSED_ARG (prot);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::msync (void *addr, size_t len, int sync)
{
  ACE_TRACE ("ACE_OS::msync");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_msync (addr, len, sync), int, -1);
#elif defined (ACE_WIN32) && !defined (ACE_HAS_PHARLAP)
  ACE_UNUSED_ARG (sync);

  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::FlushViewOfFile (addr, len), ace_result_), int, -1);
#elif !defined (ACE_LACKS_MSYNC)
# if !defined (ACE_HAS_BROKEN_NETBSD_MSYNC)
  ACE_OSCALL_RETURN (::msync ((ACE_MMAP_TYPE) addr, len, sync), int, -1);
# else
  ACE_OSCALL_RETURN (::msync ((ACE_MMAP_TYPE) addr, len), int, -1);
  ACE_UNUSED_ARG (sync);
# endif /* ACE_HAS_BROKEN_NETBSD_MSYNC */
#else
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (len);
  ACE_UNUSED_ARG (sync);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::munmap (void *addr, size_t len)
{
  ACE_TRACE ("ACE_OS::munmap");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_munmap (addr, len), int, -1);
#elif defined (ACE_WIN32)
  ACE_UNUSED_ARG (len);

  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::UnmapViewOfFile (addr), ace_result_), int, -1);
#elif !defined (ACE_LACKS_MMAP)
  ACE_OSCALL_RETURN (::munmap ((ACE_MMAP_TYPE) addr, len), int, -1);
#else
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (len);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::madvise (caddr_t addr, size_t len, int advice)
{
  ACE_TRACE ("ACE_OS::madvise");
#if defined (ACE_WIN32)
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (len);
  ACE_UNUSED_ARG (advice);

  ACE_NOTSUP_RETURN (-1);
#elif !defined (ACE_LACKS_MADVISE)
  ACE_OSCALL_RETURN (::madvise (addr, len, advice), int, -1);
#else
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (len);
  ACE_UNUSED_ARG (advice);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::putmsg (ACE_HANDLE handle, const struct strbuf *ctl,
                const struct strbuf *data, int flags)
{
  ACE_TRACE ("ACE_OS::putmsg");
#if defined (ACE_HAS_STREAM_PIPES)
  ACE_OSCALL_RETURN (::putmsg (handle,
                               (ACE_STRBUF_TYPE) ctl,
                               (ACE_STRBUF_TYPE) data,
                               flags), int, -1);
#else
  ACE_UNUSED_ARG (flags);
  if (ctl == 0 && data == 0)
    {
      errno = EINVAL;
      return 0;
    }
  // Handle the two easy cases.
  else if (ctl != 0)
    return ACE_OS::write (handle, ctl->buf, ctl->len);
  else if (data != 0)
    return ACE_OS::write (handle, data->buf, data->len);
  else
    {
      // This is the hard case.
      char *buf;
      ACE_NEW_RETURN (buf, char [ctl->len + data->len], -1);
      ACE_OS::memcpy (buf, ctl->buf, ctl->len);
      ACE_OS::memcpy (buf + ctl->len, data->buf, data->len);
      int result = ACE_OS::write (handle, buf, ctl->len + data->len);
      delete [] buf;
      return result;
    }
#endif /* ACE_HAS_STREAM_PIPES */
}

ACE_INLINE int
ACE_OS::putpmsg (ACE_HANDLE handle,
                 const struct strbuf *ctl,
                 const struct strbuf *data,
                 int band,
                 int flags)
{
  ACE_TRACE ("ACE_OS::putpmsg");
#if defined (ACE_HAS_STREAM_PIPES)
  ACE_OSCALL_RETURN (::putpmsg (handle,
                                (ACE_STRBUF_TYPE) ctl,
                                (ACE_STRBUF_TYPE) data,
                                band, flags), int, -1);
#else
  ACE_UNUSED_ARG (flags);
  ACE_UNUSED_ARG (band);
  return ACE_OS::putmsg (handle, ctl, data, flags);
#endif /* ACE_HAS_STREAM_PIPES */
}

ACE_INLINE int
ACE_OS::semctl (int int_id, int semnum, int cmd, semun value)
{
  ACE_TRACE ("ACE_OS::semctl");
#if defined (ACE_HAS_SYSV_IPC)
  ACE_OSCALL_RETURN (::semctl (int_id, semnum, cmd, value), int, -1);
#else
  ACE_UNUSED_ARG (int_id);
  ACE_UNUSED_ARG (semnum);
  ACE_UNUSED_ARG (cmd);
  ACE_UNUSED_ARG (value);

  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_SYSV_IPC */
}

ACE_INLINE int
ACE_OS::semget (key_t key, int nsems, int flags)
{
  ACE_TRACE ("ACE_OS::semget");
#if defined (ACE_HAS_SYSV_IPC)
  ACE_OSCALL_RETURN (::semget (key, nsems, flags), int, -1);
#else
  ACE_UNUSED_ARG (key);
  ACE_UNUSED_ARG (nsems);
  ACE_UNUSED_ARG (flags);

  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_SYSV_IPC */
}

ACE_INLINE int
ACE_OS::semop (int int_id, struct sembuf *sops, size_t nsops)
{
  ACE_TRACE ("ACE_OS::semop");
#if defined (ACE_HAS_SYSV_IPC)
  ACE_OSCALL_RETURN (::semop (int_id, sops, nsops), int, -1);
#else
  ACE_UNUSED_ARG (int_id);
  ACE_UNUSED_ARG (sops);
  ACE_UNUSED_ARG (nsops);

  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_SYSV_IPC */
}

ACE_INLINE void *
ACE_OS::shmat (int int_id, void *shmaddr, int shmflg)
{
  ACE_TRACE ("ACE_OS::shmat");
#if defined (ACE_HAS_SYSV_IPC)
# if defined (ACE_LACKS_POSIX_PROTOTYPES) || defined (ACE_LACKS_SOME_POSIX_PROTOTYPES)
  ACE_OSCALL_RETURN (::shmat (int_id, (char *)shmaddr, shmflg), void *, (void *) -1);
# else
  ACE_OSCALL_RETURN (::shmat (int_id, shmaddr, shmflg), void *, (void *) -1);
# endif /* ACE_LACKS_POSIX_PROTOTYPES */
#else
  ACE_UNUSED_ARG (int_id);
  ACE_UNUSED_ARG (shmaddr);
  ACE_UNUSED_ARG (shmflg);

  ACE_NOTSUP_RETURN ((void *) -1);
#endif /* ACE_HAS_SYSV_IPC */
}

ACE_INLINE int
ACE_OS::shmctl (int int_id, int cmd, struct shmid_ds *buf)
{
  ACE_TRACE ("ACE_OS::shmctl");
#if defined (ACE_HAS_SYSV_IPC)
  ACE_OSCALL_RETURN (::shmctl (int_id, cmd, buf), int, -1);
#else
  ACE_UNUSED_ARG (buf);
  ACE_UNUSED_ARG (cmd);
  ACE_UNUSED_ARG (int_id);

  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_SYSV_IPC */
}

ACE_INLINE int
ACE_OS::shmdt (void *shmaddr)
{
  ACE_TRACE ("ACE_OS::shmdt");
#if defined (ACE_HAS_SYSV_IPC)
  ACE_OSCALL_RETURN (::shmdt ((char *) shmaddr), int, -1);
#else
  ACE_UNUSED_ARG (shmaddr);

  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_SYSV_IPC */
}

ACE_INLINE int
ACE_OS::shmget (key_t key, int size, int flags)
{
  ACE_TRACE ("ACE_OS::shmget");
#if defined (ACE_HAS_SYSV_IPC)
  ACE_OSCALL_RETURN (::shmget (key, size, flags), int, -1);
#else
  ACE_UNUSED_ARG (flags);
  ACE_UNUSED_ARG (size);
  ACE_UNUSED_ARG (key);

  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_SYSV_IPC */
}

ACE_INLINE void
ACE_OS::tzset (void)
{
#if defined (ACE_HAS_PACE)
  pace_tzset ();
# elif !defined (ACE_HAS_WINCE) && !defined (VXWORKS) && !defined (ACE_PSOS)
#   if defined (ACE_WIN32)
  ::_tzset ();  // For Win32.
#   else
  ::tzset ();   // For UNIX platforms.
#   endif /* ACE_WIN32 */
# else
  errno = ENOTSUP;
# endif /* ACE_HAS_PACE */
}

ACE_INLINE long
ACE_OS::timezone (void)
{
# if !defined (ACE_HAS_WINCE) && !defined (VXWORKS) && !defined (ACE_PSOS) \
&& !defined (CHORUS)
#   if defined (ACE_WIN32)
  return _timezone;  // For Win32.
#   elif defined (__Lynx__) || defined (__FreeBSD__) || defined (ACE_HAS_SUNOS4_GETTIMEOFDAY)
  long result = 0;
  struct timeval time;
  struct timezone zone;
  ACE_UNUSED_ARG (result);
  ACE_OSCALL (::gettimeofday (&time, &zone), int, -1, result);
  return zone.tz_minuteswest * 60;
#   else
  return ::timezone;   // For UNIX platforms.
#   endif
# else
  ACE_NOTSUP_RETURN (0);
# endif /* !ACE_HAS_WINCE && !VXWORKS && !ACE_PSOS */
}

#if !defined (ACE_LACKS_DIFFTIME)
ACE_INLINE double
ACE_OS::difftime (time_t t1, time_t t0)
{
#if defined (ACE_HAS_PACE)
  return pace_difftime (t1, t0);
#elif defined (ACE_PSOS) && ! defined (ACE_PSOS_HAS_TIME)
  // simulate difftime ; just subtracting ; ACE_PSOS case
  return ((double)t1) - ((double)t0);
#else
# if defined (ACE_DIFFTIME)
  return ACE_DIFFTIME (t1, t0);
# else
  return ::difftime (t1, t0);
# endif /* ACE_DIFFTIME  && ! ACE_PSOS_HAS_TIME */
#endif /* ACE_HAS_PACE */
}
#endif /* ! ACE_LACKS_DIFFTIME */

ACE_INLINE ACE_TCHAR *
ACE_OS::ctime (const time_t *t)
{
  ACE_TRACE ("ACE_OS::ctime");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_ctime (t), char*, 0);
#elif defined (ACE_HAS_BROKEN_CTIME)
  ACE_OSCALL_RETURN (::asctime (::localtime (t)), char *, 0);
#elif defined(ACE_PSOS) && ! defined (ACE_PSOS_HAS_TIME)
  return "ctime-return";
#elif defined (ACE_HAS_WINCE)
  ACE_TCHAR buf[26];              // 26 is a "magic number" ;)
  return ACE_OS::ctime_r (t, buf, 26);
#elif defined (ACE_USES_WCHAR)
  ACE_OSCALL_RETURN (::_wctime (t), wchar_t *, 0);
#else
  ACE_OSCALL_RETURN (::ctime (t), char *, 0);
# endif    /* ACE_HAS_PACE */
}

#if !defined (ACE_HAS_WINCE)  /* CE version in OS.cpp */
ACE_INLINE ACE_TCHAR *
ACE_OS::ctime_r (const time_t *t, ACE_TCHAR *buf, int buflen)
{
  ACE_TRACE ("ACE_OS::ctime_r");
#if defined (ACE_HAS_PACE)
  ACE_UNUSED_ARG (buflen);
  ACE_OSCALL_RETURN (pace_ctime_r (t, buf), ACE_TCHAR*, 0);
# elif defined (ACE_HAS_REENTRANT_FUNCTIONS)
#   if defined (ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R)
  ACE_TCHAR *result;
#     if defined (DIGITAL_UNIX)
  ACE_OSCALL (::_Pctime_r (t, buf), ACE_TCHAR *, 0, result);
#     else /* DIGITAL_UNIX */
  ACE_OSCALL (::ctime_r (t, buf), ACE_TCHAR *, 0, result);
#     endif /* DIGITAL_UNIX */
  if (result != 0)
    ::strncpy (buf, result, buflen);
  return buf;
#   else /* ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R */

#     if defined (ACE_CTIME_R_RETURNS_INT)
  return (::ctime_r (t, buf, buflen) == -1 ? 0 : buf);
#     else /* ACE_CTIME_R_RETURNS_INT */
  ACE_OSCALL_RETURN (::ctime_r (t, buf, buflen), ACE_TCHAR *, 0);
#     endif /* ACE_CTIME_R_RETURNS_INT */

#   endif /* ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R */
# else /* ACE_HAS_REENTRANT_FUNCTIONS */
#   if defined(ACE_PSOS) && ! defined (ACE_PSOS_HAS_TIME)
   ::strncpy(buf, "ctime-return",buflen);
   return buf;
#   else /* ACE_PSOS && !ACE_PSOS_HAS_TIME */

  ACE_TCHAR *result;
#     if defined (ACE_USES_WCHAR)
  ACE_OSCALL (::_wctime (t), wchar_t *, 0, result);
#     else /* ACE_WIN32 */
  ACE_OSCALL (::ctime (t), char *, 0, result);
#     endif /* ACE_WIN32 */
  if (result != 0)
    ACE_OS::strncpy (buf, result, buflen);
  return buf;
#    endif /* ACE_PSOS && !ACE_PSOS_HAS_TIME */
# endif /* ACE_HAS_PACE */
}
#endif /* !ACE_HAS_WINCE */

ACE_INLINE struct tm *
ACE_OS::localtime (const time_t *t)
{
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_localtime (t), pace_tm*, 0);
#elif !defined (ACE_HAS_WINCE) && !defined(ACE_PSOS) || defined (ACE_PSOS_HAS_TIME)
  ACE_TRACE ("ACE_OS::localtime");
  ACE_OSCALL_RETURN (::localtime (t), struct tm *, 0);
#else
  // @@ Don't you start wondering what kind of functions
  //    does WinCE really support?
  ACE_UNUSED_ARG (t);
  ACE_NOTSUP_RETURN (0);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE struct tm *
ACE_OS::gmtime (const time_t *t)
{
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_gmtime (t), pace_tm*, 0);
#elif !defined (ACE_HAS_WINCE) && !defined (ACE_PSOS) || defined (ACE_PSOS_HAS_TIME)
  ACE_TRACE ("ACE_OS::localtime");
  ACE_OSCALL_RETURN (::gmtime (t), struct tm *, 0);
#else
  // @@ WinCE doesn't have gmtime also.
  ACE_UNUSED_ARG (t);
  ACE_NOTSUP_RETURN (0);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE struct tm *
ACE_OS::gmtime_r (const time_t *t, struct tm *res)
{
  ACE_TRACE ("ACE_OS::localtime_r");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_gmtime_r (t, res), pace_tm*, 0);
#elif defined (ACE_HAS_REENTRANT_FUNCTIONS)
# if defined (DIGITAL_UNIX)
  ACE_OSCALL_RETURN (::_Pgmtime_r (t, res), struct tm *, 0);
# elif defined (HPUX_10)
  return (::gmtime_r (t, res) == 0 ? res : (struct tm *) 0);
# else
  ACE_OSCALL_RETURN (::gmtime_r (t, res), struct tm *, 0);
# endif /* DIGITAL_UNIX */
#elif !defined (ACE_HAS_WINCE) && !defined(ACE_PSOS) || defined (ACE_PSOS_HAS_TIME)
  struct tm *result;
  ACE_OSCALL (::gmtime (t), struct tm *, 0, result) ;
  if (result != 0)
    *res = *result;
  return res;
#else
  // @@ Same as ACE_OS::gmtime (), you need to implement it
  //    yourself.
  ACE_UNUSED_ARG (t);
  ACE_UNUSED_ARG (res);
  ACE_NOTSUP_RETURN (0);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE char *
ACE_OS::asctime (const struct tm *t)
{
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_asctime (t), char*, 0);
#elif !defined (ACE_HAS_WINCE) && !defined(ACE_PSOS) || defined (ACE_PSOS_HAS_TIME)
  ACE_TRACE ("ACE_OS::asctime");
  ACE_OSCALL_RETURN (::asctime (t), char *, 0);
#else
  // @@ WinCE doesn't have gmtime also.
  ACE_UNUSED_ARG (t);
  ACE_NOTSUP_RETURN (0);
#endif /*  ACE_HAS_PACE */
}

ACE_INLINE char *
ACE_OS::asctime_r (const struct tm *t, char *buf, int buflen)
{
  ACE_TRACE ("ACE_OS::asctime_r");
#if defined (ACE_HAS_PACE)
  ACE_UNUSED_ARG (buflen);
  ACE_OSCALL_RETURN (pace_asctime_r (t, buf), char*, 0);
#elif defined (ACE_HAS_REENTRANT_FUNCTIONS)
# if defined (ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R)
  char *result;
#   if defined (DIGITAL_UNIX)
  ACE_OSCALL (::_Pasctime_r (t, buf), char *, 0, result);
#   else
  ACE_OSCALL (::asctime_r (t, buf), char *, 0, result);
#   endif /* DIGITAL_UNIX */
  ::strncpy (buf, result, buflen);
  return buf;
# else
#   if defined (HPUX_10)
  return (::asctime_r(t, buf, buflen) == 0 ? buf : (char *)0);
#   else
  ACE_OSCALL_RETURN (::asctime_r (t, buf, buflen), char *, 0);
#   endif /* HPUX_10 */
# endif /* ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R */
#elif ! defined (ACE_HAS_WINCE) && !defined(ACE_PSOS) || defined (ACE_PSOS_HAS_TIME)
  char *result;
  ACE_OSCALL (::asctime (t), char *, 0, result);
  ::strncpy (buf, result, buflen);
  return buf;
#else
  // @@ Same as ACE_OS::asctime (), you need to implement it
  //    yourself.
  ACE_UNUSED_ARG (t);
  ACE_UNUSED_ARG (buf);
  ACE_UNUSED_ARG (buflen);
  ACE_NOTSUP_RETURN (0);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE size_t
ACE_OS::strftime (char *s, size_t maxsize, const char *format,
                  const struct tm *timeptr)
{
#if defined (ACE_HAS_PACE)
  return pace_strftime (s, maxsize, format, timeptr);
#elif !defined (ACE_HAS_WINCE) && !defined(ACE_PSOS) || defined (ACE_PSOS_HAS_TIME)
  return ::strftime (s, maxsize, format, timeptr);
#else
  ACE_UNUSED_ARG (s);
  ACE_UNUSED_ARG (maxsize);
  ACE_UNUSED_ARG (format);
  ACE_UNUSED_ARG (timeptr);
  ACE_NOTSUP_RETURN (0);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::flock_init (ACE_OS::ace_flock_t *lock,
                    int flags,
                    const ACE_TCHAR *name,
                    mode_t perms)
{
  ACE_TRACE ("ACE_OS::flock_init");
#if defined (CHORUS)
  lock->lockname_ = 0;
  // Let's see if it already exists.
  lock->handle_ = ACE_OS::shm_open (name,
                                    flags | O_CREAT | O_EXCL,
                                    perms);
  if (lock->handle_ == ACE_INVALID_HANDLE)
    {
      if (errno == EEXIST)
        // It's already there, so we'll just open it.
        lock->handle_ = ACE_OS::shm_open (name,
                                          flags | O_CREAT,
                                          ACE_DEFAULT_FILE_PERMS);
      else
        return -1;
    }
  else
    {
      // We own this shared memory object!  Let's set its size.
      if (ACE_OS::ftruncate (lock->handle_,
                             sizeof (ACE_mutex_t)) == -1)
        return -1;
      // Note that only the owner can destroy a file lock...
      ACE_ALLOCATOR_RETURN (lock->lockname_,
                            ACE_OS::strdup (name),
                            -1);
    }
  if (lock->handle_ == ACE_INVALID_HANDLE)
    return -1;

  lock->process_lock_ =
    (ACE_mutex_t *) ACE_OS::mmap (0,
                                  sizeof (ACE_mutex_t),
                                  PROT_RDWR,
                                  MAP_SHARED,
                                  lock->handle_,
                                  0);
  if (lock->process_lock_ == MAP_FAILED)
    return -1;

  if (lock->lockname_
      // Only initialize it if we're the one who created it.
      && ACE_OS::mutex_init (lock->process_lock_,
                             USYNC_PROCESS,
                             name,
                             0) != 0)
        return -1;
  return 0;
#else
#if defined (ACE_WIN32)
  // Once initialized, these values are never changed.
  lock->overlapped_.Internal = 0;
  lock->overlapped_.InternalHigh = 0;
  lock->overlapped_.OffsetHigh = 0;
  lock->overlapped_.hEvent = NULL;
#endif /* ACE_WIN32 */
  lock->handle_ = ACE_INVALID_HANDLE;
  lock->lockname_ = 0;

  if (name != 0)
    {
      ACE_OSCALL (ACE_OS::open (name, flags, perms),
                  ACE_HANDLE,
                  ACE_INVALID_HANDLE,
                  lock->handle_);
      lock->lockname_ = ACE_OS::strdup (name);
      return lock->handle_ == ACE_INVALID_HANDLE ? -1 : 0;
    }
  else
    return 0;
#endif /* CHORUS */
}

#if defined (ACE_WIN32)
ACE_INLINE void
ACE_OS::adjust_flock_params (ACE_OS::ace_flock_t *lock,
                             short whence,
                             off_t &start,
                             off_t &len)
{
  switch (whence)
    {
    case SEEK_SET:
      break;
    case SEEK_CUR:
      start += SetFilePointer (lock->handle_, 0, 0, FILE_CURRENT);
      break;
    case SEEK_END:
      start += ::GetFileSize (lock->handle_, NULL);
      break;
    }
  lock->overlapped_.Offset = start;
  if (len == 0)
    len = ::GetFileSize (lock->handle_,
                         NULL) - start;
}
#endif /* ACE_WIN32 */

ACE_INLINE int
ACE_OS::flock_wrlock (ACE_OS::ace_flock_t *lock,
                      short whence,
                      off_t start,
                      off_t len)
{
  ACE_TRACE ("ACE_OS::flock_wrlock");
#if defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)
  ACE_OS::adjust_flock_params (lock, whence, start, len);
#  if defined (ACE_HAS_WINNT4) && (ACE_HAS_WINNT4 != 0)
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::LockFileEx (lock->handle_,
                                                        LOCKFILE_EXCLUSIVE_LOCK,
                                                        0,
                                                        len,
                                                        0,
                                                        &lock->overlapped_),
                                          ace_result_), int, -1);
#  else /* ACE_HAS_WINNT4 && (ACE_HAS_WINNT4 != 0) */
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::LockFile (lock->handle_,
                                                      lock->overlapped_.Offset,
                                                      0,
                                                      len,
                                                      0),
                                          ace_result_), int, -1);
#  endif /* ACE_HAS_WINNT4 && (ACE_HAS_WINNT4 != 0) */
#elif defined (CHORUS)
  ACE_UNUSED_ARG (whence);
  ACE_UNUSED_ARG (start);
  ACE_UNUSED_ARG (len);
  return ACE_OS::mutex_lock (lock->process_lock_);
#elif defined (ACE_LACKS_FILELOCKS)
  ACE_UNUSED_ARG (lock);
  ACE_UNUSED_ARG (whence);
  ACE_UNUSED_ARG (start);
  ACE_UNUSED_ARG (len);
  ACE_NOTSUP_RETURN (-1);
#else
  lock->lock_.l_whence = whence;
  lock->lock_.l_start = start;
  lock->lock_.l_len = len;
  lock->lock_.l_type = F_WRLCK;         // set write lock
  // block, if no access
  ACE_OSCALL_RETURN (ACE_OS::fcntl (lock->handle_, F_SETLKW,
                                    ACE_reinterpret_cast (long, &lock->lock_)),
                     int, -1);
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::flock_rdlock (ACE_OS::ace_flock_t *lock,
                      short whence,
                      off_t start,
                      off_t len)
{
  ACE_TRACE ("ACE_OS::flock_rdlock");
#if defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)
  ACE_OS::adjust_flock_params (lock, whence, start, len);
#  if defined (ACE_HAS_WINNT4) && (ACE_HAS_WINNT4 != 0)
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::LockFileEx (lock->handle_,
                                                        0,
                                                        0,
                                                        len,
                                                        0,
                                                        &lock->overlapped_),
                                          ace_result_), int, -1);
#  else /* ACE_HAS_WINNT4 && (ACE_HAS_WINNT4 != 0) */
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::LockFile (lock->handle_,
                                                      lock->overlapped_.Offset,
                                                      0,
                                                      len,
                                                      0),
                                          ace_result_), int, -1);
#  endif /* ACE_HAS_WINNT4 && (ACE_HAS_WINNT4 != 0) */
#elif defined (CHORUS)
  ACE_UNUSED_ARG (whence);
  ACE_UNUSED_ARG (start);
  ACE_UNUSED_ARG (len);
  return ACE_OS::mutex_lock (lock->process_lock_);
#elif defined (ACE_LACKS_FILELOCKS)
  ACE_UNUSED_ARG (lock);
  ACE_UNUSED_ARG (whence);
  ACE_UNUSED_ARG (start);
  ACE_UNUSED_ARG (len);
  ACE_NOTSUP_RETURN (-1);
#else
  lock->lock_.l_whence = whence;
  lock->lock_.l_start = start;
  lock->lock_.l_len = len;
  lock->lock_.l_type = F_RDLCK;         // set read lock
  // block, if no access
  ACE_OSCALL_RETURN (ACE_OS::fcntl (lock->handle_, F_SETLKW,
                                    ACE_reinterpret_cast (long, &lock->lock_)),
                     int, -1);
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::flock_trywrlock (ACE_OS::ace_flock_t *lock,
                         short whence,
                         off_t start,
                         off_t len)
{
  ACE_TRACE ("ACE_OS::ace_flock_trywrlock");
#if defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)
#  if defined (ACE_HAS_WINNT4) && (ACE_HAS_WINNT4 != 0)
  ACE_OS::adjust_flock_params (lock, whence, start, len);
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::LockFileEx (lock->handle_,
                                                        LOCKFILE_FAIL_IMMEDIATELY | LOCKFILE_EXCLUSIVE_LOCK,
                                                        0,
                                                        len,
                                                        0,
                                                        &lock->overlapped_),
                                          ace_result_), int, -1);
#  else /* ACE_HAS_WINNT4 && (ACE_HAS_WINNT4 != 0) */
  ACE_UNUSED_ARG (lock);
  ACE_UNUSED_ARG (whence);
  ACE_UNUSED_ARG (start);
  ACE_UNUSED_ARG (len);
  ACE_NOTSUP_RETURN (-1);
#  endif /* ACE_HAS_WINNT4 && (ACE_HAS_WINNT4 != 0) */
#elif defined (CHORUS)
  ACE_UNUSED_ARG (whence);
  ACE_UNUSED_ARG (start);
  ACE_UNUSED_ARG (len);
  return ACE_OS::mutex_trylock (lock->process_lock_);
#elif defined (ACE_LACKS_FILELOCKS)
  ACE_UNUSED_ARG (lock);
  ACE_UNUSED_ARG (whence);
  ACE_UNUSED_ARG (start);
  ACE_UNUSED_ARG (len);
  ACE_NOTSUP_RETURN (-1);
#else
  lock->lock_.l_whence = whence;
  lock->lock_.l_start = start;
  lock->lock_.l_len = len;
  lock->lock_.l_type = F_WRLCK;         // set write lock

  int result = 0;
  // Does not block, if no access, returns -1 and set errno = EBUSY;
  ACE_OSCALL (ACE_OS::fcntl (lock->handle_,
                             F_SETLK,
                             ACE_reinterpret_cast (long, &lock->lock_)),
              int, -1, result);

# if ! defined (ACE_PSOS)
  if (result == -1 && (errno == EACCES || errno == EAGAIN))
    errno = EBUSY;
# endif /* ! defined (ACE_PSOS) */

  return result;
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::flock_tryrdlock (ACE_OS::ace_flock_t *lock,
                         short whence,
                         off_t start,
                         off_t len)
{
  ACE_TRACE ("ACE_OS::ace_flock_tryrdlock");
#if defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)
#  if defined (ACE_HAS_WINNT4) && (ACE_HAS_WINNT4 != 0)
  ACE_OS::adjust_flock_params (lock, whence, start, len);
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::LockFileEx (lock->handle_,
                                                        LOCKFILE_FAIL_IMMEDIATELY,
                                                        0,
                                                        len,
                                                        0,
                                                        &lock->overlapped_),
                                          ace_result_), int, -1);
#  else /* ACE_HAS_WINNT4 && (ACE_HAS_WINNT4 != 0) */
  ACE_UNUSED_ARG (lock);
  ACE_UNUSED_ARG (whence);
  ACE_UNUSED_ARG (start);
  ACE_UNUSED_ARG (len);
  ACE_NOTSUP_RETURN (-1);
#  endif /* ACE_HAS_WINNT4 && (ACE_HAS_WINNT4 != 0) */
#elif defined (CHORUS)
  ACE_UNUSED_ARG (whence);
  ACE_UNUSED_ARG (start);
  ACE_UNUSED_ARG (len);
  return ACE_OS::mutex_trylock (lock->process_lock_);
#elif defined (ACE_LACKS_FILELOCKS)
  ACE_UNUSED_ARG (lock);
  ACE_UNUSED_ARG (whence);
  ACE_UNUSED_ARG (start);
  ACE_UNUSED_ARG (len);
  ACE_NOTSUP_RETURN (-1);
#else
  lock->lock_.l_whence = whence;
  lock->lock_.l_start = start;
  lock->lock_.l_len = len;
  lock->lock_.l_type = F_RDLCK;         // set read lock

  int result = 0;
  // Does not block, if no access, returns -1 and set errno = EBUSY;
  ACE_OSCALL (ACE_OS::fcntl (lock->handle_, F_SETLK,
                             ACE_reinterpret_cast (long, &lock->lock_)),
              int, -1, result);

# if ! defined (ACE_PSOS)
  if (result == -1 && (errno == EACCES || errno == EAGAIN))
    errno = EBUSY;
# endif /* ! defined (ACE_PSOS) */

  return result;
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::flock_unlock (ACE_OS::ace_flock_t *lock,
                      short whence,
                      off_t start,
                      off_t len)
{
  ACE_TRACE ("ACE_OS::flock_unlock");
#if defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)
  ACE_OS::adjust_flock_params (lock, whence, start, len);
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::UnlockFile (lock->handle_,
                                                        lock->overlapped_.Offset,
                                                        0,
                                                        len,
                                                        0),
                                          ace_result_), int, -1);
#elif defined (CHORUS)
  ACE_UNUSED_ARG (whence);
  ACE_UNUSED_ARG (start);
  ACE_UNUSED_ARG (len);
  return ACE_OS::mutex_unlock (lock->process_lock_);
#elif defined (ACE_LACKS_FILELOCKS)
  ACE_UNUSED_ARG (lock);
  ACE_UNUSED_ARG (whence);
  ACE_UNUSED_ARG (start);
  ACE_UNUSED_ARG (len);
  ACE_NOTSUP_RETURN (-1);
#else
  lock->lock_.l_whence = whence;
  lock->lock_.l_start = start;
  lock->lock_.l_len = len;
  lock->lock_.l_type = F_UNLCK;   // Unlock file.

  // release lock
  ACE_OSCALL_RETURN (ACE_OS::fcntl (lock->handle_, F_SETLK,
                                    ACE_reinterpret_cast (long, &lock->lock_)),
                     int, -1);
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::flock_destroy (ACE_OS::ace_flock_t *lock,
                       int unlink_file)
{
  ACE_TRACE ("ACE_OS::flock_destroy");
  if (lock->handle_ != ACE_INVALID_HANDLE)
    {
      ACE_OS::flock_unlock (lock);
      // Close the handle.
      ACE_OS::close (lock->handle_);
      lock->handle_ = ACE_INVALID_HANDLE;
#if defined (CHORUS)
      // Are we the owner?
      if (lock->process_lock_ && lock->lockname_ != 0)
        {
          // Only destroy the lock if we're the owner
          ACE_OS::mutex_destroy (lock->process_lock_);
          ACE_OS::munmap (lock->process_lock_,
                          sizeof (ACE_mutex_t));
          if (unlink_file)
            ACE_OS::shm_unlink (lock->lockname_);
          ACE_OS::free (ACE_static_cast (void *,
                                         ACE_const_cast (ACE_TCHAR *,
                                                         lock->lockname_)));
        }
      else if (lock->process_lock_)
        // Just unmap the memory.
        ACE_OS::munmap (lock->process_lock_,
                        sizeof (ACE_mutex_t));
#else
      if (lock->lockname_ != 0)
        {
          if (unlink_file)
            ACE_OS::unlink (lock->lockname_);
          ACE_OS::free (ACE_static_cast (void *,
                                         ACE_const_cast (ACE_TCHAR *,
                                                         lock->lockname_)));
        }
#endif /* CHORUS */
      lock->lockname_ = 0;
    }
  return 0;
}

ACE_INLINE int
ACE_OS::execv (const char *path,
               char *const argv[])
{
  ACE_TRACE ("ACE_OS::execv");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (execv (path, argv), int, -1);
#elif defined (ACE_LACKS_EXEC)
  ACE_UNUSED_ARG (path);
  ACE_UNUSED_ARG (argv);

  ACE_NOTSUP_RETURN (-1);
#elif defined (CHORUS)
  KnCap cactorcap;
  int result = ::afexecv (path, &cactorcap, 0, argv);
  if (result != -1)
    ACE_OS::actorcaps_[result] = cactorcap;
  return result;
#elif defined (ACE_WIN32)
# if defined (__BORLANDC__) /* VSB */
  return ::execv (path, argv);
# else
  return ::_execv (path, (const char *const *) argv);
# endif /* __BORLANDC__ */
#elif defined (ACE_LACKS_POSIX_PROTOTYPES)
  ACE_OSCALL_RETURN (::execv (path, (const char **) argv), int, -1);
#else
  ACE_OSCALL_RETURN (::execv (path, argv), int, -1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::execve (const char *path,
                char *const argv[],
                char *const envp[])
{
  ACE_TRACE ("ACE_OS::execve");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_execve (path, argv, envp), int, -1);
#elif defined (ACE_LACKS_EXEC)
  ACE_UNUSED_ARG (path);
  ACE_UNUSED_ARG (argv);
  ACE_UNUSED_ARG (envp);

  ACE_NOTSUP_RETURN (-1);
#elif defined(CHORUS)
  KnCap cactorcap;
  int result = ::afexecve (path, &cactorcap, 0, argv, envp);
  if (result != -1)
    ACE_OS::actorcaps_[result] = cactorcap;
  return result;
#elif defined (ACE_WIN32)
# if defined (__BORLANDC__) /* VSB */
  return ::execve (path, argv, envp);
# else
  return ::_execve (path, (const char *const *) argv, (const char *const *) envp);
# endif /* __BORLANDC__ */
#elif defined (ACE_LACKS_POSIX_PROTOTYPES)
  ACE_OSCALL_RETURN (::execve (path, (const char **) argv, (char **) envp), int, -1);
#else
  ACE_OSCALL_RETURN (::execve (path, argv, envp), int, -1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::execvp (const char *file,
                char *const argv[])
{
  ACE_TRACE ("ACE_OS::execvp");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_execvp (file, argv), int, -1);
#elif defined (ACE_LACKS_EXEC)
  ACE_UNUSED_ARG (file);
  ACE_UNUSED_ARG (argv);

  ACE_NOTSUP_RETURN (-1);
#elif defined(CHORUS)
  KnCap cactorcap;
  int result = ::afexecvp (file, &cactorcap, 0, argv);
  if (result != -1)
    ACE_OS::actorcaps_[result] = cactorcap;
  return result;
#elif defined (ACE_WIN32)
# if defined (__BORLANDC__) /* VSB */
  return ::execvp (file, argv);
# else
  return ::_execvp (file, (const char *const *) argv);
# endif /* __BORLANDC__ */
#elif defined (ACE_LACKS_POSIX_PROTOTYPES)
  ACE_OSCALL_RETURN (::execvp (file, (const char **) argv), int, -1);
#else
  ACE_OSCALL_RETURN (::execvp (file, argv), int, -1);
#endif /* ACE_HAS_PACE */
}

#if !defined (ACE_HAS_WINCE)
ACE_INLINE FILE *
ACE_OS::fdopen (ACE_HANDLE handle, const ACE_TCHAR *mode)
{
  ACE_TRACE ("ACE_OS::fdopen");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_fdopen (handle, mode), FILE*, 0);
# elif defined (ACE_WIN32)
  // kernel file handle -> FILE* conversion...
  // Options: _O_APPEND, _O_RDONLY and _O_TEXT are lost

  FILE *file = 0;

  int crt_handle = ::_open_osfhandle ((long) handle, 0);

  if (crt_handle != -1)
    {
#   if defined(__BORLANDC__) /* VSB */
      file = ::_fdopen (crt_handle, (char *) mode);
#   elif defined (ACE_USES_WCHAR)
      file = ::_wfdopen (crt_handle, mode);
#   else
      file = ::_fdopen (crt_handle, mode);
#   endif /* __BORLANDC__ */

      if (!file)
        {
#   if (defined(__BORLANDC__) && __BORLANDC__ >= 0x0530)
          ::_rtl_close (crt_handle);
#   else
          ::_close (crt_handle);
#   endif /* (defined(__BORLANDC__) && __BORLANDC__ >= 0x0530) */
        }
    }

  return file;
# elif defined (ACE_PSOS)
  // @@ it may be possible to implement this for pSOS,
  // but it isn't obvious how to do this (perhaps via
  // f_stat to glean the default volume, and then open_fn ?)
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (mode);
  ACE_NOTSUP_RETURN (0);
# else
  ACE_OSCALL_RETURN (::fdopen (handle, mode), FILE *, 0);
# endif /* ACE_HAS_PACE */
}
#endif /* ! ACE_HAS_WINCE */

ACE_INLINE int
ACE_OS::getrlimit (int resource, struct rlimit *rl)
{
  ACE_TRACE ("ACE_OS::getrlimit");

#if defined (ACE_LACKS_RLIMIT)
  ACE_UNUSED_ARG (resource);
  ACE_UNUSED_ARG (rl);

  ACE_NOTSUP_RETURN (-1);
#else
# if defined (ACE_HAS_RLIMIT_RESOURCE_ENUM)
  ACE_OSCALL_RETURN (::getrlimit ((ACE_HAS_RLIMIT_RESOURCE_ENUM) resource, rl), int, -1);
# else
  ACE_OSCALL_RETURN (::getrlimit (resource, rl), int, -1);
# endif /* ACE_HAS_RLIMIT_RESOURCE_ENUM */
#endif /* ACE_LACKS_RLIMIT */
}

ACE_INLINE int
ACE_OS::setrlimit (int resource, ACE_SETRLIMIT_TYPE *rl)
{
  ACE_TRACE ("ACE_OS::setrlimit");

#if defined (ACE_LACKS_RLIMIT)
  ACE_UNUSED_ARG (resource);
  ACE_UNUSED_ARG (rl);

  ACE_NOTSUP_RETURN (-1);
#else
# if defined (ACE_HAS_RLIMIT_RESOURCE_ENUM)
  ACE_OSCALL_RETURN (::setrlimit ((ACE_HAS_RLIMIT_RESOURCE_ENUM) resource, rl), int, -1);
# else
  ACE_OSCALL_RETURN (::setrlimit (resource, rl), int, -1);
# endif /* ACE_HAS_RLIMIT_RESOURCE_ENUM */
#endif /* ACE_LACKS_RLIMIT */
}

ACE_INLINE int
ACE_OS::socketpair (int domain, int type,
                    int protocol, ACE_HANDLE sv[2])
{
  ACE_TRACE ("ACE_OS::socketpair");
#if defined (ACE_WIN32) || defined (ACE_LACKS_SOCKETPAIR)
  ACE_UNUSED_ARG (domain);
  ACE_UNUSED_ARG (type);
  ACE_UNUSED_ARG (protocol);
  ACE_UNUSED_ARG (sv);

  ACE_NOTSUP_RETURN (-1);
#else
  ACE_OSCALL_RETURN (::socketpair (domain, type, protocol, sv),
                     int, -1);
#endif /* ACE_WIN32 */
}

ACE_INLINE ACE_HANDLE
ACE_OS::dup (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_OS::dup");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_dup (handle), ACE_HANDLE, ACE_INVALID_HANDLE);
#elif defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)
  ACE_HANDLE new_fd;
  if (::DuplicateHandle(::GetCurrentProcess (),
                        handle,
                        ::GetCurrentProcess(),
                        &new_fd,
                        0,
                        TRUE,
                        DUPLICATE_SAME_ACCESS))
    return new_fd;
  else
    ACE_FAIL_RETURN (ACE_INVALID_HANDLE);
  /* NOTREACHED */
#elif defined (VXWORKS) || defined (ACE_PSOS)
  ACE_UNUSED_ARG (handle);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_HAS_WINCE)
  ACE_UNUSED_ARG (handle);
  ACE_NOTSUP_RETURN (0);
#else
  ACE_OSCALL_RETURN (::dup (handle), ACE_HANDLE, ACE_INVALID_HANDLE);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::dup2 (ACE_HANDLE oldhandle, ACE_HANDLE newhandle)
{
  ACE_TRACE ("ACE_OS::dup2");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_dup2 (oldhandle, newhandle), int, -1);
#elif defined (ACE_WIN32) || defined (VXWORKS) || defined (ACE_PSOS)
  // msvcrt has _dup2 ?!
  ACE_UNUSED_ARG (oldhandle);
  ACE_UNUSED_ARG (newhandle);

  ACE_NOTSUP_RETURN (-1);
#else
  ACE_OSCALL_RETURN (::dup2 (oldhandle, newhandle), int, -1);
#endif /* ACE_HAS_PACE */
}

#if defined (ghs) && defined (ACE_HAS_PENTIUM)
  extern "C" ACE_hrtime_t ACE_gethrtime ();
#endif /* ghs && ACE_HAS_PENTIUM */

ACE_INLINE ACE_hrtime_t
ACE_OS::gethrtime (const ACE_HRTimer_Op op)
{
  ACE_TRACE ("ACE_OS::gethrtime");
#if defined (ACE_HAS_HI_RES_TIMER)
  ACE_UNUSED_ARG (op);
  return ::gethrtime ();
#elif defined (ACE_HAS_AIX_HI_RES_TIMER)
  ACE_UNUSED_ARG (op);
  timebasestruct_t tb;

  ::read_real_time(&tb, TIMEBASE_SZ);
  ::time_base_to_time(&tb, TIMEBASE_SZ);

  return ACE_hrtime_t(tb.tb_high) * ACE_ONE_SECOND_IN_NSECS + tb.tb_low;
#elif defined (ghs) && defined (ACE_HAS_PENTIUM)
  ACE_UNUSED_ARG (op);
  // Use .obj/gethrtime.o, which was compiled with g++.
  return ACE_gethrtime ();
#elif defined (__GNUG__) && defined (ACE_HAS_PENTIUM)
  ACE_UNUSED_ARG (op);

# if defined (ACE_LACKS_LONGLONG_T)
  double now;
# else  /* ! ACE_LACKS_LONGLONG_T */
  ACE_hrtime_t now;
# endif /* ! ACE_LACKS_LONGLONG_T */

  // See comments about the RDTSC Pentium instruction for the ACE_WIN32
  // version of ACE_OS::gethrtime (), below.
  //
  // Read the high-res tick counter directly into memory variable "now".
  // The A constraint signifies a 64-bit int.
  asm volatile ("rdtsc" : "=A" (now) : : "memory");

# if defined (ACE_LACKS_LONGLONG_T)
  ACE_UINT32 least, most;
  ACE_OS::memcpy (&least, &now, sizeof (ACE_UINT32));
  ACE_OS::memcpy (&most, (u_char *) &now + sizeof (ACE_UINT32),
                  sizeof (ACE_UINT32));

  ACE_hrtime_t ret (least, most);
  return ret;
# else  /* ! ACE_LACKS_LONGLONG_T */
  return now;
# endif /* ! ACE_LACKS_LONGLONG_T */
#elif defined (linux) && defined (ACE_HAS_ALPHA_TIMER)
  // NOTE:  alphas only have a 32 bit tick (cycle) counter.  The rpcc
  // instruction actually reads 64 bits, but the high 32 bits are
  // implementation-specific.  Linux and Digital Unix, for example,
  // use them for virtual tick counts, i.e., taking into account only
  // the time that the process was running.  This information is from
  // David Mosberger's article, see comment below.
  ACE_UINT32 now;

  // The following statement is based on code published by:
  // Mosberger, David, "How to Make Your Applications Fly, Part 1",
  // Linux Journal Issue 42, October 1997, page 50.  It reads the
  // high-res tick counter directly into the memory variable.
  asm volatile ("rpcc %0" : "=r" (now) : : "memory");

  return now;
#elif defined (ACE_WIN32) && defined (ACE_HAS_PENTIUM)
  LARGE_INTEGER freq;

  ::QueryPerformanceCounter (&freq);

  return freq.QuadPart;

#elif defined (CHORUS)
  if (op == ACE_OS::ACE_HRTIMER_GETTIME)
    {
      struct timespec ts;

      ACE_OS::clock_gettime (CLOCK_REALTIME, &ts);

      // Carefully create the return value to avoid arithmetic overflow
      // if ACE_hrtime_t is ACE_U_LongLong.
      ACE_hrtime_t now = ts.tv_sec;
      now *= ACE_U_ONE_SECOND_IN_NSECS;
      now += ts.tv_nsec;

      return now;
    }
  else
    {
      // Use the sysBench timer on Chorus.  On MVME177, at least, it only
      // has 32 bits.  Be careful, because using it disables interrupts!
      ACE_UINT32 now;
      if (::sysBench (op, (int *) &now) == K_OK)
        {
          now *= 1000u /* nanoseconds/microsecond */;
          return (ACE_hrtime_t) now;
        }
      else
        {
          // Something went wrong.  Just return 0.
          return (ACE_hrtime_t) 0;
        }
    }

#elif defined (ACE_HAS_POWERPC_TIMER) && (defined (ghs) || defined (__GNUG__))
  // PowerPC w/ GreenHills or g++.

  ACE_UNUSED_ARG (op);
  u_long most;
  u_long least;
  ACE_OS::readPPCTimeBase (most, least);
#if defined (ACE_LACKS_LONGLONG_T)
  return ACE_U_LongLong (least, most);
#else  /* ! ACE_LACKS_LONGLONG_T */
  return 0x100000000llu * most  +  least;
#endif /* ! ACE_LACKS_LONGLONG_T */

#elif defined (ACE_HAS_CLOCK_GETTIME) || defined (ACE_PSOS)
  // e.g., VxWorks (besides POWERPC && GreenHills) . . .
  ACE_UNUSED_ARG (op);
  struct timespec ts;

  ACE_OS::clock_gettime (CLOCK_REALTIME, &ts);

  // Carefully create the return value to avoid arithmetic overflow
  // if ACE_hrtime_t is ACE_U_LongLong.
  return ACE_static_cast (ACE_hrtime_t, ts.tv_sec) *
    ACE_U_ONE_SECOND_IN_NSECS  +  ACE_static_cast (ACE_hrtime_t, ts.tv_nsec);
#else
  ACE_UNUSED_ARG (op);
  const ACE_Time_Value now = ACE_OS::gettimeofday ();

  // Carefully create the return value to avoid arithmetic overflow
  // if ACE_hrtime_t is ACE_U_LongLong.
  return (ACE_static_cast (ACE_hrtime_t, now.sec ()) * (ACE_UINT32) 1000000  +
          ACE_static_cast (ACE_hrtime_t, now.usec ())) * (ACE_UINT32) 1000;
#endif /* ACE_HAS_HI_RES_TIMER */
}

ACE_INLINE int
ACE_OS::fdetach (const char *file)
{
  ACE_TRACE ("ACE_OS::fdetach");
#if defined (ACE_HAS_STREAM_PIPES)
  ACE_OSCALL_RETURN (::fdetach (file), int, -1);
#else
  ACE_UNUSED_ARG (file);

  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_STREAM_PIPES */
}

ACE_INLINE int
ACE_OS::fattach (int handle, const char *path)
{
  ACE_TRACE ("ACE_OS::fattach");
#if defined (ACE_HAS_STREAM_PIPES)
  ACE_OSCALL_RETURN (::fattach (handle, path), int, -1);
#else
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (path);

  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_STREAM_PIPES */
}

ACE_INLINE pid_t
ACE_OS::fork (void)
{
  ACE_TRACE ("ACE_OS::fork");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_fork (), pid_t, -1);
#elif defined (ACE_LACKS_FORK)
  ACE_NOTSUP_RETURN (pid_t (-1));
#else
  ACE_OSCALL_RETURN (::fork (), pid_t, -1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::getpagesize (void)
{
  ACE_TRACE ("ACE_OS::getpagesize");
#if defined (ACE_WIN32) && !defined (ACE_HAS_PHARLAP)
  SYSTEM_INFO sys_info;
  ::GetSystemInfo (&sys_info);
  return (int) sys_info.dwPageSize;
#elif defined (_SC_PAGESIZE)
  return (int) ::sysconf (_SC_PAGESIZE);
#elif defined (ACE_HAS_GETPAGESIZE)
  return ::getpagesize ();
#else
  // Use the default set in config.h
  return ACE_PAGE_SIZE;
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::allocation_granularity (void)
{
#if defined (ACE_WIN32)
  SYSTEM_INFO sys_info;
  ::GetSystemInfo (&sys_info);
  return (int) sys_info.dwAllocationGranularity;
#else
  return ACE_OS::getpagesize ();
#endif /* ACE_WIN32 */
}

ACE_INLINE pid_t
ACE_OS::getpid (void)
{
  // ACE_TRACE ("ACE_OS::getpid");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_getpid (), int , -1);
#elif defined (ACE_WIN32)
  return ::GetCurrentProcessId ();
#elif defined (VXWORKS) || defined (ACE_PSOS)
  // getpid() is not supported:  just one process anyways
  return 0;
#elif defined (CHORUS)
  return (pid_t) (::agetId ());
#else
  ACE_OSCALL_RETURN (::getpid (), int, -1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE pid_t
ACE_OS::getpgid (pid_t pid)
{
  ACE_TRACE ("ACE_OS::getpgid");
#if defined (ACE_LACKS_GETPGID)
  ACE_UNUSED_ARG (pid);
  ACE_NOTSUP_RETURN (-1);
#elif defined (VXWORKS) || defined (ACE_PSOS)
  // getpgid() is not supported, only one process anyway.
  ACE_UNUSED_ARG (pid);
  return 0;
#elif defined (linux) && __GLIBC__ > 1 && __GLIBC_MINOR__ >= 0
  // getpgid() is from SVR4, which appears to be the reason why GLIBC
  // doesn't enable its prototype by default.
  // Rather than create our own extern prototype, just use the one
  // that is visible (ugh).
  ACE_OSCALL_RETURN (::__getpgid (pid), pid_t, -1);
#else
  ACE_OSCALL_RETURN (::getpgid (pid), pid_t, -1);
#endif /* ACE_WIN32 */
}

ACE_INLINE pid_t
ACE_OS::getppid (void)
{
  ACE_TRACE ("ACE_OS::getppid");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_getppid (), pid_t, -1);
#elif defined (ACE_LACKS_GETPPID)
  ACE_NOTSUP_RETURN (-1);
#elif defined (VXWORKS) || defined (ACE_PSOS)
  // getppid() is not supported, only one process anyway.
  return 0;
#else
  ACE_OSCALL_RETURN (::getppid (), pid_t, -1);
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::setpgid (pid_t pid, pid_t pgid)
{
  ACE_TRACE ("ACE_OS::setpgid");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_setpgid (pid, pgid), int, -1);
#elif defined (ACE_LACKS_SETPGID)
  ACE_UNUSED_ARG (pid);
  ACE_UNUSED_ARG (pgid);
  ACE_NOTSUP_RETURN (-1);
#elif defined (VXWORKS) || defined (ACE_PSOS)
  // <setpgid> is not supported, only one process anyway.
  ACE_UNUSED_ARG (pid);
  ACE_UNUSED_ARG (pgid);
  return 0;
#else
  ACE_OSCALL_RETURN (::setpgid (pid, pgid), int, -1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::setreuid (uid_t ruid, uid_t euid)
{
  ACE_TRACE ("ACE_OS::setreuid");
#if defined (ACE_LACKS_SETREUID)
  ACE_UNUSED_ARG (ruid);
  ACE_UNUSED_ARG (euid);
  ACE_NOTSUP_RETURN (-1);
#elif defined (VXWORKS) || defined (ACE_PSOS)
  // <setpgid> is not supported, only one process anyway.
  ACE_UNUSED_ARG (ruid);
  ACE_UNUSED_ARG (euid);
  return 0;
#else
  ACE_OSCALL_RETURN (::setreuid (ruid, euid), int, -1);
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::setregid (gid_t rgid, gid_t egid)
{
  ACE_TRACE ("ACE_OS::setregid");
#if defined (ACE_LACKS_SETREGID)
  ACE_UNUSED_ARG (rgid);
  ACE_UNUSED_ARG (egid);
  ACE_NOTSUP_RETURN (-1);
#elif defined (VXWORKS) || defined (ACE_PSOS)
  // <setregid> is not supported, only one process anyway.
  ACE_UNUSED_ARG (rgid);
  ACE_UNUSED_ARG (egid);
  return 0;
#else
  ACE_OSCALL_RETURN (::setregid (rgid, egid), int, -1);
#endif /* ACE_WIN32 */
}

ACE_INLINE off_t
ACE_OS::lseek (ACE_HANDLE handle, off_t offset, int whence)
{
  ACE_TRACE ("ACE_OS::lseek");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_lseek (handle, offset, whence), pace_off_t, -1);
#elif defined (ACE_WIN32)
# if SEEK_SET != FILE_BEGIN || SEEK_CUR != FILE_CURRENT || SEEK_END != FILE_END
  //#error Windows NT is evil AND rude!
  switch (whence)
    {
    case SEEK_SET:
      whence = FILE_BEGIN;
      break;
    case SEEK_CUR:
      whence = FILE_CURRENT;
      break;
    case SEEK_END:
      whence = FILE_END;
      break;
    default:
      errno = EINVAL;
      return ACE_static_cast (off_t, -1); // rather safe than sorry
    }
# endif  /* SEEK_SET != FILE_BEGIN || SEEK_CUR != FILE_CURRENT || SEEK_END != FILE_END */
  DWORD result = ::SetFilePointer (handle, offset, NULL, whence);
  if (result == ACE_SYSCALL_FAILED)
    ACE_FAIL_RETURN (ACE_static_cast (off_t, -1));
  else
    return result;
#elif defined (ACE_PSOS)
# if defined (ACE_PSOS_LACKS_PHILE)
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (offset);
  ACE_UNUSED_ARG (whence);
  ACE_NOTSUP_RETURN (ACE_static_cast (off_t, -1));
# else
  unsigned long oldptr, newptr, result;
  // seek to the requested position
  result = ::lseek_f (handle, whence, offset, &oldptr);
  if (result != 0)
    {
      errno = result;
      return ACE_static_cast (off_t, -1);
    }
  // now do a dummy seek to the current position to obtain the position
  result = ::lseek_f (handle, SEEK_CUR, 0, &newptr);
  if (result != 0)
    {
      errno = result;
      return ACE_static_cast (off_t, -1);
    }
  return ACE_static_cast (off_t, newptr);
# endif /* defined (ACE_PSOS_LACKS_PHILE */
#else
  ACE_OSCALL_RETURN (::lseek (handle, offset, whence), off_t, -1);
#endif /* ACE_HAS_PACE */
}

#if defined (ACE_HAS_LLSEEK) || defined (ACE_HAS_LSEEK64)
ACE_INLINE ACE_LOFF_T
ACE_OS::llseek (ACE_HANDLE handle, ACE_LOFF_T offset, int whence)
{
  ACE_TRACE ("ACE_OS::llseek");

#if ACE_SIZEOF_LONG == 8
  /* The native lseek is 64 bit.  Use it. */
  return ACE_OS::lseek (handle, offset, whence);
#elif defined (ACE_HAS_LLSEEK) && defined (ACE_HAS_LSEEK64)
# error Either ACE_HAS_LSEEK64 and ACE_HAS_LLSEEK should be defined, not both!
#elif defined (ACE_HAS_LSEEK64)
  ACE_OSCALL_RETURN (::lseek64 (handle, offset, whence), ACE_LOFF_T, -1);
#elif defined (ACE_HAS_LLSEEK)
  ACE_OSCALL_RETURN (::llseek (handle, offset, whence), ACE_LOFF_T, -1);
#endif
}
#endif /* ACE_HAS_LLSEEK || ACE_HAS_LSEEK64 */

ACE_INLINE int
ACE_OS::fseek (FILE *fp, long offset, int whence)
{
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_fseek (fp, offset, whence), int, -1);
#elif defined (ACE_HAS_WINCE)
  return ACE_OS::lseek (fp, offset, whence);
#else /* ACE_HAS_WINCE */
# if defined (ACE_WIN32)
#   if SEEK_SET != FILE_BEGIN || SEEK_CUR != FILE_CURRENT || SEEK_END != FILE_END
  //#error Windows NT is evil AND rude!
  switch (whence)
    {
    case SEEK_SET:
      whence = FILE_BEGIN;
      break;
    case SEEK_CUR:
      whence = FILE_CURRENT;
      break;
    case SEEK_END:
      whence = FILE_END;
      break;
    default:
      errno = EINVAL;
      return -1; // rather safe than sorry
    }
#   endif  /* SEEK_SET != FILE_BEGIN || SEEK_CUR != FILE_CURRENT || SEEK_END != FILE_END */
# endif   /* ACE_WIN32 */
  ACE_OSCALL_RETURN (::fseek (fp, offset, whence), int, -1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE pid_t
ACE_OS::waitpid (pid_t pid,
                 ACE_exitcode *status,
                 int wait_options,
                 ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_OS::waitpid");
#if defined (ACE_HAS_PACE)
  ACE_UNUSED_ARG (handle);
  ACE_OSCALL_RETURN (pace_waitpid (pid, status, wait_options), int, -1);
#elif defined (VXWORKS) || defined (ACE_PSOS)
  ACE_UNUSED_ARG (pid);
  ACE_UNUSED_ARG (status);
  ACE_UNUSED_ARG (wait_options);
  ACE_UNUSED_ARG (handle);

  ACE_NOTSUP_RETURN (0);
#elif defined (ACE_WIN32)
  int blocking_period = ACE_BIT_ENABLED (wait_options, WNOHANG)
    ? 0 /* don't hang */
    : INFINITE;

  ACE_HANDLE phandle = handle;

  if (phandle == 0)
    {
      phandle = ::OpenProcess (SYNCHRONIZE,
                               FALSE,
                               pid);

      if (phandle == 0)
        {
          ACE_OS::set_errno_to_last_error ();
          return -1;
        }
    }

  pid_t result = pid;

  // Don't try to get the process exit status if wait failed so we can
  // keep the original error code intact.
  switch (::WaitForSingleObject (phandle,
                                 blocking_period))
    {
    case WAIT_OBJECT_0:
      if (status != 0)
        // The error status of <GetExitCodeProcess> is nonetheless
        // not tested because we don't know how to return the value.
        ::GetExitCodeProcess (phandle,
                              status);
      break;
    case WAIT_TIMEOUT:
      errno = ETIME;
      result = 0;
      break;
    default:
      ACE_OS::set_errno_to_last_error ();
      result = -1;
    }
  if (handle == 0)
    ::CloseHandle (phandle);
  return result;
#elif defined (CHORUS)
  ACE_UNUSED_ARG (status);
  ACE_UNUSED_ARG (wait_options);
  ACE_UNUSED_ARG (handle);
  ACE_OSCALL_RETURN (::await (&ACE_OS::actorcaps_[pid]),
                     pid_t, -1);
#else
  ACE_UNUSED_ARG (handle);
  ACE_OSCALL_RETURN (::waitpid (pid, status, wait_options),
                     pid_t, -1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE pid_t
ACE_OS::wait (pid_t pid,
              ACE_exitcode *status,
              int wait_options,
              ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_OS::wait");
  return ACE_OS::waitpid (pid,
                          status,
                          wait_options,
                          handle);
}

ACE_INLINE pid_t
ACE_OS::wait (int *status)
{
  ACE_TRACE ("ACE_OS::wait");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_wait (status), pace_pid_t, -1);
#elif defined (ACE_WIN32) || defined (VXWORKS) || defined(CHORUS) || defined (ACE_PSOS)
  ACE_UNUSED_ARG (status);

  ACE_NOTSUP_RETURN (0);
#else
# if defined (ACE_HAS_UNION_WAIT)
  ACE_OSCALL_RETURN (::wait ((union wait *) status), pid_t, -1);
# else
  ACE_OSCALL_RETURN (::wait (status), pid_t, -1);
# endif /* ACE_HAS_UNION_WAIT */
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::ioctl (ACE_HANDLE handle,
               int cmd,
               void *val)
{
  ACE_TRACE ("ACE_OS::ioctl");

#if defined (ACE_WIN32)
  ACE_SOCKET sock = (ACE_SOCKET) handle;
  ACE_SOCKCALL_RETURN (::ioctlsocket (sock, cmd, (u_long *) val), int, -1);
#elif defined (VXWORKS)
  ACE_OSCALL_RETURN (::ioctl (handle, cmd, ACE_reinterpret_cast (int, val)),
                     int, -1);
#elif defined (ACE_PSOS)
  ACE_OSCALL_RETURN (::ioctl (handle, cmd, (char *) val), int, -1);
#elif defined (__CYGWIN32__)
  ACE_UNUSED_ARG (handle);
   ACE_UNUSED_ARG (cmd);
   ACE_UNUSED_ARG (val);
   ACE_NOTSUP_RETURN (-1);
#else
  ACE_OSCALL_RETURN (::ioctl (handle, cmd, val), int, -1);
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::kill (pid_t pid, int signum)
{
  ACE_TRACE ("ACE_OS::kill");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_kill (pid, signum), int, -1);
#elif defined (ACE_WIN32) || defined (CHORUS) || defined (ACE_PSOS)
  ACE_UNUSED_ARG (pid);
  ACE_UNUSED_ARG (signum);
  ACE_NOTSUP_RETURN (-1);
#else
  ACE_OSCALL_RETURN (::kill (pid, signum), int, -1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::sigaction (int signum,
                   const struct sigaction *nsa,
                   struct sigaction *osa)
{
  ACE_TRACE ("ACE_OS::sigaction");
  if (signum == 0)
    return 0;
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (sigaction (signum, nsa, osa), int, -1);
#elif defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)
  struct sigaction sa;

  if (osa == 0)
    osa = &sa;

  if (nsa == 0)
    {
      osa->sa_handler = ::signal (signum, SIG_IGN);
      ::signal (signum, osa->sa_handler);
    }
  else
    osa->sa_handler = ::signal (signum, nsa->sa_handler);
  return osa->sa_handler == SIG_ERR ? -1 : 0;
#elif defined (CHORUS) || defined (ACE_HAS_WINCE) || defined(ACE_PSOS)
  ACE_UNUSED_ARG (signum);
  ACE_UNUSED_ARG (nsa);
  ACE_UNUSED_ARG (osa);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_LACKS_POSIX_PROTOTYPES) || defined (ACE_LACKS_SOME_POSIX_PROTOTYPES)
  ACE_OSCALL_RETURN (::sigaction (signum, (struct sigaction*) nsa, osa), int, -1);
#else
  ACE_OSCALL_RETURN (::sigaction (signum, nsa, osa), int, -1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE ACE_TCHAR *
ACE_OS::getcwd (ACE_TCHAR *buf, size_t size)
{
  ACE_TRACE ("ACE_OS::getcwd");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_getcwd (buf, size), char*, 0);
#elif defined (ACE_PSOS_LACKS_PHILE)
  ACE_UNUSED_ARG (buf);
  ACE_UNUSED_ARG (size);
  ACE_NOTSUP_RETURN ( (char*)-1);
#elif defined (ACE_PSOS)

  static char pathbuf [BUFSIZ];

  // blank the path buffer
  ACE_OS::memset (pathbuf, '\0', BUFSIZ);

  // the following was suggested in the documentation for get_fn ()
  u_long result;
  char cur_dir_name [BUFSIZ] = ".";

  u_long cur_dir = 0, prev_dir = 0;
  while ((ACE_OS::strlen (pathbuf) < BUFSIZ) &&
         (ACE_OS::strlen (cur_dir_name) < BUFSIZ - ACE_OS::strlen ("/..")))
  {
    // get the current directory handle
    result = ::get_fn (cur_dir_name, &cur_dir);

    // check whether we're at the root: this test is
    // really lame, but the get_fn documentation says
    // *either* condition indicates you're trying to
    // move above the root.
    if ((result != 0) || ( cur_dir == prev_dir))
    {
      break;
    }

    // change name to the parent directory
    ACE_OS::strcat (cur_dir_name, "/..");

    // open the parent directory
    XDIR xdir;
    result = ::open_dir (cur_dir_name, &xdir);
    if (result != 0)
    {
      return 0;
    }

    // look for an entry that matches the current directory handle
    struct dirent dir_entry;
    while (1)
    {
      // get the next directory entry
      result = ::read_dir (&xdir, &dir_entry);
      if (result != 0)
      {
        return 0;
      }

      // check for a match
      if (dir_entry.d_filno == cur_dir)
      {
        // prefix the previous path with the entry's name and break
        if (ACE_OS::strlen (pathbuf) + ACE_OS::strlen (dir_entry.d_name) < BUFSIZ)
        {
          ACE_OS::strcpy (pathbuf + ACE_OS::strlen (dir_entry.d_name), pathbuf);
          ACE_OS::strcpy (pathbuf, dir_entry.d_name);
          break;
        }
        else
        {
          // we're out of room in the buffer
          return 0;
        }
      }
    }

    // close the parent directory
    result = ::close_dir (&xdir);
    if (result != 0)
    {
      return 0;
    }

    // save the current directory handle as the previous
    prev_dir =  cur_dir;
  }

  // return the path, if there is one
  return (ACE_OS::strlen (pathbuf) > 0) ? pathbuf : (char *) 0;
#elif defined (ACE_HAS_WINCE)
  ACE_UNUSED_ARG (buf);
  ACE_UNUSED_ARG (size);
  ACE_NOTSUP_RETURN (0);
#elif defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
  return ::_wgetcwd (buf, size);
#else
  ACE_OSCALL_RETURN (::getcwd (buf, size), char *, 0);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::sleep (u_int seconds)
{
  ACE_TRACE ("ACE_OS::sleep");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_sleep (seconds), int, -1);
#elif defined (ACE_WIN32)
  ::Sleep (seconds * ACE_ONE_SECOND_IN_MSECS);
  return 0;
#if 0
#elif defined (HPUX_10) && defined (ACE_HAS_PTHREADS_DRAFT4)
  // On HP-UX 10, _CMA_NOWRAPPERS_ disables the mapping from sleep to cma_sleep
  // which makes sleep() put the whole process to sleep, and keeps it from
  // noticing pending cancels.  So, in this case, use pthread_delay_np
  struct timespec rqtp;
  rqtp.tv_sec = seconds;
  rqtp.tv_nsec = 0L;
  return pthread_delay_np (&rqtp);
#endif /* 0 */
#elif defined (ACE_HAS_CLOCK_GETTIME)
  struct timespec rqtp;
  // Initializer doesn't work with Green Hills 1.8.7
  rqtp.tv_sec = seconds;
  rqtp.tv_nsec = 0L;
  ACE_OSCALL_RETURN (::nanosleep (&rqtp, 0), int, -1);
#elif defined (ACE_PSOS)
  timeval wait;
  wait.tv_sec = seconds;
  wait.tv_usec = 0;
  ACE_OSCALL_RETURN (::select (0, 0, 0, 0, &wait), int, -1);
#else
  ACE_OSCALL_RETURN (::sleep (seconds), int, -1);
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::sleep (const ACE_Time_Value &tv)
{
  ACE_TRACE ("ACE_OS::sleep");
#if defined (ACE_WIN32)
  ::Sleep (tv.msec ());
  return 0;
#else
# if defined (ACE_HAS_NONCONST_SELECT_TIMEVAL)
  // Copy the timeval, because this platform doesn't declare the timeval
  // as a pointer to const.
  timeval tv_copy = tv;
  ACE_OSCALL_RETURN (::select (0, 0, 0, 0, &tv_copy), int, -1);
# else  /* ! ACE_HAS_NONCONST_SELECT_TIMEVAL */
  const timeval *tvp = tv;
  ACE_OSCALL_RETURN (::select (0, 0, 0, 0, tvp), int, -1);
# endif /* ACE_HAS_NONCONST_SELECT_TIMEVAL */
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::nanosleep (const struct timespec *requested,
                   struct timespec *remaining)
{
  ACE_TRACE ("ACE_OS::nanosleep");
#if defined (ACE_HAS_PACE)
  return pace_nanosleep (requested, remaining);
#elif defined (ACE_HAS_CLOCK_GETTIME)
  // ::nanosleep () is POSIX 1003.1b.  So is ::clock_gettime ().  So,
  // if ACE_HAS_CLOCK_GETTIME is defined, then ::nanosleep () should
  // be available on the platform.  On Solaris 2.x, both functions
  // require linking with -lposix4.
  return ::nanosleep ((ACE_TIMESPEC_PTR) requested, remaining);
#elif defined (ACE_PSOS)
#  if ! defined (ACE_PSOS_DIAB_MIPS)
  double ticks = KC_TICKS2SEC * requested->tv_sec +
                 ( ACE_static_cast (double, requested->tv_nsec) *
                   ACE_static_cast (double, KC_TICKS2SEC) ) /
                 ACE_static_cast (double, ACE_ONE_SECOND_IN_NSECS);

  if (ticks > ACE_static_cast (double, ACE_PSOS_Time_t::max_ticks))
  {
    ticks -= ACE_static_cast (double, ACE_PSOS_Time_t::max_ticks);
    remaining->tv_sec = ACE_static_cast (time_t,
                                         (ticks /
                                          ACE_static_cast (double,
                                                           KC_TICKS2SEC)));
    ticks -= ACE_static_cast (double, remaining->tv_sec) *
             ACE_static_cast (double, KC_TICKS2SEC);

    remaining->tv_nsec =
      ACE_static_cast (long,
                       (ticks * ACE_static_cast (double,
                                                 ACE_ONE_SECOND_IN_NSECS)) /
                       ACE_static_cast (double, KC_TICKS2SEC));

    ::tm_wkafter (ACE_PSOS_Time_t::max_ticks);
  }
  else
  {
    remaining->tv_sec = 0;
    remaining->tv_nsec = 0;
    ::tm_wkafter (ACE_static_cast (u_long, ticks));
  }

  // tm_wkafter always returns 0
#  endif /* ACE_PSOS_DIAB_MIPS */
  return 0;
#else
  ACE_UNUSED_ARG (remaining);

  // Convert into seconds and microseconds.
# if ! defined(ACE_HAS_BROKEN_TIMESPEC_MEMBERS)
  ACE_Time_Value tv (requested->tv_sec,
                     requested->tv_nsec / 1000);
# else
  ACE_Time_Value tv (requested->ts_sec,
                     requested->ts_nsec / 1000);
# endif /* ACE_HAS_BROKEN_TIMESPEC_MEMBERS */
  return ACE_OS::sleep (tv);
#endif /* ACE_HAS_CLOCK_GETTIME */
}

ACE_INLINE int
ACE_OS::mkdir (const ACE_TCHAR *path, mode_t mode)
{
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_mkdir (path, mode), int, -1);
#elif defined (ACE_PSOS_LACKS_PHILE)
  ACE_UNUSED_ARG (path);
  ACE_UNUSED_ARG (mode);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_PSOS)
  //The pSOS make_dir fails if the last character is a '/'
  int location;
  char *phile_path;

  phile_path = (char *)ACE_OS::malloc(strlen(path));
  if (phile_path == 0)
    {
      ACE_OS::printf ("malloc in make_dir failed: [%X]\n",
                      errno);
      return -1;
    }
  else
    ACE_OS::strcpy (phile_path, path);

  location = ACE_OS::strlen(phile_path);
  if(phile_path[location-1] == '/')
  {
     phile_path[location-1] = 0;
  }

  u_long result;
  result = ::make_dir ((char *) phile_path, mode);
  if (result == 0x2011)  // Directory already exists
    {
      result = 0;
    }
  else if (result != 0)
    {
      result = -1;
    }

  ACE_OS::free(phile_path);
  return result;

#elif defined (VXWORKS)
  ACE_UNUSED_ARG (mode);
  ACE_OSCALL_RETURN (::mkdir ((char *) path), int, -1);
#elif defined (ACE_WIN32) && defined (__IBMCPP__) && (__IBMCPP__ >= 400)
  ACE_UNUSED_ARG (mode);
  ACE_OSCALL_RETURN (::_mkdir ((char *) path), int, -1);
#elif defined (ACE_HAS_WINCE)
  ACE_UNUSED_ARG (mode);
  ACE_WIN32CALL_RETURN (ACE_ADAPT_RETVAL (::CreateDirectory (path, NULL),
                                          ace_result_),
                        int, -1);
#elif defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
  ACE_OSCALL_RETURN (::_wmkdir (path), int, -1);
#elif defined (ACE_WIN32)
  ACE_OSCALL_RETURN (::mkdir (path), int, -1);
#else
  ACE_OSCALL_RETURN (::mkdir (path, mode), int, -1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE ACE_TCHAR *
ACE_OS::getenv (const ACE_TCHAR *symbol)
{
  ACE_TRACE ("ACE_OS::getenv");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_getenv (symbol), char*, 0);
#elif defined (ACE_HAS_WINCE) || defined (ACE_PSOS)
  ACE_UNUSED_ARG (symbol);
  ACE_NOTSUP_RETURN (0);
#elif defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
  ACE_OSCALL_RETURN (::_wgetenv (symbol), ACE_TCHAR *, 0);
#else /* ACE_HAS_WINCE || ACE_PSOS */
  ACE_OSCALL_RETURN (::getenv (symbol), char *, 0);
#endif /* symbol */
}

ACE_INLINE int
ACE_OS::putenv (const ACE_TCHAR *string)
{
  ACE_TRACE ("ACE_OS::putenv");
#if defined (ACE_HAS_WINCE) || defined (ACE_PSOS)
  // WinCE and pSOS don't have the concept of environment variables.
  ACE_UNUSED_ARG (string);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
  ACE_OSCALL_RETURN (::_wputenv (string), int, -1);
#else /* ! ACE_HAS_WINCE && ! ACE_PSOS */
  // VxWorks declares ::putenv with a non-const arg.
  ACE_OSCALL_RETURN (::putenv ((char *) string), int, -1);
#endif /* ACE_HAS_WINCE */
}

ACE_INLINE
ACE_Str_Buf::ACE_Str_Buf (void *b, int l, int max)
{
  this->maxlen = max;
  this->len = l;
  this->buf = (char *) b;
}

ACE_INLINE
ACE_Str_Buf::ACE_Str_Buf (strbuf &sb)
{
  this->maxlen = sb.maxlen;
  this->len = sb.len;
  this->buf = sb.buf;
}

ACE_INLINE u_int
ACE_OS::wslen (const WChar *s)
{
  u_int len = 0;

  while (*s++ != 0)
    len++;

  return len;
}

ACE_INLINE ACE_OS::WChar *
ACE_OS::wscpy (WChar *dest, const WChar *src)
{
  WChar *original_dest = dest;

  while ((*dest++ = *src++) != 0)
    continue;

  return original_dest;
}

ACE_INLINE int
ACE_OS::wscmp (const WChar *s, const WChar *t)
{
  const WChar *scan1 = s;
  const WChar *scan2 = t;

  while (*scan1 != 0 && *scan1 == *scan2)
    {
      ++scan1;
      ++scan2;
    }

  return *scan1 - *scan2;
}

ACE_INLINE int
ACE_OS::wsncmp (const WChar *s, const WChar *t, size_t len)
{
  const WChar *scan1 = s;
  const WChar *scan2 = t;

  while (len != 0 && *scan1 != 0 && *scan1 == *scan2)
    {
      ++scan1;
      ++scan2;
      --len;
    }

  return len == 0 ? 0 : *scan1 - *scan2;
}

#if defined (ACE_LACKS_COND_T) && defined (ACE_HAS_THREADS)
ACE_INLINE long
ACE_cond_t::waiters (void) const
{
  return this->waiters_;
}
#endif /* ACE_LACKS_COND_T && ACE_HAS_THREADS */

#if 0
ACE_INLINE int
ACE_OS::thr_continue (const ACE_Thread_ID &thr_id)
{
  ACE_TRACE ("ACE_OS::thr_continue");
  return ACE_OS::thr_continue (thr_id.id ());
}

ACE_INLINE int
ACE_OS::thr_create (ACE_THR_FUNC func,
                    void *args,
                    long flags,
                    ACE_Thread_ID *thr_id,
                    long priority,
                    void *stack,
                    size_t stacksize);
{
  ACE_TRACE ("ACE_OS::thr_create");
  ACE_thread_t thread_id;
  ACE_hthread_t thread_handle;

  int result = ACE_OS::thr_create (func, args, flags,
                                   &thread_id, &thread_handle,
                                   priority, stack, stacksize);
  if (result == -1)
    return -1;
  else if (thr_id != 0)
    {
      thr_id->id (thread_id);
      thr_id->handle (thread_handle);
      return result;
    }
}

ACE_INLINE int
ACE_OS::thr_getprio (const ACE_Thread_ID &thr_id, int &prio)
{
  ACE_TRACE ("ACE_OS::thr_getprio");
  return ACE_OS::thr_getprio (thr_id.handle (), prio);
}

ACE_INLINE int
ACE_OS::thr_join (const ACE_Thread_ID &thr_id, void **status)
{
# if defined (ACE_WIN32)
  return ACE_OS::thr_join (thr_id.handle (), status);
# else
  return ACE_OS::thr_join (thr_id.id (), status);
# endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE_OS::thr_cancel (const ACE_Thread_ID &thr_id)
{
  return ACE_OS::thr_cancel (thr_id.id ());
}

ACE_INLINE int
ACE_OS::thr_kill (const ACE_Thread_ID &thr_id, int signum)
{
  return ACE_OS::thr_kill (thr_id.id (), signum);
}

ACE_INLINE ACE_Thread_ID
ACE_OS::thr_self (void)
{
  ACE_hthread_t thr_handle;
  ACE_OS::thr_self (thr_handle);
  ACE_thread_t thr_id = ACE_OS::thr_self ();

  return ACE_Thread_ID (thr_id, thr_handle);
}

ACE_INLINE int
ACE_OS::thr_setprio (const ACE_Thread_ID &thr_id, int prio)
{
  ACE_TRACE ("ACE_OS::thr_setprio");
  return ACE_OS::thr_setprio (thr_id.handle (), prio);
}

ACE_INLINE int
ACE_OS::thr_suspend (const ACE_Thread_ID &thr_id)
{
  return ACE_OS::thr_suspend (thr_id.handle ());
}

#endif /* 0 */

ACE_INLINE int
ACE_OS::sigaddset (sigset_t *s, int signum)
{
  ACE_TRACE ("ACE_OS::sigaddset");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_sigaddset (s, signum), int, -1);
#elif defined (ACE_LACKS_SIGSET) || defined (ACE_LACKS_SIGSET_DEFINITIONS)
  if (s == NULL)
    {
      errno = EFAULT;
      return -1;
    }
  else if (signum < 1 || signum >= ACE_NSIG)
    {
      errno = EINVAL;
      return -1;                 // Invalid signum, return error
    }
#   if defined (ACE_PSOS) && defined (__DIAB) && ! defined(ACE_PSOS_DIAB_MIPS) && !defined (ACE_PSOS_DIAB_PPC)
  // treat 0th u_long of sigset_t as high bits,
  // and 1st u_long of sigset_t as low bits.
  if (signum <= ACE_BITS_PER_ULONG)
    s->s[1] |= (1 << (signum - 1));
  else
    s->s[0] |= (1 << (signum - ACE_BITS_PER_ULONG - 1));
#   else
  *s |= (1 << (signum - 1)) ;
#   endif /* defined (ACE_PSOS) && defined (__DIAB) */
  return 0 ;
#else
  ACE_OSCALL_RETURN (::sigaddset (s, signum), int, -1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::sigdelset (sigset_t *s, int signum)
{
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_sigdelset (s, signum), int, -1);
#elif defined (ACE_LACKS_SIGSET) || defined (ACE_LACKS_SIGSET_DEFINITIONS)
  if (s == NULL)
    {
      errno = EFAULT;
      return -1;
    }
  else if (signum < 1 || signum >= ACE_NSIG)
    {
      errno = EINVAL;
      return -1;                 // Invalid signum, return error
    }
#   if defined (ACE_PSOS) && defined (__DIAB) && ! defined (ACE_PSOS_DIAB_MIPS) && !defined (ACE_PSOS_DIAB_PPC)
  // treat 0th u_long of sigset_t as high bits,
  // and 1st u_long of sigset_t as low bits.
  if (signum <= ACE_BITS_PER_ULONG)
    s->s[1] &= ~(1 << (signum - 1));
  else
    s->s[0] &= ~(1 << (signum - ACE_BITS_PER_ULONG - 1));
#   else
  *s &= ~(1 << (signum - 1)) ;
#   endif /* defined (ACE_PSOS) && defined (__DIAB) */
  return 0;
#else
  ACE_OSCALL_RETURN (::sigdelset (s, signum), int, -1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::sigemptyset (sigset_t *s)
{
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_sigemptyset (s), int, -1);
#elif defined (ACE_LACKS_SIGSET) || defined (ACE_LACKS_SIGSET_DEFINITIONS)
  if (s == NULL)
    {
      errno = EFAULT;
      return -1;
    }
#   if defined (ACE_PSOS) && defined (__DIAB) && ! defined (ACE_PSOS_DIAB_MIPS) && !defined (ACE_PSOS_DIAB_PPC)
  s->s[0] = 0;
  s->s[1] = 0;
#   else
  *s = 0 ;
#   endif /* defined (ACE_PSOS) && defined (__DIAB) */
  return 0 ;
#else
  ACE_OSCALL_RETURN (::sigemptyset (s), int, -1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::sigfillset (sigset_t *s)
{
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (sigfillset (s), int, -1);
#elif defined (ACE_LACKS_SIGSET) || defined (ACE_LACKS_SIGSET_DEFINITIONS)
  if (s == NULL)
    {
      errno = EFAULT;
      return -1;
    }
#   if defined (ACE_PSOS) && defined (__DIAB) && ! defined (ACE_PSOS_DIAB_MIPS) && !defined (ACE_PSOS_DIAB_PPC)
  s->s[0] = ~(u_long) 0;
  s->s[1] = ~(u_long) 0;
#   else
  *s = ~(sigset_t) 0;
#   endif /* defined (ACE_PSOS) && defined (__DIAB) */
  return 0 ;
#else
  ACE_OSCALL_RETURN (::sigfillset (s), int, -1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::sigismember (sigset_t *s, int signum)
{
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_sigismember (s, signum), int, -1);
#elif defined (ACE_LACKS_SIGSET) || defined (ACE_LACKS_SIGSET_DEFINITIONS)
  if (s == NULL)
    {
      errno = EFAULT;
      return -1;
    }
  else if (signum < 1 || signum >= ACE_NSIG)
    {
      errno = EINVAL;
      return -1;                 // Invalid signum, return error
    }
#   if defined (ACE_PSOS) && defined (__DIAB) && ! defined (ACE_PSOS_DIAB_MIPS) && !defined (ACE_PSOS_DIAB_PPC)
  // treat 0th u_long of sigset_t as high bits,
  // and 1st u_long of sigset_t as low bits.
  if (signum <= ACE_BITS_PER_ULONG)
    return ((s->s[1] & (1 << (signum - 1))) != 0);
  else
    return ((s->s[0] & (1 << (signum - ACE_BITS_PER_ULONG - 1))) != 0);
#   else
  return ((*s & (1 << (signum - 1))) != 0) ;
#   endif /* defined (ACE_PSOS) && defined (__DIAB) */
#else
#  if defined (ACE_HAS_SIGISMEMBER_BUG)
  if (signum < 1 || signum >= ACE_NSIG)
    {
      errno = EINVAL;
      return -1;                 // Invalid signum, return error
    }
#  endif /* ACE_HAS_SIGISMEMBER_BUG */
  ACE_OSCALL_RETURN (::sigismember (s, signum), int, -1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::sigsuspend (const sigset_t *sigset)
{
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_sigsuspend (sigset), int, -1);
#elif defined (ACE_HAS_SIGSUSPEND)
  sigset_t s;

  if (sigset == 0)
    {
      sigset = &s;
      ACE_OS::sigemptyset (&s);
    }
  ACE_OSCALL_RETURN (::sigsuspend (sigset), int, -1);
#else
  ACE_UNUSED_ARG (sigset);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::sigprocmask (int how, const sigset_t *nsp, sigset_t *osp)
{
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_sigprocmask (how, nsp, osp), int, -1);
#elif defined (ACE_LACKS_SIGSET) || defined (ACE_LACKS_SIGSET_DEFINITIONS)
  ACE_UNUSED_ARG (how);
  ACE_UNUSED_ARG (nsp);
  ACE_UNUSED_ARG (osp);
  ACE_NOTSUP_RETURN (-1);
#else
# if defined (ACE_LACKS_POSIX_PROTOTYPES)
  ACE_OSCALL_RETURN (::sigprocmask (how, (int*) nsp, osp), int, -1);
# else
  ACE_OSCALL_RETURN (::sigprocmask (how, nsp, osp), int, -1);
# endif /* ACE_LACKS_POSIX_PROTOTYPES */
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::pthread_sigmask (int how, const sigset_t *nsp, sigset_t *osp)
{
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (pace_pthread_sigmask (how, nsp, osp),
                                       ace_result_), int, -1);
#elif defined (ACE_HAS_PTHREADS_STD)  &&  !defined (ACE_LACKS_PTHREAD_SIGMASK)
  ACE_OSCALL_RETURN (ACE_ADAPT_RETVAL (::pthread_sigmask (how, nsp, osp),
                                       ace_result_),
                     int,
                     -1);
#else /* !ACE_HAS_PTHREADS_STD */
  ACE_UNUSED_ARG (how);
  ACE_UNUSED_ARG (nsp);
  ACE_UNUSED_ARG (osp);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE long
ACE_OS_Thread_Descriptor::flags (void) const
{
  ACE_TRACE ("ACE_OS_Thread_Descriptor::flags");
  return flags_;
}


ACE_INLINE
ACE_OS_Thread_Descriptor::ACE_OS_Thread_Descriptor (long flags)
  : flags_ (flags)
{
}

// ****************************************************************

ACE_INLINE void
ACE_Thread_Adapter::set_log_msg_hooks (ACE_INIT_LOG_MSG_HOOK init_hook,
                                       ACE_INHERIT_LOG_MSG_HOOK inherit_hook)
{
  ACE_Thread_Adapter::init_log_msg_hook_ = init_hook;
  ACE_Thread_Adapter::inherit_log_msg_hook_ = inherit_hook;
}

ACE_INLINE ACE_Thread_Manager *
ACE_Thread_Adapter::thr_mgr (void)
{
  return this->thr_mgr_;
}

ACE_INLINE
ACE_Thread_Adapter::~ACE_Thread_Adapter (void)
{
}

ACE_INLINE ACE_THR_C_FUNC
ACE_Thread_Adapter::entry_point (void)
{
  return this->entry_point_;
}

#if defined (ACE_PSOS)
ACE_INLINE int
isatty (int h)
{
  return ACE_OS::isatty (h);
}
#if defined (fileno)
#undef fileno
#endif /* defined (fileno)*/
ACE_INLINE ACE_HANDLE
fileno (FILE *fp)
{
  return (ACE_HANDLE) fp;
}
#endif /* defined (ACE_PSOS) */

ACE_INLINE
ACE_Cleanup::ACE_Cleanup (void)
{
}

ACE_INLINE void *
ACE_OS::bsearch (const void *key,
                 const void *base,
                 size_t nel,
                 size_t size,
                 ACE_COMPARE_FUNC compar)
{
#if defined (ACE_HAS_PACE)
  return pace_bsearch (key, base, nel, size, compar);
#elif !defined (ACE_LACKS_BSEARCH)
  return ::bsearch (key, base, nel, size, compar);
#else
  ACE_UNUSED_ARG (key);
  ACE_UNUSED_ARG (base);
  ACE_UNUSED_ARG (nel);
  ACE_UNUSED_ARG (size);
  ACE_UNUSED_ARG (compar);
  ACE_NOTSUP_RETURN (NULL);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE void
ACE_OS::qsort (void *base,
               size_t nel,
               size_t width,
               ACE_COMPARE_FUNC compar)
{
#if defined (ACE_HAS_PACE)
  pace_qsort (base, nel, width, compar);
#elif !defined (ACE_LACKS_QSORT)
  ::qsort (base, nel, width, compar);
#else
  ACE_UNUSED_ARG (base);
  ACE_UNUSED_ARG (nel);
  ACE_UNUSED_ARG (width);
  ACE_UNUSED_ARG (compar);
#endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::setuid (uid_t uid)
{
  ACE_TRACE ("ACE_OS::setuid");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_setuid (uid), int, -1);
# elif defined (VXWORKS) || defined (ACE_PSOS)
  // setuid() is not supported:  just one user anyways
  ACE_UNUSED_ARG (uid);
  return 0;
# elif defined (ACE_WIN32) || defined(CHORUS)
  ACE_UNUSED_ARG (uid);
  ACE_NOTSUP_RETURN (-1);
# else
  ACE_OSCALL_RETURN (::setuid (uid), int,  -1);
# endif /* ACE_HAS_PACE */
}

ACE_INLINE uid_t
ACE_OS::getuid (void)
{
  ACE_TRACE ("ACE_OS::getuid");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_getuid (), pace_uid_t, (pace_uid_t) -1);
# elif defined (VXWORKS) || defined (ACE_PSOS)
  // getuid() is not supported:  just one user anyways
  return 0;
# elif defined (ACE_WIN32) || defined(CHORUS)
  ACE_NOTSUP_RETURN (ACE_static_cast (uid_t, -1));
# else
  ACE_OSCALL_RETURN (::getuid (), uid_t, (uid_t) -1);
# endif /* ACE_HAS_PACE */
}

ACE_INLINE int
ACE_OS::setgid (gid_t gid)
{
  ACE_TRACE ("ACE_OS::setgid");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_setgid (gid), int, -1);
# elif defined (VXWORKS) || defined (ACE_PSOS)
  // setgid() is not supported:  just one user anyways
  ACE_UNUSED_ARG (gid);
  return 0;
# elif defined (ACE_WIN32) || defined(CHORUS)
  ACE_UNUSED_ARG (gid);
  ACE_NOTSUP_RETURN (-1);
# else
  ACE_OSCALL_RETURN (::setgid (gid), int,  -1);
# endif /* ACE_HAS_PACE */
}

ACE_INLINE gid_t
ACE_OS::getgid (void)
{
  ACE_TRACE ("ACE_OS::getgid");
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_getgid (), pace_gid_t, (pace_gid_t) -1);
# elif defined (VXWORKS) || defined (ACE_PSOS)
  // getgid() is not supported:  just one user anyways
  return 0;
# elif defined (ACE_WIN32) || defined(CHORUS)
  ACE_NOTSUP_RETURN (ACE_static_cast (gid_t, -1));
# else
  ACE_OSCALL_RETURN (::getgid (), gid_t, (gid_t) -1);
# endif /* ACE_HAS_PACE */
}

ACE_INLINE ACE_EXIT_HOOK
ACE_OS::set_exit_hook (ACE_EXIT_HOOK exit_hook)
{
  ACE_EXIT_HOOK old_hook = exit_hook_;
  exit_hook_ = exit_hook;
  return old_hook;
}

ACE_INLINE int
ACE_OS::isatty (int handle)
{
#if defined (ACE_HAS_PACE)
  ACE_OSCALL_RETURN (pace_isatty (handle), int, -1);
# elif defined (ACE_LACKS_ISATTY)
  ACE_UNUSED_ARG (handle);
  return 0;
# elif defined (ACE_WIN32)
  ACE_TRACE ("ACE_OS::isatty");
  return ::_isatty (handle);
# else
  ACE_TRACE ("ACE_OS::isatty");
  ACE_OSCALL_RETURN (::isatty (handle), int, -1);
# endif /* defined (ACE_LACKS_ISATTY) */
}

#if defined (ACE_WIN32)
ACE_INLINE int
ACE_OS::isatty (ACE_HANDLE handle)
{
#if defined (ACE_LACKS_ISATTY)
  ACE_UNUSED_ARG (handle);
  return 0;
#else
  int fd = ::_open_osfhandle ((long) handle, 0);
  return ::_isatty (fd);
#endif /* ACE_LACKS_ISATTY */
}

ACE_INLINE void
ACE_OS::fopen_mode_to_open_mode_converter (ACE_TCHAR x, int &hmode)
{
    switch (x)
      {
      case ACE_TEXT ('r'):
        if (ACE_BIT_DISABLED (hmode, _O_RDWR))
          {
            ACE_CLR_BITS (hmode, _O_WRONLY);
            ACE_SET_BITS (hmode, _O_RDONLY);
          }
        break;
      case ACE_TEXT ('w'):
        if (ACE_BIT_DISABLED (hmode, _O_RDWR))
          {
            ACE_CLR_BITS (hmode, _O_RDONLY);
            ACE_SET_BITS (hmode, _O_WRONLY);
          }
        ACE_SET_BITS (hmode, _O_CREAT | _O_TRUNC);
        break;
      case ACE_TEXT ('a'):
        if (ACE_BIT_DISABLED (hmode, _O_RDWR))
          {
            ACE_CLR_BITS (hmode, _O_RDONLY);
            ACE_SET_BITS (hmode, _O_WRONLY);
          }
        ACE_SET_BITS (hmode, _O_CREAT | _O_APPEND);
        break;
      case ACE_TEXT ('+'):
        ACE_CLR_BITS (hmode, _O_RDONLY | _O_WRONLY);
        ACE_SET_BITS (hmode, _O_RDWR);
        break;
      case ACE_TEXT ('t'):
        ACE_CLR_BITS (hmode, _O_BINARY);
        ACE_SET_BITS (hmode, _O_TEXT);
        break;
      case ACE_TEXT ('b'):
        ACE_CLR_BITS (hmode, _O_TEXT);
        ACE_SET_BITS (hmode, _O_BINARY);
        break;
      }
}
#endif /* ACE_WIN32 */

// Return a dynamically allocated duplicate of <str>, substituting the
// environment variable if <str[0] == '$'>.  Note that the pointer is
// allocated with <ACE_OS::malloc> and must be freed by
// <ACE_OS::free>.

ACE_INLINE ACE_TCHAR *
ACE_OS::strenvdup (const ACE_TCHAR *str)
{
#if defined (ACE_HAS_WINCE)
  // WinCE doesn't have environment variables so we just skip it.
  return ACE_OS::strdup (str);
#else
  ACE_TCHAR *temp = 0;

  if (str[0] == ACE_TEXT ('$')
      && (temp = ACE_OS::getenv (&str[1])) != 0)
    return ACE_OS::strdup (temp);
  else
    return ACE_OS::strdup (str);
#endif /* ACE_HAS_WINCE */
}

ACE_INLINE int
ACE_Countdown_Time::start (void)
{
  if (this->max_wait_time_ != 0)
    {
      this->start_time_ = ACE_OS::gettimeofday ();
      this->stopped_ = 0;
    }
  return 0;
}

ACE_INLINE int
ACE_Countdown_Time::stop (void)
{
  if (this->max_wait_time_ != 0 && this->stopped_ == 0)
    {
      ACE_Time_Value elapsed_time =
        ACE_OS::gettimeofday () - this->start_time_;

      if (*this->max_wait_time_ > elapsed_time)
        *this->max_wait_time_ -= elapsed_time;
      else
        {
          // Used all of timeout.
          *this->max_wait_time_ = ACE_Time_Value::zero;
          // errno = ETIME;
        }
      this->stopped_ = 1;
    }
  return 0;
}

ACE_INLINE int
ACE_Countdown_Time::update (void)
{
  return this->stop () == 0 && this->start ();
}


#if defined (ACE_WIN32)
ACE_INLINE const OSVERSIONINFO &
ACE_OS::get_win32_versioninfo ()
{
  return ACE_OS::win32_versioninfo_;
}
#endif /* ACE_WIN32 */
