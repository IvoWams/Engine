#ifndef UI_EVENT_HOVER_HPP
#define UI_EVENT_HOVER_HPP

#include "ui/event/UIEvent.hpp"
#include "ui/event/trait/TargetsElement.hpp"
#include "memory/recycler/Recycler.hpp"

using ui::event::trait::TargetsElement;
using memory::recycler::Recycler;

namespace ui::event::derived
{
    enum HoverDirection
    {
        HOVER, SETTLE
    };

    template<HoverDirection T>
    class HoverEvent final :
        public UIEvent,
        public TargetsElement,
        public Recycler<HoverEvent<T>>
    {
        public:
            HoverEvent(
                Event* parent,
                Element* target
            ) :
                UIEvent(parent),
                TargetsElement(target)
            {}

            ~HoverEvent(){};
    };
}

#endif