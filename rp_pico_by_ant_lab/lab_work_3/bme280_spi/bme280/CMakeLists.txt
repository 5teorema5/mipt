cmake_minimum_required(VERSION 3.13)

project(bme280)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} PUBLIC
    "${PROJECT_SOURCE_DIR}/include/bme280/bme280.h"
    "${PROJECT_SOURCE_DIR}/src/bme280.c"
)

target_link_libraries(${PROJECT_NAME} 
        pico_stdlib
        hardware_spi
        )

target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/include")