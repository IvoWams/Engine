project(test_event)

include_directories(${PROJECT_SOURCE_DIR}/src)

project(test_event VERSION 0.1.0 LANGUAGES CXX)

SET(CMAKE_CXX_FLAGS_DEBUG "-g")

add_executable(test_event main.cpp)

target_link_libraries(test_event event)
