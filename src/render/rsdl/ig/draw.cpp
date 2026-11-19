#include "veng/render/rsdl.hpp"

#include <imgui_impl_sdl3.h>
#include <imgui_impl_sdlgpu3.h>

#include "SDL3/SDL_events.h"


void rSDLRender::updateIGUIEvents(const SDL_Event* rawEvent){
    if (rawEvent){
        ImGui_ImplSDL3_ProcessEvent(rawEvent);
    }
}
void rSDLRender::beginIGUI(){
    ImGui_ImplSDLGPU3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();
}
void rSDLRender::showDemoIGUI(){
    ImGui::ShowDemoWindow();
}
void rSDLRender::endIGUI(){
    ImGui::Render();

    if (m_swapchainTexture == nullptr) return;

    ImDrawData* drawData = ImGui::GetDrawData();
    ImGui_ImplSDLGPU3_PrepareDrawData(drawData, m_cmdBuffer);

    SDL_GPUColorTargetInfo target_info = {
        .texture = m_swapchainTexture,
        .load_op = SDL_GPU_LOADOP_LOAD,
        .store_op = SDL_GPU_STOREOP_STORE,
    };

    SDL_GPURenderPass* igRenderPass = SDL_BeginGPURenderPass(m_cmdBuffer, &target_info, 1, nullptr);
    ImGui_ImplSDLGPU3_RenderDrawData(drawData, m_cmdBuffer, igRenderPass);
    SDL_EndGPURenderPass(igRenderPass);
}