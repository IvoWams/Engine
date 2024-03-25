#ifndef KEYFRAME_KEYFRAME_HPP
#define KEYFRAME_KEYFRAME_HPP

#include <cstdint>
#include "memory/recycler/Recycler.hpp"

using memory::recycler::Recycler;

namespace keyframe::algorithm
{
    template <typename T>
    class KeyframeAlgorithm;
}

using keyframe::algorithm::KeyframeAlgorithm;

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
                T& _subject,

                const uint64_t _startTime,
                const T _startValue,

                const uint64_t _endTime,
                const T _endValue,

                const KeyframeAlgorithm<T>* _algorithm
            ) :
                startTime(_startTime),
                endTime(_endTime),
                startValue(_startValue),    // Needs copy constructor ?
                endValue(_endValue),
                subject(_subject),
                status(NOT_STARTED),
                algorithm(_algorithm)
        {

        }

        ~Keyframe() = default;

        T& subject;
        KeyframeStatusEnum status;
        const KeyframeAlgorithm<T>* algorithm;

        const uint64_t startTime;
        const T startValue;

        const uint64_t endTime;
        const T endValue;
    };
}

#endif