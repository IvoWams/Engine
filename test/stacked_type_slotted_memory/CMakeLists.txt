project(stacked_type_slotted_memory)

include_directories(${PROJECT_SOURCE_DIR}/src)

SET(CMAKE_CXX_FLAGS_DEBUG "-g")

add_executable(stacked_type_slotted_memory main.cpp)

target_link_libraries(stacked_type_slotted_memory memory_slot_stack)
