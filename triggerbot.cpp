#include "cheats.h"

int myTeam = 0;

void Shoot(MemManager mem) {
	mem.WriteBase<int>(dwForceAttack, 5);
	int delay = rand() % 25 + 10;
	Sleep(delay);
	mem.WriteBase<int>(dwForceAttack, 4);
}

bool isOnTarget(MemManager mem) {
	int crosshairId = mem.ReadPlayer<int>(m_iCrosshairId);
	myTeam = mem.ReadPlayer<int>(m_iTeamNum);

	if (crosshairId != 0 && crosshairId < 64) {
		DWORD entity = mem.ReadBase<DWORD>(dwEntityList + ((crosshairId - 1) * 0x10));
		int	entityTeam = mem.Read<int>(entity + m_iTeamNum);
		int entityHealth = mem.Read<int>(entity + m_iHealth);

		if (entityTeam != myTeam && entityHealth > 0)
			return true;
		else
			return false;
	}
	
	return false;
}