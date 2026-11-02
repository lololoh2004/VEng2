#pragma once

#include <memory>


class rSDLRender;
class entityManager;
class VFileSys;
class luaScriptSys;
class SDLWindow;

class vEngine{
    std::unique_ptr<VFileSys>      m_vFileSys;
    std::unique_ptr<luaScriptSys>  m_scriptSys;
    std::unique_ptr<SDLWindow>     m_window;
    std::unique_ptr<rSDLRender>    m_render;
    std::unique_ptr<entityManager> m_entManager;
public:
    vEngine();
    ~vEngine();

    vEngine(const vEngine &) = delete;
    vEngine& operator=(const vEngine &) = delete;

    bool initAll(int argc, char *argv[]);
    void initModules(char* firstArg);
    // bool initLua();
    // bool initRender();

    void update();
    void shutdownAll();

    // void DEBUG_FUNC1();
};
