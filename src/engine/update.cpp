#include "veng/engine.hpp"

#include "veng/common/color_presets.h"
#include "veng/window/sdl_backnd.hpp"
#include "veng/render/rsdl_backnd.hpp"


void vEngine::update(){
    if (!m_window->windowShouldClose()){
        m_render->setBgColor(CLR_DARKGRAY);

        m_window->updateEvents();
        m_window->updateTime();

        m_render->beginDraw();
        m_render->endDraw();

        m_window->sleepBeforeNextFrame();
    }
}