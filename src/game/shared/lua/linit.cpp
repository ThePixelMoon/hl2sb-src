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

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

static const luaL_Reg lua_alllibs[] = {
	{LUA_BASENAME, luaopen_base},
	{NULL, NULL}
};

LUALIB_API void lua_openall (lua_State *L)
{
	const luaL_Reg *lib = lua_alllibs;
	
	for (; lib->func; lib++)
	{
		lua_pushcfunction(L, lib->func);
		lua_pushstring(L, lib->name);
		lua_call(L, 1, 0);
	}
}