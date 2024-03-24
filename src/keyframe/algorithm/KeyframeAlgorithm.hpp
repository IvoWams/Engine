#ifndef KEYFRAME_ALGORITHM_KEYFRAMEALGORITHM_HPP
#define KEYFRAME_ALGORITHM_KEYFRAMEALGORITHM_HPP

namespace keyframe::algorithm
{
    template <typename T>
    class KeyframeAlgorithm
    {
        public:
            virtual void iterate(Keyframe<T>*, uint64_t time) = 0;
    };
}

#endif