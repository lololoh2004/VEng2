#pragma once
#include <memory>

class rLibRender;
class entityManager;
class VFileSys;
class luaState;

class Engine{
public:
    Engine();
    ~Engine();

    Engine(const Engine &) = delete;
    Engine& operator=(const Engine &) = delete;

    bool initAll(int argc, char *argv[]);
    void startUpdating();
    void renderFrame();
    void shutdownAll();

    void DEBUG_FUNC1();
private:
    std::unique_ptr<rLibRender>    m_render;
    std::unique_ptr<entityManager> m_entManager;
    std::unique_ptr<VFileSys>      m_vFileSys;

    // void luaInit(luaState& sv, luaState& cl);
};
