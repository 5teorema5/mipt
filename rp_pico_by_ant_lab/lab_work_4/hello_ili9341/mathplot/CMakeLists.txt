cmake_minimum_required(VERSION 3.13)

project(mathplot)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} PUBLIC
    "${PROJECT_SOURCE_DIR}/include/mathplot/mathplot.h"
    "${PROJECT_SOURCE_DIR}/src/mathplot.c"
)

target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/../ili9341/include")