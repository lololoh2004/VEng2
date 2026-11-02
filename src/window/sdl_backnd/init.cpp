#include "veng/window/sdl_backnd.hpp"

#include "SDL3/SDL_init.h"
#include <SDL3/SDL_log.h>

#include "lo_utils/cxx_wrap/term.hpp"


SDLWindow::SDLWindow()  = default;
SDLWindow::~SDLWindow() = default;

bool SDLWindow::initWindow(){
    if (!SDL_Init(SDL_INIT_VIDEO)){
        SDL_LogError(SDL_LOG_CATEGORY_VIDEO, "SDL root initialization failed : %s", SDL_GetError());
        return false;
    }
    SDL_LogInfo(SDL_LOG_CATEGORY_VIDEO, "SDL root initialized");

    g_window = SDL_CreateWindow(m_title, m_width, m_height, SDL_WINDOW_RESIZABLE);
    if (!g_window){
        SDL_LogError(SDL_LOG_CATEGORY_VIDEO, "Window creation failed : %s", SDL_GetError());
        SDL_Quit();
        return false;
    }
    SDL_LogInfo(SDL_LOG_CATEGORY_VIDEO, "Window created");

    m_isInit = true;
    term::msg("Window init. successfully", "SDL", COLOR_GREEN);
    return true;
}
void SDLWindow::destroyWindow() const{
    SDL_LogInfo(SDL_LOG_CATEGORY_VIDEO, "Destroying window..");
    SDL_DestroyWindow(g_window);
    SDL_Quit();
}
