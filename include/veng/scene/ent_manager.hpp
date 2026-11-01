#pragma once

#include <array>
#include <vector>

#define MAX_ENT_COUNT 4096

struct entity{
private:
    bool  m_isCreated = false;
    float m_x = 0.0f;
    float m_y = 0.0f;
    float m_z = 0.0f;
public:
    entity() { m_isCreated = false; }
    entity(float x,float y,float z) : m_x(x), m_y(y), m_z(z) {
        m_isCreated = true;
    }
    ~entity() = default;

    [[nodiscard]] bool isCreated() const { return m_isCreated; }
    void kill()   { m_isCreated = false; }
    void revive() { m_isCreated = true; }
};

class entityManager{
    std::array<entity, MAX_ENT_COUNT> m_entArray;
    std::vector<int> m_activeEntsID;
    std::vector<int> m_sleepEntsID ;
public:
    entityManager();

    [[nodiscard]] int getEntCount() const;
    int addEnt(const entity& newEnt);
    void removeEnt(int id);
};