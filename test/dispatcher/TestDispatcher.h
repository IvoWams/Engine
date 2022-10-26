#ifndef ENGINE_TEST_TESTDISPATCHER_H
#define ENGINE_TEST_TESTDISPATCHER_H

#include "engine/event/Dispatcher.h"
#include "TestEvent.h"
#include "AnotherEvent.h"

using namespace engine::event;

namespace engine::test
{
    class TestDispatcher :
        public Dispatcher<TestEvent>,
        public Dispatcher<AnotherEvent>
    {
        public:

            void testDispatch()
            {
                Dispatcher<TestEvent>::dispatch(new TestEvent("test"));
            }


            using Dispatcher<TestEvent>::dispatch;
            using Dispatcher<TestEvent>::addListener;
            using Dispatcher<AnotherEvent>::dispatch;
            using Dispatcher<AnotherEvent>::addListener;

    };
}

#endif