#include "keyframe/Keyframe.hpp"
#include "keyframe/algorithm/Linear.cpp"
#include "keyframe/algorithm/KeyframeAlgorithm.cpp"

using keyframe::algorithm::Linear;
using keyframe::Keyframe;

int main()
{
    float x = 0;

    auto algorithm = new Linear<float>();

    auto keyframe = new Keyframe(x, 6, 3.0f, 12, 10.0f, algorithm);

    for (uint64_t timer = 0; timer <= 20; timer++)
    {
        algorithm->play(timer, keyframe);
        printf("x(%ld) = %f\n", timer, x);
    }
}