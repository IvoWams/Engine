#ifndef MATH_SHAPES_HPP
#define MATH_SHAPES_HPP

namespace math::shapes
{
    template <typename T>
    struct Point { T x, y; };

    template <typename T>
    struct Square { T x, y, w, h; };

    template <typename T>
    struct Circle { Point<T> c; T d; };

    template <typename T>
    bool touches(const Point<T>& p, const Square<T>& s)
    {
        return p.x >= s.x && p.x <= s.x + s.w && p.y >= s.y && p.y <= s.y + s.h; 
    }

    template <typename T>
    bool touches(const Square<T>& s1, const Square<T>& s2)
    {
        return s1.x < s2.x + s2.w &&
               s1.x + s1.w > s2.x &&
               s1.y < s2.y + s2.h &&
               s1.y + s1.h > s2.y;    
    }

    template <typename T>
    T distance(const Point<T>& p1, const Point<T>& p2)
    {
        return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
    }

    template <typename T>
    bool touches(const Point<T>& p, const Circle<T>& c)
    {
        return c.d < distance(p, c.c);
    }
};

#endif