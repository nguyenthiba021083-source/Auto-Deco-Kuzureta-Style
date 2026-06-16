cmake_minimum_required(VERSION 3.21)

project(AutoDecoKuzuretaStyle VERSION 1.0.0)

include(${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk/cmake/Geode.cmake)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
)

setup_geode_mod(${PROJECT_NAME})
