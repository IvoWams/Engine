#ifndef KEYFRAME_ALGORITHM_KEYFRAMEALGORITHM_HPP
#define KEYFRAME_ALGORITHM_KEYFRAMEALGORITHM_HPP

#include <cstdint>

#include "keyframe/Keyframe.hpp"

using keyframe::Keyframe;

namespace keyframe::algorithm
{
    template <typename T>
    class KeyframeAlgorithm
    {
        protected:
            virtual void progress(float percentage, Keyframe<T>* keyframe) = 0;

        public:
            explicit KeyframeAlgorithm() = default;
            virtual ~KeyframeAlgorithm() = default;

            void play(uint64_t time, Keyframe<T>* keyframe);
    };
}

#endif