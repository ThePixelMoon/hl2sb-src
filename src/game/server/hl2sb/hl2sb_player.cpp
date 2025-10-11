//========= Copyleft Planimeter, Some rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//
//=============================================================================//
#include "cbase.h"
#include "hl2sb_player.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

LINK_ENTITY_TO_CLASS( player, CHL2SB_Player );

LINK_ENTITY_TO_CLASS( info_player_combine, CPointEntity );
LINK_ENTITY_TO_CLASS( info_player_rebel, CPointEntity );

// specific to the local player
BEGIN_SEND_TABLE_NOBASE( CHL2SB_Player, DT_HL2SB_LocalPlayerExclusive )
	// send a hi-res origin to the local player for use in prediction
	SendPropVectorXY(SENDINFO(m_vecOrigin),               -1, SPROP_NOSCALE|SPROP_CHANGES_OFTEN, 0.0f, HIGH_DEFAULT, SendProxy_OriginXY ),
	SendPropFloat   (SENDINFO_VECTORELEM(m_vecOrigin, 2), -1, SPROP_NOSCALE|SPROP_CHANGES_OFTEN, 0.0f, HIGH_DEFAULT, SendProxy_OriginZ ),

	SendPropFloat( SENDINFO_VECTORELEM(m_angEyeAngles, 0), 8, SPROP_CHANGES_OFTEN, -90.0f, 90.0f ),
	SendPropAngle( SENDINFO_VECTORELEM(m_angEyeAngles, 1), 10, SPROP_CHANGES_OFTEN ),

END_SEND_TABLE()

// all players except the local player
BEGIN_SEND_TABLE_NOBASE( CHL2SB_Player, DT_HL2SB_NonLocalPlayerExclusive )
	// send a lo-res origin to other players
	SendPropVectorXY(SENDINFO(m_vecOrigin),               -1, SPROP_COORD_MP_LOWPRECISION|SPROP_CHANGES_OFTEN, 0.0f, HIGH_DEFAULT, SendProxy_OriginXY ),
	SendPropFloat   (SENDINFO_VECTORELEM(m_vecOrigin, 2), -1, SPROP_COORD_MP_LOWPRECISION|SPROP_CHANGES_OFTEN, 0.0f, HIGH_DEFAULT, SendProxy_OriginZ ),

	SendPropFloat( SENDINFO_VECTORELEM(m_angEyeAngles, 0), 8, SPROP_CHANGES_OFTEN, -90.0f, 90.0f ),
	SendPropAngle( SENDINFO_VECTORELEM(m_angEyeAngles, 1), 10, SPROP_CHANGES_OFTEN ),

END_SEND_TABLE()

IMPLEMENT_SERVERCLASS_ST(CHL2SB_Player, DT_HL2SB_Player)
	SendPropExclude( "DT_BaseEntity", "m_vecOrigin" ),

	// misyl:
	// m_flMaxspeed is fully predicted by the client and the client's
	// maxspeed is sent in the user message.
	// Other games like DOD, etc don't use this var at all and just fully
	// predict in GameMovement, but the HL2 codebase doesn't do that and modifies this
	// on the player.
	// So, just never send it, and don't predict it on the client either.
	SendPropExclude( "DT_BasePlayer", "m_flMaxspeed" ),


	// Data that only gets sent to the local player
	SendPropDataTable( "hl2sblocaldata", 0, &REFERENCE_SEND_TABLE( DT_HL2SB_LocalPlayerExclusive ), SendProxy_SendLocalDataTable ),

	// Data that gets sent to all other players
	SendPropDataTable( "hl2sbnonlocaldata", 0, &REFERENCE_SEND_TABLE( DT_HL2SB_NonLocalPlayerExclusive ), SendProxy_SendNonLocalDataTable ),

	SendPropEHandle( SENDINFO( m_hRagdoll ) ),
	SendPropInt( SENDINFO( m_iSpawnInterpCounter), 4 ),
	SendPropInt( SENDINFO( m_iPlayerSoundType), 3 ),
	
	SendPropExclude( "DT_BaseAnimating", "m_flPoseParameter" ),
	SendPropExclude( "DT_BaseFlex", "m_viewtarget" ),

//	SendPropExclude( "DT_ServerAnimationData" , "m_flCycle" ),	
//	SendPropExclude( "DT_AnimTimeMustBeFirst" , "m_flAnimTime" ),	
END_SEND_TABLE()

BEGIN_DATADESC( CHL2SB_Player )
END_DATADESC()
