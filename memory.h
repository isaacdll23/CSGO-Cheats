#pragma once
#ifndef MEMORY_H
#define MEMORY_H

#include <Windows.h>
#include <TlHelp32.h>
#include <string>
#include <algorithm>
#include <tchar.h>
#include <iostream>

enum ProcessAccess : DWORD{
	Full = PROCESS_ALL_ACCESS,
	ReadOnly = PROCESS_VM_OPERATION | PROCESS_VM_READ,
	WriteOnly = PROCESS_VM_OPERATION | PROCESS_VM_WRITE,
	ReadWrite = ReadOnly | WriteOnly
};

class MemManager {
	private:
		DWORD dw_pid;
		HANDLE processHandle;
		DWORD localPlayer;

	public:
		DWORD clientBaseAddress;
		DWORD engineBaseAddress;
		bool IsProcessRunning(const std::string &);
		void GetProcessID(const std::string &);
		void GetProcessHandle();
		void GetModuleBaseAddress(const std::string &, DWORD &);
		void GetLocalPlayer();
		
		template<class cData>
		cData ReadBase(DWORD address) {
			cData value;
			ReadProcessMemory(MemManager::processHandle, LPVOID(MemManager::clientBaseAddress + address), &value, sizeof(cData), NULL);
			return value;
		}

		template<class cData>
		cData ReadPlayer(DWORD address) {
			cData value;
			ReadProcessMemory(MemManager::processHandle, LPVOID(MemManager::localPlayer + address), &value, sizeof(cData), NULL);
			return value;
		}

		template<class cData>
		cData Read(DWORD address) {
			cData value;
			ReadProcessMemory(MemManager::processHandle, LPVOID(address), &value, sizeof(cData), NULL);
			return value;
		}

		template<class cData>
		void WriteBase(DWORD address, cData value) {
			WriteProcessMemory(MemManager::processHandle, LPVOID(MemManager::clientBaseAddress + address), &value, sizeof(cData), NULL);
		}

		template<class cData>
		void WritePlayer(DWORD address, cData value) {
			WriteProcessMemory(MemManager::processHandle, LPVOID(MemManager::localPlayer + address), &value, sizeof(cData), NULL);
		}

		template<class cData>
		void Write(DWORD address, cData value) {
			WriteProcessMemory(MemManager::processHandle, LPVOID(address), &value, sizeof(cData), NULL);
		}
};

#endif // !MEMORY_H

