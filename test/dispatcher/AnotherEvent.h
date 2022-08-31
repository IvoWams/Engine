#ifndef APP_TEST_ANOTHEREVENT_H
#define APP_TEST_ANOTHEREVENT_H

#include <string>
#include "../../event/Event.h"

using namespace app::event;
using namespace std;

namespace app::test
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
