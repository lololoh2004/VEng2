#include "veng/lua/get_bind_code.hpp"

#include "string"
#include "mswlua/ffi/build_func_cdef.hpp"
#include "mswlua/ffi/build_struct_cdef.hpp"


std::string getCBind(){
    std::string result;

    structBuilder stBuilder;
    stBuilder
        .createStruct("vec3")
        .var("float", "x")
        .var("float", "y")
        .var("float", "z")
    .commitAll();

    funcBuilder funcBuilder;
    funcBuilder
    // .createFunc("Beep")
    //     .path("api")
    //     .returnType("int")
    //     .arg("unsigned long", "dwFreq")
    //     .arg("unsigned long", "dwDuration")
    // .createFunc("debug_func")
    //     .returnType("void")
    //     .arg("int", "intStd")
    .commitAll();

    result =
        std::string("local ffi = require(\"ffi\")\n") +
        "ffi.cdef[[\n" +
        funcBuilder.getCDefContent() +
        stBuilder.getCDefContent() +
        "]]\n" +
        stBuilder.getBindContent() +
        funcBuilder.getBindContent();

    return result;
}
