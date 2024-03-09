#ifndef UI_EVENT_MOUSEMOVEEVENT_HPP
#define UI_EVENT_MOUSEMOVEEVENT_HPP

#include "ui/event/UIEvent.hpp"
#include "ui/event/trait/Positional.hpp"
#include "memory/recycler/Recycler.hpp"

using ui::event::trait::Positional;
using memory::recycler::Recycler;

namespace ui::event::pure
{
    class MouseMoveEvent final :
        public UIEvent,
        public Recycler<MouseMoveEvent>
    {
        public:
            MouseMoveEvent() {}
    };
}

#endif