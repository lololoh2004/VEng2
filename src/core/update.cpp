#include "veng/render/rsdl_backnd/r_class.hpp"
#include "veng/core/main_core.hpp"

void vEngine::update(){
    if (!m_render->windowShouldClose()){
        m_render->beginDraw();
        m_render->clearBG();
        m_render->endDraw();
    }
}