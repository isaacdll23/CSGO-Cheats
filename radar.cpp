#include "cheats.h"

void ToggleRadar(MemManager mem) {
	for (int i = 0; i < 64; i++) {

		DWORD entity = mem.ReadBase<DWORD>(dwEntityList + (i * 0x10));
		if (entity != NULL) {
			bool isSpotted = mem.Read<bool>(entity + m_bSpotted);
			int entityTeam = mem.Read<int>(entity + m_iTeamNum);

			if (entityTeam != myTeam) {
				mem.Write<bool>(entity + m_bSpotted, true);
			}
		}
	}
}