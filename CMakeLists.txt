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
)
FetchContent_MakeAvailable(LolohUtilsPack)

# === My MSWLua Lib ===
FetchContent_Declare(
        MSWLua
        GIT_REPOSITORY "https://github.com/lololoh2004/MSWLua.git"
        GIT_TAG        main
)
FetchContent_MakeAvailable(MSWLua)


# === V Engine Executable ===
add_executable(VEng2
        resources.rc
        src/main.cpp
        src/core/main_core.cpp
        src/core/main_core.hpp)
target_link_libraries(VEng2 PRIVATE
        LolohUtils
        MSWLua_lib
)


# === Dll Copy ===
# Lua51.dll copy
add_custom_command(TARGET VEng2 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${mswlua_SOURCE_DIR}/lib/luajit2/win64/lua51.dll"
        "$<TARGET_FILE_DIR:VEng2>"
)