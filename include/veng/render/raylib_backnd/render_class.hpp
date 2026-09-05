#pragma once

struct color{
    unsigned char r,g,b,a;
};

class RLibRender{
    bool  m_isInitialized = false;
    int   m_windowWidth   = 800;
    int   m_windowHeight  = 600;
    int   m_fps           = 20;
    color m_bgColor       = { 34, 36, 42, 255 };
    const char* m_windowTitle = "NO_WINDOW_TITLE_NAME";
public:
    RLibRender();
    ~RLibRender();

    bool init();
    void shutdown();

    void clearBG() const;
    void clearBG(color clr);
    void beginDraw();
    void endDraw();

    bool windowShouldClose();
};
