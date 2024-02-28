#ifndef ENGINE_UI_EVENT_MOUSECLICKEVENT_H
#define ENGINE_UI_EVENT_MOUSECLICKEVENT_H

#include "ui/element/Element.h"
#include "ui/event/UIEvent.hpp"
#include "ui/event/trait/Positional.hpp"

using ui::event::trait::Positional;

namespace ui::event::pure
{
    enum class MouseClickDirection
    {
        RELEASE,
        PRESS
    };

    template <MouseClickDirection T>
    class MouseClickEvent :
        public UIEvent,
        public Positional
    {
        private:
            int button;

        public:
            MouseClickEvent(
                int x, 
                int y, 
                int _button
            ) :
                Positional(x, y),
                button(_button)
            {};

            int getButton()
            {
                return button;
            }
    };
}

#endif