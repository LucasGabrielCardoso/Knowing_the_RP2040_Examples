cmake_minimum_required(VERSION 3.13)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(pioint_project)

pico_sdk_init()

add_executable(${PROJECT_NAME}
    pioint.c
)

pico_generate_pio_header(${PROJECT_NAME} ${CMAKE_CURRENT_LIST_DIR}/pioint.pio)

target_link_libraries(${PROJECT_NAME} PRIVATE
    pico_stdlib
    pico_sync
    hardware_pio
    hardware_irq
)

pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

pico_add_extra_outputs(${PROJECT_NAME})
