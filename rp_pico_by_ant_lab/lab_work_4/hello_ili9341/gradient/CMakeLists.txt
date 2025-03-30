cmake_minimum_required(VERSION 3.13)

project(gradient)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} PUBLIC
    "${PROJECT_SOURCE_DIR}/include/gradient/gradient.h"
    "${PROJECT_SOURCE_DIR}/src/gradient.c"
)

target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/../ili9341/include")