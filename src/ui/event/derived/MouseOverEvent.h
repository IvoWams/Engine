#ifndef ENGINE_UI_EVENT_MOUSEOVER_H
#define ENGINE_UI_EVENT_MOUSEOVER_H

#include "ui/event/UIEvent.hpp"
#include "ui/event/trait/TargetsElement.hpp"

using ui::event::trait::TargetsElement;

namespace ui::event::derived
{
    enum MouseEnters
    {
        OVER,
        OUT
    };

    template<MouseEnters T>
    class MouseOverEvent :
        public UIEvent,
        public TargetsElement
    {
        public:
            MouseOverEvent(
                Event* parent,
                Element* target
            ) :
                Event(parent),
                TargetsElement(target)
            {}
    };
}

#endif