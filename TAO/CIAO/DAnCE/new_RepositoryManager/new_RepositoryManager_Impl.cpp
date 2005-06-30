// $Id$

// -*- C++ -*-
//
// $Id$

///====================================================================
// filename: new_RepositoryManager_Impl.cpp
// Author: Stoyan Paunov        spaunov@isis.vanderbilt.edu
//



#include "new_RepositoryManager_Impl.h"

#include "ace/OS_NS_fcntl.h"      //for open
#include "ace/OS_NS_unistd.h"     //for close
#include "ace/OS_NS_sys_stat.h"   //for filesize and fstat and mkdir
#include "ace/OS_NS_string.h"     //for ACE_CString


//to remove a file or dir from the local filesystem need remove () from stdio.h
// ---> need to include ace/OS_NS_stdio.h which would include the correct file for any OS!
#include "ace/OS_NS_stdio.h"

#include "ZIP_Wrapper.h"
#include "ace/Containers_T.h"                   //for ACE_Double_Linked_List
#include "ace/Malloc_Allocator.h"               //for ACE_New_Allocator needed by the doubly link list

#include "Config_Handlers/cdp.hpp"
#include "Config_Handlers/Deployment.hpp"
#include "Config_Handlers/DP_Handler.h"
#include "ciao/Deployment_DataC.h"
#include "Config_Handlers/XML_Helper.h"

#include "ace/Thread.h"                                 //for obtaining the ID of the current thread
#include "ace/OS_NS_stdlib.h"                   //for itoa ()


#include <iostream>
using namespace std;


// Implementation skeleton constructor
CIAO_new_RepositoryManagerDaemon_i::CIAO_new_RepositoryManagerDaemon_i (CORBA::ORB_ptr the_orb)
  : the_orb_ (CORBA::ORB::_duplicate (the_orb))
{
  //create directory in which the packages will be stored

  ACE_OS::mkdir(RM_STORAGE_PATH);       
  //if dir already exists a -1 is returned
  //we ignore this, just need to make sure the directory exists
}

// Implementation skeleton destructor
CIAO_new_RepositoryManagerDaemon_i::~CIAO_new_RepositoryManagerDaemon_i (void)
{
  this->packages_.unbind_all ();
}


//shutdown method to shut down the orb gracefully
void 
CIAO_new_RepositoryManagerDaemon_i::shutdown ()
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Add your implementation here
	
  this->packages_.unbind_all ();
	
  this->the_orb_->shutdown (0);
}

//This method allow you to install a package into the RM

void 
CIAO_new_RepositoryManagerDaemon_i::installPackage (const char * installationName,
                                                    const ::Deployment::Package & the_package,
                                                    ::CORBA::Boolean replace)
  ACE_THROW_SPEC ((
                   CORBA::SystemException,
                   ::Deployment::NameExists,
                   ::Deployment::PackageError
                   ))
{
  // Add your implementation here

  ACE_Hash_Map_Entry <ACE_CString, ACE_CString> *entry;

  if (this->packages_.find (ACE_CString (installationName), entry) == 0)
    ACE_THROW (Deployment::NameExists ());

  ACE_CString path (RM_STORAGE_PATH);
  path += "/";
  path += installationName;
  path += ".cpk";

  int retn_code = this->write_to_disk (path.c_str (), 
                                       the_package.get_buffer (), 
                                       the_package.length ());

  if (retn_code == -1)
    ACE_THROW (Deployment::PackageError ());

  //insert the package into the database
  this->packages_.bind (ACE_CString (installationName), path);
}

//This method parse the depoyment plan in a package and return the 
//corresponding structure. You need to provide the name of the 
//package whose deployment plan you want to get . If no plan is
//found in the package, an exception is thrown

