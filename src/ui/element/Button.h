#ifndef ENGINE_UI_BUTTON_H
#define ENGINE_UI_BUTTON_H

#include "Element.h"
#include "trait/Clickable.hpp"
#include "trait/Focusable.h"

using namespace ui::event;
using namespace ui::element;
using namespace ui::element::trait;

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