#ifndef APP_TEST_TESTEVENT_H
#define APP_TEST_TESTEVENT_H

#include <string>
#include "../../event/Event.h"

using namespace app::event;
using namespace std;

namespace app::test
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
