#include "veng/window/sdl.hpp"

#include <SDL3/SDL_init.h>

#include "veng/term.hpp"
#include "veng/common/color_presets.h"


SDLWindow::SDLWindow()  = default;
SDLWindow::~SDLWindow() = default;

bool SDLWindow::initWindow(){
    if (!SDL_Init(SDL_INIT_VIDEO)){
        log(std::string("SDL root initialization failed : ").append(SDL_GetError()), "SDL_WIN", CLR_RED);
        return false;
    }
    log("SDL root initialized", "SDL_WIN", CLR_GREEN);

    g_window = SDL_CreateWindow(m_title, m_width, m_height, SDL_WINDOW_RESIZABLE);
    if (!g_window){
        log(std::string("Window creation failed : ").append(SDL_GetError()), "SDL_WIN", CLR_RED);
        SDL_Quit();
        return false;
    }
    log("Window created", "SDL_WIN", CLR_GREEN);

    m_isInit = true;
    log("Window init. successfully", "SDL_WIN", CLR_GREEN);
    return true;
}
void SDLWindow::destroyWindow() const{
    log("Destroying window..", "SDL_WIN", CLR_GRAY);
    SDL_DestroyWindow(g_window);
    SDL_Quit();
}
