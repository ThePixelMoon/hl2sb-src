//========= Copyleft Planimeter, Some rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//
//=============================================================================//
#include "cbase.h"
#include "c_hl2sb_player.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

LINK_ENTITY_TO_CLASS( player, C_HL2SB_Player );

// specific to the local player
BEGIN_RECV_TABLE_NOBASE( C_HL2SB_Player, DT_HL2SBLocalPlayerExclusive )
	RecvPropVectorXY( RECVINFO_NAME( m_vecNetworkOrigin, m_vecOrigin ) ),
	RecvPropFloat( RECVINFO_NAME( m_vecNetworkOrigin[2], m_vecOrigin[2] ) ),

	RecvPropFloat( RECVINFO( m_angEyeAngles[0] ) ),
	RecvPropFloat( RECVINFO( m_angEyeAngles[1] ) ),
END_RECV_TABLE()

// all players except the local player
BEGIN_RECV_TABLE_NOBASE( C_HL2SB_Player, DT_HL2SBNonLocalPlayerExclusive )
	RecvPropVectorXY( RECVINFO_NAME( m_vecNetworkOrigin, m_vecOrigin ) ),
	RecvPropFloat( RECVINFO_NAME( m_vecNetworkOrigin[2], m_vecOrigin[2] ) ),

	RecvPropFloat( RECVINFO( m_angEyeAngles[0] ) ),
	RecvPropFloat( RECVINFO( m_angEyeAngles[1] ) ),
END_RECV_TABLE()

IMPLEMENT_CLIENTCLASS_DT(C_HL2SB_Player, DT_HL2SB_Player, CHL2SB_Player)
	RecvPropDataTable( "hl2sblocaldata", 0, 0, &REFERENCE_RECV_TABLE( DT_HL2SBLocalPlayerExclusive ) ),
	RecvPropDataTable( "hl2sbnonlocaldata", 0, 0, &REFERENCE_RECV_TABLE( DT_HL2SBNonLocalPlayerExclusive ) ),

	RecvPropEHandle( RECVINFO( m_hRagdoll ) ),
	RecvPropInt( RECVINFO( m_iSpawnInterpCounter ) ),
	RecvPropInt( RECVINFO( m_iPlayerSoundType) ),

	RecvPropBool( RECVINFO( m_fIsWalking ) ),
END_RECV_TABLE()

BEGIN_PREDICTION_DATA( C_HL2SB_Player )
	DEFINE_PRED_FIELD( m_fIsWalking, FIELD_BOOLEAN, FTYPEDESC_INSENDTABLE ),

	// misyl: Ammo is server side entities in HL2SB. Not catastrophic to error about.
	// Just let the server stomp all over us.
	//
	// There is 1 instance in which is can be a runaway pred error, and that is if you have eg. ar2
	// with just altfire ammo, and get new ammo and we force reload. But the additional pred error sorts that out itself
	// without this for every pickup which is 1000% more common.
	DEFINE_PRED_ARRAY( m_iAmmo, FIELD_INTEGER, MAX_AMMO_TYPES, FTYPEDESC_INSENDTABLE | FTYPEDESC_OVERRIDE | FTYPEDESC_NOERRORCHECK ),
END_PREDICTION_DATA()
