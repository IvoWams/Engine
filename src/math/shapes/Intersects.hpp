#ifndef MATH_SHAPES_INTERSECTS_HPP
#define MATH_SHAPES_INTERSECTS_HPP

#include "Shapes.hpp"

namespace math::shapes
{
    template <typename T>
    T distance(const Point<T>& p1, const Point<T>& p2)
    {
        return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
    }

    template <typename T>
    bool intersects(const Point<T>& p, const Circle<T>& c)
    {
        return c.d < distance(p, c.c);
    }

    template <typename T>
    bool intersects(const Circle<T>& c1, const Circle<T>& c2)
    {
        return distance(c1.p, c2.p) < (c1.d + c2.d);
    }

    template <typename T>
    bool intersects(const Line<T>& l, const Line<T>& m)
    {
        // todo https://stackoverflow.com/questions/16524096/how-to-calculate-the-point-of-intersection-between-two-lines
        return false;
    };


    template <typename T>
    bool intersects(const Point<T>& p, const Square<T>& s)
    {
        return p.x >= s.x && p.x <= s.x + s.w && p.y >= s.y && p.y <= s.y + s.h; 
    };

    template <typename T>
    bool intersects(const Square<T>& s1, const Square<T>& s2)
    {
        return s1.x < s2.x + s2.w &&
               s1.x + s1.w > s2.x &&
               s1.y < s2.y + s2.h &&
               s1.y + s1.h > s2.y;    
    };

    template <typename T>
    bool intersects(const Polygon<T>& p, const Square<T>& s)
    {
        // todo
        return false;
    };

    template <typename T>
    bool intersects(const Polygon<T>& p1, const Polygon<T>& p2)
    {
        // todo
        return false;
    };
}

#endif