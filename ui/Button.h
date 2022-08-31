#ifndef APP_UI_BUTTON_H
#define APP_UI_BUTTON_H

#include "Element.h"
#include "../event/Dispatcher.h"
#include "event/Click.h"
#include "event/interactive/MouseDown.h"
#include "event/interactive/MouseUp.h"

using namespace app::event;

namespace app::ui
{
    struct Button :
        public Element,
        public Listener<event::interactive::MouseDown>,
        public Listener<event::interactive::MouseUp>,
        public Dispatcher<event::Click>
    {
        void onEvent(event::interactive::MouseDown* event)
        {
            focus = true;
            mousedown = true;
        }

        void onEvent(event::interactive::MouseUp* event)
        {
            mousedown = false;
            this->dispatch(new event::Click(this));
        }
    };
}

#endif