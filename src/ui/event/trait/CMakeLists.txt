add_library(
    ui_event_trait
    Positional.hpp
    Positional.cpp
    TargetsElement.hpp
    TargetsElement.cpp
)

target_link_libraries(ui_event_trait ui_element)