#ifndef ENGINE_UI_ELEMENT_INPUTTABLE_H
#define ENGINE_UI_ELEMENT_INPUTTABLE_H

#include "event/Listener.h"
#include "event/Dispatcher.h"

#include "ui/event/pure/KeyEvent.h"
#include "ui/event/derived/InputEvent.h"

using namespace event;
using namespace ui::event::pure;
using namespace ui::event::derived;

namespace ui::element
{
    class Inputtable :
        Listener<KeyEvent<KeyDirection::PRESS>>,
        Listener<KeyEvent<KeyDirection::RELEASE>>,
        Dispatcher<InputEvent>
    {
        private:
            // todo memory for every key ?
            bool keyBuffer[255];
         
            // todo Inputtable should be time aware
            int cooldown;

        public:
            Inputtable(){}

            void onEvent(KeyEvent<KeyDirection::PRESS>*);
            void onEvent(KeyEvent<KeyDirection::RELEASE>*);
    };
}

#endif