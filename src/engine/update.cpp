#include "veng/engine.hpp"

#include "veng/common/color_presets.h"
#include "veng/window/sdl.hpp"
#include "veng/render/rsdl.hpp"


void vEngine::updateEvent(const SDL_Event* event){
    if (m_render){
        m_render->updateIGUIEvents(event);
    }
}

void vEngine::updateFrame(){
    if (!m_window->windowShouldClose()){
        m_render->setBgColor(CLR_DARKGRAY);

        m_window->updateTime();

        m_render->beginDraw();
        m_render->endDraw();

        m_render->beginIGUI();
        m_render->showDemoIGUI();
        m_render->endIGUI();

        m_render->submitGPUBuf();

        m_window->sleepBeforeNextFrame();
    }
}