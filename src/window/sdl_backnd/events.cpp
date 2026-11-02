#include "veng/window/sdl_backnd.hpp"

#include "SDL3/SDL_events.h"


static SDL_Event s_event;

void SDLWindow::updateEvents(){
    while (SDL_PollEvent(&s_event)){
        switch (s_event.type){
        case SDL_EVENT_TERMINATING:
        case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
        case SDL_EVENT_QUIT:
            m_isInit = false; break;

            // case SDL_EVENT_KEY_DOWN:
            //     event.key.scancode
        default: break;
        }
    }
}

const SDL_Event* SDLWindow::getRawEvents(){
    return &s_event;
}