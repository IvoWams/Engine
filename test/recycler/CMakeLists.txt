project(test_recycler)

include_directories(${PROJECT_SOURCE_DIR}/src)

SET(CMAKE_CXX_FLAGS_DEBUG "-g")

add_executable(test_recycler main.cpp)

target_link_libraries(test_recycler memory_recycler)
