/* This may look like C code, but it is really -*- C++ -*- */
// $Id$

/* Copyright (C) 1989 Free Software Foundation, Inc.
   written by Douglas C. Schmidt (schmidt@ics.uci.edu)

This file is part of GNU GPERF.

GNU GPERF is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 1, or (at your option) any
later version.

GNU GPERF is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU GPERF; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111,
USA.  */

#include "Vectors.h"

#if defined (ACE_HAS_GPERF)

// Counts occurrences of each key set character.
int Vectors::occurrences[ALPHA_SIZE]; 

// Value associated with each character.
int Vectors::asso_values[ALPHA_SIZE]; 

#endif /* ACE_HAS_GPERF */
