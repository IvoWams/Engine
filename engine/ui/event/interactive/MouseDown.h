#ifndef ENGINE_UI_EVENT_INTERACTIVE_MOUSEDOWN_H
#define ENGINE_UI_EVENT_INTERACTIVE_MOUSEDOWN_H

#include "engine/ui/Element.h"
#include "engine/event/Event.h"

// Interactive as in the keyboard + mouse or controller
// ie. the base human interactiion in the shape of event handling

namespace engine::ui::event::interactive
{
    struct MouseDown : engine::event::Event
    {
        engine::ui::Element* target;
    };
}

#endif