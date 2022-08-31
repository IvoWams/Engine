#include "../../math/Vector.h"
#include <stdio.h>

void outputVector(const math::Vector& vector)
{
    printf(
        "{m: %p, x: %f, y: %f, z: %f}\n",
        &vector,
        vector.x,
        vector.y,
        vector.z
    );
}

int specialcontext()
{
    printf("Special context\n");
    math::Vector a{1, 2, 3}, b{2, 3, 4}, c{1, 2, 3};

    outputVector(a);
    outputVector(b);
    outputVector(c);

    // Never do this, store it in something first:
    outputVector(a + b);    // This creates new vector, which is not being deleted

    // Storing it in an existing memory:
    c = a + b;              // c is now a new pointer, the old c still gets destructed however
                            // but this here this one is now leaky

    outputVector(c);

    math::Vector d{0, 0, 0};

    outputVector(d);

    d = c;

    outputVector(d);

    outputVector(d * 5);    // not deleted
    outputVector(d / 2);    // not deleted

    // math::Vector&& ref = d * 10;    // Store 

    // 4 deletes here:
    // Vector a,b,c,d
    // All temporary (rvalue) are not deleted

    printf("End of specialcontext\n");
}

int main()
{
    printf("main context\n");
    specialcontext();
    printf("out of specialcontext\n");
}
