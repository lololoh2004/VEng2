#include "core/main_core.hpp"

int main(){
    Engine mainEng = Engine();
    mainEng.initAll();
    mainEng.startUpdating();
    mainEng.shutdownAll();

    return 0;
}
