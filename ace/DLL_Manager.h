/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    DLL_Manager.h
 *
 *  $Id$
 *
 *  @author Don Hinton <dhinton@ieee.org>
 */
//=============================================================================


#ifndef ACE_DLL_MANAGER_H
#define ACE_DLL_MANAGER_H
#include "ace/pre.h"

#include "ace/OS.h"
#include "ace/Singleton.h"
#include "ace/Synch_T.h"
#include "ace/Auto_Ptr.h"
#include "ace/SString.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#define ACE_DEFAULT_DLL_MANAGER_SIZE 1024

/**
 * @class ACE_DLL_Handle
 *
 * @brief Provides an abstract interface for handling various DLL
 * operations.
 *
 * This class is an wrapper over the various methods for utilizing
 * a dynamically linked library (DLL), which is called a shared
 * library on some platforms.  It is refcounted and managed by
 * ACE_DLL_Manager, so there will only be a single instance of this
 * class for each dll loaded, no matter how many instances of ACE_DLL
 * an application has open.  Operations <open>, <close>, and
 * <symbol> have been implemented to help opening/closing and
 * extracting symbol information from a DLL, respectively.
 *
 * Most of this class came from the original ACE_DLL class.
 * ACE_DLL is now just an interface that passed all it's calls 
 * either directly or via ACE_DLL_Manager to this class for 
 * execution.  
 *
 */
class ACE_Export ACE_DLL_Handle
{
public:

  /// Default construtor.
  ACE_DLL_Handle (void);

  /// Destructor.
  ~ACE_DLL_Handle (void);

  /// Returns the name of the shared library (without prefixes or suffixes).
  const ACE_TCHAR *dll_name () const;

  /**
   * This method opens and dynamically links <dll_name>.  The default
   * mode is <RTLD_LAZY>, which loads identifier symbols but not the
   * symbols for functions, which are loaded dynamically on-demand.
   * Other supported modes include: <RTLD_NOW>, which performs all
   * necessary relocations when <dll_name> is first loaded and
   * <RTLD_GLOBAL>, which makes symbols available for relocation
   * processing of any other DLLs.  Returns -1 on failure and 0 on
   * success.
   */
  int open (const ACE_TCHAR *dll_name, 
            int open_mode,
            ACE_SHLIB_HANDLE handle);

  /// Call to close the DLL object.  If unload = 0, it only decrements
  /// the refcount, but if unload = 1, then it will actually unload 
  /// the library when the refcount == 0;
  int close (int unload = 0);

  /// Return the current refcount.
  sig_atomic_t refcount (void) const;

  /// If <symbol_name> is in the symbol table of the DLL a pointer to
  /// the <symbol_name> is returned.  Otherwise, returns 0.
  void *symbol (const ACE_TCHAR *symbol_name);

  /**
   * Return the handle to the caller.  If <become_owner> is non-0 then
   * caller assumes ownership of the handle so we decrement the retcount.
   */
  ACE_SHLIB_HANDLE get_handle (int become_owner = 0);
 
private:
  /// Returns a pointer to a string explaining why <symbol> or <open>
  /// failed.  This is used internal to print out the error to the log,
  /// but since this object is shared, we can't store or return the error
  /// to the caller.
  auto_ptr <ACE_TString> error (void) const;

  // Keep track of how many ACE_DLL objects have a reference to this
  // dll.
  sig_atomic_t refcount_;

  /// Name of the shared library.
  ACE_TCHAR *dll_name_;

  /// Handle to the actual library loaded by the OS.
  ACE_SHLIB_HANDLE handle_;

  /// Keeps track of whether or not open() has ever been called.  This
  /// helps get around problem on Linux, and perhaps other OS's, that
  /// seg-fault if dlerror() is called before the ld library has been
  /// initialized by a call to dlopen().
  static sig_atomic_t open_called_;

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
  /// Synchronization variable for the MT_SAFE Repository
  ACE_Thread_Mutex lock_;
#endif /* ACE_MT_SAFE */

  // = Disallow copying and assignment since we don't handle these.
  ACE_UNIMPLEMENTED_FUNC (ACE_DLL_Handle (const ACE_DLL_Handle &))
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_DLL_Handle &))

};


/**
 * @class ACE_DLL_Manager_Ex
 *
 * @brief This class serves as a factory and repository for 
 * instances of ACE_DLL_Handle.  It is implemented and typedef'd 
 * as a singleton, ACE_DLL_Manager, and is thus always available
 * via it's instance() method.
 *
 */
class ACE_Export ACE_DLL_Manager_Ex
{
public:
  enum
  {
    DEFAULT_SIZE = ACE_DEFAULT_DLL_MANAGER_SIZE
  };

  enum UNLOAD_STRATEGY
  {
    /// The default strategy is to use a per-process strategy
    /// and unload dlls eagerly, i.e., as soon as the refcount
    /// reaches zero.
    DEFAULT = 0,
    /// Use strategies on a per-dll basis.  If dll doesn't
    /// define a strategy, use the default one.
    PER_DLL = 1,

    /// Apply the unload_strategy hook method to decide when to 
    /// unload the dll, defaults to program exit.
    LAZY = PER_DLL << 1
  };

  /// Default constructor.
  ACE_DLL_Manager_Ex (int size = ACE_DLL_Manager_Ex::DEFAULT_SIZE);

  /// Destructor.
  ~ACE_DLL_Manager_Ex (void);

  /// Factory for ACE_DLL_Handle objects.  If one already exits, 
  /// its refcount is incremented.
  ACE_DLL_Handle *open_dll (const ACE_TCHAR *dll_name, 
                            int openmode, 
                            ACE_SHLIB_HANDLE handle);

  /// Close the underlying dll.  Decrements the refcount.
  int close_dll (const ACE_TCHAR *dll_name);

  /// Returns the current UNLOAD_STRATEGY.
  u_long unload_strategy (void) const;

  /// Set the UNLOAD_STRATEGY.  If the strategy is changed for 
  /// LAZY to EAGER, then it will also unload any dlls with zero
  /// refcounts.
  void unload_strategy (u_long unload_strategy = 0);

protected:
  // Allocate handle_vector_.
  int open (int size);

  // Close all open dlls and deallocate memory.
  int close (void);

  // Find dll in handle_vector_.
  ACE_DLL_Handle *find_dll (const ACE_TCHAR *dll_name) const;

  // Applies strategy for unloading dll.
  int unload_dll (ACE_DLL_Handle *dll_handle, int force_close = 0);

private:

  /// Vector containing all loaded handle objects.
  ACE_DLL_Handle **handle_vector_;

  /// Current number of handles.
  int current_size_;

  /// Maximum number of handles.
  int total_size_;

  /// Unload strategy.
  u_long unload_strategy_;

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
  /// Synchronization variable for the MT_SAFE Repository
  ACE_Thread_Mutex lock_;
#endif /* ACE_MT_SAFE */

 // = Disallow copying and assignment since we don't handle these.
  ACE_UNIMPLEMENTED_FUNC (ACE_DLL_Manager_Ex (const ACE_DLL_Manager_Ex &))
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_DLL_Manager_Ex &))
};

/// Global singleton.
typedef ACE_Singleton < ACE_DLL_Manager_Ex,
                        ACE_SYNCH_MUTEX > ACE_DLL_Manager;

#include "ace/post.h"
#endif /* ACE_DLL_MANAGER_H */
