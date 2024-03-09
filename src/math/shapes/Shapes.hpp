#ifndef MATH_SHAPES_HPP
#define MATH_SHAPES_HPP

namespace math::shapes
{
    template <typename T>
    struct Point { T x, y; };

    template <typename T>
    struct Line { Point<T> p, q; };

    template <typename T>
    struct Square { T x, y, w, h; };

    template <typename T>
    struct Circle { Point<T> c; T d; };

    template <typename T>
    struct Triangle { Point<T> p[3]; };

    // Reading:
    // Convert polygon to triangles:
    // https://www.geometrictools.com/Documentation/TriangulationByEarClipping.pdf
    // https://github.com/greenm01/poly2tri

    template <typename T>
    struct Polygon { Point<T> p[]; };

};

#endif