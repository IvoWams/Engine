#ifndef KEYFRAME_ALGORITHM_LINEAR_HPP
#define KEYFRAME_ALGORITHM_LINEAR_HPP

#include "KeyframeAlgorithm.hpp"
#include <cstdint>
#include "keyframe/Keyframe.hpp"

using keyframe::Keyframe;

namespace keyframe::algorithm
{
    template <typename T>
    class Linear final : public KeyframeAlgorithm<T>
    {
        public:
            void iterate(Keyframe<T>* keyframe, uint64_t time) override;
    };
}

#endif