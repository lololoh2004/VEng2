#include "veng/render/rsdl_backnd/r_class.hpp"
extern "C"{
#include "rsdl/render.h"
}


void rSDLRender::clearBG() const{

}
void rSDLRender::clearBG(color clr){
    setBgColor( { clr.r, clr.g, clr.b, clr.a } );
}

void rSDLRender::beginDraw(){
    ::beginDraw();
}
void rSDLRender::endDraw(){
    ::endDraw();
}