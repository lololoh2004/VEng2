cmake_minimum_required(VERSION 4.1)
project(VEng2)


include(cmake/flags_all.cmake)


include(cmake/get_bin_files.cmake)
include(cmake/get_lib_repo.cmake)


# === DX Lib ( binary ) ===
set(DX_BIN_FILES
        "bin/x64/dxil.dll"
        "bin/x64/dxcompiler.dll"

        "lib/x64/dxil.lib"
        "lib/x64/dxcompiler.lib"
)
set(DX_BUILD_VER1 "v1.9.2609")
set(DX_BUILD_VER2 "2026_09_29")
get_bin_files(
        "${DX_BIN_FILES}"
        "DX"
        "zip"
        "${CMAKE_CURRENT_SOURCE_DIR}"
        "https://github.com/microsoft/DirectXShaderCompiler/releases/download/${DX_BUILD_VER1}/dxc_${DX_BUILD_VER2}.zip"
)


# === SPIRV_Cross Lib ( binary ) ===
set(SPIRV_CROSS_FILES
        "bin/spirv-cross-c-shared.dll"

        "lib/spirv-cross-c-shared.lib"
)
set(SPIRV_CROSS_VER "2")

get_bin_files(
        "${SPIRV_CROSS_FILES}"
        "spirv-cross"
        "zip"
        "${CMAKE_CURRENT_SOURCE_DIR}"
        "https://github.com/lololoh2004/spirv_bin/releases/download/${SPIRV_CROSS_VER}/win_x64.zip"
)


# === SDL3 Family Lib ( binary ) ===
set(SDL3_BIN_FILES
    "SDL3-x64/bin/SDL3.dll"
    "SDL3-x64/bin/SDL3_shadercross.dll"

    "SDL3-x64/lib/SDL3.lib"
    "SDL3-x64/lib/SDL3_shadercross.lib"
)
set(SDL3_BUILD_VER "2026-10-25")
get_bin_files(
        "${SDL3_BIN_FILES}"
        "SDL3"
        "zip"
        "${CMAKE_CURRENT_SOURCE_DIR}"
        "https://github.com/mmozeiko/build-sdl3/releases/download/${SDL3_BUILD_VER}/SDL3-x64-${SDL3_BUILD_VER}.zip"
)


# === SDL3 ===
get_sdl3_repo()

add_library(SDL3_lib SHARED IMPORTED)
set_target_properties(SDL3_lib PROPERTIES
        IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/SDL3.dll"
        IMPORTED_IMPLIB   "${CMAKE_CURRENT_SOURCE_DIR}/SDL3.lib"
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/lib/sdl3/include"
)


# === SDL3 ShaderCross ===
get_sdl3_sc_repo()

add_library(SDL3_shadercross_lib SHARED IMPORTED)
set_target_properties(SDL3_shadercross_lib PROPERTIES
        IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/SDL3_shadercross.dll"
        IMPORTED_IMPLIB   "${CMAKE_CURRENT_SOURCE_DIR}/SDL3_shadercross.lib"
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/lib/sdl3_sc/include"
)


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


# === rSDL3 External Lib ===
add_subdirectory(lib/rsdl)


# === MSWLua Wrapper ===
set(NO_DL_COPY ON CACHE BOOL "" FORCE)
add_subdirectory(lib/MSWLua)


# === PhysFS ===
include(cmake/flags_physfs.cmake)
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

        include/veng/virtual_file_sys/class.h
        src/virtual_file_sys/base.cpp

        include/veng/scene/ent_manager.hpp
        src/scene/ent_manager.cpp

        # Render section
        src/render/rsdl/base.cpp
        src/render/rsdl/draw.cpp
        # Lua section

        # UNSORTED section
        # include/veng/render/rsdl.hpp
        include/veng/script/lua_backnd.hpp
        src/script/lua_backnd/apiInit_func.cpp
        src/script/lua_backnd/base.cpp
        include/veng/term.hpp
        src/term/print.cpp
)
target_include_directories(VEng2 PUBLIC
        include
        lib/LoUtils/include
        lib/MSWLua/include
        lib/sdl3/include
        lib/rsdl/include
)
target_link_libraries(VEng2 PRIVATE
        LolohUtilsPack_cxx
        MSWLua_lib
        physfs-static
        rsdl
        SDL3_lib
        SDL3_shadercross_lib
)