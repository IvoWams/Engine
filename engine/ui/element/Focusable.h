#ifndef ENGINE_UI_ELEMENT_FOCUSABLE_H
#define ENGINE_UI_ELEMENT_FOCUSABLE_H

#include "engine/event/Dispatcher.h"
#include "engine/ui/event/Focus.h"
#include "engine/ui/event/Blur.h"

using engine::event::Dispatcher;
using engine::ui::event::Focus;
using engine::ui::event::Blur;

namespace engine::ui::element
{
    struct Focusable : Dispatcher<Focus>, Dispatcher<Blur>
    {
        bool focus = false;

        void onEvent(Focus* event)
        {
            focus = true;
        }

        void onEvent(Blur* event)
        {
            focus = false;
        }
    };
}

#endif