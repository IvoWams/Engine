#ifndef WORLD_FORCES_H
#define WORLD_FORCES_H

#include <vector>
#include "../math/Vector.h"

namespace world
{
    struct Forces : std::vector<math::Vector*>
    {
        math::Vector result;

        void push_back(const value_type& __x)
        {            
            vector::push_back(__x);
            result = result + __x;
        }

        void pop_back()
        {
            math::Vector* back = vector::back();
            math::Vector bla;
            result = result - &bla;
            result = result - (math::Vector&)back;
            vector::pop_back();        
        }


    }
}

#endif