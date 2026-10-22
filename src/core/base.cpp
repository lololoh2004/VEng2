#include "veng/core/main_core.hpp"

#include <lo_utils/cxx_wrap/term.hpp>

#include "veng/virtual_file_sys/vfs_class.h"
#include "veng/render/rsdl_backnd/r_class.hpp"
#include "veng/scene/ent_manager.hpp"

#include "veng/cfg/arg_parser.hpp"


vEngine::~vEngine(){
    shutdownAll();
}
vEngine::vEngine() = default;


bool vEngine::initRender(){
    m_render = std::make_unique<rSDLRender>();
    return m_render ->init();
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

    // Lua init
    initLua();

    // VFSys
    term::msg("Enter virtual filesystem init..", "ENG", COLOR_GRAY);
    m_vFileSys = std::make_unique<VFileSys>();
    m_vFileSys ->init(argv[0]);

    // Render init
    initRender();

    // Scene sys. init
    m_entManager = std::make_unique<entityManager>();

    return true;
}

void vEngine::shutdownAll(){
    // Nah
    term::msg("Bye", "ENG", COLOR_GRAY);
}