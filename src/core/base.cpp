#include "veng/core/engine.hpp"

#include <lo_utils/cxx_wrap/term.hpp>

#include "veng/virtual_file_sys/vfs_class.h"
#include "veng/render/rsdl_backnd.hpp"
#include "veng/scene/ent_manager.hpp"
#include "veng/script/lua_backnd.hpp"

#include "veng/cfg/arg_parser.hpp"


vEngine::~vEngine(){
    shutdownAll();
}
vEngine::vEngine() = default;


bool vEngine::initAll(int argc, char *argv[]){
    // Small setup
    term::setup();
    term::msg("Enter engine init..", "ENG", COLOR_GRAY);

    // Getting custom args
    cmdArgParser cmdArg(argc, argv);
    std::string bPrintName = "autorun";
    cmdArg.fillVar(bPrintName, "bp_print", argTypeEng);
    term::msg(bPrintName, "ENG", COLOR_CYAN);

    // Lua init
    m_scriptSys = std::make_unique<luaScriptSys>();

    // VFSys
    term::msg("Enter vfsys init..", "ENG", COLOR_GRAY);
    m_vFileSys = std::make_unique<VFileSys>();
    m_vFileSys ->init(argv[0]);

    // Render init
    m_render = std::make_unique<rSDLRender>();
    m_render ->init();

    // Scene sys. init
    m_entManager = std::make_unique<entityManager>();

    return true;
}

void vEngine::shutdownAll(){
    // Nah
    term::msg("Bye", "ENG", COLOR_GRAY);
}