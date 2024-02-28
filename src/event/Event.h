#ifndef ENGINE_EVENT_EVENT_H
#define ENGINE_EVENT_EVENT_H

#include <cstddef>

namespace event
{
    class Event
    {
        private:
            Event* parent = nullptr;

        public:
            Event() {}
            Event(Event* _parent) : parent(_parent) {}

            Event* getParent();
    };
}

#endif
