#ifndef ENGINE_EVENT_ENGINETIMINGEEVENT_HPP
#define ENGINE_EVENT_ENGINETIMINGEEVENT_HPP

#include "EngineEvent.hpp"

namespace engine::event
{
    enum EngineTimingEventTypeEnum
    {
        INITIALISATION,
        START,
        ITERATION,
        STOP,
        CLEANUP
    };

    template <EngineTimingEventTypeEnum T>
    class EngineTimingEvent :
        public EngineEvent
    {

    };
}

#endif