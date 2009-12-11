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
#ifndef _BUS_H
#  define _BUS_H

/**
 * @file
 *
 * Bus specifics
 *
 */

typedef struct _BUS_BUS
{
	PDEVICE_OBJECT LowerDeviceObject;
	PDEVICE_OBJECT PhysicalDeviceObject;
	ULONG Children;
	PDRIVER_DEVICEEXTENSION ChildList;
	KSPIN_LOCK SpinLock;
} BUS_BUS,
*PBUS_BUS;

extern NTSTATUS STDCALL Bus_Start (
	void
 );

extern VOID STDCALL Bus_Stop (
	void
 );

extern NTSTATUS STDCALL Bus_AddDevice (
	IN PDRIVER_OBJECT DriverObject,
	IN PDEVICE_OBJECT PhysicalDeviceObject
 );

extern IRPHandler_Declaration (
	Bus_DispatchPnP
 );

extern IRPHandler_Declaration (
	Bus_DispatchDeviceControl
 );

extern IRPHandler_Declaration (
	Bus_DispatchSystemControl
 );

extern VOID STDCALL Bus_AddTarget (
	IN PUCHAR ClientMac,
	IN PUCHAR ServerMac,
	USHORT Major,
	UCHAR Minor,
	LONGLONG LBASize
 );

extern VOID STDCALL Bus_CleanupTargetList (
	void
 );

extern NTSTATUS STDCALL Bus_GetDeviceCapabilities (
	IN PDEVICE_OBJECT DeviceObject,
	IN PDEVICE_CAPABILITIES DeviceCapabilities
 );

extern BOOLEAN STDCALL Bus_AddChild (
	IN PDEVICE_OBJECT BusDeviceObject,
	IN DISK_DISK Disk,
	IN BOOLEAN Boot
 );

extern PDEVICE_OBJECT Bus_Globals_Self;

#endif													/* _BUS_H */