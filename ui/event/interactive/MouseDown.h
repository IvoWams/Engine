#ifndef APP_UI_EVENT_INTERACTIVE_MOUSEDOWN_H
#define APP_UI_EVENT_INTERACTIVE_MOUSEDOWN_H

#include "../Element.h"
#include "../../event/Event.h"

// Interactive as in the keyboard + mouse or controller
// ie. the base human interactiion in the shape of event handling

namespace app::ui::event::interactive
{
    struct MouseDown : app::event::Event
    {
        app::ui::Element* target;
    };
}

#endif