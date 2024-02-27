#ifndef ENGINE_UI_EVENT_BLUR_H
#define ENGINE_UI_EVENT_BLUR_H

#include "engine/event/Event.h";
#include "engine/ui/event/Targetable.h";

namespace engine::ui::event
{
    struct Blur :
        engine::event::Event,
        Targetable
    {
        Blur(Element* target) : Targetable(target) {}
    };
}

#endif