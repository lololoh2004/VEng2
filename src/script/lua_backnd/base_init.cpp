#include "veng/script/lua_backnd.hpp"

#include "mswlua/c_api/lua_state_wrap.hpp"
#include "mswlua/c_api/open_libs.hpp"


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