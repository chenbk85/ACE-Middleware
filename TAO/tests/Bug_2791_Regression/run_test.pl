eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

use lib "$ENV{ACE_ROOT}/bin";
use PerlACE::Run_Test;

$status = 0;

if (PerlACE::is_vxworks_test()) {
    $CL = new PerlACE::ProcessVX ("client", "");
}
else {
    $CL = new PerlACE::Process ("client", "");
}

$client = $CL->SpawnWaitKill ($PerlACE::wait_interval_for_process_creation);

if ($client != 0) {
    print STDERR "ERROR: client returned $client\n";
    $status = 1;
}
else
{
    print "Test Passed."
}

exit $status;
