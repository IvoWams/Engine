add_library(
    ui_event_pure
    KeyEvent.h
    KeyEvent.cpp
    MouseClickEvent.h
    MouseMoveEvent.h
)

target_link_libraries(ui_event_pure ui_event)