#include "Linear.hpp"

namespace keyframe::algorithm
{
    template <typename T>
    void Linear::iterate(Keyframe<T>* keyframe, uint64_t time)
    {
        if (keyframe->status == KeyframeStatusEnum::FINISHED) {
            return;
        }

        if (keyframe->status == KeyframeStatusEnum::NOT_STARTED) {
            if (time < keyframe->startTime) {
                return;
            }

            keyframe->cursor = keyframe->startTime;
            keyframe->subject = keyframe->startValue;
            keyframe->status = KeyframeStatusEnum::IN_PROGRESS;
        }

        // IN_PROGRESS:
        if (time >= keyframe->endTime) {
            keyframe->subject = keyframe->endValue;
            keyframe->status = KeyframeStatusEnum::FINISHED;
            return;
        }

        // Actual calculation here, rest could be DRY
        auto delta = time - keyframe->cursor;
        keyframe->subject += (keyframe->endValue - keyframe->subject) / delta;
    }    
}
