#ifndef ENGINE_UI_EVENT_DERIVED_CLICKEVENT_HPP
#define ENGINE_UI_EVENT_DERIVED_CLICKEVENT_HPP

#include "ui/event/UIEvent.hpp"
#include "ui/event/trait/TargetsElement.hpp"
#include "memory/recycler/Recycler.hpp"

using ui::event::UIEvent;
using ui::event::trait::TargetsElement;
using memory::recycler::Recycler;

namespace ui::event::derived
{
    class ClickEvent final : 
        public UIEvent,
        public TargetsElement,
        public Recycler<ClickEvent>
    {
        public:
            ClickEvent(
                Event* parent,
                Element* target = nullptr
            ) : UIEvent(parent),
                TargetsElement(target)
            {}

            ~ClickEvent(){};
    };
}

#endif