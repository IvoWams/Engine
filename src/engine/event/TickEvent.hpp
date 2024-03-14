#ifndef ENGINE_EVENT_TICKEVENT_HPP
#define ENGINE_EVENT_TICKEVENT_HPP

#include "EngineEvent.hpp"
#include "memory/recycler/Recycler.hpp"

#include <chrono>

using memory::recycler::Recycler;

namespace engine::event
{
    class TickEvent final :
        public EngineEvent,
        public Recycler<TickEvent>
    {
        private:

        public:
            TickEvent(uint64_t _duration) : duration(_duration) {};

            uint64_t duration;
    };
}

#endif