#include "lo_utils/cxx_wrap/term.hpp"
#include "veng/render/rsdl_backnd.hpp"

#include "SDL3/SDL_error.h"
#include "SDL3/SDL_gpu.h"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_log.h"


bool rSDLRender::initRender(){
    // SDL_GPUShaderFormat formats = SDL_GPU_SHADERFORMAT_SPIRV | SDL_GPU_SHADERFORMAT_MSL | SDL_GPU_SHADERFORMAT_DXIL;
    SDL_GPUShaderFormat formats = SDL_GPU_SHADERFORMAT_SPIRV | SDL_GPU_SHADERFORMAT_MSL;
    m_gpuDevice = SDL_CreateGPUDevice(formats, true, NULL);
    if (!m_gpuDevice){
        SDL_LogError(SDL_LOG_CATEGORY_GPU, "GPU device creation failed : %s", SDL_GetError());
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }
    SDL_LogInfo(SDL_LOG_CATEGORY_GPU, "GPU device created");

    if (!SDL_ClaimWindowForGPUDevice(m_gpuDevice, m_window)){
        SDL_LogError(SDL_LOG_CATEGORY_GPU, "Failed to bind GPU to window : %s", SDL_GetError());
        return false;
    }
    SDL_LogInfo(SDL_LOG_CATEGORY_GPU, "GPU bound to window");

    term::msg("Render init. successfully", "SDL_GPU", COLOR_GREEN);
    return true;
}
