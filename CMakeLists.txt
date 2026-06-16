cmake_minimum_required(VERSION 3.21)

project(AutoDecoKuzuretaStyle)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
    src/EditorUIHook.cpp
    src/KuzuretaGenerator.cpp
    src/LayoutAnalyzer.cpp
    src/EditorLayerBridge.cpp
    
    src/TriggerGenerator.cpp
    src/ParallaxGenerator.cpp
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
