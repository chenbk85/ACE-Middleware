#! /usr/bin/perl
package PerlACE::TestTarget_Android;

# ******************************************************************
# Description : Creates a PerlACE::Android
# Author      : Marcel Smit
# Create Date : 29/20/2008
#          $Id$
# ******************************************************************

# ******************************************************************
# Pragma Section
# ******************************************************************

use strict;

use PerlACE::TestTarget;
use PerlACE::ProcessVX;
use File::Copy;
use File::Glob;
use File::Spec;
use File::Basename;
use Cwd;
use English;

use POSIX "sys_wait_h";
require PerlACE::ProcessAndroid;

our @ISA = qw(PerlACE::TestTarget);

sub new
{
    my $proto = shift;
    my $config_name = shift;
    my $component = shift;

    if (defined $ENV{'ACE_TEST_VERBOSE'}) {
        print STDERR "New Android target: $config_name : $component\n";
    }

    my $class = ref ($proto) || $proto;
    my $self = {};
    bless ($self, $class);

    $self->GetConfigSettings($config_name);
    $self->{FSROOT} = $ENV{'ANDROID_FS_ROOT'};
    $self->{PROCESS} = undef;
    $self->{RUNNING} = 0;

    # Start the target.
    if ($component == 1) {
        $self->start_target ();
    }

    return $self;
}

sub DESTROY
{
    my $self = shift;
    if ($self->{RUNNING} == 1) {
        # kill the emulator. No need to shutdown gracefully.
        if (defined $ENV{'ACE_TEST_VERBOSE'}) {
            print STDERR "Killing the Android emulator\n";
        }
        $self->KillAll ('emulator*');
        $self->KillAll ('adb');
    }
}

# ******************************************************************
# Subroutine Section
# ******************************************************************
sub LocalFile
{
    my $self = shift;
    my $file = shift;
    my $cwdrel = $file;
    my $prjroot = $ENV{'ACE_ROOT'};

    if (length ($cwdrel) > 0) {
        $cwdrel = File::Spec->abs2rel( cwd(), $prjroot );
    }
    else {
        $cwdrel = File::Spec->abs2rel( $cwdrel, $prjroot );
    }

    my $newfile = $self->{FSROOT} . "/" . $file;
    if (defined $ENV{'ACE_TEST_VERBOSE'}) {
        print STDERR "Android LocalFile for $file is $newfile\n";
    }
    return $newfile;
}

sub AddLibPath ($)
{
    my $self = shift;
    my $dir = shift;
    if (defined $ENV{'ACE_TEST_VERBOSE'}) {
        print STDERR "Adding libpath $dir\n";
    }
    PerlACE::add_lib_path ($dir);
}

sub CreateProcess
{
    my $self = shift;
    my $process = new PerlACE::ProcessAndroid (@_, $self);  return $process;
}

sub NeedReboot ($)
{
    my $self = shift;
    $self->{REBOOT_NEEDED} = 1;
}

# Reboot target
sub RebootNow ($)
{
    my $self = shift;
    $self->{REBOOT_NEEDED} = undef;
    print STDERR "Attempting to reboot target...\n";
    $self->reboot ();
}

sub start_target ()
{
    # For now, we're assuming one target (avd) is running in the test environment.
    # Need to change this when more than one avd's need to start
    my $self = shift;

    if (! defined ($ENV{'ANDROID_SDK_ROOT'})) {
        print STDERR "Error: Android SDK root not defined.\n";
        return 0;
    }
    if (! defined ($ENV{'ANDROID_AVD_NAME'})) {
        print STDERR "Error: Android AVD name not defined.\n";
        return 0;
    }
    my $android_process = $ENV{'ANDROID_SDK_ROOT'} . "/tools/android";
    my $avd_process = $ENV{'ANDROID_SDK_ROOT'} . "/tools/emulator";
    my $adb_process = $ENV{'ANDROID_SDK_ROOT'} . "/platform-tools/adb";

    my $avd_name = $ENV{'ANDROID_AVD_NAME'};
    my $avd_options = "-noaudio -no-window -wipe-data";

    if (defined ($ENV{'ANDROID_AVD_OPTIONS'})) {
        print STDERR "Resetting AVD options\n";
        $avd_options = $ENV{'ANDROID_AVD_OPTIONS'};
    }

    $self->KillAll ("emulator*");
    # create the AVD again
    # my $create_cmd = "$android_process" . ' -s create avd -f -n ' . "$avd_name $android_create_avd_options";

    # if (defined $ENV{'ACE_TEST_VERBOSE'}) {
    #     print STDERR "Create emulator cmd : $create_cmd\n";
    # }

    # system ( $create_cmd );

    # if ($? != 0) {
    #     print STDERR "failed to execute: $!\n";
    # }
    # else {
    #    print "AVD CREATED\n";
    # }

    # AVD created -> run the avd
    # since the emulator process blocks, we need to fork this process.

    FORK: {
        if ($self->{PROCESS} = fork) {
            #parent here
            bless $self;
        }
        elsif (defined $self->{PROCESS}) {
           #child here

           my $avd_cmd = "$avd_process" .' -avd ' .  "$avd_name $avd_options";
           if (defined $ENV{'ACE_TEST_VERBOSE'}) {
               print STDERR "Starting emulator cmd: $avd_cmd\n";
           }

           system ( $avd_cmd );
           if ($? != 0) {
               print STDERR "failed to execute: $!\n";
           }
           exit;
       }
       elsif ($! =~ /No more process/) {
            #EAGAIN, supposedly recoverable fork error
            sleep 5;
            redo FORK;
       }
       else {
           # weird fork error
           print STDERR "ERROR: Can't fork <" . $avd_process . ">: $!\n";
       }
    }

    my $wait_cmd = $adb_process . ' wait-for-device';
    system ( $wait_cmd );
    if (defined $ENV{'ACE_TEST_VERBOSE'}) {
        print STDERR "Emulator is running <$self->{PROCESS}> -> start the tests.\n";
    }

    # AVD is up and running and ready to spawn executables.
    # First some preparation.

    my $cmd = $adb_process . ' shell "mkdir ' . $self->{FSROOT} . '/tmp"';
    if (defined $ENV{'ACE_TEST_VERBOSE'}) {
        print STDERR "Start to execute : $cmd\n";
    }
    system ( $cmd );

    $self->{RUNNING} = 1;
    return 0;
}

