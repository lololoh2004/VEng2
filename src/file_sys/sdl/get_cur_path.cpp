#include "veng/file_sys.h"

#include "SDL3/SDL_filesystem.h"
#include <string>


std::string fileSys::getExePath(){
    const char* path = SDL_GetBasePath();
    if (path == nullptr) return "";
    return path;
}
