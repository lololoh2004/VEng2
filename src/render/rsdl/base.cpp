#include "lo_utils/common/defines.h"
#include "veng/render/rsdl_backnd.hpp"
extern "C"{
#include <rsdl/window.h>
}


rSDLRender::rSDLRender() = default;
rSDLRender::~rSDLRender(){
    shutdown();
}

bool rSDLRender::init(){
    initWindow(m_windowWidth, m_windowHeight, m_windowTitle);
    return true;
}

bool rSDLRender::init(int windowWidth, int windowHeight, const char* windowTitle,int fps){

    return true;
}

void rSDLRender::shutdown(){

}

bool rSDLRender::windowShouldClose(){
    return false;
}