package EM3WorkspaceCreator;

# ************************************************************
# Description   : An eMbedded v3 Workspace Creator
# Author        : Chad Elliott
# Create Date   : 7/3/2002
# ************************************************************

# ************************************************************
# Pragmas
# ************************************************************

use strict;

use EM3ProjectCreator;
use VC6WorkspaceCreator;

use vars qw(@ISA);
@ISA = qw(VC6WorkspaceCreator);

# ************************************************************
# Subroutine Section
# ************************************************************


sub workspace_file_name {
  my($self) = shift;
  return $self->get_modified_workspace_name($self->get_workspace_name(),
                                            '.vcw');
}


sub pre_workspace {
  my($self) = shift;
  my($fh)   = shift;
  my($crlf) = $self->crlf();

  print $fh 'Microsoft eMbedded Visual Tools Workspace File, Format Version 3.00', $crlf,
            '#', $crlf,
            '# $Id$', $crlf,
            '#', $crlf,
            '# This file was generated by MPC.  Any changes made directly to', $crlf,
            '# this file will be lost the next time it is generated.', $crlf,
            '#', $crlf,
            '# MPC Command:', $crlf,
            "# $0 @ARGV", $crlf,
            $crlf;
}


1;
