#ifndef APP_UI_EVENT_CLICK_H
#define APP_UI_EVENT_CLICK_H

#include "../Element.h"
#include "../../event/Event.h"

namespace app::ui::event
{
    struct Click : app::event::Event
    {
        app::ui::Element* target;

        Click(app::ui::Element *_target)
        {
            target = _target;
        }
    };
}

#endif