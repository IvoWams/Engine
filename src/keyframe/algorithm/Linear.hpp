#ifndef KEYFRAME_ALGORITHM_LINEAR_HPP
#define KEYFRAME_ALGORITHM_LINEAR_HPP

#include "KeyframeAlgorithm.hpp"
#include "keyframe/Keyframe.hpp"
#include <cstdint>

namespace keeyframe::algorithm
{
    template <typename T>
    class Linear : public KeyframeAlgorithm
    {
        public:
            void iterate(Keyframe<T>* keyframe, uint64_t time);
    };
}

#endif