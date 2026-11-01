set(PROJECT_LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(GITHUB_URL "https://github.com/")


set(SDL3_REPO_URL "${GITHUB_URL}/libsdl-org/SDL")
set(SDL3_REPO_PATH "${PROJECT_LIB_PATH}/sdl3")

set(SDL3_SC_REPO_URL "${GITHUB_URL}/libsdl-org/SDL_shadercross")
set(SDL3_SC_REPO_PATH "${PROJECT_LIB_PATH}/sdl3_sc")


function(get_sdl3_repo)
    if(NOT EXISTS "${SDL3_REPO_PATH}/include")

        message("[CMAKE] : SDL3 repository not found. Cloning...")
        execute_process(
                COMMAND git clone --depth 1 "${SDL3_REPO_URL}" "${SDL3_REPO_PATH}"
        )

    else()

        message("[CMAKE] : SDL3 repository found")

    endif()
endfunction()

function(get_sdl3_sc_repo)
    if(NOT EXISTS "${SDL3_SC_REPO_PATH}/include")

        message("[CMAKE] : SDL3 ShaderCross repository not found. Cloning...")
        execute_process(
                COMMAND git clone --depth 1 "${SDL3_SC_REPO_URL}" "${SDL3_SC_REPO_PATH}"
        )

    else()

        message("[CMAKE] : SDL3 ShaderCross repository found")

    endif()
endfunction()