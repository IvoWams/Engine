#ifndef ENGINE_UI_EVENT_HOVER_H
#define ENGINE_UI_EVENT_HOVER_H

#include "ui/event/UIEvent.hpp"
#include "ui/event/trait/TargetsElement.hpp"

using ui::event::trait::TargetsElement;

namespace ui::event::derived
{
    enum HoverDirection
    {
        HOVER, SETTLE
    };

    template<HoverDirection T>
    class HoverEvent :
        public UIEvent,
        public TargetsElement
    {
        public:
            HoverEvent(
                Event* parent,
                Element* target
            ) :
                UIEvent(parent),
                TargetsElement(target)
            {}
    };
}

#endif