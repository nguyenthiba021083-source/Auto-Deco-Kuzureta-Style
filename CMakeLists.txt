cmake_minimum_required(VERSION 3.21)

project(AutoDecoKuzuretaStyle)

find_package(Geode REQUIRED)

add_library(${PROJECT_NAME}
    src/main.cpp
    src/EditorUIHook.cpp
    src/KuzuretaGenerator.cpp
    src/LayoutAnalyzer.cpp
    src/EditorLayerBridge.cpp
    src/TriggerGenerator.cpp
    src/ParallaxGenerator.cpp
)

setup_geode_mod(${PROJECT_NAME})
