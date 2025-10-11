//========= Copyleft Planimeter, Some rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//
//=============================================================================//
#ifndef C_HL2SB_PLAYER_H
#define C_HL2SB_PLAYER_H
#ifdef _WIN32
#pragma once
#endif // _WIN32

#include "hl2mp/c_hl2mp_player.h"

class C_HL2SB_Player : public C_HL2MP_Player
{
	DECLARE_CLASS( C_HL2SB_Player, C_HL2MP_Player );

public:
	DECLARE_CLIENTCLASS();
	DECLARE_PREDICTABLE();
	DECLARE_INTERPOLATION();
};

#endif // C_HL2Sb_PLAYER_H