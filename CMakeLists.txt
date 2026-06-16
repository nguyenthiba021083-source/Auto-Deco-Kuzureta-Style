cmake_minimum_required(VERSION 3.21)

project(AutoDecoKuzuretaStyle VERSION 1.0.0)

include(cmake/CPM.cmake)

CPMAddPackage(
    NAME Geode
    GITHUB_REPOSITORY geode-sdk/geode
    GIT_TAG v5.7.1
)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
    src/EditorLayerBridge.cpp
    src/EditorUIHook.cpp
    src/KuzuretaGenerator.cpp
    src/LayoutAnalyzer.cpp
    src/ParallaxGenerator.cpp
    src/TriggerGenerator.cpp
)

setup_geode_mod(${PROJECT_NAME})
