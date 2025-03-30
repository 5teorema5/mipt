cmake_minimum_required(VERSION 3.13)

project(ili9341)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} PUBLIC
    "${PROJECT_SOURCE_DIR}/include/ili9341/ili9341.h"
    "${PROJECT_SOURCE_DIR}/src/ili9341.c"
)

# Add any user requested libraries
target_link_libraries(${PROJECT_NAME} 
        pico_stdlib
        hardware_spi
        )

target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/include")
