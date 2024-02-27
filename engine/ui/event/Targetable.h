#ifndef ENGINE_UI_EVENT_TARGETABLE_H
#define ENGINE_UI_EVENT_TARGETABLE_H

#include "engine/ui/element/Element.h";

using engine::ui::element::Element;

namespace engine::ui::event
{
    struct Targetable
    {
        Element* target;

        Targetable(Element* t)
        {
            target = t;
        }
    };
}

#endif