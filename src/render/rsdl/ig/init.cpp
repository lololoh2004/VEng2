#include "veng/render/rsdl.hpp"

#include <imgui.h>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_sdlgpu3.h>


bool rSDLRender::initIGUI(){
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
    // io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    ImGui_ImplSDL3_InitForSDLGPU(m_window);
    ImGui_ImplSDLGPU3_InitInfo m_igInitInfo = {
        .Device = m_gpuDevice,
        .ColorTargetFormat = SDL_GetGPUSwapchainTextureFormat(m_gpuDevice, m_window),
        .MSAASamples = SDL_GPU_SAMPLECOUNT_1,
        .SwapchainComposition = SDL_GPU_SWAPCHAINCOMPOSITION_SDR,
        .PresentMode = SDL_GPU_PRESENTMODE_VSYNC,
    };

    return ImGui_ImplSDLGPU3_Init(&m_igInitInfo);
}