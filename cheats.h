#ifndef CHEATS_H
#define CHEATS_H
#include "memory.h"
#include "offsets.h"

struct vector {
	float x, y, z;
};

struct GlowStruct {
	std::int32_t m_nNextFreeSlot;		// 0x00
	std::uint32_t pEntity;				// 0x04
	float R;							// 0x08
	float G;							// 0x0C
	float B;							// 0x10
	float A;							// 0x14
	bool bAlphaCappedByRenderAlpha;		// 0x18
	BYTE pad0[0x3];				// 0x19 - pack 1 bool as 4 bytes
	float flAlphaFunctionOfMaxVelocity; // 0x1C
	float flBloomAmount;				// 0x20
	float flPulseOverdrive;				// 0x24
	bool bRenderWhenOccluded;			// 0x28
	bool bRenderWhenUnoccluded;			// 0x29
	bool bFullBloomRender;				// 0x2A
	BYTE pad1[0x1];				// 0x2B  - pack 3 bool as 4 bytes
	int iFullBloomStencilTestValue;		// 0x2C
	int nRenderStyle;					// 0x30
	int nSplitScreenSlot;				// 0x34




	//BYTE firstBuffer[4];
	//float r;
	//float g;
	//float b;
	//float a;
	//BYTE secondBuffer[16];
	//bool renderWhenOccluded;
	//bool renderWhenUnoccluded;
	//bool fullBloom;
	//BYTE thirdBuffer[5];
	//int glowStyle;
};

extern bool bhopStatus;
extern bool triggerbotStatus;
extern bool keyHeld;
extern bool wallhackStatus;
extern bool radarStatus;

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

#endif // !CHEATS_H
