#include "veng/render/rsdl_backnd.hpp"

#include <SDL3/SDL_gpu.h>


void draw();

void rSDLRender::beginDraw(){
    m_cmdBuffer = SDL_AcquireGPUCommandBuffer(m_gpuDevice);
    m_swapchainTexture = nullptr;
    if (!SDL_WaitAndAcquireGPUSwapchainTexture(
        m_cmdBuffer, m_window, &m_swapchainTexture,
        nullptr, nullptr))
    {
        //nah
    }
    draw();
}

void rSDLRender::setBgColor(colRGBA bgColor){
    m_bgColor = bgColor;
}

void rSDLRender::draw(){
    if (!m_swapchainTexture) return;

    SDL_FColor fColor = {
        static_cast<float>(m_bgColor.r) / 255.0f,
        static_cast<float>(m_bgColor.g) / 255.0f,
        static_cast<float>(m_bgColor.b) / 255.0f,
        static_cast<float>(m_bgColor.a) / 255.0f,
    };
    SDL_GPUColorTargetInfo clrTargetInfo = {
        .texture = m_swapchainTexture,
        .clear_color = fColor,
        .load_op = SDL_GPU_LOADOP_CLEAR,
        .store_op = SDL_GPU_STOREOP_STORE,
        .cycle = false
    };

    m_renderPass = SDL_BeginGPURenderPass(
        m_cmdBuffer, &clrTargetInfo, 1, NULL);
}

void rSDLRender::endDraw(){
    if (m_renderPass){
        SDL_EndGPURenderPass(m_renderPass);
        m_renderPass = nullptr;
    }
    SDL_SubmitGPUCommandBuffer(m_cmdBuffer);
}