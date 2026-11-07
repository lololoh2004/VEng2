#include "veng/script/lua_backnd.hpp"

#include "mswlua/c_api/init.hpp"
#include "mswlua/c_api/openLib_funcs.hpp"


void luaBaseState::close(){
    closeLuaState(m_L);
    m_L = nullptr;
}

bool luaBaseState::init(){
    m_L = getLuaState();
    if (m_L == nullptr) return false;

    openLibs(m_L);
    return true;
}