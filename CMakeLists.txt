cmake_minimum_required(VERSION 3.16)
set(CMAKE_TOOLCHAIN_FILE "toolchain.cmake")
project("demo")

include_directories(code code/driver code/common code/tasks)

file(GLOB_RECURSE ALL_LIBRIRY_SRCS "code/*.c")

add_executable(${PROJECT_NAME} ${ALL_LIBRIRY_SRCS})

function(ihx_to_hex bin)
    add_custom_command(TARGET ${bin} POST_BUILD COMMAND  packihx ${bin}.ihx > ${bin}.hex)
endfunction(ihx_to_hex)
ihx_to_hex(${PROJECT_NAME})
