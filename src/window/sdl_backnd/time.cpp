#include "SDL3/SDL_timer.h"
#include "veng/window/sdl_backnd.hpp"


static uint64_t s_lastTime;
static uint64_t s_curTime = 0;

void SDLWindow::updateTime(){
    if (s_curTime == 0){
        s_curTime = SDL_GetPerformanceCounter();
    }

    s_lastTime = s_curTime;
    s_curTime = SDL_GetPerformanceCounter();
    m_deltaTime =  static_cast<float>(s_curTime - s_lastTime);
    m_deltaTime /= static_cast<float>(SDL_GetPerformanceFrequency());
}

double SDLWindow::getTime(){
    return static_cast<double>(SDL_GetTicks()) / 1000.0;
}

// This function is required for the frame rate limit to work
// It will freeze the frame if it was processed too quickly
void SDLWindow::sleepBeforeNextFrame() const{
    auto curDelta = static_cast<double>(SDL_GetPerformanceCounter() - s_curTime);
    curDelta = curDelta / static_cast<double>(SDL_GetPerformanceFrequency()) * 1000.0;

    double targetFrameTime = 1000.0 / m_fps;

    if (curDelta < targetFrameTime){
        SDL_Delay(static_cast<Uint32>(targetFrameTime - curDelta));
    }
}