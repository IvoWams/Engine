#ifndef ENGINE_UI_EVENT_INPUT_H
#define ENGINE_UI_EVENT_INPUT_H

#include "ui/event/UIEvent.hpp"
#include "ui/event/trait/TargetsElement.hpp"

using ui::event::trait::TargetsElement;

namespace ui::event::derived
{
    class InputEvent :
        public UIEvent,
        public TargetsElement
    {
        private:
            int keyCode;

        public:
            InputEvent(
                Event* parent,
                int _keyCode,
                Element* element = nullptr
            ) : UIEvent(parent),
                TargetsElement(element),
                keyCode(_keyCode)
            {}

            int getKeyCode()
            {
                return keyCode;
            }
    };
}

#endif