#ifndef ENGINE_UI_ELEMENT_FOCUSABLE_H
#define ENGINE_UI_ELEMENT_FOCUSABLE_H

#include "event/Dispatcher.h"
#include "ui/event/derived/FocusEvent.h"

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