cmake_minimum_required(VERSION 3.21)

project(AutoDecoKuzuretaStyle VERSION 1.0.0)

add_library(${PROJECT_NAME}
    src/main.cpp
    src/EditorUIHook.cpp
)

find_package(Geode REQUIRED)

setup_geode_mod(${PROJECT_NAME})
