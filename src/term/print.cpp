#include "veng/term.hpp"


void termSys::log(std::string msg){
    m_logQueue.push_back(std::move(msg));
}
