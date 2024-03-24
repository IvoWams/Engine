#ifndef KEYFRAME_ALGORITHM_LINEAR_HPP
#define KEYFRAME_ALGORITHM_LINEAR_HPP

#include "KeyframeAlgorithm.hpp"
<<<<<<< HEAD
#include "keyframe/Keyframe.hpp"
#include <cstdint>

namespace keeyframe::algorithm
{
    template <typename T>
    class Linear : public KeyframeAlgorithm
    {
        public:
            void iterate(Keyframe<T>* keyframe, uint64_t time);
=======
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
>>>>>>> 09b9cb25913c857f164f1ce352955e8db68d18ac
    };
}

#endif