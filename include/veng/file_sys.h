#pragma once

#include <string>
#include <string_view>


struct virtualFileSys{
    bool init(const char *argv0);
    void mount(std::string_view path);
    void unmount(std::string_view path);
    void readStr(std::string_view path);
};

struct nativeFileSys{
    std::string getExePath();
};

class fileSys{
public:
    fileSys() = default;
    ~fileSys();

    bool vInit(const char *argv0);
    // bool sdlInit();
    std::string nGetExePath();
    void vMountBase(std::string_view bPrintPath);
    std::string vReadStr(std::string_view vPath);
private:
    virtualFileSys vfs;
    nativeFileSys  nfs;
};