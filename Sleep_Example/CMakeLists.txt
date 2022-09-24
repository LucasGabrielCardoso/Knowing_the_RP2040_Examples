cmake_minimum_required(VERSION 3.13)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
include($ENV{PICO_EXTRAS_PATH}/external/pico_extras_import.cmake)

project(sleep_project)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(${PROJECT_NAME} 
	sleep.c
)

target_link_libraries(${PROJECT_NAME}
	pico_stdlib
	pico_time
	hardware_sleep
)

pico_add_extra_outputs(${PROJECT_NAME})
