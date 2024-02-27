#ifndef ENGINE_UI_BUTTON_H
#define ENGINE_UI_BUTTON_H

#include "Element.h"
#include "../engine/event/Dispatcher.h"
#include "engine/ui/event/Click.h"
#include "engine/ui/event/interactive/MouseDown.h"
#include "engine/ui/event/interactive/MouseUp.h"

using namespace engine::event;

namespace engine::ui
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