#include "veng/render/rsdl_backnd.hpp"

#include <SDL3_shadercross/SDL_shadercross.h>


static const char* DEFAULT_VERT_SHADER =
    "struct VSInput { float3 pos : POSITION; float2 uv : TEXCOORD; };\n"
    "struct VSOutput { float4 pos : SV_POSITION; float2 uv : TEXCOORD; };\n"
    "VSOutput VSMain(VSInput input) {\n"
    "    VSOutput output;\n"
    "    output.pos = float4(input.pos, 1.0);\n"
    "    output.uv = input.uv;\n"
    "    return output;\n"
    "}\n";

static const char* DEFAULT_FRAG_SHADER =
    "struct FSInput { float2 uv : TEXCOORD; };\n"
    "float4 FSMain(FSInput input) : SV_TARGET {\n"
    "    return float4(1.0, 0.0, 1.0, 1.0);\n"
    "}\n";

#define FS_ENTRY_POINT "FSMain"
#define VS_ENTRY_POINT "VSMain"


// static SDL_GPUShader* processShader(
//     const char* codeData,
//     size_t size,
//     rsdlShaderFormat format,
//     SDL_GPUShaderStage stage)
// {
//     // Common variables
//     SDL_GPUShader* result = NULL;
//     const char* entryPoint = stage == SDL_GPU_SHADERSTAGE_VERTEX
//         ? VS_ENTRY_POINT
//         : FS_ENTRY_POINT;
//
//     // ByteCode Variables
//     SDL_ShaderCross_ShaderStage scShaderStage = stage == SDL_GPU_SHADERSTAGE_VERTEX
//                 ? SDL_SHADERCROSS_SHADERSTAGE_VERTEX
//                 : SDL_SHADERCROSS_SHADERSTAGE_FRAGMENT;
//
//     void*  bCode = nullptr;   // bCode = byteCode
//     size_t bCodeSize = 0;
//     bool   bCodeNeedsFree = false;
//
//     switch (format)
//     {
//         case RSDL_SHADERFORMAT_SPIRV:
//         {
//             bCode = (void*)codeData;
//             bCodeSize = size;
//             bCodeNeedsFree = false;
//             break;
//         }
//         case RSDL_SHADERFORMAT_HLSL_TXT:
//         {
//             const SDL_ShaderCross_HLSL_Info hlslShInfo = {
//                 .source = codeData,
//                 .entrypoint = entryPoint,
//                 .shader_stage = scShaderStage,
//             };
//             bCode = SDL_ShaderCross_CompileSPIRVFromHLSL(&hlslShInfo, &bCodeSize);
//             bCodeNeedsFree = true;
//             break;
//         }
//         // case RSDL_SHADERFORMAT_DXIL:
//         // {
//         //     const SDL_GPUShaderCreateInfo shInfo = {
//         //         .code_size = size,
//         //         .code = (const Uint8*)codeData,
//         //         .entrypoint = entryPoint,
//         //         .stage = stage,
//         //         .format = SDL_GPU_SHADERFORMAT_DXIL,
//         //         .num_samplers = 0,
//         //         .num_uniform_buffers = 0,
//         //     };
//         //     result = SDL_CreateGPUShader(g_gpuDevice, &shInfo);
//         //
//         //     return result;
//         // }
//         default: break;
//     }
//
//     if (bCode != NULL){
//         SDL_ShaderCross_GraphicsShaderMetadata* bCodeMetadata = SDL_ShaderCross_ReflectGraphicsSPIRV(
//             bCode, bCodeSize, 0
//         );
//         if (bCodeMetadata != NULL){
//             SDL_ShaderCross_SPIRV_Info scInfo = {
//                 .bytecode = bCode,
//                 .bytecode_size = bCodeSize,
//                 .entrypoint = entryPoint,
//                 .shader_stage = scShaderStage,
//                 .props = 0,
//             };
//             result = SDL_ShaderCross_CompileGraphicsShaderFromSPIRV(
//                 m_gpuDevice, &scInfo, &bCodeMetadata->resource_info, 0
//             );
//
//             SDL_free(bCodeMetadata);
//         }
//         if (bCodeNeedsFree) SDL_free(bCode);
//     }
//
//     if (result == nullptr) {
//         SDL_LogError(
//             SDL_LOG_CATEGORY_GPU, "Shader compilation failed. Details : \n - SDL_Error : %s", SDL_GetError()
//         );
//     }
//
//     return result;
// }

// SDL_GPUShader* rSDLRender::compileShaderStr(const char* codeStr, size_t inSize, rsdlShaderFormat inFormat, rsdlShaderStage inStage){
//     // Default variables
//     SDL_GPUShaderStage sdlShStage = inStage == RSDL_SHADERSTAGE_VERTEX
//         ? SDL_GPU_SHADERSTAGE_VERTEX
//         : SDL_GPU_SHADERSTAGE_FRAGMENT;
//     const char* shCode = NULL;
//     size_t shSize = 0;
//     rsdlShaderFormat finalFormat;
//
//     if (codeStr == NULL){
//         shCode = inStage == RSDL_SHADERSTAGE_VERTEX
//             ? DEFAULT_VERT_SHADER
//             : DEFAULT_FRAG_SHADER;
//         shSize = SDL_strlen(shCode);
//         finalFormat = RSDL_SHADERFORMAT_HLSL_TXT;
//     } else{
//         shCode = codeStr;
//         shSize = inSize;
//         finalFormat = inFormat;
//     }
//
//     // Compile and return
//     return processShader(shCode, shSize, finalFormat, sdlShStage);
// }

void rSDLRender::destroyShader(SDL_GPUShader* shader){
    if (shader == nullptr) return;
    SDL_ReleaseGPUShader(m_gpuDevice, shader);
}