#include "veng/scene/ent_manager.hpp"


entityManager::entityManager(){
    m_activeEntsID.reserve(4096);
    m_sleepEntsID.reserve(4096);

    for (int i = MAX_ENT_COUNT - 1; i >= 0; i--){
        m_sleepEntsID.push_back(i);
    }
}

[[nodiscard]] int entityManager::getEntCount() const{
    return static_cast<int>(m_activeEntsID.size());
}
int entityManager::addEnt(const entity& newEnt){
    if (m_sleepEntsID.empty()) return -1;

    int freeID = m_sleepEntsID.back();
    m_sleepEntsID.pop_back();

    m_entArray[freeID] = newEnt;
    m_entArray[freeID].revive();

    m_activeEntsID.push_back(freeID);
    return freeID;
}

void entityManager::removeEnt(int id){
    if (id < 0 || id >= MAX_ENT_COUNT || m_entArray[id].isCreated() != true) return;

    m_entArray[id].kill();
    m_sleepEntsID.push_back(id);

    auto it = std::ranges::find(m_activeEntsID, id);
    if (it != m_activeEntsID.end()){
        *it = m_activeEntsID.back();
        m_activeEntsID.pop_back();
    }
}
