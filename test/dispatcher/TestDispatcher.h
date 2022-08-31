#ifndef APP_TEST_TESTDISPATCHER_H
#define APP_TEST_TESTDISPATCHER_H

#include "../../event/Dispatcher.h"
#include "TestEvent.h"
#include "AnotherEvent.h"

using namespace app::event;

namespace app::test
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