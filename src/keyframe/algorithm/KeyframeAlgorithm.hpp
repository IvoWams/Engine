#ifndef KEYFRAME_ALGORITHM_KEYFRAMEALGORITHM_HPP
#define KEYFRAME_ALGORITHM_KEYFRAMEALGORITHM_HPP

#include <cstdint>

namespace keyframe::algorithm
{
    template <typename T>
    class Keyframe;

    template <typename T>
    class KeyframeAlgorithm
    {
        public:
            virtual ~KeyframeAlgorithm() = default;

            virtual void iterate(Keyframe<T>* keyframe, uint64_t time) = 0;
    };
}

#endif