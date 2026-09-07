#include "veng/render/raylib_backnd/render_class.hpp"
#include "raylib.h"
#include "lo_utils/common/defines.h"


rLibRender::rLibRender() = default;

rLibRender::~rLibRender(){
    shutdown();
}

bool rLibRender::internalInit(){
    SetTraceLogLevel(LOG_ERROR);
    InitWindow(m_windowWidth, m_windowHeight, m_windowTitle);
    if (!IsWindowReady())
        return RETURN_FAILURE;

    SetTargetFPS(m_fps);

    m_isInitialized = true;
    return RETURN_SUCCESS;
}

bool rLibRender::init(int windowWidth, int windowHeight, const char* windowTitle,int fps){
    m_windowWidth = windowWidth;
    m_windowHeight = windowHeight;
    m_windowTitle = windowTitle;
    m_fps = fps;

    return internalInit();
}

void rLibRender::shutdown(){
    if (m_isInitialized){
        CloseWindow();
        m_isInitialized = false;
    }
}

bool rLibRender::windowShouldClose(){
    return WindowShouldClose();
}