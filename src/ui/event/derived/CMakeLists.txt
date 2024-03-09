add_library(
    ui_event_derived
    ClickEvent.hpp
    ClickEvent.cpp
    FocusEvent.hpp
    HoverEvent.hpp
    InputEvent.hpp
    MouseOverEvent.hpp
)

target_link_libraries(ui_event_derived ui_event memory_recycler)