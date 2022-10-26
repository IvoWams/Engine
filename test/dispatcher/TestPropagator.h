#ifndef ENGINE_TEST_PROPAGATOR_H
#define ENGINE_TEST_PROPAGATOR_H

#include "engine/event/Propagator.h"
#include "TestEvent.h"

using namespace engine::event;

namespace engine::test
{
    class TestPropagator : public Propagator<TestEvent>
    {
        
    };
}

#endif