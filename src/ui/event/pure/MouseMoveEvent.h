#ifndef ENGINE_UI_EVENT_MOUSEMOVEEVENT_H
#define ENGINE_UI_EVENT_MOUSEMOVEEVENT_H

#include "ui/event/UIEvent.hpp"
#include "ui/event/trait/Positional.hpp"

using ui::event::trait::Positional;

namespace ui::event::pure
{
    class MouseMoveEvent :
        UIEvent
    {
        public:
            MouseMoveEvent() {}
    };
}

#endif