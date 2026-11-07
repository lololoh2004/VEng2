#include "mswlua/c_api/doScript_funcs.hpp"
#include "veng/script/lua_backnd.hpp"


void luaBaseState::doStr(std::string_view content){
    if (m_L == nullptr) return;
    doScriptStr(m_L, content);
}
