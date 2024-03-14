project(test_engine)

include_directories(${PROJECT_SOURCE_DIR}/src)

project(event VERSION 0.1.0 LANGUAGES CXX)

SET(CMAKE_CXX_FLAGS_DEBUG "-g")

add_executable(test_engine test_engine_events.cpp)
add_executaBLE(test_timer test_engine_timer.cpp)

target_link_libraries(test_engine event)
target_link_libraries(test_engine engine)

