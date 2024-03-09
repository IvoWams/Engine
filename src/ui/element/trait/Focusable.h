#ifndef UI_ELEMENT_FOCUSABLE_HPP
#define UI_ELEMENT_FOCUSABLE_HPP

#include "event/Dispatcher.hpp"
#include "ui/event/derived/FocusEvent.hpp"

using ::event::Dispatcher;
using namespace ui::event::derived;

namespace ui::element
{
    class Focusable :
        Dispatcher<FocusEvent<FOCUS>>,
        Dispatcher<FocusEvent<BLUR>>,

        Listener<ClickEvent>
    {
        bool focus = false;

        public:
            using Dispatcher<FocusEvent<FOCUS>>::addListener; 
            using Dispatcher<FocusEvent<FOCUS>>::dispatch;
            using Dispatcher<FocusEvent<BLUR>>::addListener; 
            using Dispatcher<FocusEvent<BLUR>>::dispatch;

            void onEvent(ClickEvent* event)
            {
                if (focus != true) {
                    return;
                }

                focus = true;
                Dispatcher<FocusEvent<FOCUS>>::dispatch(new FocusEvent<FOCUS>(event, event->getTarget()));
            }
    };
}

#endif