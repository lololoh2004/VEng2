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

# === MSWLua Wrapper ===
set(NO_DL_COPY ON CACHE BOOL "" FORCE)
add_subdirectory(lib/MSWLua)

# === Raylib ( Base ) ===
add_subdirectory(lib/raylib)
# Custom shared name
set_target_properties(raylib PROPERTIES
        OUTPUT_NAME "rlib"
        PREFIX ""
)

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

        src/main.cpp
        src/core/main_core.cpp
        include/veng/core/main_core.hpp
        include/veng/render/raylib_backnd/render_class.hpp
        src/render/raylib_backnd/base.cpp
        src/render/raylib_backnd/draw.cpp
        src/scene/ent_manager.cpp
        include/veng/scene/ent_manager.hpp
        src/core/debug_func.cpp
        src/lua/get_bind_code.cpp
        include/veng/lua/get_bind_code.hpp
        include/veng/virtual_file_sys/vfs_class.h
        src/virtual_file_sys/base.cpp)
target_include_directories(VEng2 PUBLIC
        include
        lib/LoUtils/include
        lib/MSWLua/include
        lib/imgui
        lib/imgui/backends
)
target_link_libraries(VEng2 PRIVATE
        LolohUtilsPack_cxx
        MSWLua_lib
        raylib
        physfs-static
)


# PLACEHOLDER CMDS.
if(WIN32)
    add_custom_command(TARGET VEng2 POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:raylib>
            "${CMAKE_CURRENT_SOURCE_DIR}/lib/MSWLua/lib/luajit2/win64/lua51.dll"
            "$<TARGET_FILE_DIR:VEng2>"
    )
endif()