add_library(
    ui_event_pure
    KeyEvent.hpp
    KeyEvent.cpp
    MouseClickEvent.hpp
    MouseMoveEvent.hpp
)

target_link_libraries(ui_event_pure ui_event)