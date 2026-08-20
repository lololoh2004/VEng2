#pragma once

struct lua_State;

class Engine{
public:
    Engine() = default;
    ~Engine();

    Engine(const Engine &) = delete;
    Engine& operator=(const Engine &) = delete;

    bool initAll();
    void startUpdating();
    void shutdownAll();
private:
    lua_State* m_svState;
    lua_State* m_clState;
};