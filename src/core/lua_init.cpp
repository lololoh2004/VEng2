#include "veng/core/main_core.hpp"

#include "lo_utils/common/presets.h"
#include "lo_utils/cxx_wrap/term.hpp"

#include "mswlua/luaState/state.hpp"
#include "veng/lua/get_bind_code.hpp"


bool vEngine::initLua(){
    term::msg("Enter Lua api init..", "ENG", COLOR_GRAY);

    luaState state;
    state.openLibs();
    std::string apiCode = getCBind();

    term::msg(" - C bind result :", "ENG");
    printf("%s", apiCode.c_str());

    term::msg(" - Exec. bind..", "ENG", COLOR_GRAY);
    if (state.doScriptStr(apiCode)){
        term::msg(" - Success !!", "ENG", COLOR_GREEN);
        return RETURN_SUCCESS;
    } else {
        term::msg(" - Fail !!", "ENG", COLOR_RED);
        return RETURN_FAILURE;
    }
}