::Deployment::DeploymentPlan * 
CIAO_new_RepositoryManagerDaemon_i::retrievePlan (const char * packageName)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   ::Deployment::NoPlan))
{
  // Add your implementation here

  cout << "in retrieve Plan!" << endl;

  //form the path to the archive in the local filesystem
  ACE_CString path (RM_STORAGE_PATH);
  path += "/";
  path += packageName;
  path += ".cpk";

  //create a ZIP wrapper
  ZIP_Wrapper zip;

  //create a doubly link list
  ACE_New_Allocator allocator;
  ACE_Double_Linked_List<ZIP_File_Info> list (&allocator);


  cout << "Getting the list ..." <<endl;

  //get the list of files in the package and figure out the name of the Deployment Plan
  zip.file_list_info (const_cast<char*> (path.c_str ()), list);
  ACE_CString plan_name;
  CORBA::Boolean found = false;

  while (!list.is_empty ())
    {
      ZIP_File_Info* inf = list.delete_head ();
      if (!found && ACE_OS::strstr (inf->name_.c_str (), ".cdp"))
        {
          cout << inf->name_.c_str () << endl;
          plan_name = inf->name_.c_str ();
          found = true;
        }
      delete inf;
    }

  //there is not deployment plan in the package
  if (!found)
    {
      ACE_TEXT ("[RM::retrievePlan] no DeploymentPlan in package!\n");
      ACE_THROW (Deployment::NoPlan ());
    }

  //read the Deployment plan from the package
  ACE_Message_Block file (0,0);
  if (!zip.get_file (const_cast<char*> (path.c_str ()), 
                     const_cast<char*> (plan_name.c_str ()), file))
    {
      ACE_TEXT ("[RM::retrievePlan] Unable to retrieve file!\n");
      ACE_THROW (CORBA::INTERNAL ());
    }

  //if file is 0 length XERCESC Fails!!!

  //We are using Xercesc in the Config_Handlers and unfortunately its API only
  //takes a file in the local file system as an argument, thus need to
  //write out the contents of the deployent plan to a file
  //in the current directory. I use the thread id to guarrantee 
  //lack of race conditions if multithreading is enabled
  unsigned int thread_id = ACE_Thread::self ();
  char temp[128];

  ACE_CString local_file ("_dp_temp_");
  local_file += ACE_OS::itoa (thread_id, temp, 10);

  //write the file to disk
  if(!this->write_to_disk (const_cast<char*> (local_file.c_str ()), file))
    {
      ACE_TEXT ("[RM::retrievePlan] DeploymentPlan preparation failule!\n");
      ACE_THROW (CORBA::INTERNAL ());
    }

  //parse the Deployment plan and return the resulting data structure
  CIAO::Config_Handlers::XML_Helper the_helper;
  xercesc::DOMDocument *doc;

  if (!(doc = the_helper.create_dom (local_file.c_str ())))
    {
      ACE_TEXT ("[RM::retrievePlan] XML_Helper failed us!\n");
      ACE_THROW (CORBA::INTERNAL ());
    }

  CIAO::Config_Handlers::DeploymentPlan dp = CIAO::Config_Handlers::deploymentPlan (doc);
  CIAO::Config_Handlers::DP_Handler dp_handler (dp);

  //we no longer need the file with the deployment plan, so lets erase it!
  remove (local_file.c_str ());

  //the non-const version of this function releases the ownership of the plan
  //before it returns it so we are safe to return the return value
  return dp_handler.plan ();
}


//find a package and return it if installed in the RM
//else throw an exception

::Deployment::Package * 
CIAO_new_RepositoryManagerDaemon_i::findPackageByName (const char * name)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   ::Deployment::NoSuchName))
{
  // Add your implementation here

  // Find out if the package was installed in the repository,
  // return it if found or throw and exception otherwise

  ACE_Hash_Map_Entry <ACE_CString, ACE_CString> *entry = 0;

  if (this->packages_.find (ACE_CString (name), entry) != 0)
    ACE_THROW (Deployment::NoSuchName ()); // package not found

 
  size_t length = 0;	 
  CORBA::Octet* buffer = this->read_from_disk (entry->int_id_.c_str (), length);

  Deployment::Package* package = new Deployment::Package (length, //max of the sequence
                                                          length, //length of the sequence
                                                          buffer, //data to be stored within the sequence
                                                          true    //take ownership of the data
                                                          );

  return package;
}


//find an implementation (.dll, .so) by its name and return it if installed in the RM
//else throw an exception. You need to specify the package in which the RM
//is to look for the implementation

::Deployment::Implementation * 
CIAO_new_RepositoryManagerDaemon_i::findImplementationByName (const char * implementation_name, 
                                                              const char * package_name)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   ::Deployment::NoSuchName))
{
  // Add your implementation here

  //form the path to the archive in the local filesystem
  ACE_CString path (RM_STORAGE_PATH);
  path += "/";
  path += package_name;
  path += ".cpk";


  ACE_CString artifact ("implementations/");
  artifact += implementation_name;

  //create a ZIP wrapper
  ZIP_Wrapper zip;

  //read in artifact
  ACE_Message_Block file (0,0);
  if (!zip.get_file( const_cast<char*> (path.c_str ()), 
                     const_cast<char*> (artifact.c_str ()), file))
    {
      cout << "Unable to retrieve file!" << endl;
      ACE_THROW_RETURN (Deployment::NoSuchName (), 0);
    }

  Deployment::Implementation* impl = new Deployment::Implementation ();

  //initialize the Implementation struct and allocate the buffer to hold the data
  impl->name = implementation_name;
  impl->the_implementation.replace (file.total_length (), //max of the sequence
                                    file.total_length (), //length of the sequence
                                    Deployment::Artifact::allocbuf (file.total_length ()),//data to be stored within the sequence
                                    true //take ownership of the data
                                    );

  //impl->the_platform = UNDEF;		//Deployment::Platform

  CORBA::Octet* ptr = impl->the_implementation.get_buffer ();

  //place the Artifact in the Implementation struct
  for (ACE_Message_Block * curr = &file; curr != 0; curr = curr->cont ())
    {
      if (!ACE_OS::memcpy (ptr, curr->rd_ptr(), curr->length()))
        ACE_THROW_RETURN (CORBA::INTERNAL (), 0);

      ptr += curr->length ();
    }

  return impl;
}


