#ifndef KEYFRAME_KEYFRAMEHANDLER_HPP
#define KEYFRAME_KEYFRAMEHANDLER_HPP

#include "engine/trait/Progressable.hpp"
#include "memory/recycler/Recycler.hpp"
#include <map>
#include "Keyframe.hpp"

using engine::trait::Progressable;
using memory::recycler::Recycler;

namespace keyframe
{
    template <typename T>
    class KeyframeHandler final :
        public Progressable,
        public Recycler<KeyframeHandler<T>>
    {
        private:
            static std::map<T*, std::map<uint64_t, Keyframe<T>*>> keyframes;

            uint64_t cursor{};

        public:
            static void add(T&, Keyframe<T>*);
            void onEvent(TickEvent*) override;
    };
}

#endif
