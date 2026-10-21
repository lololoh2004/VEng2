#include "veng/core/main_core.hpp"

int main(int argc, char *argv[]){
    vEngine mainEng = vEngine();
    mainEng.initAll(argc, argv);
    mainEng.startUpdating();


    return 0;
}