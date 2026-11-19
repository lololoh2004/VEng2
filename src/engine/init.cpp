// Parent header
#include "veng/engine.hpp"

// Veng module headers
#include "veng/file_sys.h"
#include "veng/window/sdl.hpp"
#include "veng/render/rsdl.hpp"
#include "veng/scene/ent_manager.hpp"
#include "veng/script/lua_jit.hpp"
#include "veng/term.hpp"

// Small QoL
#include "veng/common/color_presets.h"

// MSWLua
#include <mswlua/c_api/run_str_script.hpp>


vEngine::~vEngine(){
    shutdownAll();
}
vEngine::vEngine() = default;


void vEngine::initModules(){
    // VFSys
    log("Enter vfsys init..", "ENG", CLR_GRAY);
    m_fileSys =  std::make_unique<fileSys>();
    m_fileSys -> vInit(getArg(ENGINE_ARG, "exe_path").data());
    m_fileSys -> vMountBase(getArg(ENGINE_ARG, "bp_print"));

    // Lua init
    log("Enter script backend init..", "ENG", CLR_GRAY);
    m_scriptSys = std::make_unique<luaScriptSys>();
    m_scriptSys -> initAPI();
    strScript(m_scriptSys->sv, "print('[LUA] : Lua SV state init. successfully ( raw print() )')").runScript();

    // Window init
    log("Enter window init..", "ENG", CLR_GRAY);
    m_window =  std::make_unique<SDLWindow>();
    m_window -> initWindow();
    m_window -> setMaxFPS(0);

    // Render init
    log("Enter render init..", "ENG", CLR_GRAY);
    m_render =  std::make_unique<rSDLRender>(m_window->getRawWindow());
    m_render -> initRender();
    m_render -> initIGUI();

    // Scene sys. init
    m_entManager = std::make_unique<entityManager>();
}


bool vEngine::initAll(int argc, char *argv[]){
    // Arg process
    _processArgs(argc, argv);

    // Small term setup
    // m_term =  std::make_unique<termSys>();
    termInit();
    log("Enter engine init..", "ENG", CLR_GRAY);

    initModules();



    return true;
}

void vEngine::shutdownAll(){
    // Nah
    log("Bye", "ENG", CLR_GRAY);
}