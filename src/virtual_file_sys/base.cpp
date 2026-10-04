#include "veng/virtual_file_sys/vfs_class.h"
#include <physfs.h>

#include "lo_utils/cxx_wrap/term.hpp"


bool VFileSys::init(const char *argv0){
    if (PHYSFS_init(argv0)){
        term::msg("Virtual filesystem init. successfully", "VFS", COLOR_GREEN);
        return true;
    }
    term::msg(PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode()), "VFS", COLOR_RED);
    return false;
}
VFileSys::~VFileSys(){
    PHYSFS_deinit();
}