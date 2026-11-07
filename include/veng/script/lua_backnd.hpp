#pragma once

#include <string_view>


struct lua_State;


// If wrapper method has unsigned int overload
enum scriptStateMask : unsigned int {
    SV_State = 1 << 0,
    CL_State = 1 << 1,
};

enum scriptStateIdx{
    SV_State_Idx = 0,
    CL_State_Idx = 1,
};


class luaBaseState{
    lua_State* m_L = nullptr;
public:
    bool init();
    void doStr(std::string_view content);

    void reboot() { close(); init(); }
    void close();

    [[nodiscard]] lua_State* getRaw() const { return m_L; };
};


class luaScriptSys{
    luaBaseState m_states[2];
public:
    luaScriptSys() = default;
    ~luaScriptSys() { shutdown(SV_State_Idx | CL_State_Idx); }

    bool baseInit() {
        if (m_states[SV_State_Idx].init()){
            return m_states[CL_State_Idx].init();
        } else {
            return false;
        }
    }
    void apiInit();

    void shutdown(unsigned int states){
        if (states & SV_State) m_states[SV_State_Idx].close();
        if (states & CL_State) m_states[CL_State_Idx].close();
    }

    luaBaseState& getSt(scriptStateMask stateMask){
        if (stateMask == SV_State) return m_states[SV_State_Idx];
        else                       return m_states[CL_State_Idx];
    }
};