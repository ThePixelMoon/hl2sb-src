//========= Copyleft Planimeter, Some rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//
//=============================================================================//
#include "cbase.h"
#include "luamgr.h"
#include "linit.h"
#include "tier1/utlstring.h"

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
	m_pL = luaL_newstate();
	luaL_openlibs(m_pL);

	// @ThePixelMoon: now, we open everything else
	lua_openall(m_pL);

	/*Dev*/Msg( "Lua initialized (%s | %s)\n", LUA_VERSION, LUAJIT_VERSION );

	return true;
}

void LuaManager::Shutdown()
{

}

bool LuaManager::doString( const char* m_szString )
{
    int loadStatus = luaL_loadstring(m_pL, m_szString);
    if (loadStatus != 0)
    {
        Warning("Lua load error: %s\n", lua_tostring(m_pL, -1));
        lua_pop(m_pL, 1);
        return false;
    }

    int callStatus = lua_pcall(m_pL, 0, LUA_MULTRET, 0);
    if (callStatus != 0)
    {
        Warning("Lua runtime error: %s\n", lua_tostring(m_pL, -1));
        lua_pop(m_pL, 1);

		return false;
    }

	return true;
}

void Lua_DoString(const CCommand &args)
{
    if (args.ArgC() < 2)
    {
        Msg("Usage: lua_dostring <lua code>\n");
        return;
    }

    CUtlString luaCode;
    for (int i = 1; i < args.ArgC(); i++)
    {
        luaCode += args[i];
        if (i != args.ArgC() - 1)
            luaCode += " ";
    }

	g_pLuaManager->doString(luaCode.Get());
}

