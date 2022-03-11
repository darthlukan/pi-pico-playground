cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(hello_world C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(hello_world hello_world.c)
pico_add_extra_outputs(hello_world)

target_link_libraries(hello_world pico_stdlib)
