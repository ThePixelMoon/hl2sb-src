//========= Copyleft Planimeter, Some rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//
//=============================================================================//
#ifndef HL2SB_PLAYER_H
#define HL2SB_PLAYER_H
#ifdef _WIN32
#pragma once
#endif // _WIN32

#include "hl2mp/hl2mp_player.h"

class CHL2SB_Player : public CHL2MP_Player
{
	DECLARE_CLASS( CHL2SB_Player, CHL2MP_Player );

public:
	DECLARE_SERVERCLASS();
	DECLARE_DATADESC();
};

#endif // HL2Sb_PLAYER_H