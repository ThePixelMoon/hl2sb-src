//========= Copyleft Planimeter, Some rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//
//=============================================================================//
#include "cbase.h"
#include "luamgr.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

LuaManager *g_pLuaManager = nullptr;

#ifndef LUA_SDK
#error "LUA_SDK definition must be added in order for Lua implementation to work!"
#endif // !LUA_SDK

LuaManager::LuaManager()
{

}

bool LuaManager::Initialize()
{
	DevMsg( "Lua initialized (%s | %s)\n", LUA_VERSION, LUAJIT_VERSION );

	return true;
}

void LuaManager::Shutdown()
{

}