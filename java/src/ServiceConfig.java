/*************************************************
 *
 * = PACKAGE
 *    JACE.ServiceConfigurator
 *
 * = FILENAME
 *    ServiceConfig.java
 *
 * Services can be suspended, resumed, removed, and reloaded.  Reloading requires that
 * the user calls a prepareForReload method after removing a service.  You can't access
 * the ServiceObjects that are loaded directly -- anything loaded with a class loader
 * must be wrapped and have its methods called via reflection.  This is because a
 * loaded class doesn't exist in the same space as one loaded with the system loader.
 *
 *
 *
 *@author Prashant Jain, Everett Anderson
 *
 *************************************************/
package JACE.ServiceConfigurator;

import java.io.*;
import java.util.*;
import java.net.*;
import java.lang.*;
import JACE.OS.*;
import JACE.Misc.*;

/**
 * <hr>
 * <p><b>TITLE</b><br>
 *     Provide the base class that supplies common server daemon
 *     operations.  Also provides a global point for interacting with
 *     the service repository.
 */
public class ServiceConfig
{
  /** Begins the process of loading a service configurator file:
   *  parses the command line and calls either loadOldConfigFile or
   *  processDirectives depending on whether or not the user wants
   *  to try to load a C++ svc.conf file.
   */
  public static int open (String [] args) throws FileNotFoundException, IOException, ClassNotFoundException, IllegalAccessException, InstantiationException
   {
     // Parse the command line
    ServiceConfig.parseArgs (args);

    // Create a repository and class loader
    if (ServiceConfig.svcRep_ == null)
      ServiceConfig.svcRep_ = new ServiceRepository ();
    if (ServiceConfig.loader_ == null)
      ServiceConfig.loader_ = new ServiceLoader();

    if (ServiceConfig.oldConfigFormat_) 
      return ServiceConfig.loadOldConfigFile();
    else
      return ServiceConfig.processDirectives ();
    
  }

  /** Parses the command line
    * Valid command line options:
    * -b             Run as a daemon (not implemented yet)
    * -d             Debug mode
    * -n             No defaults
    * -o             Attempt to load a C++ ACE service config file
    * -f <filename>  Load services in the given file [see below for info]
    *
    */
  protected static void parseArgs (String [] args)
  {
    GetOpt getopt = new GetOpt (args, "bdnf:o:");
    for (int c; (c = getopt.next ()) != -1; )
      switch (c)
	{
	case 'b':
	  // Note: not supported yet!
	  ServiceConfig.beADaemon_ = true;
	  break;
	case 'd': 
	  ServiceConfig.debug_ = true;
	  break;
	case 'n':
	  ServiceConfig.noDefaults_ = true;
	  break;
	case 'o':
	  ServiceConfig.oldConfigFormat_ = true;
	  break;
	case 'f':
	  ServiceConfig.serviceConfigFile_ = getopt.optarg ();
	  break;
	default:
	  ACE.ERROR ((char ) c + " is not a ServiceConfig option");
	  break;
	}
  }

  /** Called by ParseNode subclass
   * Asks the Service Repository to spend a service
   */
  public static int suspend (String name)
  {
    return svcRep_.suspend(name);
  }

  /** Called by ParseNode subclass
   * Asks the Service Repository to resume a service
   */
  public static int resume (String name)
  {
    return svcRep_.resume(name);
  }

  /** Called by ParseNode subclass
   * Asks the Service Repository to remove a serivce
   */
  public static int remove (String name)
  {
    return svcRep_.remove(name);
  }

  /** Should be called before the user wants to reload
   * a service.  This calls garbage collection to
   * (hopefully) obliterate the names of any unused
   * service classes, and creates a new instance
   * of the ClassLoader so there won't be problems
   * reloading.
   */
  public static void prepareForReload()
  {
    ServiceConfig.loader_ = new ServiceLoader();

    System.gc();

  }

