eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

use lib '../../../../bin';
use ACEutils;

$TEST  = Process::Create ($EXEPREFIX."NewPOA$EXE_EXT", "");
if ($TEST->TimedWait (60) == -1) {
  print STDERR "ERROR: test timedout\n";
  $TEST->Kill (); $TEST->TimedWait (1);
  exit 1;
}
exit 0;
