#include "veng/script/lua_backnd.hpp"

#include "mswlua/c_api/run_str_script.hpp"
#include "mswlua/ffi/build_func_cdef.hpp"
#include "mswlua/ffi/build_struct_cdef.hpp"

#include <format>


void luaScriptSys::apiInit(){
    std::string result;

    // ONLY for server side for now
    // Sorry
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

    std::string svApiBridge = std::format(
        "local ffi = require(\"ffi\")\n"
        "ffi.cdef [[\n"
        "{}\n{}\n"
        "]]\n"
        "{}\n{}\n",
        funcBuilder.getCDefContent(), structBuilder.getCDefContent(),
        structBuilder.getBindContent(), funcBuilder.getBindContent()
    );

    // m_states[SV_State].doStr(apiBridge);
    strScript(m_states[SV_State].getRaw(), svApiBridge).runScript();
}