#include "cheats.h"

GlowStruct SetEnemyColor(MemManager mem, GlowStruct glow, DWORD entity) {
	bool isDefusing = mem.Read<bool>(entity + m_bIsDefusing);

	if (isDefusing) {
		glow.R = 0.58f;
		glow.G = 0.20f;
		glow.B = 1.0f;	
	} else {
		int health = mem.Read<int>(entity + m_iHealth);
		glow.R = static_cast<float>(health * (-0.01) + 1);
		glow.G = static_cast<float>(health * 0.01);
	}

	glow.A = 0.65f;
	glow.bRenderWhenOccluded = true;
	glow.bRenderWhenUnoccluded = false;

	return glow;
}

GlowStruct SetTeamColor(MemManager mem, GlowStruct glow) {
	glow.R = 0.0f;
	glow.G = 0.0f;
	glow.B = 1.0f;
	glow.A = 0.65f;

	glow.bRenderWhenOccluded = true;
	glow.bRenderWhenUnoccluded = false;

	return glow;
}


void UpdateGlow(MemManager mem) {

	DWORD glowObject = mem.ReadBase<DWORD>(dwGlowObjectManager);
	myTeam = mem.ReadPlayer<int>(m_iTeamNum);

	for(int i = 0; i < 64; i++) {

		DWORD entity = mem.ReadBase<DWORD>(dwEntityList + (i * 0x10));
		if (entity != NULL) {
			int glowIndex = mem.Read<int>(entity + m_iGlowIndex);
			int entityTeam = mem.Read<int>(entity + m_iTeamNum);
			if (entityTeam == myTeam) {
				GlowStruct teamGlow;
				teamGlow = mem.Read<GlowStruct>(glowObject + (glowIndex * 0x38));
				teamGlow = SetTeamColor(mem, teamGlow);
				mem.Write<GlowStruct>(glowObject + (glowIndex * 0x38), teamGlow);
			}
			else {
				GlowStruct enemyGlow;
				enemyGlow = mem.Read<GlowStruct>(glowObject + (glowIndex * 0x38));
				enemyGlow = SetEnemyColor(mem, enemyGlow, entity);
				mem.Write<GlowStruct>(glowObject + (glowIndex * 0x38), enemyGlow);
			}
		}
	}
}
 