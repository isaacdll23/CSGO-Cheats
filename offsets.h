#ifndef OFFSETS_H
#define OFFSETS_H
#include <Windows.h>

// BHOPS
extern DWORD m_fFlags;
extern DWORD dwForceJump;
extern DWORD m_vecVelocity;

// TRIGGERBOT
extern DWORD m_iHealth;
extern DWORD dwForceAttack;
extern DWORD m_iCrosshairId;
extern DWORD dwEntityList;;
extern DWORD m_iTeamNum;

// WALLHACK
extern DWORD m_iGlowIndex;
extern DWORD dwGlowObjectManager;
extern DWORD m_bIsDefusing;

// RADAR
extern DWORD m_bSpotted;

// RCS
extern DWORD m_aimPunchAngle;
extern DWORD dwClientState;
extern DWORD dwClientState_ViewAngles;
extern DWORD m_iShotsFired;

#endif // !OFFSETS_H
