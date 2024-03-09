#ifndef UI_ELEMENT_HITBOX_HPP
#define UI_ELEMENT_HITBOX_HPP

#include "ui/event/trait/Positional.hpp"
#include "math/shapes/Shapes.h"

using ui::event::trait::Positional;
using math::shapes::Square;

namespace ui::element
{
    class IsHit
    {
        protected:
            IsHit(){}

        public:
            virtual ~IsHit();
            virtual bool isHit(Positional* position) = 0;
    };

    template <typename T>
    class HitBox :
        public IsHit
    {
        private:
            const Square<T>& square;

        public:
            HitBox(const Square<T>& _square) : square(_square) {}

            bool isHit(Positional* position)
            {
                return position->x >= square.x && position->x <= (square.x + square.w) &&
                position->y >= square.y && position->y <= (square.y + square.h);
            }
    }
}

#endif