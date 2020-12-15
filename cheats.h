#ifndef CHEATS_H
#define CHEATS_H
#include "memory.h"
#include "offsets.h"

struct vector {
	float x, y, z;

	vector operator+(vector v) {
		return { x + v.x, y + v.y, z + v.z };
	}
	vector operator-(vector v) {
		return { x - v.x, y - v.y, z - v.z };
	}
	vector operator*(float d) {
		return { x * d, y * d, z * d };
	}

	void Normalize() {
		while(y < -180.0f)
			y += 360.0f;

		while (y > 180.0f)
			y -= 360.0f;

		if (x > 89.0f)
			x = 89.0f;
		
		if (x < -89.0f)
			x = -89.0f;
	}
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
extern bool radarStatus;
extern bool rcsStatus;

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

// RADAR
void ToggleRadar(MemManager);

// RCS
void HandleRCS(MemManager);
void GetClientState(MemManager);

#endif // !CHEATS_H
