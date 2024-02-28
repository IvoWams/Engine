#ifndef ENGINE_TRIANGLE_H
#define ENGINE_TRIANGLE_H

#include "Vector.h"

namespace engine::math
{
    struct Triangle
    {
        Vector *a, *b, *c, *n;

        /*
        bool destroy = false;

        Triangle()
        {
            a = new Vector(0, 0, 0);
            b = new Vector(0, 0, 0);
            c = new Vector(0, 0, 0);
            destroy = true;
        }

        ~Triangle()
        {
            if (destroy) {
                delete a, b, c;
            }
        }
        */

        Triangle(Vector *_a, Vector *_b, Vector *_c)
        {
            a = _a;
            b = _b;
            c = _c;
        };

        static Vector* normal(const Triangle& triangle)
        {
            Vector A{
                triangle.b->x - triangle.a->x,
                triangle.b->y - triangle.a->y,
                triangle.b->z - triangle.a->z
            };

            Vector B{
                triangle.c->x - triangle.a->x,
                triangle.c->y - triangle.a->y,
                triangle.c->z - triangle.a->z
            };

            return new Vector(
                A.y * B.z - A.z * B.y,
                A.z * B.x - A.x * B.z,
                A.x * B.y - A.y * B.x
            );
        }

        static double dot(const Triangle& triangle)
        {
            // cos(t) = (a * b) / (abs(a) * abs(b))
        }
    };
}

#endif