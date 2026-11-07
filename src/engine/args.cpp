#include "veng/engine.hpp"


static const argContainer* getArgIterator(const std::vector<argContainer>& container, std::string_view name){
    auto it = std::ranges::find_if(container, [name](const argContainer& arg){
        return arg.argName == name;
    });
    return it == container.end() ? nullptr : &(*it);
}

bool vEngine::hasArg(argType type, std::string_view name) const{
    const argContainer* res = type == ENGINE_ARG
        ? getArgIterator(m_engineArgs, name)
        : getArgIterator(m_autorunArgs, name);

    return res != nullptr;
}
std::string_view vEngine::getArg(argType type, std::string_view name) const{
    const argContainer* res = type == ENGINE_ARG
        ? getArgIterator(m_engineArgs, name)
        : getArgIterator(m_autorunArgs, name);

    return res
        ? res->argVal
        : std::string_view{};
}

void vEngine::_processArgs(int argc, char* argv[]){
    // First iteration
    m_engineArgs.push_back({"exe_path", argv[0]});

    // All other iterations
    for (int i = 1; i < argc; i++){
        if (argv[i][0] == '-' || argv[i][0] == '+'){
            char firstChar = argv[i][0];
            int nextIt = i+1;

            std::string_view resultName(argv[i] + 1);
            std::string_view resultVal;

            if (nextIt < argc && argv[nextIt][0] != '-' && argv[nextIt][0] != '+'){
                resultVal = argv[nextIt];
                i = nextIt;
            }
            switch (firstChar){
                case '+': m_engineArgs.push_back({resultName, resultVal}); break;
                case '-': m_autorunArgs.push_back({resultName, resultVal}); break;
                default: break;
            }
        }
    }
}
