cmake_minimum_required(VERSION 3.12)
set(PICO_BOARD pico)
include(pico_sdk_import.cmake)

project(blink C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(blink)

pico_generate_pio_header(blink ${CMAKE_CURRENT_LIST_DIR}/blink.pio)

target_sources(blink PRIVATE blink.c)

target_link_libraries(blink PRIVATE pico_stdlib hardware_pio hardware_clocks)

pico_add_extra_outputs(blink)
