#ifndef ENGINE_UI_EVENT_EVENT_H
#define ENGINE_UI_EVENT_EVENT_H

#include "event/Event.h"

using event::Event;

namespace ui::event
{
    class UIEvent :
        public Event
    {
        public:
            UIEvent(){}
            UIEvent(Event* parent) : Event(parent) {}
    };
}

#endif