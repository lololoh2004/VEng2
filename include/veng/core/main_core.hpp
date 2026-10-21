#pragma once
#include <memory>

class rLibRender;
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
    void initLua();

    void startUpdating();
    void renderFrame();
    void shutdownAll();

    // void DEBUG_FUNC1();
private:
    // std::unique_ptr<rLibRender>    m_render;
    std::unique_ptr<entityManager> m_entManager;
    std::unique_ptr<VFileSys>      m_vFileSys;

    // void luaInit(luaState& sv, luaState& cl);
};
