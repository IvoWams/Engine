#ifndef KEYFRAME_KEYFRAMEHANDLER_HPP
#define KEYFRAME_KEYFRAMEHANDLER_HPP

#include "engine/trait/Progressable.hpp"
#include "memory/recycler/Recycler.hpp"
#include <map>

using engine::trait::Progressable;
using memory::recycler::Recycler;

namespace keyframe
{
    template <typename T>
    class KeyframeAlgorithm
    {
        public:
            virtual void iterate(Keyframe<T>*, uint64_t time) = 0;
    };

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

    template <typename T>
    class Linear : public KeyframeAlgorithm
    {
        public:
            void iterate(Keyframe<T>* keyframe, uint64_t time)
            {
                if (keyframe->status == KeyframeStatusEnum::FINISHED) {
                    return;
                }

                if (keyframe->status == KeyframeStatusEnum::NOT_STARTED) {
                    if (time < keyframe->startTime) {
                        return;
                    }

                    keyframe->cursor = keyframe->startTime;
                    keyframe->subject = keyframe->startValue;
                    keyframe->status = KeyframeStatusEnum::IN_PROGRESS;
                }

                // IN_PROGRESS:
                if (time >= keyframe->endTime) {
                    keyframe->subject = keyframe->endValue;
                    keyframe->status = KeyframeStatusEnum::FINISHED;
                    return;
                }

                // Actual calculation here, rest could be DRY
                auto delta = time - keyframe->cursor;
                keyframe->subject += (keyframe->endValue - keyframe->subject) / delta;
            }
    };

    template <typename T>
    class KeyframeHandler final :
        public Progressable,
        public Recycler<KeyframeHandler>
    {
        private:
            static std::map<T*, std::map<uint64_t, Keyframe<T>*>> keyframes;

            uint64_t cursor;

        public:
            static void add(
                T& value, 
                Keyframe<T>* keyframe
            )
            {
                keyframes[value].insert(std::pair(keyframe->start, keyframe));
            }

            void onEvent(TickEvent* tick)
            {
                cursor += tick->duration;

                for (auto keyframelist : keyframes) {
                    auto list = keyframelist.second;
                    auto first = list.at(0)
                    uint64_t firsttime = list.firstfirst;

                    auto firstframe = keyframelist
                }
            }
    };
}

#endif