#ifndef ENGINE_UI_EVENT_DERIVED_CLICKEVENT_HPP
#define ENGINE_UI_EVENT_DERIVED_CLICKEVENT_HPP

#include "ui/event/UIEvent.hpp"
#include "ui/event/trait/TargetsElement.hpp"

using ui::event::UIEvent;
using ui::event::trait::TargetsElement;

namespace ui::event::derived
{
    class ClickEvent : 
        public UIEvent,
        public TargetsElement
    {
        public:
            ClickEvent(
                Event* parent,
                Element* target = nullptr
            ) : UIEvent(parent),
                TargetsElement(target)
            {}
    };
}

#endif