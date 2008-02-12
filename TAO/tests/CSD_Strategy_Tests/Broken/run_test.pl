eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
     & eval 'exec perl -S $0 $argv:q'
     if 0;

# $Id$
# -*- perl -*-

use lib "$ENV{ACE_ROOT}/bin";
use PerlACE::Run_Test;

PerlACE::add_lib_path ('../TP_Foo_A/.');
PerlACE::add_lib_path ('../TP_Foo_B/.');
PerlACE::add_lib_path ('../TP_Foo_C/.');
PerlACE::add_lib_path ('../TP_Common/.');

my $status = 0;

my $iorfname_prefix        = "servant";
my $num_servants           = 1;
my $num_orb_threads        = 1;
my $num_remote_clients     = 1;
my $num_csd_threads        = 1;
my $num_collocated_clients = 0;
my $collocated_client_kind = 0;
my $client_kind            = 0;

my $i;
my $j;
my @iorfile;

my $ARGC = @ARGV;

if ($ARGC > 0)
{
  if ($ARGC > 1)
  {
    print STDERR "ERROR: Too many command-line arguments for $0.\n";
    exit 1;
  }

  my $subtest = $ARGV[0];

  if ($subtest eq 'remote')
  {
    $num_remote_clients = 40;
  }
  elsif ($subtest eq 'collocated')
  {
    $num_remote_clients = 0;
    $num_collocated_clients = 1;
    $num_csd_threads=1;
  }
  elsif ($subtest eq 'remote_orbthreads')
  {
    $num_orb_threads = 5;
    $num_remote_clients = 40;
  }
  elsif ($subtest eq 'remote_servants')
  {
    $num_servants = 5;
    $num_remote_clients = 40;
  }
  elsif ($subtest eq 'remote_csdthreads')
  {
    $num_csd_threads = 5;
    $num_remote_clients = 40;
  }
  elsif ($subtest eq 'remote_big')
  {
    $num_csd_threads = 5;
    $num_servants = 10;
    $num_orb_threads = 4;
    $num_remote_clients = 40;
  }
  elsif ($subtest eq 'big')
  {
    $num_csd_threads = 5;
    $num_servants = 10;
    $num_orb_threads = 4;
    $num_remote_clients = 40;
    $num_collocated_clients = 40;
  }
  elsif ($subtest eq 'usage')
  {
    print STDOUT "Usage: $0 [<subtest>]\n" .
                 "\n" .
                 "Supported <subtest> values:\n" .
                 "\n" .
                 "\tremote\n" .
                 "\tcollocated\n" .
                 "\tremote_orbthreads\n" .
                 "\tremote_servants\n" .
                 "\tremote_csdthreads\n" .
                 "\tremote_big\n" .
                 "\tusage\n" .
                 "\n";
    exit 0;
  }
  else
  {
    print STDERR "ERROR: invalid subtest argument for $0: $subtest\n";
    exit 1;
  }
}

#Delete old ior files.
for ($i = 0; $i < $num_servants; $i++) {
  my $servant_id = sprintf("%02d", ($i + 1));
  $iorfile[$i] = PerlACE::LocalFile($iorfname_prefix . "_$servant_id.ior");
  unlink $iorfile[$i];
}

if (PerlACE::is_vxworks_test()) {
    $SV = new PerlACE::ProcessVX ("server_main",
#                           "-ORBNegotiateCodesets 0 "    .
                           "-p $iorfname_prefix "        .
                           "-s $num_servants "           .
                           "-n $num_csd_threads "        .
                           "-t $num_orb_threads "        .
                           "-r $num_remote_clients "     .
                           "-c $num_collocated_clients " .
                           "-k $collocated_client_kind");
}
else {
    $SV = new PerlACE::Process("server_main",
#                           "-ORBNegotiateCodesets 0 "    .
                           "-p $iorfname_prefix "        .
                           "-s $num_servants "           .
                           "-n $num_csd_threads "        .
                           "-t $num_orb_threads "        .
                           "-r $num_remote_clients "     .
                           "-c $num_collocated_clients " .
                           "-k $collocated_client_kind");
}



$SV->Spawn();

# Wait for the servant ior files created by server.
for ($i = 0; $i < $num_servants; $i++) {
  if (PerlACE::waitforfile_timed
                       ($iorfile[$i],
                        $PerlACE::wait_interval_for_process_creation) == -1) {
    print STDERR "ERROR: cannot find file <$iorfile[$i]>\n";
    $SV->Kill();
    $SV->TimedWait(1);
    exit 1;
  }
}

my $count = 0;

for ($i = 0; $i < $num_remote_clients; $i++)
{
  $client_id = $i + 1;

  $j = $i % $num_servants;

  $CLS[$i] = new PerlACE::Process("client_main",
                                  "-i file://$iorfile[$j] ".
                                  "-k $client_kind ".
                                  "-n $client_id");
  $CLS[$i]->Spawn();
}

for ($i = 0; $i < $num_remote_clients; $i++)
{
  $client = $CLS[$i]->WaitKill(60);

  if ($client != 0)
  {
    print STDERR "ERROR: client $i returned $client\n";
    $status = 1;
  }
}


$server = $SV->WaitKill(60);

if ($server != 0) {
    print STDERR "ERROR: server returned $server\n";
    $status = 1;
}

#Delete ior files generated by this run.
for ($i = 0; $i < $num_servants; $i++) {
  unlink $iorfile[$i];
}

exit $status;
