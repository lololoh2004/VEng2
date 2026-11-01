#pragma once

#include <vector>
#include <thread>
#include <string>


class termSys{
    std::vector<std::string> m_logQueue;
    std::jthread m_logThread;
public:
    termSys()  = default;
    ~termSys() = default;

    void log(std::string msg);

    void clear(bool deleteWin32Folder = false);
};
