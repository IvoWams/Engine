#ifndef UI_EVENT_MOUSECLICKEVENT_HPP
#define UI_EVENT_MOUSECLICKEVENT_HPP

#include "ui/element/Element.h"
#include "ui/event/UIEvent.hpp"
#include "memory/recycler/Recycler.hpp"

using memory::recycler::Recycler;

namespace ui::event::pure
{
    enum class MouseClickDirection
    {
        RELEASE,
        PRESS
    };

    template <MouseClickDirection T>
    class MouseClickEvent final :
        public UIEvent,
        public Recycler<MouseClickEvent<T>>
    {
        private:
            int button;

        public:
            MouseClickEvent(int _button) : button(_button) { };

            int getButton()
            {
                return button;
            }
    };
}

#endif