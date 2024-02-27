#ifndef ENGINE_UI_EVENT_MOUSEDOWN_H
#define ENGINE_UI_EVENT_MOUSEDOWN_H

#include "engine/ui/element/Element.h"
#include "engine/event/Event.h"
#include "engine/ui/event/Targetable.h"

using engine::event::Event;
using engine::ui::event::Targetable;

namespace engine::ui::event
{
    struct MouseDown : engine::event::Event, Targetable
    {

    };
}

#endif