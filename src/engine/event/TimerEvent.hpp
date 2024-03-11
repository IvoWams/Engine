#ifndef ENGINE_EVENT_TIMEREVENT_HPP
#define ENGINE_EVENT_TIMEREVENT_HPP

#include "EngineEvent.hpp"
#include "Timer.hpp"

namespace engine::event
{
    class TimerEvent final : public EngineEvent
    {
        public:
            TimerEvent(Timer* _timer) : timer(_timer) {};

            Timer* timer;
    };
}

#endif