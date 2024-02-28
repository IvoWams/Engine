#ifndef ENGINE_UI_EVENT_TARGETABLE_H
#define ENGINE_UI_EVENT_TARGETABLE_H

#include "ui/element/Element.h"

using ui::element::Element;

namespace ui::event::trait
{
    class TargetsElement
    {
        private:
            Element* target;

        public:
            TargetsElement(Element* _target) : target(_target) {};

            Element* getTarget();
    };
}

#endif