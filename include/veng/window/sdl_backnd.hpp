#pragma once


struct SDL_Window;
union SDL_Event;

class SDLWindow{
    SDL_Window* g_window = nullptr;

    int m_width   = 600;
    int m_height  = 480;
    int m_fps     = 30 ;
    const char* m_title = "VENG_BCKND_NO_NAME_WINDOW";
    bool m_isInit = false;

    float m_deltaTime = 0.0f;
public:
    SDLWindow();
    ~SDLWindow();

    // Window
    bool initWindow();
    bool initWindow(int windowWidth, int windowHeight, const char* windowTitle, int fps){
        m_width  = windowWidth;
        m_height = windowHeight;
        m_title  = windowTitle;
        m_fps    = fps;
        return initWindow();
    }

    [[nodiscard]] SDL_Window* getRawWindow() const { return g_window;  }
    [[nodiscard]] bool windowShouldClose()   const { return !m_isInit; }

    // Events
    const SDL_Event* getRawEvents();
    void updateEvents();

    // Time
    void updateTime();
    [[nodiscard]] float getDeltaF() const { return m_deltaTime; }
    // double getDeltaD();
    [[nodiscard]] double getTime();
    [[nodiscard]] int    getFPS() const { return static_cast<int>(1.0f / m_deltaTime); }
    void setMaxFPS(int fps) { m_fps = fps; }
    void sleepBeforeNextFrame() const;

    void destroyWindow() const;
};
