cmake_minimum_required(VERSION 3.21)

project(AutoDecoKuzuretaStyle VERSION 1.0.0)

find_package(Geode REQUIRED)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
    src/EditorUIHook.cpp
    src/KuzuretaGenerator.cpp
    src/LayoutAnalyzer.cpp
    src/EditorLayerBridge.cpp
    src/TriggerGenerator.cpp
    src/ParallaxGenerator.cpp
)

target_compile_features(${PROJECT_NAME}
    PRIVATE
    cxx_std_20
)

setup_geode_mod(${PROJECT_NAME})
