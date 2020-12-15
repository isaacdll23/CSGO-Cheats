#include "cheats.h"


DWORD clientState;
vector viewAngles;
vector oldPunchAngle = {0, 0, 0};

void GetClientState(MemManager mem) {
	clientState = mem.Read<DWORD>(mem.engineBaseAddress + dwClientState);
}

void HandleRCS(MemManager mem) {
	vector aimPunchAngle = mem.ReadPlayer<vector>(m_aimPunchAngle);
	int shotsFired = mem.ReadPlayer<int>(m_iShotsFired);
	viewAngles = mem.Read<vector>(clientState + dwClientState_ViewAngles);
	vector punchAngle = aimPunchAngle * 2.0f;

	if (shotsFired > 1) {
		vector newAngle = viewAngles + (oldPunchAngle - punchAngle);
		newAngle.Normalize();

		mem.Write<vector>(clientState + dwClientState_ViewAngles, newAngle);
		 
		oldPunchAngle = punchAngle;
	}
	else {
		oldPunchAngle = {0, 0, 0};
	}
}