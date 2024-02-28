#ifndef ENGINE_UI_EVENT_FOCUSEVENT_H
#define ENGINE_UI_EVENT_FOCUSEVENT_H

#include "ui/event/UIEvent.hpp"
#include "ui/element/Element.h"
#include "ui/event/trait/TargetsElement.hpp"

using ui::element::Element;
using ui::event::trait::TargetsElement;

namespace ui::event::derived
{
    enum FocusBlur
    {
        FOCUS,
        BLUR
    };

    template<FocusBlur T>
    class FocusEvent :
        public UIEvent,
        public TargetsElement
    {
        public:
            FocusEvent(
                Event* parent,
                Element* target
            ) : Event(parent),
                TargetsElement(target)
            {}
    };
}

#endif