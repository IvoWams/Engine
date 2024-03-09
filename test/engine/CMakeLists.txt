project(test_engine)

include_directories(${PROJECT_SOURCE_DIR}/src)

SET(CMAKE_CXX_FLAGS_DEBUG "-g")

add_executable(test_engine main.cpp)

target_link_libraries(test_engine event)
target_link_libraries(test_engine engine)

