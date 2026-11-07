#include "veng/term.hpp"

#include "veng/common/structs.hpp"


void termSys::log(std::string_view content, const char* entryPoint, colRGBA color){
    printf("\033[38;2;%d;%d;%dm[%s] %.*s\n",
        color.r, color.g, color.b,
        entryPoint,
        static_cast<int>(content.size()), content.data()
    );
}
