#pragma once
#include <memory>

class RLibRender;

class Engine{
public:
    Engine();
    ~Engine();

    Engine(const Engine &) = delete;
    Engine& operator=(const Engine &) = delete;

    bool initAll();
    void startUpdating();
    void shutdownAll();
private:
    std::unique_ptr<RLibRender> m_render;

};
