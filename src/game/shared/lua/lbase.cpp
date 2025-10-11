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

static int base_print (lua_State *L) {
	Msg("%s\n", luaL_checkstring(L, 1));
	return 0;
}

static const luaL_Reg baselib[] = {
	{"print",   base_print},
	{NULL, NULL}
};

/*
** Open math library
*/
LUALIB_API int luaopen_base (lua_State *L)
{
	luaL_register(L, LUA_BASENAME, baselib);
	return 1;
}