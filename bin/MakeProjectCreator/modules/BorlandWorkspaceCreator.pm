package BorlandWorkspaceCreator;

# ************************************************************
# Description   : A Borland Workspace (Makefile.bor) creator
# Author        : Chad Elliott
# Create Date   : 7/02/2002
# ************************************************************

# ************************************************************
# Pragmas
# ************************************************************

use strict;
use File::Basename;

use BorlandProjectCreator;
use WorkspaceCreator;

use vars qw(@ISA);
@ISA = qw(WorkspaceCreator);

# ************************************************************
# Subroutine Section
# ************************************************************

sub workspace_file_name {
  my($self) = shift;
  if ($self->make_coexistence()) {
    return $self->get_modified_workspace_name('Makefile', '.bor');
  }
  else {
    return $self->get_modified_workspace_name('Makefile', '');
  }
}


sub workspace_per_project {
  #my($self) = shift;
  return 1;
}


sub pre_workspace {
  my($self) = shift;
  my($fh)   = shift;
  my($crlf) = $self->crlf();

  print $fh "#----------------------------------------------------------------------------$crlf" .
            "#       Borland Workspace$crlf" .
            "#----------------------------------------------------------------------------$crlf" .
            $crlf;
}


sub write_project_targets {
  my($self)   = shift;
  my($fh)     = shift;
  my($target) = shift;
  my($list)   = shift;
  my($crlf)   = $self->crlf();

  foreach my $project (@$list) {
    my($dir)    = dirname($project);
    my($chdir)  = 0;
    my($back)   = '';

    ## If the directory isn't "." then we need
    ## to figure out how to get back to our starting point
    if ($dir ne '.') {
      $chdir = 1;
      my($count)  = 0;
      my($length) = length($dir);
      for(my $i = 0; $i < $length; $i++) {
        if (substr($dir, $i, 1) eq '/') {
          $count++;
        }
      }
      if ($dir =~ /^\.\.\//) {
        $back = ('../' x $count) . basename($self->getcwd());
      }
      else {
        $back = ('../' x ($count + 1));
      }
    }

    print $fh ($chdir ? "\t\@cd $dir$crlf" : '') .
              "\t\$(MAKE) -\$(MAKEFLAGS) \$(MAKE_FLAGS) -f " . basename($project) . " $target$crlf" .
              ($chdir ? "\t\@cd $back$crlf" : '');
  }
}


sub write_comps {
  my($self)     = shift;
  my($fh)       = shift;
  my($projects) = $self->get_projects();
  my($pjs)      = $self->get_project_info();
  my(%targnum)  = ();
  my(@list)     = $self->number_target_deps($projects, $pjs, \%targnum);
  my($crlf)     = $self->crlf();

  print $fh "!include <\$(ACE_ROOT)\\include\\makeinclude\\make_flags.bor>$crlf";

  ## Print out the "all" target
  print $fh $crlf . 'all:';
  foreach my $project (@list) {
    print $fh " $$pjs{$project}->[0]";
  }
  print $fh $crlf;

  ## Print out all other targets here
  foreach my $target ('clean', 'realclean', 'install') {
    print $fh $crlf .
              "$target\:$crlf";
    $self->write_project_targets($fh, $target, \@list);
  }

  ## Print out each target separately
  foreach my $project (@list) {
    my($dname) = dirname($project);
    print $fh $crlf . $$pjs{$project}->[0] . ':';
    if (defined $targnum{$project}) {
      foreach my $number (@{$targnum{$project}}) {
        print $fh " $$pjs{$list[$number]}->[0]";
      }
    }

    print $fh $crlf;
    $self->write_project_targets($fh, 'all', [ $project ]);
  }

  ## Print out the project_name_list target
  print $fh $crlf . "project_name_list:$crlf";
  foreach my $project (sort @list) {
    print $fh "\t\@echo $$pjs{$project}->[0]$crlf";
  }
}



1;
