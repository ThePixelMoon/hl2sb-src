//========= Copyleft Planimeter, Some rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//
//=============================================================================//
#ifndef LUAMGR_H
#define LUAMGR_H
#ifdef _WIN32
#pragma once
#endif // _WIN32

#include <lua.hpp>

class LuaManager final
{
	DECLARE_CLASS_NOBASE( LuaManager );

public:
	LuaManager();

	bool Initialize();
	void Shutdown();
};

extern LuaManager *g_pLuaManager;

#endif // LUAMGR_H