#include "veng/input.hpp"

#include "SDL3/SDL_mouse.h"
#include "cglm/struct/vec2.h"


static SDL_MouseButtonFlags s_prevButtons = 0;
static SDL_MouseButtonFlags s_curButtons = 0;

void inputSys::updateMouse(){
    s_prevButtons = s_curButtons;
    s_curButtons = SDL_GetMouseState(&m_mouseX, &m_mouseY);
}

bool inputSys::isMousePressed(int sdlButton){
    Uint32 buttonMask = SDL_BUTTON_MASK(sdlButton);
    return (s_curButtons & buttonMask) && !(s_prevButtons & buttonMask);
}
bool inputSys::IsMouseReleased(int sdlButton){
    Uint32 buttonMask = SDL_BUTTON_MASK(sdlButton);
    return !(s_curButtons & buttonMask) && (s_prevButtons & buttonMask);
}
bool inputSys::IsMouseDown(int sdlButton){
    Uint32 buttonMask = SDL_BUTTON_MASK(sdlButton);
    return (s_curButtons & buttonMask);
}
bool inputSys::IsMouseUp(int sdlButton){
    Uint32 buttonMask = SDL_BUTTON_MASK(sdlButton);
    return !(s_curButtons & buttonMask);
}