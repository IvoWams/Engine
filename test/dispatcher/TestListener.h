#ifndef APP_TEST_TESTLISTENER_H
#define APP_TEST_TESTLISTENER_H

#include "../../event/Listener.h"
#include "TestEvent.h"

using namespace app::event;

namespace app::test
{
    class TestListener :
        public Listener<TestEvent>,
        public Listener<AnotherEvent>
    {

        public:
            void onEvent(TestEvent* event)
            {
                printf("Incoming testevent: %s", event->getMessage().c_str());
            }

            void onEvent(AnotherEvent* event)
            {
                printf(
                    "There is another event: %s with value %d",
                    event->getMessage().c_str(), 
                    event->getValue()
                );
            }

    };
}

#endif