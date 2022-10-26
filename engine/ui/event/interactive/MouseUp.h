#ifndef APP_UI_EVENT_INTERACTIVE_MOUSEUP_H
#define APP_UI_EVENT_INTERACTIVE_MOUSEUP_H

#include "engine/ui/Element.h"
#include "engine/event/Event.h"

namespace engine::ui::event::interactive
{
    struct MouseUp : engine::event::Event
    {
        engine::ui::Element* target;
    };
}

#endif