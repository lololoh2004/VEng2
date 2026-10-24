#include "../../include/veng/render/rsdl_backnd.hpp"
#include "veng/core/engine.hpp"

void vEngine::update(){
    if (!m_render->windowShouldClose()){
        m_render->beginDraw();
        m_render->clearBG();
        m_render->endDraw();
    }
}