#include "lo_utils/common/defines.h"
extern "C"{
    #include "rsdl/window.h"
}
#include "../../../include/veng/render/rsdl_backnd.hpp"


rSDLRender::rSDLRender() = default;
rSDLRender::~rSDLRender(){
    shutdown();
}

bool rSDLRender::init(){
    initWindow(m_windowWidth, m_windowHeight, m_windowTitle);
    // if (!IsWindowReady())
    //     return RETURN_FAILURE;

    setMaxFPS(m_fps);

    m_isInit = true;
    return RETURN_SUCCESS;
}

bool rSDLRender::init(int windowWidth, int windowHeight, const char* windowTitle,int fps){
    m_windowWidth = windowWidth;
    m_windowHeight = windowHeight;
    m_windowTitle = windowTitle;
    m_fps = fps;

    return init();
}

void rSDLRender::shutdown(){
    if (m_isInit){
        closeWindow();
        m_isInit = false;
    }
}

bool rSDLRender::windowShouldClose(){
    return !isWindowOpen();
}