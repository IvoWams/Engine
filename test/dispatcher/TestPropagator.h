#ifndef APP_TEST_PROPAGATOR_H
#define APP_TEST_PROPAGATOR_H

#include "../../event/Propagator.h"
#include "TestEvent.h"

using namespace app::event;

namespace app::test
{
    class TestPropagator : public Propagator<TestEvent>
    {
        
    };
}

#endif