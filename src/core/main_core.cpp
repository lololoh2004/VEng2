#include "veng/core/main_core.hpp"

#include "veng/lua/get_bind_code.hpp"

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
    term::msg("Enter Lua first-api init..", "ENG");

    if (state.getRawState()){
        term::msg(" - Success !!", "ENG");
    } else {
        term::msg(" - Fail !!", "ENG");
    }
}
void luaInitFinalPart(luaState& state){
    term::msg("Enter Lua final-api init..", "ENG");

    term::msg(" - Opening libs..", "ENG");
    state.openLibs();
    term::msg(" - Creating c code bind..", "ENG");
    std::string apiCode = getCBind();
    term::msg(" - Bind result :", "ENG");
    printf("%s", apiCode.c_str());

    term::msg(" - Exec. bind..", "ENG");
    if (state.doScriptStr(apiCode)){
        term::msg(" - Success !!", "ENG");
    } else {
        term::msg(" - Fail !!", "ENG");
    }
}


bool Engine::initAll(){
    // Small setup
    termSetupEnv();
    term::msg("Enter engine init..", "ENG");

    // Lua init
    luaState state;
    luaInitFirstPart(state);
    luaInitFinalPart(state);

    // Render init
    m_render = std::make_unique<rLibRender>();
    m_render->init(600,480,"ENGINE_DEBUG_WINDOW", 90);

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
}