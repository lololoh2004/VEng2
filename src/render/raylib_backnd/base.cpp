#include "veng/render/raylib_backnd/render_class.hpp"
#include "raylib.h"
#include "veng/defines.h"


RLibRender::RLibRender() = default;

RLibRender::~RLibRender(){
    shutdown();
}

bool RLibRender::init(){
    InitWindow(m_windowWidth, m_windowHeight, m_windowTitle);
    if (!IsWindowReady())
        return RETURN_FAILURE;

    SetTargetFPS(m_fps);

    m_isInitialized = true;
    return RETURN_SUCCESS;
}

void RLibRender::shutdown(){
    if (m_isInitialized){
        CloseWindow();
        m_isInitialized = false;
    }
}

bool RLibRender::windowShouldClose(){
    return WindowShouldClose();
}