#pragma once


class  strScript;
struct lua_State;

enum scriptStateMask : unsigned int {
    SV_State = 1 << 0,
    CL_State = 1 << 1,
};

enum scriptStateIdx{
    SV_State_Idx = 0,
    CL_State_Idx = 1,
};


class luaStateWrapp{
    lua_State* m_L = nullptr;
public:
    luaStateWrapp();
    ~luaStateWrapp() { close(); }

    void reboot();
    void close();

    [[nodiscard]] lua_State* raw() const { return m_L; }
    operator lua_State*()          const { return m_L; }
    explicit operator bool()       const { return m_L != nullptr; }
};


struct luaScriptSys{
    luaStateWrapp sv;
    luaStateWrapp cl;

    void initAPI();
};