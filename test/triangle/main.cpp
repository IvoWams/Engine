#include <stdio.h>
#include "engine/math/Vector.h"
#include "engine/math/Triangle.h"

using namespace engine::math;

int main()
{
    Vector a{5, 3, 4}, b{2, 5, 9}, c{8, 7, 5};

    Triangle A{&a, &b, &c};

    Vector *n = Triangle::normal(A);

    printf(
        "{%f:%f:%f}\n",
        n->x,
        n->y,
        n->z
    );

}
