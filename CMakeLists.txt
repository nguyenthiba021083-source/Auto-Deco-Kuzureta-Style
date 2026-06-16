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

find_package(Geode REQUIRED)

setup_geode_mod(${PROJECT_NAME})
