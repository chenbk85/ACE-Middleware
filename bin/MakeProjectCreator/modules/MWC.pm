package MWC;

# ******************************************************************
# Description : Instantiate a Driver and run it
# Author      : Chad Elliott
# Create Date : 1/30/2004
# ******************************************************************

# ******************************************************************
# Pragma Section
# ******************************************************************

use strict;
use Driver;

# ************************************************************
# Subroutine Section
# ************************************************************

sub new {
  my($class) = shift;
  my($self)  = bless {'creators' => [ 'GNUACEWorkspaceCreator',
                                      'NMakeWorkspaceCreator',
                                      'VC6WorkspaceCreator',
                                      'VC7WorkspaceCreator',
                                      'VC71WorkspaceCreator',
                                      'BorlandWorkspaceCreator',
                                      'GHSWorkspaceCreator',
                                      'EM3WorkspaceCreator',
                                      'VA4WorkspaceCreator',
                                      'MakeWorkspaceCreator',
                                      'AutomakeWorkspaceCreator',
                                      'BMakeWorkspaceCreator',
                                    ],
                     }, $class;
  return $self;
}


sub getCreatorList {
  my($self) = shift;
  return $self->{'creators'};
}


sub execute {
  my($self)   = shift;
  my($base)   = shift;
  my($name)   = shift;
  my($args)   = shift;
  my($driver) = new Driver($base, $name, @{$self->{'creators'}});
  return $driver->run(@$args);
}


1;
