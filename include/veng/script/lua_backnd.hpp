#pragma once


struct lua_State;

class luaScriptSys{
    lua_State* m_L = nullptr;
public:
    luaScriptSys() = default;
    ~luaScriptSys() { shutdown(); }

    bool baseInit();
    void apiInit();

    void shutdown();
};