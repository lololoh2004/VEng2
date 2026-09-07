#pragma once

struct color{
    unsigned char r,g,b,a;
};

class rLibRender{
    bool  m_isInitialized = false;
    int   m_windowWidth   = 600;
    int   m_windowHeight  = 480;
    int   m_fps           = 20;
    color m_bgColor       = { 34, 36, 42, 255 };
    const char* m_windowTitle = "NO_WINDOW_TITLE_NAME";
public:
    rLibRender();
    ~rLibRender();

    bool internalInit();
    bool init(
        int windowWidth=600,
        int windowHeight=480,
        const char* windowTitle="NO_WINDOW_TITLE_NAME",
        int fps=20);
    void shutdown();

    void clearBG() const;
    void clearBG(color clr);
    void beginDraw();
    void endDraw();

    bool windowShouldClose();
};
