#ifndef KEYFRAME_KEYFRAMEHANDLER_HPP
#define KEYFRAME_KEYFRAMEHANDLER_HPP

#include "engine/trait/Progressable.hpp"
#include "memory/recycler/Recycler.hpp"
#include <map>

using engine::trait::Progressable;
using memory::recycler::Recycler;

namespace keyframe
{
    class KeyframeAlgorithm
    {
        public:
            virtual bool iterate(Keyframe*, uint64_t time) = 0;
    };

    class Linear : public KeyframeAlgorithm
    {
        public:
            bool iterate(Keyframe* k, uint64_t time)
            {
                // guard
                if (k->cursor + time > )

                KeyframeValue* delta = k->end - k->start;
                uint64_t span = time / k->lifetime;
            }
    };

    class KeyframeValue
    {
        public:
            virtual KeyframeValue& operator+(const KeyframeValue&) = 0;
            virtual KeyframeValue& operator-(const KeyframeValue&) = 0;
            virtual KeyframeValue& operator/(const KeyframeValue&) = 0;
            virtual KeyframeValue& operator*(const KeyframeValue&) = 0;
            virtual KeyframeValue& operator=(const KeyframeValue&) = 0;
    };

    template <typename T>
    // assert that T is scalar
    class KeyframeScalarValue final : public KeyframeValue
    {
        public:
            T value;

            KeyframeScalarValue operator+(const KeyframeScalarValue<T>& _value)
            {
                value += _value;
                return this;
            }
    };

    class Keyframe final : public Recycler<Keyframe>
    {
        public:
            Keyframe(uint64_t _lifetime, KeyframeValue* _end, KeyframeAlgorithm* _algorithm)
                : lifetime(_lifetime), end(_end), algorithm(_algorithm)
            {
                KeyframeHandler<T>::keyframes[KeyframeHandler<T>::getInstance()].push_back(this);
            }

            ~Keyframe(){};

            KeyframeHandler<T>& handler;

            uint64_t lifetime;
            uint64_t cursor;
            T start, end;
            KeyframeAlgorithm<T>* algorithm;
    };

    class KeyframeHandler final :
        public Progressable,
        public Recycler<KeyframeHandler>
    {
        private:
            static std::map<KeyframeHandler*, std::map<uint64_t, Keyframe*>> keyframes;
            
            // algorithm ? lineair, easing etc

        public:
            KeyframeHandler(T& _subject) : subject(_subject) {

            };

            KeyframeValue* subject;


            static KeyframeHandler* get(KeyframeValue* value)
            {
                for (auto keyframe : keyframes) {
                    if (keyframe.first->subject)
                }
            }

            ~KeyframeHandler(){};

            void onEvent(TickEvent* tick);       
    };
}

#endif