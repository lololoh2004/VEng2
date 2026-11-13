#include "veng/file_sys.h"

#include <physfs.h>
#include <string>
#include "veng/term.hpp"
#include "veng/common/color_presets.h"


fileSys::~fileSys(){
    PHYSFS_deinit();
}

bool fileSys::vfsysInit(const char *argv0){
    if (PHYSFS_init(argv0)){
        log("Virtual filesystem init. successfully", "VFS", CLR_GREEN);
        return true;
    }
    log(PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode()), "VFS", CLR_RED);
    return false;
}

void fileSys::mountBase(std::string_view bPrintPath){
    std::string bPrintDir = getExePath().append(bPrintPath);
    log("Mounting your bprint. Details : \n - Path : " + bPrintDir, "VFS", CLR_GRAY);
    PHYSFS_mount(bPrintDir.c_str(), "/", 1);
}
