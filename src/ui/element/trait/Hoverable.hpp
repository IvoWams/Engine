#ifndef ENGINE_UI_ELEMENT_HOVERABLE_HPP
#define ENGINE_UI_ELEMENT_HOVERABLE_HPP

#include "event/Listener.h"
#include "event/Dispatcher.h"
#include "ui/event/derived/MouseOverEvent.h"
#include "ui/event/derived/HoverEvent.h"

using namespace event;
using namespace ui::event::derived;

namespace ui::element
{
    class Hoverable :
        Listener<MouseOverEvent<OVER>>,
        Listener<MouseOverEvent<OUT>>,
        Dispatcher<HoverEvent<HOVER>>,
        Dispatcher<HoverEvent<SETTLE>>
    {
        public:
            void onEvent(MouseOverEvent<OVER>*);
            void onEvent(MouseOverEvent<OUT>*);
    };
}

#endif