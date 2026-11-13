#pragma once

#include <string>
#include <string_view>

class fileSys{

public:
    fileSys() = default;
    ~fileSys();

    bool vfsysInit(const char *argv0);
    // bool sdlInit();
    std::string getExePath();
    void mountBase(std::string_view bPrintPath);
};