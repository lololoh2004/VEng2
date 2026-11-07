#include "veng/engine.hpp"

#include "veng/vfsys.h"
#include "veng/window/sdl_backnd.hpp"
#include "veng/render/rsdl_backnd.hpp"
#include "veng/scene/ent_manager.hpp"
#include "veng/script/lua_backnd.hpp"
#include "veng/term.hpp"

#include "veng/common/color_presets.h"


vEngine::~vEngine(){
    shutdownAll();
}
vEngine::vEngine() = default;


void vEngine::initModules(){
    // Lua init
    m_term->log("Enter script backend init.. ( wont provide a success log )", "ENG", CLR_GRAY);
    m_scriptSys =  std::make_unique<luaScriptSys>();
    m_scriptSys -> baseInit();

    // VFSys
    m_term->log("Enter vfsys init..", "ENG", CLR_GRAY);
    m_vFileSys =  std::make_unique<VFileSys>();
    m_vFileSys -> init(getArg(ENGINE_ARG, "exe_path").data());

    // Window init
    m_term->log("Enter window init..", "ENG", CLR_GRAY);
    m_window =  std::make_unique<SDLWindow>();
    m_window -> initWindow();
    m_window -> setMaxFPS(80);

    // Render init
    m_term->log("Enter render init..", "ENG", CLR_GRAY);
    m_render =  std::make_unique<rSDLRender>(m_window->getRawWindow());
    m_render -> initRender();

    // Scene sys. init
    m_entManager = std::make_unique<entityManager>();
}

bool vEngine::initAll(int argc, char *argv[]){
    // Arg process
    _processArgs(argc, argv);

    // Small term setup
    m_term =  std::make_unique<termSys>();
    m_term -> log("Enter engine init..", "ENG", CLR_GRAY);

    initModules();



    return true;
}

void vEngine::shutdownAll(){
    // Nah
    m_term->log("Bye", "ENG", CLR_GRAY);
}