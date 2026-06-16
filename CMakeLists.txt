cmake_minimum_required(VERSION 3.21)

project(AutoDecoKuzuretaStyle VERSION 1.0.0)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
    src/EditorLayerBridge.cpp
    src/EditorUIHook.cpp
    src/KuzuretaGenerator.cpp
    src/LayoutAnalyzer.cpp
    src/ParallaxGenerator.cpp
    src/TriggerGenerator.cpp
)

if(NOT DEFINED ENV{GEODE_SDK})
    set(GEODE_SDK $ENV{GITHUB_WORKSPACE}/geode-sdk)
else()
    set(GEODE_SDK $ENV{GEODE_SDK})
endif()

include(${GEODE_SDK}/cmake/Geode.cmake)
setup_geode_mod(${PROJECT_NAME})
