#ifndef ENGINE_UI_ELEMENT_CLICKABLE_H
#define ENGINE_UI_ELEMENT_CLICKABLE_H

#include "event/Listener.h"
#include "event/Dispatcher.h"
#include "ui/event/pure/MouseClickEvent.h"
#include "ui/event/derived/ClickEvent.hpp"

using namespace event;
using namespace ui::event::pure;
using namespace ui::event::derived;

namespace ui::element
{
    class Clickable :
        public Listener<MouseClickEvent<MouseClickDirection::PRESS>>,
        public Listener<MouseClickEvent<MouseClickDirection::RELEASE>>,
        public Dispatcher<ClickEvent>
    {
        protected:
            bool clicking = false;

        public:
            Clickable() {}

            void onEvent(MouseClickEvent<MouseClickDirection::PRESS>*);
            void onEvent(MouseClickEvent<MouseClickDirection::RELEASE>*);
    };
}

#endif