#include "veng/core/main_core.hpp"

int main(int argc, char *argv[]){
    Engine mainEng = Engine();
    mainEng.initAll(argc, argv);
    mainEng.startUpdating();


    return 0;
}