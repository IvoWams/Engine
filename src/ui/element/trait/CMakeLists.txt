add_library(
    ui_element_trait
    Focusable.h
    Hoverable.hpp
    Hoverable.cpp
    Inputtable.hpp
    Inputtable.cpp
    Clickable.hpp
    Clickable.cpp
)

target_include_directories(ui_element_trait PUBLIC ${CMAKE_SOURCE_DIR})

target_link_libraries(ui_element_trait event)
