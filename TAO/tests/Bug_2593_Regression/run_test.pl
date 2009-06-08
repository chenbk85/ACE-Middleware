eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
     & eval 'exec perl -S $0 $argv:q'
     if 0;

# $Id$
# -*- perl -*-

use lib "$ENV{ACE_ROOT}/bin";
use PerlACE::Run_Test;

$status = 0;
$debug_level = '0';

foreach $i (@ARGV) {
    if ($i eq '-debug') {
        $debug_level = '10';
    } 
}

$iorfile = PerlACE::LocalFile ("server.ior");
unlink $iorfile;

$endpoints = "-ORBEndpoint shmiop://12345 -ORBEndpoint iiop://:"
    . PerlACE::random_port();
$debug_conf = "-ORBDebugLevel $debug_level";
$svc_conf = "-ORBSvcConf server.conf";

$server_opts = "-o $iorfile $svc_conf $endpoints $debug_conf";

if (PerlACE::is_vxworks_test()) {
    $SV = new PerlACE::ProcessVX ("server", $server_opts);
}
else {
    $SV = new PerlACE::Process ("server", $server_opts);
}
$CL = new PerlACE::Process ("client", " -k file://$iorfile");
    
$server = $SV->Spawn ();

if ($server != 0) {
    print STDERR "ERROR: server returned $server\n";
    exit 1;
}

if (PerlACE::waitforfile_timed ($iorfile,
                        $PerlACE::wait_interval_for_process_creation) == -1) {
    print STDERR "ERROR: cannot find file <$iorfile>\n";
    $SV->Kill (); $SV->TimedWait (1);
    exit 1;
} 

$client = $CL->SpawnWaitKill (300);

if ($client != 0) {
    print STDERR "ERROR: client returned $client\n";
    $status = 1;
}

$server = $SV->WaitKill (10);

if ($server != 0) {
    print STDERR "ERROR: server returned $server\n";
    $status = 1;
}

unlink $iorfile;

exit $status;
