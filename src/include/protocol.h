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
#ifndef _PROTOCOL_H
#  define _PROTOCOL_H

/**
 * @file
 *
 * Protocol specifics
 *
 */

extern winvblock__bool STDCALL Protocol_SearchNIC (
  IN winvblock__uint8_ptr Mac
 );
extern winvblock__uint32 STDCALL Protocol_GetMTU (
  IN winvblock__uint8_ptr Mac
 );
extern winvblock__bool STDCALL Protocol_Send (
  IN winvblock__uint8_ptr SourceMac,
  IN winvblock__uint8_ptr DestinationMac,
  IN winvblock__uint8_ptr Data,
  IN winvblock__uint32 DataSize,
  IN void *PacketContext
 );
extern NTSTATUS Protocol_Start (
  void
 );
extern void Protocol_Stop (
  void
 );

#endif				/* _PROTOCOL_H */
