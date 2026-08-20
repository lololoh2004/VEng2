#include "main_core.hpp"

#include "lo_utils.h"
extern "C" {
#include "mswlua.h"
}

Engine::~Engine(){
    shutdownAll();
}

bool Engine::initAll(){
    termSetupEnv();
    termMsg("Enter engine init..\n", "ENG");

    termMsg("Enter Lua init..\n", "ENG");
    lua_State* sv = nullptr;
    lua_State* cl = nullptr;
    initLuaStates(&sv, &cl);
    if (sv && cl){
        termMsg("Success !!\n", "ENG");
    }
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