  /**
   * Parse a service configurator file, creating classes as necessary
   *
   * This is getting too complicated -- since CUP and JLex are available, it would be nice to
   * develop a grammar for this.  Unfortunately, there may be file problems when trying to get
   * CUP and JLex to produce more than one parser per program.
   *
   * Current formats:
   *
   *    load <Service Name> <Full Class Name> Service_Object "<argument list>"
   *
   *    resume <Service Name>
   *    suspend <Service Name>
   *    remove <Service Name>
   *
   */
  protected static int processDirectives () throws FileNotFoundException, IOException, ClassNotFoundException, IllegalAccessException, InstantiationException 
  {
    if (ServiceConfig.serviceConfigFile_ == null) 
      ServiceConfig.serviceConfigFile_ = "svc.conf";

    ACE.DEBUG("Processing directives in file " + ServiceConfig.serviceConfigFile_);

    File configFile = new File (ServiceConfig.serviceConfigFile_);
    
    // Check if file exists and is a normal file
    if (!configFile.exists () || !configFile.isFile ())
      throw new FileNotFoundException ("File " + ServiceConfig.serviceConfigFile_ + " not found");
    
    // Check if the file is readable
    if (!configFile.canRead ())
      throw new IOException ("File " + ServiceConfig.serviceConfigFile_ + " not readable");

    // Set up the stream
    FileInputStream fileIn = new FileInputStream (configFile);

    // Parse the file
    StreamTokenizer in = new StreamTokenizer (fileIn);

    // Set '#' as comment character to be ignored and set '/' as
    // ordinary character (was original comment character) 
    //    in.commentChar ('#');
    in.ordinaryChar ('/');

    // Set characters in ASCII range 33 to 47, ASCII range 91 to 96,
    // and ASCII range 123 to 126 as ordinary characters
    in.wordChars ('!', '/');  // ASCII range 33 to 47
    in.wordChars (':', '@');  // ASCII range 58 to 64
    in.wordChars ('[', '`');  // ASCII range 91 to 96
    in.wordChars ('{', '~');  // ASCII range 123 to 126

    String commandName = null;
    String serviceName = null;
    String className = null;
    String classType = null;
    String args = null;
    // Create a state machine
    int state = ServiceConfig.COMMAND_NAME;

    // The apply() method on ParseNode starts the process of actually executing the
    // desired action (suspend, load, etc)
    ParseNode result = null;

    while (in.nextToken () != StreamTokenizer.TT_EOF)
      {
	switch (state)
	  {
	  case ServiceConfig.COMMAND_NAME:
	    if (in.ttype == StreamTokenizer.TT_WORD) {
	      commandName = in.sval;

	      // This is a hack, but it should work until CUP is easier
	      // to deal with when multiple parsers are needed
	      if (commandName.equals("load"))
		result = new AddServiceObjectNode(0);
	      else
	      if (commandName.equals("remove"))
		result = new RemoveNode(0);
	      else
	      if (commandName.equals("suspend"))
		result = new SuspendNode(0);
	      else
	      if (commandName.equals("resume"))
		result = new ResumeNode(0);
	      else
		throw new IOException ("COMMAND NAME missing or invalid: " + commandName);

	      ACE.DEBUG("Command node type: " + ((Object)result).getClass().getName());


	    } else
	      throw new IOException ("Illegal COMMAND NAME argument in file " + ServiceConfig.serviceConfigFile_);
	    state = ServiceConfig.SERVICE_NAME;
	    break;
	  case ServiceConfig.SERVICE_NAME:
	    if (in.ttype == StreamTokenizer.TT_WORD)
	      serviceName = in.sval;
	    else
	      throw new IOException ("Illegal SERVICE NAME argument in file " + ServiceConfig.serviceConfigFile_);


	    if (!commandName.equals("load")) {
	        result.init(serviceName);
		result.apply(); 
		in.whitespaceChars (' ', ' ');
		state = ServiceConfig.SERVICE_NAME;
	    } else
	      state = ServiceConfig.CLASS_NAME;
	    break;
	  case ServiceConfig.CLASS_NAME:
	    if (in.ttype == StreamTokenizer.TT_WORD)
	      className = in.sval;
	    else
	      throw new IOException ("Illegal CLASS NAME argument in file " + ServiceConfig.serviceConfigFile_);
	    state = ServiceConfig.CLASS_TYPE;
	    break;
	  case ServiceConfig.CLASS_TYPE:
	    if (in.ttype == StreamTokenizer.TT_WORD)
	      classType = in.sval;
	    else
	      throw new IOException ("Illegal CLASS TYPE argument in file " + ServiceConfig.serviceConfigFile_);
	    state = ServiceConfig.ARGS;
	    // Set space to be an ordinary character to allow
	    // arguments to be parsed in
	    in.wordChars (' ', ' ');
	    break;
	  case ServiceConfig.ARGS:
	    ACE.DEBUG("Processing arguments");

	    args = new String("");

	    if (in.ttype == StreamTokenizer.TT_WORD)
	      {
		args = in.sval;

		// If just two double quotes, there are no args
		if (args.length() == 2) {
		  args = new String("");
		} else
		  args = args.substring(1, args.length() - 1);
	      }

	    // Quick hack until more parsing necessary -- set the needed data
	    ((AddServiceObjectNode)result).init(serviceName, className, false);
	    ((AddServiceObjectNode)result).params(args);

	    result.apply();

	    state = ServiceConfig.SERVICE_NAME;
	    // Set space back to whitespace-character to extract the
	    // next token
	    in.whitespaceChars (' ', ' ');
	    break;
	  default:
	    throw new IOException ("Illegal argument in file " + ServiceConfig.serviceConfigFile_);
	  }
      }
    return 0;
  }

