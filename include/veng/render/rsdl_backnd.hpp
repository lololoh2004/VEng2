#pragma once
#include "rsdl/common/structs.h"


class rSDLRender{
    int m_windowWidth  = 600;
    int m_windowHeight = 480;
    int m_fps          = 30 ;
    bool m_isInit = false;
    const char* m_windowTitle = "VENG_BCKND_NO_NAME_WINDOW";
public:
    rSDLRender();
    ~rSDLRender();

    bool init(int windowWidth, int windowHeight, const char* windowTitle,int fps);
    bool init();
    void shutdown();

    void clearBG() const;
    void clearBG(color clr);

    void beginDraw();
    void endDraw();

    bool windowShouldClose();
};
