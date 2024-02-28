add_library(
    ui_element
    Button.h
    Clickable.hpp
    Clickable.cpp
    Element.h
    Element.cpp
    Focusable.h
    Hoverable.hpp
    Hoverable.cpp
    Inputtable.hpp
    Inputtable.cpp
)

target_include_directories(ui_element PUBLIC ${CMAKE_SOURCE_DIR})

target_link_libraries(ui_element event)
