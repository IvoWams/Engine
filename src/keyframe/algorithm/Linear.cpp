#include "Linear.hpp"

namespace keyframe::algorithm
{
    template <typename T>
    void Linear<T>::progress(float percentage, Keyframe<T>* keyframe)
    {
        if (std::is_pointer_v<T>)
        {
            // Do nothing for now...
            return;
        }

        T diff = keyframe->endValue - keyframe->startValue;
        keyframe->subject = diff * percentage + keyframe->startValue;
    }
}