  /** Parses the svc.conf file, treating it as a C++ ACE svc.conf file.
    * This will involve attempts to infer the class name from
    * the service initializer path, and isn't very accurate.
    */
  public static int loadOldConfigFile ()
  {
    parser ps = new parser();

    try {

      ps.parse();

    } catch (Exception e) {
      ACE.ERROR("Error: " + e);
      return -1;
    }

    return 0;
  }


  /**
   * This is called when apply() is called on AddServiceObjectNodes.  Similar
   * methods could be developed for later data types (AddStreamNode, etc).  This
   * tries to load the ServiceObject and its classes.  When trying to find info
   * from the C++ files, this generates possible file paths.
   */
  public static int initialize (AddServiceObjectNode son)
  {
     Class c = null;

    if (ServiceConfig.oldConfigFormat_) {

      // Generate a lot of possible file locations and names
      ClassNameGenerator cng = new ClassNameGenerator(son.locator());
      String attempt = null;
      boolean ready = false;
 

      // Try to load the class based on the names we can infer from
      // the C++ svc.conf line
      while ((cng.hasMoreElements()) && (!ready)) {
	try {
	  
	  attempt = (String)cng.nextElement();
	  
	  c = loader_.loadClass(attempt, true);

	  ready = true;
      
	} catch (ClassNotFoundException e) { }
      
      }

      // Couldn't find the class
      if (!ready) {
	ACE.ERROR("Can't find class with locator: " + son.locator());
	return -1;
      }

    } else {

      try {

	c = loader_.loadClass(son.locator(), true);

      } catch (ClassNotFoundException e) {
	ACE.ERROR("Can't find class with locator: " + son.locator());
	return 01;
      }

    }

    try {

      Object service = c.newInstance();
      // Can't cast this to a ServiceObject, even though it will look just
      // like one -- Java puts things loaded with a non-standard class loader
      // in their own name space.  The ServiceObjectRecord is a wrapper that
      // gets around this by using reflection.
      ServiceObjectRecord svcObjRec = new ServiceObjectRecord(service, son.name());

      // Split the argument array up into smaller pieces
      String [] argArray = OS.createStringArray (son.params(), " ");

      // Initialize the service -- start it running
      svcObjRec.init(argArray);

      // Put it in the service repository
      svcRep_.insert((ServiceRecord)svcObjRec);

    } catch (IllegalAccessException e) {
        ACE.ERROR("Error " + e);
	return -1;
    } catch (InstantiationException e) {
        ACE.ERROR("Error " + e);
	return -1;
    }

    return 0;
  }

  // Set by command line options
  private static boolean oldConfigFormat_ = false;
  private static boolean beADaemon_ = false;
  private static boolean debug_ = false;
  private static boolean noDefaults_ = false;

  public static String serviceConfigFile_ = "svc.conf";

  private static ServiceRepository svcRep_ = null;
  private static ServiceLoader loader_ = null;

  // States for the state-machine used in parsing the config file
  private final static int SERVICE_NAME = 0;
  private final static int CLASS_NAME = 1;
  private final static int CLASS_TYPE = 2;
  private final static int ARGS = 3;
  private final static int COMMAND_NAME = 4;


}



