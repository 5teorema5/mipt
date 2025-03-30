# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(hello_ili9341 C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(hello_ili9341 hello_ili9341.c )

pico_set_program_name(hello_ili9341 "hello_ili9341")
pico_set_program_version(hello_ili9341 "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(hello_ili9341 0)
pico_enable_stdio_usb(hello_ili9341 1)

# Add the standard library to the build
target_link_libraries(hello_ili9341
        pico_stdlib)

# Add the standard include files to the build
target_include_directories(hello_ili9341 PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

target_sources(${PROJECT_NAME} PUBLIC
    "${PROJECT_SOURCE_DIR}/ant-lab/ant-lab.h"
    "${PROJECT_SOURCE_DIR}/ant-lab/ant-lab.c"
)

# Add any user requested libraries
target_link_libraries(hello_ili9341 
        hardware_spi
        ili9341
        square-swarm
        gradient
        )

pico_add_extra_outputs(hello_ili9341)

add_subdirectory("${PROJECT_SOURCE_DIR}/ili9341" "${PROJECT_BINARY_DIR}/ili9341")
add_subdirectory("${PROJECT_SOURCE_DIR}/square-swarm" "${PROJECT_BINARY_DIR}/square-swarm")
add_subdirectory("${PROJECT_SOURCE_DIR}/gradient" "${PROJECT_BINARY_DIR}/gradient")

target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/ant-lab")