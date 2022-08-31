#ifndef APP_UI_EVENT_INTERACTIVE_MOUSEUP_H
#define APP_UI_EVENT_INTERACTIVE_MOUSEUP_H

#include "../Element.h"
#include "../../event/Event.h"

namespace app::ui::event::interactive
{
    struct MouseUp : app::event::Event
    {
        app::ui::Element* target;
    };
}

#endif