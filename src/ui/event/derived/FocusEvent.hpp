#ifndef UI_EVENT_FOCUSEVENT_HPP
#define UI_EVENT_FOCUSEVENT_HPP

#include "ui/event/UIEvent.hpp"
#include "ui/element/Element.h"
#include "ui/event/trait/TargetsElement.hpp"
#include "memory/recycler/Recycler.hpp"

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
    class FocusEvent final :
        public UIEvent,
        public TargetsElement,
        public Recycler<FocusEvent<T>>
    {
        public:
            FocusEvent(
                UIEvent* parent,
                Element* target
            ) : UIEvent(parent),
                TargetsElement(target)
            {}
    };
}

#endif