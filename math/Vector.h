#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H

#include <math.h>
#include <memory>

namespace math
{
    struct Vector
    {
        double x, y, z;

        Vector()
        {
            printf("New: %p\n", this);
            x = 0;
            y = 0;
            z = 0;
        }

        Vector(double _x, double _y, double _z)
        {
            printf("New: %p\n", this);
            x = _x;
            y = _y;
            z = _z;
        }

        ~Vector()
        {
            printf("Delete: %p\n", this);
        }


        Vector& operator=(Vector& other)
        {
            x = other.x;
            y = other.y;
            z = other.z;
            printf("Copy\n");
            return *this;
        };

        Vector& operator=(Vector&& other)
        {
            x = other.x;
            y = other.y;
            z = other.z;
            printf("Move\n");
            return *this;
        }


        Vector& operator+(const Vector& other)        
        {
            auto v = new Vector(x + other.x, y + other.y, z + other.z);
            return *v;
        }

        Vector& operator-(const Vector& other)
        {
            auto v = new Vector(x - other.x, y - other.y, z - other.z);
            return *v;
        }

        Vector& operator*(double magnitude)
        {
            auto v = new Vector(x * magnitude, y * magnitude, z * magnitude);
            return *v;
        }

        Vector& operator/(double magnitude)
        {
            if (magnitude == 0) return *this;
            return operator*(1/magnitude);
        }

        // todo convert to use fast sqrt
        constexpr double length() noexcept
        {
            return sqrt(x * x + y * y + z * z);
        }
    };
}

#endif