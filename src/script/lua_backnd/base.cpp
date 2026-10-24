#include "veng/script/lua_backnd.hpp"

#include "lo_utils/common/defines.h"
#include "mswlua/c_api/init.hpp"
#include "mswlua/c_api/openLib_funcs.hpp"


void luaScriptSys::shutdown(){
    closeLuaState(m_L);
}

bool luaScriptSys::baseInit(){
    m_L = getLuaState();
    if (m_L == nullptr) return RETURN_FAILURE;

    openLibs(m_L);
    return RETURN_SUCCESS;
}