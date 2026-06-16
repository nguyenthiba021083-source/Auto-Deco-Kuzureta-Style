cmake_minimum_required(VERSION 3.21)

project(AutoDecoKuzuretaStyle VERSION 1.0.0)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
    src/EditorUIHook.cpp
    src/KuzuretaGenerator.cpp
    src/LayoutAnalyzer.cpp
    src/EditorLayerBridge.cpp
    src/TriggerGenerator.cpp
    src/ParallaxGenerator.cpp
)

if(NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "GEODE_SDK not found")
endif()

include($ENV{GEODE_SDK}/cmake/Geode.cmake)

setup_geode_mod(${PROJECT_NAME})
