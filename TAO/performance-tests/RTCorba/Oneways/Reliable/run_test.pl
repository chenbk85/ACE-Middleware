eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

unshift @INC, '../../../../../bin';
require ACEutils;

$iorfile = "test.ior";
$iterations = 1000;
$bufsize = 1002;
$type = "";
$other = "";

unlink $iorfile;

sub run_test
{
  my $type = shift(@_);

  print STDERR "\n***************** STARTING TEST ******************\n";

  $CL = Process::Create ($EXEPREFIX."client".$EXE_EXT,
                         "-t $type -i $iterations -m $bufsize");

  $client = $CL->TimedWait (60);
  if ($client == -1) {
    print STDERR "ERROR: client timedout\n";
    $CL->Kill (); $CL->TimedWait (1);
  }
}

# Parse the arguments

@types = ("none", "transport", "server", "target", "twoway");

for ($i = 0; $i <= $#ARGV; $i++)
{
  SWITCH:
  {
    if ($ARGV[$i] eq "-h" || $ARGV[$i] eq "-?")
    {
      print "Run_Test Perl script for TAO Reliable Oneways Test\n\n";
      print "run_test [-t test type] [-i iterations] [-m buffer size]\n";
      print "\n";
      print "-t test type        -- runs only one type of oneway test\n";
      print "-i iterations       -- number of calls in each test\n";
      print "-m buffer size      -- queue size for buffered oneways\n";
      exit 0;
    }
    if ($ARGV[$i] eq "-i")
    {
      $iterations = $ARGV[$i + 1];
      $i++;
      last SWITCH;
    }
    if ($ARGV[$i] eq "-m")
    {
      $bufsize = $ARGV[$i + 1];
      $i++;
      last SWITCH;
    }
    if ($ARGV[$i] eq "-t")
    {
      @types = split (',', $ARGV[$i + 1]);
      $i++;
      last SWITCH;
    }
    $other .= $ARGV[$i];
  }
}

unlink $iorfile;

$SV = Process::Create ($EXEPREFIX."server$EXE_EXT");

if (ACE::waitforfile_timed ($iorfile, 5) == -1) {
  print STDERR "ERROR: cannot find file <$iorfile>\n";
  $SV->Kill (); $SV->TimedWait (1);
  exit 1;
}

foreach $type (@types) {
  run_test ($type);
}

$server = $SV->TimedWait (5);
if ($server == -1) {
  print STDERR "ERROR: server timedout\n";
  $SV->Kill (); $SV->TimedWait (1);
}

unlink $iorfile;

if ($server != 0 || $client != 0) {
  exit 1;
}

exit 0;
