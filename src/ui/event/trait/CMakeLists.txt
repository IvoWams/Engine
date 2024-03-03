add_library(
    ui_event_trait
    Positional.hpp
    TargetsElement.hpp
    TargetsElement.cpp
)

target_link_libraries(ui_event_trait ui_element)