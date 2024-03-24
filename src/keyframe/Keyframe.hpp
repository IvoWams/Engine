#ifndef KEYFRAME_KEYFRAME_HPP
#define KEYFRAME_KEYFRAME_HPP

<<<<<<< HEAD
namespace keeyframe
=======
#include "algorithm/KeyframeAlgorithm.hpp"
#include "memory/recycler/Recycler.hpp"

using keyframe::algorithm::KeyframeAlgorithm;
using memory::recycler::Recycler;

namespace keyframe
>>>>>>> 09b9cb25913c857f164f1ce352955e8db68d18ac
{
    enum KeyframeStatusEnum
    {
        NOT_STARTED, IN_PROGRESS, FINISHED
    };

    template <typename T>
    class Keyframe final : public Recycler<Keyframe<T>>
    {
        public:
            Keyframe(
<<<<<<< HEAD
                uint64_t startTime,
                T& startValue,

                uint64_t endTime,
                T& endValue,

                KeyframeAlgorith<T>* _algorithm
            ) :
                startTime(_startTime),
                startValue(Value_starValue),
                endTime(_endTime),
                endValue(_endValue),
                algorithm(_algorithm)
=======
                const uint64_t _startTime,
                T& _startValue,

                const uint64_t _endTime,
                T& _endValue,

                KeyframeAlgorithm<T>* _algorithm
            ) :
                startTime(_startTime),
                endTime(_endTime),
                startValue(_startValue),
                endValue(_endValue),
                algorithm(_algorithm),
                status(NOT_STARTED)
>>>>>>> 09b9cb25913c857f164f1ce352955e8db68d18ac
            {
                
            }

<<<<<<< HEAD
            ~Keyframe()
            {};

            uint64_t startTime, endTime, cursor;
            T& startValue, endValue, subject;
            KeyframeAlgorithm<T>* algorithm;
=======
            ~Keyframe() = default;

            uint64_t startTime, endTime, cursor{};
            T& startValue, endValue, subject;
            KeyframeAlgorithm<T>* algorithm{};
>>>>>>> 09b9cb25913c857f164f1ce352955e8db68d18ac
            KeyframeStatusEnum status;
    };  

}

#endif