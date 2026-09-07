#include "veng/render/raylib_backnd/render_class.hpp"
#include "raylib.h"

void rLibRender::clearBG() const{
    ClearBackground( { m_bgColor.r, m_bgColor.g, m_bgColor.b, m_bgColor.a } );
}
void rLibRender::clearBG(color clr){
    ClearBackground( { clr.r, clr.g, clr.b, clr.a } );
}

void rLibRender::beginDraw(){
    BeginDrawing();
}
void rLibRender::endDraw(){
    EndDrawing();
}