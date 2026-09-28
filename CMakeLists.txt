cmake_minimum_required(VERSION 4.1)
project(VEng2)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY         "${CMAKE_SOURCE_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_SOURCE_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}")


include(FetchContent)
# === ALL THIRDPARTY LIBS ===
# === MSWLua Wrapper ===
add_subdirectory(lib/MSWLua)

# === My Shared Content ===
if(NOT TARGET LolohUtilsPack_cxx)
    add_subdirectory(lib/LoUtils)
endif()

# === Raylib ( Base ) ===
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_ games   OFF CACHE BOOL "" FORCE)
add_subdirectory(lib/raylib)

# === RlImGUI and ImGUI ( BRIDGE ) ===

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
        include/veng/scene/ent_manager.hpp)
target_include_directories(VEng2 PUBLIC
        include
        lib/LoHUtils/include
        lib/MSWLua/include
        lib/imgui
        lib/imgui/backends
)
target_link_libraries(VEng2 PRIVATE
        LolohUtilsPack_cxx
        MSWLua_lib
        raylib
)