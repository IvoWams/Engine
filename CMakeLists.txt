cmake_minimum_required(VERSION 3.0.0)

project(Engine VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")
add_compile_options(-std=c++20)

include_directories(${PROJECT_SOURCE_DIR}/src)

add_subdirectory(src)
add_subdirectory(test)
