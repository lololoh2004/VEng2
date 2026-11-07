set(PROJECT_LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(GITHUB_URL "https://github.com")


function(internal_get_lib_repo name url path)
    if(NOT EXISTS "${path}")

        message("[CMAKE] : ${name} repository not found. Cloning...")
        execute_process(
                COMMAND git clone --depth 1 "${url}" "${path}"
        )

    else()

        message("[CMAKE] : ${name} repository found")

    endif()
endfunction()


set(SDL3_REPO_URL  "${GITHUB_URL}/libsdl-org/SDL")
set(SDL3_REPO_PATH "${PROJECT_LIB_PATH}/sdl3")

function(get_sdl3_repo)
    internal_get_lib_repo(
        SDL3
        ${SDL3_REPO_URL}
        ${SDL3_REPO_PATH}
    )
endfunction()


set(SDL3_SC_REPO_URL  "${GITHUB_URL}/libsdl-org/SDL_shadercross")
set(SDL3_SC_REPO_PATH "${PROJECT_LIB_PATH}/sdl3_sc")

function(get_sdl3_sc_repo)
    internal_get_lib_repo(
        SDL3_ShaderCross
        ${SDL3_SC_REPO_URL}
        ${SDL3_SC_REPO_PATH}
    )
endfunction()


set(CGLM_REPO_URL  "${GITHUB_URL}/recp/cglm")
set(CGLM_REPO_PATH "${PROJECT_LIB_PATH}/cglm")

function(get_cglm_repo)
    internal_get_lib_repo(
        cGLM
        ${CGLM_REPO_URL}
        ${CGLM_REPO_PATH}
    )
endfunction()


set(LOUTILS_REPO_URL  "${GITHUB_URL}/lololoh2004/LolohUtilsPack")
set(LOUTILS_REPO_PATH "${PROJECT_LIB_PATH}/LoUtils")

function(get_lo_utils_repo)
    internal_get_lib_repo(
        LoUtils
        ${LOUTILS_REPO_URL}
        ${LOUTILS_REPO_PATH}
    )
endfunction()


set(MSWLUA_REPO_URL  "${GITHUB_URL}/lololoh2004/MSWLua")
set(MSWLUA_REPO_PATH "${PROJECT_LIB_PATH}/MSWLua")

function(get_mswlua_repo)
    internal_get_lib_repo(
        MSWLua
        ${MSWLUA_REPO_URL}
        ${MSWLUA_REPO_PATH}
    )
endfunction()


set(PHYSFS_REPO_URL  "${GITHUB_URL}/icculus/physfs")
set(PHYSFS_REPO_PATH "${PROJECT_LIB_PATH}/physfs")

function(get_physfs_repo)
    internal_get_lib_repo(
        PhysFS
        ${PHYSFS_REPO_URL}
        ${PHYSFS_REPO_PATH}
    )
endfunction()


#set(CIMGUI_REPO_URL  "${GITHUB_URL}/cimgui/cimgui")
#set(CIMGUI_REPO_PATH "${PROJECT_LIB_PATH}/cimgui")
#
#function(get_cimgui_repo)
#    internal_get_lib_repo(
#        cImGui
#        ${CIMGUI_REPO_URL}
#        ${CIMGUI_REPO_PATH}
#    )
#endfunction()


set(IMGUI_REPO_URL  "${GITHUB_URL}/ocornut/imgui")
set(IMGUI_REPO_PATH "${PROJECT_LIB_PATH}/imgui")

function(get_imgui_repo)
    if(NOT EXISTS "${IMGUI_REPO_PATH}")

        message("[CMAKE] : ImGUI repository not found. Cloning...")
        execute_process(
                COMMAND git clone --branch docking --depth 1 "${IMGUI_REPO_URL}" "${IMGUI_REPO_PATH}"
        )

    else()

        message("[CMAKE] : ImGUI repository found")

    endif()
endfunction()