#include "veng/core/main_core.hpp"

#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL_main.h>


SDL_AppResult SDL_AppInit(void** appstate, int argc, char** argv){
    auto* veng = new vEngine();

    *appstate = veng;
    veng->initAll(argc, argv);

    return SDL_APP_CONTINUE;
}


SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
    auto* veng = static_cast<vEngine*>(appstate);

    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
    auto* veng = static_cast<vEngine*>(appstate);

    veng->update();

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appstate, SDL_AppResult result) {
    if (appstate) {
        auto* state = static_cast<vEngine*>(appstate);
        delete state;
    }
}