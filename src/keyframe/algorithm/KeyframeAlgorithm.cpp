#include "KeyframeAlgorithm.hpp"

namespace keyframe::algorithm
{
    template <typename T>
    void KeyframeAlgorithm<T>::play(uint64_t time, Keyframe<T>* keyframe)
    {
        if (keyframe->status == FINISHED) {
            return;
        }

        if (keyframe->status == NOT_STARTED) {
            if (time < keyframe->startTime) {
                return;
            }

            keyframe->status = IN_PROGRESS;
        }

        // IN_PROGRESS:
        if (time >= keyframe->endTime) {
            keyframe->subject = keyframe->endValue;
            keyframe->status = FINISHED;
            return;
        }

        auto percentage = static_cast<float> (time - keyframe->startTime) / (keyframe->endTime - keyframe->startTime);
        progress(percentage, keyframe);
    }
}