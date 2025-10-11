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

	static CHL2SB_Player *CreatePlayer( const char *className, edict_t *ed )
	{
		CHL2SB_Player::s_PlayerEdict = ed;
		return (CHL2SB_Player*)CreateEntityByName( className );
	}

};

inline CHL2SB_Player *ToHL2SBPlayer( CBaseEntity *pEntity )
{
	if ( !pEntity || !pEntity->IsPlayer() )
		return NULL;

	return dynamic_cast<CHL2SB_Player*>( pEntity );
}

#endif // HL2Sb_PLAYER_H