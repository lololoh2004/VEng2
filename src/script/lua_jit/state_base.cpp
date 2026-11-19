#include "veng/script/lua_jit.hpp"

extern "C"{
#include "lua.h"
#include "lauxlib.h"
}


luaStateWrapp::luaStateWrapp(){
    m_L = luaL_newstate();
}

void luaStateWrapp::close(){
    if (m_L == nullptr) return;

    lua_close(m_L);
    m_L = nullptr;
}

void luaStateWrapp::reboot(){
    close();
    m_L = luaL_newstate();
}
