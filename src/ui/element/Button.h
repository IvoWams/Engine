#ifndef ENGINE_UI_BUTTON_H
#define ENGINE_UI_BUTTON_H

#include "Element.h"
#include "Clickable.hpp"
#include "Focusable.h"

using namespace ui::event;
using namespace ui::element;

namespace ui::element
{
    class Button :
        public Element,
        public Clickable,
        public Focusable
    {
        public:
            Button(){}
    };
}

#endif