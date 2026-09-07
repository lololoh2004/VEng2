#pragma once

#include <array>

class entityManager;

struct entity{
private:
    bool  m_isCreated = false;
    float m_x = 0.0f;
    float m_y = 0.0f;
    float m_z = 0.0f;

    friend class entityManager;
public:
    entity() { m_isCreated = false; }
    entity(float x,float y,float z) : m_x(x), m_y(y), m_z(z) {
        m_isCreated = true;
    }
    ~entity(){
        m_isCreated = false;
    }

    [[nodiscard]] bool isCreated() const;
};

class entityManager{
    std::array<entity, 4096> entArray;
public:
    entityManager() = default;

    [[nodiscard]] int getEntCount() const;
    int addEnt(const entity& newEnt);
    void removeEnt(int id);

};