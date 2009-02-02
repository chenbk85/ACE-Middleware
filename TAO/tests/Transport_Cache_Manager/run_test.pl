eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
     & eval 'exec perl -S $0 $argv:q'
     if 0;

# $Id$
# -*- perl -*-

use lib "$ENV{ACE_ROOT}/bin";
use PerlACE::TestTarget;
use strict;

my $final_result = 0;

my @tests = qw(Bug_3549_Regression
               Bug_3558_Regression
              );

my @testsToRun = qw();

push(@testsToRun, @tests);

foreach my $process (@testsToRun) {

  my $server = PerlACE::TestTarget::create_target (1) || die "Create target 1 failed\n";
  my $P = $server->CreateProcess ($process,
                                '--log_level=nothing '
                                .'--report_level=no');
  print "Running $process ...\n";
  my $result = $P->Spawn;
  if ($result != 0) {
    print "FAILED $process\n";
    $final_result = 1;
    next;
  }
  $result = $P->WaitKill($server->ProcessStartWaitInterval());
  if ($result != 0) {
    print "FAILED $process\n";
    $final_result = 1;
    next;
  }
  print "SUCCESS\n";
}

exit $final_result;
