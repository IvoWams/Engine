#ifndef ENGINE_UI_EVENT_FOCUS_H
#define ENGINE_UI_EVENT_FOCUS_H

#include "engine/event/Event.h";
#include "engine/ui/element/Element.h";
#include "engine/ui/event/Targetable.h";

using engine::ui::element::Element;
using engine::ui::event::Targetable;

namespace engine::ui::event
{
    struct Focus :
        engine::event::Event,
        Targetable
    {
        Focus(Element* e) : Targetable(e)
        {

        }
    };
}

#endif