::Deployment::Package * 
CIAO_new_RepositoryManagerDaemon_i::findPackageByUUID (const char * UUID)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   ::Deployment::NoSuchName))
{
  // Add your implementation here
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
}

::Deployment::Implementation * 
CIAO_new_RepositoryManagerDaemon_i::findImplementationByUUID (const char * UUID)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   ::Deployment::NoSuchName))
{
  // Add your implementation here
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
}

//get the names of all packages currently installed in the RM

::CORBA::StringSeq * 
CIAO_new_RepositoryManagerDaemon_i::getAllPackageNames ()
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Add your implementation here

  CORBA::ULong num_entries = this->packages_.current_size (); 
  CORBA::StringSeq_var seq = new CORBA::StringSeq (num_entries);

  CORBA::ULong index = 0;
  for (RepositoryDatabase_Iterator iter = this->packages_.begin ();
       iter != this->packages_.end () && index < num_entries;
       iter++)

    seq[index] = const_cast<char*> (((*iter).int_id_).c_str ());	//this looks hideous, but as lond as it works!


  return seq._retn ();		//release the underlying CORBA::StringSeq
}



// Find out if the package was installed in the repository,
// delete it if found or throw and exception otherwise

void 
CIAO_new_RepositoryManagerDaemon_i::deletePackage (const char * installationName)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   ::Deployment::NoSuchName))
{
  // Add your implementation here

  ACE_Hash_Map_Entry <ACE_CString, ACE_CString> *entry;

  if (this->packages_.find (ACE_CString (installationName), entry) != 0)
    ACE_THROW (Deployment::NoSuchName ());
  else
    this->packages_.unbind (installationName);

  //actually delete the package here!

  ACE_CString path (RM_STORAGE_PATH);
  path += "/";
  path += installationName;
  path += ".cpk";

  remove (path.c_str ());
}

//==========================================HELPER METHODS========================================================


//This function attempts to write a sequence of bytes to
//a specified location. A -1 is returned in the case of an error
//and a 1 upon success

int 
CIAO_new_RepositoryManagerDaemon_i::write_to_disk (const char* full_path, 
                                                   const CORBA::Octet* buffer, 
                                                   size_t length)
{
	
  // Open a file handle to the local filesystem
  ACE_HANDLE handle = ACE_OS::open (full_path, O_CREAT | O_TRUNC | O_WRONLY);
  if (handle == ACE_INVALID_HANDLE)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("[RM::write_to_disk] file creation error")),
                      -1);

  //write the data to the file
  if (ACE_OS::write (handle, buffer, length) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("[RM::write_to_disk] file write error")),
                      -1);

  // Close the file handle
  ACE_OS::close (handle);

  return 1;
}


//This function attempts to read a sequence of bytes into an
//ACE_Message_Block from a specified location. A -1 is returned 
//in the case of an error and a 1 upon success

int 
CIAO_new_RepositoryManagerDaemon_i::write_to_disk (const char* full_path, 
                                                   ACE_Message_Block& mb,
                                                   bool replace)
{

  ACE_stat stat;

  if (ACE_OS::stat(full_path, &stat) != -1 && !replace)
    return 0;
	
  // Open a file handle to the local filesystem
  ACE_HANDLE handle = ACE_OS::open (full_path, O_CREAT | O_TRUNC | O_WRONLY);
  if (handle == ACE_INVALID_HANDLE)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("[RM::write_to_disk] file creation error")),
                      -1);

  //write the data to the file
  for (ACE_Message_Block * curr = &mb; curr != 0; curr = curr->cont ())
    if (ACE_OS::write_n (handle, curr->rd_ptr(), curr->length()) == -1)
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%p\n"),
                         ACE_TEXT ("write error")),
                        -1);
		
  // Close the file handle
  ACE_OS::close (handle);

  return 1;
}

//This function attempts to read a sequence of bytes from a specified 
//location and returns an octet sequence. A -1 is returned 
//in the case of an error and a 1 upon success

CORBA::Octet* 
CIAO_new_RepositoryManagerDaemon_i::read_from_disk (const char* full_path,
                                                    size_t &length)
{
  //open the file

  ACE_HANDLE handle = ACE_OS::open (full_path, O_RDONLY);
  if (handle == ACE_INVALID_HANDLE)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("[RM::read_from_disk] file open error")),
                      0);

  ACE_stat file_info;

  ACE_OS::fstat (handle, &file_info);

  CORBA::Octet* buffer = new CORBA::Octet[file_info.st_size];

  if (buffer == 0)
    return 0;

  //read the contents of the file into the buffer
  if (ACE_OS::read_n (handle, buffer, file_info.st_size) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("[RM::write_to_disk] file write error")),
                      0);

  // Close the file handle
  ACE_OS::close (handle);

  length = file_info.st_size;
  return buffer;
}

