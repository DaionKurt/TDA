cmake_minimum_required(VERSION 3.6)
project(TDA)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall")
set(TDA_VERSION_MAJOR 1)
set(TDA_VERSION_MINOR 0)

set(SOURCE_FILES main.cpp)
add_executable(TDA ${SOURCE_FILES})