#include "veng/render/rsdl.hpp"

#include <SDL3/SDL_error.h>
#include <SDL3/SDL_gpu.h>
#include <SDL3/SDL_init.h>

#include "veng/term.hpp"
#include "veng/common/color_presets.h"


bool rSDLRender::initRender(){
    // SDL_GPUShaderFormat formats = SDL_GPU_SHADERFORMAT_SPIRV | SDL_GPU_SHADERFORMAT_MSL | SDL_GPU_SHADERFORMAT_DXIL;
    SDL_GPUShaderFormat formats = SDL_GPU_SHADERFORMAT_SPIRV;
    m_gpuDevice = SDL_CreateGPUDevice(formats, true, nullptr);
    if (!m_gpuDevice){
        log(std::string("GPU device creation failed : ").append(SDL_GetError()), "SDL_GPU", CLR_RED);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }
    log("GPU device created", "SDL_GPU", CLR_GREEN);

    if (!SDL_ClaimWindowForGPUDevice(m_gpuDevice, m_window)){
        log(std::string("Failed to bind GPU to window : ").append(SDL_GetError()), "SDL_GPU", CLR_RED);
        return false;
    }
    log("GPU bound to window", "SDL_GPU", CLR_GREEN);
    log("Render init. successfully", "SDL_GPU", CLR_GREEN);

    return true;
}
