#ifndef KEYFRAME_ALGORITHM_KEYFRAMEALGORITHM_HPP
#define KEYFRAME_ALGORITHM_KEYFRAMEALGORITHM_HPP

<<<<<<< HEAD
namespace keyframe::algorithm
{
    template <typename T>
    class KeyframeAlgorithm
    {
        public:
            virtual void iterate(Keyframe<T>*, uint64_t time) = 0;
=======
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
>>>>>>> 09b9cb25913c857f164f1ce352955e8db68d18ac
    };
}

#endif