
# include(CTest)
# enable_testing()

# add_executable(Engine linear.cpp)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

# include(CPack)

add_subdirectory(event)
add_subdirectory(ui)
add_subdirectory(memory)
add_subdirectory(engine)
add_subdirectory(keyframe)




# add_executable(engine ../test/ui/linear.cpp)

# target_link_libraries(engine event)
# target_link_libraries(engine ui)
