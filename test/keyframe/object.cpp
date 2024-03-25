#include "keyframe/Keyframe.hpp"
#include "keyframe/algorithm/Linear.cpp"
#include "keyframe/algorithm/KeyframeAlgorithm.cpp"

using keyframe::algorithm::Linear;
using keyframe::Keyframe;

class Obj
{
    public:
        explicit Obj(float _value) : value(_value) {}
        // Obj(const Obj& obj): Obj(obj.value) {}

        const Obj& operator-(const Obj& a)
        {
            value -= a.value;
            return *this;
        }

        const Obj& operator/(const Obj& a)
        {
            return *this;
        }

        const Obj& operator/(float a)
        {
            return *this;
        }

        const Obj& operator*(float a)
        {
            value *= a;
            return *this;
        }


        float value;
};

int main()
{
    auto subject = new Obj(0);
    auto start = new Obj(3.0f);
    auto end = new Obj(10.0f);

    auto algorithm = new Linear<Obj*>();
    auto keyframe = new Keyframe<Obj*>(subject, 6, start, 12, end, algorithm);

    for (uint64_t timer = 0; timer <= 20; timer++)
    {
        algorithm->play(timer, keyframe);
        printf("x(%ld) = %f\n", timer, subject->value);
    }
}