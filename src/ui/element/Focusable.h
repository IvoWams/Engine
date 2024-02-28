#ifndef ENGINE_UI_ELEMENT_FOCUSABLE_H
#define ENGINE_UI_ELEMENT_FOCUSABLE_H

#include "event/Dispatcher.h"
#include "ui/event/derived/FocusEvent.h"

using event::Dispatcher;
using namespace ui::event::derived;

namespace ui::element
{
    struct Focusable :
        Dispatcher<FocusEvent<FOCUS>>,
        Dispatcher<FocusEvent<BLUR>>
    {
        bool focus = false;

        void onEvent(FocusEvent<FOCUS>* event)
        {
            focus = true;
        }

        void onEvent(FocusEvent<BLUR>* event)
        {
            focus = false;
        }
    };
}

#endif