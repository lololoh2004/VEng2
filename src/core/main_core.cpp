#include "veng/core/main_core.hpp"

#include "lo_utils.h"
#include "mswlua.hpp"
#include "veng/render/raylib_backnd/render_class.hpp"


Engine::Engine() = default;

Engine::~Engine(){
    shutdownAll();
}

bool Engine::initAll(){
    termSetupEnv();
    termMsg("Enter engine init..\n", "ENG");

    // === LUA INIT ===
    termMsg("Enter Lua init..\n", "ENG");
    luaState sv;   luaState cl;
    sv.openLibs(); cl.openLibs();
    if (sv.getRawState() && cl.getRawState())
        termMsg("Success !!\n", "ENG");
    // === RENDER INIT ===
    m_render = std::make_unique<RLibRender>();
    m_render->init();

    return true;
}

void Engine::startUpdating(){
    while (!m_render->windowShouldClose()){
        m_render->beginDraw();
        m_render->clearBG();
        m_render->endDraw();
    }
}

void Engine::shutdownAll(){
    m_render->shutdown();
    // Nah
}