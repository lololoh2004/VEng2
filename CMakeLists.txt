cmake_minimum_required(VERSION 4.1)
project(VEng2)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY         "${CMAKE_SOURCE_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_SOURCE_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}")


include(FetchContent)
# === My UtilsPack Lib ===
FetchContent_Declare(
        LolohUtilsPack
        GIT_REPOSITORY "https://github.com/lololoh2004/LolohUtilsPack.git"
        GIT_TAG        main
        SOURCE_DIR     "${CMAKE_CURRENT_SOURCE_DIR}/lib/LoUtils"
)
FetchContent_MakeAvailable(LolohUtilsPack)


# === My MSWLua Lib ===
FetchContent_Declare(
        MSWLua
        GIT_REPOSITORY "https://github.com/lololoh2004/MSWLua.git"
        GIT_TAG        main
        SOURCE_DIR     "${CMAKE_CURRENT_SOURCE_DIR}/lib/MSWLua"
)
FetchContent_MakeAvailable(MSWLua)


# === PhysFS Lib ===
FetchContent_Declare(
        physfs
        GIT_REPOSITORY "https://github.com/icculus/physfs.git"
        GIT_TAG        main
        SOURCE_DIR     "${CMAKE_CURRENT_SOURCE_DIR}/lib/physfs"
)
FetchContent_MakeAvailable(physfs)


# === RayLib Lib ( MAIN ) ===
#set(GRAPHICS "GRAPHICS_API_OPENGL_ES3" CACHE STRING "Graphics API to use" FORCE)
FetchContent_Declare(
        raylib
        GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
        GIT_TAG        "master"
        SOURCE_DIR     "${CMAKE_CURRENT_SOURCE_DIR}/lib/raylib"
)
FetchContent_MakeAvailable(raylib)


# === RlImGUI and ImGUI ( BRIDGE )
FetchContent_Declare(
        rlimgui
        GIT_REPOSITORY "https://github.com/raylib-extras/rlImGui.git"
        GIT_TAG        "main"
        SOURCE_DIR     "${CMAKE_CURRENT_SOURCE_DIR}/lib/rlImGui"
)
FetchContent_MakeAvailable(rlimgui)

FetchContent_Declare(
        imgui_core
        GIT_REPOSITORY "https://github.com/ocornut/imgui.git"
        GIT_TAG        "docking"
        SOURCE_DIR     "${CMAKE_CURRENT_SOURCE_DIR}/lib/imgui"
)
FetchContent_MakeAvailable(imgui_core)

add_library(rlimgui STATIC
        "lib/rlImGui/rlImGui.cpp"
        "lib/imgui/imgui.cpp"
        "lib/imgui/imgui_draw.cpp"
        "lib/imgui/imgui_tables.cpp"
        "lib/imgui/imgui_widgets.cpp"
        "lib/imgui/imgui_demo.cpp"
)
target_include_directories(rlimgui PUBLIC
        "lib/rlImGui"
        "lib/imgui"
)
target_link_libraries(rlimgui PUBLIC raylib)


# === V Engine Executable ===
add_executable(VEng2
        resources/.build_res/resources.rc
        src/main.cpp
        src/core/main_core.cpp
        include/veng/core/main_core.hpp
        include/veng/render/raylib_backnd/render_class.hpp
        src/render/raylib_backnd/base.cpp
        include/veng/defines.h
        src/render/raylib_backnd/draw.cpp)
target_include_directories(VEng2 PUBLIC
        src/
        include/
)
target_link_libraries(VEng2 PRIVATE
        LolohUtils
        MSWLua_lib
        physfs-static
        rlimgui
        raylib
)


# === Dll Copy ===
# Lua51.dll copy
add_custom_command(TARGET VEng2 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/lib/MSWLua/lib/luajit2/win64/lua51.dll"
        "$<TARGET_FILE_DIR:VEng2>"
)