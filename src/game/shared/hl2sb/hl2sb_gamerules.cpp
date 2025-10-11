//========= Copyleft Planimeter, Some rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//
//=============================================================================//
#include "cbase.h"
#include "hl2sb_gamerules.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

REGISTER_GAMERULES_CLASS( CHL2SBRules );

BEGIN_NETWORK_TABLE_NOBASE( CHL2SBRules, DT_HL2SBRules )

	#ifdef CLIENT_DLL
		RecvPropBool( RECVINFO( m_bTeamPlayEnabled ) ),
	#else
		SendPropBool( SENDINFO( m_bTeamPlayEnabled ) ),
	#endif

END_NETWORK_TABLE()

LINK_ENTITY_TO_CLASS( hl2sb_gamerules, CHL2SBGameRulesProxy );
IMPLEMENT_NETWORKCLASS_ALIASED( HL2SBGameRulesProxy, DT_HL2SBGameRulesProxy )


#ifdef CLIENT_DLL
	void RecvProxy_HL2SBRules( const RecvProp *pProp, void **pOut, void *pData, int objectID )
	{
		CHL2SBRules *pRules = HL2SBRules();
		Assert( pRules );
		*pOut = pRules;
	}

	BEGIN_RECV_TABLE( CHL2SBGameRulesProxy, DT_HL2SBGameRulesProxy )
		RecvPropDataTable( "hl2sb_gamerules_data", 0, 0, &REFERENCE_RECV_TABLE( DT_HL2SBRules ), RecvProxy_HL2SBRules )
	END_RECV_TABLE()
#else
	void* SendProxy_HL2SBRules( const SendProp *pProp, const void *pStructBase, const void *pData, CSendProxyRecipients *pRecipients, int objectID )
	{
		CHL2SBRules *pRules = HL2SBRules();
		Assert( pRules );
		return pRules;
	}

	BEGIN_SEND_TABLE( CHL2SBGameRulesProxy, DT_HL2SBGameRulesProxy )
		SendPropDataTable( "hl2sb_gamerules_data", 0, &REFERENCE_SEND_TABLE( DT_HL2SBRules ), SendProxy_HL2SBRules )
	END_SEND_TABLE()
#endif
