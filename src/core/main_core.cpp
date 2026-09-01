#include "main_core.hpp"

#include "lo_utils.h"
#include "mswlua.hpp"

Engine::~Engine(){
    shutdownAll();
}

bool Engine::initAll(){
    termSetupEnv();
    termMsg("Enter engine init..\n", "ENG");

    termMsg("Enter Lua init..\n", "ENG");
    luaState sv;   luaState cl;
    sv.openLibs(); cl.openLibs();
    if (sv.getRawState() && cl.getRawState())
        termMsg("Success !!\n", "ENG");
    return true;
}

void Engine::startUpdating(){
    int it = 0;
    while (it <= 3){
        it++;
    } // Placeholder
}

void Engine::shutdownAll(){
    // Nah
}