#include "veng/core/main_core.hpp"

#include "veng/lua/get_bind_code.hpp"
#include "veng/virtual_file_sys/vfs_class.h"

extern "C" {
#include <lo_utils/c11/term/term_sys_wrap.h>
}
#include <lo_utils/cxx_wrap/term.hpp>
#include <mswlua/luaState/state.hpp>

#include "veng/render/raylib_backnd/render_class.hpp"
#include "veng/scene/ent_manager.hpp"


Engine::~Engine(){
    shutdownAll();
}
Engine::Engine() = default;

void luaInitFirstPart(luaState& state){
    term::msg("Enter Lua first-api init..", "ENG", COLOR_GRAY);

    if (state.getRawState()){
        term::msg(" - Success !!", "ENG", COLOR_GREEN);
    } else {
        term::msg(" - Fail !!", "ENG", COLOR_RED);
    }
}
void luaInitFinalPart(luaState& state){
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


bool Engine::initAll(int argc, char *argv[]){
    // Small setup
    termSetupEnv();
    term::msg("Enter engine init..", "ENG", COLOR_GRAY);

    // Lua init
    luaState state;
    luaInitFirstPart(state);
    luaInitFinalPart(state);

    // VFSys
    term::msg("Enter virtual filesystem init..", "ENG", COLOR_GRAY);
    m_vFileSys = std::make_unique<VFileSys>();
    m_vFileSys ->init(argv[0]);

    // Render init
    m_render = std::make_unique<rLibRender>();
    m_render ->init(600,480,"ENGINE_DEBUG_WINDOW", 90);

    // Scene sys. init
    m_entManager = std::make_unique<entityManager>();

    return true;
}

void Engine::startUpdating(){
    while (!m_render->windowShouldClose()){
        renderFrame();
    }
}

void Engine::renderFrame(){
    m_render->beginDraw();
    m_render->clearBG();
    m_render->endDraw();
}

void Engine::shutdownAll(){
    m_render->shutdown();
    // Nah
    term::msg("Bye", "ENG", COLOR_GRAY);
}