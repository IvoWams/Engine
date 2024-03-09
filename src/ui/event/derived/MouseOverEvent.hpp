#ifndef UI_EVENT_MOUSEOVER_HPP
#define UI_EVENT_MOUSEOVER_HPP

#include "ui/event/UIEvent.hpp"
#include "ui/event/trait/TargetsElement.hpp"
#include "memory/recycler/Recycler.hpp"

using ui::event::trait::TargetsElement;
using memory::recycler::Recycler;

namespace ui::event::derived
{
    enum MouseEnters
    {
        OVER,
        OUT
    };

    template<MouseEnters T>
    class MouseOverEvent :
        public UIEvent,
        public TargetsElement,
        public Recycler<MouseOverEvent<T>>
    {
        public:
            MouseOverEvent(
                Event* parent,
                Element* target
            ) :
                Event(parent),
                TargetsElement(target)
            {}

            ~MouseOverEvent(){};
    };
}


#endif