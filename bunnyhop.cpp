#include "cheats.h"

void ForceJump(MemManager mem) {
	mem.WriteBase<DWORD>(dwForceJump, 6);
}

bool isGrounded(MemManager mem) {
	int val = mem.ReadPlayer<int>(m_fFlags);

	if (val == 257)
		return true;
	else
		return false;
}

bool isMoving(MemManager mem) {
	vector vel = mem.ReadPlayer<vector>(m_vecVelocity);
	float sum = vel.x + vel.y + vel.z;
	if (sum == 0)
		return false;
	else
		return true;
} 