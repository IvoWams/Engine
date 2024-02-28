// We need something that can connect 'pure' events, determine what we are currently interacting with, and dispatch derived events
// The main handler only listens to the most basic inputs an OS can provide: keyboard keys, mouse events and gamepad/controller events

#ifndef ENGINE_UI_UIEVENTHANDLER_H
#define ENGINE_UI_UIEVENTHANDLER_H

#include "ui/element/Element.h"
#include "event/Propagator.h"
#include "event/Listener.h"
#include "ui/event/pure/KeyEvent.h"
#include "ui/event/pure/MouseClickEvent.h"
#include "ui/event/pure/MouseMoveEvent.h"

using namespace ui::element;
using namespace event;
using namespace ui::event::pure;

namespace ui
{
    // template<class T>
    // class SelectivePropagator
    // {

    // };


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
    };
}

#endif