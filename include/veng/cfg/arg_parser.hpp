#pragma once

#include <unordered_map>
#include <string_view>
#include <string>


enum cmdArgType{
    argTypeEng,
    argTypeCmd,
};

class cmdArgParser{
    std::unordered_map<std::string_view, const char*> m_engArgs;
    std::unordered_map<std::string_view, const char*> m_cmdArgs;
public:
    cmdArgParser(int argc, char *argv[]);
    ~cmdArgParser() = default;

    bool hasArg(const char* argName, cmdArgType argT) {
        const auto& targetMap = argT == argTypeEng
            ? m_engArgs
            : m_cmdArgs;
        return targetMap.find(argName) != targetMap.end();
    }

    void fillVar(std::string& inStr, const char* argName, cmdArgType argT);
    void fillVar(bool& inBool, const char* argName, cmdArgType argT);
};
