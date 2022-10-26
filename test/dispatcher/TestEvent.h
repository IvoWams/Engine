#ifndef ENGINE_TEST_TESTEVENT_H
#define ENGINE_TEST_TESTEVENT_H

#include <string>
#include "engine/event/Event.h"

using namespace engine::event;
using namespace std;

namespace engine::test
{
    class TestEvent : Event
    {
        private:
            string message;

        public:
            TestEvent(string _message)
            {
                message = _message;
            }

            string& getMessage()
            {
                return message;
            }
    };
}

#endif
