#pragma once


class VFileSys{

public:
    VFileSys() = default;
    bool init(const char *argv0);
    ~VFileSys();
};