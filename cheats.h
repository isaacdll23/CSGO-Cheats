#ifndef CHEATS_H
#define CHEATS_H
#include "memory.h"
#include "offsets.h"

struct vector {
	float x, y, z;
};

extern bool bhopStatus;
extern bool triggerbotStatus;
extern bool keyHeld;

// BHOPS
void ForceJump(MemManager);
bool isGrounded(MemManager);
bool isMoving(MemManager);


// TRIGGERBOT
extern int myTeam;
void Shoot(MemManager);
bool isOnTarget(MemManager);


#endif // !CHEATS_H
