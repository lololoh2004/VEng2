#include <format>

#include "mswlua/c_api/doScript_funcs.hpp"
#include "veng/script/lua_backnd.hpp"

#include "mswlua/ffi/build_func_cdef.hpp"
#include "mswlua/ffi/build_struct_cdef.hpp"


void luaScriptSys::apiInit(){
    std::string result;

    structBuilder structBuilder;
    structBuilder
        .createStruct("vec3")
        .var("float", "x")
        .var("float", "y")
        .var("float", "z")
    .commitAll();

    funcBuilder funcBuilder;
    funcBuilder
    .commitAll();

    std::string apiBridge = std::format(
        "local ffi = require(\"ffi\")\n"
        "ffi.cdef [[\n"
        "{}\n{}\n"
        "]]\n"
        "{}\n{}\n",
        funcBuilder.getCDefContent(), structBuilder.getCDefContent(),
        structBuilder.getBindContent(), funcBuilder.getBindContent()
    );

    doScriptStr(m_L, apiBridge);
}