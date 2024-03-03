#ifndef UI_ELEMENT_HITBOX_HPP
#define UI_ELEMENT_HITBOX_HPP

#include "ui/event/trait/Positional.hpp"

using ui::event::trait::Positional;

namespace ui::element
{
    class IsHit
    {
        public:
            virtual bool isHit(Positional* position) = 0;
    };

    struct Square { int x, y, w, h; };

    class HitBox :
        public IsHit
    {
        private:
            const Square& square;
        public:
            HitBox(const Square& _square) : square(_square) {}

            bool isHit(Positional* position)
            {
                return position->x >= square.x && position->x <= (square.x + square.w) &&
                position->y >= square.y && position->y <= (square.y + square.h);
            }
    }
}

#endif