#!/pkg/gnu/bin/perl -I../../../bin
#
# If your perl installation isn't in /pkg/gnu/bin/perl,
# please make the change accordingly
#
# This is a Perl script that runs the client and all the other servers that
# are needed

use Process;

$nsiorfile = "qns_ior";

# number of threads to use for multithreaded clients or servers

$num_threads = 4;

# amount of delay between running the servers

$sleeptime = 1;

# Get the userid (or ip on NT)

if ($^O eq "MSWin32")
{
  system ("ipconfig | find \"Address\">ipnum");

  open (IPNUM, "ipnum");

  read (IPNUM, $line, 80);

  ($junk, $ip1, $ip2, $ip3, $ip4) = split (/: (\d+)\.(\d+)\.(\d+)\.(\d+)/, $line);

  close IPNUM;

  system ("del /q ipnum");

  $uid = $ip4;
}
else
{
  $uid = getpwnam (getlogin ());
}

# variables for parameters

$nsport = 20000 + $uid;
$clport = 0; 
$svport = 0; 
$ffport = 0; 
$gfport = 0; 

# other variables

$n = 1;
$leave = 1;
$ior = 0;
$done = "";
$debug = "";
$cm = "";
$sm = "";
$other = "";
$c_conf = "client.conf";
$s_conf = "server.conf";

sub read_nsior
{
  open (FH, "<".$nsiorfile);

  read (FH, $ior, 255);

  close (FH);
}

sub name_server
{
  my $args = "$other -ORBport $nsport -ORBobjrefstyle url -o $nsiorfile";
  my $prog = "..$DIR_SEPARATOR..$DIR_SEPARATOR"."orbsvcs$DIR_SEPARATOR".
             "Naming_Service$DIR_SEPARATOR".
             "Naming_Service$Process::EXE_EXT";

  $NS = Process::Create ($prog, $args);
}

sub server
{
  my $args = "$other $debug $sm -ORBport $svport -ORBobjrefstyle url ".
             "-ORBnameserviceior $ior -ORBsvcconf $s_conf";

  $SV = Process::Create ("server$Process::EXE_EXT", $args);
}

sub factory_finder
{
  my $args = "$other -ORBport $ffport -ORBobjrefstyle url -ORBnameserviceior ".
             "$ior -ORBsvcconf svc.conf";
	
  $FF = Process::Create ("Factory_Finder".$Process::EXE_EXT, $args);
}

sub generic_factory
{
  my $args = "$other -ORBport $gfport -ORBobjrefstyle url -ORBnameserviceior ".
             "$ior -ORBsvcconf svc.conf";

  $GF = Process::Create ("Generic_Factory".$Process::EXE_EXT, $args);
}

sub client
{
  my $exe = "client$Process::EXE_EXT $other $debug $cm -ORBobjrefstyle url ".
            "-ORBport $clport -ORBnameserviceior $ior -ORBsvcconf $c_conf";

  for ($j = 0; $j < $n; $j++)
  {
    system ($exe);
  }
}

# Parse the arguments

for ($i = 0; $i <= $#ARGV; $i++)
{
  SWITCH: 
  {
    if ($ARGV[$i] eq "-h" || $ARGV[$i] eq "-?")
    {
      print "run_test [-n num] [-leave] [-d] [-h] [-cm] [-sm] [-ns|sv|ff|cl|gf]\n";
      print "\n";
      print "-n num              -- runs the client num times\n";
      print "-leave              -- leaves the servers running and their windows open\n";
      print "-d                  -- runs each in debug mode\n";
      print "-h                  -- prints this information\n";
      print "-cm                 -- use more than one thread in the client\n";
      print "-sm                 -- use more than one thread in the server\n";
      print "-ns -sv -ff -cl -gf -- runs only one of the executables\n";
      exit;
    }
    if ($ARGV[$i] eq "-n")
    {
      $n = $ARGV[$i + 1];
      $i++;
      last SWITCH;
    }
    if ($ARGV[$i] eq "-d")
    {
      $debug = $debug." -d";
      last SWITCH;
    }
    if ($ARGV[$i] eq "-cm")
    {
      $cm = "-n ".$num_threads;
      last SWITCH;
    }
    if ($ARGV[$i] eq "-sm")
    {
      $sm = "-n ".$num_threads;
      last SWITCH;
    }
    if ($ARGV[$i] eq "-leave")
    {
      $leave = 0;
      last SWITCH;
    }
    if ($ARGV[$i] eq "-ns")
    {
      name_server ();
      exit;
    }
    if ($ARGV[$i] eq "-sv")
    {
      read_nsior ();
      server ();
      exit;
    }
    if ($ARGV[$i] eq "-ff")
    {
      read_nsior ();
      factory_finder ();
      exit;
    }
    if ($ARGV[$i] eq "-gf")
    {
      read_nsior ();
      generic_factory ();
      exit;
    }
    if ($ARGV[$i] eq "-cl")
    {
      read_nsior ();
      client ();
      exit;
    }
    if ($ARGV[$i] eq "-customconf")  #secret flag from testall.pl
    {
      #use a different set of *.conf files
      $c_conf = "c.conf";
      $s_conf = "s.conf";
      last SWITCH; 
    }
    $other = $other." ".$ARGV[$i];
  }
}

name_server ();

read_nsior ();

sleep $sleeptime;

server ();
sleep $sleeptime;

factory_finder ();
sleep $sleeptime;

generic_factory ();
sleep $sleeptime;

client ();

if ($leave)
{
  $GF->Kill ();
  $FF->Kill ();
  $SV->Kill ();
  $NS->Kill ();
}


if ($^O eq "MSWin32")
{
  system ("del ".$nsiorfile);
}
else
{
  system ("rm ".$nsiorfile);
}