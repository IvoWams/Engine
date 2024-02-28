add_library(
    ui_event_derived
    ClickEvent.hpp
    ClickEvent.cpp
    FocusEvent.h
    HoverEvent.h
    InputEvent.h
    MouseOverEvent.h
)

target_link_libraries(ui_event_derived ui_event)