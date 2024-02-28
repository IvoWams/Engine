cmake_minimum_required(VERSION 3.0.0)
project(Engine VERSION 0.1.0 LANGUAGES CXX)

# include(CTest)
# enable_testing()

# add_executable(Engine main.cpp)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

# include(CPack)

add_subdirectory(event)
add_subdirectory(ui)

add_executable(Engine ../test/ui/main.cpp)

target_link_libraries(Engine event)
target_link_libraries(Engine ui)
