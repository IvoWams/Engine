#ifndef KEYFRAME_KEYFRAME_HPP
#define KEYFRAME_KEYFRAME_HPP

#include "algorithm/KeyframeAlgorithm.hpp"
#include "memory/recycler/Recycler.hpp"

using keyframe::algorithm::KeyframeAlgorithm;
using memory::recycler::Recycler;

namespace keyframe
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
            {
                
            }

            ~Keyframe() = default;

            uint64_t startTime, endTime, cursor{};
            T& startValue, endValue, subject;
            KeyframeAlgorithm<T>* algorithm{};
            KeyframeStatusEnum status;
    };  

}

#endif