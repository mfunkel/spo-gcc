/* Core target definitions for GNU compiler
   for IBM RS/6000 PowerPC targeted to embedded ELF systems.
   Copyright (C) 1995 Free Software Foundation, Inc.
   Contributed by Cygnus Support.

This file is part of GNU CC.

GNU CC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU CC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU CC; see the file COPYING.  If not, write to
the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* eABI local switches */
/* Set PCC_BITFIELD_TYPE_MATTERS to 0 to ignore the type of bitfields
   when calculating alignment.  */
#define	MASK_NO_BITFIELD_TYPE	0x40000000

#define	TARGET_NO_BITFIELD_TYPE	(target_flags & MASK_NO_BITFIELD_TYPE)
#define	TARGET_BITFIELD_TYPE	(! TARGET_NO_BITFIELD_TYPE)

#define SUBTARGET_SWITCHES						\
  { "bit-align",	-MASK_NO_BITFIELD_TYPE },			\
  { "no-bit-align",	 MASK_NO_BITFIELD_TYPE },

#include "rs6000/sysv4.h"

/* For now, make stabs the default debugging type, not dwarf. */
#undef	PREFERRED_DEBUGGING_TYPE
#define PREFERRED_DEBUGGING_TYPE DBX_DEBUG

/* Make int foo : 8 not cause structures to be aligned to an int boundary */

#undef	PCC_BITFIELD_TYPE_MATTERS
#define	PCC_BITFIELD_TYPE_MATTERS (TARGET_BITFIELD_TYPE)

/* Align stack to 8 byte boundaries, rather than 16 bytes Sys V.4 uses */
#undef	STACK_BOUNDARY
#define	STACK_BOUNDARY	64

/* No data type wants to be aligned rounder than this.  */
#undef	BIGGEST_ALIGNMENT
#define BIGGEST_ALIGNMENT 64

#undef TARGET_VERSION
#define TARGET_VERSION fprintf (stderr, " (PowerPC Embedded)");

/* FIXME: These should actually indicate PowerPC, when there is some
   standard way of expressing that.  */
#undef CPP_PREDEFINES
#define CPP_PREDEFINES \
  "-DPPC -D__embedded__ -Asystem(embedded) -Acpu(powerpc) -Amachine(powerpc)"
