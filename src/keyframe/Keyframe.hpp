#ifndef KEYFRAME_KEYFRAME_HPP
#define KEYFRAME_KEYFRAME_HPP

namespace keeyframe
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
            {
                
            }

            ~Keyframe()
            {};

            uint64_t startTime, endTime, cursor;
            T& startValue, endValue, subject;
            KeyframeAlgorithm<T>* algorithm;
            KeyframeStatusEnum status;
    };  

}

#endif