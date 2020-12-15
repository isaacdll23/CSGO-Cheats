#include <thread>
#include "memory.h"
#include "cheats.h"
#include "offsets.h"
#include "menu.h"

#define KeyDown -32768
#define KeyUp 0

int main() {
	MemManager mem;
	const std::string targetProcess = "csgo.exe";
	const std::string targetModule = "client.dll";
	const std::string targetModule2 = "engine.dll";

	while (!mem.IsProcessRunning(targetProcess)) {
		PrintWaiting(targetProcess);
		Sleep(500);
	}

	PrintGameFound(targetProcess);

	mem.GetProcessID(targetProcess);
	mem.GetProcessHandle();
	mem.GetModuleBaseAddress(targetModule, mem.clientBaseAddress);
	mem.GetModuleBaseAddress(targetModule2, mem.engineBaseAddress);
	mem.GetLocalPlayer();

	ClearScreen();
	PrintStatus();

	while (true) {

		/* Menu Actions */
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

		if (GetAsyncKeyState(VK_HOME)) {
			wallhackStatus = !wallhackStatus;
			ClearScreen();
			PrintStatus();
			Sleep(300);
		}

		if (GetAsyncKeyState(VK_END)) {
			radarStatus = !radarStatus;
			ClearScreen();
			PrintStatus();
			Sleep(300);
		}

		if (GetAsyncKeyState(VK_PRIOR)) {
			rcsStatus = !rcsStatus;
			GetClientState(mem);
			ClearScreen();
			PrintStatus();
			Sleep(300);
		}

		/* Key Actions */
		// BHOP
		if (GetAsyncKeyState(VK_SPACE) && bhopStatus) {
			if (isGrounded(mem) && isMoving(mem)) {
				ForceJump(mem);
			}
		}

		// TRIGGERBOT
		if (GetAsyncKeyState(VK_MENU) == KeyDown && triggerbotStatus) {
			if (!keyHeld) {
				keyHeld = true;
			}

			if (isOnTarget(mem) && keyHeld) {
				Sleep(15);
				Shoot(mem);
			}
		}

		if (GetAsyncKeyState(VK_MENU) == KeyUp && triggerbotStatus) {
			if (keyHeld) {
				keyHeld = false;
			}
		}

		// WALLHACK
		if (wallhackStatus) {
			UpdateGlow(mem);
		}

		// RADAR
		if (radarStatus) {
			ToggleRadar(mem);
		}
		// RCS
		if (rcsStatus) {
			HandleRCS(mem);
		}
	}
}