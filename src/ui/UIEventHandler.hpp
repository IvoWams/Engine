// We need something that can connect 'pure' events, determine what we are currently interacting with, and dispatch derived events
// The main handler only listens to the most basic inputs an OS can provide: keyboard keys, mouse events and gamepad/controller events

#ifndef UI_UIEVENTHANDLER_HPP
#define UI_UIEVENTHANDLER_HPP

#include "ui/element/Element.h"
#include "event/Propagator.hpp"
#include "event/Listener.cpp"
#include "ui/event/pure/KeyEvent.hpp"
#include "ui/event/pure/MouseClickEvent.hpp"
#include "ui/event/pure/MouseMoveEvent.hpp"

using namespace ::event;
using namespace ui::element;
using namespace ui::event::pure;

namespace ui
{
    // template<class T>
    // class SelectivePropagator
    // {

    // };

    // Main ui handler should only listen to the main OS event triggers, process them, and trigger events in active elements


    class UIEventHandler :
        public Listener<KeyEvent<KeyDirection::PRESS>>,
        public Listener<KeyEvent<KeyDirection::RELEASE>>,
        public Listener<MouseClickEvent<MouseClickDirection::PRESS>>,
        public Listener<MouseClickEvent<MouseClickDirection::RELEASE>>,
        public Listener<MouseMoveEvent>
    {

        private:

        public:
            UIEventHandler(){}

            Element root;

            void onEvent(KeyEvent<KeyDirection::PRESS>*);
            void onEvent(KeyEvent<KeyDirection::RELEASE>*);
            void onEvent(MouseClickEvent<MouseClickDirection::PRESS>*);
            void onEvent(MouseClickEvent<MouseClickDirection::RELEASE>*);
            void onEvent(MouseMoveEvent*);

            // void onEvent(GamePadButtonEvent<GamePadButtonDirection::PRESS_BUTTON>*)
            // void onEvent(GamePadButtonEvent<GamePadInputType::RELEASE_BUTTON>*)
            // void onEvent(GamePadDigitalEvent*)
            // void onEvent(GamePadAnalogEvent*)
    };
}

#endif