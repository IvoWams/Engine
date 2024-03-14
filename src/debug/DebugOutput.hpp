#ifndef DEBUG_DEBUGOUTPUT_HPP
#define DEBUG_DEBUGOUTPUT_HPP

#include "engine/event/TickEvent.hpp"
#include "engine/Engine.hpp"
#include "event/Listener.hpp"

using engine::event::TickEvent;
using engine::Engine;
using event::Listener;

namespace debug
{
    class DebugOutput
        : public Listener<TickEvent>
    {

    };
}

#endif