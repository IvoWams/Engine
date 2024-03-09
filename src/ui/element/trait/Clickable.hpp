#ifndef UI_ELEMENT_CLICKABLE_HPP
#define UI_ELEMENT_CLICKABLE_HPP

#include "event/Listener.hpp"
#include "event/Dispatcher.hpp"
#include "ui/event/pure/MouseClickEvent.hpp"
#include "ui/event/derived/ClickEvent.hpp"

using namespace ::event;
using namespace ui::event::pure;
using namespace ui::event::derived;

namespace ui::element::trait
{
    class Clickable :
        public Listener<MouseClickEvent<MouseClickDirection::PRESS>>,
        public Listener<MouseClickEvent<MouseClickDirection::RELEASE>>,
        public Dispatcher<ClickEvent>
    {
        protected:
            bool clicking = false;

        public:
            Clickable() {};
            virtual ~Clickable() {};

            using Dispatcher<ClickEvent>::addListener; 
            using Dispatcher<ClickEvent>::dispatch;

            void onEvent(MouseClickEvent<MouseClickDirection::PRESS>*);
            void onEvent(MouseClickEvent<MouseClickDirection::RELEASE>*);
    };
}

#endif