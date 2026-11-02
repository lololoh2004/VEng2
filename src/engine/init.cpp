#include "veng/engine.hpp"

#include <lo_utils/cxx_wrap/term.hpp>

#include "veng/vfsys.h"
#include "veng/window/sdl_backnd.hpp"
#include "veng/render/rsdl_backnd.hpp"
#include "veng/scene/ent_manager.hpp"
#include "veng/script/lua_backnd.hpp"

#include "veng/utils/arg_parser.hpp"


vEngine::~vEngine(){
    shutdownAll();
}
vEngine::vEngine() = default;


void vEngine::initModules(char* firstArg){
    // Lua init
    m_scriptSys = std::make_unique<luaScriptSys>();

    // VFSys
    term::msg("Enter vfsys init..", "ENG", COLOR_GRAY);
    m_vFileSys =  std::make_unique<VFileSys>();
    m_vFileSys -> init(firstArg);

    // Window init
    term::msg("Enter window init..", "ENG", COLOR_GRAY);
    m_window =  std::make_unique<SDLWindow>();
    m_window -> initWindow();
    m_window -> setMaxFPS(80);

    // Render init
    term::msg("Enter render init..", "ENG", COLOR_GRAY);
    m_render =  std::make_unique<rSDLRender>(m_window->getRawWindow());
    m_render -> initRender();

    // Scene sys. init
    m_entManager = std::make_unique<entityManager>();
}

bool vEngine::initAll(int argc, char *argv[]){
    // Small setup
    term::setup();
    term::msg("Enter engine init..", "ENG", COLOR_GRAY);

    // Getting custom args
    cmdArgParser cmdArg(argc, argv);
    std::string bPrintName = "autorun";
    cmdArg.fillVar(bPrintName, "bp_print", argTypeEng);
    term::msg(bPrintName, "ENG", COLOR_CYAN);

    initModules(argv[0]);

    return true;
}

void vEngine::shutdownAll(){
    // Nah
    term::msg("Bye", "ENG", COLOR_GRAY);
}