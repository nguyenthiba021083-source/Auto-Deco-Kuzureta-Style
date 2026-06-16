cmake_minimum_required(VERSION 3.21)

project(AutoDecoKuzuretaStyle VERSION 1.0.0)

include(${CMAKE_SOURCE_DIR}/geode-sdk/cmake/Geode.cmake)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
    src/EditorUIHook.cpp
    src/KuzuretaGenerator.cpp
    src/LayoutAnalyzer.cpp
    src/EditorLayerBridge.cpp
    src/TriggerGenerator.cpp
    src/ParallaxGenerator.cpp
)

setup_geode_mod(${PROJECT_NAME})
