#ifndef ENGINE_TEST_ANOTHEREVENT_H
#define ENGINE_TEST_ANOTHEREVENT_H

#include <string>
#include "engine/event/Event.h"

using namespace engine::event;
using namespace std;

namespace engine::test
{
    class AnotherEvent : Event
    {
        private:
            string message;
            int somevalue;

        public:
            AnotherEvent(string _message, int _somevalue)
            {
                message = _message;
                somevalue = _somevalue;
            }

            string& getMessage()
            {
                return message;
            }

            int getValue()
            {
                return somevalue;
            }
    };
}

#endif
