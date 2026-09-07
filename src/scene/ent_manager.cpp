#include "veng/scene/ent_manager.hpp"

[[nodiscard]] bool entity::isCreated() const {
    return m_isCreated;
}


[[nodiscard]] int entityManager::getEntCount() const{
    int result = 0;
    for (const auto& ent : entArray)
        if (ent.m_isCreated) result++;
    return result;
}
int entityManager::addEnt(const entity& newEnt){
    for (int i=0; i < 4096; i++){
        if (!entArray[i].m_isCreated){
            entArray[i] = newEnt;
            entArray[i].m_isCreated = true;
            return i;
        }
    }
    return -1;
}

void entityManager::removeEnt(int id){
    if (id < 4096 && id >= 0){
        entArray[id].m_isCreated = false;
    }
}
