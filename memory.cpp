#include "memory.h"
#include "offsets.h"

bool MemManager::IsProcessRunning(const std::string &processName) {
	bool isRunning = false;

	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);
	const HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	// Check if process can be loaded onto entry, else terminate
	if (!Process32First(snap, &entry)) {
		CloseHandle(snap);
		return false;
	}

	// If loading was succesful, find entry with process name
	do {
		if (!strcmp(entry.szExeFile, processName.c_str())){
			CloseHandle(snap);
			isRunning = true;
			break;
		}
	} while (Process32Next(snap, &entry));

	return isRunning;
}

void MemManager::GetProcessID(const std::string &processName) {
	
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);
	HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	// Check if process can be loaded onto entry, else terminate
	if (!Process32First(snap, &entry)) {
		CloseHandle(snap);
		return;
	}

	// If loading was succesful, find entry with process name and return pid
	do {
		if (!strcmp(entry.szExeFile, processName.c_str())) {
			MemManager::dw_pid = entry.th32ProcessID;
			std::cout << "PID found and stored\n";
			CloseHandle(snap);
			return;
		}
	} while (Process32Next(snap, &entry));

	CloseHandle(snap);
}

void MemManager::GetProcessHandle() {
	MemManager::processHandle = OpenProcess(ProcessAccess::ReadWrite, FALSE, dw_pid);
}

void MemManager::GetModuleBaseAddress(const std::string &moduleName) {
	MODULEENTRY32 entry;
	entry.dwSize = sizeof(MODULEENTRY32);
	HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE32 | TH32CS_SNAPMODULE, dw_pid);

	// Check if module can be loaded onto entry, else terminate
	if (!Module32First(snap, &entry)) {
		std::cout << "Closing Handle\n";
		CloseHandle(snap);
		return;
	}

	// If loading was succesful, find module with target module name and store base address
	do {
		if (!strcmp(entry.szModule, moduleName.c_str())) {
			MemManager::baseAddress = (DWORD)entry.modBaseAddr;
			std::cout << "Module base address found\n";
			CloseHandle(snap);
			return;
		}
	} while (Module32Next(snap, &entry));
	std::cout << "Module not found\n";
	CloseHandle(snap);
}


void MemManager::GetLocalPlayer() {
	do {
		MemManager::localPlayer = ReadBase<DWORD>(dwLocalPlayer);
	} while (localPlayer == NULL);
}