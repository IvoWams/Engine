add_subdirectory(element)
add_subdirectory(event)

add_library(
    ui
    UIEventHandler.hpp
    UIEventHandler.cpp
)

target_include_directories(ui PUBLIC ${CMAKE_SOURCE_DIR})

# target_include_directories(ui PUBLIC ../src)
target_link_libraries(ui ui_element)
target_link_libraries(ui ui_event)
