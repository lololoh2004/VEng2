#pragma once

#include <vector>
#include <thread>
#include <string>

#include "common/structs.hpp"


class termSys{
    std::vector<std::string> m_logQueue;
    std::jthread m_logThread;
public:
    termSys();
    ~termSys() = default;

    // [[deprecated]]
    void log(std::string_view content, const char* entryPoint, colRGBA color);

    void clear(bool deleteWin32Folder = false);
};
