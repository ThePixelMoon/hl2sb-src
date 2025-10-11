//========= Copyleft Planimeter, Some rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//
//=============================================================================//
#ifndef LINIT_H
#define LINIT_H
#ifdef _WIN32
#pragma once
#endif // _WIN32

#define LUA_BASENAME "_G"
LUALIB_API int luaopen_base (lua_State *L);

LUALIB_API void lua_openall (lua_State *L);

#endif // LINIT_H