sub ProcessStartWaitInterval ($)
{
    my $self = shift;
    my $wait_interval = $self->{PROCESS_START_WAIT_INTERVAL};

    return $wait_interval;
}

sub ProcessStopWaitInterval ($)
{
    my $self = shift;
    my $wait_interval = $self->{PROCESS_STOP_WAIT_INTERVAL};

    return $wait_interval;
}

sub WaitForFileTimed ($)
{
    my $self = shift;
    my $file = shift;
    my $timeout = shift;
    my $silent;

    if (!defined $ENV{'ACE_TEST_VERBOSE'}) {
      $silent = "2> /dev/null"
    }

    if ($PerlACE::Process::WAIT_DELAY_FACTOR > 0) {
        $timeout *= $PerlACE::Process::WAIT_DELAY_FACTOR;
    }

    my $newfile = $self->LocalFile ($file);
    if (defined $ENV{'ACE_TEST_VERBOSE'}) {
        print STDERR "Android waits $timeout seconds for $newfile\n";
    }

    # Since the file is available on the target (which we cannot reach),
    # we will try to pull the file from the target to a local directory.
    # If succeed, the the file is there an we can continue.
    my $adb_process = $ENV{'ANDROID_SDK_ROOT'} . "/platform-tools/adb";
    my $fsroot_target = $ENV{'ANDROID_FS_ROOT'};

    my $cmd_copy_ior = $adb_process . ' pull ' . $newfile . ' ' .
                          File::Spec->tmpdir() . '/' .
                          basename ($newfile) . ' $silent';

    while ($timeout-- != 0) {
        # copy the ior back to the host sytem
        if (system ( $cmd_copy_ior ) == 0) {
            if (defined $ENV{'ACE_TEST_VERBOSE'}) {
                print STDERR "Pull ior succeeded\n";
            }
            return 0;
        }
        sleep (1);
    }
    return -1;
}

sub DeleteFile ($)
{
    my $self = shift;
    my $file = shift;
    my $newfile = $self->LocalFile($file);
    if (defined $ENV{'ACE_TEST_VERBOSE'}) {
        print STDERR "delete $newfile\n";
    }
    unlink ("$newfile");
}

sub Kill ()
{
    my $self = shift;

    if ($self->{RUNNING} == 1) {
        if (defined $ENV{'ACE_TEST_VERBOSE'}) {
            print STDERR "Killing emulator process <$self->{PROCESS}>\n";
        }

        my $cnt = kill (1, $self->{PROCESS});

        waitpid ($self->{PROCESS}, WNOHANG);
        if (defined $ENV{'ACE_TEST_VERBOSE'}) {
            print STDERR "Killed $cnt process(es)\n";
        }
        # $self->check_return_value ($?);
    }

    $self->{RUNNING} = 0;
}

sub KillAll ($)
{
    my $self = shift;
    my $procmask = shift;
    if ($OSNAME eq 'MSWin32') {
        if (defined $ENV{'ACE_TEST_VERBOSE'}) {
            print STDERR "Killall not implemented for Windows\n";
            return;
        }
    }
    else {
        my $cmd_killall = "killall -q -r $procmask";
        system ( $cmd_killall );
    }
}

sub PutFile ($)
{
    my $self = shift;
    my $src = shift;
    my $dest = shift;
    my $silent;

    if (!defined $ENV{'ACE_TEST_VERBOSE'}) {
      $silent = "2> /dev/null"
    }

    my $adb_process = $ENV{'ANDROID_SDK_ROOT'} . "/platform-tools/adb";

    my $cmd = "$adb_process" . ' push '. "$src $dest $silent";

    if (defined $ENV{'ACE_TEST_VERBOSE'}) {
      print STDERR "PutFile cmd: $cmd\n";
    }

    system ( $cmd );
    if ($? != 0) {
        return -1;
    }
    return 0;
}

1;

