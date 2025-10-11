//========= Copyleft Planimeter, Some rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//
//=============================================================================//
#ifndef HL2SB_GAMERULES_H
#define HL2SB_GAMERULES_H
#ifdef _WIN32
#pragma once
#endif // _WIN32

#include "hl2mp/hl2mp_gamerules.h"


#ifdef CLIENT_DLL
	#define CHL2SBRules C_HL2SBRules
	#define CHL2SBGameRulesProxy C_HL2SBGameRulesProxy
#endif

class CHL2SBGameRulesProxy : public CHL2MPGameRulesProxy
{
public:
	DECLARE_CLASS( CHL2MPGameRulesProxy, CHL2MPGameRulesProxy );
	DECLARE_NETWORKCLASS();
};

class CHL2SBRules : public CHL2MPRules
{
	DECLARE_CLASS( CHL2SBRules, CHL2MPRules );

public:
#ifdef CLIENT_DLL
	DECLARE_CLIENTCLASS_NOBASE(); // This makes datatables able to access our private vars.
#else
	DECLARE_SERVERCLASS_NOBASE(); // This makes datatables able to access our private vars.
#endif
};

inline CHL2SBRules* HL2SBRules()
{
	return static_cast<CHL2SBRules*>(g_pGameRules);
}

#endif // HL2SB_GAMERULES_H