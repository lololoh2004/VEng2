#include "veng/core/main_core.hpp"

extern "C"{
#include <lo_utils/c11/term.h>
}
#include <lo_utils/cxx_wrap/term.hpp>
#include <mswlua/luaState/state.hpp>

#include "veng/render/raylib_backnd/render_class.hpp"
#include "veng/scene/ent_manager.hpp"


Engine::Engine() = default;

Engine::~Engine(){
    shutdownAll();
}

void Engine::DEBUG_FUNC(){
    term::msg(m_entManager->getEntCount());
    for (int i = 0; i < 10; i++){
        entity ent(1, 1, 1);
        m_entManager->addEnt(ent);
    }
    term::msg(m_entManager->getEntCount());
}

bool Engine::initAll(){
    termSetupEnv();
    term::msg("Enter engine init..", "ENG");

    // === LUA INIT ===
    term::msg("Enter Lua init..", "ENG");
    luaState sv;   luaState cl;
    sv.openLibs(); cl.openLibs();
    if (sv.getRawState() && cl.getRawState())
        term::msg("Success !!", "ENG");

    // === RENDER INIT ===
    m_render = std::make_unique<rLibRender>();
    m_render->init(600,480,"ENGINE_DEBUG_WINDOW", 90);

    // === SCENE INIT ===
    m_entManager = std::make_unique<entityManager>();

    // === DEBUG TESTS ===
    DEBUG_FUNC();

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