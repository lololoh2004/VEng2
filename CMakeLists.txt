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


# === cGLM ===
get_cglm_repo()


# === ImGui ===
get_imgui_repo()
#get_cimgui_repo()

#set(CIMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/cimgui")
set(IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/imgui")

set(IMGUI_ALL_SOURCES
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_demo.cpp

        ${IMGUI_DIR}/backends/imgui_impl_sdl3.cpp
)

add_library(ImGuiBind STATIC ${IMGUI_ALL_SOURCES})

target_include_directories(ImGuiBind PUBLIC
        ${IMGUI_DIR}
        ${IMGUI_DIR}/backends
)

target_link_libraries(ImGuiBind PRIVATE SDL3_lib)


# === LoUtils Lib ===
get_lo_utils_repo()
add_subdirectory(lib/LoUtils)

#set_target_properties(LolohUtilsPack PROPERTIES
#        OUTPUT_NAME "lo_utils"
#        PREFIX ""
#)
#set_target_properties(LolohUtilsPack_cxx PROPERTIES
#        OUTPUT_NAME "lo_utils_cxx"
#        PREFIX ""
#)


# === MSWLua Wrapper ===
get_mswlua_repo()
set(NO_DL_COPY ON CACHE BOOL "" FORCE)
add_subdirectory(lib/MSWLua)


# === PhysFS ===
get_physfs_repo()
include(cmake/flags_physfs.cmake)
add_subdirectory(lib/physfs)


# === V Engine Executable ===
add_executable(VEng2
        resources/.build_res/resources.rc

        # Core section
        src/main.cpp
        include/veng/engine.hpp
        src/engine/init.cpp
        src/engine/update.cpp

        include/veng/vfsys.h
        src/vfsys/init.cpp

        include/veng/scene/ent_manager.hpp
        src/scene/ent_manager.cpp

        # Render section
        # Lua section

        # UNSORTED section
        include/veng/script/lua_backnd.hpp
        src/script/lua_backnd/api_init.cpp
        src/script/lua_backnd/base_init.cpp
        include/veng/term.hpp
        src/term/print.cpp
        src/input/keyboard.cpp
        src/input/mouse.cpp
        include/veng/input.hpp
        src/window/sdl_backnd/init.cpp
        src/render/rsdl_backnd/init.cpp
        src/render/rsdl_backnd/draw.cpp
        include/veng/window/sdl_backnd.hpp
        include/veng/common/structs.hpp
        src/render/rsdl_backnd/load_shader.cpp
        src/window/sdl_backnd/events.cpp
        src/window/sdl_backnd/time.cpp
        src/script/lua_backnd/do.cpp
        src/term/constructor.cpp
        src/engine/args.cpp
)
target_include_directories(VEng2 PUBLIC
        include
        lib/
        lib/LoUtils/include
        lib/MSWLua/include
        lib/sdl3/include
        lib/cglm/include
        lib/imgui
        lib/imgui/backends
        lib/cimgui
)
target_link_libraries(VEng2 PRIVATE
        LolohUtilsPack_cxx
        MSWLua_lib
        physfs-static
        SDL3_lib
        SDL3_shadercross_lib
        ImGuiBind
)