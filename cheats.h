#ifndef CHEATS_H
#define CHEATS_H
#include "memory.h"
#include "offsets.h"

struct vector {
	float x, y, z;
};

struct GlowStruct {
	BYTE firstBuffer[4];
	float r;
	float g;
	float b;
	float a;
	BYTE secondBuffer[16];
	bool renderWhenOccluded;
	bool renderWhenUnoccluded;
	bool fullBloom;
	BYTE thirdBuffer[5];
	int glowStyle;
};

extern bool bhopStatus;
extern bool triggerbotStatus;
extern bool keyHeld;
extern bool wallhackStatus;

// BHOPS
void ForceJump(MemManager);
bool isGrounded(MemManager);
bool isMoving(MemManager);


// TRIGGERBOT
extern int myTeam;
void Shoot(MemManager);
bool isOnTarget(MemManager);

// WALLHACK
GlowStruct SetEnemyColor(MemManager, GlowStruct, DWORD);
GlowStruct SetTeamColor(MemManager, GlowStruct);
void UpdateGlow(MemManager);

#endif // !CHEATS_H
