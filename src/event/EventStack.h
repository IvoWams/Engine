#ifndef ENGINE_EVENT_EVENTSTACK_H
#define ENGINE_EVENT_EVENTSTACK_H

#include <cstddef>

namespace event
{
    class EventStack
    {
        private:
            static void* unique;

        public:
            void* operator new(size_t size);
            void operator delete(void* p);
    };
}

#endif