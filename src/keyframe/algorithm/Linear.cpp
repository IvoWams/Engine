#include "Linear.hpp"

namespace keyframe::algorithm
{
    template <typename T>
<<<<<<< HEAD
    void Linear::iterate(Keyframe<T>* keyframe, uint64_t time)
    {
        if (keyframe->status == KeyframeStatusEnum::FINISHED) {
            return;
        }

        if (keyframe->status == KeyframeStatusEnum::NOT_STARTED) {
=======
    void Linear<T>::iterate(Keyframe<T>* keyframe, uint64_t time)
    {
        if (keyframe->status == FINISHED) {
            return;
        }

        if (keyframe->status == NOT_STARTED) {
>>>>>>> 09b9cb25913c857f164f1ce352955e8db68d18ac
            if (time < keyframe->startTime) {
                return;
            }

            keyframe->cursor = keyframe->startTime;
            keyframe->subject = keyframe->startValue;
<<<<<<< HEAD
            keyframe->status = KeyframeStatusEnum::IN_PROGRESS;
=======
            keyframe->status = IN_PROGRESS;
>>>>>>> 09b9cb25913c857f164f1ce352955e8db68d18ac
        }

        // IN_PROGRESS:
        if (time >= keyframe->endTime) {
            keyframe->subject = keyframe->endValue;
<<<<<<< HEAD
            keyframe->status = KeyframeStatusEnum::FINISHED;
=======
            keyframe->status = FINISHED;
>>>>>>> 09b9cb25913c857f164f1ce352955e8db68d18ac
            return;
        }

        // Actual calculation here, rest could be DRY
        auto delta = time - keyframe->cursor;
        keyframe->subject += (keyframe->endValue - keyframe->subject) / delta;
    }    
}
