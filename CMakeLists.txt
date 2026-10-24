cmake_minimum_required(VERSION 4.1)
project(VEng2)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY         "${CMAKE_SOURCE_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_SOURCE_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}")

# Global vars.
set(CUSTOMIZE_BUILD   ON  CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(BUILD_EXAMPLES    OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES       OFF CACHE BOOL "" FORCE)

if(WIN32)
    set(BIN_OS_ALIAS "win")
else()
    set(BIN_OS_ALIAS "lin")
endif()
set(BINS_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/VEngBinary/${BIN_OS_ALIAS}_x64")


include(FetchContent)
# === ALL THIRDPARTY LIBS ===

# === LoUtils Lib ===
add_subdirectory(lib/LoUtils)

set_target_properties(LolohUtilsPack PROPERTIES
        OUTPUT_NAME "lo_utils"
        PREFIX ""
)
set_target_properties(LolohUtilsPack_cxx PROPERTIES
        OUTPUT_NAME "lo_utils_cxx"
        PREFIX ""
)

# === rSDL3 lib ===
add_subdirectory(lib/rsdl)

# === MSWLua Wrapper ===
set(NO_DL_COPY ON CACHE BOOL "" FORCE)
add_subdirectory(lib/MSWLua)


# === PhysFS ===
set(PHYSFS_ARCHIVE_7Z      OFF CACHE BOOL "" FORCE)
set(PHYSFS_ARCHIVE_GRP     OFF CACHE BOOL "" FORCE)
set(PHYSFS_ARCHIVE_HOG     OFF CACHE BOOL "" FORCE)
set(PHYSFS_ARCHIVE_MVL     OFF CACHE BOOL "" FORCE)
set(PHYSFS_ARCHIVE_QPAK    OFF CACHE BOOL "" FORCE)
set(PHYSFS_ARCHIVE_WAD     OFF CACHE BOOL "" FORCE)
set(PHYSFS_ARCHIVE_SLB     OFF CACHE BOOL "" FORCE)
set(PHYSFS_ARCHIVE_ISO9660 OFF CACHE BOOL "" FORCE)
set(PHYSFS_ARCHIVE_VDF     OFF CACHE BOOL "" FORCE)

set(PHYSFS_ARCHIVE_ZIP     ON  CACHE BOOL "" FORCE)
set(PHYSFS_ARCHIVE_TAR     ON  CACHE BOOL "" FORCE)

set(PHYSFS_BUILD_TEST      OFF CACHE BOOL "" FORCE)
set(PHYSFS_BUILD_SHARED    OFF CACHE BOOL "" FORCE)

add_subdirectory(lib/physfs)


# === V Engine Executable ===
add_executable(VEng2
        resources/.build_res/resources.rc

        # Core section
        src/main.cpp
        include/veng/core/engine.hpp
        src/core/base.cpp
        src/core/update.cpp

        include/veng/cfg/arg_parser.hpp
        src/cfg/arg_parser.cpp

        include/veng/virtual_file_sys/vfs_class.h
        src/virtual_file_sys/base.cpp

        include/veng/scene/ent_manager.hpp
        src/scene/ent_manager.cpp

        # Render section

        # Lua section

        # UNSORTED section
        src/render/rsdl_backnd/base.cpp
        src/render/rsdl_backnd/draw.cpp
        include/veng/render/rsdl_backnd.hpp
        include/veng/script/lua_backnd.hpp
        src/script/lua_backnd/apiInit_func.cpp
        src/script/lua_backnd/base.cpp

)
target_include_directories(VEng2 PUBLIC
        include
        lib/LoUtils/include
        lib/MSWLua/include
)
target_link_libraries(VEng2 PRIVATE
        LolohUtilsPack_cxx
        MSWLua_lib
        rsdl
        physfs-static
)


# Custom CMDS.
add_custom_command(TARGET VEng2 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo "Deploying all engine bins. from shred-binary repo (VengBinary).."

        COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
        "${BINS_SOURCE_DIR}"
        "$<TARGET_FILE_DIR:VEng2>"
)