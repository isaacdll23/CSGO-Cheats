#include <thread>
#include "memory.h"
#include "cheats.h"
#include "offsets.h"
#include "menu.h"

#define KeyDown -32760;
#define KeyUp 0;

int main() {
	MemManager mem;
	const std::string targetProcess = "csgo.exe";
	const std::string targetModule = "client.dll";

	while (!mem.IsProcessRunning(targetProcess)) {
		PrintWaiting(targetProcess);
		Sleep(500);
	}

	PrintGameFound(targetProcess);

	mem.GetProcessID(targetProcess);
	mem.GetProcessHandle();
	mem.GetModuleBaseAddress(targetModule);

	mem.GetLocalPlayer();

	ClearScreen();
	PrintStatus();

	while (true) {
		
		// Menu Actions
		if (GetAsyncKeyState(VK_INSERT)) {
			bhopStatus = !bhopStatus;
			ClearScreen();
			PrintStatus();
			Sleep(300);
		}
		
		if (GetAsyncKeyState(VK_DELETE)) {
			triggerbotStatus = !triggerbotStatus;
			ClearScreen();
			PrintStatus();
			Sleep(300);
		}

		// Key Actions
		//BHOP
		if (GetAsyncKeyState(VK_SPACE) && bhopStatus) {
			if (isGrounded(mem) && isMoving(mem)) {
				ForceJump(mem);
			}
		}

		//TRIGGERBOT
		if (GetAsyncKeyState(VK_CAPITAL) && triggerbotStatus) {
			if (isOnTarget(mem)) {
				Sleep(5);
				Shoot(mem);
			}

		}
	}
}