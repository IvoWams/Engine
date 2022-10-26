#ifndef ENGINE_UI_EVENT_CLICK_H
#define ENGINE_UI_EVENT_CLICK_H

#include "engine/ui/Element.h"
#include "engine/event/Event.h"

namespace engine::ui::event
{
    struct Click : engine::event::Event
    {
        engine::ui::Element* target;

        Click(engine::ui::Element *_target)
        {
            target = _target;
        }
    };
}

#endif