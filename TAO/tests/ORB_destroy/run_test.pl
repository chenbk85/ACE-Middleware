eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

unshift @INC, '../../../bin';
require ACEutils;
use Cwd;

ACE::checkForTarget(getcwd());

$T = Process::Create ($EXEPREFIX."ORB_destroy".$EXE_EXT);

$client = $T->TimedWait (60);
if ($client == -1) {
  print STDERR "ERROR: test timedout\n";
  $T->Kill (); $T->TimedWait (1);
  exit 1;
}

exit 0;
