#pragma once

#include "veng/common/structs.hpp"


struct SDL_GPUDevice;
struct SDL_Window;
struct SDL_GPUCommandBuffer;
struct SDL_GPUTexture;
struct SDL_GPUShader;
struct SDL_GPURenderPass;
union  SDL_Event;


// typedef enum rsdlShaderStage {
//     RSDL_SHADERSTAGE_VERTEX,
//     RSDL_SHADERSTAGE_FRAGMENT
// } rsdlShaderStage;
//
// typedef enum rsdlShaderFormat{
//     RSDL_SHADERFORMAT_HLSL_TXT,
//     RSDL_SHADERFORMAT_SPIRV,
//     RSDL_SHADERFORMAT_DXIL,
// } rsdlShaderFormat;
//
// typedef struct shaderFileInfo{
//     bool isValid;
//     rsdlShaderFormat format;
//     size_t size;
//     char* content;
// } shaderFileInfo;
//
// typedef struct SDLShaderWrapper {
//     shaderFileInfo fileInfo;
//     SDL_GPUShader* sdlShader;
//     rsdlShaderStage stage;
// } SDLShaderWrapper;


class rSDLRender{
    SDL_GPUCommandBuffer* m_cmdBuffer  = nullptr;
    SDL_GPUTexture* m_swapchainTexture = nullptr;
    SDL_GPURenderPass* m_renderPass    = nullptr;

    SDL_GPUDevice*  m_gpuDevice = nullptr;
    SDL_Window*     m_window    = nullptr;

    colRGBA m_bgColor = { 255, 255, 255, 255 };

    void draw();
    // SDL_GPUShader* processShader(const char* codeData, size_t size, rsdlShaderFormat format, SDL_GPUShaderStage stage);
public:
    rSDLRender(SDL_Window* window) : m_window(window) {}
    ~rSDLRender() = default;

    bool initRender();

    void beginDraw();
    void endDraw();

    void setBgColor(colRGBA color) { m_bgColor = color; }

    // SDL_GPUShader* compileShaderStr(const char* codeStr, size_t inSize, rsdlShaderFormat inFormat, rsdlShaderStage inStage);
    void destroyShader(SDL_GPUShader* shader);


    bool initIGUI();

    void updateIGUIEvents(const SDL_Event* rawEvent);

    void beginIGUI();
    void endIGUI();
    void showDemoIGUI();


    void submitGPUBuf();
};
