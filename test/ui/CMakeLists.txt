project(test_ui)

include_directories(${PROJECT_SOURCE_DIR}/src)

project(test_ui LANGUAGES CXX)

SET(CMAKE_CXX_FLAGS_DEBUG "-g")

add_executable(test_ui main.cpp)

target_link_libraries(test_ui event)
target_link_libraries(test_ui ui)
