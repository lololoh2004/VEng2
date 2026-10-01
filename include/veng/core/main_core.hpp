#pragma once
#include <memory>

class entityManager;
class rLibRender;
class luaState;

class Engine{
public:
    Engine();
    ~Engine();

    Engine(const Engine &) = delete;
    Engine& operator=(const Engine &) = delete;

    bool initAll();
    void startUpdating();
    void renderFrame();
    void shutdownAll();

    void DEBUG_FUNC1();
private:
    std::unique_ptr<rLibRender>    m_render;
    std::unique_ptr<entityManager> m_entManager;

    // void luaInit(luaState& sv, luaState& cl);
};
