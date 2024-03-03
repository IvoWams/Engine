#ifndef ENGINE_UI_EVENT_MOUSECLICKEVENT_H
#define ENGINE_UI_EVENT_MOUSECLICKEVENT_H

#include "ui/element/Element.h"
#include "ui/event/UIEvent.hpp"

namespace ui::event::pure
{
    enum class MouseClickDirection
    {
        RELEASE,
        PRESS
    };

    template <MouseClickDirection T>
    class MouseClickEvent :
        public UIEvent
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