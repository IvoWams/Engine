
# include(CTest)
# enable_testing()

# add_executable(Engine main.cpp)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

# include(CPack)

add_subdirectory(event)
add_subdirectory(ui)

# add_executable(engine ../test/ui/main.cpp)

# target_link_libraries(engine event)
# target_link_libraries(engine ui)
