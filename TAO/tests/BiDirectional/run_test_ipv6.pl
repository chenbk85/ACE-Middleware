eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

use lib '../../../bin';
use PerlACE::Run_Test;

$status = 0;
$iorfile = PerlACE::LocalFile ("test.ior");

unlink $iorfile;

if (PerlACE::is_vxworks_test()) {
    $SV = new PerlACE::ProcessVX ("server", "-o test.ior -i 100 -ORBConnectIPV6Only YES");
}
else {
    $SV = new PerlACE::Process ("server", "-o $iorfile -i 100 -ORBConnectIPV6Only YES");
}
$CL = new PerlACE::Process ("client", "-k file://$iorfile -ORBConnectIPV6Only YES");

$SV->Spawn ();

if (PerlACE::waitforfile_timed ($iorfile, 15) == -1) {
    print STDERR "ERROR: cannot find file <$iorfile>\n";
    $SV->Kill ();
    exit 1;
}

$client = $CL->SpawnWaitKill (20);

if ($client != 0) {
    print STDERR "ERROR: client returned $client\n";
    $status = 1;
}

$server = $SV->WaitKill (20);

if ($server != 0) {
    print STDERR "ERROR: server returned $server\n";
    $status = 1;
}

unlink $iorfile;

exit $status;
