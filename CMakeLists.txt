cmake_minimum_required(VERSION 3.21)

project(AutoDecoKuzuretaStyle VERSION 1.0.0)

find_package(Geode REQUIRED)

add_library(${PROJECT_NAME} SHARED
    src
