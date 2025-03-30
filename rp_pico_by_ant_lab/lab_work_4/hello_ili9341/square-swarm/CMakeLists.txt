cmake_minimum_required(VERSION 3.13)

project(square-swarm)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} PUBLIC
    "${PROJECT_SOURCE_DIR}/include/square-swarm/square-swarm.h"
    "${PROJECT_SOURCE_DIR}/src/square-swarm.c"
)

target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/../ili9341/include")