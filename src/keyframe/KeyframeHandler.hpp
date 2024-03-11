#ifndef KEYFRAME_KEYFRAMEHANDLER_HPP
#define KEYFRAME_KEYFRAMEHANDLER_HPP

#include "engine/trait/Progressable.hpp"
#include "memory/recycler/Recycler.hpp"

using engine::trait::Progressable;
using memory::recycler::Recycler;

namespace keyframe
{
    // Progresses the keyframe in time. Should return true if complete
    template <class T>
    class KeyframeAlgorithm
    {
        public:
            bool iterate(Keyframe*, uint64_t time) = 0;
    };

    template <class T>
    class Linear : public KeyframeAlgorithm<T>
    {
        public:
            bool iterate(Keyframe* k, uint64_t time)
            {
                // guard
                if (k->cursor + time > )

                T delta = k->end - k->start;
                uint64_t span = time / k->lifetime;
            }
    };

    class KeyframeValue
    {
        public:
            virtual void operator+(const KeyframeValue&) = 0;
            virtual void operator-(const KeyframeValue&) = 0;
            virtual void operator/(const KeyframeValue&) = 0;
            virtual void operator*(const KeyframeValue&) = 0;
            virtual void operator=(const KeyframeValue&) = 0;
    }

    class Keyframe final : public Recycler<Keyframe<T>>
    {
        public:
            Keyframe(uint64_t _lifetime, T _end, KeyframeAlgorithm<T>* _algorithm)
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
            static map<KeyframeHandler*, map<T start, Keyframe*>> keyframes;

            T& subject;
            
            // algorithm ? lineair, easing etc

        public:
            KeyframeHandler(T& _subject) : subject(_subject) {

            };

            ~KeyframeHandler(){};

            void onEvent(TickEvent* tick);       
    };
}

#endif