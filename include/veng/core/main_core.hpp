#pragma once
#include <memory>

class rSDLRender;
class entityManager;
class VFileSys;
class luaState;

class vEngine{
public:
    vEngine();
    ~vEngine();

    vEngine(const vEngine &) = delete;
    vEngine& operator=(const vEngine &) = delete;

    bool initAll(int argc, char *argv[]);
    bool initLua();
    bool initRender();
    //

    void update();
    void shutdownAll();

    // void DEBUG_FUNC1();
private:
    std::unique_ptr<rSDLRender>    m_render;
    std::unique_ptr<entityManager> m_entManager;
    std::unique_ptr<VFileSys>      m_vFileSys;

    // void luaInit(luaState& sv, luaState& cl);
};
