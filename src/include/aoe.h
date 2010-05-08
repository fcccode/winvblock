/**
 * Copyright (C) 2009, Shao Miller <shao.miller@yrdsb.edu.on.ca>.
 * Copyright 2006-2008, V.
 * For WinAoE contact information, see http://winaoe.org/
 *
 * This file is part of WinVBlock, derived from WinAoE.
 *
 * WinVBlock is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * WinVBlock is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with WinVBlock.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _AOE_H
#  define _AOE_H

/**
 * @file
 *
 * AoE specifics
 *
 */

/* TODO: Remove this inclusion when the time is right */
#  include "aoe_ioctl.h"

#  define htons(x) (winvblock__uint16)((((x) << 8) & 0xff00) | \
                                       (((x) >> 8) & 0xff))
#  define ntohs(x) (winvblock__uint16)((((x) << 8) & 0xff00) | \
                                       (((x) >> 8) & 0xff))

extern NTSTATUS STDCALL aoe__reply (
  IN winvblock__uint8_ptr SourceMac,
  IN winvblock__uint8_ptr DestinationMac,
  IN winvblock__uint8_ptr Data,
  IN winvblock__uint32 DataSize
 );
extern void AoE_ResetProbe (
  void
 );
extern NTSTATUS AoE_Start (
  void
 );
extern void AoE_Stop (
  void
 );
extern void aoe__process_abft (
  void
 );

#endif				/* _AOE_H */
