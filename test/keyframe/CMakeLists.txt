project(test_keyframe)

cmake_minimum_required(VERSION 3.28)

include_directories(${PROJECT_SOURCE_DIR}/src)

project(test_keyframe VERSION 0.1.0 LANGUAGES CXX)

SET(CMAKE_CXX_FLAGS_DEBUG "-g")

add_executable(test_keyframe_algorithm linear.cpp)
add_executable(test_keyframe_algorithm_object object.cpp)

target_link_libraries(test_keyframe_algorithm keyframe_algorithm)
