#pragma once

#include <memory>
#include <vector>


class rSDLRender;
class entityManager;
class VFileSys;
class luaScriptSys;
class SDLWindow;
class termSys;

enum argType{
    ENGINE_ARG,
    AUTORUN_ARG,
};
struct argContainer{
    std::string_view argName;
    std::string_view argVal;
};


class vEngine{
    std::unique_ptr<termSys>       m_term;
    std::unique_ptr<VFileSys>      m_vFileSys;
    std::unique_ptr<luaScriptSys>  m_scriptSys;
    std::unique_ptr<SDLWindow>     m_window;
    std::unique_ptr<rSDLRender>    m_render;
    std::unique_ptr<entityManager> m_entManager;

    std::vector<argContainer> m_engineArgs;
    std::vector<argContainer> m_autorunArgs;

    void _processArgs(int argc, char *argv[]);
public:
    vEngine();
    ~vEngine();

    vEngine(const vEngine &) = delete;
    vEngine& operator=(const vEngine &) = delete;

    bool initAll(int argc, char *argv[]);
    void initModules();

    [[nodiscard]] bool hasArg(argType type, std::string_view name) const;
    [[nodiscard]] std::string_view getArg(argType type, std::string_view name) const;

    void update();
    void shutdownAll();

    // void DEBUG_FUNC1();
};
