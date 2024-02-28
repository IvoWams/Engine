add_subdirectory(derived)
add_subdirectory(pure)
add_subdirectory(trait)

add_library(
    ui_event
    UIEvent.hpp
    UIEvent.cpp
)

target_include_directories(ui_event PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(ui_event ui_event_derived)
target_link_libraries(ui_event ui_event_pure)
target_link_libraries(ui_event ui_event_trait)
