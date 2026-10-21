#include "lo_utils/cxx_wrap/term.hpp"
#include "mswlua/luaState/state.hpp"
#include "veng/core/main_core.hpp"
#include "veng/lua/get_bind_code.hpp"


void vEngine::initLua(){
    luaState state;

    // First part
    term::msg("Enter Lua first-api init..", "ENG", COLOR_GRAY);
    // ..

    // Final part
    term::msg("Enter Lua final-api init..", "ENG", COLOR_GRAY);

    term::msg(" - Opening libs..", "ENG", COLOR_GRAY);
    state.openLibs();
    term::msg(" - Creating c code bind..", "ENG", COLOR_GRAY);
    std::string apiCode = getCBind();
    term::msg(" - Bind result :", "ENG");
    printf("%s", apiCode.c_str());

    term::msg(" - Exec. bind..", "ENG", COLOR_GRAY);
    if (state.doScriptStr(apiCode)){
        term::msg(" - Success !!", "ENG", COLOR_GREEN);
    } else {
        term::msg(" - Fail !!", "ENG", COLOR_RED);
    }
}