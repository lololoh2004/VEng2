#include "veng/cfg/arg_parser.hpp"


cmdArgParser::cmdArgParser(int argc, char* argv[]){
    for (int i = 1; i < argc; i++){
        if (argv[i][0] == '-' || argv[i][0] == '+'){
            char firstChar = argv[i][0];
            const char* key = argv[i];
            const char* val = nullptr;

            int nextStep = i+1;
            if (nextStep < argc && argv[nextStep][0] != '-' && argv[nextStep][0] != '+'){
                val = argv[nextStep];
                i++;
            }

            if (firstChar == '+'){
                m_engArgs[key + 1] = val;
            } else {
                m_cmdArgs[key + 1] = val;
            }
        }
    }
}

void cmdArgParser::fillVar(std::string& inStr, const char* argName, cmdArgType argT){
    const auto& targetMap = argT == argTypeEng
        ? m_engArgs
        : m_cmdArgs;

    auto it = targetMap.find(argName);
    if (it != targetMap.end()){
        inStr = it->second != nullptr ? it->second : "";
    }
}
void cmdArgParser::fillVar(bool& inBool, const char* argName, cmdArgType argT){
    const auto& targetMap = argT == argTypeEng
        ? m_engArgs
        : m_cmdArgs;

    inBool = hasArg(argName, argT);
}