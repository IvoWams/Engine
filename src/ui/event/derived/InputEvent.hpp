#ifndef UI_EVENT_INPUT_HPP
#define UI_EVENT_INPUT_HPP

#include "ui/event/UIEvent.hpp"
#include "ui/event/trait/TargetsElement.hpp"
#include "memory/recycler/Recycler.hpp"

using ui::event::trait::TargetsElement;
using memory::recycler::Recycler;

namespace ui::event::derived
{
    class InputEvent final :
        public UIEvent,
        public TargetsElement,
        public Recycler<InputEvent>
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

            ~InputEvent(){};

            int getKeyCode()
            {
                return keyCode;
            }
    };
}

#endif